 /**********************************************************
 *
 * Module: Applications
 *
 * File Name: app_functions.h
 *
 * Description: Header file for the app_functions of stop watch
 *
 * Created on:5/2/2023
 *
 * Author: Mohammed Sayed Shaaban
 *
 ***********************************************************/

#ifndef APP_FUNCTIONS_H_
#define APP_FUNCTIONS_H_
#include "std_types.h"

/*
 * Function_Name:display_time
 *
 * description:to display the time on 7-segment
 */
void display_time(void);

/*
 * Function_Name:APP_callBack
 *
 * description:the function that will executed when the Timer
 * finish the count and give an interrupt
 */

void APP_timerCallBack(void);

/*
 * Function_Name:APP_INT0_CallBack
 *
 * description:the function that will executed when the Interrupt
 * on INT0 occur
 */

void APP_INT0_CallBack(void);

/*
 * Function_Name:APP_INT0_CallBack
 *
 * description:the function that will executed when the Interrupt
 * on INT1 occur
 */

void APP_INT1_CallBack(void);

/*
 * Function_Name:APP_INT0_CallBack
 *
 * description:the function that will executed when the Interrupt
 * on INT2 occur
 */

void APP_INT2_CallBack(void);

#endif /* APP_FUNCTIONS_H_ */
