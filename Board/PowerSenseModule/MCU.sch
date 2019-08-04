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
Text Notes 10025 5425 0    50   ~ 0
Close to VDD TX pin\n
$Comp
L power:+5V #PWR021
U 1 1 5D44F50B
P 8475 5475
F 0 "#PWR021" H 8475 5325 50  0001 C CNN
F 1 "+5V" H 8490 5648 50  0000 C CNN
F 2 "" H 8475 5475 50  0001 C CNN
F 3 "" H 8475 5475 50  0001 C CNN
	1    8475 5475
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 1400 3275 1500
Wire Wire Line
	1925 1900 1725 1900
$Comp
L F1_Microchip_MCUs:dsPIC33EV32GM102 U3
U 1 1 5D3ED3E3
P 3175 5150
F 0 "U3" H 1875 6450 50  0000 R CNN
F 1 "dsPIC33EV32GM102" H 1925 6350 50  0000 R CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 3175 5150 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33EVXXXGM00X-10X-Family-Data-Sheet-DS70005144H.pdf" H 3175 5150 50  0001 C CNN
	1    3175 5150
	1    0    0    -1  
$EndComp
$Comp
L Interface_CAN_LIN:MCP2542FDxMF U4
U 1 1 5D33FB36
P 8725 3700
F 0 "U4" H 8375 3350 50  0000 C CNN
F 1 "MCP2542FDxMF" H 9175 3300 50  0000 C CNN
F 2 "Package_DFN_QFN:DFN-8-1EP_3x3mm_P0.65mm_EP1.55x2.4mm" H 8725 3200 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/MCP2542FD-4FD-MCP2542WFD-4WFD-Data-Sheet20005514B.pdf" H 8725 3700 50  0001 C CNN
	1    8725 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR031
U 1 1 5D3FDEC2
P 8725 4100
F 0 "#PWR031" H 8725 3850 50  0001 C CNN
F 1 "GNDD" H 8725 3950 50  0000 C CNN
F 2 "" H 8725 4100 50  0001 C CNN
F 3 "" H 8725 4100 50  0001 C CNN
	1    8725 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR018
U 1 1 5D3FC142
P 1225 2500
F 0 "#PWR018" H 1225 2250 50  0001 C CNN
F 1 "GNDD" H 1229 2345 50  0000 C CNN
F 2 "" H 1225 2500 50  0001 C CNN
F 3 "" H 1225 2500 50  0001 C CNN
	1    1225 2500
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
P 8475 5775
F 0 "#PWR016" H 8475 5525 50  0001 C CNN
F 1 "GNDD" H 8479 5620 50  0000 C CNN
F 2 "" H 8475 5775 50  0001 C CNN
F 3 "" H 8475 5775 50  0001 C CNN
	1    8475 5775
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR020
U 1 1 5D3FABB0
P 9925 5775
F 0 "#PWR020" H 9925 5525 50  0001 C CNN
F 1 "GNDD" H 9929 5620 50  0000 C CNN
F 2 "" H 9925 5775 50  0001 C CNN
F 3 "" H 9925 5775 50  0001 C CNN
	1    9925 5775
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR028
U 1 1 5D3C46D6
P 9175 1925
F 0 "#PWR028" H 9175 1675 50  0001 C CNN
F 1 "GNDD" H 9179 1770 50  0000 C CNN
F 2 "" H 9175 1925 50  0001 C CNN
F 3 "" H 9175 1925 50  0001 C CNN
	1    9175 1925
	1    0    0    -1  
$EndComp
Text Notes 9175 1375 0    50   ~ 0
MCLR
Text Notes 9175 1775 0    50   ~ 0
PGEC
Text Notes 9175 1675 0    50   ~ 0
PDEC
Wire Wire Line
	8875 1375 9275 1375
Wire Wire Line
	975  1900 975  800 
Wire Wire Line
	9175 1875 9175 1925
Wire Wire Line
	9275 1875 9175 1875
Connection ~ 9175 1875
Wire Wire Line
	9175 1575 9175 1875
Text HLabel 9800 3850 2    50   Input ~ 0
CANL
Text HLabel 9800 3550 2    50   Input ~ 0
CANH
Wire Wire Line
	3125 1300 3125 1500
