// License       : License.txt
// Specifications: Spec-AD22100S.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100S.h
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __AD22100S_H__
#define __AD22100S_H__

#include "user_define.h"

// Components number
#define iAD22100S               108U                    // Analog devices AD22100S

// AD22100S System Parts definitions
#define iAD22100S_xoff          ( 1.375F*(iADC_vdd/5.0F) )      // X offset [V]
#define iAD22100S_yoff          0.0F                    // Y offset [degree celsius]
#define iAD22100S_gain          ( 0.0225F*(iADC_vdd/5.0F) )     // Gain [V/degree celsius]
#define iAD22100S_max           150.0F                  // Temperature Max [degree celsius]
#define iAD22100S_min           -50.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_AD22100S;

#endif /*__AD22100S_H__*/
