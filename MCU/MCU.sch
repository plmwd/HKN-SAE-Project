EESchema Schematic File Version 4
LIBS:MCU-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Formula 1 Power Monioring - MCU"
Date ""
Rev "1.0"
Comp "University of Central Florida - HKN Zeta Chi"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3300 1500 3300 1100
Wire Wire Line
	3300 1500 3500 1500
$Comp
L Device:L L1
U 1 1 5D1AFDBE
P 3450 1100
F 0 "L1" V 3300 1100 50  0000 C CNN
F 1 "L" V 3400 1100 50  0000 C CNN
F 2 "" H 3450 1100 50  0001 C CNN
F 3 "~" H 3450 1100 50  0001 C CNN
	1    3450 1100
	0    -1   -1   0   
$EndComp
Connection ~ 3300 1100
Wire Wire Line
	3300 1100 3300 950 
$Comp
L Device:CP1 C2
U 1 1 5D1B11E5
P 3800 1450
F 0 "C2" H 3685 1404 50  0000 R CNN
F 1 "10uF" H 3685 1495 50  0000 R CNN
F 2 "" H 3800 1450 50  0001 C CNN
F 3 "~" H 3800 1450 50  0001 C CNN
	1    3800 1450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3650 1100 3600 1100
$Comp
L power:GND #PWR04
U 1 1 5D1B4504
P 3800 1300
F 0 "#PWR04" H 3800 1050 50  0001 C CNN
F 1 "GND" H 3805 1127 50  0000 C CNN
F 2 "" H 3800 1300 50  0001 C CNN
F 3 "" H 3800 1300 50  0001 C CNN
	1    3800 1300
	-1   0    0    1   
$EndComp
Text Notes 3900 1600 0    50   ~ 0
tantalum, < 1 Ohm ESR\n
$Comp
L Device:R_US R1
U 1 1 5D1B51D5
P 1850 1550
F 0 "R1" H 1918 1596 50  0000 L CNN
F 1 "R_US" H 1918 1505 50  0000 L CNN
F 2 "" V 1890 1540 50  0001 C CNN
F 3 "~" H 1850 1550 50  0001 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5D1B85DD
P 2200 1800
F 0 "R2" H 2268 1846 50  0000 L CNN
F 1 "R_US" H 2268 1755 50  0000 L CNN
F 2 "" V 2240 1790 50  0001 C CNN
F 3 "~" H 2200 1800 50  0001 C CNN
	1    2200 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1850 1700 1850 1800
Wire Wire Line
	1850 1800 2050 1800
$Comp
L Device:Jumper_NO_Small JP1
U 1 1 5D1B8B21
P 1850 2000
F 0 "JP1" V 1800 1800 50  0000 L CNN
F 1 "Jumper_NO_Small" V 1900 1300 50  0000 L CNN
F 2 "" H 1850 2000 50  0001 C CNN
F 3 "~" H 1850 2000 50  0001 C CNN
	1    1850 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 1900 1850 1800
Connection ~ 1850 1800
$Comp
L Device:C C1
U 1 1 5D1BA03E
P 1850 2250
F 0 "C1" H 1965 2296 50  0000 L CNN
F 1 "0.1uF" H 1965 2205 50  0000 L CNN
F 2 "" H 1888 2100 50  0001 C CNN
F 3 "~" H 1850 2250 50  0001 C CNN
	1    1850 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D1BA5A8
P 1850 2400
F 0 "#PWR02" H 1850 2150 50  0001 C CNN
F 1 "GND" H 1855 2227 50  0000 C CNN
F 2 "" H 1850 2400 50  0001 C CNN
F 3 "" H 1850 2400 50  0001 C CNN
	1    1850 2400
	1    0    0    -1  
$EndComp
Text Notes 3350 1050 0    50   ~ 0
OPTIONAL\n
Wire Wire Line
	3400 4000 3400 4200
Wire Wire Line
	3400 4200 3600 4200
Wire Wire Line
	3600 4200 3600 4000
Wire Wire Line
	3800 4000 3800 4200
Wire Wire Line
	3800 4200 3600 4200
Connection ~ 3600 4200
$Comp
L power:GND #PWR09
U 1 1 5D1C8BCB
P 3600 4200
F 0 "#PWR09" H 3600 3950 50  0001 C CNN
F 1 "GND" H 3605 4027 50  0000 C CNN
F 2 "" H 3600 4200 50  0001 C CNN
F 3 "" H 3600 4200 50  0001 C CNN
	1    3600 4200
	1    0    0    -1  
$EndComp
Text Notes 700  2700 0    50   ~ 0
Capacitor disconnected when programming\n
$Comp
L Interface_CAN_LIN:MCP2542WFDxMF U2
U 1 1 5D1D10B6
P 7000 1400
F 0 "U2" H 6700 1000 50  0000 C CNN
F 1 "MCP2542WFDxMF-SOIC" H 6500 900 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7000 900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/MCP2542FD-4FD-MCP2542WFD-4WFD-Data-Sheet20005514B.pdf" H 7000 1400 50  0001 C CNN
	1    7000 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 5D1D3CD9
