EESchema Schematic File Version 4
LIBS:PowerSenseModule-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Power Sense Module - MCU"
Date ""
Rev "1.0"
Comp "University of Central Florida - HKN Zeta Chi"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3500 6850 0    50   ~ 0
Close to VDD TX pin\n
$Comp
L power:+5V #PWR021
U 1 1 5D44F50B
P 1250 6825
F 0 "#PWR021" H 1250 6675 50  0001 C CNN
F 1 "+5V" H 1265 6998 50  0000 C CNN
F 2 "" H 1250 6825 50  0001 C CNN
F 3 "" H 1250 6825 50  0001 C CNN
	1    1250 6825
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 1400 3275 1500
Wire Wire Line
	1925 1900 1725 1900
$Comp
L Interface_CAN_LIN:MCP2542FDxMF U4
U 1 1 5D33FB36
P 1625 5400
F 0 "U4" H 1275 5050 50  0000 C CNN
F 1 "MCP2542FDxMF" H 2075 5000 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 1625 4900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/MCP2542FD-4FD-MCP2542WFD-4WFD-Data-Sheet20005514B.pdf" H 1625 5400 50  0001 C CNN
F 4 "Microchip" H 1625 5400 50  0001 C CNN "Manufacturer"
F 5 "MCP2542FD-H/SN" H 1625 5400 50  0001 C CNN "Manufacturer PN"
F 6 "0.79" H 1625 5400 50  0001 C CNN "Price 1 QTY"
F 7 "Mouser" H 1625 5400 50  0001 C CNN "Supplier"
F 8 "https://www.mouser.com/ProductDetail/Microchip-Technology/MCP2542FD-H-SN?qs=sGAEpiMZZMsGqoCZrYwANkPccAfLmAxJzMSmRhEMflk%3D" H 1625 5400 50  0001 C CNN "Supplier Link"
F 9 " 579-MCP2542FD-H/SN " H 1625 5400 50  0001 C CNN "Supplier PN"
	1    1625 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR031
U 1 1 5D3FDEC2
P 1625 5800
F 0 "#PWR031" H 1625 5550 50  0001 C CNN
F 1 "GNDD" H 1625 5650 50  0000 C CNN
F 2 "" H 1625 5800 50  0001 C CNN
F 3 "" H 1625 5800 50  0001 C CNN
	1    1625 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR018
U 1 1 5D3FC142
P 1225 2530
F 0 "#PWR018" H 1225 2280 50  0001 C CNN
F 1 "GNDD" H 1229 2375 50  0000 C CNN
F 2 "" H 1225 2530 50  0001 C CNN
F 3 "" H 1225 2530 50  0001 C CNN
	1    1225 2530
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR025
U 1 1 5D3FBC0D
P 3675 1100
F 0 "#PWR025" H 3675 850 50  0001 C CNN
F 1 "GNDD" H 3679 945 50  0000 C CNN
F 2 "" H 3675 1100 50  0001 C CNN
F 3 "" H 3675 1100 50  0001 C CNN
	1    3675 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR016
U 1 1 5D3FB889
P 1250 7125
F 0 "#PWR016" H 1250 6875 50  0001 C CNN
F 1 "GNDD" H 1254 6970 50  0000 C CNN
F 2 "" H 1250 7125 50  0001 C CNN
F 3 "" H 1250 7125 50  0001 C CNN
	1    1250 7125
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR020
U 1 1 5D3FABB0
P 3400 7200
F 0 "#PWR020" H 3400 6950 50  0001 C CNN
F 1 "GNDD" H 3404 7045 50  0000 C CNN
F 2 "" H 3400 7200 50  0001 C CNN
F 3 "" H 3400 7200 50  0001 C CNN
	1    3400 7200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR028
U 1 1 5D3C46D6
P 7075 5800
F 0 "#PWR028" H 7075 5550 50  0001 C CNN
F 1 "GNDD" H 7079 5645 50  0000 C CNN
F 2 "" H 7075 5800 50  0001 C CNN
F 3 "" H 7075 5800 50  0001 C CNN
	1    7075 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 5175 7125 5175
Wire Wire Line
	7075 5675 7075 5800
Connection ~ 7075 5675
Wire Wire Line
	7075 5375 7075 5675
Text HLabel 2700 5550 2    50   Input ~ 0
CANL
Text HLabel 2700 5250 2    50   Input ~ 0
CANH
Wire Wire Line
	3125 1300 3125 1500
Wire Wire Line
	1175 1900 1225 1900
Wire Wire Line
	7075 5275 7075 5025
Wire Wire Line
	7125 5275 7075 5275
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 5D1EB185
P 7325 5375
F 0 "J3" H 7405 5367 50  0000 L CNN
F 1 "Programming Header" H 7405 5276 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 7325 5375 50  0001 C CNN
F 3 "~" H 7325 5375 50  0001 C CNN
	1    7325 5375
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5D1E9E31
P 3400 6900
F 0 "#PWR019" H 3400 6750 50  0001 C CNN
F 1 "+5V" H 3415 7073 50  0000 C CNN
F 2 "" H 3400 6900 50  0001 C CNN
F 3 "" H 3400 6900 50  0001 C CNN
	1    3400 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5D1E97D6
