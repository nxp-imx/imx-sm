/**
*   @file    Reg_eSys_Vfccu_MIMX9.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - VFCCU register definitions
*   @details VFCCU HW-related definition
*
*   @addtogroup EMCEM_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX9XX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.8.4
*   Build Version        : MIMX9_SAF_0_8_4_20250110
*
*   Copyright 2012-2014 Freescale
*   Copyright 2016, 2018-2020, 2023-2025 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef REG_ESYS_VFCCU_MIMX9_H
#define REG_ESYS_VFCCU_MIMX9_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section Reg_eSys_Vfccu_MIMX9_h_REF_0409
* Violates MISRA 2012 Advisory Rule 4.9, Used to address array of similar registers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
#include "SafetyBase.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_VFCCU_REG_SW_MAJOR_VERSION             0
#define EMCEM_VFCCU_REG_SW_MINOR_VERSION             8
#define EMCEM_VFCCU_REG_SW_PATCH_VERSION             4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_REG_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_REG_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_REG_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Reg_eSys_Vfccu_MIMX9.h and MIMX9XX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*
*  VFCCU BASE ADDRESS
*/
#define FCCU_BASE_ADDRESS                  0x44570000UL

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*
*  VFCCU Fault Reaction Set Configuration Register - R/W
*/
#define FCCU_FHFLTRKC0_0_ADDR32            (FCCU_BASE_ADDRESS + 0x140090U)
/* @violates @ref Reg_eSys_Vfccu_MIMX9_h_REF_0409 */
#define FCCU_FHFLTRKC0_ADDR32(add)         ((sBase_PointerSizeType)(FCCU_FHFLTRKC0_0_ADDR32 + (((uint32)(add)) << 2UL)))

/*
*  VFCCU Immediate Reaction Configuration Register - R/W
*/
#define FCCU_FHIMRKC0_00_ADDR32            (FCCU_BASE_ADDRESS + 0x140290U)
/* @violates @ref Reg_eSys_Vfccu_MIMX9_h_REF_0409 */
#define FCCU_FHIMRKC0_ADDR32(add)          ((sBase_PointerSizeType)(FCCU_FHIMRKC0_00_ADDR32 + (((uint32)(add)) << 5UL)))

/*
*  VFCCU Delayed Reaction Configuration Register - R/W
*/
#define FCCU_FHDLRKC0_00_ADDR32            (FCCU_BASE_ADDRESS + 0x1402A0U)
/* @violates @ref Reg_eSys_Vfccu_MIMX9_h_REF_0409 */
#define FCCU_FHDLRKC0_ADDR32(add)          ((sBase_PointerSizeType)(FCCU_FHDLRKC0_00_ADDR32 + (((uint32)(add)) << 5UL)))

/*
*  VFCCU Fault Status Register - R/W
*/
#define FCCU_FHFLTS0_0_ADDR32              (FCCU_BASE_ADDRESS + 0x140050U)
/* @violates @ref Reg_eSys_Vfccu_MIMX9_h_REF_0409 */
#define FCCU_FHFLTS0_ADDR32(add)           ((sBase_PointerSizeType)(FCCU_FHFLTS0_0_ADDR32 + (((uint32)(add)) << 2UL)))

/*
*  VFCCU Global Fault Recovery Register - R/W
*/
#define FCCU_GFLTRC_C0_ADDR32              (FCCU_BASE_ADDRESS + 0x440U)
/* @violates @ref Reg_eSys_Vfccu_MIMX9_h_REF_0409 */
#define FCCU_GFLTRC_ADDR32(add)            ((sBase_PointerSizeType)(FCCU_GFLTRC_C0_ADDR32 + (((uint32)(add)) << 2UL)))

/*
*  VFCCU Fault Handler Register - R/W
*/
#define FCCU_FHCFG0_ADDR32                 (FCCU_BASE_ADDRESS + 0x140000U)

/*
*  VFCCU Fault Handler Status Register - R
*/
#define FCCU_FHSRVDS0_ADDR32               (FCCU_BASE_ADDRESS + 0x140004U)


/* Width of FCCU registers (bits), and corresponding shifts and masks */
#define FCCU_REG_SIZE_U8                   (32U)
#define FCCU_REG_SIZE_BYTE_U8              (4U)
#define FCCU_REG_SHIFT_U8                  (5U)
#if((1UL << FCCU_REG_SHIFT_U8)) != FCCU_REG_SIZE_U8
    #error "FCCU_REG_SIZE_U8 and FCCU_REG_SHIFT_U8 do not correspond."
#endif
#define FCCU_REG_MASK_U8                   (FCCU_REG_SIZE_U8 - 1U)
#define FCCU_REG_SHIFT_U3                  (2UL)
#define FCCU_REG_SIZE_U3                   (8UL)
#define FCCU_REG_MASK_U3                   ((uint32)(FCCU_REG_SIZE_U3 - 1UL))
#define FCCU_REACTION_SETS_PER_REG         (4U)
#define FCCU_SHIFT_REACTION_SET_IN_REG     (8U)

#if ( SAFETY_BASE_MIMX95XX || SAFETY_BASE_MIMX952X )
#define FCCU_IRQ0_3_REACT_MASK             ((uint32)(0x0000001CUL))    /* FCCU Interrupt 0...3 Reaction Handler mask */
#define FCCU_IRQ0_REACT_MASK               ((uint32)(0x00000004UL))    /* FCCU Interrupt 0 Reaction Handler mask */
#define FCCU_RES_REACT_MASK                ((uint32)(0x00000100UL))    /* FCCU Reset Reaction Handler mask */
#elif SAFETY_BASE_MIMX943X
#define FCCU_IRQ0_3_REACT_MASK             ((uint32)(0x0000007CUL))    /* FCCU Interrupt 0...5 Reaction Handler mask */
#define FCCU_IRQ0_REACT_MASK               ((uint32)(0x00000004UL))    /* FCCU Interrupt 0 Reaction Handler mask */
#define FCCU_RES_REACT_MASK                ((uint32)(0x00001000UL))    /* FCCU Reset Reaction Handler mask */
#endif /* SAFETY_BASE_MIMX9XXX */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_VFCCU_MIMX9_H */

/** @} */
