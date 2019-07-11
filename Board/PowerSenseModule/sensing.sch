EESchema Schematic File Version 4
LIBS:PowerSenseModule-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "Power Sense Module - Power Sensing"
Date ""
Rev ""
Comp "University of Central Florida - HKN Zeta Chi"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L F1_Power_Sense:MCP39F511A U?
U 1 1 5D2177A0
P 6700 3250
F 0 "U?" H 6700 3450 50  0000 C CNN
F 1 "MCP39F511A" H 6700 3300 50  0000 C CNB
F 2 "Package_DFN_QFN:QFN-28-1EP_5x5mm_P0.5mm_EP3.35x3.35mm" H 6600 2100 50  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/MCP39F511A-Data-Sheet-20006044A.pdf" H 6600 2100 50  0001 C CNN
	1    6700 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3350 6050 3350
Wire Wire Line
	6050 3350 6050 3450
Wire Wire Line
	6050 3450 6100 3450
$Comp
L Device:C C?
U 1 1 5D21A0CB
P 5100 1950
F 0 "C?" H 5215 1996 50  0000 L CNN
F 1 "1uF" H 5215 1905 50  0000 L CNN
F 2 "" H 5138 1800 50  0001 C CNN
F 3 "~" H 5100 1950 50  0001 C CNN
	1    5100 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D21B3BB
P 6700 1800
F 0 "R?" V 6495 1800 50  0000 C CNN
F 1 "10" V 6586 1800 50  0000 C CNN
F 2 "" V 6740 1790 50  0001 C CNN
F 3 "~" H 6700 1800 50  0001 C CNN
	1    6700 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 2450 6600 2300
Wire Wire Line
	6600 2300 6550 2300
Wire Wire Line
	6550 2300 6550 1800
Wire Wire Line
	6800 2450 6800 2300
Wire Wire Line
	6800 2300 6850 2300
Wire Wire Line
	6850 2300 6850 1800
$Comp
L Device:C C?
U 1 1 5D21F603
P 8050 1950
F 0 "C?" H 8165 1996 50  0000 L CNN
F 1 "0.1uF" H 8165 1905 50  0000 L CNN
F 2 "" H 8088 1800 50  0001 C CNN
F 3 "~" H 8050 1950 50  0001 C CNN
	1    8050 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0116
U 1 1 5D21F609
P 8050 2100
F 0 "#PWR0116" H 8050 1850 50  0001 C CNN
F 1 "GNDD" H 8054 1945 50  0000 C CNN
F 2 "" H 8050 2100 50  0001 C CNN
F 3 "" H 8050 2100 50  0001 C CNN
	1    8050 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0117
U 1 1 5D21F7BD
P 5100 2100
F 0 "#PWR0117" H 5100 1850 50  0001 C CNN
F 1 "GNDA" H 5105 1927 50  0000 C CNN
F 2 "" H 5100 2100 50  0001 C CNN
F 3 "" H 5100 2100 50  0001 C CNN
	1    5100 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D218FF9
P 5450 1950
F 0 "C?" H 5565 1996 50  0000 L CNN
F 1 "0.1uF" H 5565 1905 50  0000 L CNN
F 2 "" H 5488 1800 50  0001 C CNN
F 3 "~" H 5450 1950 50  0001 C CNN
	1    5450 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0118
U 1 1 5D2201CD
P 5450 2100
F 0 "#PWR0118" H 5450 1850 50  0001 C CNN
F 1 "GNDA" H 5455 1927 50  0000 C CNN
F 2 "" H 5450 2100 50  0001 C CNN
F 3 "" H 5450 2100 50  0001 C CNN
	1    5450 2100
	1    0    0    -1  
$EndComp
Connection ~ 6850 1800
$Comp
L power:+3V3 #PWR0119
U 1 1 5D2207AA
P 6850 1550
F 0 "#PWR0119" H 6850 1400 50  0001 C CNN
F 1 "+3V3" H 6865 1723 50  0000 C CNN
F 2 "" H 6850 1550 50  0001 C CNN
F 3 "" H 6850 1550 50  0001 C CNN
	1    6850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1550 6850 1800
$Comp
L power:GNDA #PWR0120
U 1 1 5D2218B8
P 6600 4150
F 0 "#PWR0120" H 6600 3900 50  0001 C CNN
F 1 "GNDA" H 6605 3977 50  0000 C CNN
F 2 "" H 6600 4150 50  0001 C CNN
F 3 "" H 6600 4150 50  0001 C CNN
	1    6600 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0121
U 1 1 5D22204E
P 6800 4150
F 0 "#PWR0121" H 6800 3900 50  0001 C CNN
F 1 "GNDD" H 6804 3995 50  0000 C CNN
F 2 "" H 6800 4150 50  0001 C CNN
F 3 "" H 6800 4150 50  0001 C CNN
	1    6800 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D2237F5
