/* 
 * File:   calibration.h
 * Author: Paul
 *
 * Created on August 7, 2019, 6:47 PM
 */

#ifndef CALIBRATION_H
#define	CALIBRATION_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
  @Description
    Calibration data point struct. Houses the ideal point to be calibrated, the measured
    (from another instrument), the measured data from the unit, and the difference
    between the actual and measured.
 
 */
typedef struct {
    uint16_t ideal;
    uint16_t actual;
    uint16_t measured;
    uint16_t difference;
} cal_point_t;


/**
  @Summary
    This function calibrates data based on calibration data points

  @Description
    This function linearly offsets data based off of calibration data points. The
    outputted data is the (raw data) + offset. A linear line is created between two
    calibration offset points and the offset is interpolated based on the inputted data.
 
    * Example:
 
    offset
    ^
    |
    |
    |    *
    |  /   \
    |/        *              *
    -----1----2----3----*----5----> Voltage
    |              *    
    |
    |
    |
    |


  @Param
    uint16_t data: data to be calibrated
    cal_point_t* cal_data_points: array of calibration data points
    uint16_t num_points: number of data points

  @Returns
    Calibrated data ( calibrated_data = data + offset)

*/
uint16_t CalibrateData(uint16_t data, cal_point_t* cal_data_points, uint16_t num_points);


/**
  @Summary
    Runs calibration routine for passed calibration points array.

  @Description
    Runs calibration setup routine and makes sure that the actual and ideal points are
    within a certain tolerance to make sure that random points aren't used.
 
  @Params
    cal_point_t* cal_data_points: calibration data points array to be filled
    uint16_t num_points: number of data points
    uint16_t tolerance: tolerance for calibration setup
 
  @Returns
    TODO: calibration setup status (errors or whatever)

*/
uint16_t RunCalibrationSetup(cal_point_t* cal_data_points, uint16_t num_points, uint16_t tolerance);



#ifdef	__cplusplus
}
#endif

#endif	/* CALIBRATION_H */

