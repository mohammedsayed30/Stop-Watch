 /******************************************************************
 * Module: 	External_Interrupt
 *
 * File Name: external_interrupt.c
 *
 * Description: Source file for the external_interrupt driver
 *
 * Author: Mohammed Sayed Shaaban
 *
 * Created on : 5/2/2023
 *
 ********************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "external_interrupt.h"
#include "gpio.h"

/************************************************************
 *                  Global Variables
 ***********************************************************/
/* Global variables to hold the address of the
 * call back function in the application that response for INT0
 */
static volatile void (*g0_callBackPtr)(void) =NULL_PTR;
/* Global variables to hold the address of the
 * call back function in the application that response for INT1
 */
static volatile void (*g1_callBackPtr)(void) =NULL_PTR;
/* Global variables to hold the address of the
 * call back function in the application that response for INT2
 */
static volatile void (*g2_callBackPtr)(void) =NULL_PTR;


/*************************************************************
 *                    Functions_definitions
 *************************************************************/
/*
 * This the function Interrupt That will be Executed when the
 * Interrupt occurs  on INT0
 */
ISR(INT0_vect){
	if(g0_callBackPtr!=NULL_PTR){
		g0_callBackPtr();
	}
}
/*
 * This the function Interrupt That will be Executed when the
 * Interrupt occurs on INT1
 */
ISR(INT1_vect){
	if(g1_callBackPtr!=NULL_PTR){
		g1_callBackPtr();
	}
}

/*
 * This the function Interrupt That will be Executed when the
 * Interrupt occurs on INT1
 */
ISR(INT2_vect){
	if(g2_callBackPtr!=NULL_PTR){
		g2_callBackPtr();
	}
}
/*
 * function Name: Init_INT0
 *
 * description:to enable INT0
 */
void Init_INT0(uint8 edg){
	/*to make  this pin as input pin*/
	GPIO_setupPinDirection(INT0_PORT,INT0_PIN,PIN_INPUT);
	 /*to enable internal pull up resistor*/
	GPIO_writePin(INT0_PORT,INT0_PIN,LOGIC_HIGH);
	/*to make this interrupt with falling edge*/
	if(edg==0){
		MCUCR |=(1<<ISC01);
		MCUCR &=~(1<<ISC00);
	}
	/*to make this interrupt with rising edge*/
	if(edg==1){
		MCUCR |=(1<<ISC01);
		MCUCR |=(1<<ISC00);
	}
	GICR |=(1<<INT0);  //to enable INT0
}
void Init_INT1(uint8 edg){
	/*to make  this pin as input pin*/
	GPIO_setupPinDirection(INT1_PORT,INT1_PIN,PIN_INPUT);
	/*to make this interrupt with raising edge*/
	if(edg==1){
		MCUCR |=(1<<ISC10)|(1<<ISC11);
	}
	/*to make this interrupt with falling edge*/
	else if(edg==0){
		MCUCR |=(1<<ISC11);
		MCUCR &=~(1<<ISC10);
	}

	GICR |=(1<<INT1);   //to enable INT1
}
void Init_INT2(uint8 edg){
	/*to make  this pin as input pin*/
	GPIO_setupPinDirection(INT2_PORT,INT2_PIN,PIN_INPUT);
	/*to enable internal pull up resistor*/
	GPIO_writePin(INT2_PORT,INT2_PIN,LOGIC_HIGH);
	/*to make this interrupt with falling edge*/
	if(edg==0){
		MCUCSR &=~(1<<ISC2);
	}
	else if(edg==1){
		MCUCSR |=(1<<ISC2);
	}

	GICR |=(1<<INT2); /*to enable INT1*/
}

/*
 * function Name: INT0_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT0
 */
void INT0_setCallBack(void(*a_ptr)(void)){
	/*
	 * hold the address of Application functions that response
	 * for ISR of INT0
	 */
	g0_callBackPtr=a_ptr;
}

/*
 * function Name: INT1_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT1
 */
void INT1_setCallBack(void(*a_ptr)(void)){
	/*
	 * hold the address of Application functions that response
	 * for ISR of INT1
	 */
	g1_callBackPtr=a_ptr;
}

/*
 * function Name: INT2_setCallBack
 *
 * description:to set the function that will be executed when
 * the Interrupt occurs on INT2
 */
void INT2_setCallBack(void(*a_ptr)(void)){
	/*
	 * hold the address of Application functions that respone
	 * for ISR of INT0
	 */
	g2_callBackPtr=a_ptr;
}
