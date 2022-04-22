/*
 * adc.c
 *
 *  Created on: Mar 25, 2022
 *      Author: tjfriedl
 */

#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include "lcd.h"
#include "math.h"

void adc_init(void) {

        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
        SYSCTL_RCGCADC_R |= 0x1;
        GPIO_PORTB_AFSEL_R |= 0x01;
        GPIO_PORTB_DIR_R &= 0b11111110;
        GPIO_PORTB_DEN_R |= 0x00;
        GPIO_PORTB_AMSEL_R |= 0x01;
        GPIO_PORTB_ADCCTL_R = 0x00;

        ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN1;
        ADC0_EMUX_R = ADC_EMUX_EM1_PROCESSOR;
        ADC0_SSMUX1_R |= 0x000A;
        ADC0_SSCTL0_R |= (ADC_SSCTL1_IE0 | ADC_SSCTL1_END0);
        ADC0_SAC_R |= ADC_SAC_AVG_64X;
        ADC0_ACTSS_R |= ADC_ACTSS_ASEN1;
}

unsigned adc_read(void) {
        ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN1;
        ADC0_SSMUX1_R |= 0;
        ADC0_ACTSS_R |= ADC_ACTSS_ASEN1;
        ADC0_PSSI_R=ADC_PSSI_SS1;
        while((ADC_RIS_INR1) == 0){}
        ADC0_ISC_R=ADC_ISC_IN1;

       return ADC0_SSFIFO1_R;
}

float convertVoltageToDigital() {

    // ALGORITHM TO AVERAGE READINGS PER 100 milliseconds
    int i = 0, increments = 100;
        int isr_int_value = 0;
        for(i=0;i<increments;i++){
            timer_waitMicros(500);  //samples every 1 millisecond
            isr_int_value += adc_read();
        }
        int quantNum = isr_int_value/increments;
        float distance = 105375 * pow(quantNum,-1.153);
        return distance;

}
