
#include "platform.h"
#include "Region.h" /* Needed for LORAWAN_DEFAULT_DATA_RATE */
#include "sys_app.h"
#include "lora_app.h"
#include "stm32_seq.h"
#include "stm32_timer.h"
#include "utilities_def.h"
#include "lora_app_version.h"
#include "lorawan_version.h"
#include "subghz_phy_version.h"
#include "lora_info.h"
#include "LmHandler.h"
#include "stm32_lpm.h"
#include "adc_if.h"
#include "sys_conf.h"

#include "sys_sensors.h"

typedef enum TxEventType_e
{
  /**
    * @brief AppdataTransmition issue based on timer every TxDutyCycleTime
    */
  TX_ON_TIMER,
  /**
    * @brief AppdataTransmition external event plugged on OnSendEvent( )
    */
  TX_ON_EVENT
  /* USER CODE BEGIN TxEventType_t */

  /* USER CODE END TxEventType_t */
} TxEventType_t;

/**
  * @brief  LoRa endNode send request
  * @param  none
  * @retval none
  */
static void SendTxData(void);

/**
  * @brief  TX timer callback function
  * @param  timer context
  * @retval none
  */
static void OnTxTimerEvent(void *context);

/**
  * @brief  LED Tx timer callback function
  * @param  LED context
  * @retval none
  */
static void OnTxTimerLedEvent(void *context);

/**
  * @brief  LED Rx timer callback function
  * @param  LED context
  * @retval none
  */
static void OnRxTimerLedEvent(void *context);

/**
  * @brief  LED Join timer callback function
  * @param  LED context
  * @retval none
  */
static void OnJoinTimerLedEvent(void *context);

/**
  * @brief  join event callback function
  * @param  params
  * @retval none
  */
static void OnJoinRequest(LmHandlerJoinParams_t *joinParams);

/**
  * @brief  tx event callback function
  * @param  params
  * @retval none
  */
static void OnTxData(LmHandlerTxParams_t *params);

/**
  * @brief callback when LoRa endNode has received a frame
  * @param appData
  * @param params
  * @retval None
  */
static void OnRxData(LmHandlerAppData_t *appData, LmHandlerRxParams_t *params);

/*!
 * Will be called each time a Radio IRQ is handled by the MAC layer
 *
 */
static void OnMacProcessNotify(void);






/* Private variables ---------------------------------------------------------*/

/**
  * @brief User application buffer
  */
static uint8_t AppDataBuffer[LORAWAN_APP_DATA_BUFFER_MAX_SIZE];

/**
  * @brief User application data structure
  */
static LmHandlerAppData_t AppData = { 0, 0, AppDataBuffer };

static ActivationType_t ActivationType = LORAWAN_DEFAULT_ACTIVATION_TYPE;

/**
  * @brief LoRaWAN handler Callbacks
  */
static LmHandlerCallbacks_t LmHandlerCallbacks =
{
  .GetBatteryLevel =           GetBatteryLevel,
  .GetTemperature =            GetTemperatureLevel,
  .OnMacProcess =              OnMacProcessNotify,
  .OnJoinRequest =             OnJoinRequest,
  .OnTxData =                  OnTxData,
  .OnRxData =                  OnRxData
};

/**
  * @brief LoRaWAN handler parameters
  */
static LmHandlerParams_t LmHandlerParams =
{
  .ActiveRegion =             ACTIVE_REGION,
  .DefaultClass =             LORAWAN_DEFAULT_CLASS,
  .AdrEnable =                LORAWAN_ADR_STATE,
  .TxDatarate =               LORAWAN_DEFAULT_DATA_RATE,
  .PingPeriodicity =          LORAWAN_DEFAULT_PING_SLOT_PERIODICITY
};

/**
  * @brief Specifies the state of the application LED
  */
static uint8_t AppLedStateOn = RESET;

/**
  * @brief Type of Event to generate application Tx
  */
static TxEventType_t EventType = TX_ON_TIMER;

/**
  * @brief Timer to handle the application Tx
  */
static UTIL_TIMER_Object_t TxTimer;

/**
  * @brief Timer to handle the application Tx Led to toggle
  */
static UTIL_TIMER_Object_t TxLedTimer;

/**
  * @brief Timer to handle the application Rx Led to toggle
  */
static UTIL_TIMER_Object_t RxLedTimer;

/**
  * @brief Timer to handle the application Join Led to toggle
  */
static UTIL_TIMER_Object_t JoinLedTimer;

