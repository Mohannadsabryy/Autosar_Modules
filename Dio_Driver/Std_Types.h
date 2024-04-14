/******************************************************************************
 *
 * Module: Common - Platform
 *
 * File Name: Std_Types.h
 *
 * Description: General type definitions
 *
 * Author: Mohannad Sabry
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*====================================================================
                     File Version Information
=====================================================================*/

/*
 * Vendor Id
 */
#define STD_TYPES_VENDOR_ID                  (1000U)

/*
 * Module Version 1.0.0
*/
#define STD_TYPES_SW_MAJOR_VERSION            (1U)
#define STD_TYPES_SW_MINOR_VERSION            (0U)
#define STD_TYPES_SW_PATCH_VERSION            (0U)

/*
 *AUTOSAR Version 4.0.3
*/
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION    (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION    (0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION    (3U)

/*====================================================================
                        Include files
=====================================================================*/
#include "Platform_Types.h"
#include "Compiler.h"

/*
  * Compatability check when file includes another file. (parent always make the compatability check)
*/

#if((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION ))
     #error "Autosar Version numbers of Std_Types.h and Platform_Types.h are diffrent"
#endif

#if((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)|| \
    (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION ))
      #error "Autosar Version numbers of Std_Types.h and Compiler.h are diffrent"
#endif

/*====================================================================
                        Constants
=====================================================================*/

/*
  * This type can be used as standard API return type which is shared between the RTE and the BSW modules.
*/
typedef uint8 Std_ReturnType;

/*
 * This type shall be used to request the version of a
 * BSW module using the <Module name>_GetVersionInfo()
 * function.
*/
typedef struct
{
        uint16 vendorID;
        uint16 moduleID;
        uint8 sw_major_version;
        uint8 sw_minor_version;
        uint8 sw_patch_version;
} Std_VersionInfoType;

#define   STD_HIGH         (0x01U)  /* Physical state 5V or 3.3V */
#define   STD_LOW          (0x00U)  /* Physical state 0V         */

#define   STD_ACTIVE       (0x01U)  /* Logical state active */
#define   STD_IDLE         (0x00U)  /* Logical state idle */

#define   STD_ON           (0x01U)  /* Standard ON */
#define   STD_OFF          (0x00U)  /* Standard OFF */

#define   E_OK             ((Std_ReturnType)0x00U)   /* Function Return OK */
#define   E_NOT_OK         ((Std_ReturnType)0x01U)   /* Function Return Not OK*/

#endif /* STD_TYPES_H_ */
