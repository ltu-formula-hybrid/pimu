#include "utils.h"

float utils::convertPercentVolts(float percent, float maxVoltage) {
    return percent * maxVoltage;
}

float utils::convertVoltsPercent(float currentVoltage, float maxVoltage) {
    if (maxVoltage == 0) {
        return 0;
    }
    return currentVoltage / maxVoltage;
}

void utils::set_leds(bool first, bool second, bool third, bool fourth) {
    DigitalOut led_one(LED1);
    DigitalOut led_two(LED2);
    DigitalOut led_three(LED3);
    DigitalOut led_four(LED4);

    led_one.write(first ? 1 : 0);
    led_two.write(second ? 1 : 0);
    led_three.write(third ? 1 : 0);
    led_four.write(fourth ? 1 : 0);
}

void utils::led_num(int display) {
    DigitalOut led_one(LED1);
    DigitalOut led_two(LED2);
    DigitalOut led_three(LED3);
    DigitalOut led_four(LED4);

    led_one.write(0);
    led_two.write(0);
    led_three.write(0);
    led_four.write(0);
    
    if (display & 0x08) {
        led_four.write(1);
    }
    if (display & 0x04) {
        led_three.write(1);
    }
    if (display & 0x02) {
        led_two.write(1);
    }
    if (display & 0x01) {
        led_one.write(1);
    }
}