void LoRaWAN_Init(void)
{


  SYS_LED_Init(SYS_LED_BLUE);
  SYS_LED_Init(SYS_LED_GREEN);
  SYS_LED_Init(SYS_LED_RED);
  SYS_PB_Init(SYS_BUTTON2, SYS_BUTTON_MODE_EXTI);

  APP_LOG(TS_OFF, VLEVEL_M, "MX_BOARD_PSEUDODRIVER\r\n");


  /* Get LoRa APP version*/
  APP_LOG(TS_OFF, VLEVEL_M, "APP_VERSION:        V%X.%X.%X\r\n",
          (uint8_t)(__LORA_APP_VERSION >> __APP_VERSION_MAIN_SHIFT),
          (uint8_t)(__LORA_APP_VERSION >> __APP_VERSION_SUB1_SHIFT),
          (uint8_t)(__LORA_APP_VERSION >> __APP_VERSION_SUB2_SHIFT));

  /* Get MW LoraWAN info */
  APP_LOG(TS_OFF, VLEVEL_M, "MW_LORAWAN_VERSION: V%X.%X.%X\r\n",
          (uint8_t)(__LORAWAN_VERSION >> __APP_VERSION_MAIN_SHIFT),
          (uint8_t)(__LORAWAN_VERSION >> __APP_VERSION_SUB1_SHIFT),
          (uint8_t)(__LORAWAN_VERSION >> __APP_VERSION_SUB2_SHIFT));

  /* Get MW SubGhz_Phy info */
  APP_LOG(TS_OFF, VLEVEL_M, "MW_RADIO_VERSION:   V%X.%X.%X\r\n",
          (uint8_t)(__SUBGHZ_PHY_VERSION >> __APP_VERSION_MAIN_SHIFT),
          (uint8_t)(__SUBGHZ_PHY_VERSION >> __APP_VERSION_SUB1_SHIFT),
          (uint8_t)(__SUBGHZ_PHY_VERSION >> __APP_VERSION_SUB2_SHIFT));

  UTIL_TIMER_Create(&TxLedTimer, 0xFFFFFFFFU, UTIL_TIMER_ONESHOT, OnTxTimerLedEvent, NULL);
  UTIL_TIMER_Create(&RxLedTimer, 0xFFFFFFFFU, UTIL_TIMER_ONESHOT, OnRxTimerLedEvent, NULL);
  UTIL_TIMER_Create(&JoinLedTimer, 0xFFFFFFFFU, UTIL_TIMER_PERIODIC, OnJoinTimerLedEvent, NULL);
  UTIL_TIMER_SetPeriod(&TxLedTimer, 500);
  UTIL_TIMER_SetPeriod(&RxLedTimer, 500);
  UTIL_TIMER_SetPeriod(&JoinLedTimer, 500);

  UTIL_SEQ_RegTask((1 << CFG_SEQ_Task_LmHandlerProcess), UTIL_SEQ_RFU, LmHandlerProcess);
  UTIL_SEQ_RegTask((1 << CFG_SEQ_Task_LoRaSendOnTxTimerOrButtonEvent), UTIL_SEQ_RFU, SendTxData);

  /* Init Info table used by LmHandler*/
  LoraInfo_Init();

  /* Init the Lora Stack*/
  LmHandlerInit(&LmHandlerCallbacks);

  LmHandlerConfigure(&LmHandlerParams);

  UTIL_TIMER_Start(&JoinLedTimer);

  LmHandlerJoin(ActivationType);

  if (EventType == TX_ON_TIMER)
  {
    /* send every time timer elapses */
    UTIL_TIMER_Create(&TxTimer,  0xFFFFFFFFU, UTIL_TIMER_ONESHOT, OnTxTimerEvent, NULL);
    UTIL_TIMER_SetPeriod(&TxTimer,  APP_TX_DUTYCYCLE);
    UTIL_TIMER_Start(&TxTimer);
  }
  else
  {
    /* send every time button is pushed */


    SYS_PB_Init(SYS_BUTTON1, SYS_BUTTON_MODE_EXTI);

  }

  /* USER CODE BEGIN LoRaWAN_Init_Last */

  /* USER CODE END LoRaWAN_Init_Last */
}



