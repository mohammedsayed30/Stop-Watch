 /******************************************************************
 * Module: Seven_Segement
 *
 * File Name: seven_seg.c
 *
 * Description: Source file for the Seven Segement driver
 *
 * Author: Mohammed Sayed Shaaban
 *
 * Created on : 4/2/2023
 *
 ********************************************************************/
#include "seven_seg.h"
#include "gpio.h"

/*
 * Function_Name:SEVEN_setup
 *
 * Function_description:
 * To set the direction of seven segment as output
 */
void SEVEN_setup(void){
	/*Set the four pins of 7-segment as output PINS*/
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_FIRST_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_SECOND_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_THIRD_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_FOURTH_PIN,PIN_OUTPUT);
	/*Initialise the Seven segment =zero in the begging*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_FIRST_PIN,LOGIC_LOW);/*1th_pin*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_SECOND_PIN,LOGIC_LOW);/*2th_pin*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_THIRD_PIN,LOGIC_LOW);/*3th_pin*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_FOURTH_PIN,LOGIC_LOW);/*4th_pin*/

#if (SEVEN_SEG_TYPE==7)
	/*Set the four pins of 7-segment as output PINS*/
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_FIVE_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_SIX_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEG_PORT,SEVEN_SEG_SEVEN_PIN,PIN_OUTPUT);
	/*Initialise the Seven segment =zero in the begging*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_FIVE_PIN,LOGIC_LOW);/*1th_pin*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_SIX_PIN,LOGIC_LOW);/*2th_pin*/
	GPIO_writePin(SEVEN_SEG_PORT,SEVEN_SEG_SEVEN_PIN,LOGIC_LOW);/*3th_pin*/
#endif
}

/*
 * Function_Name:SEVEN_display
 *
 * Function_description:
 * To display what we want on seven segment(4 pins connections)
 * value argument -->to detect which number will be displayed
 */
void SEVEN_display(uint8 value){
#if(SEVEN_SEG_TYPE==7)
	switch(value)
	{
	case 0:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_LOW);
		break;
	case 2:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	case 3:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	case 4:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	case 5:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	case 6:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_LOW);
		break;
	case 7:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_LOW);
		break;
	case 8:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	case 9:
		GPIO_writePin(SEVEN_SEG_PORT,PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN2_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN3_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN4_ID, LOGIC_LOW);
		GPIO_writePin(SEVEN_SEG_PORT,PIN5_ID, LOGIC_HIGH);
		GPIO_writePin(SEVEN_SEG_PORT,PIN6_ID, LOGIC_HIGH);
		break;
	}
#else if(SEVEN_SEG_TYPE==4)
	/*to don't change the value of the rest of pins in this port*/
	value=(GPIO_readPort(SEVEN_SEG_PORT) & 0xF0)|(value & 0x0F);
	GPIO_writePort(SEVEN_SEG_PORT,value);
#endif

}

/*
 * Function_Name:SEVEN_greaterThan_9
 *
 * Function_description:
 * To handle the overflow of sevenSegment
 */
uint8 SEVEN_Equal_9(void){
	/*check the number if will pass 9*/
	if((GPIO_readPort(SEVEN_SEG_PORT) & 0x0F) == 9){
		return TRUE;
	}
	return FALSE;
}

