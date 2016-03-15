EESchema Schematic File Version 2
LIBS:schematic-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:schematic
LIBS:schematic-cache
EELAYER 25 0
EELAYER END
$Descr User 7874 7874
encoding utf-8
Sheet 1 1
Title "Powertrain Integration Module"
Date "2016-03-11"
Rev "1.0"
Comp "LTU Formula Hybrid"
Comment1 "System overview"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LPC1768 IC1
U 1 1 56C3976E
P 1750 1700
F 0 "IC1" H 1600 2600 60  0000 C CNN
F 1 "LPC1768" H 1600 2500 60  0000 C CNN
F 2 "schematic:LPC1768" H 1650 300 60  0000 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/LPC1769_68_67_66_65_64_63.pdf" H 1800 350 60  0001 C CNN
	1    1750 1700
	1    0    0    -1  
$EndComp
Text GLabel 950  1000 0    47   Input ~ 0
GND
Text GLabel 1000 1100 0    47   Input ~ 0
10VDC
Text GLabel 950  2700 0    47   Output ~ 0
EM_MC
Text GLabel 2350 1000 2    47   Output ~ 0
3.3V
$Comp
L MCP2551 IC3
U 1 1 56C39E16
P 3450 2550
F 0 "IC3" H 2950 3400 60  0000 C CNN
F 1 "MCP2551" H 3000 3300 60  0000 C CNN
F 2 "schematic:MCP2551-ESN" H 3300 2650 60  0000 C CNN
F 3 "" H 3450 2550 60  0000 C CNN
	1    3450 2550
	1    0    0    -1  
$EndComp
Text GLabel 3800 1900 2    47   BiDi ~ 0
CANH
Text GLabel 3800 2200 2    47   BiDi ~ 0
CANL
Text Notes 1250 3050 0    60   ~ 12
Micro-controller
Text Notes 2750 2400 0    60   ~ 12
CAN Transeiver\n
Text GLabel 950  2800 0    39   Input ~ 0
TP_CH2
Text GLabel 950  2900 0    39   Input ~ 0
TP_CH1
$Comp
L R R1
U 1 1 56D1C933
P 3700 2050
F 0 "R1" V 3780 2050 50  0000 C CNN
F 1 "120" V 3700 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3630 2050 30  0001 C CNN
F 3 "" H 3700 2050 30  0000 C CNN
	1    3700 2050
	1    0    0    -1  
$EndComp
Text GLabel 2650 2900 2    39   Output ~ 0
MC_CTRL
Text Notes 2550 3400 0    60   ~ 12
PCB Terminal Block
Text GLabel 950  2600 0    39   Output ~ 0
FAN_CTRL
Text GLabel 2650 2800 2    47   Input ~ 0
GND
Text GLabel 2850 3550 0    39   UnSpc ~ 0
GND
Text GLabel 2850 3650 0    39   Output ~ 0
10VDC
Text GLabel 2850 3750 0    39   Input ~ 0
EM_MC
Text GLabel 2850 3850 0    39   Input ~ 0
TP_CH1
Text GLabel 2850 3950 0    39   Input ~ 0
TP_CH2
Text GLabel 2850 4050 0    39   BiDi ~ 0
CANH
Text GLabel 2850 4150 0    39   BiDi ~ 0
CANL
Text GLabel 2850 4250 0    39   Input ~ 0
MC_CTRL
Text GLabel 2850 4350 0    39   Input ~ 0
FAN_CTRL
Text GLabel 1000 1400 0    39   BiDi ~ 0
GPIO_01
Text GLabel 1000 1500 0    39   BiDi ~ 0
GPIO_02
Text GLabel 1000 1600 0    39   BiDi ~ 0
GPIO_03
Text GLabel 1000 1700 0    39   BiDi ~ 0
GPIO_04
Text GLabel 1000 1800 0    39   BiDi ~ 0
STARTER_SIG
Text GLabel 2850 4450 0    39   BiDi ~ 0
STARTER_SIG
Text Notes 5000 2000 0    51   ~ 10
Labels
Text Notes 5050 3150 0    51   ~ 0
GND: chassis ground\n10VDC: regulated 10VDC\nEM_MC: electric motor's motor controller's control signal\nTP_CH1: thottle position sensor's channel 01\nTP_CH2: throttle position sensor's channel 02\nCANH: high CAN line\nCANL: low CAN line\nMC_CTRL: throttle body's motor controler control signal\nFAN_CTRL: motor fan's control signal\nGPIO_01: unused\nGPIO_02: unused\nGPIO_03: unused\nGPIO_04: unused\nGPIO_05: unused
Text GLabel 4250 5100 0    39   Input ~ 0
MC_CTRL
Text GLabel 1250 7100 0    39   Output ~ 0
CH2
Text GLabel 1250 7000 0    39   Output ~ 0
CH1
Text Notes 2200 6100 2    60   ~ 12
Voltage Regulator
Text GLabel 2450 5900 2    39   Output ~ 0
GND
Text GLabel 2450 5800 2    39   Output ~ 0
10VDC
$Comp
L 090483 IC2
U 1 1 56CBE051
P 1750 5750
F 0 "IC2" H 1900 6000 60  0000 C CNN
F 1 "090483" H 1600 6000 60  0000 C CNN
F 2 "" H 1900 6000 39  0001 C CNN
F 3 "" H 1900 6000 39  0000 C CNN
	1    1750 5750
	1    0    0    -1  
