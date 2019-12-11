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
	2025 3600 1725 3600
Wire Wire Line
	2025 3400 1725 3400
Wire Wire Line
	1800 3500 1725 3500
Connection ~ 1800 3700
Wire Wire Line
	1800 3500 1800 3700
Wire Wire Line
	1725 3700 1800 3700
Wire Wire Line
	1800 3700 1800 4175
$Comp
L power:GND #PWR01
U 1 1 5D342EEF
P 1800 4175
F 0 "#PWR01" H 1800 3925 50  0001 C CNN
F 1 "GND" H 1805 4002 50  0000 C CNN
F 2 "" H 1800 4175 50  0001 C CNN
F 3 "" H 1800 4175 50  0001 C CNN
	1    1800 4175
	1    0    0    -1  
$EndComp
Text Notes 1050 3725 0    50   ~ 0
Neutral_OUT
Text Notes 1175 3700 0    50   ~ 0
Live_OUT\n\n
Text Notes 1075 3500 0    50   ~ 0
Neutral_IN\n
Text Notes 1225 3400 0    50   ~ 0
Live_IN\n
$Comp
L power:GNDD #PWR013
U 1 1 5D401FC5
P 10600 1625
F 0 "#PWR013" H 10600 1375 50  0001 C CNN
F 1 "GNDD" H 10604 1470 50  0000 C CNN
F 2 "" H 10600 1625 50  0001 C CNN
F 3 "" H 10600 1625 50  0001 C CNN
	1    10600 1625
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR014
U 1 1 5D40268A
P 10850 1625
F 0 "#PWR014" H 10850 1375 50  0001 C CNN
F 1 "GNDA" H 10855 1452 50  0000 C CNN
F 2 "" H 10850 1625 50  0001 C CNN
F 3 "" H 10850 1625 50  0001 C CNN
	1    10850 1625
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 1625 10850 1525
Wire Wire Line
	10850 1525 10700 1525
$Comp
L power:GND #PWR012
U 1 1 5D405EBA
P 10350 1625
F 0 "#PWR012" H 10350 1375 50  0001 C CNN
F 1 "GND" H 10355 1452 50  0000 C CNN
F 2 "" H 10350 1625 50  0001 C CNN
F 3 "" H 10350 1625 50  0001 C CNN
	1    10350 1625
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 1625 10350 1525
Wire Wire Line
	10350 1525 10500 1525
Text Notes 575  5400 0    59   ~ 0
NOTES
Text Notes 675  5750 0    39   ~ 0
The grounds should have their own planes and the power, digital, and analog sections should tried to be kept separate - different regions of the board
Text Notes 675  5900 0    39   ~ 0
Bypass capacitors need to be placed close to the IC and must be physically between the power and IC\n
Text Notes 675  6050 0    39   ~ 0
The TVS (zener) diodes need to be placed physically before the capacitors and before any connections to power sensor\n
Text Notes 675  5600 0    39   ~ 0
The different grounds should only be connected at one junction using the net tie
Text Notes 675  6200 0    39   ~ 0
Temp IC should be close to the power sensor\n
Wire Wire Line
	4100 2050 4350 2050
Connection ~ 4100 2050
Wire Wire Line
	4100 2150 4100 2050
$Comp
L power:GND #PWR03
U 1 1 5D359FFF
P 4100 2150
F 0 "#PWR03" H 4100 1900 50  0001 C CNN
F 1 "GND" H 4105 1977 50  0000 C CNN
F 2 "" H 4100 2150 50  0001 C CNN
F 3 "" H 4100 2150 50  0001 C CNN
	1    4100 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2050 3850 2050
Connection ~ 3400 2050
Wire Wire Line
	3400 1850 3400 2050
Wire Wire Line
	3850 2050 4100 2050
Connection ~ 3850 2050
Wire Wire Line
	3850 1850 3850 2050
Wire Wire Line
	4350 2050 4800 2050
Connection ~ 4350 2050
Wire Wire Line
	4350 1850 4350 2050
Wire Wire Line
	4800 2050 5250 2050
Connection ~ 4800 2050
Wire Wire Line
	4800 1850 4800 2050
Wire Wire Line
	5250 2050 5250 1850
Wire Wire Line
	2950 2050 3400 2050