Wire Wire Line
	975  1900 1225 1900
Wire Wire Line
	9275 1575 9175 1575
Wire Wire Line
	9175 1475 9175 1225
Wire Wire Line
	9275 1475 9175 1475
$Comp
L power:+3.3V #PWR027
U 1 1 5D1EE46F
P 9175 1225
F 0 "#PWR027" H 9175 1075 50  0001 C CNN
F 1 "+3.3V" H 9190 1398 50  0000 C CNN
F 2 "" H 9175 1225 50  0001 C CNN
F 3 "" H 9175 1225 50  0001 C CNN
	1    9175 1225
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 5D1EB185
P 9475 1575
F 0 "J3" H 9555 1567 50  0000 L CNN
F 1 "Programming Header" H 9555 1476 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 9475 1575 50  0001 C CNN
F 3 "~" H 9475 1575 50  0001 C CNN
	1    9475 1575
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5D1E9E31
P 9925 5475
F 0 "#PWR019" H 9925 5325 50  0001 C CNN
F 1 "+5V" H 9940 5648 50  0000 C CNN
F 2 "" H 9925 5475 50  0001 C CNN
F 3 "" H 9925 5475 50  0001 C CNN
	1    9925 5475
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5D1E97D6
P 10425 5625
F 0 "C14" H 10540 5671 50  0000 L CNN
F 1 "0.1uF" H 10540 5580 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10463 5475 50  0001 C CNN
F 3 "~" H 10425 5625 50  0001 C CNN
	1    10425 5625
	1    0    0    -1  
$EndComp
Wire Wire Line
	10125 5775 10425 5775
Wire Wire Line
	9925 5775 10125 5775
Connection ~ 10125 5775
Wire Wire Line
	10125 5475 10425 5475
Wire Wire Line
	9925 5475 10125 5475
Connection ~ 10125 5475
$Comp
L Device:C C13
U 1 1 5D1E97D0
P 10125 5625
F 0 "C13" H 9925 5675 50  0000 L CNN
F 1 "0.01uF" H 9775 5575 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10163 5475 50  0001 C CNN
F 3 "~" H 10125 5625 50  0001 C CNN
	1    10125 5625
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5D1BE43C
P 8975 5625
F 0 "C11" H 9090 5671 50  0000 L CNN
F 1 "0.1uF" H 9090 5580 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9013 5475 50  0001 C CNN
F 3 "~" H 8975 5625 50  0001 C CNN
	1    8975 5625
	1    0    0    -1  
$EndComp
Wire Wire Line
	8675 5775 8975 5775
Wire Wire Line
	8475 5775 8675 5775
Connection ~ 8675 5775
Wire Wire Line
	8675 5475 8975 5475
Wire Wire Line
	8475 5475 8675 5475
Connection ~ 8675 5475
$Comp
L Device:C C10
U 1 1 5D1BE442
P 8675 5625
F 0 "C10" H 8400 5675 50  0000 L CNN
F 1 "0.01uF" H 8325 5575 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8713 5475 50  0001 C CNN
F 3 "~" H 8675 5625 50  0001 C CNN
	1    8675 5625
	1    0    0    -1  
$EndComp
Text Notes 8725 5375 0    50   ~ 0
Close to VDD MCU pin\n
$Comp
L power:+3.3V #PWR022
U 1 1 5D1E7EFD
P 2975 1050
F 0 "#PWR022" H 2975 900 50  0001 C CNN
F 1 "+3.3V" H 2990 1223 50  0000 C CNN
F 2 "" H 2975 1050 50  0001 C CNN
F 3 "" H 2975 1050 50  0001 C CNN
	1    2975 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR017
U 1 1 5D1E7B70
P 1225 1500
F 0 "#PWR017" H 1225 1350 50  0001 C CNN
F 1 "+3.3V" H 1240 1673 50  0000 C CNN
F 2 "" H 1225 1500 50  0001 C CNN
F 3 "" H 1225 1500 50  0001 C CNN
	1    1225 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 3800 9350 3850
Wire Wire Line
	9225 3800 9350 3800
Wire Wire Line
	9350 3600 9350 3550
Wire Wire Line
	9225 3600 9350 3600
Wire Wire Line
	9525 3850 9800 3850
