EESchema Schematic File Version 4
LIBS:PowerSenseModule-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Power Sense Module - Main Page and Power"
Date ""
Rev ""
Comp "University of Central Florida - HKN Zeta Chi"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1950 2800 1200 2800
Wire Wire Line
	1400 2600 1200 2600
Wire Wire Line
	1400 2700 1200 2700
Connection ~ 1400 2900
Wire Wire Line
	1400 2700 1400 2900
Wire Wire Line
	1200 2900 1400 2900
Wire Wire Line
	1400 2900 1400 3500
$Comp
L power:GND #PWR01
U 1 1 5D342EEF
P 1400 3500
F 0 "#PWR01" H 1400 3250 50  0001 C CNN
F 1 "GND" H 1405 3327 50  0000 C CNN
F 2 "" H 1400 3500 50  0001 C CNN
F 3 "" H 1400 3500 50  0001 C CNN
	1    1400 3500
	1    0    0    -1  
$EndComp
Text Notes 525  2925 0    50   ~ 0
Neutral_OUT
Text Notes 650  2900 0    50   ~ 0
Live_OUT\n\n
Text Notes 550  2700 0    50   ~ 0
Neutral_IN\n
Text Notes 700  2600 0    50   ~ 0
Live_IN\n
$Comp
L power:GNDD #PWR013
U 1 1 5D401FC5
P 10750 900
F 0 "#PWR013" H 10750 650 50  0001 C CNN
F 1 "GNDD" H 10754 745 50  0000 C CNN
F 2 "" H 10750 900 50  0001 C CNN
F 3 "" H 10750 900 50  0001 C CNN
	1    10750 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR014
U 1 1 5D40268A
P 11000 900
F 0 "#PWR014" H 11000 650 50  0001 C CNN
F 1 "GNDA" H 11005 727 50  0000 C CNN
F 2 "" H 11000 900 50  0001 C CNN
F 3 "" H 11000 900 50  0001 C CNN
	1    11000 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	11000 900  11000 800 
Wire Wire Line
	11000 800  10850 800 
$Comp
L power:GND #PWR012
U 1 1 5D405EBA
P 10500 900
F 0 "#PWR012" H 10500 650 50  0001 C CNN
F 1 "GND" H 10505 727 50  0000 C CNN
F 2 "" H 10500 900 50  0001 C CNN
F 3 "" H 10500 900 50  0001 C CNN
	1    10500 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 900  10500 800 
Wire Wire Line
	10500 800  10650 800 
Text Notes 1925 6425 0    59   ~ 0
NOTES
Text Notes 2025 6775 0    39   ~ 0
The grounds should have their own planes and the power, digital, and analog sections should tried to be kept separate - different regions of the board
Text Notes 2025 6925 0    39   ~ 0
Bypass capacitors need to be placed close to the IC and must be physically between the power and IC\n
Text Notes 2025 7075 0    39   ~ 0
The TVS (zener) diodes need to be placed physically before the capacitors and before any connections to power sensor\n
Text Notes 2025 6625 0    39   ~ 0
The different grounds should only be connected at one junction using the net tie
Text Notes 2025 7225 0    39   ~ 0
Temp IC should be close to the power sensor\n
Wire Wire Line
	1400 1550 1400 2600
Wire Wire Line
	3700 2300 3950 2300
Connection ~ 3700 2300
Wire Wire Line
	3700 2400 3700 2300
$Comp
L power:GND #PWR03
U 1 1 5D359FFF
P 3700 2400
F 0 "#PWR03" H 3700 2150 50  0001 C CNN
F 1 "GND" H 3705 2227 50  0000 C CNN
F 2 "" H 3700 2400 50  0001 C CNN
F 3 "" H 3700 2400 50  0001 C CNN
	1    3700 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2300 3450 2300
Connection ~ 3000 2300
Wire Wire Line
	3000 2100 3000 2300
Wire Wire Line
	3450 2300 3700 2300