Wire Wire Line
	2950 1850 2950 2050
Connection ~ 5250 1300
Wire Wire Line
	5250 1550 5250 1300
Wire Wire Line
	4800 1300 5250 1300
Connection ~ 4800 1300
Wire Wire Line
	4350 1300 4800 1300
Wire Wire Line
	4800 1550 4800 1300
Connection ~ 4350 1300
Wire Wire Line
	4350 1550 4350 1300
Wire Wire Line
	3850 1300 4350 1300
Connection ~ 3850 1300
Wire Wire Line
	3850 1550 3850 1300
Wire Wire Line
	3400 1300 3850 1300
Connection ~ 3400 1300
Wire Wire Line
	3400 1550 3400 1300
Wire Wire Line
	2950 1300 3400 1300
Connection ~ 2950 1300
Wire Wire Line
	2950 1550 2950 1300
Wire Wire Line
	7300 1300 7300 1600
Connection ~ 7300 1300
Wire Wire Line
	7100 1300 7300 1300
Wire Wire Line
	7300 1300 7875 1300
Wire Wire Line
	7300 1900 7300 2000
Wire Wire Line
	7300 2000 6200 2000
Wire Wire Line
	7875 1650 7875 1700
Connection ~ 7875 1700
Wire Wire Line
	7875 1700 7650 1700
Wire Wire Line
	7650 1700 7650 1500
Wire Wire Line
	7650 1500 7100 1500
Wire Wire Line
	7875 1700 7875 1750
$Comp
L power:GND #PWR06
U 1 1 5D354DD4
P 7875 2050
F 0 "#PWR06" H 7875 1800 50  0001 C CNN
F 1 "GND" H 7880 1877 50  0000 C CNN
F 2 "" H 7875 2050 50  0001 C CNN
F 3 "" H 7875 2050 50  0001 C CNN
	1    7875 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8475 1525 8475 1300
Connection ~ 8475 1300
$Comp
L power:GND #PWR08
U 1 1 5D36B6A5
P 8475 2025
F 0 "#PWR08" H 8475 1775 50  0001 C CNN
F 1 "GND" H 8480 1852 50  0000 C CNN
F 2 "" H 8475 2025 50  0001 C CNN
F 3 "" H 8475 2025 50  0001 C CNN
	1    8475 2025
	1    0    0    -1  
$EndComp
Wire Wire Line
	8475 2025 8475 1825
Wire Wire Line
	7875 1300 7875 1350
Connection ~ 7875 1300
Wire Wire Line
	8475 1300 7875 1300
Text Notes 5950 2400 0    35   ~ 0
1mOhm ESR\n\n
$Comp
L power:GND #PWR04
U 1 1 5D34E109
P 5900 2350
F 0 "#PWR04" H 5900 2100 50  0001 C CNN
F 1 "GND" H 5905 2177 50  0000 C CNN
F 2 "" H 5900 2350 50  0001 C CNN
F 3 "" H 5900 2350 50  0001 C CNN
	1    5900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 1700 6300 1700
Wire Wire Line
	5900 2050 5900 1700
Wire Wire Line
	6200 1600 6300 1600
Wire Wire Line
	6200 2000 6200 1600
Wire Wire Line
	6200 1300 6200 1500
Connection ~ 6200 1300
Wire Wire Line
	6200 1300 6300 1300
Wire Wire Line
	6200 1500 6300 1500
Text Notes 2925 2225 0    35   ~ 0
ceramic, 2mOhm ESR\n
Wire Wire Line
	8475 1200 8475 1300
$Comp
L power:+5V #PWR07
U 1 1 5D35D5EE
P 8475 1200
F 0 "#PWR07" H 8475 1050 50  0001 C CNN
F 1 "+5V" H 8490 1373 50  0000 C CNN
F 2 "" H 8475 1200 50  0001 C CNN
F 3 "" H 8475 1200 50  0001 C CNN
	1    8475 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5D34E632
P 6700 2200
F 0 "#PWR05" H 6700 1950 50  0001 C CNN
F 1 "GND" H 6705 2027 50  0000 C CNN
F 2 "" H 6700 2200 50  0001 C CNN
F 3 "" H 6700 2200 50  0001 C CNN
	1    6700 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 1900 6700 2200
