/*
 * acd.h
 *
 *  Created on: Mar 25, 2022
 *      Author: tjfriedl
 */

#ifndef ACD_H_
#define ACD_H_

/// Initializes the ADC registers used for the sensor conversions
void adc_init(void);

/// Takes samples of data and parses/operates with what was read in
unsigned adc_read(void);

/// Converts voltage value into digital sample
float convertVoltageToDigital();


#endif /* ACD_H_ */
