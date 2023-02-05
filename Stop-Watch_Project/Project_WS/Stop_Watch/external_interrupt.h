 /******************************************************************
 * Module: 	External_Interrupt
 *
 * File Name: external_interrupt.h
 *
 * Description: Header file for the external_interrupt driver
 *
 * Author: Mohammed Sayed Shaaban
 *
 * Created on : 5/2/2023
 *
 ********************************************************************/

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "std_types.h"

/**************************************************************
 *                       Definitions
 **************************************************************/
#define INT0_PORT        PORTD_ID
#define INT0_PIN         PIN2_ID
#define INT1_PORT        PORTD_ID
#define INT1_PIN         PIN3_ID
#define INT2_PORT        PORTB_ID
#define INT2_PIN         PIN2_ID




/*
 * function Name: Init_INT0
 *
 * description:to enable INT0
 */
void Init_INT0(uint8);
/*
 * function Name: Init_INT1
 *
 * description:to enable INT1
 */
void Init_INT1(uint8);
/*
 * function Name: Init_INT2
 *
 * description:to enable INT2
 */
void Init_INT2(uint8);

/*
 * function Name: INT0_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT0
 */
void INT0_setCallBack(void(*a_ptr)(void));

/*
 * function Name: INT1_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT1
 */
void INT1_setCallBack(void(*a_ptr)(void));

/*
 * function Name: INT2_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT2
 */
void INT2_setCallBack(void(*a_ptr)(void));




#endif /* EXTERNAL_INTERRUPT_H_ */
