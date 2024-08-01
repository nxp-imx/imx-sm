/*
 * Copyright 2023-2024 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */

#include "sm.h"
#include "fsl_ele.h"
#include "fsl_mu.h"
#include "crc.h"

/* Local Defines */

#define ELE_STAT(X)          ((X) & 0x000000FFUL)
#define ELE_ID(X)            ((X) & 0x00FFFFFFUL)
#define ELE_VER(X)           ((X) & 0x7FFFFFFFUL)
#define ELE_DIRTY_VER(X)     (((X) >> 31) & 0x1UL)

#define ELE_MSG_VER             0x06U
#define ELE_MSG_TAG             0x17U
#define ELE_MSG_TAG_RESP        0xE1U
#define ELE_MSG_MIN_SIZE        3U
#define ELE_MSG_MAX_SIZE        23U

/* Local Types */

typedef enum
{
    ELE_PING_REQ                = 0x01,
    ELE_FW_AUTH_REQ             = 0x02,
    ELE_RESTART_RST_TIMER_REQ   = 0x04,
    ELE_DUMP_DEBUG_BUFFER_REQ   = 0x21,
    ELE_OEM_CNTN_AUTH_REQ       = 0x87,
    ELE_VERIFY_IMAGE_REQ        = 0x88,
    ELE_RELEASE_CONTAINER_REQ   = 0x89,
    ELE_WRITE_SECURE_FUSE_REQ   = 0x91,
    ELE_FWD_LIFECYCLE_UP_REQ    = 0x95,
    ELE_READ_FUSE_REQ           = 0x97,
    ELE_GET_FW_VERSION_REQ      = 0x9D,
    ELE_RET_LIFECYCLE_UP_REQ    = 0xA0,
    ELE_GET_EVENTS_REQ          = 0xA2,
    ELE_START_RNG_REQ           = 0xA3,
    ELE_GET_TRNG_STATE_REQ      = 0xA4,
    ELE_ENABLE_PATCH_REQ        = 0xC3,
    ELE_RELEASE_RDC_REQ         = 0xC4,
    ELE_GET_FW_STATUS_REQ       = 0xC5,
    ELE_ENABLE_OTFAD_REQ        = 0xC6,
    ELE_RESET_REQ               = 0xC7,
    ELE_UPDATE_OTP_CLKDIV_REQ   = 0xD0,
    ELE_POWER_DOWN_REQ          = 0xD1,
    ELE_ENABLE_APC_REQ          = 0xD2,
    ELE_ENABLE_RTC_REQ          = 0xD3,
    ELE_ENABLE_AUX_REQ          = 0xD4,
    ELE_STOP_RST_TIMER_REQ      = 0xD5,
    ELE_WRITE_FUSE_REQ          = 0xD6,
    ELE_RELEASE_CAAM_REQ        = 0xD7,
    ELE_RESET_A35_CTX_REQ       = 0xD8,
    ELE_MOVE_TO_UNSECURED_REQ   = 0xD9,
    ELE_GET_INFO_REQ            = 0xDA,
    ELE_ATTEST_REQ              = 0xDB,
    ELE_RELEASE_PATCH_REQ       = 0xDC,
    ELE_OTP_SEQ_SWITH_REQ       = 0xDD,
    ELE_ABORT                   = 0xFF
} ele_cmd_type_t;

typedef struct
{
    uint8_t ver;
    uint8_t size;
    ele_cmd_type_t cmd;
    uint8_t tag;
} msg_hdr_t;

typedef struct
{
    ele_msg_status_t status;
    ele_msg_ind_t ind;
    uint16_t abortCode;
} ele_msg_resp_t;

typedef union
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
{
    msg_hdr_t hdr;
    uint32_t word[ELE_MSG_MAX_SIZE];
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
} ele_mu_msg_t;

typedef union
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
{
    msg_hdr_t hdr;
    uint32_t word[ELE_MSG_MIN_SIZE];
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
} ele_mu_min_t;

/* Local Functions */

static void ELE_Call(ele_mu_msg_t *msg, ele_cmd_type_t cmd,
    uint8_t size);
