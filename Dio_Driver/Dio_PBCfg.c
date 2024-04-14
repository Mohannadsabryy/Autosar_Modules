/******************************************************************************
*
* Module: Dio
*
* File Name: Dio_PBcfg.c
*
* Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Mohannad Sabry
******************************************************************************/

/*====================================================================
                     File Version Information
=====================================================================*/

/* Autosar Version 4.0.3 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION      (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION      (0U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION      (3U)

/* Module Version 1.0.0 */
#define DIO_PBGFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/*====================================================================
                        Include files
=====================================================================*/

#include "Dio.h"

/* AUTOSAR checking between Dio.h and Dio_PBCfg.c */
#if((DIO_AR_RELEASE_MAJOR_VERSION != DIO_PBCFG_AR_RELEASE_MAJOR_VERSION)\
  ||(DIO_AR_RELEASE_MINOR_VERSION != DIO_PBCFG_AR_RELEASE_MINOR_VERSION)\
  ||(DIO_AR_RELEASE_PATCH_VERSION != DIO_PBCFG_AR_RELEASE_PATCH_VERSION))
        #error "Autosar Version Numbers are diffrent between Dio.h and Dio_PBCfg.c"
#endif

/* AUTOSAR checking between Dio.h and Dio_PBCfg.c */
#if ((DIO_SW_MAJOR_VERSION != DIO_PBGFG_SW_MAJOR_VERSION)\
 ||  (DIO_SW_MINOR_VERSION != DIO_PBCFG_SW_MINOR_VERSION)\
 ||  (DIO_SW_PATCH_VERSION != DIO_PBCFG_SW_PATCH_VERSION))
    #error "SW Version Numbers are diffrent between Dio.h and Dio_PBCfg.h"
#endif


/* PB structure used with Dio_Init API */
Dio_ConfigType Dio_Configuration={
                                  {DioConf_LED1_PORT_NUM,DioConf_LED1_CHANNEL_NUM},
                                  {DioConf_LED2_PORT_NUM,DioConf_LED2_CHANNEL_NUM},
                                  {DioConf_SW1_PORT_NUM,DioConf_SW1_CHANNEL_NUM},
                                  {DioConf_SW2_PORT_NUM,DioConf_SW2_CHANNEL_NUM}
};