$Sheet
S 4025 3225 1700 1550
U 5D226D6E
F0 "MCU and CAN" 50
F1 "MCU.sch" 50
F2 "CANH" T L 4025 3925 50 
F3 "CANL" T L 4025 4075 50 
F4 "MEASURE_IN" I L 4025 3400 50 
F5 "MEASURE_OUT" I L 4025 3575 50 
F6 "PWM" O R 5725 3400 50 
$EndSheet
$Comp
L power:+12V #PWR09
U 1 1 5D5198D9
P 5900 1200
F 0 "#PWR09" H 5900 1050 50  0001 C CNN
F 1 "+12V" H 5915 1373 50  0000 C CNN
F 2 "" H 5900 1200 50  0001 C CNN
F 3 "" H 5900 1200 50  0001 C CNN
	1    5900 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 3800 1725 3800
Wire Wire Line
	2025 3900 1725 3900
Text Notes 1200 3825 0    50   ~ 0
CAN_HI\n
Text Notes 1200 3925 0    50   ~ 0
CAN_LO
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 5D4A20AB
P 1525 3600
F 0 "J1" H 1633 3981 50  0000 C CNN
F 1 "Conn_01x06_Male" H 1633 3890 50  0000 C CNN
F 2 "Connector_TE:DT13-6P" H 1525 3600 50  0001 C CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7FDT13-4P%7FC%7Fpdf%7FEnglish%7FENG_CD_DT13-4P_C.pdf%7FDT13-4P" H 1525 3600 50  0001 C CNN
	1    1525 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C6
U 1 1 5D3208C5
P 5250 1700
F 0 "C6" H 5365 1746 50  0000 L CNN
F 1 "47uF" H 5365 1655 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 5288 1550 50  0001 C CNN
F 3 "~" H 5250 1700 50  0001 C CNN
	1    5250 1700
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Switching:TPS82150 U1
U 1 1 5D32B50B
P 6700 1500
F 0 "U1" H 6700 1967 50  0000 C CNN
F 1 "TPS82150" H 6700 1876 50  0000 C CNN
F 2 "Package_LGA:Texas_SIL0008D_MicroSiP-8-1EP_2.8x3mm_P0.65mm_EP1.1x1.9mm" H 6700 850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps82150.pdf" H 6700 750 50  0001 C CNN
F 4 "TI" H 6700 1500 50  0001 C CNN "Manufacturer"
F 5 "TPS82150SILR " H 6700 1500 50  0001 C CNN "Manufacturer PN"
F 6 "3.03" H 6700 1500 50  0001 C CNN "Price 1 QTY"
F 7 "Mouser" H 6700 1500 50  0001 C CNN "Supplier"
F 8 "https://www.mouser.com/ProductDetail/?qs=gt1LBUVyoHksxpRVOmIIkg%3D%3D" H 6700 1500 50  0001 C CNN "Supplier Link"
F 9 " 595-TPS82150SILR " H 6700 1500 50  0001 C CNN "Supplier PN"
	1    6700 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5D33425E
P 5900 2200
F 0 "C7" H 6015 2246 50  0000 L CNN
F 1 "470p" H 6015 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5938 2050 50  0001 C CNN
F 3 "~" H 5900 2200 50  0001 C CNN
	1    5900 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C8
U 1 1 5D369605
P 8475 1675
F 0 "C8" H 8590 1721 50  0000 L CNN
F 1 "47uF" H 8590 1630 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 8513 1525 50  0001 C CNN
F 3 "~" H 8475 1675 50  0001 C CNN
	1    8475 1675
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5D350E98
P 7875 1900
F 0 "R3" H 7943 1946 50  0000 L CNN
F 1 "100k" H 7943 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7915 1890 50  0001 C CNN
F 3 "~" H 7875 1900 50  0001 C CNN
	1    7875 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5D350393
P 7875 1500
F 0 "R2" H 7943 1546 50  0000 L CNN
F 1 "523k" H 7943 1455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7915 1490 50  0001 C CNN
F 3 "~" H 7875 1500 50  0001 C CNN
	1    7875 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5D32FCBE
