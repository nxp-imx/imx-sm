/**************************************************************************
 * FILE NAME: SafetyBase_MIMX952X_SAF.h                                   *
 * REVISION:  1.0                                                         *
 *                                                                        *
 * DESCRIPTION:                                                           *
 * This file contains all of the register and bit field definitions for   *
 * the ip_params_top.                                                     *
 *========================================================================*
 * UPDATE HISTORY                                                         *
 * REV     AUTHOR     DATE          DESCRIPTION OF CHANGE                 *
 * 0       nxf85804   30-Jan-2025   Initial revision                      *
 * 1       nxf85804   13-Mar-2025   Clean unused structures               *
 *                                                                        *
 *========================================================================*
 * Copyright 2026 NXP                                                *
 * Detailed license terms of software usage can be found in the           *
 * license.txt file located in the root folder of this package.           *
 *                                                                        *
 **************************************************************************/
/**************************************************************************
 * Example register & bit field write:                                    *
 *                                                                        *
 *  <MODULE>.<REGISTER>.B.<BIT> = 1;                                      *
 *  <MODULE>.<REGISTER>.R       = 0x10000000;                             *
 *                                                                        *
 **************************************************************************/

#ifndef _SafetyBase_MIMX952X_SAF_H_
#define _SafetyBase_MIMX952X_SAF_H_
#include "Std_Types.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif
#ifdef __ghs__
#pragma ghs nowarning 618
#endif
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma pack(push,1)
#endif

#include "SafetyBase_Cfg.h"

/*=============================================================================
*                               DEFINES AND MACROS
===============================================================================*/
#if SAFETY_BASE_MIMX952X

/* EIM */
#define EIM_EICHD_WORDS_PER_CHANNEL (9U)                /* Maximum number ofWords per Error Injection Channel */
#define EIM_CHANNELS_COUNT          (32U)               /* Number of Error Injection Channels */

/* NVIC */
#define NVIC_BASEADDR                          (0xE000E100UL)
#define NVIC_ISER_OFFSET(id)                   ((uint8)((id >> 5) << 2))
#define NVIC_ICER_OFFSET(id)                   ((0x80UL + (uint8)((id >> 5) << 2)))
#define NVIC_FCCU_IRQ0                         (210UL)
#define NVIC_FCCU_IRQ1                         (211UL)
#define NVIC_FCCU_IRQ2                         (212UL)
#define NVIC_FCCU_IRQ0_MASK                    (1UL << (NVIC_FCCU_IRQ0 % 32UL))
#define NVIC_FCCU_IRQ1_MASK                    (1UL << (NVIC_FCCU_IRQ1 % 32UL))
#define NVIC_FCCU_IRQ2_MASK                    (1UL << (NVIC_FCCU_IRQ2 % 32UL))
#define NVIC_FCCU_IRQ_MASKS                    (NVIC_FCCU_IRQ0_MASK |\
                                                NVIC_FCCU_IRQ1_MASK |\
                                                NVIC_FCCU_IRQ2_MASK)
#define NVIC_ISER_FCCU_IRQ_ADDR                (NVIC_BASEADDR + NVIC_ISER_OFFSET(NVIC_FCCU_IRQ0))
#define NVIC_ICER_FCCU_IRQ_ADDR                (NVIC_BASEADDR + NVIC_ICER_OFFSET(NVIC_FCCU_IRQ0))

/* ============================================================================
   =============================== Module: CACHE_ECC_MCM ======================
   ============================================================================ */

typedef union CACHE_ECC_MCM_CACHE_ECCR_union_tag { /* CACHE ECC Control */
  volatile uint32 R;
  struct {
    volatile uint32 WECC_DIS:1;              /* Disable CACHE ECC Write Generation */
    volatile uint32 RECC_DIS:1;              /* Disable Cache ECC Read Check */
    volatile uint32 _unused_0:30;
  } B;
} CACHE_ECC_MCM_CACHE_ECCR_tag;

typedef union CACHE_ECC_MCM_INT_STATUS_union_tag { /* Interrupt Status */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_24:8;
    volatile uint32 CODE_CACHE_ECC_ERRM_INT:1; /* Code Cache Access Multibit ECC Error Interrupt Status */
    volatile uint32 CODE_CACHE_ECC_ERRS_INT:1; /* Code Cache Access Single-Bit ECC Error Interrupt Status */
    volatile uint32 CODE_CACHE_ECC_ERRM_OVER_INT:1; /* Code Cache Access Multiple Multibit ECC Error Interrupt Status */
    volatile uint32 CODE_CACHE_ECC_ERRS_OVER_INT:1; /* Code Cache Access Multiple Single-Bit ECC Error Interrupt Status */
    volatile uint32 SYSTEM_CACHE_ECC_ERRM_INT:1; /* System Cache Access Multibit ECC Error Interrupt Status */
    volatile uint32 SYSTEM_CACHE_ECC_ERRS_INT:1; /* System Cache Access Single-Bit ECC Error Interrupt Status */
    volatile uint32 SYSTEM_CACHE_ECC_ERRM_OVER_INT:1; /* System Cache Access Multiple Multibit ECC Error Interrupt Status */
    volatile uint32 SYSTEM_CACHE_ECC_ERRS_OVER_INT:1; /* System Cache Access Multiple Single-Bit ECC Error Interrupt Status */
    volatile uint32 _unused_0:16;
  } B;
} CACHE_ECC_MCM_INT_STATUS_tag;

typedef union CACHE_ECC_MCM_INT_STAT_EN_union_tag { /* Interrupt Status Enable */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_24:8;
    volatile uint32 CODE_CACHE_ERRM_INT_EN:1; /* Code Cache Access Multibit ECC Error Interrupt Status Enable */
    volatile uint32 CODE_CACHE_ERRS_INT_EN:1; /* Code Cache Access Single-Bit ECC Error Interrupt Status Enable */
    volatile uint32 CODE_CACHE_ERRM_OVER_INT_EN:1; /* Code Cache Access Multiple Multibit ECC Error Interrupt Status Enable */
    volatile uint32 CODE_CACHE_ERRS_OVER_INT_EN:1; /* Code Cache Access Multiple Single-Bit ECC Error Interrupt Status Enable */
    volatile uint32 SYSTEM_CACHE_ECC_ERRM_INT_EN:1; /* System Cache Access Multibit ECC Error Interrupt Status Enable */
    volatile uint32 SYSTEM_CACHE_ECC_ERRS_INT_EN:1; /* System Cache Access Single-Bit ECC Error Interrupt Status Enable */
    volatile uint32 SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN:1; /* System Cache Access Multiple Multibit ECC Error Interrupt Status Enable */
    volatile uint32 SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN:1; /* System Cache Access Multiple Single-Bit ECC Error Interrupt Status Enable */
    volatile uint32 _unused_0:16;
  } B;
} CACHE_ECC_MCM_INT_STAT_EN_tag;

