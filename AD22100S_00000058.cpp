// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100S_00000058.cpp
// BSL              : 00000058
// Model number     : Analog devices AD22100S
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "AD22100S.h"

AnalogIn AD22100S_adc( iAD22100S_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t AD22100S_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( AD22100S_adc , tbl_AD22100S );
        return( res );
}