P 7550 4200
F 0 "C?" H 7665 4246 50  0000 L CNN
F 1 "1uF" H 7665 4155 50  0000 L CNN
F 2 "" H 7588 4050 50  0001 C CNN
F 3 "~" H 7550 4200 50  0001 C CNN
	1    7550 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D2237FE
P 7900 4200
F 0 "C?" H 8015 4246 50  0000 L CNN
F 1 "0.1uF" H 8015 4155 50  0000 L CNN
F 2 "" H 7938 4050 50  0001 C CNN
F 3 "~" H 7900 4200 50  0001 C CNN
	1    7900 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4050 7900 4050
Wire Wire Line
	7300 3800 7550 3800
Wire Wire Line
	7550 3800 7550 4050
$Comp
L power:GNDA #PWR0122
U 1 1 5D223DE6
P 7550 4350
F 0 "#PWR0122" H 7550 4100 50  0001 C CNN
F 1 "GNDA" H 7555 4177 50  0000 C CNN
F 2 "" H 7550 4350 50  0001 C CNN
F 3 "" H 7550 4350 50  0001 C CNN
	1    7550 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0123
U 1 1 5D2243A8
P 7900 4350
F 0 "#PWR0123" H 7900 4100 50  0001 C CNN
F 1 "GNDA" H 7905 4177 50  0000 C CNN
F 2 "" H 7900 4350 50  0001 C CNN
F 3 "" H 7900 4350 50  0001 C CNN
	1    7900 4350
	1    0    0    -1  
$EndComp
Text Notes 9100 3500 0    50   ~ 0
The exposed pad should be connected to GNDD\n
Text Notes 9850 3650 0    50   ~ 0
Using internal oscillator\n
$Comp
L Sensor_Temperature:MCP9700AT-ETT U?
U 1 1 5D225BE6
P 5200 4500
F 0 "U?" H 4870 4546 50  0000 R CNN
F 1 "MCP9700AT-ETT" H 4870 4455 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5200 4100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21942e.pdf" H 5050 4750 50  0001 C CNN
	1    5200 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0124
U 1 1 5D22706A
P 5200 4200
F 0 "#PWR0124" H 5200 4050 50  0001 C CNN
F 1 "+3V3" H 5215 4373 50  0000 C CNN
F 2 "" H 5200 4200 50  0001 C CNN
F 3 "" H 5200 4200 50  0001 C CNN
	1    5200 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0125
U 1 1 5D2279C0
P 5200 4800
F 0 "#PWR0125" H 5200 4550 50  0001 C CNN
F 1 "GNDA" H 5205 4627 50  0000 C CNN
F 2 "" H 5200 4800 50  0001 C CNN
F 3 "" H 5200 4800 50  0001 C CNN
	1    5200 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Shunt_US R?
U 1 1 5D23AF10
P 2300 2450
F 0 "R?" H 2212 2496 50  0000 R CNN
F 1 "2m" H 2212 2405 50  0000 R CNN
F 2 "" V 2230 2450 50  0001 C CNN
F 3 "~" H 2300 2450 50  0001 C CNN
	1    2300 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D263BF8
P 2850 2550
F 0 "R?" V 2750 2550 50  0000 C CNN
F 1 "1k" V 2650 2550 50  0000 C CNN
F 2 "" V 2890 2540 50  0001 C CNN
F 3 "~" H 2850 2550 50  0001 C CNN
	1    2850 2550
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C?
U 1 1 5D264BA1
P 3300 2750
F 0 "C?" H 3415 2796 50  0000 L CNN
F 1 "3.0nF" H 3415 2705 50  0000 L CNN
F 2 "" H 3338 2600 50  0001 C CNN
F 3 "~" H 3300 2750 50  0001 C CNN
	1    3300 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D26507B
P 3800 2750
F 0 "C?" H 3915 2796 50  0000 L CNN
F 1 "3.0nF" H 3915 2705 50  0000 L CNN
F 2 "" H 3838 2600 50  0001 C CNN
F 3 "~" H 3800 2750 50  0001 C CNN
	1    3800 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0126
U 1 1 5D26D7C8
P 3800 2900
F 0 "#PWR0126" H 3800 2650 50  0001 C CNN
F 1 "GNDA" H 3805 2727 50  0000 C CNN
F 2 "" H 3800 2900 50  0001 C CNN
F 3 "" H 3800 2900 50  0001 C CNN
	1    3800 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0127
U 1 1 5D26DECF
P 3300 2900
F 0 "#PWR0127" H 3300 2650 50  0001 C CNN
F 1 "GNDA" H 3305 2727 50  0000 C CNN
F 2 "" H 3300 2900 50  0001 C CNN
F 3 "" H 3300 2900 50  0001 C CNN
	1    3300 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D27159F
