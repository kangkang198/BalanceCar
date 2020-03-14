#ifndef _INDUCTOR_PROCESS_H
#define _INDUCTOR_PROCESS_H

#include "headfile.h"
extern uint16 g_iL_Inductor;
extern uint16 g_iMid_Inductor;
extern uint16 g_iR_Inductor;
extern uint16 g_iLS_Inductor;
extern uint16 g_iRS_Inductor;
extern float g_fAd_Error;
extern float P_Dir,D_Dir;
extern float g_fDirection_Control_Out;
extern float g_fDirection_Gyro;


void Get_Inductor_data(void);
void Ad_Error_Cal(void);
float Adc_Data_Process(ADCN_enum adcn, ADCCH_enum ch);
void Direction_Control(void);


#endif //_INDUCTANCE_PROCESS_H