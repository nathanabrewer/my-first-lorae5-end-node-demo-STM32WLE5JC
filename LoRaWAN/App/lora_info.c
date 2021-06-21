
#include "LoRaMac.h"
#include "lora_info.h"

static LoraInfo_t loraInfo = {0, 0};


void LoraInfo_Init(void)
{
  loraInfo.ActivationMode = 0;
  loraInfo.Region = 0;
  loraInfo.ClassB = 0;
  loraInfo.Kms = 0;

  loraInfo.Region |= (1 << LORAMAC_REGION_US915) ;


  if (loraInfo.Region == 0)
  {
    APP_PRINTF("error: At least one region shall be defined in the MW: check lorawan_conf.h \r\n");
    while (1) {} /* At least one region shall be defined */
  }

#if ( LORAMAC_CLASSB_ENABLED == 1 )
  loraInfo.ClassB = 1;
#elif !defined (LORAMAC_CLASSB_ENABLED)
#error LORAMAC_CLASSB_ENABLED not defined ( shall be <0 or 1> )
#endif /* LORAMAC_CLASSB_ENABLED */

#if (!defined (LORAWAN_KMS) || (LORAWAN_KMS == 0))
  loraInfo.Kms = 0;
  loraInfo.ActivationMode = 3;
#else /* LORAWAN_KMS == 1 */
  loraInfo.Kms = 1;
  loraInfo.ActivationMode = ACTIVATION_BY_PERSONALISATION + (OVER_THE_AIR_ACTIVATION << 1);
#endif /* LORAWAN_KMS */
  /* USER CODE BEGIN LoraInfo_Init_2 */

  /* USER CODE END LoraInfo_Init_2 */
}

LoraInfo_t *LoraInfo_GetPtr(void)
{

  return &loraInfo;
}