Connection ~ 3450 2300
Wire Wire Line
	3450 2100 3450 2300
Wire Wire Line
	3950 2300 4400 2300
Connection ~ 3950 2300
Wire Wire Line
	3950 2100 3950 2300
Wire Wire Line
	4400 2300 4850 2300
Connection ~ 4400 2300
Wire Wire Line
	4400 2100 4400 2300
Wire Wire Line
	4850 2300 4850 2100
Wire Wire Line
	2550 2300 3000 2300
Wire Wire Line
	2550 2100 2550 2300
Wire Wire Line
	4850 1550 5500 1550
Connection ~ 4850 1550
Wire Wire Line
	4850 1800 4850 1550
Wire Wire Line
	4400 1550 4850 1550
Connection ~ 4400 1550
Wire Wire Line
	3950 1550 4400 1550
Wire Wire Line
	4400 1800 4400 1550
Connection ~ 3950 1550
Wire Wire Line
	3950 1800 3950 1550
Wire Wire Line
	3450 1550 3950 1550
Connection ~ 3450 1550
Wire Wire Line
	3450 1800 3450 1550
Wire Wire Line
	3000 1550 3450 1550
Connection ~ 3000 1550
Wire Wire Line
	3000 1800 3000 1550
Wire Wire Line
	2550 1550 3000 1550
Connection ~ 2550 1550
Wire Wire Line
	2550 1800 2550 1550
Wire Wire Line
	6900 1550 6900 1850
Connection ~ 6900 1550
Wire Wire Line
	6700 1550 6900 1550
Wire Wire Line
	6900 1550 7650 1550
Wire Wire Line
	6900 2150 6900 2250
Wire Wire Line
	6900 2250 5800 2250
Wire Wire Line
	7650 1900 7650 1950
Connection ~ 7650 1950
Wire Wire Line
	7650 1950 7300 1950
Wire Wire Line
	7300 1950 7300 1750
Wire Wire Line
	7300 1750 6700 1750
Wire Wire Line
	7650 1950 7650 2000
$Comp
L power:GND #PWR06
U 1 1 5D354DD4
P 7650 2300
F 0 "#PWR06" H 7650 2050 50  0001 C CNN
F 1 "GND" H 7655 2127 50  0000 C CNN
F 2 "" H 7650 2300 50  0001 C CNN
F 3 "" H 7650 2300 50  0001 C CNN
	1    7650 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1800 8200 1550
Connection ~ 8200 1550
$Comp
L power:GND #PWR08
U 1 1 5D36B6A5
P 8200 2300
F 0 "#PWR08" H 8200 2050 50  0001 C CNN
F 1 "GND" H 8205 2127 50  0000 C CNN
F 2 "" H 8200 2300 50  0001 C CNN
F 3 "" H 8200 2300 50  0001 C CNN
	1    8200 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2300 8200 2100
Wire Wire Line
	7650 1550 7650 1600
Connection ~ 7650 1550
Wire Wire Line
	8200 1550 7650 1550
Text Notes 5550 2650 0    35   ~ 0
1mOhm ESR\n\n
$Comp
L power:GND #PWR04
U 1 1 5D34E109
P 5500 2600
F 0 "#PWR04" H 5500 2350 50  0001 C CNN
F 1 "GND" H 5505 2427 50  0000 C CNN
F 2 "" H 5500 2600 50  0001 C CNN
F 3 "" H 5500 2600 50  0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1950 5900 1950
Wire Wire Line
	5500 2300 5500 1950
Wire Wire Line
	5800 1850 5900 1850
Wire Wire Line
	5800 2250 5800 1850
Wire Wire Line
	5800 1550 5800 1750
Connection ~ 5800 1550
Wire Wire Line
	5800 1550 5900 1550
Wire Wire Line
	5800 1750 5900 1750
Text Notes 2650 1400 0    35   ~ 0
ceramic, 2mOhm ESR\n
Wire Wire Line
	8200 1350 8200 1550