P 3900 7050
F 0 "C14" H 4015 7096 50  0000 L CNN
F 1 "0.1uF" H 4015 7005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3938 6900 50  0001 C CNN
F 3 "~" H 3900 7050 50  0001 C CNN
	1    3900 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 7200 3900 7200
Wire Wire Line
	3400 7200 3600 7200
Connection ~ 3600 7200
Wire Wire Line
	3600 6900 3900 6900
Wire Wire Line
	3400 6900 3600 6900
Connection ~ 3600 6900
$Comp
L Device:C C13
U 1 1 5D1E97D0
P 3600 7050
F 0 "C13" H 3400 7100 50  0000 L CNN
F 1 "0.01uF" H 3250 7000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3638 6900 50  0001 C CNN
F 3 "~" H 3600 7050 50  0001 C CNN
	1    3600 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5D1BE43C
P 1750 6975
F 0 "C11" H 1865 7021 50  0000 L CNN
F 1 "0.1uF" H 1865 6930 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1788 6825 50  0001 C CNN
F 3 "~" H 1750 6975 50  0001 C CNN
	1    1750 6975
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 7125 1750 7125
Wire Wire Line
	1250 7125 1450 7125
Connection ~ 1450 7125
Wire Wire Line
	1450 6825 1750 6825
Wire Wire Line
	1250 6825 1450 6825
Connection ~ 1450 6825
$Comp
L Device:C C10
U 1 1 5D1BE442
P 1450 6975
F 0 "C10" H 1175 7025 50  0000 L CNN
F 1 "0.01uF" H 1100 6925 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1488 6825 50  0001 C CNN
F 3 "~" H 1450 6975 50  0001 C CNN
	1    1450 6975
	1    0    0    -1  
$EndComp
Text Notes 1500 6725 0    50   ~ 0
Close to VDD MCU pin\n
Wire Wire Line
	2250 5500 2250 5550
Wire Wire Line
	2125 5500 2250 5500
Wire Wire Line
	2250 5300 2250 5250
Wire Wire Line
	2125 5300 2250 5300
Wire Wire Line
	2425 5550 2700 5550
Wire Wire Line
	2250 5550 2425 5550
Connection ~ 2425 5550
Wire Wire Line
	2425 5250 2700 5250
Wire Wire Line
	2250 5250 2425 5250
Connection ~ 2425 5250
$Comp
L Device:R_US R7
U 1 1 5D1D5ACD
P 2425 5400
F 0 "R7" H 2493 5446 50  0000 L CNN
F 1 "120" H 2493 5355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2465 5390 50  0001 C CNN
F 3 "~" H 2425 5400 50  0001 C CNN
	1    2425 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR030
U 1 1 5D1D3CD9
P 1575 5000
F 0 "#PWR030" H 1575 4850 50  0001 C CNN
F 1 "+5V" H 1625 5150 50  0000 C CNN
F 2 "" H 1575 5000 50  0001 C CNN
F 3 "" H 1575 5000 50  0001 C CNN
	1    1575 5000
	1    0    0    -1  
$EndComp
Text Notes 500  2795 0    50   ~ 0
Capacitor disconnected when programming\n
Wire Wire Line
	1225 2000 1225 1900
$Comp
L Device:Jumper_NO_Small JP1
U 1 1 5D1B8B21
P 1225 2100
F 0 "JP1" V 1175 1900 50  0000 L CNN
F 1 "Jumper_NO_Small" V 1275 1400 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1225 2100 50  0001 C CNN
F 3 "~" H 1225 2100 50  0001 C CNN
	1    1225 2100
	0    1    1    0   
$EndComp
Connection ~ 1225 1900
Wire Wire Line
	1225 1900 1425 1900
Wire Wire Line
	1225 1800 1225 1900
$Comp
L Device:R_US R5
U 1 1 5D1B85DD
P 1575 1900
F 0 "R5" H 1643 1946 50  0000 L CNN
F 1 "470" H 1643 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1615 1890 50  0001 C CNN
F 3 "~" H 1575 1900 50  0001 C CNN
	1    1575 1900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R4
U 1 1 5D1B51D5
P 1225 1650
F 0 "R4" H 1293 1696 50  0000 L CNN
F 1 "10k" H 1293 1605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1265 1640 50  0001 C CNN
F 3 "~" H 1225 1650 50  0001 C CNN
	1    1225 1650
	1    0    0    -1  
$EndComp
Text Notes 3375 1400 0    50   ~ 0
tantalum, < 1 Ohm ESR\n
Wire Wire Line
	2975 1050 2975 1300
Wire Wire Line
	2975 1300 2975 1500
Connection ~ 2975 1300
Wire Wire Line
	3125 1300 2975 1300
$Comp
L Device:CP1 C15
U 1 1 5D1B11E5
P 3275 1250
F 0 "C15" H 3160 1204 50  0000 R CNN
F 1 "10uF" H 3160 1295 50  0000 R CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 3275 1250 50  0001 C CNN
F 3 "~" H 3275 1250 50  0001 C CNN
	1    3275 1250
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR026
U 1 1 5D514FF2
P 3125 4350
F 0 "#PWR026" H 3125 4100 50  0001 C CNN
F 1 "GNDD" H 3129 4195 50  0000 C CNN
F 2 "" H 3125 4350 50  0001 C CNN
F 3 "" H 3125 4350 50  0001 C CNN
	1    3125 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR024
