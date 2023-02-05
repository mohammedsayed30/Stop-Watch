 /**********************************************************
 *
 * Module: Applications
 *
 * File Name: app.c
 *
 * Description: Source file for the app_functions of stop watch
 *
 * Created on:5/2/2023
 *
 * Author: Mohammed Sayed Shaaban
 *
 ***********************************************************/
#include "seven_seg.h"
#include "timer1.h"
#include <avr/io.h>
#include "external_interrupt.h"
#include "app_functions.h"




int main(void){
	/*send the address of app call functions of Timer1 Interrupt*/
	Timer1_setCallBack(APP_timerCallBack);
	/*send the address of app call functions of INT0*/
	INT0_setCallBack(APP_INT0_CallBack);
	/*send the address of app call functions of INT1*/
	INT1_setCallBack(APP_INT1_CallBack);
	/*send the address of app call functions of INT2*/
	INT2_setCallBack(APP_INT2_CallBack);
	/*
	 * set the required configurations of timer1:
	 * Compare mode and 1024 prescalar
	 */
	Timer1_ConfigType conf;
	conf.compare_value=1000;
	conf.initial_value=0;
	conf.mode=COMPARE_MODE;
	conf.prescalar=CLK_1024;
	Timer1_init(&conf);
	/*setup the 7-segment*/
	SEVEN_setup();
/*
 * set the first six pins as ouput pins to control which
 * segment will be display
 */
	DDRA |=0x3F;
	SREG|=(1<<7);   //to enable global interrupt
	Init_INT0(0);   //run the INT0(falling edge)
	Init_INT1(1);   //run the INT1(rising edge)
	Init_INT2(0);     //run the INT2(falling_edge)
	while(1){
		/*to display the digits always*/
		display_time();
	}
}