$Comp
L power:+5V #PWR07
U 1 1 5D35D5EE
P 8200 1350
F 0 "#PWR07" H 8200 1200 50  0001 C CNN
F 1 "+5V" H 8215 1523 50  0000 C CNN
F 2 "" H 8200 1350 50  0001 C CNN
F 3 "" H 8200 1350 50  0001 C CNN
	1    8200 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5D34E632
P 6300 2450
F 0 "#PWR05" H 6300 2200 50  0001 C CNN
F 1 "GND" H 6305 2277 50  0000 C CNN
F 2 "" H 6300 2450 50  0001 C CNN
F 3 "" H 6300 2450 50  0001 C CNN
	1    6300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2150 6300 2450
$Sheet
S 3150 3800 1700 1550
U 5D226D6E
F0 "MCU and CAN" 50
F1 "MCU.sch" 50
F2 "CANH" T L 3150 4500 50 
F3 "CANL" T L 3150 4650 50 
F4 "MEASURE_IN" I L 3150 3975 50 
F5 "MEASURE_OUT" I L 3150 4150 50 
F6 "PWM" O R 4850 3975 50 
$EndSheet
$Comp
L power:+12V #PWR09
U 1 1 5D5198D9
P 5500 1300
F 0 "#PWR09" H 5500 1150 50  0001 C CNN
F 1 "+12V" H 5515 1473 50  0000 C CNN
F 2 "" H 5500 1300 50  0001 C CNN
F 3 "" H 5500 1300 50  0001 C CNN
	1    5500 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1550 2200 3975
Wire Wire Line
	2200 3975 3150 3975
Connection ~ 2200 1550
Wire Wire Line
	3150 4150 1950 4150
Wire Wire Line
	1950 4150 1950 2800
Wire Wire Line
	3150 4500 1750 4500
Wire Wire Line
	1750 4500 1750 3000
Wire Wire Line
	1750 3000 1200 3000
Wire Wire Line
	3150 4650 1625 4650
Wire Wire Line
	1625 4650 1625 3100
Wire Wire Line
	1625 3100 1200 3100
Text Notes 675  3025 0    50   ~ 0
CAN_HI\n
Text Notes 675  3125 0    50   ~ 0
CAN_LO
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 5D4A20AB
P 1000 2800
F 0 "J1" H 1108 3181 50  0000 C CNN
F 1 "Conn_01x06_Male" H 1108 3090 50  0000 C CNN
F 2 "Connector_TE:DT13-6P" H 1000 2800 50  0001 C CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7FDT13-4P%7FC%7Fpdf%7FEnglish%7FENG_CD_DT13-4P_C.pdf%7FDT13-4P" H 1000 2800 50  0001 C CNN
	1    1000 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C6
U 1 1 5D3208C5
P 4850 1950
F 0 "C6" H 4965 1996 50  0000 L CNN
F 1 "47uF" H 4965 1905 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 4888 1800 50  0001 C CNN
F 3 "~" H 4850 1950 50  0001 C CNN
	1    4850 1950
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Switching:TPS82150 U1
U 1 1 5D32B50B
P 6300 1750
F 0 "U1" H 6300 2217 50  0000 C CNN
F 1 "TPS82150" H 6300 2126 50  0000 C CNN
F 2 "Package_LGA:Texas_SIL0008D_MicroSiP-8-1EP_2.8x3mm_P0.65mm_EP1.1x1.9mm" H 6300 1100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps82150.pdf" H 6300 1000 50  0001 C CNN
F 4 "TI" H 6300 1750 50  0001 C CNN "Manufacturer"
F 5 "TPS82150SILR " H 6300 1750 50  0001 C CNN "Manufacturer PN"
F 6 "3.03" H 6300 1750 50  0001 C CNN "Price 1 QTY"
F 7 "Mouser" H 6300 1750 50  0001 C CNN "Supplier"
F 8 "https://www.mouser.com/ProductDetail/?qs=gt1LBUVyoHksxpRVOmIIkg%3D%3D" H 6300 1750 50  0001 C CNN "Supplier Link"
F 9 " 595-TPS82150SILR " H 6300 1750 50  0001 C CNN "Supplier PN"
	1    6300 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5D33425E
