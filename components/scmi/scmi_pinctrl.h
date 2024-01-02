/*
** ###################################################################
**
** Copyright 2023-2024 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

#ifndef SCMI_PINCTRL_H
#define SCMI_PINCTRL_H

/*!
 * @addtogroup scmi_proto_pinctrl
 * @{
 */

/*!
 * @file
 * @brief Header file containing the client-side API for the System Control and
 * Management Interface (SCMI) pinctrl protocol.
 */

/* Defines */

/*!
 * @name SCMI pinctrl protocol message IDs
 */
/** @{ */
/*! Get pin attributes */
#define SCMI_MSG_PINCTRL_ATTRIBUTES       0x3U
/*! Get pin configuration */
#define SCMI_MSG_PINCTRL_CONFIG_GET       0x5U
/*! Set pin configuration */
#define SCMI_MSG_PINCTRL_CONFIG_SET       0x6U
/*! Select a function for a pin */
#define SCMI_MSG_PINCTRL_FUNCTION_SELECT  0x7U
/*! Request a pin */
#define SCMI_MSG_PINCTRL_REQUEST          0x8U
/*! Release a pin */
#define SCMI_MSG_PINCTRL_RELEASE          0x9U
/** @} */

/*!
 * @name SCMI max pin control argument lengths
 */
/** @{ */
/*! Max length of the returned pin name */
#define SCMI_PINCTRL_MAX_NAME       16U
/*! Max number of configs returned in one call */
#define SCMI_PINCTRL_MAX_CONFIGS    SCMI_ARRAY(8U, scmi_pin_config_t)
/*! Max number of configs sent in one call */
#define SCMI_PINCTRL_MAX_CONFIGS_T  SCMI_ARRAY(8U, scmi_pin_config_t)
/** @} */

/*!
 * @name SCMI actual pin control argument lengths
 */
/** @{ */
/*! Actual number of configs returned */
#define SCMI_PINCTRL_NUM_CONFIGS    SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(msgRx->numConfigs)
/*! Actual number of configs sent */
#define SCMI_PINCTRL_NUM_CONFIGS_T  (attributes >> 2)
/** @} */

/*!
 * @name SCMI pin control selectors
 */
/** @{ */
/*! Select pin */
#define SCMI_PINCTRL_SEL_PIN    0U
/*! Select group */
#define SCMI_PINCTRL_SEL_GROUP  1U
/** @} */

/*!
 * @name SCMI pin control types
 */
/** @{ */
/*! Mux type */
#define SCMI_PINCTRL_TYPE_MUX        192U
/*! Config type */
#define SCMI_PINCTRL_TYPE_CONFIG     193U
/*! Daisy ID type */
#define SCMI_PINCTRL_TYPE_DAISY_ID   194U
/*! Daisy config type */
#define SCMI_PINCTRL_TYPE_DAISY_CFG  195U
/** @} */

/* Macros */

/*!
 * @name SCMI pin control protocol attributes (low)
 */
/** @{ */
/*! Number of groups */
#define SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_GROUPS(x)  (((x) & 0xFFFF0000U) >> 16U)
/*! Number of pins */
#define SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_PINS(x)    (((x) & 0xFFFFU) >> 0U)
/** @} */

/*!
 * @name SCMI pin control protocol attributes (high)
 */
/** @{ */
/*! Number of functions */
#define SCMI_PINCTRL_PROTO_ATTR_HIGH_NUM_FUNCTIONS(x)  (((x) & 0xFFFFU) >> 0U)
/** @} */

/*!
 * @name SCMI pin control flags
 */
/** @{ */
/*! Selector */
#define SCMI_PINCTRL_FLAGS_SELECTOR(x)  (((x) & 0x3U) << 0U)
/** @} */

/*!
 * @name SCMI pin attributes
 */
/** @{ */
/*! Extended name */
#define SCMI_PINCTRL_ATTR_EXT_NAME(x)  (((x) & 0x80000000U) >> 31U)
/*! Number of pins or groups */
#define SCMI_PINCTRL_ATTR_NUM(x)       (((x) & 0xFFFFU) >> 0U)
/** @} */

