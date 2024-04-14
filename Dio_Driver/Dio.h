/******************************************************************************
*
* Module: Dio
*
* File Name: Dio.h
*
* Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Mohannad Sabry
******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/*====================================================================
                     File Version Information
=====================================================================*/

/* Vendor Id */
#define DIO_VENDOR_ID                 (5000U)

/* Dio Module Id */
#define DIO_MODULE_ID                 (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID                (0U)

/* Autosar Version 4.0.3 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/* Module Version 1.0.0 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*====================================================================
                        Include files
=====================================================================*/

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
   ||(DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
   ||(DIO_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
        #error "Autosar Version Numbers are diffrent between Dio.h and Std_types.h"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR checking between Dio.h and Dio_Cfg.h */
#if((DIO_AR_RELEASE_MAJOR_VERSION != DIO_CFG_AR_RELEASE_MAJOR_VERSION)\
  ||(DIO_AR_RELEASE_MINOR_VERSION != DIO_CFG_AR_RELEASE_MINOR_VERSION)\
  ||(DIO_AR_RELEASE_PATCH_VERSION != DIO_CFG_AR_RELEASE_PATCH_VERSION))
        #error "Autosar Version Numbers are diffrent between Dio.h and Dio_Cfg.h"
#endif

/* SW checking between Dio.h and Dio_Cfg.h */
#if((DIO_SW_MAJOR_VERSION != DIO_CFG_SW_MAJOR_VERSION)\
  ||(DIO_SW_MINOR_VERSION != DIO_CFG_SW_MINOR_VERSION)\
  ||(DIO_SW_PATCH_VERSION != DIO_CFG_SW_PATCH_VERSION))
        #error "Sw Version Numbers are diffrent between Dio.h and Dio_Cfg.h"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/*====================================================================
                        API Service Id Macros
=====================================================================*/

/* Serive Id for Dio Read Channel Api */
#define DIO_READ_CHANNEL_SID            (uint8)(0x00)

/* Serive Id for Dio Write Channel Api */
#define DIO_WRITE_CHANNEL_SID           (uint8)(0x01)

/* Serive Id for Dio Read Port Api */
#define DIO_READ_PORT_SID               (uint8)(0x02)

/* Serive Id for Dio Write Port Api */
#define DIO_WRITE_PORT_SID              (uint8)(0x03)

/* Serive Id for Dio Read Channel Group Api */
#define DIO_READ_CHANNEL_GROUP_SID      (uint8)(0x04)

/* Serive Id for Dio Write Channel Group Api */
#define DIO_WRITE_CHANNEL_GROUP_SID     (uint8)(0x05)

/* Serive Id for Dio GetVersionInfo Api */
#define DIO_GET_VERSION_INFO_SID        (uint8)(0x12)

/*Servie Id for Dio Init Api*/
#define DIO_INIT_SID                    (uint8)(0x10)

/*Servie Id for Dio Flip Channel Api*/
#define DIO_FLIP_CHANNEL_SID            (uint8)(0x11)

/*====================================================================
                        DET Error Codes
=====================================================================*/

/* Det Error Code to report Invalid Channel Name */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  (uint8)(0x0A)

/* Det Error Code to report API Service called with “NULL Pointer” Parameter*/
#define DIO_E_PARAM_CONFIG              (uint8)(0x10)

/* Det Error Code to report Invalid port name requested*/
#define DIO_E_PARAM_INVALID_PORT_ID     (uint8)(0x14)

/* Det Error code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP       (uint8)(0x1F)

/*
 * API service called with a NULL pointer.
 * In case of this error, the API service shall return immediately without any further action,
 * beside reporting this development error
*/
#define DIO_E_PARAM_POINTER             (uint8)(0x20)

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8)0xF0
/*====================================================================
                     Macros for Dio Status
=====================================================================*/

#define DIO_INITIALIZED                         (1U)
#define DIO_NOT_INITIALIZED                     (0U)

/*====================================================================
                       Module Data Types
=====================================================================*/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* These are the possible levels a DIO channel can have (input or output) */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint8 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;

} Dio_ChannelGroupType;

typedef struct{

    /* Member contains the ID of the Port that this channel belongs to */
    Dio_PortType Port_Num;

    /* Member contains the ID of the Channel*/
    Dio_ChannelType Ch_Num;

}Dio_ConfigChannel;

typedef struct{
    Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
}Dio_ConfigType;

/* this is added enumeration (no in autosar document) to avoid magic numbers */
typedef enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}PORTS;

/*====================================================================
                      Function Prototypes
=====================================================================*/

/* Returns the value of the specified DIO channel. */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Service to set a level of a channel. */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Returns the level of all channels of that port. */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

/* Service to set a value of the port. */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Leve);

/* This Service reads a subset of the adjoining bits of a port. */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr );

/* Service to set a subset of the adjoining bits of a port to a specified level. */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);

/* Initializes the module. */
void Dio_Init(const Dio_ConfigType* ConfigPtr);

#if(DIO_VERSION_INFO_API==STD_ON)
    /* Service to get the version information of this module. */
    void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

#if(DIO_FLIP_CHANNEL_API==STD_ON)
    /*Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip. */
    Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/*====================================================================
                      External Variables
=====================================================================*/

/* Extern PB structures to be used by Dio and other modules */
extern Dio_ConfigType Dio_Configuration;

#endif /* DIO_H_ */
