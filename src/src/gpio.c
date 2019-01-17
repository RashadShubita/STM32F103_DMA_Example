/*
 * GPIO.c
 *
 *  Created on: Nov 13, 2018
 *      Author: Rashad Shubita
 */

/* Includes */
#include "gpio.h"

/**
 * @brief   LED initialization function
 * @note    Yellow_LED -> PC13
 * @param   None
 * @retval  None
 */
void GPIO_OnBoard_Init_LED(void)
{
 /* Enable clock for GPIOC */
    RCC ->APB2ENR |= RCC_APB2ENR_IOPCEN;
 /* Configure PC.13 in output mode, max speed 2 MHz. */
    GPIOC ->CRH &= ~GPIO_CRH_MODE13;
    GPIOC ->CRH |=  GPIO_CRH_MODE13_1;
 /* Configure PC.13 as  general purpose output push-pull */
    GPIOC ->CRH  &= ~GPIO_CRH_CNF13;
 /* Led OFF */
    GPIOC ->ODR  |= GPIO_ODR_ODR13;

}

/**
 * @brief   Push button initialization function
 * @note    Push button connected to PA0
 * @param   None
 * @retval  None
 */
void GPIO_Init_PB(void)
{
	RCC -> APB2ENR |=  RCC_APB2ENR_IOPAEN;  //Enable Clock for GPIOA
	GPIOA -> CRL   &= ~GPIO_CRL_MODE0;      //Input mode (reset state)
	GPIOA -> CRL   &= ~GPIO_CRL_CNF0_0;     //Input with pull-up / pull-down
	GPIOA -> CRL   |=  GPIO_CRL_CNF0_1;     //
	GPIOA ->ODR    &= ~GPIO_ODR_ODR0;       //active pull-down resistor
}