P 5500 2450
F 0 "C7" H 5615 2496 50  0000 L CNN
F 1 "470p" H 5615 2405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5538 2300 50  0001 C CNN
F 3 "~" H 5500 2450 50  0001 C CNN
	1    5500 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C8
U 1 1 5D369605
P 8200 1950
F 0 "C8" H 8315 1996 50  0000 L CNN
F 1 "47uF" H 8315 1905 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 8238 1800 50  0001 C CNN
F 3 "~" H 8200 1950 50  0001 C CNN
	1    8200 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5D350E98
P 7650 2150
F 0 "R3" H 7718 2196 50  0000 L CNN
F 1 "100k" H 7718 2105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7690 2140 50  0001 C CNN
F 3 "~" H 7650 2150 50  0001 C CNN
	1    7650 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5D350393
P 7650 1750
F 0 "R2" H 7718 1796 50  0000 L CNN
F 1 "523k" H 7718 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7690 1740 50  0001 C CNN
F 3 "~" H 7650 1750 50  0001 C CNN
	1    7650 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5D32FCBE
P 6900 2000
F 0 "R1" H 6968 2046 50  0000 L CNN
F 1 "100k" H 6968 1955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6940 1990 50  0001 C CNN
F 3 "~" H 6900 2000 50  0001 C CNN
	1    6900 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5D3344CE
P 4400 1950
F 0 "C5" H 4515 1996 50  0000 L CNN
F 1 "4.7uF" H 4515 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4438 1800 50  0001 C CNN
F 3 "~" H 4400 1950 50  0001 C CNN
	1    4400 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5D334C90
P 3950 1950
F 0 "C4" H 4065 1996 50  0000 L CNN
F 1 "0.1uF" H 4065 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3988 1800 50  0001 C CNN
F 3 "~" H 3950 1950 50  0001 C CNN
	1    3950 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5D334CE0
P 3450 1950
F 0 "C3" H 3565 1996 50  0000 L CNN
F 1 "0.01uF" H 3565 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3488 1800 50  0001 C CNN
F 3 "~" H 3450 1950 50  0001 C CNN
	1    3450 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5D335009
P 3000 1950
F 0 "C2" H 3115 1996 50  0000 L CNN
F 1 "470pF" H 3115 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3038 1800 50  0001 C CNN
F 3 "~" H 3000 1950 50  0001 C CNN
	1    3000 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D33534D
P 2550 1950
F 0 "C1" H 2665 1996 50  0000 L CNN
F 1 "4.7pF" H 2665 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2588 1800 50  0001 C CNN
F 3 "~" H 2550 1950 50  0001 C CNN
	1    2550 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_3_Tee NT1
U 1 1 5D4008D3
P 10750 800
F 0 "NT1" H 10750 981 50  0000 C CNN
F 1 "Net-Tie_3_Tee" H 10750 890 50  0000 C CNN
F 2 "NetTie:NetTie-3_SMD_Pad2.0mm" H 10750 800 50  0001 C CNN
F 3 "~" H 10750 800 50  0001 C CNN
	1    10750 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1550 1775 1550
$Comp
L Device:D_Zener D1
U 1 1 5DEFEB23
P 1775 1800
F 0 "D1" V 1729 1879 50  0000 L CNN
F 1 "SD05-7" V 1820 1879 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 1775 1800 50  0001 C CNN
F 3 "https://www.mouser.com/ProductDetail/Diodes-Incorporated/SD05-7?qs=%2Fha2pyFadugD%2Fr1MYEydUCcSjftG2Vlq5z2%2Fe2tdzfA%3D" H 1775 1800 50  0001 C CNN
	1    1775 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	1775 1650 1775 1550
