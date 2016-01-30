/* 
 * File:   ThrottleBodyCtrl.cpp
 * Author: clagraff
 * 
 * Created on January 9, 2016, 1:10 PM
 */

#include "ThrottleBodyCtrl.h"

void ThrottleBodyCtrl::setup() {
    (*this->controller).putc(0x85); // Set motor to forward diretion
    (*this->controller).putc(0x00); // nop
    
}

void ThrottleBodyCtrl::idle() {
    this->setup();
    (*this->controller).putc(this->idlePercentage); 
}

void ThrottleBodyCtrl::increase() {
    this->setup();
    (*this->controller).putc(this->increaseAmt); 
}

void ThrottleBodyCtrl::decrease() {
    this->setup();
    (*this->controller).putc(this->decreaseAmt); 
}

void ThrottleBodyCtrl::hold() {
    this->setup();
    (*this->controller).putc(this->holdPercentage); 
}

float ThrottleBodyCtrl::percent() {
    // The TPS will not go to 0 volts.
    // We will do the following to adjust. This is NOT the best solution,
    // but will work for now...
    float skewed = *this->feedback - 0.1030f;
    
    if (skewed < 0.0f)
    {
        skewed = 0.0f;
    }
    else if (skewed > 1.0f)
    {
        skewed = 1.0f;
    }
    
    return skewed;
}

ThrottleBodyCtrl::ThrottleBodyCtrl(Serial * ctrl, AnalogIn * feedback) {
    if (ctrl != NULL)
    {
        this->controller = ctrl;
    }
    if (feedback != NULL)
    {
        this->feedback = feedback;
    }
}

ThrottleBodyCtrl::~ThrottleBodyCtrl() {
    if (this->controller != NULL)
    {
        delete this->controller;
    }
}

