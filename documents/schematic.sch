EESchema Schematic File Version 2
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
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LPC1768 IC1
U 1 1 56C3976E
P 2300 1650
F 0 "IC1" H 2150 2550 60  0000 C CNN
F 1 "LPC1768" H 2150 2450 60  0000 C CNN
F 2 "" H 2600 1750 60  0000 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/LPC1769_68_67_66_65_64_63.pdf" H 2350 300 60  0001 C CNN
	1    2300 1650
	1    0    0    -1  
$EndComp
Text GLabel 1500 950  0    39   Input ~ 0
GND
Text GLabel 1550 1050 0    39   Input ~ 0
12VDC
Text GLabel 1500 2650 0    39   Input ~ 0
YASA_MC
$Comp
L TPS280DP U1
U 1 1 56C39ACF
P 2650 4000
F 0 "U1" H 2050 4950 60  0000 C CNN
F 1 "TPS280DP" H 2100 4850 60  0000 C CNN
F 2 "" H 2150 5000 60  0000 C CNN
F 3 "http://www.racetuners.com/wp-content/uploads/2013/01/TPS280DP_tech_data_Ver-2_01_101.pdf" H 2100 4300 60  0001 C CNN
	1    2650 4000
	1    0    0    -1  
$EndComp
Text GLabel 1500 3350 0    39   Input ~ 0
GND
Text GLabel 2900 950  2    39   Output ~ 0
3V
Text GLabel 1500 3250 0    39   Input ~ 0
3V
$Comp
L MCP2551 IC2
U 1 1 56C39E16
P 4000 2500
F 0 "IC2" H 3500 3350 60  0000 C CNN
F 1 "MCP2551" H 3550 3250 60  0000 C CNN
F 2 "" H 4000 2500 60  0000 C CNN
F 3 "" H 4000 2500 60  0000 C CNN
	1    4000 2500
	1    0    0    -1  
$EndComp
Text GLabel 3050 2050 0    39   Input ~ 0
GND
Text GLabel 4200 1950 2    39   BiDi ~ 0
CANH
Text GLabel 4200 2050 2    39   BiDi ~ 0
CANL
Text GLabel 4200 1850 2    39   Input ~ 0
GND
$Comp
L JRK_12v12 U2
U 1 1 56C3A265
P 3700 3200
F 0 "U2" H 3350 4050 60  0000 C CNN
F 1 "JRK_12v12" H 3400 3950 60  0000 C CNN
F 2 "" H 3650 4000 60  0000 C CNN
F 3 "" H 3650 4000 60  0000 C CNN
	1    3700 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 950  1650 950 
Wire Wire Line
	1650 1050 1550 1050
Wire Wire Line
	1650 2650 1500 2650
Wire Wire Line
	1200 2750 1650 2750
Wire Wire Line
	2650 950  2900 950 
Wire Wire Line
	1700 3250 1500 3250
Wire Wire Line
	1700 3350 1500 3350
Wire Wire Line
	1700 3450 1300 3450
Wire Wire Line
	2650 1950 2750 1950
Wire Wire Line
	2750 1950 2750 2150
Wire Wire Line
	2650 2050 2800 2050
Wire Wire Line
	2800 2050 2800 1850
Wire Wire Line
	2800 1850 3150 1850
Wire Wire Line
	2750 2150 3150 2150
Wire Wire Line
	2650 1050 2950 1050
Wire Wire Line
	2950 1050 2950 1950
Wire Wire Line
	2950 1950 3150 1950
Wire Wire Line
	3150 2050 3050 2050
Wire Wire Line
	4050 1950 4200 1950
Wire Wire Line
	4200 2050 4050 2050
Wire Wire Line
	4200 1850 4050 1850
Wire Wire Line
	4100 1850 4100 2150
Wire Wire Line
	4100 2150 4050 2150
Connection ~ 4100 1850
Wire Wire Line
	2750 2850 2650 2850
Wire Wire Line
	3650 3500 3650 3550
Wire Wire Line
	3650 3550 3750 3550
Wire Wire Line
	3750 3550 3750 3500
Wire Wire Line
	3850 3500 3850 3550
Wire Wire Line
	3850 3550 3950 3550
Wire Wire Line
	3950 3550 3950 3500
$Comp
L +12V #PWR?
U 1 1 56C3A4CA
P 3700 950
F 0 "#PWR?" H 3700 800 50  0001 C CNN
F 1 "+12V" H 3700 1090 50  0000 C CNN
F 2 "" H 3700 950 60  0000 C CNN
F 3 "" H 3700 950 60  0000 C CNN
	1    3700 950 
	1    0    0    -1  
$EndComp
Text GLabel 3850 1050 2    39   Output ~ 0
12VDC
Wire Wire Line
	3700 950  3700 1050
Wire Wire Line
	3700 1050 3850 1050
$Comp
L GND #PWR?
U 1 1 56C3A530
P 3700 1300
F 0 "#PWR?" H 3700 1050 50  0001 C CNN
F 1 "GND" H 3700 1150 50  0000 C CNN
F 2 "" H 3700 1300 60  0000 C CNN
F 3 "" H 3700 1300 60  0000 C CNN
	1    3700 1300
	1    0    0    -1  
$EndComp
Text GLabel 3850 1200 2    39   Output ~ 0
GND
Wire Wire Line
	3850 1200 3700 1200
Wire Wire Line
	3700 1200 3700 1300
Wire Wire Line
	2750 3050 2850 3050
Text GLabel 4350 2550 2    39   Input ~ 0
12V
Text GLabel 4350 2650 2    39   Input ~ 0
GND
Text GLabel 4350 2750 2    39   Output ~ 0
MC_A
Text GLabel 4350 2850 2    39   Output ~ 0
MC_B
Wire Wire Line
	4350 2850 4200 2850
Wire Wire Line
	4350 2750 4200 2750
Wire Wire Line
	4200 2650 4350 2650
Wire Wire Line
	4350 2550 4200 2550
Text GLabel 3550 3650 3    39   Input ~ 0
TPS_FB
Wire Wire Line
	3550 3500 3550 3650
Wire Wire Line
	2750 2850 2750 3050
Wire Wire Line
	1300 3450 1300 2850
Wire Wire Line
	1300 2850 1650 2850
Wire Wire Line
	1200 2750 1200 3550
Wire Wire Line
	1200 3550 1700 3550
$EndSCHEMATC