P 3250 4000
F 0 "R?" H 3182 3954 50  0000 R CNN
F 1 "34.8k" H 3182 4045 50  0000 R CNN
F 2 "" V 3290 3990 50  0001 C CNN
F 3 "~" H 3250 4000 50  0001 C CNN
	1    3250 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D271D51
P 4050 4000
F 0 "R?" H 3982 3954 50  0000 R CNN
F 1 "34.8k" H 3982 4045 50  0000 R CNN
F 2 "" V 4090 3990 50  0001 C CNN
F 3 "~" H 4050 4000 50  0001 C CNN
	1    4050 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 3550 2300 3550
Connection ~ 2300 3550
Wire Wire Line
	2450 3750 1700 3750
Connection ~ 1700 3750
Wire Wire Line
	3250 3750 3250 3850
Wire Wire Line
	4050 3550 4050 3850
$Comp
L power:GNDA #PWR0128
U 1 1 5D282E96
P 4050 4150
F 0 "#PWR0128" H 4050 3900 50  0001 C CNN
F 1 "GNDA" H 4055 3977 50  0000 C CNN
F 2 "" H 4050 4150 50  0001 C CNN
F 3 "" H 4050 4150 50  0001 C CNN
	1    4050 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0129
U 1 1 5D283600
P 3250 4150
F 0 "#PWR0129" H 3250 3900 50  0001 C CNN
F 1 "GNDA" H 3255 3977 50  0000 C CNN
F 2 "" H 3250 4150 50  0001 C CNN
F 3 "" H 3250 4150 50  0001 C CNN
	1    3250 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2550 2700 2550
Wire Wire Line
	4600 3550 4600 3050
Wire Wire Line
	4600 3050 6100 3050
Wire Wire Line
	4050 3550 4450 3550
Connection ~ 4050 3550
Wire Wire Line
	3250 3750 3650 3750
Wire Wire Line
	4750 3750 4750 3150
Wire Wire Line
	4750 3150 6100 3150
Connection ~ 3250 3750
Wire Wire Line
	4250 2550 4250 2950
Wire Wire Line
	4250 2950 6100 2950
Wire Wire Line
	4400 2350 4400 2850
Wire Wire Line
	4400 2850 6100 2850
Wire Wire Line
	5600 4500 5700 4500
Wire Wire Line
	5700 3650 6100 3650
Wire Wire Line
	5700 3650 5700 4500
Wire Wire Line
	2300 2650 2300 3550
$Comp
L Device:R_US R?
U 1 1 5D25FC31
P 2850 2350
F 0 "R?" V 2645 2350 50  0000 C CNN
F 1 "1k" V 2736 2350 50  0000 C CNN
F 2 "" V 2890 2340 50  0001 C CNN
F 3 "~" H 2850 2350 50  0001 C CNN
	1    2850 2350
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D2710EB
P 2600 3750
F 0 "R?" V 2700 3750 50  0000 C CNN
F 1 "499k" V 2800 3750 50  0000 C CNN
F 2 "" V 2640 3740 50  0001 C CNN
F 3 "~" H 2600 3750 50  0001 C CNN
	1    2600 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D270144
P 2600 3550
F 0 "R?" V 2395 3550 50  0000 C CNN
F 1 "499k" V 2486 3550 50  0000 C CNN
F 2 "" V 2640 3540 50  0001 C CNN
F 3 "~" H 2600 3550 50  0001 C CNN
	1    2600 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 3750 3250 3750
Wire Wire Line
	2750 3750 2850 3750
Wire Wire Line
	3150 3550 4050 3550
Wire Wire Line
	2750 3550 2850 3550
$Comp
L Device:R_US R?
U 1 1 5D271520
P 3000 3750
F 0 "R?" V 3100 3750 50  0000 C CNN
F 1 "499k" V 3200 3750 50  0000 C CNN
F 2 "" V 3040 3740 50  0001 C CNN
F 3 "~" H 3000 3750 50  0001 C CNN
	1    3000 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5D271375
P 3000 3550
F 0 "R?" V 2800 3550 50  0000 C CNN
F 1 "499k" V 2886 3550 50  0000 C CNN
F 2 "" V 3040 3540 50  0001 C CNN
F 3 "~" H 3000 3550 50  0001 C CNN
	1    3000 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 2350 2700 2350
Wire Wire Line
	3000 2550 3800 2550
Wire Wire Line
	3000 2350 3300 2350
Wire Wire Line
	3300 2600 3300 2350
Connection ~ 3300 2350
Wire Wire Line
	3300 2350 4400 2350
Wire Wire Line
	3800 2600 3800 2550
