/*
 * dma.h
 *
 *  Created on: Dec 11, 2018
 *      Author: Rashad Shubita
 */

/* Define to prevent recursive inclusion */
#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "stm32f10x.h"


/**
 * @brief   DMA1 Channel3 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA1_Channel3_Init(void);

/*
 * @brief   DMA Channel set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered in a specific channel
 * @param   DMA_Channel, Peripheral_Adr, Memory_Adr, size
 * @retval  None
 */
void DMA_Channel_Set_Addresses(DMA_Channel_TypeDef *DMA_Channel, const uint32_t * Peripheral_Adr,
                                uint32_t * Memory_Adr, const uint32_t size);

/**
 * @brief   Enable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelEnable(DMA_Channel_TypeDef *DMA_Channel,uint8_t DMA_Num, uint8_t Ch_Num);

/**
 * @brief   Disable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelDisable(DMA_Channel_TypeDef *DMA_Channel);


#endif /* INC_DMA_H_ */
