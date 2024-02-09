 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC_NUM_OF_BITS 10
#define ADC_PORT PORTA_ID
#define CHANNEL0 PIN0_ID
#define CHANNEL1 PIN1_ID
#define CHANNEL2 PIN2_ID
#define CHANNEL3 PIN3_ID
#define CHANNEL4 PIN4_ID
#define CHANNEL5 PIN5_ID
#define CHANNEL6 PIN6_ID
#define CHANNEL7 PIN7_ID

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

typedef enum{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum{
	PRE2_1,PRE2_2,PRE4,PRE8,PRE16,PRE32,PRE64,PRE128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