Connection ~ 3800 2550
Wire Wire Line
	3800 2550 4250 2550
$Comp
L Device:C C?
U 1 1 5D23D964
P 3650 4000
F 0 "C?" H 3765 4046 50  0000 L CNN
F 1 "820pF" H 3765 3955 50  0000 L CNN
F 2 "" H 3688 3850 50  0001 C CNN
F 3 "~" H 3650 4000 50  0001 C CNN
	1    3650 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D23E4B6
P 4450 4000
F 0 "C?" H 4565 4046 50  0000 L CNN
F 1 "820pF" H 4565 3955 50  0000 L CNN
F 2 "" H 4488 3850 50  0001 C CNN
F 3 "~" H 4450 4000 50  0001 C CNN
	1    4450 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3850 3650 3750
Connection ~ 3650 3750
Wire Wire Line
	3650 3750 4750 3750
Wire Wire Line
	4450 3850 4450 3550
Connection ~ 4450 3550
Wire Wire Line
	4450 3550 4600 3550
$Comp
L power:GNDA #PWR0130
U 1 1 5D24546D
P 3650 4150
F 0 "#PWR0130" H 3650 3900 50  0001 C CNN
F 1 "GNDA" H 3655 3977 50  0000 C CNN
F 2 "" H 3650 4150 50  0001 C CNN
F 3 "" H 3650 4150 50  0001 C CNN
	1    3650 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0131
U 1 1 5D245980
P 4450 4150
F 0 "#PWR0131" H 4450 3900 50  0001 C CNN
F 1 "GNDA" H 4455 3977 50  0000 C CNN
F 2 "" H 4450 4150 50  0001 C CNN
F 3 "" H 4450 4150 50  0001 C CNN
	1    4450 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1800 5450 1800
Text HLabel 7400 3500 2    50   Input ~ 0
PSEN_EVENT2
Text HLabel 7400 3400 2    50   Input ~ 0
PSEN_EVENT1
Text HLabel 5400 2650 0    50   Input ~ 0
PSEN_ADC_RST
Text HLabel 8650 2650 2    50   Input ~ 0
PSEN_MCLR
Text HLabel 7400 2950 2    50   Input ~ 0
PSEN_UART_RX
Text HLabel 7400 2850 2    50   Input ~ 0
PSEN_UART_TX
Text HLabel 7400 3650 2    50   Input ~ 0
PSEN_ZCD
$Comp
L Device:R_US R?
U 1 1 5D243C8A
P 7450 2300
F 0 "R?" H 7518 2346 50  0000 L CNN
F 1 "10k" H 7518 2255 50  0000 L CNN
F 2 "" V 7490 2290 50  0001 C CNN
F 3 "~" H 7450 2300 50  0001 C CNN
	1    7450 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2150 7450 1800
Wire Wire Line
	6850 1800 7450 1800
Wire Wire Line
	8050 1800 7450 1800
Wire Wire Line
	7450 2450 7450 2650
Wire Wire Line
	7450 2650 7300 2650
Wire Wire Line
	7450 2650 8650 2650
Connection ~ 7450 2650
Connection ~ 5450 1800
Connection ~ 6550 1800
Connection ~ 7450 1800
$Comp
L Device:R_US R?
U 1 1 5D262084
P 5950 2300
F 0 "R?" H 6018 2346 50  0000 L CNN
F 1 "R_US" H 6018 2255 50  0000 L CNN
F 2 "" V 5990 2290 50  0001 C CNN
F 3 "~" H 5950 2300 50  0001 C CNN
	1    5950 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2450 5950 2650
Wire Wire Line
	5950 2650 6100 2650
Wire Wire Line
	5950 2150 5950 1800
Wire Wire Line
	5450 1800 5950 1800
Connection ~ 5950 1800
Wire Wire Line
	5950 1800 6550 1800
Wire Wire Line
	5400 2650 5950 2650
Connection ~ 5950 2650
Wire Wire Line
	7400 2850 7300 2850
Wire Wire Line
	7400 2950 7300 2950
Wire Wire Line
	7300 3400 7400 3400
Wire Wire Line
	7300 3500 7400 3500
Wire Wire Line
	7300 3650 7400 3650
Text HLabel 2300 1300 1    50   Input ~ 0
Live_IN
Text HLabel 1700 1300 1    50   Input ~ 0
Neutral_IN
Wire Wire Line
	1700 3750 1700 4300
Wire Wire Line
	2300 3550 2300 4300
Text HLabel 1700 4300 3    50   Input ~ 0
Neutral_OUT
Text HLabel 2300 4300 3    50   Input ~ 0
Live_OUT
Wire Wire Line
	1700 1300 1700 3750
Wire Wire Line
	2300 1300 2300 2250
$EndSCHEMATC