Wire Wire Line
	9350 3850 9525 3850
Connection ~ 9525 3850
Wire Wire Line
	9525 3550 9800 3550
Wire Wire Line
	9350 3550 9525 3550
Connection ~ 9525 3550
$Comp
L Device:R_US R7
U 1 1 5D1D5ACD
P 9525 3700
F 0 "R7" H 9593 3746 50  0000 L CNN
F 1 "120" H 9593 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9565 3690 50  0001 C CNN
F 3 "~" H 9525 3700 50  0001 C CNN
	1    9525 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR029
U 1 1 5D1D4392
P 8850 3425
F 0 "#PWR029" H 8850 3275 50  0001 C CNN
F 1 "+3.3V" H 8800 3575 50  0000 C CNN
F 2 "" H 8850 3425 50  0001 C CNN
F 3 "" H 8850 3425 50  0001 C CNN
	1    8850 3425
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR030
U 1 1 5D1D3CD9
P 8950 3425
F 0 "#PWR030" H 8950 3275 50  0001 C CNN
F 1 "+5V" H 9000 3575 50  0000 C CNN
F 2 "" H 8950 3425 50  0001 C CNN
F 3 "" H 8950 3425 50  0001 C CNN
	1    8950 3425
	1    0    0    -1  
$EndComp
Text Notes 550  2775 0    50   ~ 0
Capacitor disconnected when programming\n
$Comp
L Device:C C12
U 1 1 5D1BA03E
P 1225 2350
F 0 "C12" H 1340 2396 50  0000 L CNN
F 1 "0.1uF" H 1340 2305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1263 2200 50  0001 C CNN
F 3 "~" H 1225 2350 50  0001 C CNN
	1    1225 2350
	1    0    0    -1  
$EndComp
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
Wire Wire Line
	8500 2400 8500 1675
Wire Wire Line
	8675 2500 8675 1775
Wire Wire Line
	8225 3900 8025 3900
Wire Wire Line
	8025 3900 8025 3700
$Comp
L power:GNDD #PWR026
U 1 1 5D514FF2
P 3350 4575
F 0 "#PWR026" H 3350 4325 50  0001 C CNN
F 1 "GNDD" H 3354 4420 50  0000 C CNN
F 2 "" H 3350 4575 50  0001 C CNN
F 3 "" H 3350 4575 50  0001 C CNN
	1    3350 4575
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR024
U 1 1 5D516C00
P 2825 4450
F 0 "#PWR024" H 2825 4200 50  0001 C CNN
F 1 "GNDA" H 2830 4277 50  0000 C CNN
F 2 "" H 2825 4450 50  0001 C CNN
F 3 "" H 2825 4450 50  0001 C CNN
	1    2825 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2825 4150 2825 4450
Wire Wire Line
	3350 4475 3350 4575
Wire Wire Line
	8500 1675 9275 1675
Wire Wire Line
	8675 1775 9275 1775
$Comp
L Device:R_Small_US R8
U 1 1 5D498F82
P 1750 6075
F 0 "R8" H 1818 6121 50  0000 L CNN
F 1 "4m" H 1818 6030 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 1750 6075 50  0001 C CNN
F 3 "~" H 1750 6075 50  0001 C CNN
	1    1750 6075
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 5D49A156
P 1750 5625
F 0 "R6" H 1818 5671 50  0000 L CNN
F 1 "0" H 1818 5580 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1750 5625 50  0001 C CNN
F 3 "~" H 1750 5625 50  0001 C CNN
	1    1750 5625
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R9
U 1 1 5D49A4A2
P 1750 6525
F 0 "R9" H 1818 6571 50  0000 L CNN
F 1 "0" H 1818 6480 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1750 6525 50  0001 C CNN
F 3 "~" H 1750 6525 50  0001 C CNN
	1    1750 6525
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5725 1750 5825
Wire Wire Line
	1750 6175 1750 6325
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 5D49D215
P 900 6025
F 0 "J4" H 1008 6206 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1008 6115 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical_SMD_Pin1Left" H 900 6025 50  0001 C CNN
F 3 "~" H 900 6025 50  0001 C CNN
	1    900  6025
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6025 1400 6025
Wire Wire Line
	1400 6025 1400 5825
