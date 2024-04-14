/******************************************************************************
*
* Module: Dio
*
* File Name: Dio.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
*
* Author: Mohannad Sabry
******************************************************************************/

/*====================================================================
                        Include files
=====================================================================*/

#include "Dio.h"
#include "Dio_Regs.h"

#include "Det.h"

/* AUTOSAR Version checking between Det and Dio Modules */
#if((DIO_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
  ||(DIO_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
  ||(DIO_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
        #error " The AR version of Det.h does not match the expected version "
#endif

/*====================================================================
                        Global Variables
=====================================================================*/

STATIC const Dio_ConfigChannel * Dio_PortChannels = NULL_PTR;
STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/
void Dio_Init(const Dio_ConfigType* ConfigPtr){

#if(DIO_DEV_ERROR_DETECT==STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if(ConfigPtr==NULL_PTR){
        /* report det error that the input configuration pointer is a null pointer */
        Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_INIT_SID,DIO_E_PARAM_CONFIG);
    }
    else
#endif
    {
        /* make Dio_PortChannels point to first location of array of struct */
        Dio_PortChannels=ConfigPtr->Channels;
        /* Set status to Initialized*/
        Dio_Status=DIO_INITIALIZED;
    }
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level){
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error=FALSE;
#if(DIO_DEV_ERROR_DETECT==STD_ON)
    /* Check that Dio was initialized before use*/
    if(Dio_Status == DIO_NOT_INITIALIZED){
        /* Report a Det error that Dio used without initialization */
        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
        /* set error to true */
        error = TRUE;
    }
    else{
        /* Do nothing */
    }
    if(ChannelId>=DIO_CONFIGURED_CHANNLES){
        /* Report a Det error that channel was given not in the range (0,DIO_CONFIGURED_CHANNLES-1) */
        Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
        /* set error to true */
        error=TRUE;
    }
    else{
        /* Do nothing */
    }
#endif

    if(error==FALSE){
        switch(Dio_PortChannels[ChannelId].Port_Num){
            case PORTA: Port_Ptr=&GPIO_PORTA_DATA_REG;
            break;
            case PORTB: Port_Ptr=&GPIO_PORTB_DATA_REG;
            break;
            case PORTC: Port_Ptr=&GPIO_PORTC_DATA_REG;
            break;
            case PORTD: Port_Ptr=&GPIO_PORTD_DATA_REG;
            break;
            case PORTE: Port_Ptr=&GPIO_PORTE_DATA_REG;
            break;
            case PORTF: Port_Ptr=&GPIO_PORTF_DATA_REG;
            break;
        }
        if(Level==STD_HIGH){
            /* Write Logic High */
            SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
        }
        else if(Level==STD_LOW){
            /* Write Logic low */
            CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
        }
    }
    else{
        /* Do nothing */
    }

}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
    volatile uint32 * Port_Ptr = NULL_PTR;
    boolean error=FALSE;
    Dio_LevelType output=STD_LOW;
#if(DIO_DEV_ERROR_DETECT==STD_ON)
    if(Dio_Status==DIO_NOT_INITIALIZED){
        /* Report a Det error that Dio used without initialization */
        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
        /* set error to true */
        error = TRUE;
    }
    else{
        /* Do nothing */
    }
    if(ChannelId>=DIO_CONFIGURED_CHANNLES){
        /* Report a Det error that channel was given not in the range (0,DIO_CONFIGURED_CHANNLES-1) */
        Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
        /* set error to true */
        error = TRUE;
    }
    else{
        /* Do nothing */
    }
#endif
    if(error==FALSE){
        switch(Dio_PortChannels[ChannelId].Port_Num){
            case PORTA: Port_Ptr=&GPIO_PORTA_DATA_REG;
            break;
            case PORTB: Port_Ptr=&GPIO_PORTB_DATA_REG;
            break;
            case PORTC: Port_Ptr=&GPIO_PORTC_DATA_REG;
            break;
            case PORTD: Port_Ptr=&GPIO_PORTD_DATA_REG;
            break;
            case PORTE: Port_Ptr=&GPIO_PORTE_DATA_REG;
            break;
            case PORTF: Port_Ptr=&GPIO_PORTF_DATA_REG;
            break;
        }
        /* Read the required channel */
        output=GET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
    }
    else{
        /* Do nothing */
    }
    return output;
}

/************************************************************************************
* Service Name: Dio_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/
#if(DIO_VERSION_INFO_API==STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo){
    boolean error=TRUE;
#if(DIO_DEV_ERROR_DETECT==STD_ON)
    /* check if the versioninfo pointer is not a NULL_PTR */
    if(versioninfo==NULL_PTR){
        /* Report a Det error that versioninfo pointer is a null pointer*/
        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
        error=TRUE;
    }
    else{
      /* Do nothing */
    }
#endif
    if(error==FALSE){
        /* Copy the module Id */
        versioninfo->moduleID=(uint16)DIO_MODULE_ID;
        /* Copy the vendor Id */
        versioninfo->vendorID=(uint16)DIO_VENDOR_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version=(uint8)DIO_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version=(uint8)DIO_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version=(uint8)DIO_SW_PATCH_VERSION;
    }
    else{
        /* do nothing */
    }
}
#endif

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
    volatile uint32 *Port_Ptr=NULL_PTR;
    boolean error=FALSE;
    Dio_LevelType output=STD_LOW;
#if(DIO_DEV_ERROR_DETECT==STD_ON)
    if(Dio_Status==DIO_INITIALIZED){
        /* Report a Det error that Dio used without initialization */
        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
        /* set error to true */
        error = TRUE;
    }
    else{
        /* Do nothing */
    }
    if(ChannelId>=DIO_CONFIGURED_CHANNLES){
        /* Report a Det error that channel was given not in the range (0,DIO_CONFIGURED_CHANNLES-1) */
        Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
        /* set error to true */
        error = TRUE;
    }
    else{
        /* Do nothing */
    }
#endif

    if(error==FALSE){
        switch(Dio_PortChannels[ChannelId].Port_Num){
            case PORTA: Port_Ptr=&GPIO_PORTA_DATA_REG;
            break;
            case PORTB: Port_Ptr=&GPIO_PORTB_DATA_REG;
            break;
            case PORTC: Port_Ptr=&GPIO_PORTC_DATA_REG;
            break;
            case PORTD: Port_Ptr=&GPIO_PORTD_DATA_REG;
            break;
            case PORTE: Port_Ptr=&GPIO_PORTE_DATA_REG;
            break;
            case PORTF: Port_Ptr=&GPIO_PORTF_DATA_REG;
            break;
        }
        TOGGLE_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
        output=GET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
    }
    else{
        /* Do nothing */
    }

    return output;
}
#endif




