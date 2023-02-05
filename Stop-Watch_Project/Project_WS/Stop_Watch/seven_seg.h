 /*******************************************************************
 *
 * Module: Seven_Segement
 *
 * File Name: seven_seg.h
 *
 * Description: Header file for the Seven Segement driver
 *
 * Author: Mohammed Sayed Shaaban
 *
 * Created on : 4/2/2023
 *
 ********************************************************************/

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_types.h"
/********************************************************************
 *                     Definitions
 ********************************************************************/
/*to define which type we will used (4 pins or 8 pins)*/
#define SEVEN_SEG_TYPE        4
#define SEVEN_SEG_PORT        PORTC_ID
#if(SEVEN_SEG_TYPE==4)
#define SEVEN_SEG_FIRST_PIN   PIN0_ID
#define SEVEN_SEG_SECOND_PIN  PIN1_ID
#define SEVEN_SEG_THIRD_PIN   PIN2_ID
#define SEVEN_SEG_FOURTH_PIN  PIN3_ID
#else if(SEVEN_SEG_TYPE==7)
#define SEVEN_SEG_FIVE_PIN    PIN4_ID
#define SEVEN_SEG_SIX_PIN     PIN5_ID
#define SEVEN_SEG_SEVEN_PIN   PIN6_ID
#endif
/********************************************************************
 *                     Functions_Prototypes
 ********************************************************************/

/*
 * Function_Name:SEVEN_setup
 *
 * Function_description:
 * To set the direction of seven segment as output
 */
void SEVEN_setup(void);
/*
 * Function_Name:SEVEN_display
 *
 * Function_description:
 * To display what we want on seven segment
 * argument -->to detect which number will be displayed
 */
void SEVEN_display(uint8);

/*
 * Function_Name:SEVEN_greaterThan_9
 *
 * Function_description:
 * To handle the overflow of sevenSegment
 */
uint8 SEVEN_Equal_9(void);



#endif /* SEVEN_SEG_H_ */