P 7000 1000
F 0 "#PWR011" H 7000 850 50  0001 C CNN
F 1 "+5V" H 7050 1150 50  0000 C CNN
F 2 "" H 7000 1000 50  0001 C CNN
F 3 "" H 7000 1000 50  0001 C CNN
	1    7000 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 5D1D4392
P 6900 1000
F 0 "#PWR010" H 6900 850 50  0001 C CNN
F 1 "+3.3V" H 6850 1150 50  0000 C CNN
F 2 "" H 6900 1000 50  0001 C CNN
F 3 "" H 6900 1000 50  0001 C CNN
	1    6900 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5D1D5ACD
P 7800 1400
F 0 "R3" H 7868 1446 50  0000 L CNN
F 1 "120" H 7868 1355 50  0000 L CNN
F 2 "" V 7840 1390 50  0001 C CNN
F 3 "~" H 7800 1400 50  0001 C CNN
	1    7800 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1300 7650 1300
Wire Wire Line
	7650 1300 7650 1250
Wire Wire Line
	7650 1250 7800 1250
Connection ~ 7800 1250
Wire Wire Line
	7800 1250 8300 1250
Wire Wire Line
	7500 1500 7650 1500
Wire Wire Line
	7650 1500 7650 1550
Wire Wire Line
	7650 1550 7800 1550
Connection ~ 7800 1550
Wire Wire Line
	7800 1550 8300 1550
Text GLabel 8300 1250 2    50   Input ~ 0
CANH
Text GLabel 8300 1550 2    50   Input ~ 0
CANL
$Comp
L power:GND #PWR012
U 1 1 5D1D8E02
P 7000 1800
F 0 "#PWR012" H 7000 1550 50  0001 C CNN
F 1 "GND" H 7005 1627 50  0000 C CNN
F 2 "" H 7000 1800 50  0001 C CNN
F 3 "" H 7000 1800 50  0001 C CNN
	1    7000 1800
	1    0    0    -1  
$EndComp
Text GLabel 6500 1200 0    50   Input ~ 0
CAN_TX
Text GLabel 6500 1300 0    50   Input ~ 0
CAN_RX
Text GLabel 6500 1600 0    50   Input ~ 0
CAN_STBY
$Comp
L power:+3.3V #PWR03
U 1 1 5D1E7B70
P 1850 1400
F 0 "#PWR03" H 1850 1250 50  0001 C CNN
F 1 "+3.3V" H 1865 1573 50  0000 C CNN
F 2 "" H 1850 1400 50  0001 C CNN
F 3 "" H 1850 1400 50  0001 C CNN
	1    1850 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR08
U 1 1 5D1E7EFD
P 3300 950
F 0 "#PWR08" H 3300 800 50  0001 C CNN
F 1 "+3.3V" H 3315 1123 50  0000 C CNN
F 2 "" H 3300 950 50  0001 C CNN
F 3 "" H 3300 950 50  0001 C CNN
	1    3300 950 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 5D1E73B5
P 8050 2350
F 0 "#PWR01" H 8050 2200 50  0001 C CNN
F 1 "+3.3V" H 8065 2523 50  0000 C CNN
F 2 "" H 8050 2350 50  0001 C CNN
F 3 "" H 8050 2350 50  0001 C CNN
	1    8050 2350
	1    0    0    -1  
$EndComp
Text Notes 8300 2250 0    50   ~ 0
Close to VDD MCU pin\n
$Comp
L power:GND #PWR06
U 1 1 5D1BE44C
P 8050 2650
F 0 "#PWR06" H 8050 2400 50  0001 C CNN
F 1 "GND" H 8055 2477 50  0000 C CNN
F 2 "" H 8050 2650 50  0001 C CNN
F 3 "" H 8050 2650 50  0001 C CNN
	1    8050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2650 8550 2650
Wire Wire Line
	8250 2650 8050 2650
Connection ~ 8250 2650
Wire Wire Line
	8250 2350 8550 2350
Wire Wire Line
	8250 2350 8050 2350
Connection ~ 8250 2350
$Comp
L Device:C C3
U 1 1 5D1BE442
P 8250 2500
F 0 "C3" H 8050 2550 50  0000 L CNN
F 1 "0.01uF" H 7900 2450 50  0000 L CNN
F 2 "" H 8288 2350 50  0001 C CNN
F 3 "~" H 8250 2500 50  0001 C CNN
	1    8250 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5D1BE43C
P 8550 2500
F 0 "C4" H 8665 2546 50  0000 L CNN
F 1 "0.1uF" H 8665 2455 50  0000 L CNN
F 2 "" H 8588 2350 50  0001 C CNN
F 3 "~" H 8550 2500 50  0001 C CNN
	1    8550 2500
	1    0    0    -1  
