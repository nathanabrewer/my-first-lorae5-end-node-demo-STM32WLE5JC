/*!
 * \file      NvmCtxMgmt.h
 *
 * \brief     NVM context management implementation
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    Daniel Jaeckle ( STACKFORCE )
 *
 * \author    Johannes Bruder ( STACKFORCE )
 *
 * \defgroup  NVMCTXMGMT NVM context management implementation
 *            This module implements the NVM context handling
 * \{
 */
/**
  ******************************************************************************
  *
  *          Portions COPYRIGHT 2020 STMicroelectronics
  *
  * @file    NvmCtxMgmt.h
  * @author  MCD Application Team
  * @brief   Header for NVM Context Management module
  ******************************************************************************
  */
#ifndef __NVMCTXMGMT_H__
#define __NVMCTXMGMT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "LoRaMac.h"

/* Exported defines ----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/*!
 * Data structure containing the status of a operation
 */
typedef enum NvmCtxMgmtStatus_e
{
  /*!
   * Operation was successful
   */
  NVMCTXMGMT_STATUS_SUCCESS,
  /*!
   * Operation was not successful
   */
  NVMCTXMGMT_STATUS_FAIL
} NvmCtxMgmtStatus_t;

/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/*!
 * \brief Calculates the next datarate to set, when ADR is on or off.
 *
 * \param [in] adrNext Pointer to the function parameters.
 *
 */
void NvmCtxMgmtEvent(LoRaMacNvmCtxModule_t module);

NvmCtxMgmtStatus_t NvmCtxMgmtStore(void);

NvmCtxMgmtStatus_t NvmCtxMgmtRestore(void);


#ifdef __cplusplus
}
#endif

#endif /* __NVMCTXMGMT_H__ */

/*! \} defgroup NVMCTXMGMT */
