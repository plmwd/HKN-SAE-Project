
#include "calibration.h"

double CalibrateData(double data, cal_point_t* cal_data_points, uint16_t num_points){
    
    int i = 0;
    int rightPoint = 0;
    int leftPoint = 0;
    double slope = 0;
    double calibratedData;
    
    // Iterating through array of points
    for(i = 0; i < num_points; i++)
    {
        // Checking if current point is bigger than data.
        if(cal_data_points[i].measured > data)
        {
            rightPoint = i;
            break;
        } 
    }
    
    leftPoint = rightPoint - 1;
    
    // Getting slope. Using measured as x-axis and offset as y-axis
    slope = (cal_data_points[rightPoint].offset - cal_data_points[leftPoint].offset) / (cal_data_points[rightPoint].measured - cal_data_points[leftPoint].measured);
    
    
    // y = m(x - x_0) + y_0
    calibratedData = slope * (data - cal_data_points[leftPoint].measured) + cal_data_points[leftPoint].offset;
    
    return calibratedData;
}

uint16_t RunCalibrationSetup(cal_point_t* cal_data_points, uint16_t num_points, uint16_t tolerance){
    return 0;
}
