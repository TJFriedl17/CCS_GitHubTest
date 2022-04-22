#include "ping.h"
#include "lcd.h"

/*
 * ping.c
 *
 *  Revised on: April 14, 2022
 *      Author: Trevor Friedl
 */


void ping_init()
{
    num_overflows = 0;

    //Config for GPIO Port B Wire 3
    SYSCTL_RCGCGPIO_R |= 0b10; // clock B
    GPIO_PORTB_DIR_R |=0b1000; // set output
    GPIO_PORTB_AFSEL_R &= ~0b1000; // not alt func yet
    GPIO_PORTB_DEN_R |= 0b1000; // turn on digital functions
    GPIO_PORTB_PCTL_R &= 0xFFFF7FFF; //Alternate function to timer
    GPIO_PORTB_PCTL_R |= 0x7000; //Alternate function to timer


    SYSCTL_RCGCTIMER_R |= 0x8; //Enable Timer3(B)
    TIMER3_CTL_R &= ~0x100; //Stop counting
    TIMER3_CFG_R |= 0x4; //Select 16 bit config
    TIMER3_TBMR_R &= ~0x18; // force zero on what is not a 1
    TIMER3_TBMR_R |= 0x007; //Capture mode, edge time mode, timer counts up

    TIMER3_CTL_R |= 0xC00; //Both edges on TimerB
    TIMER3_TBILR_R = 0xFFFF; //Sets upper bound to 65535
    TIMER3_TBPR_R = 0xFF; //Prescale to 24 bit timer

    TIMER3_ICR_R |= 0x400; //Clear interrupt
    TIMER3_IMR_R |= 0x00400;

    NVIC_EN1_R |=  0x10;
    IntRegister(INT_TIMER3B, TIMER3B_Handler);

}

/*
 * This will be one of the main functions that we'll use for the scanning on the board
 */
float ping_read() {

    send_pulse();
    while(state != DONE); //Busy wait
    int time = rising_time - falling_time; //Counting down, so rising is greater than falling
    if(time < 0) {
        num_overflows++;
        time = rising_time - (0xFFFFF + falling_time);
    }
    float millis = time / 16000000.0;
    float centi = (millis / 2) * 34000;
    return centi;

}

void send_pulse()
{
    TIMER3_CTL_R &= ~0x100; //Stop counting
    TIMER3_IMR_R &= ~0x400; //Disable interrupt for CBEIM
    GPIO_PORTB_AFSEL_R &= ~0b1000; //Select software controlled
    GPIO_PORTB_DIR_R |= 0b1000; // Set PB3 as output
    GPIO_PORTB_DATA_R &= ~0b1000;//Set low
    timer_waitMicros(2);
    GPIO_PORTB_DATA_R |= 0b1000;// Set PB3 to high
    // wait at least 5 microseconds based on data sheet
    timer_waitMicros(10);
    GPIO_PORTB_DATA_R &= ~0b1000;// Set PB3 to low
    GPIO_PORTB_DIR_R &= ~0b1000;// Set PB3 as input
    GPIO_PORTB_AFSEL_R |= 0b1000; //Select alternate function
    state = LOW;
    TIMER3_ICR_R |= 0x400; //Clear interrupt
    TIMER3_IMR_R |= 0x400; //Enable interrupt for CBEIM
    TIMER3_CTL_R |= 0x100; //Start counting
}


// ISR captures PING sensor’s response pulse start and end time
void TIMER3B_Handler()
{
    if((TIMER3_MIS_R & 0x400) == 0)
        return; //Interrupt was not capture event

    TIMER3_ICR_R |= 0x400; //Clear interrupt

    if(state == LOW) {
        rising_time = TIMER3_TBR_R;
        state = HIGH;
    } else if (state == HIGH) {
        falling_time = TIMER3_TBR_R;
        state = DONE;
    }



}