U 1 1 5D516C00
P 2825 4350
F 0 "#PWR024" H 2825 4100 50  0001 C CNN
F 1 "GNDA" H 2830 4177 50  0000 C CNN
F 2 "" H 2825 4350 50  0001 C CNN
F 3 "" H 2825 4350 50  0001 C CNN
	1    2825 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2825 4150 2825 4350
Wire Wire Line
	3125 4225 3125 4350
Wire Wire Line
	6900 5475 7125 5475
Wire Wire Line
	6900 5575 7125 5575
$Comp
L Device:R_Small_US R8
U 1 1 5D498F82
P 7025 2000
F 0 "R8" H 7093 2046 50  0000 L CNN
F 1 "4m" H 7093 1955 50  0000 L CNN
F 2 "Resistor_SMD:R_4020_10251Metric_Pad1.65x5.30mm_HandSolder" H 7025 2000 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/427/wslp3921-536393.pdf" H 7025 2000 50  0001 C CNN
F 4 "Vishay" H 7025 2000 50  0001 C CNN "Manufacturer"
F 5 "WSLP39214L000FEB " H 7025 2000 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 7025 2000 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/Vishay-Dale/WSLP39214L000FEB?qs=sGAEpiMZZMtlleCFQhR%2FzQgA6HzdQSfq2cZRquULrVo%3D" H 7025 2000 50  0001 C CNN "Supplier Link"
F 8 " 71- 71-WSLP39214L000FEB " H 7025 2000 50  0001 C CNN "Supplier PN"
	1    7025 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 5D49A156
P 7025 1550
F 0 "R6" H 7093 1596 50  0000 L CNN
F 1 "0" H 7093 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7025 1550 50  0001 C CNN
F 3 "~" H 7025 1550 50  0001 C CNN
	1    7025 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R9
U 1 1 5D49A4A2
P 7025 2450
F 0 "R9" H 7093 2496 50  0000 L CNN
F 1 "0" H 7093 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7025 2450 50  0001 C CNN
F 3 "~" H 7025 2450 50  0001 C CNN
	1    7025 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7025 1650 7025 1750
Wire Wire Line
	7025 2100 7025 2250
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 5D49D215
P 6175 1950
F 0 "J4" H 6283 2131 50  0000 C CNN
F 1 "Conn_01x02_Male" H 6283 2040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6175 1950 50  0001 C CNN
F 3 "~" H 6175 1950 50  0001 C CNN
	1    6175 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6375 1950 6675 1950
Wire Wire Line
	6675 1950 6675 1750
Wire Wire Line
	6675 1750 7025 1750
Connection ~ 7025 1750
Wire Wire Line
	7025 1750 7025 1900
Wire Wire Line
	6375 2050 6675 2050
Wire Wire Line
	6675 2050 6675 2250
Wire Wire Line
	6675 2250 7025 2250
Connection ~ 7025 2250
Wire Wire Line
	7025 2250 7025 2350
Wire Wire Line
	7025 1450 7025 1350
Wire Wire Line
	7025 2550 7025 2650
