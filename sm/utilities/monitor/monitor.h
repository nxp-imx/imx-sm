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

/*==========================================================================*/
/*!
 * @addtogroup MONITOR
 * @{
 *
 * @file
 * @brief
 *
 * Header file for the debug monitor.
 */
/*==========================================================================*/


#ifndef SM_MONITOR_H
#define SM_MONITOR_H

/* Includes */

#include "sm.h"
#include "brd_sm.h"

/* Defines */

#define EOL         '\x00'  /*!< End of line character */

/* Types */

/*!
 * Key:string pair
 */
typedef struct
{
    uint32_t key;   /*!< Key */
    string str;     /*!< String */
} monitor_key_pair_t;

/*! Callback function type for searching for a name */
typedef int32_t (*func_t)(uint32_t lm, uint32_t id, string *addr,
    int32_t *len);

/* Functions */

#ifdef MONITOR

/*!
 * Run the monitor.
 *
 * @param[in]     banner       String to display as a banner
 *
 * This function allows the caller to run the debug monitor.
 */
void MONITOR_Cmd(string banner);

/*!
 * Insert a string into the monitor line buffer.
 *
 * @param[in]     my_string    Character string of command
 *
 * This function allows a caller to issue a monitor command.
 */
void MONITOR_LineUpdateDispatch(const char *my_string);

/*!
 * Search string list for matching string.
 *
 * @param[in]     list         List of strings to search
 * @param[in]     max          Number of strings in list
 * @param[in]     str          String to find
 *
 * This function allows a caller to find a string in a list.
 *
 * @return Returns the matching index.
 */
int32_t MONITOR_Find(string const *list, int32_t max, const char *str);

/*!
 * Search string list for matching string (limited).
 *
 * @param[in]     list         List of strings to search
 * @param[in]     max          Number of strings in list
 * @param[in]     str          String to find
 *
 * This function allows a caller to find a string in a list. It varies
 * from MONITOR_Find() in that is only matches up to the length
 * of the string in the list.
 *
 * @return Returns the matching index.
 */
int32_t MONITOR_FindN(string const *list, int32_t max, const char *str);

/*!
 * Parse command string into array of args.
 *
 * @param[in]     line         Line to parse
 * @param[out]    argc         Return number of arguments
 * @param[out]    argv         Array of pointers to arguments
 *
 * This function plits the line at space boundaries and creates a
 * pointer list to each. Note it modifies \a line.
 */
void MONITOR_ParseLine(char *line, int32_t *argc, const char *argv[]);

#ifdef SIMU
uint32_t SystemMemoryProbe(const void *addr, void *val, uint8_t width);
#endif

/*!
 * Get character pending status.
 *
 * @return Returns true if a character is pending.
 */
bool MONITOR_CharPending(void);

/*!
 * Yield to allow other interrupts to run.
 */
void MONITOR_Yield(void);

/*!
 * Search via LMM name function for a match.
 *
 * @param[in]     rsrcName     Name to search for
 * @param[out]    id           Return pointer to index
 * @param[in]     func         Function pointer to get name
 * @param[in]     max          Max indexes to search over
 *
 * This function allows a caller to find a string in a name function.
 * It varies from MONITOR_Find() in that its calls \a func to get
 * each name.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t MONITOR_NameToId(const char *rsrcName, uint32_t *id,
    func_t func, uint32_t max);

/*!
 * Convert a string to a 32-bit unsigned integer.
 *
 * @param[in]     str          String to convert
 * @param[out]    val          Return number
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t MONITOR_ConvU32(const char *str, uint32_t *val);

/*!
 * Convert a string to a 64-bit unsigned integer.
 *
 * @param[in]     str          String to convert
 * @param[out]    val          Return number
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t MONITOR_ConvU64(const char *str, uint64_t *val);

/*!
 * Convert a string to a 32-bit integer.
 *
 * @param[in]     str          String to convert
 * @param[out]    val          Return number
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t MONITOR_ConvI32(const char *str, int32_t *val);

/*!
 * Find matching string.
 *
 * @param[in]     key          Key to find
 * @param[in]     pair         Key:String pair array
 *
 * @return Matching string.
 */
string MONITOR_Key2Str(uint32_t key, const monitor_key_pair_t *pair);

#endif

#endif /* SM_MONITOR_H */

/** @} */