/*!
 * @name SCMI pin control get attributes
 */
/** @{ */
/*! Get all configs */
#define SCMI_PINCTRL_GET_ATTR_GET_ALL(x)       (((x) & 0x1U) << 18U)
/*! Selector */
#define SCMI_PINCTRL_GET_ATTR_SELECTOR(x)      (((x) & 0x3U) << 16U)
/*! Skip Configs */
#define SCMI_PINCTRL_GET_ATTR_SKIP_CONFIGS(x)  (((x) & 0xFFU) << 8U)
/*! ConfigType */
#define SCMI_PINCTRL_GET_ATTR_CONFIG_TYPE(x)   (((x) & 0xFFU) << 0U)
/** @} */

/*!
 * @name SCMI pin control num config flags
 */
/** @{ */
/*! Number of remaining configurations */
#define SCMI_PINCTRL_NUM_CONFIG_FLAGS_REMAING_CONFIGS(x)  (((x) & 0xFF000000U) >> 24U)
/*! Number of configurations that are returned by this call */
#define SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(x)      (((x) & 0xFFU) >> 0U)
/** @} */

/*!
 * @name SCMI pin control set attributes
 */
/** @{ */
/*! Number of configurations to set */
#define SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(x)  (((x) & 0xFFU) << 2U)
/*! Selector */
#define SCMI_PINCTRL_SET_ATTR_SELECTOR(x)     (((x) & 0x3U) << 0U)
/** @} */

/* Types */

/*!
 * SCMI pin control config
 */
typedef struct
{
    /*! The type of config */
    uint32_t type;
    /*! The configuration value */
    uint32_t value;
} scmi_pin_config_t;

/* Functions */

/*!
 * Get protocol version.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[out]    version  Protocol version. For this revision of the
 *                         specification, this value must be 0x10000
 *
 * On success, this function returns the Protocol version. For this version of
 * the specification, the return value must be 0x10000, which corresponds to
 * version 1.0. See section 4.11.2.1 PROTOCOL_VERSION in the
 * [SCMI Spec](@ref DOCS).
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_PinctrlProtocolVersion(uint32_t channel, uint32_t *version);

/*!
 * Get protocol attributes.
 *
 * @param[in]     channel         A2P channel for comms
 * @param[out]    attributesLow   Low protocol attributes:<BR>
 *                                Bits[31:16] Number of pin groups.<BR>
 *                                Bits[15:0] Number of pins
 * @param[out]    attributesHigh  High protocol attributes:<BR>
 *                                Bits[31:16] Reserved, must be zero.<BR>
 *                                Bits[15:0] Number of functions
 *
 * This function returns the implementation details associated with this
 * protocol. See section 4.11.2.3 PROTOCOL_ATTRIBUTES in the
 * [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_GROUPS() - Number of groups
 * - ::SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_PINS() - Number of pins
 * - ::SCMI_PINCTRL_PROTO_ATTR_HIGH_NUM_FUNCTIONS() - Number of functions
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_PinctrlProtocolAttributes(uint32_t channel,
    uint32_t *attributesLow, uint32_t *attributesHigh);

/*!
 * Get protocol message attributes.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     messageId   Message ID of the message
 * @param[out]    attributes  Message attributes. Flags that are associated
 *                            with a specific function in the protocol.<BR>
 *                            In the current version of the specification, this
 *                            value is always 0
 *
 * On success, this function returns the implementation details associated with
 * a specific message in this protocol. An example message ID is
 * ::SCMI_MSG_PINCTRL_ATTRIBUTES. The max name length is
 * ::SCMI_PINCTRL_MAX_NAME. See section 4.11.2.4 PROTOCOL_MESSAGE_ATTRIBUTES in
 * the [SCMI Spec](@ref DOCS).
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: in case the message is implemented and available to
 *   use.
 * - ::SCMI_ERR_NOT_FOUND: if the message identified by \a messageId is
 *   invalid or not implemented.
 */