typedef union CACHE_ECC_MCM_INT_SIG_EN_union_tag { /* Interrupt Enable */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_24:8;
    volatile uint32 CODE_CACHE_ERRM_INT_SIG_EN:1; /* Code Cache Access Multibit ECC Error Interrupt Signal Enable */
    volatile uint32 CODE_CACHE_ERRS_INT_SIG_EN:1; /* Code Cache Access Single-Bit ECC Error Interrupt Signal Enable */
    volatile uint32 CODE_CACHE_ERRM_OVER_INT_SIG_EN:1; /* Code Cache Access Multiple Multibit ECC Error Interrupt Signal Enable */
    volatile uint32 CODE_CACHE_ERRS_OVER_INT_SIG_EN:1; /* Code Cache Access Multiple Single-Bit ECC Error Interrupt Signal Enable */
    volatile uint32 SYSTEM_CACHE_ERRM_INT_SIG_EN:1; /* System Cache Access Multibit ECC Error Interrupt Signal Enable */
    volatile uint32 SYSTEM_CACHE_ERRS_INT_SIG_EN:1; /* System Cache Access Single-Bit ECC Error Interrupt Signal Enable */
    volatile uint32 SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN:1; /* System Cache Access Multiple Multibit ECC Error Interrupt Signal Enable */
    volatile uint32 SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN:1; /* System Cache Access Multiple Single-Bit ECC Error Interrupt Signal Enable */
    volatile uint32 _unused_0:16;
  } B;
} CACHE_ECC_MCM_INT_SIG_EN_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_union_tag { /* Code Cache Single-Bit ECC Error Information */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_ECCS_TAG:1;   /* Code Cache Single-Bit ECC Error */
    volatile uint32 CODE_CACHE_ECCS_CMD:1;   /* Code Cache Single-Bit ECC Error on Cache Command */
    volatile uint32 _unused_28:2;
    volatile uint32 CODE_CACHE_ECCS_EFMST:4; /* Code Cache Single-Bit ECC Error Master Number */
    volatile uint32 CODE_CACHE_ECCS_EFPRT:6; /* Code Cache Single-Bit ECC Error Protection */
    volatile uint32 _unused_16:2;
    volatile uint32 CODE_CACHE_ECCS_EFSYN:7; /* Code Cache Single-Bit ECC Error Corresponding Syndrome */
    volatile uint32 _unused_0:9;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_union_tag { /* Code Cache Single-Bit ECC Error Address */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_ECCS_ERRED_ADDR:32; /* Code Cache Single-Bit ECC Error Address */
  } B;
} CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_union_tag { /* Code Cache Multibit ECC Error Information */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_ECCM_TAG:1;   /* Code Cache Multibit ECC Error */
    volatile uint32 CODE_CACHE_ECCM_CMD:1;   /* Code Cache Multibit ECC Error on Code Cache Command */
    volatile uint32 _unused_28:2;
    volatile uint32 CODE_CACHE_ECCM_EFMST:4; /* Code Cache Multibit ECC Error Master Number */
    volatile uint32 CODE_CACHE_ECCM_EFPRT:6; /* Code Cache Multibit ECC Error Protection */
    volatile uint32 _unused_16:2;
    volatile uint32 CODE_CACHE_ECCM_EFSYN:7; /* Code Cache Multibit ECC Error Corresponding Syndrome */
    volatile uint32 _unused_0:9;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_union_tag { /* System Cache Single-Bit ECC Error Information */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_ECCS_TAG:1; /* System Cache Single-Bit ECC Error */
    volatile uint32 SYSTEM_CACHE_ECCS_CMD:1; /* System Cache Single-Bit ECC Error on Cache Command */
    volatile uint32 _unused_28:2;
    volatile uint32 SYSTEM_CACHE_ECCS_EFMST:4; /* System Cache Single-Bit ECC Error Master Number */
    volatile uint32 SYSTEM_CACHE_ECCS_EFPRT:6; /* System Cache Single-Bit ECC Error Protection */
    volatile uint32 _unused_16:2;
    volatile uint32 SYSTEM_CACHE_ECCS_EFSYN:7; /* System Cache Single-Bit ECC Error Corresponding Syndrome */
    volatile uint32 _unused_0:9;
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_union_tag { /* System Cache Single-Bit ECC Error Address */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_ECCS_ERRED_ADDR:32; /* System Cache Single-Bit ECC Error Address */
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_union_tag { /* System Cache Multibit ECC Error Information */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_ECCM_TAG:1; /* System Cache Multibit ECC Error */
    volatile uint32 SYSTEM_CACHE_ECCM_CMD:1; /* System Cache Multibit ECC Error on System Cache Command */
    volatile uint32 _unused_28:2;
    volatile uint32 SYSTEM_CACHE_ECCM_EFMST:4; /* System Cache Multibit ECC Error Master Number */
    volatile uint32 SYSTEM_CACHE_ECCM_EFPRT:6; /* System Cache Multibit ECC Error Protection */
    volatile uint32 _unused_16:2;
    volatile uint32 SYSTEM_CACHE_ECCM_EFSYN:7; /* System Cache Multibit ECC Error Corresponding Syndrome */
    volatile uint32 _unused_0:9;
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_union_tag { /* System Cache Multibit ECC Error Data */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_ECCM_ERRED_DATA:32; /* System Cache Multibit ECC Error Data */
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_union_tag { /* Code Cache TAG0 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_TAG0_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 CODE_CACHE_TAG0_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 CODE_CACHE_TAG0_FR11BI:1; /* Force One 1-Bit Data Inversion on Code Cache TAG0 Write Access */
    volatile uint32 CODE_CACHE_TAG0_FR1NCI:1; /* Force One Noncorrectable Data Inversion on Code Cache TAG0 Write Access */
    volatile uint32 CODE_CACHE_TAG0_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on Code Cache TAG0 Write Access */
    volatile uint32 CODE_CACHE_TAG0_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on Code Cache TAG0 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_union_tag { /* Code Cache TAG1 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_TAG1_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 CODE_CACHE_TAG1_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 CODE_CACHE_TAG1_FR11BI:1; /* Force One 1-Bit Data Inversion on Code Cache TAG1 Write Access */
    volatile uint32 CODE_CACHE_TAG1_FR1NCI:1; /* Force One Noncorrectable Data Inversion on Code Cache TAG1 Write Access */
    volatile uint32 CODE_CACHE_TAG1_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on Code Cache TAG1 Write Access */
    volatile uint32 CODE_CACHE_TAG1_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on Code Cache TAG1 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_union_tag { /* Code Cache DATA0 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_DATA0_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 CODE_CACHE_DATA0_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 CODE_CACHE_DATA0_FR11BI:1; /* Force One 1-Bit Data Inversion on Code Cache DATA0 Write Access */
    volatile uint32 CODE_CACHE_DATA0_FR1NCI:1; /* Force One Noncorrectable Data Inversion on Code Cache DATA0 Write Access */
    volatile uint32 CODE_CACHE_DATA0_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on Code Cache DATA0 Write Access */
    volatile uint32 CODE_CACHE_DATA0_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on Code Cache DATA0 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_union_tag { /* Code Cache DATA1 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 CODE_CACHE_DATA1_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 CODE_CACHE_DATA1_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 CODE_CACHE_DATA1_FR11BI:1; /* Force One 1-Bit Data Inversion on Code Cache DATA1 Write Access */
    volatile uint32 CODE_CACHE_DATA1_FR1NCI:1; /* Force One Noncorrectable Data Inversion on Code Cache DATA1 Write Access */
    volatile uint32 CODE_CACHE_DATA1_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on Code Cache DATA1 Write Access */
    volatile uint32 CODE_CACHE_DATA1_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on Code Cache DATA1 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_union_tag { /* System Cache TAG0 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_TAG0_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 SYSTEM_CACHE_TAG0_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 SYSTEM_CACHE_TAG0_FR11BI:1; /* Force One 1-Bit Data Inversion on System Cache TAG0 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG0_FR1NCI:1; /* Force One Noncorrectable Data Inversion on System Cache TAG0 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG0_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on System Cache TAG0 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG0_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on System Cache TAG0 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_union_tag { /* System Cache TAG1 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_TAG1_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 SYSTEMCACHE_TAG1_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 SYSTEM_CACHE_TAG1_FR11BI:1; /* Force One 1-Bit Data Inversion on System Cache TAG1 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG1_FR1NCI:1; /* Force One Noncorrectable Data Inversion on System Cache TAG1 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG1_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on System Cache TAG1 Write Access */
    volatile uint32 SYSTEM_CACHE_TAG1_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on System Cache TAG1 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_union_tag { /* System Cache DATA0 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_DATA0_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 SYSTEM_CACHE_DATA0_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 SYSTEM_CACHE_DATA0_FR11BI:1; /* Force One 1-Bit Data Inversion on System Cache DATA0 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA0_FR1NCI:1; /* Force One Noncorrectable Data Inversion on System Cache DATA0 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA0_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on System Cache DATA0 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA0_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on System Cache DATA0 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_union_tag { /* System Cache DATA1 ECC Error Injection */
  volatile uint32 R;
  struct {
    volatile uint32 SYSTEM_CACHE_DATA1_ERR1BIT:7; /* Position of First Bit to Inject ECC Error */
    volatile uint32 _unused_24:1;
    volatile uint32 SYSTEM_CACHE_DATA1_ERR2BIT:7; /* Position of Second Bit to Inject ECC Error */
    volatile uint32 _unused_16:1;
    volatile uint32 SYSTEM_CACHE_DATA1_FR11BI:1; /* Force One 1-Bit Data Inversion on System Cache DATA1 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA1_FR1NCI:1; /* Force One Noncorrectable Data Inversion on System Cache DATA1 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA1_FRC1BI:1; /* Force Continuous 1-Bit Data Inversions on System Cache DATA1 Write Access */
    volatile uint32 SYSTEM_CACHE_DATA1_FRCNCI:1; /* Force Continuous Noncorrectable Data Inversions on System Cache DATA1 Write Access */
    volatile uint32 _unused_0:12;
  } B;
} CACHE_ECC_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_tag;

typedef union CACHE_ECC_MCM_FCCU_SW_FAULTS_union_tag { /* FCCU Software Faults */
  volatile uint32 R;
  struct {
    volatile uint32 FCCU_SW_FAULTS:6;        /* FCCU Software Faults */
    volatile uint32 _unused_0:26;
  } B;
} CACHE_ECC_MCM_FCCU_SW_FAULTS_tag;

struct CACHE_ECC_MCM_tag {
  CACHE_ECC_MCM_CACHE_ECCR_tag CACHE_ECCR; /* CACHE ECC Control */
  uint8 CACHE_ECC_MCM_reserved0[28];
  CACHE_ECC_MCM_INT_STATUS_tag INT_STATUS; /* Interrupt Status */
  CACHE_ECC_MCM_INT_STAT_EN_tag INT_STAT_EN; /* Interrupt Status Enable */
  CACHE_ECC_MCM_INT_SIG_EN_tag INT_SIG_EN; /* Interrupt Enable */
  uint8 CACHE_ECC_MCM_reserved1[48];
  CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_tag CODE_CACHE_ECC_SINGLE_ERROR_INFO; /* Code Cache Single-Bit ECC Error Information */
  CACHE_ECC_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_tag CODE_CACHE_ECC_SINGLE_ERROR_ADDR; /* Code Cache Single-Bit ECC Error Address */
  uint8 CACHE_ECC_MCM_reserved2[4];
  CACHE_ECC_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_tag CODE_CACHE_ECC_MULTI_ERROR_INFO; /* Code Cache Multibit ECC Error Information */
  uint8 CACHE_ECC_MCM_reserved3[8];
  CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_tag SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO; /* System Cache Single-Bit ECC Error Information */
  CACHE_ECC_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_tag SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR; /* System Cache Single-Bit ECC Error Address */
  uint8 CACHE_ECC_MCM_reserved4[4];
  CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_tag SYSTEM_CACHE_ECC_MULTI_ERROR_INFO; /* System Cache Multibit ECC Error Information */
  CACHE_ECC_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_tag SYSTEM_CACHE_ECC_MULTI_ERROR_DATA; /* System Cache Multibit ECC Error Data */
  uint8 CACHE_ECC_MCM_reserved5[4];
  CACHE_ECC_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_tag CODE_CACHE_TAG0_ECC_ERROR_INJEC; /* Code Cache TAG0 ECC Error Injection */
  CACHE_ECC_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_tag CODE_CACHE_TAG1_ECC_ERROR_INJEC; /* Code Cache TAG1 ECC Error Injection */
  CACHE_ECC_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_tag CODE_CACHE_DATA0_ECC_ERROR_INJEC; /* Code Cache DATA0 ECC Error Injection */
  CACHE_ECC_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_tag CODE_CACHE_DATA1_ECC_ERROR_INJEC; /* Code Cache DATA1 ECC Error Injection */
  CACHE_ECC_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_tag SYTEM_CACHE_TAG0_ECC_ERROR_INJEC; /* System Cache TAG0 ECC Error Injection */
  CACHE_ECC_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_tag SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC; /* System Cache TAG1 ECC Error Injection */
  CACHE_ECC_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_tag SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC; /* System Cache DATA0 ECC Error Injection */
  CACHE_ECC_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_tag STSTEM_CACHE_DATA1_ECC_ERROR_INJEC; /* System Cache DATA1 ECC Error Injection */
  CACHE_ECC_MCM_FCCU_SW_FAULTS_tag FCCU_SW_FAULTS; /* FCCU Software Faults */
};


/* ============================================================================
 =============================== Module: EIM ============================
  ============================================================================ */

typedef union EIM_EIMCR_union_tag { /* Error Injection Module Configuration Register */
  volatile uint32 R;
  struct {
    volatile uint32 GEIEN:1;                 /* Global Error Injection Enable */
    volatile uint32 _unused_0:31;            /* Reserved */
  } B;
} EIM_EIMCR_tag;

typedef union EIM_EICHEN_union_tag { /* Error Injection Channel Enable register */
  volatile uint32 R;
  struct {
    volatile uint32 EICH31EN:1;              /* Error Injection Channel 31 Enable */
    volatile uint32 EICH30EN:1;              /* Error Injection Channel 30 Enable */
    volatile uint32 EICH29EN:1;              /* Error Injection Channel 29 Enable */
    volatile uint32 EICH28EN:1;              /* Error Injection Channel 28 Enable */
    volatile uint32 EICH27EN:1;              /* Error Injection Channel 27 Enable */
    volatile uint32 EICH26EN:1;              /* Error Injection Channel 26 Enable */
    volatile uint32 EICH25EN:1;              /* Error Injection Channel 25 Enable */
    volatile uint32 EICH24EN:1;              /* Error Injection Channel 24 Enable */
    volatile uint32 EICH23EN:1;              /* Error Injection Channel 23 Enable */
    volatile uint32 EICH22EN:1;              /* Error Injection Channel 22 Enable */
    volatile uint32 EICH21EN:1;              /* Error Injection Channel 21 Enable */
    volatile uint32 EICH20EN:1;              /* Error Injection Channel 20 Enable */
    volatile uint32 EICH19EN:1;              /* Error Injection Channel 19 Enable */
    volatile uint32 EICH18EN:1;              /* Error Injection Channel 18 Enable */
    volatile uint32 EICH17EN:1;              /* Error Injection Channel 17 Enable */
    volatile uint32 EICH16EN:1;              /* Error Injection Channel 16 Enable */
    volatile uint32 EICH15EN:1;              /* Error Injection Channel 15 Enable */
    volatile uint32 EICH14EN:1;              /* Error Injection Channel 14 Enable */
    volatile uint32 EICH13EN:1;              /* Error Injection Channel 13 Enable */
    volatile uint32 EICH12EN:1;              /* Error Injection Channel 12 Enable */
    volatile uint32 EICH11EN:1;              /* Error Injection Channel 11 Enable */
    volatile uint32 EICH10EN:1;              /* Error Injection Channel 10 Enable */
    volatile uint32 EICH9EN:1;               /* Error Injection Channel 9 Enable */
    volatile uint32 EICH8EN:1;               /* Error Injection Channel 8 Enable */
    volatile uint32 EICH7EN:1;               /* Error Injection Channel 7 Enable */
    volatile uint32 EICH6EN:1;               /* Error Injection Channel 6 Enable */
    volatile uint32 EICH5EN:1;               /* Error Injection Channel 5 Enable */
    volatile uint32 EICH4EN:1;               /* Error Injection Channel 4 Enable */
    volatile uint32 EICH3EN:1;               /* Error Injection Channel 3 Enable */
    volatile uint32 EICH2EN:1;               /* Error Injection Channel 2 Enable */
    volatile uint32 EICH1EN:1;               /* Error Injection Channel 1 Enable */
    volatile uint32 EICH0EN:1;               /* Error Injection Channel 0 Enable */
  } B;
} EIM_EICHEN_tag;

typedef struct EIM_EICHD_union_tag {
  volatile uint32 WORD[EIM_EICHD_WORDS_PER_CHANNEL];    /* Error Injection Words */
  volatile uint8  EICHD_reserved0[28];
} EIM_EICHD_tag;

struct EIM_tag {
  EIM_EIMCR_tag EIMCR;             /* Error Injection Module Configuration Register */
  EIM_EICHEN_tag EICHEN;           /* Error Injection Channel Enable register */
  volatile uint8 EIM_reserved0[248];
  EIM_EICHD_tag EICHD[EIM_CHANNELS_COUNT];
};

/* ============================================================================
 =============================== Module: ERM ================================
  ============================================================================ */
typedef union ERM_CR_union_tag {      /* ERM Configuration Registers */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_0:2;
    volatile uint32 ENCIE:1;
    volatile uint32 ESCIE:1;
  } CH[8];
} ERM_CR_tag;

typedef union ERM_SR_union_tag {      /* ERM Status Registers */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_0:2;
    volatile uint32 NCE:1;
    volatile uint32 SBC:1;
  } CH[8];
} ERM_SR_tag;

typedef union ERM_EAR_union_tag {     /* ERM Memory Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 EAR:32;                  /* EAR */
  } B;
} ERM_EAR_tag;

typedef union ERM_SYN_union_tag {     /* ERM Memory Syndrome Register */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_0:24;            /* Reserved */
    volatile uint32 SYNDROME:8;              /* SYNDROME */
  } B;
} ERM_SYN_tag;

typedef union ERM_CORR_ERR_CNT_union_tag { /* ERM Memory Correctable Error Count Register */
  volatile uint32 R;
  struct {
    volatile uint32 COUNT:8;                 /* Memory Correctable Error Count */
    volatile uint32 _unused_8:24;            /* Reserved */
  } B;
} ERM_CORR_ERR_CNT_tag;

typedef struct ERM_MEM_struct_tag {
  ERM_EAR_tag EAR;                    /* ERM Memory Error Address Register */
  ERM_SYN_tag SYN;                    /* ERM Memory Syndrome Register */
  ERM_CORR_ERR_CNT_tag CORR_ERR_CNT;  /* ERM Memory Correctable Error Count Register */
  uint8 ERM_MEM_Reserved[4];          /* Reserved */
} ERM_MEM_tag;

struct ERM_tag {
  ERM_CR_tag CR[2];                     /* ERM Configuration Registers */
  uint8 ERM_reserved0[8];               /* Reserved */
  ERM_SR_tag SR[2];                     /* ERM Status Registers */
  uint8 ERM_reserved1[232];             /* Reserved */
  ERM_MEM_tag MEM[10];                  /* ERM Memory Error Registers */
};


/* ============================================================================
   =============================== Module: M7_A7_APB_MCM ======================
   ============================================================================ */

typedef union M7_A7_APB_MCM_ERR_INFO_EN_union_tag { /* Error Info Enable */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_24:8;            /* Reserved */
    volatile uint32 ITCM_ERRM_INFO_EN:1;     /* ITCM Access multi bit ECC Error Info Status Enable */
    volatile uint32 ITCM_ERRS_INFO_EN:1;     /* ITCM Access single bit ECC Error Info Status Enable */
    volatile uint32 D0TCM_ERRM_INFO_EN:1;    /* D0TCM Access multi bit ECC Error Info Status Enable */
    volatile uint32 D0TCM_ERRS_INFO_EN:1;    /* D0TCM Access single bit ECC Error Info Status Enable */
    volatile uint32 D1TCM_ERRM_INFO_EN:1;    /* D1TCM Access multi bit ECC Error Info Status Enable */
    volatile uint32 D1TCM_ERRS_INFO_EN:1;    /* D1TCM Access single bit ECC Error Info Status Enable */
    volatile uint32 _unused_0:18;            /* Reserved */
  } B;
} M7_A7_APB_MCM_ERR_INFO_EN_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_union_tag { /* ITCM single-bit ECC Error Information */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCS_EFW:1;         /* Read or write of the access */
    volatile uint32 ITCM_ECCS_EFSIZ:3;       /* Size of the access */
    volatile uint32 ITCM_ECCS_EFMST:4;       /* Encodes the requestor of the access */
    volatile uint32 ITCM_ECCS_EFPRT:4;       /* Privilege level of access */
    volatile uint32 _unused_12:8;
    volatile uint32 RESERVED:12;             /* Reserved */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_union_tag { /* ITCM single-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCS_ERRED_ADDR:32; /* ITCM single-bit ECC error address */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_union_tag { /* ITCM single-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCS_ERRED_DATA_LSB:32; /* ITCM single-bit ECC error data [31:0] */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_union_tag { /* ITCM single-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCS_ERRED_DATA_MSB:32; /* ITCM single-bit ECC error data [63:32] */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_union_tag { /* ITCM multi-bit ECC Error Information Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCM_EFW:1;         /* ITCM multi-bit ECC error corresponding tcm_wr value */
    volatile uint32 ITCM_ECCM_EFSIZ:3;       /* ITCM multi-bit ECC error corresponding tcm access size */
    volatile uint32 ITCM_ECCM_EFMST:4;       /* ITCM multi-bit ECC error corresponding tcm_controller */
    volatile uint32 ITCM_ECCM_EFPRT:4;       /* ITCM multi-bit ECC error corresponding tcm_priv */
    volatile uint32 _unused_12:8;
    volatile uint32 RESERVED:12;             /* Reserved */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_union_tag { /* ITCM multi-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCM_ERRED_ADDR:32; /* ITCM multi-bit ECC error address */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_union_tag { /* ITCM multi-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCM_ERRED_DATA_LSB:32; /* ITCM multi-bit ECC error data [31:0] */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_tag;

typedef union M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_union_tag { /* ITCM multi-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 ITCM_ECCM_ERRED_DATA_MSB:32; /* ITCM multi-bit ECC error data [63:32] */
  } B;
} M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_union_tag { /* D0TCM single-bit ECC Error Information Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCS_EFW:1;        /* D0TCM single-bit ECC error corresponding tcm_wr value */
    volatile uint32 D0TCM_ECCS_EFSIZ:3;      /* D0TCM single-bit ECC error corresponding tcm access size */
    volatile uint32 D0TCM_ECCS_EFMST:4;      /* D0TCM single-bit ECC error corresponding tcm_controller */
    volatile uint32 D0TCM_ECCS_EFPRT:4;      /* D0TCM single-bit ECC error corresponding tcm_priv */
    volatile uint32 _unused_13:7;
    volatile uint32 RESERVED:13;             /* Reserved */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_union_tag { /* D0TCM single-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCS_ERRED_ADDR:32; /* D0TCM single-bit ECC error address */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_union_tag { /* D0TCM single-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCS_ERRED_DATA:32; /* D0TCM single-bit ECC error data */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_union_tag { /* D0TCM multi-bit ECC Error Information Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCM_EFW:1;        /* D0TCM multi-bit ECC error corresponding tcm_wr value */
    volatile uint32 D0TCM_ECCM_EFSIZ:3;      /* D0TCM multi-bit ECC error corresponding tcm access size */
    volatile uint32 D0TCM_ECCM_EFMST:4;      /* D0TCM multi-bit ECC error corresponding tcm_controller */
    volatile uint32 D0TCM_ECCM_EFPRT:4;      /* D0TCM multi-bit ECC error corresponding tcm_priv */
    volatile uint32 _unused_13:7;
    volatile uint32 RESERVED:13;             /* Reserved */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_union_tag { /* D0TCM multi-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCM_ERRED_ADDR:32; /* D0TCM multi-bit ECC error address */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_union_tag { /* D0TCM multi-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 D0TCM_ECCM_ERRED_DATA:32; /* D0TCM multi-bit ECC error data */
  } B;
} M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_union_tag { /* D1TCM single-bit ECC Error Information Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCS_EFW:1;        /* D1TCM single-bit ECC error corresponding tcm_wr value */
    volatile uint32 D1TCM_ECCS_EFSIZ:3;      /* D1TCM single-bit ECC error corresponding tcm access size */
    volatile uint32 D1TCM_ECCS_EFMST:4;      /* D1TCM single-bit ECC error corresponding tcm_controller */
    volatile uint32 D1TCM_ECCS_EFPRT:4;      /* D1TCM single-bit ECC error corresponding tcm_priv */
    volatile uint32 _unused_13:7;
    volatile uint32 RESERVED:13;             /* Reserved */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_union_tag { /* D1TCM single-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCS_ERRED_ADDR:32; /* D1TCM single-bit ECC error address */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_union_tag { /* D1TCM single-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCS_ERRED_DATA:32; /* D1TCM single-bit ECC error data */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_union_tag { /* D1TCM multi-bit ECC Error Information Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCM_EFW:1;        /* D1TCM multi-bit ECC error corresponding tcm_wr value */
    volatile uint32 D1TCM_ECCM_EFSIZ:3;      /* D1TCM multi-bit ECC error corresponding tcm access size */
    volatile uint32 D1TCM_ECCM_EFMST:4;      /* D1TCM multi-bit ECC error corresponding tcm_controller */
    volatile uint32 D1TCM_ECCM_EFPRT:4;      /* D1TCM multi-bit ECC error corresponding tcm_priv */
    volatile uint32 _unused_13:7;
    volatile uint32 RESERVED:13;             /* Reserved */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_union_tag { /* D1TCM multi-bit ECC Error Address Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCM_ERRED_ADDR:32; /* D1TCM multi-bit ECC error address */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_tag;

typedef union M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_union_tag { /* D1TCM multi-bit ECC Error Data Register */
  volatile uint32 R;
  struct {
    volatile uint32 D1TCM_ECCM_ERRED_DATA:32; /* D1TCM multi-bit ECC error data */
  } B;
} M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_tag;

typedef union M7_A7_APB_MCM_FCCU_SW_FAULTS_union_tag { /* FCCU Software Faults */
  volatile uint32 R;
  struct {
    volatile uint32 FCCU_SW_FAULTS:6;        /* FCCU Software Faults */
    volatile uint32 _unused_0:26;
  } B;
} M7_A7_APB_MCM_FCCU_SW_FAULTS_tag;

struct M7_A7_APB_MCM_tag {
  uint8 M7_A7_APB_MCM_reserved0[36];
  M7_A7_APB_MCM_ERR_INFO_EN_tag ERR_INFO_EN; /* Error Info Enable */
  uint8 M7_A7_APB_MCM_reserved1[20];
  M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_tag ITCM_ECC_SINGLE_ERROR_INFO; /* ITCM single-bit ECC Error Information */
  M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_tag ITCM_ECC_SINGLE_ERROR_ADDR; /* ITCM single-bit ECC Error Address Register */
  M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_tag ITCM_ECC_SINGLE_ERROR_DATA_LSB; /* ITCM single-bit ECC Error Data Register */
  M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_tag ITCM_ECC_SINGLE_ERROR_DATA_MSB; /* ITCM single-bit ECC Error Data Register */
  M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_tag ITCM_ECC_MULTI_ERROR_INFO; /* ITCM multi-bit ECC Error Information Register */
  M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_tag ITCM_ECC_MULTI_ERROR_ADDR; /* ITCM multi-bit ECC Error Address Register */
  M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_tag ITCM_ECC_MULTI_ERROR_DATA_LSB; /* ITCM multi-bit ECC Error Data Register */
  M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_tag ITCM_ECC_MULTI_ERROR_DATA_MSB; /* ITCM multi-bit ECC Error Data Register */
  M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_tag D0TCM_ECC_SINGLE_ERROR_INFO; /* D0TCM single-bit ECC Error Information Register */
  M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_tag D0TCM_ECC_SINGLE_ERROR_ADDR; /* D0TCM single-bit ECC Error Address Register */
  M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_tag D0TCM_ECC_SINGLE_ERROR_DATA; /* D0TCM single-bit ECC Error Data Register */
  M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_tag D0TCM_ECC_MULTI_ERROR_INFO; /* D0TCM multi-bit ECC Error Information Register */
  M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_tag D0TCM_ECC_MULTI_ERROR_ADDR; /* D0TCM multi-bit ECC Error Address Register */
  M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_tag D0TCM_ECC_MULTI_ERROR_DATA; /* D0TCM multi-bit ECC Error Data Register */
  M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_tag D1TCM_ECC_SINGLE_ERROR_INFO; /* D1TCM single-bit ECC Error Information Register */
  M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_tag D1TCM_ECC_SINGLE_ERROR_ADDR; /* D1TCM single-bit ECC Error Address Register */
  M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_tag D1TCM_ECC_SINGLE_ERROR_DATA; /* D1TCM single-bit ECC Error Data Register */
  M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_tag D1TCM_ECC_MULTI_ERROR_INFO; /* D1TCM multi-bit ECC Error Information Register */
  M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_tag D1TCM_ECC_MULTI_ERROR_ADDR; /* D1TCM multi-bit ECC Error Address Register */
  M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_tag D1TCM_ECC_MULTI_ERROR_DATA; /* D1TCM multi-bit ECC Error Data Register */
  uint8 M7_A7_APB_MCM_reserved2[16];
  M7_A7_APB_MCM_FCCU_SW_FAULTS_tag FCCU_SW_FAULTS; /* FCCU Software Faults */
};

/* ============================================================================
 =============================== Module: VFCCU ==============================
  ============================================================================ */
typedef union SAFETYBASE_VFCCU_GFLTRC_union_tag { /* Global Fault Recovery */
  volatile uint32 R;
  struct {
    volatile uint32 RHWSW0:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW1:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW2:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW3:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW4:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW5:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW6:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW7:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW8:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW9:1;                /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW10:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW11:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW12:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW13:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW14:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW15:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW16:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW17:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW18:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW19:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW20:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW21:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW22:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW23:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW24:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW25:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW26:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW27:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW28:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW29:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW30:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
    volatile uint32 RHWSW31:1;               /* Recovery/Clearing Mechanism Hardware Or Software */
  } B;
} SAFETYBASE_VFCCU_GFLTRC_tag;

typedef union AON_FCCU_FHFLTENC_union_tag { /* Fault Enable */
  volatile uint32 R;
  struct {
    volatile uint32 EN0:1;                   /* Fault Enable */
    volatile uint32 EN1:1;                   /* Fault Enable */
    volatile uint32 EN2:1;                   /* Fault Enable */
    volatile uint32 EN3:1;                   /* Fault Enable */
    volatile uint32 EN4:1;                   /* Fault Enable */
    volatile uint32 EN5:1;                   /* Fault Enable */
    volatile uint32 EN6:1;                   /* Fault Enable */
    volatile uint32 EN7:1;                   /* Fault Enable */
    volatile uint32 EN8:1;                   /* Fault Enable */
    volatile uint32 EN9:1;                   /* Fault Enable */
    volatile uint32 EN10:1;                  /* Fault Enable */
    volatile uint32 EN11:1;                  /* Fault Enable */
    volatile uint32 EN12:1;                  /* Fault Enable */
    volatile uint32 EN13:1;                  /* Fault Enable */
    volatile uint32 EN14:1;                  /* Fault Enable */
    volatile uint32 EN15:1;                  /* Fault Enable */
    volatile uint32 EN16:1;                  /* Fault Enable */
    volatile uint32 EN17:1;                  /* Fault Enable */
    volatile uint32 EN18:1;                  /* Fault Enable */
    volatile uint32 EN19:1;                  /* Fault Enable */
    volatile uint32 EN20:1;                  /* Fault Enable */
    volatile uint32 EN21:1;                  /* Fault Enable */
    volatile uint32 EN22:1;                  /* Fault Enable */
    volatile uint32 EN23:1;                  /* Fault Enable */
    volatile uint32 EN24:1;                  /* Fault Enable */
    volatile uint32 EN25:1;                  /* Fault Enable */
    volatile uint32 EN26:1;                  /* Fault Enable */
    volatile uint32 EN27:1;                  /* Fault Enable */
    volatile uint32 EN28:1;                  /* Fault Enable */
    volatile uint32 EN29:1;                  /* Fault Enable */
    volatile uint32 EN30:1;                  /* Fault Enable */
    volatile uint32 EN31:1;                  /* Fault Enable */
  } B;
} SAFETYBASE_VFCCU_FHFLTENC_tag;

typedef union SAFETYBASE_VFCCU_FHFLTS_union_tag { /* Fault Status */
  volatile uint32 R;
  struct {
    volatile uint32 STAT0:1;                 /* Fault Status */
    volatile uint32 STAT1:1;                 /* Fault Status */
    volatile uint32 STAT2:1;                 /* Fault Status */
    volatile uint32 STAT3:1;                 /* Fault Status */
    volatile uint32 STAT4:1;                 /* Fault Status */
    volatile uint32 STAT5:1;                 /* Fault Status */
    volatile uint32 STAT6:1;                 /* Fault Status */
    volatile uint32 STAT7:1;                 /* Fault Status */
    volatile uint32 STAT8:1;                 /* Fault Status */
    volatile uint32 STAT9:1;                 /* Fault Status */
    volatile uint32 STAT10:1;                /* Fault Status */
    volatile uint32 STAT11:1;                /* Fault Status */
    volatile uint32 STAT12:1;                /* Fault Status */
    volatile uint32 STAT13:1;                /* Fault Status */
    volatile uint32 STAT14:1;                /* Fault Status */
    volatile uint32 STAT15:1;                /* Fault Status */
    volatile uint32 STAT16:1;                /* Fault Status */
    volatile uint32 STAT17:1;                /* Fault Status */
    volatile uint32 STAT18:1;                /* Fault Status */
    volatile uint32 STAT19:1;                /* Fault Status */
    volatile uint32 STAT20:1;                /* Fault Status */
    volatile uint32 STAT21:1;                /* Fault Status */
    volatile uint32 STAT22:1;                /* Fault Status */
    volatile uint32 STAT23:1;                /* Fault Status */
    volatile uint32 STAT24:1;                /* Fault Status */
    volatile uint32 STAT25:1;                /* Fault Status */
    volatile uint32 STAT26:1;                /* Fault Status */
    volatile uint32 STAT27:1;                /* Fault Status */
    volatile uint32 STAT28:1;                /* Fault Status */
    volatile uint32 STAT29:1;                /* Fault Status */
    volatile uint32 STAT30:1;                /* Fault Status */
    volatile uint32 STAT31:1;                /* Fault Status */
  } B;
} SAFETYBASE_VFCCU_FHFLTS_tag;

typedef union SAFETYBASE_VFCCU_FHFLTRKC_union_tag { /* Fault Reaction Set Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 RKNSEL0:3;               /* Reaction Selection */
    volatile uint32 _unused_24:5;
    volatile uint32 RKNSEL1:3;               /* Reaction Selection */
    volatile uint32 _unused_16:5;
    volatile uint32 RKNSEL2:3;               /* Reaction Selection */
    volatile uint32 _unused_8:5;
    volatile uint32 RKNSEL3:3;               /* Reaction Selection */
    volatile uint32 _unused_0:5;
  } B;
} SAFETYBASE_VFCCU_FHFLTRKC_tag;

typedef union SAFETYBASE_VFCCU_FHIMRKC_union_tag { /* Immediate Reaction Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTEN0:1;               /* EOUT Enable */
    volatile uint32 EOUTEN1:1;               /* EOUT Enable */
    volatile uint32 RKNEN0:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN1:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN2:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN3:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN4:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN5:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN6:1;                /* Reaction Line Enable */
    volatile uint32 _unused_0:23;
  } B;
} SAFETYBASE_VFCCU_FHIMRKC_tag;

typedef union SAFETYBASE_VFCCU_FHDLRKC_union_tag { /* Delayed Reaction Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTEN0:1;               /* EOUT Enable */
    volatile uint32 EOUTEN1:1;               /* EOUT Enable */
    volatile uint32 RKNEN0:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN1:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN2:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN3:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN4:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN5:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN6:1;                /* Reaction Line Enable */
    volatile uint32 _unused_0:23;
  } B;
} SAFETYBASE_VFCCU_FHDLRKC_tag;

typedef struct { /* Reaction Configuration */
    SAFETYBASE_VFCCU_FHIMRKC_tag FHIMRKC; /* Immediate Reaction Configuration */
    uint8 SAFETYBASE_VFCCU_reserved0[12];
    SAFETYBASE_VFCCU_FHDLRKC_tag FHDLRKC; /* Delayed Reaction Configuration */
    uint8 SAFETYBASE_VFCCU_reserved1[12];
} SAFETYBASE_VFCCU_FHRKC_tag;

typedef union AON_FCCU_GRKNTIMC_union_tag { /* Global Reaction Timer Period */
  volatile uint32 R;
  struct {
    volatile uint32 RKTIMCFG:32;             /* Reaction Timer Period */
  } B;
} AON_FCCU_GRKNTIMC_tag;

typedef union AON_FCCU_GRKNTIMS_union_tag { /* Global Reaction Timer Status */
  volatile uint32 R;
  struct {
    volatile uint32 RKTIMVAL:32;             /* Current Reaction Timer */
  } B;
} AON_FCCU_GRKNTIMS_tag;

typedef union AON_FCCU_GINTOVFS_union_tag { /* Global DID FSM Status */
  volatile uint32 R;
  struct {
    volatile uint32 FSMSTATE:2;              /* FSM State */
    volatile uint32 _unused_25:5;
    volatile uint32 FLTSERV:1;               /* Fault Serve */
    volatile uint32 _unused_23:1;
    volatile uint32 _unused_21:2;
    volatile uint32 _unused_16:5;
    volatile uint32 SERV_DID:4;              /* Domain Being Serviced */
    volatile uint32 _unused_8:4;
    volatile uint32 _unused_4:4;
    volatile uint32 _unused_0:4;
  } B;
} AON_FCCU_GINTOVFS_tag;

typedef union AON_FCCU_GOVFRKC_union_tag { /* Global Overflow Reaction */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTEN0:1;               /* EOUT Enable */
    volatile uint32 EOUTEN1:1;               /* EOUT Enable */
    volatile uint32 RKNEN0:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN1:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN2:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN3:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN4:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN5:1;                /* Reaction Line Enable */
    volatile uint32 RKNEN6:1;                /* Reaction Line Enable */
    volatile uint32 _unused_0:23;
  } B;
} AON_FCCU_GOVFRKC_tag;

typedef union AON_FCCU_GMEOUTDC_union_tag { /* Global Minimum EOUT Duration */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTMIND:32;             /* EOUT Minimum Duration */
  } B;
} AON_FCCU_GMEOUTDC_tag;

typedef union AON_FCCU_GEOUTTCT_union_tag { /* Global EOUT Timer Disable */
  volatile uint32 R;
  struct {
    volatile uint32 TMRDIS0:1;               /* Timer Disable */
    volatile uint32 TMRDIS1:1;               /* Timer Disable */
    volatile uint32 _unused_0:30;
  } B;
} AON_FCCU_GEOUTTCT_tag;

typedef union AON_FCCU_GLB_EOUT_GEOUTPNC_union_tag { /* Global EOUT Pin */
  volatile uint32 R;
  struct {
    volatile uint32 OBE_VALID:1;             /* Output Buffer Enable Valid */
    volatile uint32 OBE_STAT:1;              /* Output Buffer Enable Status */
    volatile uint32 _unused_29:1;
    volatile uint32 DO_STAT:1;               /* Data Output Status */
    volatile uint32 VAL_CTRL:2;              /* Invert Output */
    volatile uint32 _unused_24:2;
    volatile uint32 IBE:1;                   /* Input Buffer Enable */
    volatile uint32 IND_STAT:1;              /* Input Data From Pad */
    volatile uint32 INV_IP:1;                /* Invert Input */
    volatile uint32 _unused_16:5;
    volatile uint32 SOC_PAD_CTRL1:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL2:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL3:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL4:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL5:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL6:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL7:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL8:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL9:1;         /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL10:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL11:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL12:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL13:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL14:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL15:1;        /* SoC Pad Control */
    volatile uint32 SOC_PAD_CTRL16:1;        /* SoC Pad Control */
  } B;
} AON_FCCU_GLB_EOUT_GEOUTPNC_tag;

typedef union AON_FCCU_GLB_EOUT_GEOUTPMC_union_tag { /* Global EOUT Pin Map */
  volatile uint32 R;
  struct {
    volatile uint32 SPLENB0:1;               /* Special Enable Pins */
    volatile uint32 SPLENB1:1;               /* Special Enable Pins */
    volatile uint32 SPLENB2:1;               /* Special Enable Pins */
    volatile uint32 SPLENB3:1;               /* Special Enable Pins */
    volatile uint32 _unused_0:28;
  } B;
} AON_FCCU_GLB_EOUT_GEOUTPMC_tag;

typedef union AON_FCCU_GLB_EOUT_GEOUTMC_union_tag { /* Global EOUT Mode */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTM:3;                 /* EOUT Pin Mode */
    volatile uint32 INV:1;                   /* Invert EOUT */
    volatile uint32 _unused_0:28;
  } B;
} AON_FCCU_GLB_EOUT_GEOUTMC_tag;

typedef union AON_FCCU_GLB_EOUT_GEOUTTMS_union_tag { /* Global EOUT Timer Status */
  volatile uint32 R;
  struct {
    volatile uint32 EOUTDVAL:32;             /* EOUT Timer Current Value */
  } B;
} AON_FCCU_GLB_EOUT_GEOUTTMS_tag;

typedef union AON_FCCU_GLB_EOUT_GEOUTDIC_union_tag { /* Global EOUT DID */
  volatile uint32 R;
  struct {
    volatile uint32 DID_EOUT:4;              /* DID for Fault on EOUT */
    volatile uint32 _unused_0:28;
  } B;
} AON_FCCU_GLB_EOUT_GEOUTDIC_tag;

typedef struct AON_FCCU_GLB_EOUT_struct_tag {
  AON_FCCU_GLB_EOUT_GEOUTPNC_tag GEOUTPNC; /* Global EOUT Pin */
  AON_FCCU_GLB_EOUT_GEOUTPMC_tag GEOUTPMC; /* Global EOUT Pin Map */
  AON_FCCU_GLB_EOUT_GEOUTMC_tag GEOUTMC; /* Global EOUT Mode */
  AON_FCCU_GLB_EOUT_GEOUTTMS_tag GEOUTTMS; /* Global EOUT Timer Status */
  AON_FCCU_GLB_EOUT_GEOUTDIC_tag GEOUTDIC; /* Global EOUT DID */
} AON_FCCU_GLB_EOUT_tag;

typedef union AON_FCCU_GDBGCFG_union_tag { /* Global Debug */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_16:16;
    volatile uint32 FRZ:1;                   /* Freeze On First Fault */
    volatile uint32 _unused_0:15;
  } B;
} AON_FCCU_GDBGCFG_tag;

typedef union AON_FCCU_GDBGSTAT_union_tag { /* Global Debug Status */
  volatile uint32 R;
  struct {
    volatile uint32 FLTIND:8;                /* Fault Index */
    volatile uint32 _unused_2:22;
    volatile uint32 _unused_0:2;
  } B;
} AON_FCCU_GDBGSTAT_tag;

typedef union AON_FCCU_GDPFSTAT_union_tag { /* Global Debug Pending Fault Status */
  volatile uint32 R;
  struct {
    volatile uint32 PENDFLT0:1;              /* Pending Fault Status for corresponding EOUT pin */
    volatile uint32 PENDFLT1:1;              /* Pending Fault Status for corresponding EOUT pin */
    volatile uint32 _unused_0:30;
  } B;
} AON_FCCU_GDPFSTAT_tag;

typedef union AON_FCCU_GDALTRLD_union_tag { /* Global Debug Alternate Reload Status */
  volatile uint32 R;
  struct {
    volatile uint32 ALTRLD0:1;               /* Alternate timer reload status for corresponding EOUT pin */
    volatile uint32 ALTRLD1:1;               /* Alternate timer reload status for corresponding EOUT pin */
    volatile uint32 _unused_0:30;
  } B;
} AON_FCCU_GDALTRLD_tag;

typedef union AON_FCCU_FHCFG0_union_tag { /* Fault Handler */
  volatile uint32 R;
  struct {
    volatile uint32 FHIDEN:1;                /* Fault Handler Enable */
    volatile uint32 _unused_0:31;
  } B;
} AON_FCCU_FHCFG0_tag;

typedef union AON_FCCU_FHSRVDS0_union_tag { /* Fault Handler Status */
  volatile uint32 R;
  struct {
    volatile uint32 SERV_DID:4;              /* DID Being Serviced */
    volatile uint32 _unused_24:4;
    volatile uint32 AGGFLTS:1;               /* Aggregated Fault Status */
    volatile uint32 _unused_0:23;
  } B;
} AON_FCCU_FHSRVDS0_tag;

struct SAFETYBASE_VFCCU_tag {
  uint8 AON_FCCU_reserved0[768];
  AON_FCCU_GRKNTIMC_tag GRKNTIMC[1];   /* Global Reaction Timer Period */
  uint8 AON_FCCU_reserved1[316];
  SAFETYBASE_VFCCU_GFLTRC_tag GFLTRC[4];    /* Global Fault Recovery */
  uint8 AON_FCCU_reserved2[2224];
  AON_FCCU_GRKNTIMS_tag GRKNTIMS;      /* Global Reaction Timer Status */
  uint8 AON_FCCU_reserved3[4];
  AON_FCCU_GINTOVFS_tag GINTOVFS;      /* Global DID FSM Status */
  uint8 AON_FCCU_reserved4[20];
  AON_FCCU_GMEOUTDC_tag GMEOUTDC;      /* Global Minimum EOUT Duration */
  AON_FCCU_GEOUTTCT_tag GEOUTTCT;      /* Global EOUT Timer Disable */
  uint8 AON_FCCU_reserved5[8];
  AON_FCCU_GLB_EOUT_tag GLB_EOUT[2];
  uint8 AON_FCCU_reserved7[600];
  AON_FCCU_GDBGCFG_tag GDBGCFG;        /* Global Debug */
  AON_FCCU_GDBGSTAT_tag GDBGSTAT;      /* Global Debug Status */
  AON_FCCU_GDPFSTAT_tag GDPFSTAT;      /* Global Debug Pending Fault Status */
  AON_FCCU_GDALTRLD_tag GDALTRLD;      /* Global Debug Alternate Reload Status */
  uint8 AON_FCCU_reserved8[1306688];
  AON_FCCU_FHCFG0_tag FHCFG0;          /* Fault Handler */
  AON_FCCU_FHSRVDS0_tag FHSRVDS0;      /* Fault Handler Status */
  uint8 AON_FCCU_reserved9[8];
  SAFETYBASE_VFCCU_FHFLTENC_tag FHFLTENC[4]; /* Fault Enable */
  uint8 AON_FCCU_reserved10[48];
  SAFETYBASE_VFCCU_FHFLTS_tag FHFLTS[4];    /* Fault Status */
  uint8 AON_FCCU_reserved11[48];
  SAFETYBASE_VFCCU_FHFLTRKC_tag FHFLTRKC[25]; /* Fault Reaction Set Configuration */
  uint8 AON_FCCU_reserved12[412];
  SAFETYBASE_VFCCU_FHRKC_tag FHRKC[8]; /* Reaction Configuration */
};

/* ============================================================================
 =============================== Module: SRAMCTL ============================
  ============================================================================ */
typedef union SRAMCTL_RAMCR_union_tag { /* RAM Control */
  volatile uint32 R;
  struct {
    volatile uint32 INIT:1;                  /* Initialization Request */
    volatile uint32 IWS:2;                   /* Initialization Wait States */
    volatile uint32 _unused_3:5;             /* Reserved */
    volatile uint32 INIT_SYSA:1;             /* Initialize With System Address */
    volatile uint32 _unused_9:23;            /* Reserved */
  } B;
} SRAMCTL_RAMCR_tag;

typedef union SRAMCTL_RAMIAS_union_tag { /* RAM Initialization Address Start */
  volatile uint32 R;
  struct {
    volatile uint32 IAS:32;                  /* Initialization Address Start */
  } B;
} SRAMCTL_RAMIAS_tag;

typedef union SRAMCTL_RAMIAE_union_tag { /* RAM Initialization Address End */
  volatile uint32 R;
  struct {
    volatile uint32 IAE:32;                  /* Initialization Address End */
  } B;
} SRAMCTL_RAMIAE_tag;

typedef union SRAMCTL_RAMSR_union_tag { /* RAM Status */
  volatile uint32 R;
  struct {
    volatile uint32 IDONE:1;                 /* Initialization Done */
    volatile uint32 BUSERR:1;                /* Bus Error */
    volatile uint32 IPEND:1;                 /* Initialization Pending */
    volatile uint32 AVALID:1;                /* Addresses Valid */
    volatile uint32 _unused_4:1;             /* Reserved */
    volatile uint32 AERR:1;                  /* ECC Address Error */
    volatile uint32 MLTERR:1;                /* ECC Multi-Bit Error */
    volatile uint32 SGLERR:1;                /* ECC Single-Bit Error */
    volatile uint32 SYND:8;                  /* ECC Syndrome Value */
    volatile uint32 EINFO:8;                 /* Event Information */
    volatile uint32 _unused_24:8;            /* Reserved */
  } B;
} SRAMCTL_RAMSR_tag;

typedef union SRAMCTL_RAMMEMA_union_tag { /* RAM ECC Address */
  volatile uint32 R;
  struct {
    volatile uint32 MEMA:17;                 /* RAM Bank Address */
    volatile uint32 _unused_17:3;            /* Reserved */
    volatile uint32 BANK:5;                  /* RAM Bank ID */
    volatile uint32 _unused_25:7;            /* Reserved */
  } B;
} SRAMCTL_RAMMEMA_tag;

typedef union SRAMCTL_RAMSYSA_union_tag { /* RAM System Address */
  volatile uint32 R;
  struct {
    volatile uint32 SYSA:32;                 /* System Address */
  } B;
} SRAMCTL_RAMSYSA_tag;

typedef union SRAMCTL_RAMECCNT_union_tag { /* RAM Correctable Error Count */
  volatile uint32 R;
  struct {
    volatile uint32 ECCNT:8;                 /* ECC Correctable Error Count */
    volatile uint32 _unused_8:24;            /* Reserved */
  } B;
} SRAMCTL_RAMECCNT_tag;

typedef union SRAMCTL_RAMEID0_union_tag { /* RAM Error Injection Data 0 */
  volatile uint32 R;
  struct {
    volatile uint32 EID_W0:32;               /* Error Injection Data Word 0 */
  } B;
} SRAMCTL_RAMEID0_tag;

typedef union SRAMCTL_RAMEID1_union_tag { /* RAM Error Injection Data 1 */
  volatile uint32 R;
  struct {
    volatile uint32 EID_W1:32;               /* Error Injection Data Word 1 */
  } B;
} SRAMCTL_RAMEID1_tag;

typedef union SRAMCTL_RAMEIDC_union_tag { /* RAM Error Injection Data Control */
  volatile uint32 R;
  struct {
    volatile uint32 EID_CKB:8;               /* Error Injection Data Checkbits */
    volatile uint32 _unused_8:16;            /* Reserved */
    volatile uint32 EIP_EN:1;                /* Error Injection Into Pipeline Enable */
    volatile uint32 _unused_25:5;            /* Reserved */
    volatile uint32 EIA_EN:1;                /* Error Injection Address Enable */
    volatile uint32 EID_EN:1;                /* Error Injection Data Enable */
  } B;
} SRAMCTL_RAMEIDC_tag;

typedef union SRAMCTL_RAMEIA_union_tag { /* RAM Error Injection Base Address */
  volatile uint32 R;
  struct {
    volatile uint32 EIA:32;                  /* Error Injection Base Address */
  } B;
} SRAMCTL_RAMEIA_tag;

typedef union SRAMCTL_RAMEIAM_union_tag { /* RAM Error Injection Address Mask */
  volatile uint32 R;
  struct {
    volatile uint32 EIAM:32;                 /* Error Injection Address Mask */
  } B;
} SRAMCTL_RAMEIAM_tag;

typedef union SRAMCTL_RAMMAXA_union_tag { /* RAM Maximum-Value Address */
  volatile uint32 R;
  struct {
    volatile uint32 MAXA:32;                 /* Maximum Address */
  } B;
} SRAMCTL_RAMMAXA_tag;

typedef union SRAMCTL_RAMCR2_union_tag { /* RAM Control 2 */
  volatile uint32 R;
  struct {
    volatile uint32 PREF:1;                  /* Prefetch for Read Bursts */
    volatile uint32 WBUF:2;                  /* Write Buffer Control */
    volatile uint32 DEM:1;                   /* Disable Exclusive Monitor */
    volatile uint32 _unused_4:28;            /* Reserved */
  } B;
} SRAMCTL_RAMCR2_tag;

struct SRAMCTL_tag {
  SRAMCTL_RAMCR_tag RAMCR;             /* RAM Control */
  SRAMCTL_RAMIAS_tag RAMIAS;           /* RAM Initialization Address Start */
  SRAMCTL_RAMIAE_tag RAMIAE;           /* RAM Initialization Address End */
  SRAMCTL_RAMSR_tag RAMSR;             /* RAM Status */
  SRAMCTL_RAMMEMA_tag RAMMEMA;         /* RAM ECC Address */
  uint8 SRAMCTL_reserved0[4];
  SRAMCTL_RAMSYSA_tag RAMSYSA;         /* RAM System Address */
  SRAMCTL_RAMECCNT_tag RAMECCNT;       /* RAM Correctable Error Count */
  SRAMCTL_RAMEID0_tag RAMEID0;         /* RAM Error Injection Data 0 */
  SRAMCTL_RAMEID1_tag RAMEID1;         /* RAM Error Injection Data 1 */
  SRAMCTL_RAMEIDC_tag RAMEIDC;         /* RAM Error Injection Data Control */
  uint8 SRAMCTL_reserved1[4];
  SRAMCTL_RAMEIA_tag RAMEIA;           /* RAM Error Injection Base Address */
  SRAMCTL_RAMEIAM_tag RAMEIAM;         /* RAM Error Injection Address Mask */
  uint8 SRAMCTL_reserved2[8];
  SRAMCTL_RAMMAXA_tag RAMMAXA;         /* RAM Maximum-Value Address */
  uint8 SRAMCTL_reserved3[60];
  SRAMCTL_RAMCR2_tag RAMCR2;           /* RAM Control 2 */
};

/* ============================================================================
   =============================== Module: DDR_DDRC ===========================
   ============================================================================ */

typedef union DDR_DDRC_CS_BNDS_CS_BNDS_union_tag { /* Rank 0 Memory Bounds */
  volatile uint32 R;
  struct {
    volatile uint32 EA:16;                   /* Ending Address */
    volatile uint32 SA:16;                   /* Starting Address */
  } B;
} DDR_DDRC_CS_BNDS_CS_BNDS_tag;

typedef struct DDR_DDRC_CS_BNDS_struct_tag {
  DDR_DDRC_CS_BNDS_CS_BNDS_tag CS_BNDS; /* Rank 0 Memory Bounds */
  uint8 CS_BNDS_reserved0[4];
} DDR_DDRC_CS_BNDS_tag;

typedef union DDR_DDRC_REMAP_EXT_0_union_tag { /* Remap Extended Region 0 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_0_EA:8;          /* Region 0 Extended Ending Address */
    volatile uint32 EXT_REG_0_SA:8;          /* Region 0 Extended Starting Address */
    volatile uint32 REG_0_EXT_REMAP_ADDR:8;  /* Region 0 Extended Remap Starting Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_REMAP_EXT_0_tag;

typedef union DDR_DDRC_REMAP_EXT_1_union_tag { /* Remap Extended Region 1 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_1_EA:8;          /* Region 1 Extended Ending Address */
    volatile uint32 EXT_REG_1_SA:8;          /* Region 1 Extended Starting Address */
    volatile uint32 REG_1_EXT_REMAP_ADDR:8;  /* Region 1 Extended Remap Starting Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_REMAP_EXT_1_tag;

typedef union DDR_DDRC_REMAP_EXT_2_union_tag { /* Remap Extended Region 2 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_2_EA:8;          /* Region 2 Extended Ending Address */
    volatile uint32 EXT_REG_2_SA:8;          /* Region 2 Extended Starting Address */
    volatile uint32 REG_2_EXT_REMAP_ADDR:8;  /* Region 2 Extended Remap Starting Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_REMAP_EXT_2_tag;

typedef union DDR_DDRC_REMAP_EXT_3_union_tag { /* Remap Extended Region 3 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_3_EA:8;          /* Region 3 Extended Ending Address */
    volatile uint32 EXT_REG_3_SA:8;          /* Region 3 Extended Starting Address */
    volatile uint32 REG_3_EXT_REMAP_ADDR:8;  /* Region 3 Extended Remap Starting Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_REMAP_EXT_3_tag;

typedef union DDR_DDRC_REMAP_0A_union_tag { /* Remap Region 0A Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_0_REMAP_ADDR:12;     /* Region 0 Remap Starting Address */
    volatile uint32 _unused_1:19;
    volatile uint32 REG_0_REMAP_EN:1;        /* Region 0 Remap Enable */
  } B;
} DDR_DDRC_REMAP_0A_tag;

typedef union DDR_DDRC_REMAP_0B_union_tag { /* Remap Region 0B Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_0_EA:12;             /* Region 0 Ending Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_0_SA:12;             /* Region 0 Starting Address */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_REMAP_0B_tag;

typedef union DDR_DDRC_REMAP_1A_union_tag { /* Remap Region 1A Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_1_REMAP_ADDR:12;     /* Region 1 Remap Starting Address */
    volatile uint32 _unused_1:19;
    volatile uint32 REG_1_REMAP_EN:1;        /* Region 1 Remap Enable */
  } B;
} DDR_DDRC_REMAP_1A_tag;

typedef union DDR_DDRC_REMAP_1B_union_tag { /* Remap Region 1B Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_1_EA:12;             /* Region 1 Ending Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_1_SA:12;             /* Region 1 Starting Address */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_REMAP_1B_tag;

typedef union DDR_DDRC_REMAP_2A_union_tag { /* Remap Region 2A Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_2_REMAP_ADDR:12;     /* Region 2 Remap Starting Address */
    volatile uint32 _unused_1:19;
    volatile uint32 REG_2_REMAP_EN:1;        /* Region 2 Remap Enable */
  } B;
} DDR_DDRC_REMAP_2A_tag;

typedef union DDR_DDRC_REMAP_2B_union_tag { /* Remap Region 2B Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_2_EA:12;             /* Region 2 Ending Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_2_SA:12;             /* Region 2 Starting Address */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_REMAP_2B_tag;

typedef union DDR_DDRC_REMAP_3A_union_tag { /* Remap Region 3A Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_3_REMAP_ADDR:12;     /* Region 3 Remap Starting Address */
    volatile uint32 _unused_1:19;
    volatile uint32 REG_3_REMAP_EN:1;        /* Region 3 Remap Enable */
  } B;
} DDR_DDRC_REMAP_3A_tag;

typedef union DDR_DDRC_REMAP_3B_union_tag { /* Remap Region 3B Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_3_EA:12;             /* Region 3 Ending Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_3_SA:12;             /* Region 3 Starting Address */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_REMAP_3B_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_0_union_tag { /* DDRC Address Decode 0 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 ROW14_OVRD:6;            /* Row 14 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 ROW15_OVRD:6;            /* Row 15 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 ROW16_OVRD:6;            /* Row 16 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 ROW17_OVRD:6;            /* Row 17 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_0_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_1_union_tag { /* DDRC Address Decode 1 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 ROW10_OVRD:6;            /* Row 10 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 ROW11_OVRD:6;            /* Row 11 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 ROW12_OVRD:6;            /* Row 12 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 ROW13_OVRD:6;            /* Row 13 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_1_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_2_union_tag { /* DDRC Address Decode 2 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 ROW6_OVRD:6;             /* Row 6 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 ROW7_OVRD:6;             /* Row 7 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 ROW8_OVRD:6;             /* Row 8 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 ROW9_OVRD:6;             /* Row 9 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_2_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_3_union_tag { /* DDRC Address Decode 3 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 ROW2_OVRD:6;             /* Row 2 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 ROW3_OVRD:6;             /* Row 3 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 ROW4_OVRD:6;             /* Row 4 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 ROW5_OVRD:6;             /* Row 5 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_3_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_4_union_tag { /* DDRC Address Decode 4 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 COL9_OVRD:6;             /* Col 9 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 COL10_OVRD:6;            /* Col 10 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 ROW0_OVRD:6;             /* Row 0 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 ROW1_OVRD:6;             /* Row 1 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_4_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_5_union_tag { /* DDRC Address Decode 5 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 COL5_OVRD:6;             /* Col 5 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 COL6_OVRD:6;             /* Col 6 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 COL7_OVRD:6;             /* Col 7 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 COL8_OVRD:6;             /* Col 8 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_5_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_6_union_tag { /* DDRC Address Decode 6 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 COL1_OVRD:6;             /* Col 1 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 COL2_OVRD:6;             /* Col 2 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 COL3_OVRD:6;             /* Col 3 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 COL4_OVRD:6;             /* Col 4 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_6_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_7_union_tag { /* DDRC Address Decode 7 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 CID1_OVRD:6;             /* CID 1 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 BA0_OVRD:6;              /* Bank 0 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 BA1_OVRD:6;              /* Bank 1 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 COL0_OVRD:6;             /* Col 0 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_7_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_8_union_tag { /* DDRC Address Decode 8 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 BG1_OVRD:6;              /* Bank Group 1 Override */
    volatile uint32 _unused_22:2;
    volatile uint32 CS0_OVRD:6;              /* Interleaved Rank 0 Override */
    volatile uint32 _unused_14:2;
    volatile uint32 CS1_OVRD:6;              /* Interleaved Rank 1 Override */
    volatile uint32 _unused_6:2;
    volatile uint32 CID0_OVRD:6;             /* CID 0 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_8_tag;

typedef union DDR_DDRC_DDR_ADDR_DEC_9_union_tag { /* DDRC Address Decode 9 */
  volatile uint32 R;
  struct {
    volatile uint32 ADDR_DEC_OVRD:1;         /* Address Decode Override */
    volatile uint32 _unused_6:25;
    volatile uint32 BG0_OVRD:6;              /* Bank Group 0 Override */
  } B;
} DDR_DDRC_DDR_ADDR_DEC_9_tag;

typedef union DDR_DDRC_CS_CONFIG_union_tag { /* Rank 0 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 COL_BITS_CS:3;           /* Column Bits */
    volatile uint32 _unused_28:1;
    volatile uint32 BG_BITS_CS:2;            /* Bank Group Bits */
    volatile uint32 _unused_24:2;
    volatile uint32 ROW_BITS_CS:3;           /* Row Bits */
    volatile uint32 _unused_16:5;
    volatile uint32 ODT_WR_CFG:3;            /* ODT Write Configuration */
    volatile uint32 _unused_12:1;
    volatile uint32 ODT_RD_CFG:3;            /* ODT Read Configuration */
    volatile uint32 AP_EN:1;                 /* Auto-Precharge Enable */
    volatile uint32 INTLV_CTL:4;             /* Interleaving Control */
    volatile uint32 _unused_3:1;
    volatile uint32 INTLV_EN:2;              /* Interleaving Enable */
    volatile uint32 CS_EN:1;                 /* Rank Enable */
  } B;
} DDR_DDRC_CS_CONFIG_tag;

typedef union DDR_DDRC_TIMING_CFG_3_union_tag { /* DDR SDRAM Timing Configuration 3 */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_WRTORD:1;            /* Extended Write-To-Read Time */
    volatile uint32 EXT_ACTTOACT:1;          /* Extended Activate-To-Activate Time */
    volatile uint32 SPARE_CNFG:1;            /* Spare Config */
    volatile uint32 EXT_FOUR_ACT:1;          /* Extended Four Activate */
    volatile uint32 EXT_CKE_PLS:2;           /* Extended MCKE Pulse */
    volatile uint32 _unused_24:2;
    volatile uint32 EXT_WRREC:3;             /* Extended Write Recovery */
    volatile uint32 EXT_WR_LAT_2:1;          /* Extended Write Latency 2 */
    volatile uint32 EXT_CASLAT:3;            /* Extended CAS Latency */
    volatile uint32 _unused_16:1;
    volatile uint32 EXT_REFREC:6;            /* Extended Refresh Recovery */
    volatile uint32 EXT_ACTTORW:2;           /* Extended Activate To Read Or Write Time */
    volatile uint32 EXT_ACTTOPRE:3;          /* Extended Activate-To-Precharge Time */
    volatile uint32 _unused_4:1;
    volatile uint32 EXT_PRETOACT:2;          /* Extended Precharge-To-Activate Time */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_TIMING_CFG_3_tag;

typedef union DDR_DDRC_TIMING_CFG_0_union_tag { /* DDR SDRAM Timing Configuration 0 */
  volatile uint32 R;
  struct {
    volatile uint32 MRS_CYC:6;               /* MRW Cycle Time */
    volatile uint32 _unused_20:6;
    volatile uint32 EXT_ACT_PD_EXIT:1;       /* Extended Active Power-Down Exit */
    volatile uint32 _unused_18:1;
    volatile uint32 EXT_PRE_PD_EXIT:2;       /* Extended Precharge Power-Down Exit */
    volatile uint32 PRE_PD_EXIT:4;           /* Precharge Power-Down Exit */
    volatile uint32 ACT_PD_EXIT:4;           /* Active Powerdown Exit */
    volatile uint32 WWT:2;                   /* Write-To-Write Turnaround To Different Ranks */
    volatile uint32 RRT:2;                   /* Read-To-Read Turnaround To Different Ranks */
    volatile uint32 WRT:2;                   /* Write-To-Read Turnaround To Different Ranks */
    volatile uint32 RWT:2;                   /* Read-To-Write Turnaround To Different Ranks */
  } B;
} DDR_DDRC_TIMING_CFG_0_tag;

typedef union DDR_DDRC_TIMING_CFG_1_union_tag { /* DDR SDRAM Timing Configuration 1 */
  volatile uint32 R;
  struct {
    volatile uint32 WRTORD:4;                /* Write-To-Read Interval */
    volatile uint32 ACTTOACT:4;              /* Activate-To-Activate Interval */
    volatile uint32 WRREC:4;                 /* Write Recovery */
    volatile uint32 REFREC:4;                /* Refresh Recovery */
    volatile uint32 _unused_15:1;
    volatile uint32 CASLAT:3;                /* CAS Latency */
    volatile uint32 ACTTORW:4;               /* Activate To Read Or Write */
    volatile uint32 ACTTOPRE:4;              /* Activate-To-Precharge Time */
    volatile uint32 PRETOACT:4;              /* Precharge-To-Activate Time */
  } B;
} DDR_DDRC_TIMING_CFG_1_tag;

typedef union DDR_DDRC_TIMING_CFG_2_union_tag { /* DDR SDRAM Timing Configuration 2 */
  volatile uint32 R;
  struct {
    volatile uint32 FOUR_ACT:6;              /* Four Activate */
    volatile uint32 CKE_PLS:3;               /* MCKE Pulse */
    volatile uint32 _unused_19:4;
    volatile uint32 RD_TO_PRE:5;             /* Read-To-Precharge Time */
    volatile uint32 EXT_WR_LAT:1;            /* Extended Write Latency */
    volatile uint32 WR_LAT:4;                /* Write Latency */
    volatile uint32 _unused_4:5;
    volatile uint32 DERATE_VAL:4;            /* Derate Value */
  } B;
} DDR_DDRC_TIMING_CFG_2_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_union_tag { /* DDR SDRAM Control Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 BI:1;                    /* Bypass Initialization */
    volatile uint32 MEM_HALT:1;              /* DDRC Halt */
    volatile uint32 RSRVD:1;                 /* Reserved. Should be written to 0. */
    volatile uint32 _unused_28:1;
    volatile uint32 _unused_24:4;
    volatile uint32 BA_INTLV_CTL:7;          /* Rank interleaving control. */
    volatile uint32 _unused_16:1;
    volatile uint32 DC_EN:1;                 /* Dual Channel Enable */
    volatile uint32 _unused_14:1;
    volatile uint32 _unused_13:1;
    volatile uint32 DBW:2;                   /* DDR SDRAM Data Bus Width */
    volatile uint32 DYN_PWR:1;               /* Dynamic Power Management */
    volatile uint32 _unused_8:2;
    volatile uint32 SDRAM_TYPE:3;            /* DDR SDRAM Type */
    volatile uint32 _unused_4:1;
    volatile uint32 RD_EN:1;                 /* Registered DIMM Enable */
    volatile uint32 _unused_2:1;
    volatile uint32 SREN:1;                  /* Self-Refresh Enable */
    volatile uint32 MEM_EN:1;                /* DDRC Enable */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_2_union_tag { /* DDR SDRAM Control Configuration 2 */
  volatile uint32 R;
  struct {
    volatile uint32 SPARE_CNFG:1;            /* Spare Config */
    volatile uint32 _unused_30:1;
    volatile uint32 _unused_29:1;
    volatile uint32 SPARE_CNFG2:1;           /* Spare Config */
    volatile uint32 D_INIT:1;                /* DDR SDRAM Data Initialization */
    volatile uint32 SPARE_CNFG3:2;           /* Spare Config */
    volatile uint32 _unused_24:1;
    volatile uint32 RSRVD:1;                 /* Reserved. Must be written to 0. */
    volatile uint32 QD_EN:1;                 /* Quad-Rank Enable */
    volatile uint32 _unused_21:1;
    volatile uint32 _unused_20:1;
    volatile uint32 NUM_PR:4;                /* Number Of Posted Refreshes */
    volatile uint32 _unused_11:5;
    volatile uint32 _unused_10:1;
    volatile uint32 MT_RR_EN:1;              /* Memory Test Round-Robin Enable */
    volatile uint32 _unused_8:1;
    volatile uint32 MCK_DIS:4;               /* MCK Disable */
    volatile uint32 _unused_2:2;
    volatile uint32 _unused_1:1;
    volatile uint32 FRC_SR:1;                /* Force Self-Refresh */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_2_tag;

typedef union DDR_DDRC_DDR_SDRAM_MD_CNTL_union_tag { /* DDR SDRAM Mode Control */
  volatile uint32 R;
  struct {
    volatile uint32 MD_VALUE:18;             /* Mode Register Value */
    volatile uint32 _unused_13:1;
    volatile uint32 _unused_12:1;
    volatile uint32 CKE_CNTL:2;              /* Clock Enable Control */
    volatile uint32 START_OSC:1;             /* Start Oscillator */
    volatile uint32 START_OSC2:1;            /* Start Oscillator 2 */
    volatile uint32 MD_SEL:4;                /* Mode Register Select */
    volatile uint32 CS_SEL:3;                /* Select Rank */
    volatile uint32 MD_EN:1;                 /* Mode Enable */
  } B;
} DDR_DDRC_DDR_SDRAM_MD_CNTL_tag;

typedef union DDR_DDRC_DDR_SDRAM_INTERVAL_union_tag { /* DDR SDRAM Interval Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 BSTOPRE:14;              /* Precharge Interval */
    volatile uint32 _unused_16:2;
    volatile uint32 REFINT:16;               /* Refresh Interval */
  } B;
} DDR_DDRC_DDR_SDRAM_INTERVAL_tag;

typedef union DDR_DDRC_DDR_DATA_INIT_union_tag { /* DDR SDRAM Data Initialization */
  volatile uint32 R;
  struct {
    volatile uint32 INIT_VALUE:32;           /* Initialization Value */
  } B;
} DDR_DDRC_DDR_DATA_INIT_tag;

typedef union DDR_DDRC_TIMING_CFG_4_union_tag { /* DDR SDRAM Timing Configuration 4 */
  volatile uint32 R;
  struct {
    volatile uint32 DLL_LOCK:2;              /* DDR SDRAM DLL Lock Time */
    volatile uint32 _unused_28:2;
    volatile uint32 EXT_REFINT:1;            /* Extended Refresh Interval */
    volatile uint32 _unused_24:3;
    volatile uint32 EXT_WWT:2;               /* Extended Write-To-Write Turnaround */
    volatile uint32 EXT_RRT:2;               /* Extended Read-To-Read Turnaround */
    volatile uint32 EXT_WRT:2;               /* Extended Write-To-Read Turnaround */
    volatile uint32 EXT_RWT:2;               /* Extended Read-To-Write Turnaround */
    volatile uint32 WWT:4;                   /* Write-To-Write Turnaround For Same Rank */
    volatile uint32 RRT:4;                   /* Read-To-Read Turnaround For Same Rank */
    volatile uint32 WRT:4;                   /* Write-To-Read Turnaround For Same Rank */
    volatile uint32 RWT:4;                   /* Read-To-Write Turnaround For Same Rank */
  } B;
} DDR_DDRC_TIMING_CFG_4_tag;

typedef union DDR_DDRC_TIMING_CFG_5_union_tag { /* DDR SDRAM Timing Configuration 5 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_24:8;
    volatile uint32 _unused_21:3;
    volatile uint32 _unused_20:1;
    volatile uint32 _unused_15:5;
    volatile uint32 _unused_12:3;
    volatile uint32 _unused_9:3;
    volatile uint32 _unused_8:1;
    volatile uint32 _unused_3:5;
    volatile uint32 _unused_0:3;
  } B;
} DDR_DDRC_TIMING_CFG_5_tag;

typedef union DDR_DDRC_TIMING_CFG_7_union_tag { /* DDR SDRAM Timing Configuration 7 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_28:4;
    volatile uint32 WR_ADJ:3;                /* Write Adjustment */
    volatile uint32 RSRVD_1:1;               /* Reserved. */
    volatile uint32 _unused_16:8;
    volatile uint32 RD_ADJ:3;                /* Read Adjustment */
    volatile uint32 RSRVD:1;                 /* Reserved. */
    volatile uint32 CKSRX:4;                 /* Clock After Self-Refresh Exit */
    volatile uint32 CKSRE:4;                 /* Clock After Self-Refresh Entry */
    volatile uint32 CKE_RST:2;               /* MCKE Reset Time */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_TIMING_CFG_7_tag;

typedef union DDR_DDRC_DDR_ZQ_CNTL_union_tag { /* DDR SDRAM ZQ Calibration Control */
  volatile uint32 R;
  struct {
    volatile uint32 ZQCS_INT:4;              /* ZQCS Interval */
    volatile uint32 _unused_24:4;
    volatile uint32 ZQCS:4;                  /* ZQ Calibration Short Time */
    volatile uint32 _unused_16:4;
    volatile uint32 ZQOPER:4;                /* ZQ Calibration Operation Time */
    volatile uint32 _unused_8:4;
    volatile uint32 ZQINIT:4;                /* ZQ Calibration Initialization Time */
    volatile uint32 _unused_1:3;
    volatile uint32 ZQ_EN:1;                 /* ZQ Calibration Enable */
  } B;
} DDR_DDRC_DDR_ZQ_CNTL_tag;

typedef union DDR_DDRC_DDR_SR_CNTR_union_tag { /* DDR SDRAM Self-Refresh Counter */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_16:16;
    volatile uint32 SR_IT:4;                 /* Self-Refresh Idle Threshold */
    volatile uint32 _unused_0:12;
  } B;
} DDR_DDRC_DDR_SR_CNTR_tag;

typedef union DDR_DDRC_TIMING_CFG_8_union_tag { /* DDR SDRAM Timing Configuration 8 */
  volatile uint32 R;
  struct {
    volatile uint32 PRE_ALL_REC:6;           /* Precharge All-To-Activate Interval */
    volatile uint32 _unused_25:1;
    volatile uint32 EXT_WRTORD_BG:1;         /* Extended Write-To-Read Same Bank Group */
    volatile uint32 WRTORD_BG:4;             /* Write-To-Read Same Bank Group */
    volatile uint32 ACTTOACT_BG:4;           /* Activate-To-Activate Same Bank Group */
    volatile uint32 WWT_BG:4;                /* Write-To-Write Turnaround For Same CS And Bank Group */
    volatile uint32 RRT_BG:4;                /* Read-To-Read Turnaround For Same Rank And Bank Group */
    volatile uint32 WRT_BG:4;                /* Write-To-Read Turnaround For Same Rank And Bank Group */
    volatile uint32 RWT_BG:4;                /* Read-To-Write Turnaround For Same Rank And Bank Group */
  } B;
} DDR_DDRC_TIMING_CFG_8_tag;

typedef union DDR_DDRC_TIMING_CFG_9_union_tag { /* DDR SDRAM timing configuration 9 */
  volatile uint32 R;
  struct {
    volatile uint32 REFTOREF_PB:10;          /* Refresh-to-refresh interval for per-bank refresh. */
    volatile uint32 SPARE_CNFG:2;            /* Spare Config */
    volatile uint32 _unused_16:4;
    volatile uint32 REFREC_PB:10;            /* Refresh Recovery Per-Bank Refresh */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_TIMING_CFG_9_tag;

typedef union DDR_DDRC_TIMING_CFG_10_union_tag { /* DDR SDRAM Timing Configuration 10 */
  volatile uint32 R;
  struct {
    volatile uint32 T_STAB:15;               /* Stabilization Wait Time */
    volatile uint32 _unused_9:8;
    volatile uint32 PBRTOACT:5;              /* Per-Bank Refresh to Activate */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_TIMING_CFG_10_tag;

typedef union DDR_DDRC_TIMING_CFG_11_union_tag { /* DDR SDRAM Timing Configuration 11 */
  volatile uint32 R;
  struct {
    volatile uint32 MWWT:4;                  /* Masked Write-To-Write Turnaround (tCCDMW) */
    volatile uint32 _unused_24:4;
    volatile uint32 PRE_TO_PRE:4;            /* Precharge-To-Precharge Time */
    volatile uint32 _unused_16:4;
    volatile uint32 WCKEN_FS:4;              /* WCKEN FS Time */
    volatile uint32 WCK_STOP:4;              /* WCK Stop Time */
    volatile uint32 WS_OFF:3;                /* WS_OFF Wait Time */
    volatile uint32 RSRVD:1;                 /* Reserved. Should be written to 0. */
    volatile uint32 WCKPRE_STATIC:4;         /* WCKPRE Static Time */
  } B;
} DDR_DDRC_TIMING_CFG_11_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_3_union_tag { /* DDR SDRAM Control Configuration 3 */
  volatile uint32 R;
  struct {
    volatile uint32 DIS_MR13:1;              /* Disable MR13 Write for Self Refresh */
    volatile uint32 SR_FAST_WK_EN:1;         /* Self Refresh Fast Wakeup Enable */
    volatile uint32 RSRVD:1;                 /* Reserved. Should be written to 0. */
    volatile uint32 NON_PWR_2:1;             /* Non Power of 2 Enable */
    volatile uint32 SR_PD_EN:1;              /* Self Refresh Powerdown Enable */
    volatile uint32 DIS_MR28:1;              /* Disable MR28 Write for Self Refresh */
    volatile uint32 _unused_25:1;
    volatile uint32 DYN_REF_RATE_EN:1;       /* Dynamic Refresh Rate Enable */
    volatile uint32 REF_MODE:2;              /* Refresh Mode */
    volatile uint32 _unused_21:1;
    volatile uint32 DRAIN_FOR_SR:1;          /* Drain Queues For Self-Refresh */
    volatile uint32 DM_CFG:3;                /* Data Mask Configuration */
    volatile uint32 _unused_16:1;
    volatile uint32 CHB_SWP_EN:1;            /* Channel B Swap Enable */
    volatile uint32 CHA_SWP_EN:1;            /* Channel A Swap Enable */
    volatile uint32 TRM_EN:1;                /* Targeted Refresh Management */
    volatile uint32 HP_EN:1;                 /* High Performance Enable */
    volatile uint32 CMD_QUEUE_DPTH:2;        /* Command Queue Depth. */
    volatile uint32 _unused_8:2;
    volatile uint32 ECC_SCRUB_INT:4;         /* ECC Scrubbing Interval */
    volatile uint32 _unused_2:2;
    volatile uint32 ECC_FIX_EN:1;            /* ECC Fixing Enable */
    volatile uint32 DDRC_RST:1;              /* DDRC Reset */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_3_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_4_union_tag { /* DDR SDRAM Control Configuration 4 */
  volatile uint32 R;
  struct {
    volatile uint32 BLK_RD_WR:3;             /* Block Read-To-Write. */
    volatile uint32 BLK_WR_RD:3;             /* Block Write-To-Read. */
    volatile uint32 BLK_RD_RD:3;             /* Block Read-To-Read. */
    volatile uint32 BLK_WR_WR:3;             /* Block Write-To-Write. */
    volatile uint32 DFI_FREQ:5;              /* DFI Frequency. */
    volatile uint32 DFI_FREQ_HS:5;           /* DFI Frequency */
    volatile uint32 _unused_8:2;
    volatile uint32 DFI_FREQ_FSP:2;          /* DFI Frequency FSP. */
    volatile uint32 _unused_4:2;
    volatile uint32 DFI_WAKEUP:4;            /* DFI Wakeup. */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_4_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_5_union_tag { /* DDR SDRAM Control Configuration 5 */
  volatile uint32 R;
  struct {
    volatile uint32 LNK_ECC_EN:1;            /* Link ECC enable. */
    volatile uint32 DSLP_EN:1;               /* Deep sleep enable. */
    volatile uint32 _unused_24:6;
    volatile uint32 WCK_DYN:1;               /* WCK Dynamic Mode. */
    volatile uint32 _unused_8:15;
    volatile uint32 MED_PRIO:4;              /* Medium Priority Level. */
    volatile uint32 HIGH_PRIO:4;             /* High Priority Level. */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_5_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_6_union_tag { /* DDR SDRAM Control Configuration 6 */
  volatile uint32 R;
  struct {
    volatile uint32 MR28_VAL:6;              /* MR28 Value. */
    volatile uint32 RRO:1;                   /* Refresh rate option. */
    volatile uint32 FRC_DFI_INIT:1;          /* Force dfi_init_start low. */
    volatile uint32 ALT_TRN_INT:4;           /* Force dfi_init_start low. */
    volatile uint32 ADDR_SZL_EN:1;           /* Address swizzle enable. */
    volatile uint32 RD_SPLT_EN:1;            /* Read split enable. */
    volatile uint32 SRE_DIS:1;               /* Self refresh entry disable. */
    volatile uint32 IECC_PERF_EN:1;          /* Inline ECC performance enable. */
    volatile uint32 RH_REF_SUB:3;            /* Row hammer refresh subtract value. */
    volatile uint32 RH_THRSHLD3:3;           /* Row hammer threshold 3 value. */
    volatile uint32 RH_THRSHLD2:3;           /* Row hammer threshold 2 value. */
    volatile uint32 RH_THRSHLD1:3;           /* Row hammer threshold 1 value. */
    volatile uint32 RH_CYC_RST:3;            /* Row hammer cycle reset value. */
    volatile uint32 LP5_RFM_EN:1;            /* LPDDR5 refresh management enable. */
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_6_tag;

typedef union DDR_DDRC_DDR_SDRAM_MD_CNTL2_union_tag { /* DDR SDRAM mode control 2 */
  volatile uint32 R;
  struct {
    volatile uint32 DQ_CNTL:18;              /* Data control. */
    volatile uint32 MPRR_RD_SEL:2;           /* MPRR read select. */
    volatile uint32 PDA_EN:1;                /* Per DDR SDRAM Addressability Enable. */
    volatile uint32 _unused_3:8;
    volatile uint32 NOP_EN:1;                /* NOP Enable. */
    volatile uint32 MPRW:1;                  /* Multi-purpose register write. */
    volatile uint32 MPRR:1;                  /* Multi-purpose register read. */
  } B;
} DDR_DDRC_DDR_SDRAM_MD_CNTL2_tag;

typedef union DDR_DDRC_DDR_SDRAM_CFG_7_union_tag { /* DDR SDRAM Control Configuration 7 */
  volatile uint32 R;
  struct {
    volatile uint32 UPD_INT:3;               /* Update interval. */
    volatile uint32 _unused_28:1;
    volatile uint32 BYP_DIS:1;               /* Bypass Disable. */
    volatile uint32 _unused_16:11;
    volatile uint32 RCOV:6;                  /* Read Collision Override Value. */
    volatile uint32 RCOE:1;                  /* Read Collision Override Enable. */
    volatile uint32 _unused_8:1;
    volatile uint32 RBOV:6;                  /* Read Block Override Value. */
    volatile uint32 RBOE:1;                  /* Read Block Override Enable. */
    volatile uint32 _unused_0:1;
  } B;
} DDR_DDRC_DDR_SDRAM_CFG_7_tag;

typedef union DDR_DDRC_DDR_SDRAM_MPR1_union_tag { /* DDR SDRAM multi-purpose register 1 */
  volatile uint32 R;
  struct {
    volatile uint32 MPR_READ:32;             /* MPR Read Value. */
  } B;
} DDR_DDRC_DDR_SDRAM_MPR1_tag;

typedef union DDR_DDRC_DDR_SDRAM_MPR2_union_tag { /* DDR SDRAM multi-purpose register 2 */
  volatile uint32 R;
  struct {
    volatile uint32 MPR_READ:32;             /* MPR Read Value. */
  } B;
} DDR_DDRC_DDR_SDRAM_MPR2_tag;

typedef union DDR_DDRC_DDR_SDRAM_MPR3_union_tag { /* DDR SDRAM multi-purpose register 3 */
  volatile uint32 R;
  struct {
    volatile uint32 MPR_READ:32;             /* MPR Read Value. */
  } B;
} DDR_DDRC_DDR_SDRAM_MPR3_tag;

typedef union DDR_DDRC_DDR_SDRAM_MPR4_union_tag { /* DDR SDRAM multi-purpose register 4 */
  volatile uint32 R;
  struct {
    volatile uint32 MPR_READ:32;             /* MPR Read Value. */
  } B;
} DDR_DDRC_DDR_SDRAM_MPR4_tag;

typedef union DDR_DDRC_DDR_SDRAM_MPR5_union_tag { /* DDR SDRAM multi-purpose register 5 */
  volatile uint32 R;
  struct {
    volatile uint32 MPR_VLD:1;               /* MPR Valid. */
    volatile uint32 _unused_16:15;
    volatile uint32 MPR_READ:16;             /* MPR Read Value. */
  } B;
} DDR_DDRC_DDR_SDRAM_MPR5_tag;

typedef union DDR_DDRC_DDR_SDRAM_REF_RATE_union_tag { /* DDR Refresh Rate */
  volatile uint32 R;
  struct {
    volatile uint32 REF_RATE_CS1:8;          /* Refresh Rate Rank 1 */
    volatile uint32 REF_RATE_CS0:8;          /* Refresh Rate Rank 0 */
    volatile uint32 REF_RATE_CS1_CHB:8;      /* Refresh Rate Rank 1 */
    volatile uint32 REF_RATE_CS0_CHB:8;      /* Refresh Rate Rank 0 */
  } B;
} DDR_DDRC_DDR_SDRAM_REF_RATE_tag;

typedef union DDR_DDRC_TIMING_CFG_12_union_tag { /* DDR SDRAM Timing Configuration 12 */
  volatile uint32 R;
  struct {
    volatile uint32 CASLAT_HS:6;             /* CAS Latency For Half Speed */
    volatile uint32 _unused_24:2;
    volatile uint32 ACTTORW_HS:6;            /* Activate To Read Or Write For Half Speed */
    volatile uint32 _unused_16:2;
    volatile uint32 ACTTOPRE_HS:7;           /* Activate-To-Precharge Time For Half Speed */
    volatile uint32 _unused_8:1;
    volatile uint32 PRETOACT_HS:6;           /* Precharge-To-Activate Time For Half Speed */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_TIMING_CFG_12_tag;

typedef union DDR_DDRC_TIMING_CFG_13_union_tag { /* DDR SDRAM Timing Configuration 13 */
  volatile uint32 R;
  struct {
    volatile uint32 ACTTOACT_HS:5;           /* Activate-To-Activate Interval For Half Speed */
    volatile uint32 _unused_24:3;
    volatile uint32 WRREC_HS:6;              /* Write Recovery For Half Speed */
    volatile uint32 _unused_16:2;
    volatile uint32 REFREC_HS:10;            /* Refresh Recovery For Half Speed */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_TIMING_CFG_13_tag;

typedef union DDR_DDRC_TIMING_CFG_14_union_tag { /* DDR SDRAM Timing Configuration 14 */
  volatile uint32 R;
  struct {
    volatile uint32 REFINT_HS:17;            /* Refresh Interval For Half Speed */
    volatile uint32 _unused_14:1;
    volatile uint32 RD_TO_PRE_HS:5;          /* Read-To-Precharge Time For Half Speed */
    volatile uint32 _unused_8:1;
    volatile uint32 WRLAT_HS:6;              /* Write Latency For Half Speed */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_TIMING_CFG_14_tag;

typedef union DDR_DDRC_TIMING_CFG_15_union_tag { /* DDR SDRAM Timing Configuration 15 */
  volatile uint32 R;
  struct {
    volatile uint32 REFTOREF_PB_HS:10;       /* Refresh-to-refresh interval for per-bank refresh. */
    volatile uint32 _unused_20:2;
    volatile uint32 _unused_16:4;
    volatile uint32 REFREC_PB_HS:10;         /* Refresh Recovery During Per-Bank Refresh. */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_TIMING_CFG_15_tag;

typedef union DDR_DDRC_TIMING_CFG_16_union_tag { /* DDR SDRAM Timing Configuration 16 */
  volatile uint32 R;
  struct {
    volatile uint32 T_STAB_HS:15;            /* Stabilization Wait Time at Half Speed */
    volatile uint32 LNK_ECC_EN_HS:1;         /* Link ECC Enable at Half Speed. */
    volatile uint32 WCK_CNFGS_HS:16;         /* WCK Configuration Settings at Half Speed */
  } B;
} DDR_DDRC_TIMING_CFG_16_tag;

typedef union DDR_DDRC_TIMING_CFG_17_union_tag { /* DDR SDRAM Timing Configuration 17 */
  volatile uint32 R;
  struct {
    volatile uint32 ZQCS_INT_HS:4;           /* ZQCS Interval */
    volatile uint32 _unused_24:4;
    volatile uint32 ZQCS_HS:4;               /* ZQ Calibration Short Time */
    volatile uint32 _unused_16:4;
    volatile uint32 ZQOPER_HS:4;             /* ZQ Calibration Operation Time */
    volatile uint32 _unused_8:4;
    volatile uint32 ZQINIT_HS:4;             /* ZQ Calibration Initialization Time */
    volatile uint32 _unused_0:4;
  } B;
} DDR_DDRC_TIMING_CFG_17_tag;

typedef union DDR_DDRC_TX_CFG_1_union_tag { /* Transaction Configuration Register 1 */
  volatile uint32 R;
  struct {
    volatile uint32 WWATER:4;                /* Write Watermark. */
    volatile uint32 REAP_BLOCK_DIS:1;        /* Read Estimated Activate to Precharge Block Disable. */
    volatile uint32 WEAP_BLOCK_DIS:1;        /* Write Estimated Activate to Precharge Block Disable. */
    volatile uint32 NO_COS:1;                /* No Quality of Service. This field allows you to ignore the QOS value received by the DDR controller such that only one priority is used. */
    volatile uint32 TS_DEPTH:5;              /* Transaction Scheduler Depth */
    volatile uint32 RD_URG_DIS:1;            /* Disable read urgent mode capability */
    volatile uint32 WR_URG_DIS:1;            /* Disable write urgent mode capability */
    volatile uint32 _unused_17:1;
    volatile uint32 RSRV_RDWR:1;             /* Reserve Read and Write Entries. */
    volatile uint32 DYN_RSRV_EN:1;           /* Dynamic Reservation Enable */
    volatile uint32 RDFC_DIS:1;              /* Read Data Flow Control Disabled. */
    volatile uint32 NRM_OCC:2;               /* Normal Occupancy. */
    volatile uint32 BAD_DD:1;                /* Bad Dropdown. */
    volatile uint32 HPR:1;                   /* High Priority Read. */
    volatile uint32 RT_PLS_EN:1;             /* Real-time Urgent Pulse Mode Enable. */
    volatile uint32 _unused_8:1;
    volatile uint32 INF_WR_CNT:1;            /* Infinite Write Count. */
    volatile uint32 INF_RD_CNT:1;            /* Infinite Read Count. */
    volatile uint32 LT_REOD_DIS:1;           /* Large Transaction Reorder Disable. */
    volatile uint32 _unused_4:1;
    volatile uint32 SER:1;                   /* Serialize. */
    volatile uint32 _unused_2:1;
    volatile uint32 HWA_EN:1;                /* Hardware Assert Enable. */
    volatile uint32 _unused_0:1;
  } B;
} DDR_DDRC_TX_CFG_1_tag;

typedef union DDR_DDRC_TX_CFG_2_union_tag { /* Transaction Configuration Register 2 */
  volatile uint32 R;
  struct {
    volatile uint32 WR_BONUS:5;              /* Write Bandwidth Bonus Count. */
    volatile uint32 RSRVD_4:3;               /* Reserved. */
    volatile uint32 WR_CNT:5;                /* Write Bandwidth Count. */
    volatile uint32 RSRVD_3:3;               /* Reserved. */
    volatile uint32 RD_BONUS:5;              /* Read Bandwidth Bonus Count. */
    volatile uint32 RSRVD_2:3;               /* Reserved. */
    volatile uint32 RD_CNT:5;                /* Read Bandwidth Count. */
    volatile uint32 RT_OPT_DIS:1;            /* Real Time Traffic Optimizaiton Disable. */
    volatile uint32 RD_EPA_DIS:1;            /* Read Precharge to Activate Disable. */
    volatile uint32 WR_EPA_DIS:1;            /* Write Precharge to Activate Disable. */
  } B;
} DDR_DDRC_TX_CFG_2_tag;

typedef union DDR_DDRC_TX_CFG_3_union_tag { /* Transaction Configuration Register 3. */
  volatile uint32 R;
  struct {
    volatile uint32 RSRVD_4:3;               /* Reserved. */
    volatile uint32 RMED_BDD:5;              /* Read Medium Bonus Dropdown. */
    volatile uint32 RSRVD_3:3;               /* Reserved. */
    volatile uint32 RHI_BDD:5;               /* Read High Bonus Dropdown. */
    volatile uint32 RSRVD_2:3;               /* Reserved. */
    volatile uint32 RMED_DD:5;               /* Read Medium Dropdown. */
    volatile uint32 RSRVD_1:3;               /* Reserved. */
    volatile uint32 RHI_DD:5;                /* Read High Dropdown. */
  } B;
} DDR_DDRC_TX_CFG_3_tag;

typedef union DDR_DDRC_TX_CFG_4_union_tag { /* Transaction Configuration Register 4. */
  volatile uint32 R;
  struct {
    volatile uint32 RSRVD_4:3;               /* Reserved. */
    volatile uint32 RMED_BDDD:5;             /* Read Medium Bonus Dropdown Duration. */
    volatile uint32 RSRVD_3:3;               /* Reserved. */
    volatile uint32 RHI_BDDD:5;              /* Read High Bonus Dropdown Duration. */
    volatile uint32 RSRVD_2:3;               /* Reserved. */
    volatile uint32 RMED_DDD:5;              /* Read Medium Dropdown Duration. */
    volatile uint32 RSRVD_1:3;               /* Reserved. */
    volatile uint32 RHI_DDD:5;               /* Read High Dropdown Duration. */
  } B;
} DDR_DDRC_TX_CFG_4_tag;

typedef union DDR_DDRC_TX_CFG_5_union_tag { /* Transaction Configuration Register 5. */
  volatile uint32 R;
  struct {
    volatile uint32 EDDRTQ_CFG_5:32;         /* DDRC_TX_CFG_5 used by the DDRC. */
  } B;
} DDR_DDRC_TX_CFG_5_tag;

typedef union DDR_DDRC_DDRDSR_2_union_tag { /* DDR SDRAM Debug Status 2 */
  volatile uint32 R;
  struct {
    volatile uint32 RPD_END:1;               /* Rapid Clear Of Memory End */
    volatile uint32 RPD_ST:1;                /* Rapid Clear Of Memory Start */
    volatile uint32 PHY_INIT_CMPLT:1;        /* DDR PHY Initialization Complete */
    volatile uint32 _unused_2:27;
    volatile uint32 NML:1;                   /* No Modified Lines */
    volatile uint32 IDLE:1;                  /* Memory controller idle (read only). */
  } B;
} DDR_DDRC_DDRDSR_2_tag;

typedef union DDR_DDRC_DDR_IP_REV1_union_tag { /* DDRC Revision 1 */
  volatile uint32 R;
  struct {
    volatile uint32 IP_MN:8;                 /* Minor Revision */
    volatile uint32 IP_MJ:8;                 /* Major Revision */
    volatile uint32 IP_ID:16;                /* IP Block ID */
  } B;
} DDR_DDRC_DDR_IP_REV1_tag;

typedef union DDR_DDRC_DDR_IP_REV2_union_tag { /* DDRC Revision 2 */
  volatile uint32 R;
  struct {
    volatile uint32 IP_CFG:8;                /* IP Block Configuration Options */
    volatile uint32 IP_ERRATA:8;             /* IP Errata Version. */
    volatile uint32 IP_INT:8;                /* IP Block Integration Options */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_DDR_IP_REV2_tag;

typedef union DDR_DDRC_DDR_EOR_union_tag { /* DDR Enhanced Optimization Register */
  volatile uint32 R;
  struct {
    volatile uint32 DYN_BSTOPRE_THRSHLD:6;   /* Dynamic BSTOPRE threshold. */
    volatile uint32 _unused_24:2;
    volatile uint32 DYN_BSTOPRE_EN:1;        /* Dynamic BSTOPRE enable. */
    volatile uint32 _unused_12:11;
    volatile uint32 WR_REOD_DIS:2;           /* Write reorder disable. */
    volatile uint32 _unused_8:2;
    volatile uint32 RD_REOD_DIS:3;           /* Read reorder disable. */
    volatile uint32 _unused_2:3;
    volatile uint32 ADDR_HASH_EN:1;          /* Address hash enabled. */
    volatile uint32 RD_BDW_OPT_DIS:1;        /* Read bandwidth optimization disable. */
  } B;
} DDR_DDRC_DDR_EOR_tag;

typedef union DDR_DDRC_DDR_MTCR_union_tag { /* DDR SDRAM Memory Test Control */
  volatile uint32 R;
  struct {
    volatile uint32 MT_STAT:1;               /* Memory Test Status */
    volatile uint32 _unused_25:6;
    volatile uint32 _unused_24:1;
    volatile uint32 MT_ADDR2_EN:1;           /* Memory Test Address Range 2 Enable. */
    volatile uint32 MT_ADDR_EN:1;            /* Memory Test Address Range Enable */
    volatile uint32 _unused_20:2;
    volatile uint32 MT_TSIZ:3;               /* Memory Test Transaction Size. */
    volatile uint32 _unused_16:1;
    volatile uint32 MT_TRNARND:4;            /* Memory Test Turnaround */
    volatile uint32 _unused_8:4;
    volatile uint32 MT_TYP:2;                /* Memory Test Type */
    volatile uint32 _unused_1:5;
    volatile uint32 MT_EN:1;                 /* Memory Test Enable */
  } B;
} DDR_DDRC_DDR_MTCR_tag;

typedef union DDR_DDRC_DDR_MTP_union_tag { /* DDR SDRAM Memory Test Pattern n */
  volatile uint32 R;
  struct {
    volatile uint32 DDR_PATT:32;             /* DDR SDRAM Pattern */
  } B;
} DDR_DDRC_DDR_MTP_tag;

typedef union DDR_DDRC_DDR_MT_ST_EXT_ADDR_union_tag { /* DDR SDRAM Memory Test Start Extended Address */
  volatile uint32 R;
  struct {
    volatile uint32 MT_ST_EXT_ADDR:8;        /* Memory Test Start Extended Address */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_DDR_MT_ST_EXT_ADDR_tag;

typedef union DDR_DDRC_DDR_MT_ST_ADDR_union_tag { /* DDR SDRAM Memory Test Start Address */
  volatile uint32 R;
  struct {
    volatile uint32 MT_ST_ADDR:32;           /* Memory Test Start Address */
  } B;
} DDR_DDRC_DDR_MT_ST_ADDR_tag;

typedef union DDR_DDRC_DDR_MT_END_EXT_ADDR_union_tag { /* DDR SDRAM Memory Test End Extended Address */
  volatile uint32 R;
  struct {
    volatile uint32 MT_END_EXT_ADDR:8;       /* Memory Test End Extended Address */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_DDR_MT_END_EXT_ADDR_tag;

typedef union DDR_DDRC_DDR_MT_END_ADDR_union_tag { /* DDR SDRAM Memory Test End Address */
  volatile uint32 R;
  struct {
    volatile uint32 MT_END_ADDR:32;          /* Memory Test End Address */
  } B;
} DDR_DDRC_DDR_MT_END_ADDR_tag;

typedef union DDR_DDRC_DDR_MT_ST_EXT_ADDR2_union_tag { /* DDR Memory Test Start Extended Address 2 */
  volatile uint32 R;
  struct {
    volatile uint32 MT_ST_EXT_ADDR2:8;       /* Memory Test Start Extended Address 2 */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_DDR_MT_ST_EXT_ADDR2_tag;

typedef union DDR_DDRC_DDR_MT_ST_ADDR2_union_tag { /* DDR Memory Test Start Address 2 */
  volatile uint32 R;
  struct {
    volatile uint32 MT_ST_ADDR2:32;          /* Memory Test Start Address 2 */
  } B;
} DDR_DDRC_DDR_MT_ST_ADDR2_tag;

typedef union DDR_DDRC_DDR_MT_END_EXT_ADDR2_union_tag { /* DDR Memory Test End Extended Address 2 */
  volatile uint32 R;
  struct {
    volatile uint32 MT_END_EXT_ADDR2:8;      /* Memory Test End Extended Address 2 */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_DDR_MT_END_EXT_ADDR2_tag;

typedef union DDR_DDRC_DDR_MT_END_ADDR2_union_tag { /* DDR Memory Test End Address 2 */
  volatile uint32 R;
  struct {
    volatile uint32 MT_END_ADDR2:32;         /* Memory Test End Address 2 */
  } B;
} DDR_DDRC_DDR_MT_END_ADDR2_tag;

typedef union DDR_DDRC_DEBUG_1_union_tag { /* Debug 1 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_29:3;
    volatile uint32 MAPD:1;                  /* Transaction scheduler auto-precharge disable. */
    volatile uint32 _unused_17:11;
    volatile uint32 CM:1;                    /* Crawl mode. */
    volatile uint32 _unused_3:13;
    volatile uint32 FRC_ZQCS:1;              /* Force ZQCS command. */
    volatile uint32 FRC_ZQCL:1;              /* Force ZQCL command. */
    volatile uint32 UZQO:1;                  /* Update ZQ Calibration Once. */
  } B;
} DDR_DDRC_DEBUG_1_tag;

typedef union DDR_DDRC_DEBUG_2_union_tag { /* Debug 2 */
  volatile uint32 R;
  struct {
    volatile uint32 NML:1;                   /* No Modified Lines */
    volatile uint32 IDLE:1;                  /* Memory controller idle (read only). */
    volatile uint32 SR_I:1;                  /* Memory controller is in self refresh due to idle (read only). */
    volatile uint32 SR:1;                    /* Memory controller is in self refresh and clocks can be gated if DDR_SDRAM_CFG_3[SR_FAST_WK_EN] is 0 (read only). */
    volatile uint32 _unused_26:2;
    volatile uint32 IR:1;                    /* Issue refresh. */
    volatile uint32 WRCD:1;                  /* Write Cancel Disable */
    volatile uint32 _unused_21:3;
    volatile uint32 INV_ARB:1;               /* Invert arbitration mode. */
    volatile uint32 _unused_0:20;
  } B;
} DDR_DDRC_DEBUG_2_tag;

typedef union DDR_DDRC_DEBUG_4_union_tag { /* Debug 4 */
  volatile uint32 R;
  struct {
    volatile uint32 SPARE_CNFG:32;           /* Spare register bits. */
  } B;
} DDR_DDRC_DEBUG_4_tag;

typedef union DDR_DDRC_DEBUG_19_union_tag { /* Debug 19 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_30:2;
    volatile uint32 CNTR_OVRD_VAL:3;         /* Counter Override Value. */
    volatile uint32 CNTR_OVRD:1;             /* Counter Override Enable. */
    volatile uint32 _unused_16:10;
    volatile uint32 MCK_DIS:1;               /* MCK Gating Disable. */
    volatile uint32 _unused_11:4;
    volatile uint32 ALT_TRAIN_EN:1;          /* Alternate Train Enable. */
    volatile uint32 _unused_8:2;
    volatile uint32 REF_READ_RATE:4;         /* Refresh Read Rate. */
    volatile uint32 _unused_2:2;
    volatile uint32 FRC_1X_REF_RATE:1;       /* Force 1x refresh rate. */
    volatile uint32 MCSR:1;                  /* DDRC Soft Reset. */
  } B;
} DDR_DDRC_DEBUG_19_tag;

typedef union DDR_DDRC_DEBUG_20_union_tag { /* Debug 20 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_8:24;
    volatile uint32 DISM_CS:5;               /* DISM Current State. */
    volatile uint32 SPARE_CNFG:1;            /* Spare config bits. */
    volatile uint32 _unused_1:1;
    volatile uint32 INIT_DONE:1;             /* Initialization Done. */
  } B;
} DDR_DDRC_DEBUG_20_tag;

typedef union DDR_DDRC_DEBUG_26_union_tag { /* Debug 26 */
  volatile uint32 R;
  struct {
    volatile uint32 DDRC_WEOD_DIS:1;         /* Command Queue Write Reordering Disable. */
    volatile uint32 _unused_30:1;
    volatile uint32 DIS_CTRLUPD_REQ:1;       /* Disable Controller Update Request. */
    volatile uint32 FRC_WRDATA_CS0:1;        /* Force Write Data Timing to rank 0 */
    volatile uint32 DIS_WR_COMB:1;           /* Disable Write Combining for ECC */
    volatile uint32 SPARE_CNFG2:1;           /* Spare config bits. This must be set to 0. */
    volatile uint32 RESET_RAM:1;             /* Reset RAM. */
    volatile uint32 IDLE_FLUSH_DIS:1;        /* Idle Flush Disable. */
    volatile uint32 WCK_CS:2;                /* WCK_CS Debug. */
    volatile uint32 LEGACY_ROQ:1;            /* Legacy ROQ mode. */
    volatile uint32 DDRC_REOD_DIS:1;         /* Command Queue Read Reordering Disable. */
    volatile uint32 DFI_FREQ:5;              /* DFI Frequency. */
    volatile uint32 DFI_FREQ_HS:5;           /* DFI Frequency. */
    volatile uint32 EXT_DFI_WAKEUP:1;        /* Extended DFI Wakeup. */
    volatile uint32 DFI_RSTN:1;              /* DFI Reset_N. */
    volatile uint32 DFI_FREQ_FSP_HS:2;       /* DFI Frequency FSP Half-Speed. */
    volatile uint32 DFI_FREQ_FSP:2;          /* DFI Frequency FSP. */
    volatile uint32 DFI_WAKEUP:4;            /* DFI Wakeup. */
  } B;
} DDR_DDRC_DEBUG_26_tag;

typedef union DDR_DDRC_DEBUG_27_union_tag { /* Debug 27 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_8:24;
    volatile uint32 INVC:1;                  /* Invalidate Cache */
    volatile uint32 PRE_TO_ACT_4X:1;         /* Precharge-To-Activate x4. */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_DEBUG_27_tag;

typedef union DDR_DDRC_DEBUG_28_union_tag { /* Debug 28 */
  volatile uint32 R;
  struct {
    volatile uint32 PLL_LCK:1;               /* DDR PHY PLL Lock. */
    volatile uint32 _unused_16:15;
    volatile uint32 WLAST_ERR:1;             /* WLAST error bit. */
    volatile uint32 _unused_0:15;
  } B;
} DDR_DDRC_DEBUG_28_tag;

typedef union DDR_DDRC_ERR_EN_union_tag { /* Error Enable */
  volatile uint32 R;
  struct {
    volatile uint32 WTE_EN:1;                /* Write Tag Error Enable */
    volatile uint32 RTE_EN:1;                /* Read Tag Error Enable */
    volatile uint32 LKSTP_2_EN:1;            /* Lockstep 2 Enable */
    volatile uint32 LKSTP_1_EN:1;            /* Lockstep 1 Enable */
    volatile uint32 _unused_27:1;
    volatile uint32 PAR_1_EN:1;              /* Parity Enable For Internal Errors */
    volatile uint32 ECC_EN_RAM_2:1;          /* ECC Enable For On-Chip RAM 2 */
    volatile uint32 ECC_EN_RAM_1:1;          /* ECC Enable For On-Chip RAM 1 */
    volatile uint32 CRC_2_EN:1;              /* CRC Enable For Group 2 Registers */
    volatile uint32 CRC_1_EN:1;              /* CRC Enable For Group 1 Registers */
    volatile uint32 _unused_8:14;
    volatile uint32 DRAM_SF1_EN:1;           /* DRAM Safety Feature 1 Enable */
    volatile uint32 DRAM_SF2_EN:1;           /* DRAM Safety Feature 2 Enable */
    volatile uint32 DRAM_SF3_EN:1;           /* DRAM Safety Feature 3 Enable */
    volatile uint32 _unused_2:3;
    volatile uint32 INLINE_ECC_EN:1;         /* Inline ECC Enable */
    volatile uint32 ECC_EN:1;                /* ECC Enable */
  } B;
} DDR_DDRC_ERR_EN_tag;

typedef union DDR_DDRC_DATA_ERR_INJECT_HI_union_tag { /* Memory Data Path Error Injection Mask High */
  volatile uint32 R;
  struct {
    volatile uint32 EIMH:32;                 /* Error Injection Mask High Data Path */
  } B;
} DDR_DDRC_DATA_ERR_INJECT_HI_tag;

typedef union DDR_DDRC_DATA_ERR_INJECT_LO_union_tag { /* Memory Data Path Error Injection Mask Low */
  volatile uint32 R;
  struct {
    volatile uint32 EIML:32;                 /* Error Injection Mask Low Data Bit */
  } B;
} DDR_DDRC_DATA_ERR_INJECT_LO_tag;

typedef union DDR_DDRC_ERR_INJECT_union_tag { /* Memory Data Path Error Injection Mask ECC */
  volatile uint32 R;
  struct {
    volatile uint32 EEIM:8;                  /* ECC Error Injection Mask */
    volatile uint32 EIEN:1;                  /* Error Injection Enable */
    volatile uint32 _unused_22:1;
    volatile uint32 _unused_20:2;
    volatile uint32 NUM_ECC_INJ:4;           /* Number Of ECC Errors Injected */
    volatile uint32 PIEN:1;                  /* Parity Error Injection Enable */
    volatile uint32 INTEIN:1;                /* Internal Error Injection Enable */
    volatile uint32 INTIES:3;                /* Internal Error Injection Source */
    volatile uint32 ECC_INJ_SRC:2;           /* ECC Injection Source */
    volatile uint32 FRC2B:1;                 /* Force 2-Bit Error */
    volatile uint32 PAR_INJ_SRC:2;           /* Parity Error Injection Source */
    volatile uint32 _unused_1:5;
    volatile uint32 ADDR_TEN:1;              /* Address Trigger Enable */
  } B;
} DDR_DDRC_ERR_INJECT_tag;

typedef union DDR_DDRC_ADDR_ERR_INJ_union_tag { /* Address Error Inject */
  volatile uint32 R;
  struct {
    volatile uint32 ADDR:32;                 /* Address */
  } B;
} DDR_DDRC_ADDR_ERR_INJ_tag;

typedef union DDR_DDRC_EXT_ADDR_ERR_INJ_union_tag { /* Extended Address Error Inject */
  volatile uint32 R;
  struct {
    volatile uint32 EADDR:8;                 /* Extended Address */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_EXT_ADDR_ERR_INJ_tag;

typedef union DDR_DDRC_CAPTURE_EXT_DATA_HI_union_tag { /* Memory Extended Data Path Read Capture High */
  volatile uint32 R;
  struct {
    volatile uint32 ECEHD:32;                /* Error Capture Extended High Data Path */
  } B;
} DDR_DDRC_CAPTURE_EXT_DATA_HI_tag;

typedef union DDR_DDRC_CAPTURE_EXT_DATA_LO_union_tag { /* Memory Extended Data Path Read Capture Low */
  volatile uint32 R;
  struct {
    volatile uint32 ECELD:32;                /* Error Capture Extended Low Data Path */
  } B;
} DDR_DDRC_CAPTURE_EXT_DATA_LO_tag;

typedef union DDR_DDRC_CAPTURE_DATA_HI_union_tag { /* Memory Data Path Read Capture High */
  volatile uint32 R;
  struct {
    volatile uint32 ECHD:32;                 /* Error Capture High Data Path */
  } B;
} DDR_DDRC_CAPTURE_DATA_HI_tag;

typedef union DDR_DDRC_CAPTURE_DATA_LO_union_tag { /* Memory Data Path Read Capture Low */
  volatile uint32 R;
  struct {
    volatile uint32 ECLD:32;                 /* Error Capture Low Data Path */
  } B;
} DDR_DDRC_CAPTURE_DATA_LO_tag;

typedef union DDR_DDRC_CAPTURE_ECC_union_tag { /* Memory Data Path Read Capture ECC */
  volatile uint32 R;
  struct {
    volatile uint32 ECE:32;                  /* Error Capture ECC */
  } B;
} DDR_DDRC_CAPTURE_ECC_tag;

typedef union DDR_DDRC_CAPTURE_UPPER_EXT_DATA_HI_union_tag { /* Memory Upper Extended Data Path Read Capture High */
  volatile uint32 R;
  struct {
    volatile uint32 ECUEHD:32;               /* Error Capture Upper Extended High Data Path */
  } B;
} DDR_DDRC_CAPTURE_UPPER_EXT_DATA_HI_tag;

typedef union DDR_DDRC_CAPTURE_UPPER_EXT_DATA_LO_union_tag { /* Memory Upper Extended Data Path Read Capture Low */
  volatile uint32 R;
  struct {
    volatile uint32 ECUELD:32;               /* Error Capture Upper Extended Low Data Path */
  } B;
} DDR_DDRC_CAPTURE_UPPER_EXT_DATA_LO_tag;

typedef union DDR_DDRC_CAPTURE_UPPER_DATA_HI_union_tag { /* Memory Upper Data Path Read Capture High */
  volatile uint32 R;
  struct {
    volatile uint32 ECUHD:32;                /* Error Capture Upper High Data Path */
  } B;
} DDR_DDRC_CAPTURE_UPPER_DATA_HI_tag;

typedef union DDR_DDRC_CAPTURE_UPPER_DATA_LO_union_tag { /* Memory Upper Data Path Read Capture Low */
  volatile uint32 R;
  struct {
    volatile uint32 ECULD:32;                /* Error Capture Upper Low Data Path */
  } B;
} DDR_DDRC_CAPTURE_UPPER_DATA_LO_tag;

typedef union DDR_DDRC_ERR_DETECT_union_tag { /* Memory Error Detect */
  volatile uint32 R;
  struct {
    volatile uint32 MSE:1;                   /* Memory-Select Error */
    volatile uint32 _unused_30:1;
    volatile uint32 SBE:1;                   /* Single-Bit ECC Errors */
    volatile uint32 MBE:1;                   /* Multiple-Bit Error */
    volatile uint32 ILLTXNE:1;               /* Illegal transaction error. */
    volatile uint32 DRAM3E:1;                /* DRAM 2 error. */
    volatile uint32 _unused_25:1;
    volatile uint32 REFRATEE:1;              /* Refresh rate error. */
    volatile uint32 _unused_22:2;
    volatile uint32 _unused_21:1;
    volatile uint32 LKSTP4E:1;               /* Lockstep 4 error. */
    volatile uint32 SSBE:1;                  /* Scrubbed Single-Bit ECC Error */
    volatile uint32 LNKE:1;                  /* Link ECC Error */
    volatile uint32 DRAM1E:1;                /* DRAM 1 error. */
    volatile uint32 DRAM2E:1;                /* DRAM 2 error. */
    volatile uint32 PHYE:1;                  /* PHY error. */
    volatile uint32 CFGE:1;                  /* Configuration read error. */
    volatile uint32 REGE:1;                  /* Region error. */
    volatile uint32 IPE:1;                   /* Internal Parity Error */
    volatile uint32 UPDTMTE:1;               /* Update Timeout Error */
    volatile uint32 CRCE:1;                  /* Configuration CRC Error */
    volatile uint32 SMBE2:1;                 /* SRAM Multi-Bit Error 2 */
    volatile uint32 SMBE1:1;                 /* SRAM Multi-Bit Error 1 */
    volatile uint32 SSBE2:1;                 /* SRAM SBE 2 */
    volatile uint32 SSBE1:1;                 /* SRAM SBE 1 */
    volatile uint32 WTAGE:1;                 /* Write Tag Error */
    volatile uint32 RTAGE:1;                 /* Read Tag Error */
    volatile uint32 WTTE:1;                  /* Write Tag Timeout Error */
    volatile uint32 RTTE:1;                  /* Read Tag Timeout Error */
    volatile uint32 RTMTE:1;                 /* Read Timeout Error */
    volatile uint32 MME:1;                   /* Multiple Memory Errors */
  } B;
} DDR_DDRC_ERR_DETECT_tag;

typedef union DDR_DDRC_ERR_DISABLE_union_tag { /* Memory Error Disable */
  volatile uint32 R;
  struct {
    volatile uint32 MSED:1;                  /* Memory-Select Error Disable */
    volatile uint32 _unused_30:1;
    volatile uint32 SBED:1;                  /* Single-Bit ECC Error Disable */
    volatile uint32 MBED:1;                  /* Multiple-Bit ECC Error Disable */
    volatile uint32 ILLTXNED:1;              /* Illegal Transaction Error Disable */
    volatile uint32 _unused_25:2;
    volatile uint32 REFRATEED:1;             /* Refresh Rate Error Disable */
    volatile uint32 LNKED:1;                 /* Link ECC Error Disable */
    volatile uint32 SPARE:1;                 /* Spare config bit. */
    volatile uint32 _unused_20:2;
    volatile uint32 SSBED:1;                 /* Scrubbed Single-Bit ECC Error Disable */
    volatile uint32 _unused_16:3;
    volatile uint32 PHYED:1;                 /* PHY Error Disable */
    volatile uint32 _unused_12:3;
    volatile uint32 UPDTMTED:1;              /* Update Timeout Error Disable */
    volatile uint32 _unused_0:11;
  } B;
} DDR_DDRC_ERR_DISABLE_tag;

typedef union DDR_DDRC_ERR_INT_EN_union_tag { /* Memory Error Interrupt Enable */
  volatile uint32 R;
  struct {
    volatile uint32 MSEE:1;                  /* Memory-Select Error Interrupt Enable */
    volatile uint32 _unused_30:1;
    volatile uint32 SBEE:1;                  /* Single-Bit ECC Error Interrupt Enable */
    volatile uint32 MBEE:1;                  /* Multiple-Bit ECC Error Interrupt Enable */
    volatile uint32 SSBE12E:1;               /* SRAM Single-Bit Error Interrupt Enable */
    volatile uint32 _unused_25:2;
    volatile uint32 REFRATEEE:1;             /* Refresh Rate Interrupt Enable */
    volatile uint32 ILLTXNEE:1;              /* Illegal Transaction Interrupt Enable */
    volatile uint32 LNKEE:1;                 /* Link ECC Error Interrupt Enable */
    volatile uint32 _unused_20:2;
    volatile uint32 SSBEE:1;                 /* Scrubbed Single-Bit ECC Error Interrupt Enable */
    volatile uint32 _unused_16:3;
    volatile uint32 PHYEE:1;                 /* PHY error interrupt enable. */
    volatile uint32 _unused_12:3;
    volatile uint32 UPDTMTEE:1;              /* Update Timeout Interrupt Enable */
    volatile uint32 _unused_0:11;
  } B;
} DDR_DDRC_ERR_INT_EN_tag;

typedef union DDR_DDRC_CAPTURE_ATTRIBUTES_union_tag { /* Memory Error Attributes Capture */
  volatile uint32 R;
  struct {
    volatile uint32 VLD:1;                   /* Valid */
    volatile uint32 _unused_28:3;
    volatile uint32 _unused_24:4;
    volatile uint32 _unused_20:4;
    volatile uint32 TTYP:2;                  /* Error Transaction Type */
    volatile uint32 _unused_16:2;
    volatile uint32 TSRC:8;                  /* Error Transaction Source */
    volatile uint32 TSIZ:3;                  /* Error Transaction Size */
    volatile uint32 _unused_4:1;
    volatile uint32 BNUM:3;                  /* Data Beat Number */
    volatile uint32 _unused_0:1;
  } B;
} DDR_DDRC_CAPTURE_ATTRIBUTES_tag;

typedef union DDR_DDRC_CAPTURE_ADDRESS_union_tag { /* Memory Error Address Capture */
  volatile uint32 R;
  struct {
    volatile uint32 CADDR:32;                /* Captured Address */
  } B;
} DDR_DDRC_CAPTURE_ADDRESS_tag;

typedef union DDR_DDRC_CAPTURE_EXT_ADDRESS_union_tag { /* Memory Error Extended Address Capture */
  volatile uint32 R;
  struct {
    volatile uint32 CEADDR:8;                /* Captured Extended Address */
    volatile uint32 _unused_0:24;
  } B;
} DDR_DDRC_CAPTURE_EXT_ADDRESS_tag;

typedef union DDR_DDRC_ERR_SBE_union_tag { /* Single-Bit ECC Memory Error Management */
  volatile uint32 R;
  struct {
    volatile uint32 SBEC:8;                  /* SBE Counter */
    volatile uint32 SSBEC:8;                 /* Scrubbed SBE Counter */
    volatile uint32 SBET:8;                  /* SBE Threshold */
    volatile uint32 SSBET:8;                 /* Scrubbed SBE Threshold */
  } B;
} DDR_DDRC_ERR_SBE_tag;

typedef union DDR_DDRC_REG_CRC_GRP_1_union_tag { /* Register CRC Code For Group 1 */
  volatile uint32 R;
  struct {
    volatile uint32 CRC_1:32;                /* Programmed CRC Code */
  } B;
} DDR_DDRC_REG_CRC_GRP_1_tag;

typedef union DDR_DDRC_REG_CRC_GRP_2_union_tag { /* Register CRC Code For Group 2 */
  volatile uint32 R;
  struct {
    volatile uint32 CRC_2:32;                /* Programmed CRC Code */
  } B;
} DDR_DDRC_REG_CRC_GRP_2_tag;

typedef union DDR_DDRC_ECC_EXT_REG_0_union_tag { /* ECC Extended Region 0 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_0_EA:8;          /* Extended Region 0 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_0_SA:8;          /* Extended Region 0 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_0_tag;

typedef union DDR_DDRC_ECC_EXT_REG_1_union_tag { /* ECC Extended Region 1 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_1_EA:8;          /* Extended Region 1 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_1_SA:8;          /* Extended Region 1 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_1_tag;

typedef union DDR_DDRC_ECC_EXT_REG_2_union_tag { /* ECC Extended Region 2 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_2_EA:8;          /* Extended Region 2 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_2_SA:8;          /* Extended Region 2 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_2_tag;

typedef union DDR_DDRC_ECC_EXT_REG_3_union_tag { /* ECC Extended Region 3 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_3_EA:8;          /* Extended Region 3 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_3_SA:8;          /* Extended Region 3 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_3_tag;

typedef union DDR_DDRC_ECC_EXT_REG_4_union_tag { /* ECC Extended Region 4 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_4_EA:8;          /* Extended Region 4 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_4_SA:8;          /* Extended Region 4 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_4_tag;

typedef union DDR_DDRC_ECC_EXT_REG_5_union_tag { /* ECC Extended Region 5 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_5_EA:8;          /* Extended Region 5 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_5_SA:8;          /* Extended Region 5 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_5_tag;

typedef union DDR_DDRC_ECC_EXT_REG_6_union_tag { /* ECC Extended Region 6 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_6_EA:8;          /* Extended Region 6 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_6_SA:8;          /* Extended Region 6 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_6_tag;

typedef union DDR_DDRC_ECC_EXT_REG_7_union_tag { /* ECC Extended Region 7 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 EXT_REG_7_EA:8;          /* Extended Region 7 End Address */
    volatile uint32 _unused_16:8;
    volatile uint32 EXT_REG_7_SA:8;          /* Extended Region 7 Start Address */
    volatile uint32 _unused_0:8;
  } B;
} DDR_DDRC_ECC_EXT_REG_7_tag;

typedef union DDR_DDRC_ECC_REG_0_union_tag { /* ECC Region 0 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_0_EA:12;             /* Region 0 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_0_SA:12;             /* Region 0 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_0_EN:1;              /* Region 0 Enable */
  } B;
} DDR_DDRC_ECC_REG_0_tag;

typedef union DDR_DDRC_ECC_REG_1_union_tag { /* ECC Region 1 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_1_EA:12;             /* Region 1 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_1_SA:12;             /* Region 1 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_1_EN:1;              /* Region 1 Enable */
  } B;
} DDR_DDRC_ECC_REG_1_tag;

typedef union DDR_DDRC_ECC_REG_2_union_tag { /* ECC Region 2 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_2_EA:12;             /* Region 2 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_2_SA:12;             /* Region 2 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_2_EN:1;              /* Region 2 Enable */
  } B;
} DDR_DDRC_ECC_REG_2_tag;

typedef union DDR_DDRC_ECC_REG_3_union_tag { /* ECC Region 3 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_3_EA:12;             /* Region 3 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_3_SA:12;             /* Region 3 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_3_EN:1;              /* Region 3 Enable */
  } B;
} DDR_DDRC_ECC_REG_3_tag;

typedef union DDR_DDRC_ECC_REG_4_union_tag { /* ECC Region 4 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_4_EA:12;             /* Region 4 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_4_SA:12;             /* Region 4 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_4_EN:1;              /* Region 4 Enable */
  } B;
} DDR_DDRC_ECC_REG_4_tag;

typedef union DDR_DDRC_ECC_REG_5_union_tag { /* ECC Region 5 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_5_EA:12;             /* Region 5 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_5_SA:12;             /* Region 5 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_5_EN:1;              /* Region 5 Enable */
  } B;
} DDR_DDRC_ECC_REG_5_tag;

typedef union DDR_DDRC_ECC_REG_6_union_tag { /* ECC Region 6 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_6_EA:12;             /* Region 6 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_6_SA:12;             /* Region 6 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_6_EN:1;              /* Region 6 Enable */
  } B;
} DDR_DDRC_ECC_REG_6_tag;

typedef union DDR_DDRC_ECC_REG_7_union_tag { /* ECC Region 7 Configuration */
  volatile uint32 R;
  struct {
    volatile uint32 REG_7_EA:12;             /* Region 7 End Address */
    volatile uint32 _unused_16:4;
    volatile uint32 REG_7_SA:12;             /* Region 7 Start Address */
    volatile uint32 _unused_1:3;
    volatile uint32 REG_7_EN:1;              /* Region 7 Enable */
  } B;
} DDR_DDRC_ECC_REG_7_tag;

typedef union DDR_DDRC_PMCFG_1_union_tag { /* Performance Monitor Configuration 1 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_14:18;
    volatile uint32 _unused_3:11;
    volatile uint32 _unused_2:1;
    volatile uint32 RD_BT_FILT_EN:1;         /* Read Beat Filter Enable */
    volatile uint32 WR_BEAT_FILT_EN:1;       /* Write Beat Filter Enable */
  } B;
} DDR_DDRC_PMCFG_1_tag;

typedef union DDR_DDRC_PMCFG_2_union_tag { /* Performance Monitor Configuration 2 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_14:18;
    volatile uint32 _unused_0:14;
  } B;
} DDR_DDRC_PMCFG_2_tag;

typedef union DDR_DDRC_PMCFG_3_union_tag { /* Performance Monitor Configuration 3 */
  volatile uint32 R;
  struct {
    volatile uint32 MSTR_ID_MSK_3:10;        /* Master ID Mask 3 */
    volatile uint32 _unused_16:6;
    volatile uint32 MSTR_ID_3:10;            /* Master ID 3 */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_PMCFG_3_tag;

typedef union DDR_DDRC_PMCFG_4_union_tag { /* Performance Monitor Configuration 4 */
  volatile uint32 R;
  struct {
    volatile uint32 MSTR_ID_MSK_2:10;        /* Master ID Mask 2 */
    volatile uint32 _unused_16:6;
    volatile uint32 MSTR_ID_2:10;            /* Master ID 2 */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_PMCFG_4_tag;

typedef union DDR_DDRC_PMCFG_5_union_tag { /* Performance Monitor Configuration 5 */
  volatile uint32 R;
  struct {
    volatile uint32 MSTR_ID_MSK_1:10;        /* Master ID Mask 1 */
    volatile uint32 _unused_16:6;
    volatile uint32 MSTR_ID_1:10;            /* Master ID 1 */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_PMCFG_5_tag;

typedef union DDR_DDRC_PMCFG_6_union_tag { /* Performance Monitor Configuration 6 */
  volatile uint32 R;
  struct {
    volatile uint32 MSTR_ID_MSK_0:10;        /* Master ID Mask 0 */
    volatile uint32 _unused_16:6;
    volatile uint32 MSTR_ID_0:10;            /* Master ID 0 */
    volatile uint32 _unused_0:6;
  } B;
} DDR_DDRC_PMCFG_6_tag;

typedef union DDR_DDRC_PMGC0_union_tag { /* Performance Monitor Global Control */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_3:29;
    volatile uint32 FCECE:1;                 /* Freeze Counters On Enabled Condition Or Event */
    volatile uint32 PMIE:1;                  /* Performance Monitor Interrupt Enable */
    volatile uint32 FAC:1;                   /* Freeze All Counters */
  } B;
} DDR_DDRC_PMGC0_tag;

typedef union DDR_DDRC_PMLCA0_union_tag { /* Performance Monitor Local Control A0 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_6:26;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA0_tag;

typedef union DDR_DDRC_PMLCB0_union_tag { /* Performance Monitor Local Control B0 */
  volatile uint32 R;
  struct {
    volatile uint32 _unused_16:16;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB0_tag;

typedef union DDR_DDRC_PMC0A_union_tag { /* PMC 0a */
  volatile uint32 R;
  struct {
    volatile uint32 PMC0:32;                 /* Counter 0 */
  } B;
} DDR_DDRC_PMC0A_tag;

typedef union DDR_DDRC_PMC0B_union_tag { /* PMC 0b */
  volatile uint32 R;
  struct {
    volatile uint32 PMC0:32;                 /* Counter 0 */
  } B;
} DDR_DDRC_PMC0B_tag;

typedef union DDR_DDRC_PMLCA1_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA1_tag;

typedef union DDR_DDRC_PMLCB1_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB1_tag;

typedef union DDR_DDRC_PMC1_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC1:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC1_tag;

typedef union DDR_DDRC_PMLCA2_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA2_tag;

typedef union DDR_DDRC_PMLCB2_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB2_tag;

typedef union DDR_DDRC_PMC2_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC2:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC2_tag;

typedef union DDR_DDRC_PMLCA3_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA3_tag;

typedef union DDR_DDRC_PMLCB3_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB3_tag;

typedef union DDR_DDRC_PMC3_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC3:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC3_tag;

typedef union DDR_DDRC_PMLCA4_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA4_tag;

typedef union DDR_DDRC_PMLCB4_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB4_tag;

typedef union DDR_DDRC_PMC4_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC4:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC4_tag;

typedef union DDR_DDRC_PMLCA5_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA5_tag;

typedef union DDR_DDRC_PMLCB5_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB5_tag;

typedef union DDR_DDRC_PMC5_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC5:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC5_tag;

typedef union DDR_DDRC_PMLCA6_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA6_tag;

typedef union DDR_DDRC_PMLCB6_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB6_tag;

typedef union DDR_DDRC_PMC6_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC6:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC6_tag;

typedef union DDR_DDRC_PMLCA7_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA7_tag;

typedef union DDR_DDRC_PMLCB7_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB7_tag;

typedef union DDR_DDRC_PMC7_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC7:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC7_tag;

typedef union DDR_DDRC_PMLCA8_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA8_tag;

typedef union DDR_DDRC_PMLCB8_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB8_tag;

typedef union DDR_DDRC_PMC8_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC8:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC8_tag;

typedef union DDR_DDRC_PMLCA9_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA9_tag;

typedef union DDR_DDRC_PMLCB9_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB9_tag;

typedef union DDR_DDRC_PMC9_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC9:32;                 /* Event Count */
  } B;
} DDR_DDRC_PMC9_tag;

typedef union DDR_DDRC_PMLCA10_union_tag { /* Performance Monitor Local Control A */
  volatile uint32 R;
  struct {
    volatile uint32 BDIST:6;                 /* Burst Distance */
    volatile uint32 BGRAN:5;                 /* Burst Granularity */
    volatile uint32 BSIZE:5;                 /* Burst Size */
    volatile uint32 EVENT:7;                 /* Event Selector */
    volatile uint32 _unused_6:3;
    volatile uint32 CE:1;                    /* Condition Enable */
    volatile uint32 _unused_1:4;
    volatile uint32 FC:1;                    /* Freeze Counter */
  } B;
} DDR_DDRC_PMLCA10_tag;

typedef union DDR_DDRC_PMLCB10_union_tag { /* Performance Monitor Local Control B */
  volatile uint32 R;
  struct {
    volatile uint32 THRESHOLD:6;             /* Threshold */
    volatile uint32 _unused_24:2;
    volatile uint32 TBMULT:3;                /* Threshold And Burstiness Multiplier */
    volatile uint32 _unused_16:5;
    volatile uint32 TRIGOFFCNTL:2;           /* Trigger-Off Control */
    volatile uint32 TRIGONCNTL:2;            /* Trigger-On Control */
    volatile uint32 TRIGOFFSEL:4;            /* Trigger-Off Select */
    volatile uint32 _unused_6:2;
    volatile uint32 TRIGONSEL:4;             /* Trigger-On Select */
    volatile uint32 _unused_0:2;
  } B;
} DDR_DDRC_PMLCB10_tag;

typedef union DDR_DDRC_PMC10_union_tag { /* Performance Monitor Counter */
  volatile uint32 R;
  struct {
    volatile uint32 PMC10:32;                /* Event Count */
  } B;
} DDR_DDRC_PMC10_tag;

struct DDR_DDRC_tag {
  DDR_DDRC_CS_BNDS_tag CS_BNDS[2];
  DDR_DDRC_REMAP_EXT_0_tag REMAP_EXT_0; /* Remap Extended Region 0 Configuration */
  DDR_DDRC_REMAP_EXT_1_tag REMAP_EXT_1; /* Remap Extended Region 1 Configuration */
  DDR_DDRC_REMAP_EXT_2_tag REMAP_EXT_2; /* Remap Extended Region 2 Configuration */
  DDR_DDRC_REMAP_EXT_3_tag REMAP_EXT_3; /* Remap Extended Region 3 Configuration */
  DDR_DDRC_REMAP_0A_tag REMAP_0A;      /* Remap Region 0A Configuration */
  DDR_DDRC_REMAP_0B_tag REMAP_0B;      /* Remap Region 0B Configuration */
  DDR_DDRC_REMAP_1A_tag REMAP_1A;      /* Remap Region 1A Configuration */
  DDR_DDRC_REMAP_1B_tag REMAP_1B;      /* Remap Region 1B Configuration */
  DDR_DDRC_REMAP_2A_tag REMAP_2A;      /* Remap Region 2A Configuration */
  DDR_DDRC_REMAP_2B_tag REMAP_2B;      /* Remap Region 2B Configuration */
  DDR_DDRC_REMAP_3A_tag REMAP_3A;      /* Remap Region 3A Configuration */
  DDR_DDRC_REMAP_3B_tag REMAP_3B;      /* Remap Region 3B Configuration */
  DDR_DDRC_DDR_ADDR_DEC_0_tag DDR_ADDR_DEC_0; /* DDRC Address Decode 0 */
  DDR_DDRC_DDR_ADDR_DEC_1_tag DDR_ADDR_DEC_1; /* DDRC Address Decode 1 */
  DDR_DDRC_DDR_ADDR_DEC_2_tag DDR_ADDR_DEC_2; /* DDRC Address Decode 2 */
  DDR_DDRC_DDR_ADDR_DEC_3_tag DDR_ADDR_DEC_3; /* DDRC Address Decode 3 */
  DDR_DDRC_DDR_ADDR_DEC_4_tag DDR_ADDR_DEC_4; /* DDRC Address Decode 4 */
  DDR_DDRC_DDR_ADDR_DEC_5_tag DDR_ADDR_DEC_5; /* DDRC Address Decode 5 */
  DDR_DDRC_DDR_ADDR_DEC_6_tag DDR_ADDR_DEC_6; /* DDRC Address Decode 6 */
  DDR_DDRC_DDR_ADDR_DEC_7_tag DDR_ADDR_DEC_7; /* DDRC Address Decode 7 */
  DDR_DDRC_DDR_ADDR_DEC_8_tag DDR_ADDR_DEC_8; /* DDRC Address Decode 8 */
  DDR_DDRC_DDR_ADDR_DEC_9_tag DDR_ADDR_DEC_9; /* DDRC Address Decode 9 */
  uint8 DDR_DDRC_reserved0[24];
  DDR_DDRC_CS_CONFIG_tag CS_CONFIG[2]; /* Rank 0 Configuration */
  uint8 DDR_DDRC_reserved1[120];
  DDR_DDRC_TIMING_CFG_3_tag TIMING_CFG_3; /* DDR SDRAM Timing Configuration 3 */
  DDR_DDRC_TIMING_CFG_0_tag TIMING_CFG_0; /* DDR SDRAM Timing Configuration 0 */
  DDR_DDRC_TIMING_CFG_1_tag TIMING_CFG_1; /* DDR SDRAM Timing Configuration 1 */
  DDR_DDRC_TIMING_CFG_2_tag TIMING_CFG_2; /* DDR SDRAM Timing Configuration 2 */
  DDR_DDRC_DDR_SDRAM_CFG_tag DDR_SDRAM_CFG; /* DDR SDRAM Control Configuration */
  DDR_DDRC_DDR_SDRAM_CFG_2_tag DDR_SDRAM_CFG_2; /* DDR SDRAM Control Configuration 2 */
  uint8 DDR_DDRC_reserved2[8];
  DDR_DDRC_DDR_SDRAM_MD_CNTL_tag DDR_SDRAM_MD_CNTL; /* DDR SDRAM Mode Control */
  DDR_DDRC_DDR_SDRAM_INTERVAL_tag DDR_SDRAM_INTERVAL; /* DDR SDRAM Interval Configuration */
  DDR_DDRC_DDR_DATA_INIT_tag DDR_DATA_INIT; /* DDR SDRAM Data Initialization */
  uint8 DDR_DDRC_reserved3[52];
  DDR_DDRC_TIMING_CFG_4_tag TIMING_CFG_4; /* DDR SDRAM Timing Configuration 4 */
  DDR_DDRC_TIMING_CFG_5_tag TIMING_CFG_5; /* DDR SDRAM Timing Configuration 5 */
  uint8 DDR_DDRC_reserved4[4];
  DDR_DDRC_TIMING_CFG_7_tag TIMING_CFG_7; /* DDR SDRAM Timing Configuration 7 */
  DDR_DDRC_DDR_ZQ_CNTL_tag DDR_ZQ_CNTL; /* DDR SDRAM ZQ Calibration Control */
  uint8 DDR_DDRC_reserved5[8];
  DDR_DDRC_DDR_SR_CNTR_tag DDR_SR_CNTR; /* DDR SDRAM Self-Refresh Counter */
  uint8 DDR_DDRC_reserved6[208];
  DDR_DDRC_TIMING_CFG_8_tag TIMING_CFG_8; /* DDR SDRAM Timing Configuration 8 */
  DDR_DDRC_TIMING_CFG_9_tag TIMING_CFG_9; /* DDR SDRAM timing configuration 9 */
  DDR_DDRC_TIMING_CFG_10_tag TIMING_CFG_10; /* DDR SDRAM Timing Configuration 10 */
  DDR_DDRC_TIMING_CFG_11_tag TIMING_CFG_11; /* DDR SDRAM Timing Configuration 11 */
  DDR_DDRC_DDR_SDRAM_CFG_3_tag DDR_SDRAM_CFG_3; /* DDR SDRAM Control Configuration 3 */
  DDR_DDRC_DDR_SDRAM_CFG_4_tag DDR_SDRAM_CFG_4; /* DDR SDRAM Control Configuration 4 */
  DDR_DDRC_DDR_SDRAM_CFG_5_tag DDR_SDRAM_CFG_5; /* DDR SDRAM Control Configuration 5 */
  DDR_DDRC_DDR_SDRAM_CFG_6_tag DDR_SDRAM_CFG_6; /* DDR SDRAM Control Configuration 6 */
  DDR_DDRC_DDR_SDRAM_MD_CNTL2_tag DDR_SDRAM_MD_CNTL2; /* DDR SDRAM mode control 2 */
  uint8 DDR_DDRC_reserved7[4];
  DDR_DDRC_DDR_SDRAM_CFG_7_tag DDR_SDRAM_CFG_7; /* DDR SDRAM Control Configuration 7 */
  uint8 DDR_DDRC_reserved8[4];
  DDR_DDRC_DDR_SDRAM_MPR1_tag DDR_SDRAM_MPR1; /* DDR SDRAM multi-purpose register 1 */
  DDR_DDRC_DDR_SDRAM_MPR2_tag DDR_SDRAM_MPR2; /* DDR SDRAM multi-purpose register 2 */
  DDR_DDRC_DDR_SDRAM_MPR3_tag DDR_SDRAM_MPR3; /* DDR SDRAM multi-purpose register 3 */
  DDR_DDRC_DDR_SDRAM_MPR4_tag DDR_SDRAM_MPR4; /* DDR SDRAM multi-purpose register 4 */
  DDR_DDRC_DDR_SDRAM_MPR5_tag DDR_SDRAM_MPR5; /* DDR SDRAM multi-purpose register 5 */
  uint8 DDR_DDRC_reserved9[44];
  DDR_DDRC_DDR_SDRAM_REF_RATE_tag DDR_SDRAM_REF_RATE; /* DDR Refresh Rate */
  uint8 DDR_DDRC_reserved10[60];
  DDR_DDRC_TIMING_CFG_12_tag TIMING_CFG_12; /* DDR SDRAM Timing Configuration 12 */
  DDR_DDRC_TIMING_CFG_13_tag TIMING_CFG_13; /* DDR SDRAM Timing Configuration 13 */
  DDR_DDRC_TIMING_CFG_14_tag TIMING_CFG_14; /* DDR SDRAM Timing Configuration 14 */
  DDR_DDRC_TIMING_CFG_15_tag TIMING_CFG_15; /* DDR SDRAM Timing Configuration 15 */
  DDR_DDRC_TIMING_CFG_16_tag TIMING_CFG_16; /* DDR SDRAM Timing Configuration 16 */
  DDR_DDRC_TIMING_CFG_17_tag TIMING_CFG_17; /* DDR SDRAM Timing Configuration 17 */
  uint8 DDR_DDRC_reserved11[1256];
  DDR_DDRC_TX_CFG_1_tag TX_CFG_1;      /* Transaction Configuration Register 1 */
  DDR_DDRC_TX_CFG_2_tag TX_CFG_2;      /* Transaction Configuration Register 2 */
  DDR_DDRC_TX_CFG_3_tag TX_CFG_3;      /* Transaction Configuration Register 3. */
  DDR_DDRC_TX_CFG_4_tag TX_CFG_4;      /* Transaction Configuration Register 4. */
  DDR_DDRC_TX_CFG_5_tag TX_CFG_5;      /* Transaction Configuration Register 5. */
  uint8 DDR_DDRC_reserved12[784];
  DDR_DDRC_DDRDSR_2_tag DDRDSR_2;      /* DDR SDRAM Debug Status 2 */
  uint8 DDR_DDRC_reserved13[208];
  DDR_DDRC_DDR_IP_REV1_tag DDR_IP_REV1; /* DDRC Revision 1 */
  DDR_DDRC_DDR_IP_REV2_tag DDR_IP_REV2; /* DDRC Revision 2 */
  DDR_DDRC_DDR_EOR_tag DDR_EOR;        /* DDR Enhanced Optimization Register */
  uint8 DDR_DDRC_reserved14[252];
  DDR_DDRC_DDR_MTCR_tag DDR_MTCR;      /* DDR SDRAM Memory Test Control */
  uint8 DDR_DDRC_reserved15[28];
  DDR_DDRC_DDR_MTP_tag DDR_MTP[10];    /* DDR SDRAM Memory Test Pattern n */
  uint8 DDR_DDRC_reserved16[24];
  DDR_DDRC_DDR_MT_ST_EXT_ADDR_tag DDR_MT_ST_EXT_ADDR; /* DDR SDRAM Memory Test Start Extended Address */
  DDR_DDRC_DDR_MT_ST_ADDR_tag DDR_MT_ST_ADDR; /* DDR SDRAM Memory Test Start Address */
  DDR_DDRC_DDR_MT_END_EXT_ADDR_tag DDR_MT_END_EXT_ADDR; /* DDR SDRAM Memory Test End Extended Address */
  DDR_DDRC_DDR_MT_END_ADDR_tag DDR_MT_END_ADDR; /* DDR SDRAM Memory Test End Address */
  DDR_DDRC_DDR_MT_ST_EXT_ADDR2_tag DDR_MT_ST_EXT_ADDR2; /* DDR Memory Test Start Extended Address 2 */
  DDR_DDRC_DDR_MT_ST_ADDR2_tag DDR_MT_ST_ADDR2; /* DDR Memory Test Start Address 2 */
  DDR_DDRC_DDR_MT_END_EXT_ADDR2_tag DDR_MT_END_EXT_ADDR2; /* DDR Memory Test End Extended Address 2 */
  DDR_DDRC_DDR_MT_END_ADDR2_tag DDR_MT_END_ADDR2; /* DDR Memory Test End Address 2 */
  uint8 DDR_DDRC_reserved17[384];
  DDR_DDRC_DEBUG_1_tag DEBUG_1;        /* Debug 1 */
  DDR_DDRC_DEBUG_2_tag DEBUG_2;        /* Debug 2 */
  uint8 DDR_DDRC_reserved18[4];
  DDR_DDRC_DEBUG_4_tag DEBUG_4;        /* Debug 4 */
  uint8 DDR_DDRC_reserved19[56];
  DDR_DDRC_DEBUG_19_tag DEBUG_19;      /* Debug 19 */
  DDR_DDRC_DEBUG_20_tag DEBUG_20;      /* Debug 20 */
  uint8 DDR_DDRC_reserved20[20];
  DDR_DDRC_DEBUG_26_tag DEBUG_26;      /* Debug 26 */
  DDR_DDRC_DEBUG_27_tag DEBUG_27;      /* Debug 27 */
  DDR_DDRC_DEBUG_28_tag DEBUG_28;      /* Debug 28 */
  uint8 DDR_DDRC_reserved21[144];
  DDR_DDRC_ERR_EN_tag ERR_EN;          /* Error Enable */
  uint8 DDR_DDRC_reserved22[252];
  DDR_DDRC_DATA_ERR_INJECT_HI_tag DATA_ERR_INJECT_HI; /* Memory Data Path Error Injection Mask High */
  DDR_DDRC_DATA_ERR_INJECT_LO_tag DATA_ERR_INJECT_LO; /* Memory Data Path Error Injection Mask Low */
  DDR_DDRC_ERR_INJECT_tag ERR_INJECT;  /* Memory Data Path Error Injection Mask ECC */
  DDR_DDRC_ADDR_ERR_INJ_tag ADDR_ERR_INJ; /* Address Error Inject */
  DDR_DDRC_EXT_ADDR_ERR_INJ_tag EXT_ADDR_ERR_INJ; /* Extended Address Error Inject */
  uint8 DDR_DDRC_reserved23[4];
  DDR_DDRC_CAPTURE_EXT_DATA_HI_tag CAPTURE_EXT_DATA_HI; /* Memory Extended Data Path Read Capture High */
  DDR_DDRC_CAPTURE_EXT_DATA_LO_tag CAPTURE_EXT_DATA_LO; /* Memory Extended Data Path Read Capture Low */
  DDR_DDRC_CAPTURE_DATA_HI_tag CAPTURE_DATA_HI; /* Memory Data Path Read Capture High */
  DDR_DDRC_CAPTURE_DATA_LO_tag CAPTURE_DATA_LO; /* Memory Data Path Read Capture Low */
  DDR_DDRC_CAPTURE_ECC_tag CAPTURE_ECC; /* Memory Data Path Read Capture ECC */
  uint8 DDR_DDRC_reserved24[4];
  DDR_DDRC_CAPTURE_UPPER_EXT_DATA_HI_tag CAPTURE_UPPER_EXT_DATA_HI; /* Memory Upper Extended Data Path Read Capture High */
  DDR_DDRC_CAPTURE_UPPER_EXT_DATA_LO_tag CAPTURE_UPPER_EXT_DATA_LO; /* Memory Upper Extended Data Path Read Capture Low */
  DDR_DDRC_CAPTURE_UPPER_DATA_HI_tag CAPTURE_UPPER_DATA_HI; /* Memory Upper Data Path Read Capture High */
  DDR_DDRC_CAPTURE_UPPER_DATA_LO_tag CAPTURE_UPPER_DATA_LO; /* Memory Upper Data Path Read Capture Low */
  DDR_DDRC_ERR_DETECT_tag ERR_DETECT;  /* Memory Error Detect */
  DDR_DDRC_ERR_DISABLE_tag ERR_DISABLE; /* Memory Error Disable */
  DDR_DDRC_ERR_INT_EN_tag ERR_INT_EN;  /* Memory Error Interrupt Enable */
  DDR_DDRC_CAPTURE_ATTRIBUTES_tag CAPTURE_ATTRIBUTES; /* Memory Error Attributes Capture */
  DDR_DDRC_CAPTURE_ADDRESS_tag CAPTURE_ADDRESS; /* Memory Error Address Capture */
  DDR_DDRC_CAPTURE_EXT_ADDRESS_tag CAPTURE_EXT_ADDRESS; /* Memory Error Extended Address Capture */
  DDR_DDRC_ERR_SBE_tag ERR_SBE;        /* Single-Bit ECC Memory Error Management */
  uint8 DDR_DDRC_reserved25[180];
  DDR_DDRC_REG_CRC_GRP_1_tag REG_CRC_GRP_1; /* Register CRC Code For Group 1 */
  DDR_DDRC_REG_CRC_GRP_2_tag REG_CRC_GRP_2; /* Register CRC Code For Group 2 */
  uint8 DDR_DDRC_reserved26[8];
  DDR_DDRC_ECC_EXT_REG_0_tag ECC_EXT_REG_0; /* ECC Extended Region 0 Configuration */
  DDR_DDRC_ECC_EXT_REG_1_tag ECC_EXT_REG_1; /* ECC Extended Region 1 Configuration */
  DDR_DDRC_ECC_EXT_REG_2_tag ECC_EXT_REG_2; /* ECC Extended Region 2 Configuration */
  DDR_DDRC_ECC_EXT_REG_3_tag ECC_EXT_REG_3; /* ECC Extended Region 3 Configuration */
  DDR_DDRC_ECC_EXT_REG_4_tag ECC_EXT_REG_4; /* ECC Extended Region 4 Configuration */
  DDR_DDRC_ECC_EXT_REG_5_tag ECC_EXT_REG_5; /* ECC Extended Region 5 Configuration */
  DDR_DDRC_ECC_EXT_REG_6_tag ECC_EXT_REG_6; /* ECC Extended Region 6 Configuration */
  DDR_DDRC_ECC_EXT_REG_7_tag ECC_EXT_REG_7; /* ECC Extended Region 7 Configuration */
  DDR_DDRC_ECC_REG_0_tag ECC_REG_0;    /* ECC Region 0 Configuration */
  DDR_DDRC_ECC_REG_1_tag ECC_REG_1;    /* ECC Region 1 Configuration */
  DDR_DDRC_ECC_REG_2_tag ECC_REG_2;    /* ECC Region 2 Configuration */
  DDR_DDRC_ECC_REG_3_tag ECC_REG_3;    /* ECC Region 3 Configuration */
  DDR_DDRC_ECC_REG_4_tag ECC_REG_4;    /* ECC Region 4 Configuration */
  DDR_DDRC_ECC_REG_5_tag ECC_REG_5;    /* ECC Region 5 Configuration */
  DDR_DDRC_ECC_REG_6_tag ECC_REG_6;    /* ECC Region 6 Configuration */
  DDR_DDRC_ECC_REG_7_tag ECC_REG_7;    /* ECC Region 7 Configuration */
  uint8 DDR_DDRC_reserved27[64352];
  DDR_DDRC_PMCFG_1_tag PMCFG_1;        /* Performance Monitor Configuration 1 */
  DDR_DDRC_PMCFG_2_tag PMCFG_2;        /* Performance Monitor Configuration 2 */
  DDR_DDRC_PMCFG_3_tag PMCFG_3;        /* Performance Monitor Configuration 3 */
  DDR_DDRC_PMCFG_4_tag PMCFG_4;        /* Performance Monitor Configuration 4 */
  DDR_DDRC_PMCFG_5_tag PMCFG_5;        /* Performance Monitor Configuration 5 */
  DDR_DDRC_PMCFG_6_tag PMCFG_6;        /* Performance Monitor Configuration 6 */
  uint8 DDR_DDRC_reserved28[40];
  DDR_DDRC_PMGC0_tag PMGC0;            /* Performance Monitor Global Control */
  uint8 DDR_DDRC_reserved29[12];
  DDR_DDRC_PMLCA0_tag PMLCA0;          /* Performance Monitor Local Control A0 */
  DDR_DDRC_PMLCB0_tag PMLCB0;          /* Performance Monitor Local Control B0 */
  DDR_DDRC_PMC0A_tag PMC0A;            /* PMC 0a */
  DDR_DDRC_PMC0B_tag PMC0B;            /* PMC 0b */
  DDR_DDRC_PMLCA1_tag PMLCA1;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB1_tag PMLCB1;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC1_tag PMC1;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved30[4];
  DDR_DDRC_PMLCA2_tag PMLCA2;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB2_tag PMLCB2;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC2_tag PMC2;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved31[4];
  DDR_DDRC_PMLCA3_tag PMLCA3;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB3_tag PMLCB3;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC3_tag PMC3;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved32[4];
  DDR_DDRC_PMLCA4_tag PMLCA4;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB4_tag PMLCB4;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC4_tag PMC4;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved33[4];
  DDR_DDRC_PMLCA5_tag PMLCA5;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB5_tag PMLCB5;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC5_tag PMC5;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved34[4];
  DDR_DDRC_PMLCA6_tag PMLCA6;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB6_tag PMLCB6;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC6_tag PMC6;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved35[4];
  DDR_DDRC_PMLCA7_tag PMLCA7;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB7_tag PMLCB7;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC7_tag PMC7;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved36[4];
  DDR_DDRC_PMLCA8_tag PMLCA8;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB8_tag PMLCB8;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC8_tag PMC8;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved37[4];
  DDR_DDRC_PMLCA9_tag PMLCA9;          /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB9_tag PMLCB9;          /* Performance Monitor Local Control B */
  DDR_DDRC_PMC9_tag PMC9;              /* Performance Monitor Counter */
  uint8 DDR_DDRC_reserved38[4];
  DDR_DDRC_PMLCA10_tag PMLCA10;        /* Performance Monitor Local Control A */
  DDR_DDRC_PMLCB10_tag PMLCB10;        /* Performance Monitor Local Control B */
  DDR_DDRC_PMC10_tag PMC10;            /* Performance Monitor Counter */
};

/* MCM */
#define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM (*(volatile struct CACHE_ECC_MCM_tag *) 0x44401000UL)
#define M7__A7_APB_MCM1 (*(volatile struct M7_A7_APB_MCM_tag *) 0x4A0A0000UL)

/* DDRC */
#define DDRC (*(volatile struct DDR_DDRC_tag *) 0x4E080000UL)

/* ERM */
#define AON_ERMA (*(volatile struct ERM_tag *) 0x44560000UL)
#define WAKEUP_ERMW (*(volatile struct ERM_tag *) 0x423B0000UL)
#define NPU_ERM_NPUMIX (*(volatile struct ERM_tag *) 0x4A870000UL)
#define NETC_ERM (*(volatile struct ERM_tag *) 0x4D060000UL)

/* VFCCU */
#define AON_VFCCU (*(volatile struct SAFETYBASE_VFCCU_tag *) 0x44570000UL)

/* SRAMCTL */
#define OCRAM_BASE_ADDR (0x20480000UL)
#define OCRAM_SIZE (0x00060000UL)
#define NOC_SRAMCTL (*(volatile struct SRAMCTL_tag *) 0x490A0000UL)

/* EIM */
#define AON_EIMA (*(volatile struct EIM_tag *) 0x44550000UL)
#define WAKEUP_EIMW (*(volatile struct EIM_tag *) 0x423A0000UL)
#define NOC_EIMN (*(volatile struct EIM_tag *) 0x49270000UL)
#define M7_EIM (*(volatile struct EIM_tag *) 0x4A060000UL)
#define NPU_EIM_NPUMIX (*(volatile struct EIM_tag *) 0x4A860000UL)

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __MWERKS__
#pragma pop
#endif
#ifdef __ghs__
#pragma ghs endnowarning
#endif
#ifdef __GNUC__
#pragma GCC diagnostic pop
#pragma pack(pop)
#endif
#ifdef  __cplusplus
}
#endif
#endif /* ifdef _SafetyBase_MIMX952X_SAF_H_ */