$EndComp
Text Notes 9750 2250 0    50   ~ 0
Close to CAN transceiver
$Comp
L power:GND #PWR07
U 1 1 5D1E97C4
P 9500 2650
F 0 "#PWR07" H 9500 2400 50  0001 C CNN
F 1 "GND" H 9505 2477 50  0000 C CNN
F 2 "" H 9500 2650 50  0001 C CNN
F 3 "" H 9500 2650 50  0001 C CNN
	1    9500 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2650 10000 2650
Wire Wire Line
	9700 2650 9500 2650
Connection ~ 9700 2650
Wire Wire Line
	9700 2350 10000 2350
Wire Wire Line
	9700 2350 9500 2350
Connection ~ 9700 2350
$Comp
L Device:C C5
U 1 1 5D1E97D0
P 9700 2500
F 0 "C5" H 9500 2550 50  0000 L CNN
F 1 "0.01uF" H 9350 2450 50  0000 L CNN
F 2 "" H 9738 2350 50  0001 C CNN
F 3 "~" H 9700 2500 50  0001 C CNN
	1    9700 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5D1E97D6
P 10000 2500
F 0 "C6" H 10115 2546 50  0000 L CNN
F 1 "0.1uF" H 10115 2455 50  0000 L CNN
F 2 "" H 10038 2350 50  0001 C CNN
F 3 "~" H 10000 2500 50  0001 C CNN
	1    10000 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR05
U 1 1 5D1E9E31
P 9500 2350
F 0 "#PWR05" H 9500 2200 50  0001 C CNN
F 1 "+5V" H 9515 2523 50  0000 C CNN
F 2 "" H 9500 2350 50  0001 C CNN
F 3 "" H 9500 2350 50  0001 C CNN
	1    9500 2350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J1
U 1 1 5D1EB185
P 9750 1400
F 0 "J1" H 9830 1392 50  0000 L CNN
F 1 "Programming Header" H 9830 1301 50  0000 L CNN
F 2 "" H 9750 1400 50  0001 C CNN
F 3 "~" H 9750 1400 50  0001 C CNN
	1    9750 1400
	1    0    0    -1  
$EndComp
Text GLabel 9550 1200 0    50   Input ~ 0
PMCLR
$Comp
L power:+3.3V #PWR013
U 1 1 5D1EE46F
P 9100 1200
F 0 "#PWR013" H 9100 1050 50  0001 C CNN
F 1 "+3.3V" H 9115 1373 50  0000 C CNN
F 2 "" H 9100 1200 50  0001 C CNN
F 3 "" H 9100 1200 50  0001 C CNN
	1    9100 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5D1EF94D
P 9100 1450
F 0 "#PWR014" H 9100 1200 50  0001 C CNN
F 1 "GND" H 9105 1277 50  0000 C CNN
F 2 "" H 9100 1450 50  0001 C CNN
F 3 "" H 9100 1450 50  0001 C CNN
	1    9100 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 1300 9100 1300
Wire Wire Line
	9100 1300 9100 1200
Wire Wire Line
	9550 1400 9100 1400
Wire Wire Line
	9100 1400 9100 1450
Text GLabel 9550 1500 0    50   Input ~ 0
PGED
Text GLabel 9550 1600 0    50   Input ~ 0
PDEC
$Comp
L power:GND #PWR015
U 1 1 5D1F1BB9
P 9550 1700
F 0 "#PWR015" H 9550 1450 50  0001 C CNN
F 1 "GND" H 9555 1527 50  0000 C CNN
F 2 "" H 9550 1700 50  0001 C CNN
F 3 "" H 9550 1700 50  0001 C CNN
	1    9550 1700
	1    0    0    -1  
$EndComp
Text GLabel 4850 2600 2    50   Input ~ 0
PGED
Text GLabel 4850 2500 2    50   Input ~ 0
PDEC
Text GLabel 4850 3400 2    50   Input ~ 0
CAN_TX
Text GLabel 4850 3500 2    50   Input ~ 0
CAN_RX
Text GLabel 4850 3600 2    50   Input ~ 0
CAN_STBY
Text GLabel 4850 3000 2    50   Input ~ 0
PMON_UART_RX
Text GLabel 4850 3100 2    50   Input ~ 0
PMON_UART_TX
Text GLabel 1700 1800 0    50   Input ~ 0
PMCLR
Wire Wire Line
	1700 1800 1850 1800
$Comp
L Microchip_MCUs:dsPIC33EP32GP502_QFN U?
U 1 1 5D1D3BA4
P 2450 3900
F 0 "U?" H 2306 5046 50  0000 R CNN
F 1 "dsPIC33EP32GP502_QFN" H 2306 4955 50  0000 R CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_6x6mm_P0.65mm_EP4.25x4.25mm_ThermalVias" H 2900 6550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/70000657H.pdf" H 2900 6550 50  0001 C CNN
	1    2450 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1500 3500 1600
Wire Wire Line
	3650 1100 3650 1600
$EndSCHEMATC
