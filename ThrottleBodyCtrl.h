/* 
 * File:   ThrottleBodyCtrl.h
 * Author: clagraff
 *
 * Created on January 9, 2016, 1:10 PM
 */
#include "../mbed/mbed.h"

#ifndef THROTTLEBODYCTRL_H
#define	THROTTLEBODYCTRL_H

class ThrottleBodyCtrl {
public:
    void increase(); // Increase the throttle position.
    void decrease(); // Decrease the throttle position.
    void hold(); // Hold at the current throttle position.
    
    ThrottleBodyCtrl(Serial*);
    virtual ~ThrottleBodyCtrl();
private:
    Serial *controller;
    const int increasePercentage = 0x30f;
    const int decreasePercentage = 0x05f;
    const int holdPercentage = 0x10f;
    
    void setup();
};

#endif	/* THROTTLEBODYCTRL_H */