/* Note: Current MX does not support EXTI IP neither BSP. */
/* In order to get a push button IRS by code automatically generated */
/* this function is today the only available possibility. */
/* Calling BSP_PB_Callback() from here it shortcuts the BSP. */
/* If users wants to go through the BSP, it can remove BSP_PB_Callback() from here */
/* and add a call to BSP_PB_IRQHandler() in the USER CODE SESSION of the */
/* correspondent EXTIn_IRQHandler() in the stm32wlxx_it.c */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* USER CODE BEGIN HAL_GPIO_EXTI_Callback_1 */

  /* USER CODE END HAL_GPIO_EXTI_Callback_1 */
  switch (GPIO_Pin)
  {
    case  SYS_BUTTON1_PIN:
      /* Note: when "EventType == TX_ON_TIMER" this GPIO is not initialised */
      UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LoRaSendOnTxTimerOrButtonEvent), CFG_SEQ_Prio_0);
      /* USER CODE BEGIN EXTI_Callback_Switch_B1 */
      /* USER CODE END EXTI_Callback_Switch_B1 */
      break;
    case  SYS_BUTTON2_PIN:
      /* USER CODE BEGIN EXTI_Callback_Switch_B2 */
      /* USER CODE END EXTI_Callback_Switch_B2 */
      break;
    /* USER CODE BEGIN EXTI_Callback_Switch_case */

    /* USER CODE END EXTI_Callback_Switch_case */
    default:
    /* USER CODE BEGIN EXTI_Callback_Switch_default */
    /* USER CODE END EXTI_Callback_Switch_default */
      break;
  }
  /* USER CODE BEGIN HAL_GPIO_EXTI_Callback_Last */

  /* USER CODE END HAL_GPIO_EXTI_Callback_Last */
}



static void OnRxData(LmHandlerAppData_t *appData, LmHandlerRxParams_t *params)
{
  /* USER CODE BEGIN OnRxData_1 */

  /* USER CODE END OnRxData_1 */
  if ((appData != NULL) && (params != NULL))
  {
    SYS_LED_On(SYS_LED_BLUE) ;

    UTIL_TIMER_Start(&RxLedTimer);

    static const char *slotStrings[] = { "1", "2", "C", "C Multicast", "B Ping-Slot", "B Multicast Ping-Slot" };

    APP_LOG(TS_OFF, VLEVEL_M, "\r\n###### ========== MCPS-Indication ==========\r\n");
    APP_LOG(TS_OFF, VLEVEL_H, "###### D/L FRAME:%04d | SLOT:%s | PORT:%d | DR:%d | RSSI:%d | SNR:%d\r\n",
            params->DownlinkCounter, slotStrings[params->RxSlot], appData->Port, params->Datarate, params->Rssi, params->Snr);
    switch (appData->Port)
    {
      case LORAWAN_SWITCH_CLASS_PORT:
        /*this port switches the class*/
        if (appData->BufferSize == 1)
        {
          switch (appData->Buffer[0])
          {
            case 0:
            {
              LmHandlerRequestClass(CLASS_A);
              break;
            }
            case 1:
            {
              LmHandlerRequestClass(CLASS_B);
              break;
            }
            case 2:
            {
              LmHandlerRequestClass(CLASS_C);
              break;
            }
            default:
              break;
          }
        }
        break;
      case LORAWAN_USER_APP_PORT:
        if (appData->BufferSize == 1)
        {
          AppLedStateOn = appData->Buffer[0] & 0x01;
          if (AppLedStateOn == RESET)
          {
            APP_LOG(TS_OFF, VLEVEL_H,   "LED OFF\r\n");


            SYS_LED_Off(SYS_LED_RED) ;

          }
          else
          {
            APP_LOG(TS_OFF, VLEVEL_H, "LED ON\r\n");

            SYS_LED_On(SYS_LED_RED) ;

          }
        }
        break;
    /* USER CODE BEGIN OnRxData_Switch_case */

    /* USER CODE END OnRxData_Switch_case */
      default:
    /* USER CODE BEGIN OnRxData_Switch_default */

    /* USER CODE END OnRxData_Switch_default */
        break;
    }
  }

  /* USER CODE BEGIN OnRxData_2 */

  /* USER CODE END OnRxData_2 */
}