Wire Wire Line
	1400 5825 1750 5825
Connection ~ 1750 5825
Wire Wire Line
	1750 5825 1750 5975
Wire Wire Line
	1100 6125 1400 6125
Wire Wire Line
	1400 6125 1400 6325
Wire Wire Line
	1400 6325 1750 6325
Connection ~ 1750 6325
Wire Wire Line
	1750 6325 1750 6425
Wire Wire Line
	1750 5525 1750 5275
Wire Wire Line
	1750 6625 1750 7025
Text HLabel 1750 5275 1    50   Input ~ 0
MEASURE_IN
Text HLabel 1750 7025 3    50   Input ~ 0
MEASURE_OUT
$Comp
L F1_OP_Amps:NCV2007x U2
U 1 1 5D4B495F
P 2850 5725
F 0 "U2" H 2900 5358 50  0000 C CNN
F 1 "NCV2007x" H 2900 5449 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 2850 5375 50  0001 C CNN
F 3 "" H 2850 5375 50  0001 C CNN
	1    2850 5725
	1    0    0    1   
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 2 1 5D4B605F
P 2850 6425
F 0 "U2" H 2900 6792 50  0000 C CNN
F 1 "NCV2007x" H 2900 6701 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 2850 6075 50  0001 C CNN
F 3 "" H 2850 6075 50  0001 C CNN
	2    2850 6425
	1    0    0    -1  
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 3 1 5D4B6BBE
P 4300 6025
F 0 "U2" H 4350 6392 50  0000 C CNN
F 1 "NCV2007x" H 4350 6301 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 4300 5675 50  0001 C CNN
F 3 "" H 4300 5675 50  0001 C CNN
	3    4300 6025
	1    0    0    -1  
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 4 1 5D4B7A85
P 5950 6125
F 0 "U2" H 6000 6492 50  0000 C CNN
F 1 "NCV2007x" H 6000 6401 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5950 5775 50  0001 C CNN
F 3 "" H 5950 5775 50  0001 C CNN
	4    5950 6125
	1    0    0    -1  
$EndComp
$Comp
L F1_OP_Amps:NCV2007x U2
U 5 1 5D4B8129
P 7425 5600
F 0 "U2" H 7503 5671 50  0000 L CNN
F 1 "NCV2007x" H 7503 5580 50  0000 L CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 7425 5250 50  0001 C CNN
F 3 "" H 7425 5250 50  0001 C CNN
	5    7425 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5825 1750 5825
Wire Wire Line
	2600 6325 1750 6325
Wire Wire Line
	2600 6525 2500 6525
Wire Wire Line
	2500 6525 2500 6675
Wire Wire Line
	2500 6675 3300 6675
Wire Wire Line
	3300 6675 3300 6425
Wire Wire Line
	3300 6425 3200 6425
Wire Wire Line
	2600 5625 2500 5625
Wire Wire Line
	2500 5625 2500 5475
Wire Wire Line
	2500 5475 3300 5475
Wire Wire Line
	3300 5475 3300 5725
Wire Wire Line
	3300 5725 3200 5725
$Comp
L Device:R_US R10
U 1 1 5D4CA065
P 3700 5925
F 0 "R10" V 3495 5925 50  0000 C CNN
F 1 "12k" V 3586 5925 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3740 5915 50  0001 C CNN
F 3 "~" H 3700 5925 50  0001 C CNN
	1    3700 5925
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R11
U 1 1 5D4CA856
P 3700 6125
F 0 "R11" V 3800 6125 50  0000 C CNN
F 1 "12k" V 3900 6125 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3740 6115 50  0001 C CNN
F 3 "~" H 3700 6125 50  0001 C CNN
	1    3700 6125
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R13
U 1 1 5D4CADE5
P 4300 5425
F 0 "R13" V 4095 5425 50  0000 C CNN
F 1 "180k" V 4186 5425 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4340 5415 50  0001 C CNN
F 3 "~" H 4300 5425 50  0001 C CNN
	1    4300 5425
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 5925 3950 5925
Wire Wire Line
	4050 6125 3950 6125
