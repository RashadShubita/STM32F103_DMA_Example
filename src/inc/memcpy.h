/*******************************************************************************
 * @file    memcpy.h
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    15.02.2019
 *
 * @brief   Copy data between two memory buffers
 * @note
 *
@verbatim
Copyright (C) 2019, Rashad Shubita

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_MEMCPY_H_
#define __INC_MEMCPY_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f10x.h"




/* Exported typedef ----------------------------------------------------------*/
/**
 * @brief   Return type
 */
typedef enum
{
  RETURN_STATUS_OK = 0u,
  RETURN_STATUS_NOT_OK = 1u
} ReturnStatus_Type;



/* Exported define -----------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


/* Exported functions --------------------------------------------------------*/
/**
 * @brief   Copy data between two memory buffers
 * @note
 * @param   src, dst, size
 * @retval  RETURN_STATUS_OK, RETURN_STATUS_NOT_OK
 */
ReturnStatus_Type memcpy32(const uint32_t * src,
    uint32_t * dst, const uint32_t size);


/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_MEMCPY_H_ */
