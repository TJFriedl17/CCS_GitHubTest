/*
 * servo.c
 *
 *  Created on: Apr 8, 2022
 *      Author: tjfriedl
 */

#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include <servo.h>
#include <Timer.h>

void servo_init(void) {
    //GPIO

    SYSCTL_RCGCGPIO_R |= 0b10; //enable port b
    SYSCTL_RCGCTIMER_R |= 0b10; //enables timer 1
    timer_waitMillis(10);
    GPIO_PORTB_DEN_R |= 0x20; // enable digital functions of wire 5
    GPIO_PORTB_DIR_R |= 0x20; // turn wire 5 into output
    GPIO_PORTB_AFSEL_R |= 0x20; // enable alt func wire 5
    GPIO_PORTB_PCTL_R &= ~0xF00000; //Clear wire 5
    GPIO_PORTB_PCTL_R |= 0x700000; //Set port control to 7, i.e. T1CCP1

    //TIMER


    TIMER1_CTL_R &= ~0x100; // disable timer b while init
    TIMER1_CFG_R = 0x00000004; // select 16 bit timer config
    TIMER1_TBMR_R |= 0xA; // periodic timer mode, pwm enabled, edge count mode
    TIMER1_CTL_R &= ~0x4000; // output is standard/not inverted
    TIMER1_TBPR_R = 0x4; // prescale value = 4
    TIMER1_TBILR_R = 0xE200; // 800 in dec, start 20 ms between pwm waves
    TIMER1_TBMATCHR_R = 0xA380; // high for 5% of 20ms
    TIMER1_TBPMR_R = 0x4;
    TIMER1_CTL_R |= 0x100; // re-enable timer b

    current_degrees = 0; //Resets this value for everytime we want to set value back to zero

}

void servo_move(float degrees) {

    degrees -= 12.5;
    TIMER1_CTL_R &= ~0x100;
    float ms = ((degrees / 180) * 1.5) + 0.75;
    int cycles = (320000 - ((ms / 20) * 320000));
    TIMER1_TBMATCHR_R = cycles & 0xFFFF;
    TIMER1_TBPMR_R = cycles >> 16;
    TIMER1_CTL_R |= 0x100;
    current_degrees = degrees;
    timer_waitMillis(200);
}
