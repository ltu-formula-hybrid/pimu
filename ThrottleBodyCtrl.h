/* 
 * File:   ThrottleBodyCtrl.h
 * Author: clagraff
 *
 * Created on January 9, 2016, 1:10 PM
 */

#ifndef THROTTLEBODYCTRL_H
#define	THROTTLEBODYCTRL_H
#include "../mbed/mbed.h"

class ThrottleBodyCtrl {
public:
    void increase(); // Increase the throttle position.
    void decrease(); // Decrease the throttle position.
    void hold(); // Hold at the current throttle position.
    void idle(); // Bring throttle position into idle location.
    
    ThrottleBodyCtrl(Serial *, AnalogIn *);
    virtual ~ThrottleBodyCtrl();
private:
    Serial * controller;
    AnalogIn * feedback;
    const int increasePercentage = 0x35;
    const int decreasePercentage = 0x00;
    const int holdPercentage = 0x10;
    
    void setup();
};

#endif	/* THROTTLEBODYCTRL_H */