$EndComp
Text Notes 5700 5150 0    60   ~ 12
Motor Controller for Throttle Body
Text Notes 1200 7250 0    60   ~ 12
Accelerator Position Sensor
Text GLabel 5450 5700 3    47   Output ~ 0
TPS_GND
Text GLabel 5250 5700 3    47   Output ~ 0
TPS_VSS
$Comp
L TPS280DP SEN1
U 1 1 56CBAA16
P 2400 7550
F 0 "SEN1" H 1800 8500 60  0000 C CNN
F 1 "TPS280DP" H 1850 8400 60  0000 C CNN
F 2 "" H 1900 8550 60  0001 C CNN
F 3 "http://www.racetuners.com/wp-content/uploads/2013/01/TPS280DP_tech_data_Ver-2_01_101.pdf" H 1850 7850 60  0001 C CNN
	1    2400 7550
	1    0    0    -1  
$EndComp
Text GLabel 5150 5700 3    47   Input ~ 0
TPS_FB
Text GLabel 5950 4900 2    47   Output ~ 0
MC_B
Text GLabel 5950 4800 2    47   Output ~ 0
MC_A
Text GLabel 5950 4700 2    47   Input ~ 0
GND
Text GLabel 5950 4600 2    47   Input ~ 0
10VDC
$Comp
L GND #PWR01
U 1 1 56C3A530
P 1050 5800
F 0 "#PWR01" H 1050 5550 50  0001 C CNN
F 1 "GND" H 1050 5650 50  0000 C CNN
F 2 "" H 1050 5800 60  0000 C CNN
F 3 "" H 1050 5800 60  0000 C CNN
	1    1050 5800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR02
U 1 1 56C3A4CA
P 1050 5500
F 0 "#PWR02" H 1050 5350 50  0001 C CNN
F 1 "+12V" H 1050 5640 50  0000 C CNN
F 2 "" H 1050 5500 60  0000 C CNN
F 3 "" H 1050 5500 60  0000 C CNN
	1    1050 5500
	1    0    0    -1  
$EndComp
$Comp
L JRK_12v12 MC1
U 1 1 56C3A265
P 5300 5250
F 0 "MC1" H 4950 6100 60  0000 C CNN
F 1 "JRK_12v12" H 5000 6000 60  0000 C CNN
F 2 "" H 5250 6050 60  0001 C CNN
F 3 "" H 5250 6050 60  0000 C CNN
	1    5300 5250
	1    0    0    -1  
$EndComp
Text GLabel 1250 6800 0    47   Input ~ 0
3.3V
Text GLabel 1250 6900 0    47   Input ~ 0
GND
$Comp
L CONN_01X10 P1
U 1 1 56E87048
P 3150 4000
F 0 "P1" H 3150 4550 50  0000 C CNN
F 1 "CONN_01X10" V 3250 4000 50  0000 C CNN
F 2 "schematic:CONN_01X10_CUST" H 3100 4750 60  0000 C CNN
F 3 "" H 3150 4000 60  0000 C CNN
	1    3150 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2100 2500 2100
Connection ~ 2150 2800
Connection ~ 1050 1200
Connection ~ 1050 1000
Connection ~ 2150 1900
Connection ~ 2150 2200
Connection ~ 2150 2300
Wire Wire Line
	2150 2200 2100 2200
Connection ~ 2150 2400
Wire Wire Line
	2150 2300 2100 2300
Connection ~ 2150 2500
Wire Wire Line
	2150 2400 2100 2400
Connection ~ 2150 2600
Wire Wire Line
	2150 2500 2100 2500
Connection ~ 2150 2700
Wire Wire Line
	2150 2600 2100 2600
Wire Wire Line
	2150 2700 2100 2700
Wire Wire Line
	2100 2800 2650 2800
Connection ~ 2150 1800
Wire Wire Line
	2150 1900 2100 1900
Connection ~ 2150 1700
Wire Wire Line
	2150 1800 2100 1800
Connection ~ 2150 1600
Wire Wire Line
	2150 1700 2100 1700
Connection ~ 2150 1500
Wire Wire Line
	2150 1600 2100 1600
Connection ~ 2150 1400
Wire Wire Line
	2150 1500 2100 1500