Text HLabel 7025 1350 1    50   Input ~ 0
MEASURE_IN
Text HLabel 7025 2650 3    50   Input ~ 0
MEASURE_OUT
$Comp
L F1_OP_Amps:NCV2007x U2
U 1 1 5D4B495F
P 8125 1650
F 0 "U2" H 8175 1283 50  0000 C CNN
F 1 "NCV2007x" H 8175 1374 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 8125 1300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCS20071-D.PDF" H 8125 1300 50  0001 C CNN
F 4 "ON Semiconductor" H 8125 1650 50  0001 C CNN "Manufacturer"
F 5 "NCV20074DR2G " H 8125 1650 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 8125 1650 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ON-Semiconductor/NCV20074DR2G?qs=sGAEpiMZZMtCHixnSjNA6NXlPpRsFEjtp%252BTBls3ALHY%3D" H 8125 1650 50  0001 C CNN "Supplier Link"
F 8 " 863-NCV20074DR2G " H 8125 1650 50  0001 C CNN "Supplier PN"
F 9 "1.19" H 8125 1650 50  0001 C CNN "Price 1 QTY"
	1    8125 1650
	1    0    0    1   
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 2 1 5D4B605F
P 8125 2350
F 0 "U2" H 8175 2717 50  0000 C CNN
F 1 "NCV2007x" H 8175 2626 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 8125 2000 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCS20071-D.PDF" H 8125 2000 50  0001 C CNN
F 4 "ON Semiconductor" H 8125 2350 50  0001 C CNN "Manufacturer"
F 5 "NCV20074DR2G " H 8125 2350 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 8125 2350 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ON-Semiconductor/NCV20074DR2G?qs=sGAEpiMZZMtCHixnSjNA6NXlPpRsFEjtp%252BTBls3ALHY%3D" H 8125 2350 50  0001 C CNN "Supplier Link"
F 8 " 863-NCV20074DR2G " H 8125 2350 50  0001 C CNN "Supplier PN"
F 9 "1.19" H 8125 2350 50  0001 C CNN "Price 1 QTY"
	2    8125 2350
	1    0    0    -1  
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 3 1 5D4B6BBE
P 9575 1950
F 0 "U2" H 9625 2317 50  0000 C CNN
F 1 "NCV2007x" H 9625 2226 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 9575 1600 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCS20071-D.PDF" H 9575 1600 50  0001 C CNN
F 4 "ON Semiconductor" H 9575 1950 50  0001 C CNN "Manufacturer"
F 5 "NCV20074DR2G " H 9575 1950 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 9575 1950 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ON-Semiconductor/NCV20074DR2G?qs=sGAEpiMZZMtCHixnSjNA6NXlPpRsFEjtp%252BTBls3ALHY%3D" H 9575 1950 50  0001 C CNN "Supplier Link"
F 8 " 863-NCV20074DR2G " H 9575 1950 50  0001 C CNN "Supplier PN"
F 9 "1.19" H 9575 1950 50  0001 C CNN "Price 1 QTY"
	3    9575 1950
	1    0    0    1   
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 4 1 5D4B7A85
P 9650 3400
F 0 "U2" H 9700 3767 50  0000 C CNN
F 1 "NCV2007x" H 9700 3676 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 9650 3050 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCS20071-D.PDF" H 9650 3050 50  0001 C CNN
F 4 "ON Semiconductor" H 9650 3400 50  0001 C CNN "Manufacturer"
F 5 "NCV20074DR2G " H 9650 3400 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 9650 3400 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ON-Semiconductor/NCV20074DR2G?qs=sGAEpiMZZMtCHixnSjNA6NXlPpRsFEjtp%252BTBls3ALHY%3D" H 9650 3400 50  0001 C CNN "Supplier Link"
F 8 " 863-NCV20074DR2G " H 9650 3400 50  0001 C CNN "Supplier PN"
F 9 "1.19" H 9650 3400 50  0001 C CNN "Price 1 QTY"
	4    9650 3400
	1    0    0    1   
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 5 1 5D4B8129
P 5725 7075
F 0 "U2" H 5803 7146 50  0000 L CNN
F 1 "NCV2007x" H 5803 7055 50  0000 L CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5725 6725 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCS20071-D.PDF" H 5725 6725 50  0001 C CNN
F 4 "ON Semiconductor" H 5725 7075 50  0001 C CNN "Manufacturer"
F 5 "NCV20074DR2G " H 5725 7075 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 5725 7075 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ON-Semiconductor/NCV20074DR2G?qs=sGAEpiMZZMtCHixnSjNA6NXlPpRsFEjtp%252BTBls3ALHY%3D" H 5725 7075 50  0001 C CNN "Supplier Link"
F 8 " 863-NCV20074DR2G " H 5725 7075 50  0001 C CNN "Supplier PN"
F 9 "1.19" H 5725 7075 50  0001 C CNN "Price 1 QTY"
	5    5725 7075
	1    0    0    -1  
$EndComp
Wire Wire Line
	7875 2250 7025 2250
Wire Wire Line
	7875 2450 7775 2450
Wire Wire Line
	7775 2450 7775 2600
Wire Wire Line
	7775 2600 8100 2600
Wire Wire Line
	8575 2600 8575 2350
Wire Wire Line
	8575 2350 8475 2350
Wire Wire Line
	7875 1550 7775 1550
Wire Wire Line
	7775 1550 7775 1400
Wire Wire Line
	7775 1400 8575 1400
Wire Wire Line
	8575 1400 8575 1650
Wire Wire Line
	8575 1650 8475 1650
$Comp
L Device:R_US R10
U 1 1 5D4CA065
P 8975 1850
F 0 "R10" V 8770 1850 50  0000 C CNN
F 1 "1.2k" V 8861 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9015 1840 50  0001 C CNN
F 3 "~" H 8975 1850 50  0001 C CNN
	1    8975 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R11
U 1 1 5D4CA856
P 8975 2050
F 0 "R11" V 9075 2050 50  0000 C CNN
F 1 "1.2k" V 9175 2050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9015 2040 50  0001 C CNN
F 3 "~" H 8975 2050 50  0001 C CNN
	1    8975 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R13
U 1 1 5D4CADE5
P 9625 1400
F 0 "R13" V 9420 1400 50  0000 C CNN
F 1 "75k" V 9511 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9665 1390 50  0001 C CNN
F 3 "~" H 9625 1400 50  0001 C CNN
	1    9625 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	9125 1850 9225 1850
Wire Wire Line
	9325 2050 9225 2050
$Comp
L Device:R_US R12
U 1 1 5D4D53DE
P 9225 2500
F 0 "R12" H 9293 2546 50  0000 L CNN
F 1 "75k" H 9293 2455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9265 2490 50  0001 C CNN
F 3 "~" H 9225 2500 50  0001 C CNN
	1    9225 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8825 1850 8575 1850
Wire Wire Line
	8575 1850 8575 1650
Connection ~ 8575 1650
Wire Wire Line
	8825 2050 8575 2050
Wire Wire Line
	8575 2050 8575 2350
Connection ~ 8575 2350
Wire Wire Line
	9475 1400 9225 1400
Wire Wire Line
	9225 1400 9225 1850
Connection ~ 9225 1850
Wire Wire Line
	9225 1850 9325 1850
Wire Wire Line
	9225 2350 9225 2050
Connection ~ 9225 2050
Wire Wire Line
	9225 2050 9125 2050
