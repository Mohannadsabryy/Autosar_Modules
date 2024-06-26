/******************************************************************************
*
* Module: Dio
*
* File Name: Dio_Cfg.h
*
* Description: Pre Compile Configuration header file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Mohannad Sabry
******************************************************************************/

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*====================================================================
                     File Version Information
=====================================================================*/

/* Autosar Version 4.0.3 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION   (3U)

/* Module Version 1.0.0 */
#define DIO_CFG_SW_MAJOR_VERSION           (1U)
#define DIO_CFG_SW_MINOR_VERSION           (0U)
#define DIO_CFG_SW_PATCH_VERSION           (0U)

/*====================================================================
                     Configuration Parameters
=====================================================================*/

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES            (4U)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API               STD_ON

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API               STD_ON

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT               STD_ON


/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x02
#define DioConf_SW2_CHANNEL_ID_INDEX         (uint8)0x03

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)5 /* PORTF */
#define DioConf_LED2_PORT_NUM                (Dio_PortType)5 /* PORTF */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)5 /* PORTF */
#define DioConf_SW2_PORT_NUM                 (Dio_PortType)5 /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_LED2_CHANNEL_NUM             (Dio_ChannelType)2 /* Pin 2 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)4 /* Pin 0 in PORTF */
#define DioConf_SW2_CHANNEL_NUM              (Dio_ChannelType)0 /* Pin 0 in PORTF */

#endif /* DIO_CFG_H_ */