P 7300 1750
F 0 "R1" H 7368 1796 50  0000 L CNN
F 1 "100k" H 7368 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7340 1740 50  0001 C CNN
F 3 "~" H 7300 1750 50  0001 C CNN
	1    7300 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5D3344CE
P 4800 1700
F 0 "C5" H 4915 1746 50  0000 L CNN
F 1 "4.7uF" H 4915 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4838 1550 50  0001 C CNN
F 3 "~" H 4800 1700 50  0001 C CNN
	1    4800 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5D334C90
P 4350 1700
F 0 "C4" H 4465 1746 50  0000 L CNN
F 1 "0.1uF" H 4465 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4388 1550 50  0001 C CNN
F 3 "~" H 4350 1700 50  0001 C CNN
	1    4350 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5D334CE0
P 3850 1700
F 0 "C3" H 3965 1746 50  0000 L CNN
F 1 "0.01uF" H 3965 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3888 1550 50  0001 C CNN
F 3 "~" H 3850 1700 50  0001 C CNN
	1    3850 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5D335009
P 3400 1700
F 0 "C2" H 3515 1746 50  0000 L CNN
F 1 "470pF" H 3515 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3438 1550 50  0001 C CNN
F 3 "~" H 3400 1700 50  0001 C CNN
	1    3400 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D33534D
P 2950 1700
F 0 "C1" H 3065 1746 50  0000 L CNN
F 1 "4.7pF" H 3065 1655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2988 1550 50  0001 C CNN
F 3 "~" H 2950 1700 50  0001 C CNN
	1    2950 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_3_Tee NT1
U 1 1 5D4008D3
P 10600 1525
F 0 "NT1" H 10600 1706 50  0000 C CNN
F 1 "Net-Tie_3_Tee" H 10600 1615 50  0000 C CNN
F 2 "NetTie:NetTie-3_SMD_Pad2.0mm" H 10600 1525 50  0001 C CNN
F 3 "~" H 10600 1525 50  0001 C CNN
	1    10600 1525
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1300 2175 1300
$Comp
L Device:D_Zener D1
U 1 1 5DEFEB23
P 2175 1550
F 0 "D1" V 2129 1629 50  0000 L CNN
F 1 "SD05-7" V 2220 1629 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 2175 1550 50  0001 C CNN
F 3 "https://www.mouser.com/ProductDetail/Diodes-Incorporated/SD05-7?qs=%2Fha2pyFadugD%2Fr1MYEydUCcSjftG2Vlq5z2%2Fe2tdzfA%3D" H 2175 1550 50  0001 C CNN
	1    2175 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	2175 1400 2175 1300
Connection ~ 2175 1300
$Comp
L power:GND #PWR02
U 1 1 5DF00A75
P 2175 1775
F 0 "#PWR02" H 2175 1525 50  0001 C CNN
F 1 "GND" H 2180 1602 50  0000 C CNN
F 2 "" H 2175 1775 50  0001 C CNN
F 3 "" H 2175 1775 50  0001 C CNN
	1    2175 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	2175 1775 2175 1700
$Comp
L Device:D D2
U 1 1 5E37B877
P 7825 3500
F 0 "D2" H 7825 3284 50  0000 C CNN
F 1 "D" H 7825 3375 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 7825 3500 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 7825 3500 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 7825 3500 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 7825 3500 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 7825 3500 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 7825 3500 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 7825 3500 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 7825 3500 50  0001 C CNN "Supplier PN"
	1    7825 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:D D5
U 1 1 5E37C9F3
P 8350 3500
F 0 "D5" H 8350 3284 50  0000 C CNN
F 1 "D" H 8350 3375 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 8350 3500 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 8350 3500 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 8350 3500 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 8350 3500 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 8350 3500 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 8350 3500 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 8350 3500 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 8350 3500 50  0001 C CNN "Supplier PN"
	1    8350 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C20
U 1 1 5E37E7E2
P 8675 3725
F 0 "C20" H 8790 3771 50  0000 L CNN
F 1 "0.1uF" H 8790 3680 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8713 3575 50  0001 C CNN
F 3 "~" H 8675 3725 50  0001 C CNN
	1    8675 3725
	1    0    0    -1  
