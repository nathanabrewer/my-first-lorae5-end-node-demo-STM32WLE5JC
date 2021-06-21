
#include "radio_board_if.h"


int32_t RBI_Init(void)
{

  GPIO_InitTypeDef  gpio_init_structure = {0};
  RF_SW_CTRL3_GPIO_CLK_ENABLE(); /* Enable the Radio Switch Clock */

  /* Configure the Radio Switch pin */
  gpio_init_structure.Pin   = RF_SW_CTRL1_PIN;
  gpio_init_structure.Mode  = GPIO_MODE_OUTPUT_PP;
  gpio_init_structure.Pull  = GPIO_NOPULL;
  gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  HAL_GPIO_Init(RF_SW_CTRL1_GPIO_PORT, &gpio_init_structure);

  gpio_init_structure.Pin = RF_SW_CTRL2_PIN;
  HAL_GPIO_Init(RF_SW_CTRL2_GPIO_PORT, &gpio_init_structure);

  gpio_init_structure.Pin = RF_SW_CTRL3_PIN;
  HAL_GPIO_Init(RF_SW_CTRL3_GPIO_PORT, &gpio_init_structure);

  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);

  return 0;

}

int32_t RBI_DeInit(void){
  RF_SW_CTRL3_GPIO_CLK_ENABLE();

  /* Turn off switch */
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);

  /* DeInit the Radio Switch pin */
  HAL_GPIO_DeInit(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN);

  return 0;

}

int32_t RBI_ConfigRFSwitch(RBI_Switch_TypeDef Config){

  switch (Config)
  {
    case RBI_SWITCH_OFF:
    {
      /* Turn off switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
      break;
    }
    case RBI_SWITCH_RX:
    {
      /*Turns On in Rx Mode the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
      break;
    }
    case RBI_SWITCH_RFO_LP:
    {
      /*Turns On in Tx Low Power the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
      break;
    }
    case RBI_SWITCH_RFO_HP:
    {
      /*Turns On in Tx High Power the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET);
      break;
    }
    default:
      break;
  }

  return 0;

}

int32_t RBI_GetTxConfig(void){
	  return RBI_CONF_RFO;
}

int32_t RBI_GetWakeUpTime(void){
	return RF_WAKEUP_TIME;
}

int32_t RBI_IsTCXO(void){
	return IS_TCXO_SUPPORTED;
}

int32_t RBI_IsDCDC(void){
	return IS_DCDC_SUPPORTED;
}