$Comp
L power:GNDA #PWR015
U 1 1 5D4E04FF
P 9225 2750
F 0 "#PWR015" H 9225 2500 50  0001 C CNN
F 1 "GNDA" H 9230 2577 50  0000 C CNN
F 2 "" H 9225 2750 50  0001 C CNN
F 3 "" H 9225 2750 50  0001 C CNN
	1    9225 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9225 2750 9225 2650
Wire Wire Line
	9775 1400 10025 1400
Wire Wire Line
	10025 1400 10025 1950
Wire Wire Line
	10025 1950 9925 1950
$Comp
L Device:R_US R14
U 1 1 5D4E9DB7
P 10325 1950
F 0 "R14" V 10120 1950 50  0000 C CNN
F 1 "1k" V 10211 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10365 1940 50  0001 C CNN
F 3 "~" H 10325 1950 50  0001 C CNN
	1    10325 1950
	0    1    1    0   
$EndComp
$Comp
L Device:C C9
U 1 1 5D4EE1B9
P 10575 2275
F 0 "C9" H 10690 2321 50  0000 L CNN
F 1 "33nF" H 10690 2230 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10613 2125 50  0001 C CNN
F 3 "~" H 10575 2275 50  0001 C CNN
	1    10575 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	10175 1950 10025 1950
Connection ~ 10025 1950
Wire Wire Line
	10575 2125 10575 1950
Wire Wire Line
	10475 1950 10575 1950
$Comp
L power:GNDA #PWR023
U 1 1 5D501AF9
P 10575 2550
F 0 "#PWR023" H 10575 2300 50  0001 C CNN
F 1 "GNDA" H 10580 2377 50  0000 C CNN
F 2 "" H 10575 2550 50  0001 C CNN
F 3 "" H 10575 2550 50  0001 C CNN
	1    10575 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10575 2550 10575 2425
$Comp
L power:GNDA #PWR011
U 1 1 5D527CAD
P 5725 7375
F 0 "#PWR011" H 5725 7125 50  0001 C CNN
F 1 "GNDA" H 5730 7202 50  0000 C CNN
F 2 "" H 5725 7375 50  0001 C CNN
F 3 "" H 5725 7375 50  0001 C CNN
	1    5725 7375
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R16
U 1 1 5D52A243
P 5250 2200
F 0 "R16" H 5318 2246 50  0000 L CNN
F 1 "10k" H 5318 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5250 2200 50  0001 C CNN
F 3 "~" H 5250 2200 50  0001 C CNN
	1    5250 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR033
U 1 1 5D53513F
P 5250 2375
F 0 "#PWR033" H 5250 2125 50  0001 C CNN
F 1 "GNDD" H 5254 2220 50  0000 C CNN
F 2 "" H 5250 2375 50  0001 C CNN
F 3 "" H 5250 2375 50  0001 C CNN
	1    5250 2375
	1    0    0    -1  
$EndComp
Text Notes 5155 990  0    50   ~ 0
Only one soldered\n
Text Notes 6375 4425 0    50   ~ 0
These 0 ohm resistors should be unsoldered when used with the secondary high-current sensing board\n
Wire Wire Line
	3275 1100 3275 1025
Wire Wire Line
	3275 1025 3675 1025
Wire Wire Line
	3675 1025 3675 1100
$Comp
L power:GNDA #PWR0101
U 1 1 5D62FB9E
P 9125 3875
F 0 "#PWR0101" H 9125 3625 50  0001 C CNN
F 1 "GNDA" H 9130 3702 50  0000 C CNN
F 2 "" H 9125 3875 50  0001 C CNN
F 3 "" H 9125 3875 50  0001 C CNN
	1    9125 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3500 8275 3500
Wire Wire Line
	8675 3500 8575 3500
$Comp
L Device:R_US R19
U 1 1 5D60BC64
P 9125 3725
F 0 "R19" H 9057 3679 50  0000 R CNN
F 1 "4.99k" H 9057 3770 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9165 3715 50  0001 C CNN
F 3 "~" H 9125 3725 50  0001 C CNN
	1    9125 3725
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R18
U 1 1 5D60BBAB
P 8825 3500
F 0 "R18" V 8620 3500 50  0000 C CNN
F 1 "10k" V 8711 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8865 3490 50  0001 C CNN
F 3 "~" H 8825 3500 50  0001 C CNN
	1    8825 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R17
U 1 1 5D60A810
P 8425 3500
F 0 "R17" V 8220 3500 50  0000 C CNN
F 1 "4.99k" V 8311 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8465 3490 50  0001 C CNN
F 3 "~" H 8425 3500 50  0001 C CNN
	1    8425 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	2975 4150 2975 4225
Wire Wire Line
	2975 4225 3125 4225
Wire Wire Line
	3125 4150 3125 4225
Connection ~ 3125 4225
Wire Wire Line
	1625 5000 1575 5000
Connection ~ 1575 5000
Wire Wire Line
	1575 5000 1525 5000
$Comp
L power:+5V #PWR0102
U 1 1 5D4D2E35
P 7075 5025
F 0 "#PWR0102" H 7075 4875 50  0001 C CNN
F 1 "+5V" H 7125 5175 50  0000 C CNN
F 2 "" H 7075 5025 50  0001 C CNN
F 3 "" H 7075 5025 50  0001 C CNN
	1    7075 5025
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5D4DBFC0
P 2975 1050
F 0 "#PWR0103" H 2975 900 50  0001 C CNN
F 1 "+5V" H 3025 1200 50  0000 C CNN
F 2 "" H 2975 1050 50  0001 C CNN
F 3 "" H 2975 1050 50  0001 C CNN
	1    2975 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5D4EDBBD