$Comp
L Device:R_US R12
U 1 1 5D4D53DE
P 3950 6575
F 0 "R12" H 4018 6621 50  0000 L CNN
F 1 "180k" H 4018 6530 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3990 6565 50  0001 C CNN
F 3 "~" H 3950 6575 50  0001 C CNN
	1    3950 6575
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 5925 3300 5925
Wire Wire Line
	3300 5925 3300 5725
Connection ~ 3300 5725
Wire Wire Line
	3550 6125 3300 6125
Wire Wire Line
	3300 6125 3300 6425
Connection ~ 3300 6425
Wire Wire Line
	4150 5425 3950 5425
Wire Wire Line
	3950 5425 3950 5925
Connection ~ 3950 5925
Wire Wire Line
	3950 5925 4050 5925
Wire Wire Line
	3950 6425 3950 6125
Connection ~ 3950 6125
Wire Wire Line
	3950 6125 3850 6125
$Comp
L power:GNDA #PWR015
U 1 1 5D4E04FF
P 3950 6825
F 0 "#PWR015" H 3950 6575 50  0001 C CNN
F 1 "GNDA" H 3955 6652 50  0000 C CNN
F 2 "" H 3950 6825 50  0001 C CNN
F 3 "" H 3950 6825 50  0001 C CNN
	1    3950 6825
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 6825 3950 6725
Wire Wire Line
	4450 5425 4750 5425
Wire Wire Line
	4750 5425 4750 6025
Wire Wire Line
	4750 6025 4650 6025
$Comp
L Device:R_US R14
U 1 1 5D4E9DB7
P 5050 6025
F 0 "R14" V 4845 6025 50  0000 C CNN
F 1 "1k" V 4936 6025 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5090 6015 50  0001 C CNN
F 3 "~" H 5050 6025 50  0001 C CNN
	1    5050 6025
	0    1    1    0   
$EndComp
$Comp
L Device:C C9
U 1 1 5D4EE1B9
P 5300 6575
F 0 "C9" H 5415 6621 50  0000 L CNN
F 1 "33nF" H 5415 6530 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5338 6425 50  0001 C CNN
F 3 "~" H 5300 6575 50  0001 C CNN
	1    5300 6575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 6025 4750 6025
Connection ~ 4750 6025
Wire Wire Line
	5300 6425 5300 6025
Wire Wire Line
	5200 6025 5300 6025
Connection ~ 5300 6025
Wire Wire Line
	5300 6025 5700 6025
Wire Wire Line
	5700 6225 5600 6225
Wire Wire Line
	5600 6225 5600 6375
Wire Wire Line
	5600 6375 6400 6375
Wire Wire Line
	6400 6375 6400 6125
Wire Wire Line
	6400 6125 6300 6125
$Comp
L power:GNDA #PWR023
U 1 1 5D501AF9
P 5300 6825
F 0 "#PWR023" H 5300 6575 50  0001 C CNN
F 1 "GNDA" H 5305 6652 50  0000 C CNN
F 2 "" H 5300 6825 50  0001 C CNN
F 3 "" H 5300 6825 50  0001 C CNN
	1    5300 6825
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 6825 5300 6725
Wire Wire Line
	6400 6125 6675 6125
Connection ~ 6400 6125
Wire Wire Line
	6675 2700 4425 2700
Wire Wire Line
	6675 2700 6675 6125
$Comp
L power:GNDA #PWR011
U 1 1 5D527CAD
P 7425 5900
F 0 "#PWR011" H 7425 5650 50  0001 C CNN
F 1 "GNDA" H 7430 5727 50  0000 C CNN
F 2 "" H 7425 5900 50  0001 C CNN
F 3 "" H 7425 5900 50  0001 C CNN
	1    7425 5900
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR010
U 1 1 5D528ACF
P 7425 5250
F 0 "#PWR010" H 7425 5100 50  0001 C CNN
F 1 "+12V" H 7440 5423 50  0000 C CNN
F 2 "" H 7425 5250 50  0001 C CNN
F 3 "" H 7425 5250 50  0001 C CNN
	1    7425 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R15
U 1 1 5D529372
P 7500 1450
F 0 "R15" H 7568 1496 50  0000 L CNN
F 1 "10k" H 7568 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7500 1450 50  0001 C CNN
F 3 "~" H 7500 1450 50  0001 C CNN
	1    7500 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R16
