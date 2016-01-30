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
    
    float percent(); // Retrieve the current position of the throttle.
    
    const int defaultIncreaseAmount = 0x10;
    const int defaultDecreaseAmount = 0x20;
    
    int increaseAmt = 0x10;
    int decreaseAmt = 0x20;
    
    ThrottleBodyCtrl(Serial *, AnalogIn *);
    virtual ~ThrottleBodyCtrl();
private:
    Serial * controller;
    AnalogIn * feedback;
    
    const int increasePercentage = 0x45;
    const int decreasePercentage = 0x00;
    const int holdPercentage = 0x10;
    const int idlePercentage = 0x00;
    
    const float threshold = 0.07; // 7.00% threshold
    const float commDelay = 0.00001;
    
    void setup();
};

#endif	/* THROTTLEBODYCTRL_H */

