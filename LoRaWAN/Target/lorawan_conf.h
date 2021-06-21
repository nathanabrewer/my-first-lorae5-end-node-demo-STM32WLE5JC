
#ifndef __LORAWAN_CONF_H__
#define __LORAWAN_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "stm32_systime.h"
#include "sys_app.h"   /* needed for APP_PRINTF */

#define REGION_US915
#define HYBRID_ENABLED          0
#define KEY_LOG_ENABLED         1

/* Class B ------------------------------------*/
#define LORAMAC_CLASSB_ENABLED  0

#if ( LORAMAC_CLASSB_ENABLED == 1 )
/* CLASS B LSE crystall calibration*/
/**
  * \brief Temperature coefficient of the clock source
  */
#define RTC_TEMP_COEFFICIENT                            ( -0.035 )

/**
  * \brief Temperature coefficient deviation of the clock source
  */
#define RTC_TEMP_DEV_COEFFICIENT                        ( 0.0035 )

/**
  * \brief Turnover temperature of the clock source
  */
#define RTC_TEMP_TURNOVER                               ( 25.0 )

/**
  * \brief Turnover temperature deviation of the clock source
  */
#define RTC_TEMP_DEV_TURNOVER                           ( 5.0 )
#endif /* LORAMAC_CLASSB_ENABLED == 1 */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
#ifndef CRITICAL_SECTION_BEGIN
#define CRITICAL_SECTION_BEGIN( )      UTILS_ENTER_CRITICAL_SECTION( )
#endif /* !CRITICAL_SECTION_BEGIN */
#ifndef CRITICAL_SECTION_END
#define CRITICAL_SECTION_END( )        UTILS_EXIT_CRITICAL_SECTION( )
#endif /* !CRITICAL_SECTION_END */

/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __LORAWAN_CONF_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
