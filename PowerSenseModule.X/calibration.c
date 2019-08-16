
#include "calibration.h"

uint16_t CalibrateData(uint16_t data, cal_point_t* cal_data_points, uint16_t num_points){
    return 0;
}

uint16_t RunCalibrationSetup(cal_point_t* cal_data_points, uint16_t num_points, uint16_t tolerance){
    return 0;
}


//void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AD1Interrupt ( void )
//{
//    // Disable timer 3 (ADC conversion trigger)
//    TMR3_Stop();
//    
//	// ADC1 callback function 
//	//ADC1_CallBack();
//	
//    // transfer ADC samples to buffer (could use DMA in the future)
//    adc_buffer[0] = ADC1BUF0;
//    adc_buffer[1] = ADC1BUF1;
//    adc_buffer[2] = ADC1BUF2;
//    adc_buffer[3] = ADC1BUF3;
//    adc_buffer[4] = ADC1BUF4;
//    adc_buffer[5] = ADC1BUF5;
//    adc_buffer[6] = ADC1BUF6;
//    adc_buffer[7] = ADC1BUF7;
//    adc_buffer[8] = ADC1BUF8;
//    adc_buffer[9] = ADC1BUF9;
//    adc_buffer[10] = ADC1BUFA;
//    adc_buffer[11] = ADC1BUFB;
//    adc_buffer[12] = ADC1BUFC;
//    adc_buffer[13] = ADC1BUFD;
//    adc_buffer[14] = ADC1BUFE;
//    adc_buffer[15] = ADC1BUFF;
//    
//    
//    data_ready = true;
//    
//    // clear the ADC interrupt flag
//    IFS0bits.AD1IF = false;
//}