
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wlxx_hal.h"

#include "board_resources.h"

void Error_Handler(void);


/* Private defines -----------------------------------------------------------*/
#define RTC_N_PREDIV_S 10
#define RTC_PREDIV_S ((1<<RTC_N_PREDIV_S)-1)
#define RTC_PREDIV_A ((1<<(15-RTC_N_PREDIV_S))-1)
#define USART_BAUDRATE 115200
#define LED1_Pin GPIO_PIN_15
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOB
#define DBG3_Pin GPIO_PIN_14
#define DBG3_GPIO_Port GPIOB
#define RF_CTRL3_Pin GPIO_PIN_3
#define RF_CTRL3_GPIO_Port GPIOC
#define BUT1_Pin GPIO_PIN_0
#define BUT1_GPIO_Port GPIOA
#define BUT1_EXTI_IRQn EXTI0_IRQn
#define DBG2_Pin GPIO_PIN_13
#define DBG2_GPIO_Port GPIOB
#define RF_CTRL2_Pin GPIO_PIN_5
#define RF_CTRL2_GPIO_Port GPIOC
#define DBG1_Pin GPIO_PIN_12
#define DBG1_GPIO_Port GPIOB
#define RF_CTRL1_Pin GPIO_PIN_4
#define RF_CTRL1_GPIO_Port GPIOC
#define BUT3_Pin GPIO_PIN_6
#define BUT3_GPIO_Port GPIOC
#define BUT2_Pin GPIO_PIN_1
#define BUT2_GPIO_Port GPIOA
#define BUT2_EXTI_IRQn EXTI1_IRQn
#define LED3_Pin GPIO_PIN_11
#define LED3_GPIO_Port GPIOB
#define USARTx_RX_Pin GPIO_PIN_3
#define USARTx_RX_GPIO_Port GPIOA
#define USARTx_TX_Pin GPIO_PIN_2
#define USARTx_TX_GPIO_Port GPIOA
#define DBG4_Pin GPIO_PIN_10
#define DBG4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
