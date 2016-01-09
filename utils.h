/* 
 * File:   utils.h
 * Author: clagraff
 *
 * Created on January 9, 2016, 3:52 PM
 */

#ifndef UTILS_H
#define	UTILS_H
#include "../mbed/mbed.h"

namespace utils {
    
    float convertPercentVolts(float, float);
    float convertVoltsPercent(float, float);
    
    void led_num(int);
    void set_leds(bool, bool, bool, bool);
}


#endif	/* UTILS_H */