static void SendTxData(void)
{
  uint16_t pressure = 0;
  int16_t temperature = 0;
  sensor_t sensor_data;
  UTIL_TIMER_Time_t nextTxIn = 0;


  uint32_t i = 0;

  uint16_t humidity = 0;
  int32_t latitude = 0;
  int32_t longitude = 0;
  uint16_t altitudeGps = 0;


  EnvSensors_Read(&sensor_data);

  temperature = (SYS_GetTemperatureLevel() >> 8);
  pressure    = (uint16_t)(sensor_data.pressure * 100 / 10);      /* in hPa / 10 */

  humidity    = (uint16_t)(sensor_data.humidity * 10);            /* in %*10     */


  AppData.Port = LORAWAN_USER_APP_PORT;

  AppData.Buffer[i++] = AppLedStateOn;
  AppData.Buffer[i++] = (uint8_t)((pressure >> 8) & 0xFF);
  AppData.Buffer[i++] = (uint8_t)(pressure & 0xFF);
  AppData.Buffer[i++] = (uint8_t)(temperature & 0xFF);
  AppData.Buffer[i++] = (uint8_t)((humidity >> 8) & 0xFF);
  AppData.Buffer[i++] = (uint8_t)(humidity & 0xFF);

  // if(LmHandlerParams.ActiveRegion == LORAMAC_REGION_US915)

    AppData.Buffer[i++] = 0;
    AppData.Buffer[i++] = 0;
    AppData.Buffer[i++] = 0;
    AppData.Buffer[i++] = 0;


  AppData.BufferSize = i;


  if (LORAMAC_HANDLER_SUCCESS == LmHandlerSend(&AppData, LORAWAN_DEFAULT_CONFIRMED_MSG_STATE, &nextTxIn, false)){
    APP_LOG(TS_ON, VLEVEL_L, "SEND REQUEST\r\n");
  }
  else if (nextTxIn > 0){
    APP_LOG(TS_ON, VLEVEL_L, "Next Tx in  : ~%d second(s)\r\n", (nextTxIn / 1000));
  }

}

static void OnTxTimerEvent(void *context)
{
  UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LoRaSendOnTxTimerOrButtonEvent), CFG_SEQ_Prio_0);
  UTIL_TIMER_Start(&TxTimer);
}


static void OnTxTimerLedEvent(void *context)
{

  SYS_LED_Off(SYS_LED_GREEN) ;
}

static void OnRxTimerLedEvent(void *context)
{
  SYS_LED_Off(SYS_LED_BLUE) ;
}

static void OnJoinTimerLedEvent(void *context)
{
  SYS_LED_Toggle(SYS_LED_RED) ;
}

static void OnTxData(LmHandlerTxParams_t *params)
{

  if ((params != NULL) && (params->IsMcpsConfirm != 0))
  {

    SYS_LED_On(SYS_LED_GREEN) ;
    UTIL_TIMER_Start(&TxLedTimer);
    APP_LOG(TS_OFF, VLEVEL_M, "\r\n###### ========== MCPS-Confirm =============\r\n");
    APP_LOG(TS_OFF, VLEVEL_H, "###### U/L FRAME:%04d | PORT:%d | DR:%d | PWR:%d", params->UplinkCounter, params->AppData.Port, params->Datarate, params->TxPower);

    APP_LOG(TS_OFF, VLEVEL_H, " | MSG TYPE:");

    if (params->MsgType == LORAMAC_HANDLER_CONFIRMED_MSG){
      APP_LOG(TS_OFF, VLEVEL_H, "CONFIRMED [%s]\r\n", (params->AckReceived != 0) ? "ACK" : "NACK");
    }else{
      APP_LOG(TS_OFF, VLEVEL_H, "UNCONFIRMED\r\n");
    }
  }
}

static void OnJoinRequest(LmHandlerJoinParams_t *joinParams)
{
  /* USER CODE BEGIN OnJoinRequest_1 */

  /* USER CODE END OnJoinRequest_1 */
  if (joinParams != NULL)
  {
    if (joinParams->Status == LORAMAC_HANDLER_SUCCESS)
    {
      UTIL_TIMER_Stop(&JoinLedTimer);


      SYS_LED_Off(SYS_LED_RED) ;


      APP_LOG(TS_OFF, VLEVEL_M, "\r\n###### = JOINED = ");
      if (joinParams->Mode == ACTIVATION_TYPE_ABP)
      {
        APP_LOG(TS_OFF, VLEVEL_M, "ABP ======================\r\n");
      }
      else
      {
        APP_LOG(TS_OFF, VLEVEL_M, "OTAA =====================\r\n");
      }
    }
    else
    {
      APP_LOG(TS_OFF, VLEVEL_M, "\r\n###### = JOIN FAILED\r\n");
    }
  }

  /* USER CODE BEGIN OnJoinRequest_2 */

  /* USER CODE END OnJoinRequest_2 */
}

static void OnMacProcessNotify(void)
{
  /* USER CODE BEGIN OnMacProcessNotify_1 */

  /* USER CODE END OnMacProcessNotify_1 */
  UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LmHandlerProcess), CFG_SEQ_Prio_0);
  /* USER CODE BEGIN OnMacProcessNotify_2 */

  /* USER CODE END OnMacProcessNotify_2 */
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/