P 1225 1500
F 0 "#PWR0104" H 1225 1350 50  0001 C CNN
F 1 "+5V" H 1275 1650 50  0000 C CNN
F 2 "" H 1225 1500 50  0001 C CNN
F 3 "" H 1225 1500 50  0001 C CNN
	1    1225 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5D1BA03E
P 1225 2380
F 0 "C12" H 1340 2426 50  0000 L CNN
F 1 "0.1uF" H 1340 2335 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1263 2230 50  0001 C CNN
F 3 "~" H 1225 2380 50  0001 C CNN
	1    1225 2380
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0105
U 1 1 5D4D1DB2
P 4525 4125
F 0 "#PWR0105" H 4525 3875 50  0001 C CNN
F 1 "GNDD" H 4529 3970 50  0000 C CNN
F 2 "" H 4525 4125 50  0001 C CNN
F 3 "" H 4525 4125 50  0001 C CNN
	1    4525 4125
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5D518286
P 9900 5575
F 0 "D4" H 9825 5675 50  0000 C CNN
F 1 "LED" H 10025 5675 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9900 5575 50  0001 C CNN
F 3 "~" H 9900 5575 50  0001 C CNN
	1    9900 5575
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 5D518C5C
P 10000 5150
F 0 "D3" H 10100 5100 50  0000 C CNN
F 1 "LED" H 10100 5025 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10000 5150 50  0001 C CNN
F 3 "~" H 10000 5150 50  0001 C CNN
	1    10000 5150
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R20
U 1 1 5D526340
P 9500 5150
F 0 "R20" V 9450 4975 50  0000 C CNN
F 1 "300" V 9450 5325 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9540 5140 50  0001 C CNN
F 3 "~" H 9500 5150 50  0001 C CNN
	1    9500 5150
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R21
U 1 1 5D527256
P 9400 5575
F 0 "R21" V 9475 5475 50  0000 C CNN
F 1 "300" V 9475 5650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9440 5565 50  0001 C CNN
F 3 "~" H 9400 5575 50  0001 C CNN
	1    9400 5575
	0    1    1    0   
$EndComp
Wire Wire Line
	9750 5575 9550 5575
Wire Wire Line
	9850 5150 9650 5150
$Comp
L power:GNDD #PWR0106
U 1 1 5D597A06
P 10450 5250
F 0 "#PWR0106" H 10450 5000 50  0001 C CNN
F 1 "GNDD" H 10454 5095 50  0000 C CNN
F 2 "" H 10450 5250 50  0001 C CNN
F 3 "" H 10450 5250 50  0001 C CNN
	1    10450 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 5575 10350 5575
Wire Wire Line
	10150 5150 10450 5150
Text Notes 10250 5125 0    50   ~ 0
Green
Text Notes 10075 5675 0    50   ~ 0
Red\n
Wire Wire Line
	1225 2200 1225 2230
Wire Wire Line
	800  700  800  2200
Wire Wire Line
	800  2200 1225 2200
Connection ~ 1225 2200
Wire Wire Line
	800  700  4525 700 
Wire Wire Line
	7075 5675 7125 5675
Wire Wire Line
	7075 5375 7125 5375
Wire Wire Line
	4525 700  4525 1900
Wire Wire Line
	4525 1900 4425 1900
Wire Wire Line
	8975 3500 9125 3500
Wire Wire Line
	4425 2800 4525 2800
Wire Wire Line
	4425 2900 4525 2900
Connection ~ 4525 2900
Wire Wire Line
	4525 2900 4525 3000
Wire Wire Line
	4425 3000 4525 3000
Connection ~ 4525 3000
Wire Wire Line
	4525 3000 4525 3100
Wire Wire Line
	4425 3100 4525 3100
Connection ~ 4525 3100
Wire Wire Line
	4425 3200 4525 3200
Wire Wire Line
	4525 3100 4525 3200
Connection ~ 4525 3200
Wire Wire Line
	4525 3200 4525 3300
Wire Wire Line
	4425 3300 4525 3300
Connection ~ 4525 3300
Connection ~ 4525 2800
Wire Wire Line
	4525 2800 4525 2900
Wire Wire Line
	4425 2300 4525 2300
Wire Wire Line
	4525 2300 4525 2800
Wire Wire Line
	9125 3575 9125 3500
Wire Wire Line
	9125 3500 9400 3500
Connection ~ 9125 3500
Wire Wire Line
	9400 3300 9300 3300
Wire Wire Line
	9300 3300 9300 3125
Wire Wire Line
	9300 3125 10075 3125
Wire Wire Line
	10075 3125 10075 3400
Wire Wire Line
	10075 3400 10000 3400
$Comp
L Device:R_US R22
U 1 1 5D6A43A9
P 10350 3400
F 0 "R22" V 10145 3400 50  0000 C CNN
F 1 "1k" V 10236 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10390 3390 50  0001 C CNN
F 3 "~" H 10350 3400 50  0001 C CNN
	1    10350 3400
	0    1    1    0   
