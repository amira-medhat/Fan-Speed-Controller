/*
 * main.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Amira
 */


#include "lm35_sensor.h"
#include "lcd.h"
#include "DC_MOTOR.h"
#include "adc.h"

void display(uint8 temp)
{
	if (temp < 30)
	{
		LCD_moveCursor(0,3);
		LCD_displayString("FAN is OFF");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10);
		DC_Motor_rotate(OFF,0);
	}
	else if (temp >= 30 && temp < 60)
	{
		LCD_moveCursor(0,3);
		LCD_displayString("FAN is ON");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,3);
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10);
		DC_Motor_rotate(CW,25);
	}
	else if (temp >= 60 && temp < 90)
	{
		LCD_moveCursor(0,3);
		LCD_displayString("FAN is ON");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,3);
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10);
		DC_Motor_rotate(CW,50);
	}
	else if (temp >= 90 && temp < 120)
	{
		LCD_moveCursor(0,3);
		LCD_displayString("FAN is ON");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,3);
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10);
		DC_Motor_rotate(CW,75);
	}
	else if (temp > 120)
	{
		LCD_moveCursor(0,3);
		LCD_displayString("FAN is ON");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1,3);
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10);
		DC_Motor_rotate(CW,100);
	}
	if(temp >= 100)
	{
		LCD_intgerToString(temp);
	}
	else
	{
		LCD_intgerToString(temp);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}

}

int main(void)
{
	uint8 temp;
	ADC_ConfigType ADC_state;
	LCD_init(); /* initialize LCD driver */

	ADC_state.ref_volt = INTERNAL;
	ADC_state.prescaler = PRE8;
	DC_Motor_init(); /* initialize DC motor driver */
	ADC_init(&ADC_state); /* initialize ADC driver */
	temp = LM35_getTemperature();
	display(temp);


	while(1)
	{
		if (temp != LM35_getTemperature())
		{
			temp = LM35_getTemperature();
			display(temp);
		}
		else
		{
			/* do nothing */
		}
	}
}
