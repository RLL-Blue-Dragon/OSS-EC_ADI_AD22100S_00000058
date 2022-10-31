// License       : License.txt
// Specifications: Spec-AD22100S.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100S.cpp
// Reason for change: 01.00.00 : 05/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "AD22100S.h"

#if     iAD22100S_ma == iSMA                            // Simple moving average filter
static float32 AD22100S_sma_buf[iAD22100S_SMA_num];
static sma_f32_t AD22100S_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iAD22100S_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &AD22100S_sma_buf[0]                            // buffer
};

#elif   iAD22100S_ma == iEMA                            // Exponential moving average filter
static ema_f32_t AD22100S_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iAD22100S_EMA_K                                 // Exponential smoothing factor
};

#elif   iAD22100S_ma == iWMA                            // Weighted moving average filter
static float32 AD22100S_wma_buf[iAD22100S_WMA_num];
static wma_f32_t AD22100S_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iAD22100S_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iAD22100S_WMA_num * (iAD22100S_WMA_num + 1)/2 , // kn sum
        &AD22100S_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_AD22100S =
{
        iAD22100S               ,
        iAD22100S_pin           ,
        iAD22100S_xoff          ,
        iAD22100S_yoff          ,
        iAD22100S_gain          ,
        iAD22100S_max           ,
        iAD22100S_min           ,
        iAD22100S_ma            ,
        
#if     iAD22100S_ma == iSMA                            // Simple moving average filter
        &AD22100S_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100S_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &AD22100S_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100S_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &AD22100S_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