$EndComp
$Comp
L Device:C C19
U 1 1 5E37E843
P 8100 3725
F 0 "C19" H 8215 3771 50  0000 L CNN
F 1 "0.1uF" H 8215 3680 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8138 3575 50  0001 C CNN
F 3 "~" H 8100 3725 50  0001 C CNN
	1    8100 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3575 8100 3500
Wire Wire Line
	8100 3500 7975 3500
Wire Wire Line
	8100 3500 8200 3500
Connection ~ 8100 3500
Wire Wire Line
	8675 3575 8675 3500
Wire Wire Line
	8675 3500 8500 3500
Wire Wire Line
	7675 3500 7575 3500
Wire Wire Line
	7575 3500 7575 3400
$Comp
L power:+12V #PWR010
U 1 1 5E389ACF
P 7575 3400
F 0 "#PWR010" H 7575 3250 50  0001 C CNN
F 1 "+12V" H 7590 3573 50  0000 C CNN
F 2 "" H 7575 3400 50  0001 C CNN
F 3 "" H 7575 3400 50  0001 C CNN
	1    7575 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3875 8100 4225
$Comp
L power:GNDA #PWR022
U 1 1 5E38CDB2
P 8675 3900
F 0 "#PWR022" H 8675 3650 50  0001 C CNN
F 1 "GNDA" H 8680 3727 50  0000 C CNN
F 2 "" H 8675 3900 50  0001 C CNN
F 3 "" H 8675 3900 50  0001 C CNN
	1    8675 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8675 3900 8675 3875
$Comp
L Device:D D6
U 1 1 5E394EB5
P 8975 3500
F 0 "D6" H 8975 3284 50  0000 C CNN
F 1 "D" H 8975 3375 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 8975 3500 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 8975 3500 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 8975 3500 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 8975 3500 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 8975 3500 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 8975 3500 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 8975 3500 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 8975 3500 50  0001 C CNN "Supplier PN"
	1    8975 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:D D7
U 1 1 5E394EBB
P 9500 3500
F 0 "D7" H 9500 3284 50  0000 C CNN
F 1 "D" H 9500 3375 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 9500 3500 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/ap-en/product/diode/sbd/detail.CUS10S30.html" H 9500 3500 50  0001 C CNN
F 4 "https://www.mouser.com/ProductDetail/Toshiba/CUS10S30H3F?qs=sGAEpiMZZMtQ8nqTKtFS%2FLnbHK8U7YHpoD%2FnZkbvIUu50yFANYtBSg%3D%3D" H 9500 3500 50  0001 C CNN "Supplier Link"
F 5 "Toshiba" H 9500 3500 50  0001 C CNN "Manufacturer"
F 6 "CUS10S30,H3F" H 9500 3500 50  0001 C CNN "Manufacturer PN"
F 7 "0.42" H 9500 3500 50  0001 C CNN "Price 1 QTY"
F 8 "Mouser" H 9500 3500 50  0001 C CNN "Supplier"
F 9 " 757-CUS10S30H3F " H 9500 3500 50  0001 C CNN "Supplier PN"
	1    9500 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C22
U 1 1 5E394EC1
P 9825 3725
F 0 "C22" H 9940 3771 50  0000 L CNN
F 1 "0.1uF" H 9940 3680 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9863 3575 50  0001 C CNN
F 3 "~" H 9825 3725 50  0001 C CNN
	1    9825 3725
	1    0    0    -1  
$EndComp
$Comp
L Device:C C21
U 1 1 5E394EC7
P 9250 3725
F 0 "C21" H 9365 3771 50  0000 L CNN
F 1 "0.1uF" H 9365 3680 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9288 3575 50  0001 C CNN
F 3 "~" H 9250 3725 50  0001 C CNN
	1    9250 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3575 9250 3500
Wire Wire Line
	9250 3500 9125 3500
Wire Wire Line
	9250 3500 9350 3500
Connection ~ 9250 3500
Wire Wire Line
	9825 3575 9825 3500
Wire Wire Line
	9825 3500 9650 3500
$Comp
L power:GNDA #PWR027
U 1 1 5E394ED5
P 9825 3900
F 0 "#PWR027" H 9825 3650 50  0001 C CNN
F 1 "GNDA" H 9830 3727 50  0000 C CNN
F 2 "" H 9825 3900 50  0001 C CNN
F 3 "" H 9825 3900 50  0001 C CNN
	1    9825 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9825 3900 9825 3875