static void ELE_MuTx(ele_mu_msg_t *msg);
static void ELE_MuRx(ele_mu_msg_t *msg, uint8_t maxLen,
    ele_cmd_type_t cmd);
static void ELE_ErrXlate(int32_t *err, uint32_t resp);

/* Local Variables */

// coverity[misra_c_2012_rule_19_2_violation:FALSE]
static ele_mu_msg_t s_msgMax;
static bool s_aborted = false;
static uint32_t s_eleErrno = 0U;
static MU_Type *s_eleMuBase = NULL;

/* Global variable */

int32_t g_eleStatus = SM_ERR_SUCCESS;

/*--------------------------------------------------------------------------*/
/* Init ELE                                                                 */
/*--------------------------------------------------------------------------*/
void ELE_Init(MU_Type *base)
{
    s_eleMuBase = base;
}

/*--------------------------------------------------------------------------*/
/* Ping ELE                                                                 */
/*--------------------------------------------------------------------------*/
void ELE_Ping(void)
{
    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_PING_REQ, 1U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Release RDC to calling core                                              */
/*--------------------------------------------------------------------------*/
void ELE_RdcRelease(uint8_t rdcId)
{
    /* Fill in parameters */
    s_msgMax.word[1] = 1U;
    s_msgMax.word[1] |= ((uint32_t) rdcId) << 8U;

    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_RELEASE_RDC_REQ, 2U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Get ELE FW status                                                        */
/*--------------------------------------------------------------------------*/
void ELE_FwStatusGet(uint32_t *status)
{
    static uint32_t s_statWord2Cache = 0xFFFFFFFFUL;

    /* Check if status cached? */
    if (s_statWord2Cache == 0xFFFFFFFFUL)
    {
        /* Call ELE */
        ELE_Call(&s_msgMax, ELE_GET_FW_STATUS_REQ, 1U);

        s_statWord2Cache = s_msgMax.word[2];

        /* Translate error */
        ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
        ELE_DebugDump();
#endif
    }

    /* Return data */
    if (g_eleStatus == SM_ERR_SUCCESS)
    {
        *status = ELE_STAT(s_statWord2Cache);
    }
}

/*--------------------------------------------------------------------------*/
/* Get ELE ROM ID info                                                      */
/*--------------------------------------------------------------------------*/
void ELE_RomIdGet(uint32_t *id, uint32_t *commit, bool *dirty)
{
    static uint32_t s_idWord2Cache = 0U;
    static uint32_t s_idWord3Cache = 0U;

    g_eleStatus = SM_ERR_SUCCESS;

    /* Check if version cached? */
    if (s_idWord2Cache == 0U)
    {
        /* Call ELE */
        ELE_Call(&s_msgMax, ELE_GET_FW_VERSION_REQ, 1U);

        s_idWord2Cache = s_msgMax.word[2];
        s_idWord3Cache = s_msgMax.word[3];

        /* Translate error */
        ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
        ELE_DebugDump();
#endif
    }

    /* Return data */
    if (g_eleStatus == SM_ERR_SUCCESS)
    {
        *id = ELE_ID(s_idWord2Cache);
        *commit = s_idWord3Cache;
        *dirty = (ELE_DIRTY_VER(s_idWord2Cache) != 0U);
    }
}

/*--------------------------------------------------------------------------*/
/* Get ELE FW version info                                                  */
/*--------------------------------------------------------------------------*/
void ELE_FwVersionGet(uint32_t *version, uint32_t *commit, bool *dirty,
    bool *alt, bool *auth)
{
    static uint32_t s_verWord2Cache = 0U;
    static uint32_t s_verWord3Cache = 0U;

    g_eleStatus = SM_ERR_SUCCESS;

    /* Check if version cached? */
    if (s_verWord2Cache == 0U)
    {
        /* Call ELE */
        ELE_Call(&s_msgMax, ELE_GET_FW_VERSION_REQ, 1U);

        s_verWord2Cache = s_msgMax.word[2];
        s_verWord3Cache = s_msgMax.word[3];

        /* Translate error */
        ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
        ELE_DebugDump();
#endif
    }

    /* Return data */
    if (g_eleStatus == SM_ERR_SUCCESS)
    {
        *version = ELE_VER(s_verWord2Cache);
        *commit = s_verWord3Cache;
        *dirty = (ELE_DIRTY_VER(s_verWord2Cache) != 0U);
        *alt = (ELE_ALT_VER(s_verWord2Cache) != 0U);
        *auth = (ELE_AUTH_VER(s_verWord2Cache) != 0U);
    }
}

/*--------------------------------------------------------------------------*/
/* Get ELE events                                                           */
/*--------------------------------------------------------------------------*/
uint32_t ELE_EventGet(uint8_t idx)
{
    int32_t status = SM_ERR_SUCCESS;
    // coverity[misra_c_2012_rule_19_2_violation:FALSE]
    static ele_mu_msg_t s_msgEnv;
    static uint32_t s_numEvents = 0U;
    uint32_t event;

    /* Request events if index is 0 */
    if (idx == 0U)
    {
        /* Call ELE */
        ELE_Call(&s_msgEnv, ELE_GET_EVENTS_REQ, 1U);

        /* Translate error */
        ELE_ErrXlate(&g_eleStatus, s_msgEnv.word[1]);
        status = g_eleStatus;

        /* Extract results */
        if (status == SM_ERR_SUCCESS)
        {
            uint16_t event_max = ((uint16_t) ((s_msgEnv.word[2] >> 16U)
                & 0xFFFFU));
            uint16_t events = ((uint16_t) (s_msgEnv.word[2] & 0xFFFFU));

            s_numEvents = MIN(events, event_max);
            s_numEvents = MIN(s_numEvents, ELE_MSG_MAX_SIZE - 3U);
        }
        else
        {
            s_numEvents = 0U;
        }
    }

    /* Check parms */
    if (idx >= s_numEvents)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check error */
    if (status == SM_ERR_SUCCESS)
    {
        event = s_msgEnv.word[idx + 3U];
    }
    else
    {
        event = 0U;
    }

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif

    g_eleStatus = status;

    return event;
}

/*--------------------------------------------------------------------------*/
/* Get ELE info                                                             */
/*--------------------------------------------------------------------------*/
void ELE_InfoGet(ele_info_t *info)
{
    const volatile uint32_t data[sizeof(ele_info_t) / sizeof(uint32_t)];

    /* Fill in parameters */
    s_msgMax.word[1] = 0U;
    s_msgMax.word[2] = (uint32_t) &data;
    s_msgMax.word[3] = sizeof(data);

    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_GET_INFO_REQ, 4U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

    /* Extract data */
    if (g_eleStatus == SM_ERR_SUCCESS)
    {
        info->socId = (uint16_t) (data[1] & 0x0000FFFFU);
        info->socRev = (uint16_t) ((data[1] >> 16U) & 0x0000FFFFU);
        info->lifecycle = (uint16_t) (data[2] & 0x0000FFFFU);
        info->sssmState = (uint8_t) ((data[2] >> 16U) & 0x000000FFU);
        info->attestApiVer = (uint8_t) ((data[2] >> 24U) & 0x000000FFU);
        info->trngState = (uint8_t) (data[39] & 0x000000FFU);
        info->csalState = (uint8_t) ((data[39] >> 8U) & 0x000000FFU);
        info->imemState = (uint8_t) ((data[39] >> 16U) & 0x000000FFU);

        for (uint32_t idx = 0U; idx < 4U; idx++)
        {
            info->uid[idx] = data[idx + 3U];
        }

        for (uint32_t idx = 0U; idx < 8U; idx++)
        {
            info->shaPatch[idx] = data[idx + 7U];
        }

        for (uint32_t idx = 0U; idx < 8U; idx++)
        {
            info->shaFw[idx] = data[idx + 15U];
        }
    }

    /* Append error if data not correct */
    if ((data[0] & 0xFFUL) != ((uint32_t) ELE_GET_INFO_REQ))
    {
        g_eleStatus = SM_ERR_NOT_SUPPORTED;
    }

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Dump debug log                                                           */
/*--------------------------------------------------------------------------*/
void ELE_DebugDump(void)
{
#ifdef MONITOR
    uint8_t cnt = 0U;

    int32_t copyEleErr = g_eleStatus;

    do
    {
        uint8_t idx;

        /* Call ELE */
        ELE_Call(&s_msgMax, ELE_DUMP_DEBUG_BUFFER_REQ, 1U);

        /* Check if data to dump */
        if (g_eleStatus == SM_ERR_SUCCESS)
        {
            cnt = s_msgMax.hdr.size - 1U;
        }
        else
        {
            cnt = 0U;
        }

        /* Display data */
        for (idx = 0U; idx < (cnt / 2U); idx++)
        {
            printf("ELE: %u 0x%08X\n", s_msgMax.word[(idx * 2U) + 2U],
                s_msgMax.word[(idx * 2U) + 1U]);
        }
    }
    while (cnt >= 20U);

    g_eleStatus = copyEleErr;
#endif
}

/*--------------------------------------------------------------------------*/
/* Release APC                                                              */
/*--------------------------------------------------------------------------*/
void ELE_EnableApcRequest(void)
{
    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_ENABLE_APC_REQ, 1U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Release AUX                                                              */
/*--------------------------------------------------------------------------*/
void ELE_EnableAuxRequest(uint32_t core)
{
    /* Fill in parameters */
    s_msgMax.word[1] = core;

    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_ENABLE_AUX_REQ, 2U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Read fuse                                                                */
/*--------------------------------------------------------------------------*/
void ELE_FuseRead(uint32_t fuseId, uint32_t *fuseVal)
{
    /* Fill in parameters */
    s_msgMax.word[1] = fuseId;

    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_READ_FUSE_REQ, 2U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

    /* Extract data */
    if (g_eleStatus == SM_ERR_SUCCESS)
    {
        *fuseVal = s_msgMax.word[2];
    }

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Write fuse                                                               */
/*--------------------------------------------------------------------------*/
void ELE_FuseWrite(uint32_t fuseId, uint32_t fuseVal, bool lock)
{
    /* Fill in parameters */
    s_msgMax.word[1] = (fuseId * 32UL) & 0xFFFFU;
    s_msgMax.word[1] |= (32UL << 16);
    if (lock)
    {
        s_msgMax.word[1] |= BIT32(31U);
    }
    s_msgMax.word[2] = fuseVal;

    /* Call ELE */
    ELE_Call(&s_msgMax, ELE_WRITE_FUSE_REQ, 3U);

    /* Translate error */
    ELE_ErrXlate(&g_eleStatus, s_msgMax.word[1]);

#ifdef DEBUG_ELE
    ELE_DebugDump();
#endif
}

/*--------------------------------------------------------------------------*/
/* Get ELE error number                                                     */
/*--------------------------------------------------------------------------*/
uint32_t ELE_ErrNumber(void)
{
    /* Return error number */
    return s_eleErrno;
}

/*--------------------------------------------------------------------------*/
/* Abort ELE                                                                */
/*--------------------------------------------------------------------------*/
void ELE_Abort(void)
{
    if (!s_aborted)
    {
        s_aborted = true;
    }
}

/*--------------------------------------------------------------------------*/
/* Is ELE aborted?                                                          */
/*--------------------------------------------------------------------------*/
bool ELE_IsAborted(void)
{
    return s_aborted;
}

/*--------------------------------------------------------------------------*/
/* Parse ELE response                                                       */
/*--------------------------------------------------------------------------*/
void ELE_RespParse(uint32_t resp, ele_msg_status_t *status,
    ele_msg_ind_t *ind, uint16_t *abortCode)
{
    const ele_msg_resp_t *r = (ele_msg_resp_t*) &resp;

    *status = r->status;
    *ind = r->ind;
    *abortCode = r->abortCode;
}

/*--------------------------------------------------------------------------*/
/* Parse ELE response                                                       */
/*--------------------------------------------------------------------------*/
int32_t ELE_Ind2Err(ele_msg_ind_t ind)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (ind)
    {
        /* No error */
        case ELE_ROM_PING_FAILURE_IND:
        case ELE_FW_PING_FAILURE_IND:
            status = SM_ERR_SUCCESS;
            break;

        /* Denied error */
        case ELE_INVALID_LIFECYCLE_IND:
        case ELE_PERMISSION_DENIED_FAILURE_IND:
        case ELE_OTP_LOCKED_FAILURE_IND:
        case ELE_LOCKED_REG_FAILURE_IND:
            status = SM_ERR_DENIED;
            break;

        /* Protocol error */
        case ELE_BAD_VERSION_FAILURE_IND:
        case ELE_OLD_VERSION_FAILURE_IND:
        case ELE_INVALID_MESSAGE_FAILURE_IND:
        case ELE_CRC_ERROR_IND:
        case ELE_INVALID_OPERATION_FAILURE_IND:
        case ELE_MSG_TRUNCATED_IND:
            status = SM_ERR_PROTOCOL_ERROR;
            break;

        /* Bad parameter */
        case ELE_BAD_HASH_FAILURE_IND:
        case ELE_BAD_VALUE_FAILURE_IND:
        case ELE_BAD_FUSE_ID_FAILURE_IND:
        case ELE_BAD_CONTAINER_FAILURE_IND:
        case ELE_BAD_KEY_HASH_FAILURE_IND:
        case ELE_NO_VALID_CONTAINER_FAILURE_IND:
        case ELE_MUST_SIGNED_FAILURE_IND:
        case ELE_UNALIGNED_PAYLOAD_FAILURE_IND:
        case ELE_WRONG_SIZE_FAILURE_IND:
        case ELE_OTP_INVALID_IDX_FAILURE_IND:
        case ELE_BAD_PAYLOAD_FAILURE_IND:
        case ELE_WRONG_ADDRESS_FAILURE_IND:
        case ELE_DMA_FAILURE_IND:
        case ELE_BAD_UID_FAILURE_IND:
        case ELE_INCONSISTENT_PAR_FAILURE_IND:
        case ELE_BAD_MONOTONIC_COUNTER_FAILURE_IND:
        case ELE_BAD_SRK_SET_FAILURE_IND:
        case ELE_BAD_ID_FAILURE_IND:
            status = SM_ERR_INVALID_PARAMETERS;
            break;

        /* Not supported */
        case ELE_OUT_OF_MEMORY_IND:
        case ELE_NON_SECURE_STATE_FAILURE_IND:
        case ELE_DISABLED_FEATURE_FAILURE_IND:
        case ELE_FASBOOT_DISABLED_FAILURE_IND:
            status = SM_ERR_NOT_SUPPORTED;
            break;

        /* Busy */
        case ELE_TIME_OUT_FAILURE_IND:
            status = SM_ERR_BUSY;
            break;

        /* Generic fail */
        case ELE_ENCRYPTION_FAILURE_IND:
        case ELE_DECRYPTION_FAILURE_IND:
        case ELE_BAD_CERTIFICATE_FAILURE_IND:
        case ELE_OTP_PROGFAIL_FAILURE_IND:
        case ELE_BAD_SIGNATURE_FAILURE_IND:
        case ELE_INVALID_KEY_FAILURE_IND:
        case ELE_MUST_ATTEST_FAILURE_IND:
        case ELE_RNG_NOT_STARTED_FAILURE_IND:
        case ELE_RNG_INST_FAILURE_FAILURE_IND:
        case ELE_NO_AUTHENTICATION_FAILURE_IND:
        case ELE_AUTH_SKIPPED_OR_FAILED_FAILURE_IND:
        case ELE_FASTBOOT_ILLEGAL_STATE_FAILURE_IND:
        case ELE_GENERIC_AUTH_FW_FAILURE_IND:
        case ELE_GENERIC_AUTH_OEM_FAILURE_IND:
        case ELE_FAST_IMAGE_VERIFY_FAILURE_IND:
        default:
            status = SM_ERR_GENERIC_ERROR;
            break;
    }

    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Call ELE function                                                        */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
static void ELE_Call(ele_mu_msg_t *msg, ele_cmd_type_t cmd, uint8_t size)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check for abort state */
    if (s_aborted)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Setup message */
        msg->hdr.tag = ELE_MSG_TAG;
        msg->hdr.cmd = cmd;
        msg->hdr.size = size;
        msg->hdr.ver = ELE_MSG_VER;

        /* Send message */
        ELE_MuTx(msg);

        /* Receive response */
        msg->word[1] = 0U;
        ELE_MuRx(msg, ELE_MSG_MAX_SIZE, cmd);

        /* Check response */
        if (msg->hdr.tag != ELE_MSG_TAG_RESP)
        {
            status = SM_ERR_PROTOCOL_ERROR;
        }
        else if ((msg->hdr.cmd != cmd) && (msg->hdr.cmd != ELE_ABORT))
        {
            status = SM_ERR_PROTOCOL_ERROR;
        }
        else if (msg->hdr.size == 0U)
        {
            status = SM_ERR_PROTOCOL_ERROR;
        }
        else if (msg->hdr.ver != ELE_MSG_VER)
        {
            status = SM_ERR_PROTOCOL_ERROR;
        }
        else
        {
            ; /* Intentional empty else */
        }
    }

    g_eleStatus = status;
}

/*--------------------------------------------------------------------------*/
/* Send MU message to ELE                                                   */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
static void ELE_MuTx(ele_mu_msg_t *msg)
{
    const uint32_t *buf = (const uint32_t*) msg;
    uint32_t size;
    uint32_t pos = 1U;

    /* Calculate CRC */
    if (msg->hdr.size > 4U)
    {
        msg->hdr.size++;
        s_msgMax.word[msg->hdr.size - 1U] = CRC_Xor(&msg->word[0],
            ((uint32_t)msg->hdr.size) - 1UL);
    }

    /* Send header and NMI */
    MU_SendMsg(s_eleMuBase, 0, buf[0]);

    /* Send message body */
    size = ((uint32_t) msg->hdr.size) - 1UL;
    while (size > 0U)
    {
        MU_SendMsg(s_eleMuBase, pos % 8UL, buf[pos]);

        pos++;
        size--;
    }
}

/*--------------------------------------------------------------------------*/
/* Receive MU message from ELE                                              */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
static void ELE_MuRx(ele_mu_msg_t *msg, uint8_t maxLen,
    ele_cmd_type_t cmd)
{
    uint32_t *buf = (uint32_t*) msg;

    /* Check if aborted */
    if ((!s_aborted)
        || (cmd == ELE_DUMP_DEBUG_BUFFER_REQ))
    {
        /* Get message header */
        buf[0] = MU_ReceiveMsg(s_eleMuBase, 0U);

        /* Check response */
        if ((msg->hdr.tag == ELE_MSG_TAG_RESP)
            && (msg->hdr.ver == ELE_MSG_VER))
        {
            uint8_t size;
            uint8_t pos = 1U;

            /* Get message size */
            size = MIN(msg->hdr.size - 1U, maxLen - 1U);

            /* Get message body */
            while (size > 0U)
            {
                buf[pos] = MU_ReceiveMsg(s_eleMuBase, ((uint32_t) pos)
                    % 8UL);

                pos++;
                size--;
            }
        }
    }
    else
    {
        /* Pretend was an MU abort response */
        msg->word[1] = 0U;
    }
}

/*--------------------------------------------------------------------------*/
/* Translate ELE error code                                                 */
/*--------------------------------------------------------------------------*/
static void ELE_ErrXlate(int32_t *err, uint32_t resp)
{
    int32_t rtn = SM_ERR_SUCCESS;
    ele_msg_status_t status;
    ele_msg_ind_t ind;
    uint16_t abortCode;

    ELE_RespParse(resp, &status, &ind, &abortCode);

    /* Check for comm error */
    if ((err != NULL) && (*err != SM_ERR_SUCCESS))
    {
        rtn = *err;
    }

    /* Check for abort */
    else if (abortCode != 0U)
    {
        if (!s_aborted)
        {
            s_aborted = true;
        }

        rtn = SM_ERR_GENERIC_ERROR;
    }

    /* Check for success */
    else if (status == ELE_SUCCESS_IND)
    {
        s_eleErrno = 0U;
    }

    /* ELE error */
    else
    {
        s_eleErrno = (uint32_t) ind;

        rtn = ELE_Ind2Err(ind);
    }

    if (err != NULL)
    {
        *err = rtn;
    }
}