int32_t SCMI_PinctrlProtocolMessageAttributes(uint32_t channel,
    uint32_t messageId, uint32_t *attributes);

/*!
 * Get pin attributes.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin, group, or function
 * @param[in]     flags       Selector: Whether the identifier field selects a
 *                            pin, a group, or a function.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            2 - Function<BR>
 *                            All other values are reserved for future use
 * @param[out]    attributes  Pin attributes:<BR>
 *                            The attributes of the pin, group, or function
 *                            identified by the identifier field in combination
 *                            with Bits[1:0] of the flag field in the
 *                            function.<BR>
 *                            Bit[31] Extended name.<BR>
 *                            If set to 1, the name is greater than 16
 *                            bytes.<BR>
 *                            If set to 0, extended name is not supported.<BR>
 *                            Bits[30:16] Reserved, must be zero.<BR>
 *                            Bits[15:0] Number of pins or groups.<BR>
 *                            - Set to 0, if Bits[1:0] of flags field in the
 *                            function is set to 0.<BR>
 *                            - Set to the number of pins in the group, if
 *                            Bits[1:0] of flags field in the function is set
 *                            to 1.<BR>
 *                            - Set to the number of groups associated with the
 *                            function, if Bits[1:0]<BR>
 *                            Bit[30] Extended pin control name.<BR>
 *                            If set to 1, the pin control name is greater than
 *                            16 bytes.<BR>
 *                            If set to 0, extended pin control name is not
 *                            supported.<BR>
 *                            Bits[29:0] Reserved, must be zero
 * @param[out]    name        Null-terminated ASCII string of up to 16 bytes in
 *                            length describing the pin, group, or function
 *                            name. When Bit[31] of attributes field is set to
 *                            1, this field contains the lower 15 bytes of the
 *                            NULL terminated name
 *
 * This function returns the attributes associated with a specific function,
 * pin, or a group of pins. See section 4.11.2.6 PINCTRL_ATTRIBUTES in the
 * [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_FLAGS_SELECTOR() - Selector
 * - ::SCMI_PINCTRL_ATTR_EXT_NAME() - Extended name
 * - ::SCMI_PINCTRL_ATTR_NUM() - Number of pins or groups
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if valid attributes were returned.
 * - ::SCMI_ERR_NOT_FOUND: if the \a identifier field pertains to a
 *   non-existent pin, group, or function.
 */
int32_t SCMI_PinctrlAttributes(uint32_t channel, uint32_t identifier,
    uint32_t flags, uint32_t *attributes, uint8_t *name);