Connection ~ 1775 1550
Wire Wire Line
	1775 1550 2200 1550
$Comp
L power:GND #PWR02
U 1 1 5DF00A75
P 1775 2025
F 0 "#PWR02" H 1775 1775 50  0001 C CNN
F 1 "GND" H 1780 1852 50  0000 C CNN
F 2 "" H 1775 2025 50  0001 C CNN
F 3 "" H 1775 2025 50  0001 C CNN
	1    1775 2025
	1    0    0    -1  
$EndComp
Wire Wire Line
	1775 2025 1775 1950
$Comp
L Device:D D2
U 1 1 5E37B877
P 7300 4175
F 0 "D2" H 7300 3959 50  0000 C CNN
F 1 "D" H 7300 4050 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 7300 4175 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 7300 4175 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 7300 4175 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 7300 4175 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 7300 4175 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 7300 4175 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 7300 4175 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 7300 4175 50  0001 C CNN "Supplier PN"
	1    7300 4175
	-1   0    0    1   
$EndComp
$Comp
L Device:D D5
U 1 1 5E37C9F3
P 7825 4175
F 0 "D5" H 7825 3959 50  0000 C CNN
F 1 "D" H 7825 4050 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 7825 4175 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 7825 4175 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 7825 4175 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 7825 4175 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 7825 4175 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 7825 4175 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 7825 4175 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 7825 4175 50  0001 C CNN "Supplier PN"
	1    7825 4175
	-1   0    0    1   
$EndComp
$Comp
L Device:C C20
U 1 1 5E37E7E2
P 8150 4400
F 0 "C20" H 8265 4446 50  0000 L CNN
F 1 "0.1uF" H 8265 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8188 4250 50  0001 C CNN
F 3 "~" H 8150 4400 50  0001 C CNN
	1    8150 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C19
U 1 1 5E37E843
P 7575 4400
F 0 "C19" H 7690 4446 50  0000 L CNN
F 1 "0.1uF" H 7690 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7613 4250 50  0001 C CNN
F 3 "~" H 7575 4400 50  0001 C CNN
	1    7575 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7575 4250 7575 4175
Wire Wire Line
	7575 4175 7450 4175
Wire Wire Line
	7575 4175 7675 4175
Connection ~ 7575 4175
Wire Wire Line
	8150 4250 8150 4175
Wire Wire Line
	8150 4175 7975 4175
Wire Wire Line
	7150 4175 7050 4175
Wire Wire Line
	7050 4175 7050 4075
$Comp
L power:+12V #PWR010
U 1 1 5E389ACF
P 7050 4075
F 0 "#PWR010" H 7050 3925 50  0001 C CNN
F 1 "+12V" H 7065 4248 50  0000 C CNN
F 2 "" H 7050 4075 50  0001 C CNN
F 3 "" H 7050 4075 50  0001 C CNN
	1    7050 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	7575 4550 7575 4900
$Comp
L power:GNDA #PWR022
U 1 1 5E38CDB2
P 8150 4575
F 0 "#PWR022" H 8150 4325 50  0001 C CNN
F 1 "GNDA" H 8155 4402 50  0000 C CNN
F 2 "" H 8150 4575 50  0001 C CNN
F 3 "" H 8150 4575 50  0001 C CNN
	1    8150 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 4575 8150 4550
$Comp
L Device:D D6
U 1 1 5E394EB5
P 8450 4175
F 0 "D6" H 8450 3959 50  0000 C CNN
F 1 "D" H 8450 4050 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 8450 4175 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 8450 4175 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 8450 4175 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 8450 4175 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 8450 4175 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 8450 4175 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 8450 4175 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 8450 4175 50  0001 C CNN "Supplier PN"
	1    8450 4175
	-1   0    0    1   
