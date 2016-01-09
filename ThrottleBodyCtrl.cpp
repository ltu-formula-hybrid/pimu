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

void ThrottleBodyCtrl::increase() {
    this->setup();
    (*this->controller).putc(this->increasePercentage); 
}

void ThrottleBodyCtrl::decrease() {
    this->setup();
    (*this->controller).putc(this->decreasePercentage); 
}

void ThrottleBodyCtrl::hold() {
    this->setup();
    (*this->controller).putc(this->holdPercentage); 
}

void ThrottleBodyCtrl::idle() {
    float idle_percent = 0.30f;
    float skewed_tps = *this->feedback - 0.1030f;
    if (skewed_tps < idle_percent) {
        this->increase();
    } 
    else if (idle_percent < skewed_tps && skewed_tps < idle_percent + 0.10f) {
        this->hold();
    } else {
        this->decrease();
    }
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