Connection ~ 2150 1300
Wire Wire Line
	2150 1400 2100 1400
Wire Wire Line
	2150 1300 2100 1300
Wire Wire Line
	2150 1200 2150 2800
Wire Wire Line
	2100 1200 2150 1200
Connection ~ 1050 1300
Wire Wire Line
	1050 1200 1100 1200
Wire Wire Line
	1050 1300 1100 1300
Wire Wire Line
	1000 1400 1100 1400
Wire Wire Line
	1000 1500 1100 1500
Wire Wire Line
	1000 1600 1100 1600
Wire Wire Line
	1000 1700 1100 1700
Connection ~ 1050 1900
Wire Wire Line
	1000 1800 1100 1800
Connection ~ 1050 2000
Wire Wire Line
	1050 1900 1100 1900
Connection ~ 1050 2100
Wire Wire Line
	1050 2000 1100 2000
Connection ~ 1050 2200
Wire Wire Line
	1050 2100 1100 2100
Connection ~ 1050 2300
Wire Wire Line
	1050 2200 1100 2200
Connection ~ 1050 2400
Wire Wire Line
	1050 2300 1100 2300
Wire Wire Line
	1050 2400 1100 2400
Wire Wire Line
	1050 2500 1100 2500
Wire Wire Line
	1100 2600 950  2600
Wire Wire Line
	2100 2900 2650 2900
Connection ~ 3700 2200
Connection ~ 3700 1900
Wire Wire Line
	3600 2100 3500 2100
Wire Wire Line
	3600 2000 3500 2000
Wire Wire Line
	3500 1900 3550 1900
Wire Wire Line
	3600 2200 3600 2100
Wire Wire Line
	3600 2200 3800 2200
Wire Wire Line
	3600 1900 3600 2000
Wire Wire Line
	3600 1900 3800 1900
Wire Wire Line
	950  2900 1100 2900
Wire Wire Line
	1100 2800 950  2800
Wire Wire Line
	3550 2200 3500 2200
Wire Wire Line
	2400 2000 2600 2000
Wire Wire Line
	2400 1100 2400 2000
Wire Wire Line
	2100 1100 2400 1100
Wire Wire Line
	2200 2200 2600 2200
Wire Wire Line
	2250 1900 2600 1900
Wire Wire Line
	2250 2100 2250 1900
Wire Wire Line
	2100 2100 2250 2100
Wire Wire Line
	2200 2000 2200 2200
Wire Wire Line
	2100 2000 2200 2000
Wire Wire Line
	2100 1000 2350 1000
Wire Wire Line
	1100 2700 950  2700
Wire Wire Line
	1100 1100 1000 1100
Wire Wire Line
	950  1000 1100 1000
Wire Wire Line
	2500 2100 2500 2800
Connection ~ 2500 2800
Wire Wire Line
	1050 1000 1050 2500
Wire Wire Line
	3550 1900 3550 2300
Wire Wire Line
	3550 2300 2500 2300
Connection ~ 2500 2300
Connection ~ 3550 2200
Wire Wire Line
	1450 6800 1250 6800
Wire Wire Line
	1450 6900 1250 6900
Wire Wire Line
	5250 5550 5250 5700
Wire Wire Line
	5250 5600 5350 5600
Wire Wire Line
	5350 5600 5350 5550
Wire Wire Line
	5450 5550 5450 5700
Wire Wire Line
	5450 5600 5550 5600
Wire Wire Line
	5550 5600 5550 5550
Wire Wire Line
	5950 4900 5800 4900
Wire Wire Line
	5950 4800 5800 4800
Wire Wire Line
	5800 4700 5950 4700
Wire Wire Line
	5950 4600 5800 4600
Wire Wire Line
	5150 5550 5150 5700
Connection ~ 5250 5600
Connection ~ 5450 5600
Wire Wire Line
	2300 5800 2450 5800
Wire Wire Line
	2450 5900 2300 5900
Wire Wire Line
	1050 5500 1050 5600
Wire Wire Line
	1050 5600 1250 5600
Wire Wire Line
	1050 5800 1050 5700
Wire Wire Line
	1050 5700 1250 5700
Wire Wire Line
	1450 7000 1250 7000
Wire Wire Line
	1250 7100 1450 7100
Wire Wire Line
	4250 5100 4450 5100
Wire Wire Line
	2950 3550 2850 3550
Wire Wire Line
	2950 3650 2850 3650
Wire Wire Line
	2950 3750 2850 3750
Wire Wire Line
	2950 3850 2850 3850
Wire Wire Line
	2950 3950 2850 3950
Wire Wire Line
	2950 4050 2850 4050
Wire Wire Line
	2950 4150 2850 4150
Wire Wire Line
	2950 4250 2850 4250
Wire Wire Line
	2950 4350 2850 4350
Wire Wire Line
	2950 4450 2850 4450
$EndSCHEMATC