$EndComp
$Comp
L Device:D D7
U 1 1 5E394EBB
P 8975 4175
F 0 "D7" H 8975 3959 50  0000 C CNN
F 1 "D" H 8975 4050 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 8975 4175 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 8975 4175 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 8975 4175 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 8975 4175 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 8975 4175 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 8975 4175 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 8975 4175 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 8975 4175 50  0001 C CNN "Supplier PN"
	1    8975 4175
	-1   0    0    1   
$EndComp
$Comp
L Device:C C22
U 1 1 5E394EC1
P 9300 4400
F 0 "C22" H 9415 4446 50  0000 L CNN
F 1 "0.1uF" H 9415 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9338 4250 50  0001 C CNN
F 3 "~" H 9300 4400 50  0001 C CNN
	1    9300 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C21
U 1 1 5E394EC7
P 8725 4400
F 0 "C21" H 8840 4446 50  0000 L CNN
F 1 "0.1uF" H 8840 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8763 4250 50  0001 C CNN
F 3 "~" H 8725 4400 50  0001 C CNN
	1    8725 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8725 4250 8725 4175
Wire Wire Line
	8725 4175 8600 4175
Wire Wire Line
	8725 4175 8825 4175
Connection ~ 8725 4175
Wire Wire Line
	9300 4250 9300 4175
Wire Wire Line
	9300 4175 9125 4175
$Comp
L power:GNDA #PWR027
U 1 1 5E394ED5
P 9300 4575
F 0 "#PWR027" H 9300 4325 50  0001 C CNN
F 1 "GNDA" H 9305 4402 50  0000 C CNN
F 2 "" H 9300 4575 50  0001 C CNN
F 3 "" H 9300 4575 50  0001 C CNN
	1    9300 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 4575 9300 4550
Wire Wire Line
	8300 4175 8150 4175
Connection ~ 8150 4175
Wire Wire Line
	8725 4900 7575 4900
Wire Wire Line
	8725 4550 8725 4900
Connection ~ 7575 4900
Wire Wire Line
	7575 4900 7050 4900
Wire Wire Line
	9300 4175 9800 4175
Connection ~ 9300 4175
$Comp
L power:VS #PWR034
U 1 1 5E3A54BD
P 9925 4075
F 0 "#PWR034" H 9725 3925 50  0001 C CNN
F 1 "VS" H 9942 4248 50  0000 C CNN
F 2 "" H 9925 4075 50  0001 C CNN
F 3 "" H 9925 4075 50  0001 C CNN
	1    9925 4075
	1    0    0    -1  
$EndComp
Wire Wire Line
	9925 4075 9925 4175
Text Notes 10050 4700 0    50   ~ 0
Unloaded +22V out\n
Wire Wire Line
	5500 1300 5500 1550
Connection ~ 5500 1550
Wire Wire Line
	5500 1550 5800 1550
Wire Wire Line
	2200 1550 2550 1550
$Comp
L Device:CP C23
U 1 1 5E3BD7DC
P 9800 4400
F 0 "C23" H 9918 4446 50  0000 L CNN
F 1 "4.7uF" H 9918 4355 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 9838 4250 50  0001 C CNN
F 3 "~" H 9800 4400 50  0001 C CNN
	1    9800 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 4250 9800 4175
Connection ~ 9800 4175
Wire Wire Line
	9800 4175 9925 4175
$Comp
L power:GNDA #PWR029
U 1 1 5E3C0B37
P 9800 4600
F 0 "#PWR029" H 9800 4350 50  0001 C CNN
F 1 "GNDA" H 9805 4427 50  0000 C CNN
F 2 "" H 9800 4600 50  0001 C CNN
F 3 "" H 9800 4600 50  0001 C CNN
	1    9800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 4600 9800 4550
Text Label 7050 4900 2    50   ~ 0
PWM
Text Label 5075 3975 0    50   ~ 0
PWM
Wire Wire Line
	5075 3975 4850 3975
Text Notes 10050 4875 0    50   ~ 0
35 to 50V cap and diode \nrating\n
$EndSCHEMATC