Wire Wire Line
	8825 3500 8675 3500
Connection ~ 8675 3500
Wire Wire Line
	9250 4225 8100 4225
Wire Wire Line
	9250 3875 9250 4225
Connection ~ 8100 4225
Wire Wire Line
	8100 4225 7575 4225
Wire Wire Line
	9825 3500 10325 3500
Connection ~ 9825 3500
$Comp
L power:VS #PWR034
U 1 1 5E3A54BD
P 10450 3400
F 0 "#PWR034" H 10250 3250 50  0001 C CNN
F 1 "VS" H 10467 3573 50  0000 C CNN
F 2 "" H 10450 3400 50  0001 C CNN
F 3 "" H 10450 3400 50  0001 C CNN
	1    10450 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 3400 10450 3500
Text Notes 10000 4350 0    50   ~ 0
Unloaded +22V out\n
Wire Wire Line
	5900 1200 5900 1300
Connection ~ 5900 1300
Wire Wire Line
	5900 1300 6200 1300
$Comp
L Device:CP C23
U 1 1 5E3BD7DC
P 10325 3725
F 0 "C23" H 10443 3771 50  0000 L CNN
F 1 "4.7uF" H 10443 3680 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.8" H 10363 3575 50  0001 C CNN
F 3 "~" H 10325 3725 50  0001 C CNN
	1    10325 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	10325 3575 10325 3500
Connection ~ 10325 3500
Wire Wire Line
	10325 3500 10450 3500
$Comp
L power:GNDA #PWR029
U 1 1 5E3C0B37
P 10325 3925
F 0 "#PWR029" H 10325 3675 50  0001 C CNN
F 1 "GNDA" H 10330 3752 50  0000 C CNN
F 2 "" H 10325 3925 50  0001 C CNN
F 3 "" H 10325 3925 50  0001 C CNN
	1    10325 3925
	1    0    0    -1  
$EndComp
Wire Wire Line
	10325 3925 10325 3875
Text Label 7575 4225 2    50   ~ 0
PWM
Text Label 5950 3400 0    50   ~ 0
PWM
Wire Wire Line
	5950 3400 5725 3400
Text Notes 10000 4525 0    50   ~ 0
35 to 50V cap and diode \nrating\n
Wire Wire Line
	2175 1300 2950 1300
$Comp
L Device:Fuse F?
U 1 1 5DFE1622
P 1650 1300
F 0 "F?" V 1453 1300 50  0000 C CNN
F 1 "Fuse" V 1544 1300 50  0000 C CNN
F 2 "" V 1580 1300 50  0001 C CNN
F 3 "~" H 1650 1300 50  0001 C CNN
	1    1650 1300
	0    1    1    0   
$EndComp
Text Label 3900 3400 2    50   ~ 0
MEAS_IN
Wire Wire Line
	3900 3400 4025 3400
Text Label 3900 3575 2    50   ~ 0
MEAS_OUT
Wire Wire Line
	3900 3575 4025 3575
Text Label 3900 3925 2    50   ~ 0
CANH
Wire Wire Line
	3900 3925 4025 3925
Text Label 3900 4075 2    50   ~ 0
CANL
Wire Wire Line
	3900 4075 4025 4075
Text Label 1375 1300 2    50   ~ 0
LIVE_IN
Wire Wire Line
	1375 1300 1500 1300
Text Label 2025 3400 0    50   ~ 0
LIVE_IN
Text Label 2025 3600 0    50   ~ 0
MEAS_OUT
Text Label 2025 3800 0    50   ~ 0
CANH
Text Label 2025 3900 0    50   ~ 0
CANL
Text Label 5425 1300 0    50   ~ 0
MEAS_IN
Wire Wire Line
	5250 1300 5900 1300
Wire Notes Line
	475  2700 11225 2700
Wire Notes Line
	9550 2700 9550 500 
Wire Notes Line
	475  5175 11225 5175
Wire Notes Line
	6825 2700 6825 5175
Wire Notes Line
	2950 2700 2950 5175
Text Notes 675  6325 0    50   ~ 0
MEAS_IN needs to be physically placed after caps\n
$EndSCHEMATC