/*!
 * Get pin configuration.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin or group
 * @param[in]     attributes  Pin control set attributes:<BR>
 *                            Bits[31:19] Reserved, must be zero.<BR>
 *                            Bit[18] Get all configs.<BR>
 *                            When set to 0, only the configuration value for
 *                            the configuration type specified by Bits[7:0]
 *                            needs to be returned.<BR>
 *                            When set to 1, configuration values for all
 *                            relevant configuration types associated with the
 *                            pin or group need to be returned. The returned
 *                            configuration array is sorted in numerically
 *                            increasing order of config types.<BR>
 *                            Bits[17:16] Selector: Whether the identifier
 *                            field refers to a pin or a group.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            All other values are reserved for future use.<BR>
 *                            Bits[15:8] skipConfigs<BR>
 *                            The number of configuration types to skip over,
 *                            before returning the first configuration type and
 *                            value in the return configuration array.<BR>
 *                            This field is ignored if Bit[18] is set to 0.<BR>
 *                            Bits[7:0] ConfigType: The type of config.<BR>
 *                            This field is ignored if Bit[18] is set to 1
 * @param[out]    numConfigs  Number of configs:<BR>
 *                            Bits[31:24] Number of remaining
 *                            configurations.<BR>
 *                            Bits[23:8] Reserved, must be zero.<BR>
 *                            Bits[7:0] Number of configurations that are
 *                            returned by this call.<BR>
 *                            This field should be ignored if Bit[18] (Get all
 *                            configs) of the attributes field of the function
 *                            was set to 0
 * @param[out]    configs     Array of configurations: sorted in numerically
 *                            increasing config type order.<BR>
 *                            Size is specified by Bits[7:0] of the \a
 *                            numConfigs field if Bit[18] (Get all configs) of
 *                            the attributes field of the function was set to
 *                            1. Else size must be 1.<BR>
 *                            Each array entry is composed of two 32-bit words
 *                            containing the type and value
 *
 * This function can be used by an agent to get the pin or group configuration.
 * The max number of config is ::SCMI_PINCTRL_MAX_CONFIGS. See section 4.11.2.7
 * PINCTRL_CONFIG_GET in the [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_GET_ATTR_GET_ALL() - Get all configs
 * - ::SCMI_PINCTRL_GET_ATTR_SELECTOR() - Selector
 * - ::SCMI_PINCTRL_GET_ATTR_SKIP_CONFIGS() - Skip Configs
 * - ::SCMI_PINCTRL_GET_ATTR_CONFIG_TYPE() - ConfigType
 * - ::SCMI_PINCTRL_NUM_CONFIG_FLAGS_REMAING_CONFIGS() - Number of remaining
 *   configurations
 * - ::SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS() - Number of configurations
 *   that are returned by this call
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the pin or group configuration was successfully
 *   returned.
 * - ::SCMI_ERR_NOT_FOUND: if the \a identifier field does not point to a
 *   valid pin or group.
 * - ::SCMI_ERR_INVALID_PARAMETERS, if the \a attributes flag specifies
 *   unsupported or invalid configurations.
 * - ::SCMI_ERR_NOT_SUPPORTED: if the request is not supported.
 */
int32_t SCMI_PinctrlConfigGet(uint32_t channel, uint32_t identifier,
    uint32_t attributes, uint32_t *numConfigs, scmi_pin_config_t *configs);

/*!
 * Set pin configuration.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin or group
 * @param[in]     attributes  Pin control get attributes:<BR>
 *                            Bits[31:10] Reserved, must be zero.<BR>
 *                            Bits[9:2] Number of configurations to set.<BR>
 *                            The maximum value of this field is limited by the
 *                            transport used. The agent needs to specify this
 *                            field such that the entire function can be
 *                            accommodated within the transport chosen.<BR>
 *                            Bits[1:0] Selector: Whether the identifier field
 *                            refers to a pin or a group.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            All other values are reserved for future use
 * @param[in]     configs     Array of configurations: sorted in numerically
 *                            increasing config type order.<BR>
 *                            Size is specified by Bits[9:2] of the \a
 *                            attributes field.<BR>
 *                            Each array entry is composed of two 32-bit words
 *                            containing the type and value
 *
 * This function can be used by an agent to set the pin or group configuration.
 * The max number of configs is ::SCMI_PINCTRL_MAX_CONFIGS_T. See section
 * 4.11.2.8 PINCTRL_CONFIG_SET in the [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS() - Number of configurations to set
 * - ::SCMI_PINCTRL_SET_ATTR_SELECTOR() - Selector
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the pin or group configuration was successfully
 *   set.
 * - ::SCMI_ERR_NOT_FOUND: if \a identifier field does not point to a valid
 *   pin or group.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the input parameters specify incorrect
 *   or illegal values.
 * - ::SCMI_ERR_NOT_SUPPORTED: if the configuration requested by this
 *   function is not supported by the pin or group.
 * - ::SCMI_ERR_DENIED: if the calling agent is not allowed to set the
 *   configuration of this pin or group.
 */
int32_t SCMI_PinctrlConfigSet(uint32_t channel, uint32_t identifier,
    uint32_t attributes, const scmi_pin_config_t *configs);