U 1 1 5D52A243
P 7500 1925
F 0 "R16" H 7568 1971 50  0000 L CNN
F 1 "10k" H 7568 1880 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7500 1925 50  0001 C CNN
F 3 "~" H 7500 1925 50  0001 C CNN
	1    7500 1925
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR033
U 1 1 5D53513F
P 7500 2075
F 0 "#PWR033" H 7500 1825 50  0001 C CNN
F 1 "GNDD" H 7504 1920 50  0000 C CNN
F 2 "" H 7500 2075 50  0001 C CNN
F 3 "" H 7500 2075 50  0001 C CNN
	1    7500 2075
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2075 7500 2025
$Comp
L power:+5V #PWR032
U 1 1 5D5394EC
P 7500 1300
F 0 "#PWR032" H 7500 1150 50  0001 C CNN
F 1 "+5V" H 7515 1473 50  0000 C CNN
F 2 "" H 7500 1300 50  0001 C CNN
F 3 "" H 7500 1300 50  0001 C CNN
	1    7500 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1300 7500 1350
Text Notes 7575 1725 0    50   ~ 0
Configuration resistors
Text Notes 7675 1825 0    50   ~ 0
Only one soldered\n
Text Notes 1725 7750 0    50   ~ 0
These 0 ohm resistors should be unsoldered when used with the secondary high-current sensing board\n
Wire Wire Line
	4450 3500 8225 3500
Wire Wire Line
	4425 3600 8225 3600
Wire Wire Line
	4425 3700 8025 3700
Wire Wire Line
	3275 1100 3275 1025
Wire Wire Line
	3275 1025 3675 1025
Wire Wire Line
	3675 1025 3675 1100
Wire Wire Line
	7500 1550 7500 1675
Wire Wire Line
	4425 2400 8500 2400
Wire Wire Line
	4425 2500 8675 2500
Wire Wire Line
	4425 1900 6350 1900
Wire Wire Line
	6350 1900 6350 1675
Wire Wire Line
	6350 1675 7500 1675
Connection ~ 7500 1675
Wire Wire Line
	7500 1675 7500 1825
Connection ~ 3300 5475
Wire Wire Line
	3300 4925 3300 5475
Wire Wire Line
	4425 3100 6075 3100
Connection ~ 6075 4925
Wire Wire Line
	6075 3100 6075 4925
$Comp
L power:GNDA #PWR0101
U 1 1 5D62FB9E
P 6075 5350
F 0 "#PWR0101" H 6075 5100 50  0001 C CNN
F 1 "GNDA" H 6080 5177 50  0000 C CNN
F 2 "" H 6075 5350 50  0001 C CNN
F 3 "" H 6075 5350 50  0001 C CNN
	1    6075 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4925 5125 4925
Wire Wire Line
	6075 4925 6075 5050
Wire Wire Line
	5825 4925 6075 4925
Wire Wire Line
	5525 4925 5425 4925
$Comp
L Device:R_US R19
U 1 1 5D60BC64
P 6075 5200
F 0 "R19" H 6007 5154 50  0000 R CNN
F 1 "499k" H 6007 5245 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6115 5190 50  0001 C CNN
F 3 "~" H 6075 5200 50  0001 C CNN
	1    6075 5200
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R18
U 1 1 5D60BBAB
P 5675 4925
F 0 "R18" V 5470 4925 50  0000 C CNN
F 1 "499k" V 5561 4925 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5715 4915 50  0001 C CNN
F 3 "~" H 5675 4925 50  0001 C CNN
	1    5675 4925
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R17
U 1 1 5D60A810
P 5275 4925
F 0 "R17" V 5070 4925 50  0000 C CNN
F 1 "499k" V 5161 4925 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5315 4915 50  0001 C CNN
F 3 "~" H 5275 4925 50  0001 C CNN
	1    5275 4925
	0    1    1    0   
$EndComp
Wire Wire Line
	2975 4150 2975 4475
Wire Wire Line
	2975 4475 3125 4475
Wire Wire Line
	3125 4150 3125 4475
Connection ~ 3125 4475
Wire Wire Line
	3125 4475 3350 4475
Wire Wire Line
	975  800  8875 800 
Wire Wire Line
	8875 800  8875 1375
$EndSCHEMATC
