/*******************************************************************************
 * @file    main.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    15.02.2019
 *
 * @brief   main application called after startup
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


/* Includes ------------------------------------------------------------------*/
#include "nvic.h"
#include "SysTick.h"
#include "exti.h"
#include "gpio.h"
#include "dma.h"
#include "memcpy.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/**
 * @brief   Buffer array size
 */
#define BUFFER_SIZE     ((uint32_t) 500)

/**
 * @brief   use #define USE_MEMCPY or USE_DMA
 */
#define USE_DMA

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/**
 * @brief   Source and destination buffers
 */
static uint32_t srcBuffer[BUFFER_SIZE];
static uint32_t dstBuffer[BUFFER_SIZE];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	SysTick_Init();
    GPIO_OnBoard_Init_LED();

    GPIO_Init_PB();
    EXTI_Init_PB();
    NVIC_Init();

    DMA1_Channel3_Init();
    DMA_Channel_Set_Addresses(DMA1_Channel3, dstBuffer, srcBuffer, BUFFER_SIZE);

    /* Initialize source buffer */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
      srcBuffer[idx] = idx;
    }
    Yellow_LED_BITBAND = 1;
    __enable_irq();
    SysTick_Delay(50);

      /* Signal start of coping data, by turning on Yellow LED */
    	Yellow_LED_BITBAND = 0;

      /* Copy data */
      #ifdef USE_MEMCPY
      ReturnStatus_Type returnResults = memcpy32(srcBuffer, dstBuffer, BUFFER_SIZE);

      /* Check return status */
      if(RETURN_STATUS_OK != returnResults)
      {
        /* Copying is not OK */

      }
      else
      {
        /* Copying is OK, Turn off Yellow LED */
    	   Yellow_LED_BITBAND = 1;
      }
      #endif

     #ifdef USE_DMA
      /* Clear PRIMASK, enable IRQs */

      /* DMA enable */
      DMA_ChannelEnable(DMA1_Channel3, 1,3);

      #endif
  while(1);

}


