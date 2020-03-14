#include "Balance.h"
/**************************************************************************
*  �������ƣ�Get_Balance_Angle
*  ����˵������ȡMPU6050ԭʼ���ݣ�������õ��ںϽǶ�
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
float g_fBalance_Angle;
float g_fAccel_Angle;
float g_fBalance_Gyro;
float OutData[6] = {0};//�洢4�����ݵ����飬��������ʾ��������4�����ݲ���
void Get_Balance_Angle(void)
{
  
  uint8 gyro_offset = 11;//����ʱ���ٶȵ�ƫ����
  float gyro_dt = 0.0003f;//�����ǽ��ٶȻ���ϵ��,��������������

  
  get_gyrodata();//��ȡԭʼ������ٶ�
  get_accdata();//��ȡԭʼ������ٶ�

  g_fBalance_Gyro = mpu_gyro_y - gyro_offset;
  g_fAccel_Angle = (float)atan2(mpu_acc_x,mpu_acc_z) * 57.296f;//������ٶ������ǵõ����ٶȽǶȣ�����57.296,�ǰѻ���ת��Ϊ��

  g_fBalance_Angle = 0.02f * g_fAccel_Angle + 0.98f * (g_fBalance_Angle - g_fBalance_Gyro * gyro_dt);//һ�׻����˲��õ��ںϽǶ�

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
*  �������ƣ�Balance_Control
*  ����˵����ֱ����PD����
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
float g_fBalance_Control_Out;
float P_Balance = 120, D_Balance = 0.0;//200,1.0
float g_ftarget_speed_angle = 7.0f;//�������õ��ٶȽǶ�,����Ϊ����
float Angle_Zero = -19.35f;//ƽ��Ƕ������λ
void Balance_Control(void)
{
  
  
  Get_Balance_Angle();//��ȡ�ںϽǶ�
  g_fBalance_Control_Out = P_Balance * (g_fBalance_Angle + Angle_Zero - g_ftarget_speed_angle);
  g_fBalance_Control_Out += D_Balance * g_fBalance_Gyro;
  
}

/**************************************************************************
*  �������ƣ�Motor_Control
*  ����˵�����������
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
void Motor_Control(void)
{
  float L_Pwm_Out,R_Pwm_Out;
  const uint16 Pwm_Max = 700;
  Balance_Control();//�õ�ֱ�����Ƶ����
  //Direction_Control();//�õ�������Ƶ����
  
  L_Pwm_Out = g_fBalance_Control_Out - g_fDirection_Control_Out;
  R_Pwm_Out = g_fBalance_Control_Out + g_fDirection_Control_Out;


 

  //����޷�
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







