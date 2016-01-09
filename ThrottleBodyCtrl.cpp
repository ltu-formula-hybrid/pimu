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

ThrottleBodyCtrl::ThrottleBodyCtrl(Serial * ctrl) {
    this->controller = ctrl;
}

ThrottleBodyCtrl::~ThrottleBodyCtrl() {}

