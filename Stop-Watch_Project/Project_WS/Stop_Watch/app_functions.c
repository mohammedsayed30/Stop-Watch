 /**********************************************************
 *
 * Module: Applications
 *
 * File Name: app_functions.c
 *
 * Description: Source file for the app_functions of stop watch
 *
 * Created on:5/2/2023
 *
 * Author: Mohammed Sayed Shaaban
 *
 ***********************************************************/
#include <util/delay.h> /*to use the delay functions*/
#include "app_functions.h"
#include <avr/io.h>      /*to use the Registers*/
unsigned char sec1=0;    //hold the first digit of seconds
unsigned char sec2=0;   //hold the second digit of seconds
unsigned char min1=0;   //hold the first digit of minutes
unsigned char min2=0;   //hold the second digit of minutes
unsigned char h1=0;     //hold the first digit of hours
unsigned char h2=0;     //hold the second digit of hours
/*
 * Function_Name:display_time
 *
 * description:to display the time on 7-segment
 */
void display_time(void){
	PORTA=(PORTA & 0xC0)|(0x01);   //enable the first segment
	SEVEN_display(sec1);           //display  the first digit of seconds
	_delay_ms(3);                 //as the CPU very fast
	PORTA=(PORTA & 0xC0)|(0x02);  //enable the second segment
	SEVEN_display(sec2);         //display  the second digit of seconds
	_delay_ms(3);
	PORTA=(PORTA & 0xC0)|(0x04);   //enable the third segment
	SEVEN_display(min1);           //display  the first digit of minutes
	_delay_ms(3);
	PORTA=(PORTA & 0xC0)|(0x08);   //enable the fourth segment
	SEVEN_display(min2);           //display  the second digit of minutes
	_delay_ms(3);
	PORTA=(PORTA & 0xC0)|(16);     //enable the fifth segment
	SEVEN_display(h1);             //display  the first digit of hours
	_delay_ms(3);
	PORTA=(PORTA & 0xC0)|(32);    //enable the sixth segment
	SEVEN_display(h2);            //display  the second digit of hours
	_delay_ms(3);
}

/*
 * Function_Name:APP_callBack
 *
 * description:the function that will executed when the Timer
 * finish the count and give an interrupt
 *
 * an interrupt every one second
 */

void APP_timerCallBack(void){
	/*as every interrupt=1second--->So we will increase sec count*/
	sec1++;
	if(sec1==10){
		sec2++;
		sec1=0;
	}
	/* this mean the timer count one minute more*/
	if(sec2==6){
		sec2=0;
		sec1=0;
		min1++;
	}
	if(min1==10){
		sec2=0;
		sec1=0;
		min1=0;
		min2++;
	}
	/* this mean the time increase one hour more*/
	if(min2==6){
		sec2=0;
		sec1=0;
		min1=0;
		min2=0;
		h1++;
	}
	if(h1==10){
		sec2=0;
		sec1=0;
		min1=0;
		min2=0;
		h1=0;
		h2++;
	}
}
/*
 * Function_Name:APP_INT0_CallBack
 *
 * description:
 * 1-the function that will executed when the Interrupt on INT0 occur
 * 2-this to reset the stop watch when the interrupt occurs
 */
void APP_INT0_CallBack(void){
	sec1=0;
	sec2=0;
	min1=0;
	min2=0;
	h1=0;
	h2=0;
	TCNT1=0;
}

/*
 * Function_Name:APP_INT1_CallBack
 *
 *description:
 *1-the function that will executed when the Interrupt on INT1 occur
 *2-external interrupt for INT1 (Paused The Time)
 */

void APP_INT1_CallBack(void){
	/*to close the clock source*/
	TCCR1B &=~(1<<CS12) & ~(1<<CS10) & ~(1<<CS11);
}

/*
 * Function_Name:APP_INT2_CallBack
 *
 * description:
 *1-the function that will executed when the Interrupt on INT2 occur
 *2-external interrupt for INT2 (resumed The Time)
 */

void APP_INT2_CallBack(void){
	/*to return the clock source*/
	TCCR1B=(1<<WGM12)|(1<<CS12)|(1<<CS10);
}


