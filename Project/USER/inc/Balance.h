#ifndef _BALANCE_H
#define _BALANCE_H


#include "headfile.h"


extern float g_fBalance_Angle;
extern float g_fBalance_Gyro;
extern float g_fAccel_Angle;
extern float g_fBalance_Control_Out;
extern float P_Balance,D_Balance;
extern float g_ftarget_speed_angle;//开环设置的速度角度
extern float OutData[6];
extern float Angle_Zero;
void Get_Balance_Angle(void);
void Balance_Control(void);
void Motor_Control(void);



#endif //_BALANCE_H