$EndComp
$Comp
L Device:C C16
U 1 1 5D6ABDC3
P 10600 3650
F 0 "C16" H 10715 3696 50  0000 L CNN
F 1 "33nF" H 10715 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10638 3500 50  0001 C CNN
F 3 "~" H 10600 3650 50  0001 C CNN
	1    10600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 3400 10075 3400
Connection ~ 10075 3400
Wire Wire Line
	10500 3400 10600 3400
Wire Wire Line
	10600 3400 10600 3500
Wire Wire Line
	10700 3400 10600 3400
Connection ~ 10600 3400
$Comp
L power:GNDA #PWR017
U 1 1 5D6D0338
P 10600 3900
F 0 "#PWR017" H 10600 3650 50  0001 C CNN
F 1 "GNDA" H 10605 3727 50  0000 C CNN
F 2 "" H 10600 3900 50  0001 C CNN
F 3 "" H 10600 3900 50  0001 C CNN
	1    10600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 3900 10600 3800
Wire Wire Line
	7025 1750 7875 1750
$Comp
L Device:Crystal Y1
U 1 1 5D7A06C0
P 4400 5375
F 0 "Y1" V 4446 5244 50  0000 R CNN
F 1 "25 MHz" V 4355 5244 50  0000 R CNN
F 2 "Crystal_SMD_2520-4Pin_2.5x2.0mm.kicad_mod_IEEE.kicad_mod" H 4400 5375 50  0001 C CNN
F 3 "https://www.mouser.com/datasheet/2/3/ABM10AIG-783578.pdf" H 4400 5375 50  0001 C CNN
F 4 "Abracon" H 4400 5375 50  0001 C CNN "Manufacturer"
F 5 "ABM10AIG-25.000MHZ-4Z-T3" H 4400 5375 50  0001 C CNN "Manufacturer PN"
F 6 "Mouser" H 4400 5375 50  0001 C CNN "Supplier"
F 7 "https://www.mouser.com/ProductDetail/ABRACON/ABM10AIG-25000MHZ-4Z-T3?qs=%2Fha2pyFaduj1vudij7IzbnSbHVJSLi0XvJwHGYKLyiyh0mMcWMnyPh%2FmB9bKfREs" H 4400 5375 50  0001 C CNN "Supplier Link"
F 8 " 815-M10AIG-25-4ZT3 " H 4400 5375 50  0001 C CNN "Supplier PN"
F 9 "1.30" H 4400 5375 50  0001 C CNN "Price 1 QTY"
	1    4400 5375
	0    -1   -1   0   
$EndComp
Text Notes 5055 890  0    50   ~ 0
Configuration resistors
$Comp
L power:+5V #PWR032
U 1 1 5D5394EC
P 5250 1600
F 0 "#PWR032" H 5250 1450 50  0001 C CNN
F 1 "+5V" H 5265 1773 50  0000 C CNN
F 2 "" H 5250 1600 50  0001 C CNN
F 3 "" H 5250 1600 50  0001 C CNN
	1    5250 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R15
U 1 1 5D529372
P 5250 1800
F 0 "R15" H 5318 1846 50  0000 L CNN
F 1 "10k" H 5318 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5250 1800 50  0001 C CNN
F 3 "~" H 5250 1800 50  0001 C CNN
	1    5250 1800
	1    0    0    -1  
$EndComp
$Comp
L F1_Microchip_MCUs:dsPIC33EV32GM102 U3
U 1 1 5D3ED3E3
P 3175 5150
F 0 "U3" H 1875 6450 50  0000 R CNN
F 1 "dsPIC33EV32GM102" H 1925 6350 50  0000 R CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 3175 5150 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33EVXXXGM00X-10X-Family-Data-Sheet-DS70005144H.pdf" H 3175 5150 50  0001 C CNN
F 4 "Microchip" H 3175 5150 50  0001 C CNN "Manufacturer"
F 5 "dsPIC33EV32GM102-E/SS" H 3175 5150 50  0001 C CNN "Manufacturer PN"
F 6 "3.04" H 3175 5150 50  0001 C CNN "Price 1 QTY"
F 7 "Mouser" H 3175 5150 50  0001 C CNN "Supplier"
F 8 "https://www.mouser.com/ProductDetail/Microchip-Technology/dsPIC33EV32GM102-E-SS?qs=sGAEpiMZZMvt8PIZHrwfMh2yGkphHpwrjAuM9fzLf5ybGoYsGfYIMw%3D%3D" H 3175 5150 50  0001 C CNN "Supplier Link"
F 9 " 579-33EV32GM102ESS " H 3175 5150 50  0001 C CNN "Supplier PN"
	1    3175 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5D7A1F19
P 4920 5200
F 0 "C17" H 5035 5246 50  0000 L CNN
F 1 "10uF" H 5035 5155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4958 5050 50  0001 C CNN
F 3 "~" H 4920 5200 50  0001 C CNN
	1    4920 5200
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C18
U 1 1 5D95386F
P 4920 5550
F 0 "C18" V 4668 5550 50  0000 C CNN
F 1 "10uF" V 4759 5550 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4958 5400 50  0001 C CNN
F 3 "~" H 4920 5550 50  0001 C CNN
	1    4920 5550
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5D9832AA
P 5070 5370
F 0 "#PWR?" H 5070 5120 50  0001 C CNN
F 1 "GNDA" V 5075 5242 50  0000 R CNN
F 2 "" H 5070 5370 50  0001 C CNN
F 3 "" H 5070 5370 50  0001 C CNN
	1    5070 5370
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5070 5200 5070 5370
Connection ~ 5070 5370
Wire Wire Line
	5070 5370 5070 5550
