/******************************************************************************
 *
 * Module: Det
 *
 * File Name: Det.h
 *
 * Description:  Det stores the development errors reported by other modules.
 *               This header file is a STUB for the Det Module
 *
 * Author: Mohannad Sabry
 ******************************************************************************/

#ifndef DET_H_
#define DET_H_



/*====================================================================
                     File Version Information
=====================================================================*/

/*
 *Vendor Id
*/
#define DET_VENDOR_ID                       (1000U)

/* Det Module Id */
#define DET_MODULE_ID                       (15U)

/* Instance Id */
#define DET_INSTANCE_ID                      (0U)

/*
 * Module Version 1.0.0
*/
#define DET_SW_MAJOR_VERSION                (1U)
#define DET_SW_MINOR_VERSION                (0U)
#define DET_SW_PATCH_VERSION                (0U)

/*
 *AUTOSAR Version 4.0.3
*/
#define DET_AR_RELEASE_MAJOR_VERSION        (4U)
#define DET_AR_RELEASE_MINOR_VERSION        (0U)
#define DET_AR_RELEASE_PATCH_VERSION        (3U)

/*====================================================================
                        Include files
=====================================================================*/
#include "Std_Types.h"

/*
  * Compatability check when file includes another file. (parent always make the compatability check)
*/
#if(  (DET_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
   || (DET_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
   || (DET_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
   #error "Autosar Version Numbers of Det and Std_types are diffrent "

#endif

/*====================================================================
                     External Variables
=====================================================================*/

extern uint16 Det_ModuleId;       /*DET module ID*/
extern uint8 Det_InstanceId;      /*DET instance ID*/
extern uint8 Det_ApiId;           /* DET API ID*/
extern uint8 Det_ErrorId;         /* DET Error ID*/

/*====================================================================
                       Function Prototypes
=====================================================================*/
Std_ReturnType Det_ReportError( uint16 ModuleId,
                                uint8 InstanceId,
                                uint8 ApiId,
                                uint8 ErrorId );


#endif /* DET_H_ */