/*!
 * Select a function for a pin.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin or group
 * @param[in]     functionId  Identifier for the function to enable for the pin
 *                            or group
 * @param[in]     flags       Selector: Whether the identifier field selects a
 *                            pin, a group, or a function.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            2 - Function<BR>
 *                            All other values are reserved for future use
 *
 * This function can be used by an agent to select a function for a pin or
 * group. See section 4.11.2.9 PINCTRL_FUNCTION_SELECT in the
 * [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_FLAGS_SELECTOR() - Selector
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the function was successfully enabled.
 * - ::SCMI_ERR_NOT_FOUND: if the \a identifier field does not point to a
 *   valid pin or group, or if the function_id field does not point to a valid
 *   function.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the input parameters specify incorrect
 *   or illegal values.
 * - ::SCMI_ERR_NOT_SUPPORTED: if the configuration requested by this
 *   function is not supported by the pin or group.
 * - ::SCMI_ERR_DENIED: if the calling agent is not allowed to enable this
 *   function on this pin.
 */
int32_t SCMI_PinctrlFunctionSelect(uint32_t channel, uint32_t identifier,
    uint32_t functionId, uint32_t flags);

/*!
 * Request a pin.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin or group
 * @param[in]     flags       Selector: Whether the identifier field selects a
 *                            pin, or a group.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            All other values are reserved for future use
 *
 * This function is used by an agent to request exclusive control of a pin or
 * group. This would make the pin or group unavailable for any other agent
 * until SCMI_PinctrlRelease() has been called by the controlling agent.
 *
 * For the SM, this function is not required as pin access controls are static
 * and cannot be changed dynamically. See section 4.11.2.10 PINCTRL_REQUEST in
 * the [SCMI Spec](@ref DOCS).
 *
 * Access macros:
 * - ::SCMI_PINCTRL_FLAGS_SELECTOR() - Selector
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if exclusive control of the pin or group was granted.
 * - ::SCMI_ERR_NOT_FOUND: if the \a identifier field does not point to a
 *   valid pin or group.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the input parameters specify incorrect
 *   or illegal values.
 * - ::SCMI_ERR_DENIED: if the calling agent is not allowed to request this
 *   pin or group..
 * - ::SCMI_ERR_IN_USE: if the pin or group is currently under exclusive
 *   control of another agent.
 */
int32_t SCMI_PinctrlRequest(uint32_t channel, uint32_t identifier,
    uint32_t flags);

/*!
 * Release a pin.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     identifier  Identifier for the pin or group
 * @param[in]     flags       Selector: Whether the identifier field selects a
 *                            pin, or a group.<BR>
 *                            0 - Pin<BR>
 *                            1 - Group<BR>
 *                            All other values are reserved for future use
 *
 * This function is used by an agent to release exclusive control of a pin or
 * group. See section 4.11.2.11 PINCTRL_RELEASE in the [SCMI Spec](@ref DOCS).
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if exclusive control of the pin or group was released.
 * - ::SCMI_ERR_NOT_FOUND: if the \a identifier field does not point to a
 *   valid pin or group.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the input parameters specify incorrect
 *   or illegal values.
 */
int32_t SCMI_PinctrlRelease(uint32_t channel, uint32_t identifier,
    uint32_t flags);

/*!
 * Negotiate the protocol version.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[in]     version  The negotiated protocol version the agent intends to
 *                         use
 *
 * This command is used to negotiate the protocol version that the agent
 * intends to use, if it does not support the version returned by the
 * SCMI_ProtocolVersion() function. There is no limit on the number of
 * negotiations which can be attempted by the agent. All commands, responses,
 * and notifications must comply with the protocol version which was last
 * negotiated successfully. Using protocol versions different from the version
 * returned by SCMI_ProtocolVersion() without successful negotiation is
 * considered best effort, and functionality is not guaranteed. See section
 * 4.11.2.2 NEGOTIATE_PROTOCOL_VERSION in the [SCMI Spec](@ref DOCS).
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the negotiated protocol version is supported by the
 *   platform. All commands, responses, and notifications post successful
 *   return of this command must comply with the negotiated version.
 * - ::SCMI_ERR_NOT_SUPPORTED: if the protocol version is not supported.
 */
int32_t SCMI_PinctrlNegotiateProtocolVersion(uint32_t channel,
    uint32_t version);

#endif /* SCMI_PINCTRL_H */

/** @} */