Wire Wire Line
	4425 2500 4675 2500
Wire Wire Line
	4675 2700 4425 2700
Wire Wire Line
	4425 2600 4675 2600
Wire Wire Line
	4525 3300 4525 4125
Text GLabel 4675 2500 2    50   Input ~ 0
VSENSE
Text GLabel 10700 3400 2    50   Input ~ 0
VSENSE
Text GLabel 10725 1950 2    50   Input ~ 0
ISENSE
Wire Wire Line
	10725 1950 10575 1950
Connection ~ 10575 1950
Text GLabel 4675 2400 2    50   Input ~ 0
ISENSE
Wire Wire Line
	4675 2400 4425 2400
Text GLabel 4175 5200 0    50   Input ~ 0
OSC1
Wire Wire Line
	4775 5550 4770 5550
Wire Wire Line
	4400 5550 4400 5525
Connection ~ 4770 5550
Wire Wire Line
	4770 5550 4400 5550
Wire Wire Line
	4775 5200 4770 5200
Wire Wire Line
	4400 5200 4400 5225
Connection ~ 4770 5200
Wire Wire Line
	4770 5200 4400 5200
Wire Wire Line
	4400 5200 4175 5200
Connection ~ 4400 5200
Wire Wire Line
	4400 5550 4175 5550
Connection ~ 4400 5550
Text GLabel 4175 5550 0    50   Input ~ 0
OSC2
Text GLabel 4675 2100 2    50   Input ~ 0
OSC1
Text GLabel 4675 2200 2    50   Input ~ 0
OSC2
Wire Wire Line
	4675 2100 4425 2100
Wire Wire Line
	4675 2200 4425 2200
Text GLabel 6900 5575 0    50   Input ~ 0
PGEC
Text GLabel 6900 5475 0    50   Input ~ 0
PGED
Text GLabel 6900 5175 0    50   Input ~ 0
J_MCLR
Text GLabel 1175 1900 0    50   Input ~ 0
J_MCLR
Text GLabel 4675 2600 2    50   Input ~ 0
PGEC
Text GLabel 4675 2700 2    50   Input ~ 0
PGED
Text GLabel 1125 5200 0    50   Input ~ 0
CAN_TX
Text GLabel 4675 3500 2    50   Input ~ 0
CAN_TX
Wire Wire Line
	4675 3500 4425 3500
Text GLabel 1125 5300 0    50   Input ~ 0
CAN_RX
Text GLabel 4675 3600 2    50   Input ~ 0
CAN_RX
Wire Wire Line
	4675 3600 4425 3600
Text GLabel 4675 3800 2    50   Input ~ 0
LED1
Text GLabel 4675 3900 2    50   Input ~ 0
LED2
Wire Wire Line
	4675 3800 4425 3800
Wire Wire Line
	4675 3900 4425 3900
Text GLabel 9250 5150 0    50   Input ~ 0
LED1
Wire Wire Line
	9250 5150 9350 5150
Wire Wire Line
	10450 5150 10450 5250
Text GLabel 9125 5575 0    50   Input ~ 0
LED2
Wire Wire Line
	9250 5575 9125 5575
$Comp
L power:GNDD #PWR?
U 1 1 5E0DEE0A
P 10350 5725
F 0 "#PWR?" H 10350 5475 50  0001 C CNN
F 1 "GNDD" H 10354 5570 50  0000 C CNN
F 2 "" H 10350 5725 50  0001 C CNN
F 3 "" H 10350 5725 50  0001 C CNN
	1    10350 5725
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 5725 10350 5575
Wire Wire Line
	8100 3500 8100 2600
Connection ~ 8100 2600
Wire Wire Line
	8100 2600 8575 2600
Wire Wire Line
	5250 2000 5250 1900
Wire Wire Line
	4425 2000 5250 2000
Wire Wire Line
	5250 2000 5250 2100
Connection ~ 5250 2000
Wire Wire Line
	5250 2375 5250 2300
Wire Wire Line
	5250 1600 5250 1700
Wire Notes Line
	475  4675 11200 4675
Text GLabel 1125 5600 0    50   Input ~ 0
CAN_STBY
Text GLabel 4675 3700 2    50   Input ~ 0
CAN_STBY
Wire Wire Line
	4675 3700 4425 3700
Wire Notes Line
	8500 6300 8500 4675
Wire Notes Line
	475  6300 11225 6300
Wire Notes Line
	4650 6300 4650 7800
Wire Notes Line
	2725 6300 2725 7800
Wire Notes Line
	3275 4675 3275 6300
Wire Notes Line
	5925 475  5925 6300
Text HLabel 4675 3400 2    50   Input ~ 0
PWM
Wire Wire Line
	4675 3400 4425 3400
$Comp
L power:VS #PWR?
U 1 1 5E3CF0BD
P 5725 6725
F 0 "#PWR?" H 5525 6575 50  0001 C CNN
F 1 "VS" H 5742 6898 50  0000 C CNN
F 2 "" H 5725 6725 50  0001 C CNN
F 3 "" H 5725 6725 50  0001 C CNN
	1    5725 6725
	1    0    0    -1  
$EndComp
$EndSCHEMATC
