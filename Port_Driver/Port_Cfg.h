/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohannad Sabry
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*====================================================================
                     File Version Information
=====================================================================*/

/*
 * AUTOSAR Version 4.0.3
*/
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/*
 * Module Version 1.0.0
*/
#define PORT_CFG_SW_MAJOR_VERSION             (1U)
#define PORT_CFG_SW_MINOR_VERSION             (0U)
#define PORT_CFG_SW_PATCH_VERSION             (0U)

/*====================================================================
                     Configuration Parameters
=====================================================================*/

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                  (STD_ON)

/* Pre-processor switch to enable / disable the use of the function */
#define PORT_SET_PIN_DIRECTION_API             (STD_ON)

/* Pre-processor switch to enable / disable the use of the function */
#define PORT_SET_PIN_MODE_API                  (STD_ON)

/* Pre-processor switch to enable / disable the use of the function */
#define PORT_VERSION_INFO_API                  (STD_ON)

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_PINS                    (43U)

/*Parameter to indicate if the direction is changeable on a port pin during runtime*/
#define PortConf_LED1_PIN_DIRECTION_CHANGEABLE  (STD_ON)

/*Parameter to indicate if the direction is changeable on a port pin during runtime*/
#define PortConf_SW1_PIN_DIRECTION_CHANGEABLE   (STD_ON)

/*Parameter to indicate if the mode is changeable on a port pin during runtime*/
#define PortConf_LED1_PIN_MODE_CHANGEABLE       (STD_ON)

/*Parameter to indicate if the mode is changeable on a port pin during runtime*/
#define PortConf_SW1_PIN_MODE_CHANGEABLE        (STD_ON)

#endif /* PORT_CFG_H_ */
