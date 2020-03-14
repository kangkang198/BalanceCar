#include "Balance.h"
/**************************************************************************
*  函数名称：Get_Balance_Angle
*  功能说明：获取MPU6050原始数据，并计算得到融合角度
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
float g_fBalance_Angle;
float g_fAccel_Angle;
float g_fBalance_Gyro;
float OutData[6] = {0};//存储4个数据的数组，用于虚拟示波器看这4个数据波形
void Get_Balance_Angle(void)
{
  
  uint8 gyro_offset = 11;//静置时角速度的偏移量
  float gyro_dt = 0.0003f;//陀螺仪角速度积分系数,增长缓慢就增加

  
  get_gyrodata();//获取原始三轴角速度
  get_accdata();//获取原始三轴加速度

  g_fBalance_Gyro = mpu_gyro_y - gyro_offset;
  g_fAccel_Angle = (float)atan2(mpu_acc_x,mpu_acc_z) * 57.296f;//两轴加速度求反三角得到加速度角度，乘以57.296,是把弧度转化为度

  g_fBalance_Angle = 0.02f * g_fAccel_Angle + 0.98f * (g_fBalance_Angle - g_fBalance_Gyro * gyro_dt);//一阶互补滤波得到融合角度

#if 0
    //OutData[0] =  g_fBalance_Gyro;
   // OutData[1] =  g_fAccel_Angle -19.35 ;
   // OutData[2] =  g_fBalance_Angle -19.35;
 
 // OutData[0] = mpu_gyro_x;
 // OutData[1] = mpu_gyro_y;
 // OutData[2] = mpu_gyro_z;
 // OutData[3] = mpu_acc_x;
 // OutData[4] = mpu_acc_y;
 // OutData[5] = mpu_acc_z;
 // vcan_sendware((uint8_t *)OutData, sizeof(OutData));


 
 
#endif

}
/**************************************************************************
*  函数名称：Balance_Control
*  功能说明：直立环PD控制
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
float g_fBalance_Control_Out;
float P_Balance = 120, D_Balance = 0.0;//200,1.0
float g_ftarget_speed_angle = 7.0f;//开环设置的速度角度,正数为加速
float Angle_Zero = -19.35f;//平衡角度软件零位
void Balance_Control(void)
{
  
  
  Get_Balance_Angle();//获取融合角度
  g_fBalance_Control_Out = P_Balance * (g_fBalance_Angle + Angle_Zero - g_ftarget_speed_angle);
  g_fBalance_Control_Out += D_Balance * g_fBalance_Gyro;
  
}

/**************************************************************************
*  函数名称：Motor_Control
*  功能说明：电机控制
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
void Motor_Control(void)
{
  float L_Pwm_Out,R_Pwm_Out;
  const uint16 Pwm_Max = 700;
  Balance_Control();//得到直立控制的输出
  //Direction_Control();//得到方向控制的输出
  
  L_Pwm_Out = g_fBalance_Control_Out - g_fDirection_Control_Out;
  R_Pwm_Out = g_fBalance_Control_Out + g_fDirection_Control_Out;


 

  //输出限幅
  if(L_Pwm_Out >= Pwm_Max)  L_Pwm_Out = Pwm_Max;
  if(L_Pwm_Out <= -Pwm_Max) L_Pwm_Out = -Pwm_Max;
  if(R_Pwm_Out >= Pwm_Max)  R_Pwm_Out = Pwm_Max;
  if(R_Pwm_Out <= -Pwm_Max) R_Pwm_Out = -Pwm_Max;

  if(L_Pwm_Out <= 0) 
  { 
      pwm_duty(MOTOR_LEFT_BK,(uint32)(-L_Pwm_Out));
      pwm_duty(MOTOR_LEFT_UP,0);
  }
  else 
  {     
      pwm_duty(MOTOR_LEFT_BK,0);
      pwm_duty(MOTOR_LEFT_UP,(uint32)(L_Pwm_Out));
  }


  if(R_Pwm_Out <= 0)
  { 
      pwm_duty(MOTOR_RIGHT_BK,(uint32)(-R_Pwm_Out));
      pwm_duty(MOTOR_RIGHT_UP,0);
  }
  else 
  {    
      pwm_duty(MOTOR_RIGHT_BK,0);
      pwm_duty(MOTOR_RIGHT_UP,(uint32)(R_Pwm_Out));
  }
}







