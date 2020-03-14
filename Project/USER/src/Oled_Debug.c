#include "Oled_Debug.h"
/**************************************************************************
*  ����˵����OLED��ʾֱ��������
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
*  ��ע��
***************************************************************************/
static void Show_Balance_Data(void)
{
  
   oled_p6x8str(2,1,"P_Balance");   oled_printf_float(80, 1, P_Balance, 3,0);//ֱ��������P
   oled_p6x8str(2,2,"D_Balance");   oled_printf_float(80, 2, D_Balance, 3,2);//ֱ��������D
   
 
}
/**************************************************************************
*  ����˵����OLED��ʾ��������
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
*  ��ע��
***************************************************************************/ 
static void Show_Direction_Data(void)
{
   oled_p6x8str(2,0,"P_Dir");       oled_printf_float(80, 0, P_Dir, 2,2);//���򻷲���P
   oled_p6x8str(2,1,"D_Dir");       oled_printf_float(80, 1, D_Dir, 2,2);//���򻷲���D
  
   
}
/**************************************************************************
*  ����˵����OLED��ʾ�������
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
*  ��ע��
***************************************************************************/
static void Show_Inductor_Data(void)
{
   oled_p6x8str(2,0,"L_Inductor");    oled_uint16(80, 0, g_iL_Inductor);//��ˮƽ�������
   oled_p6x8str(2,1,"R_Inductor");    oled_uint16(80, 1, g_iR_Inductor);//��ˮƽ���
   oled_p6x8str(2,2,"AD_Error");      oled_printf_float(80, 2, g_fAd_Error, 2,2);//����ƫ��
   oled_p6x8str(2,3,"SpeedAngle");    oled_printf_float(80, 3,  g_ftarget_speed_angle, 2,2);//�����ںϽǶ�
   
 
}



/**************************************************************************
*  ����˵����ֱ�����İ��������������OLED��ʾ
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-12-23
*  ��ע���򿪲���1
***************************************************************************/
static void Balance_Debug(void)
{
 
  while(gpio_get(BOMA1_PIN) == BOMA_ON)//��1�������
  {
     DisableGlobalIRQ();
    
     Show_Balance_Data();//OLED��ʾֱ��������
     if(gpio_get(KEY1_PIN) == KEY_DOWN)//��1����������
     {
       systick_delay_ms(100);//����������ʱ�����ó�һ�����ʹ����ʱ���ݱ仯����̫��
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       P_Balance += 1;
     
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//��2���������£����Գ���
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       P_Balance -= 1;
        
     }
      if(gpio_get(KEY3_PIN) == KEY_DOWN)//��3���������£����Գ���
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY3_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       D_Balance += 0.01;
       
     }
      if(gpio_get(KEY4_PIN) == KEY_DOWN)//��4����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY4_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       D_Balance -= 0.01;
      
     }
     
     if(gpio_get(BOMA1_PIN) == BOMA_OFF)//��1������ر�
     {
      
       oled_cls();//OLED�����
       EnableGlobalIRQ(0);
      
       break;//�˳���whileѭ��
     }
      
  }
     
}

/**************************************************************************
*  ����˵�������򻷵İ��������������OLED��ʾ
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-3-3
*  ��ע���򿪲���2
***************************************************************************/
static void Direction_Debug(void)
{
  
  while(gpio_get(BOMA2_PIN) == BOMA_ON)//��1�������
  {
     DisableGlobalIRQ();
    
     Show_Direction_Data();//OLED��ʾ��������
    

     if(gpio_get(KEY1_PIN) == KEY_DOWN)//��1����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       P_Dir += 0.1;
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//��2����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       P_Dir -= 0.1;
     }
      if(gpio_get(KEY3_PIN) == KEY_DOWN)//��3����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY3_PIN) == KEY_DOWN)//�ȴ���������
       D_Dir += 0.01;
     }
      if(gpio_get(KEY4_PIN) == KEY_DOWN)//��4����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY4_PIN) == KEY_DOWN)//�ȴ���������
       D_Dir -= 0.01;
     }
     if(gpio_get(BOMA2_PIN) == BOMA_OFF)//��2������ر�
     {
       oled_cls();//OLED�����
       EnableGlobalIRQ(0);
    
       break;//�˳���whileѭ��
     }
  }
 
}

/**************************************************************************
*  ����˵�����򿪲��뿴��Ŵ��������ݣ�OLED��ʾ
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
*  ��ע���򿪲���1
***************************************************************************/
static void Boma_Show_Inductor_Data(void)
{
  
  while(gpio_get(BOMA1_PIN) == BOMA_ON)//��3�������
  {  
    
    DisableGlobalIRQ();
    
    Direction_Control();
  
    Show_Inductor_Data();//����Ŵ���������
   
    if(gpio_get(KEY1_PIN) == KEY_DOWN)//��1����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       g_ftarget_speed_angle += 0.1;
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//��2����������
     {
       systick_delay_ms(100);//��������
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//�ȴ��������𣬿��Գ���
       g_ftarget_speed_angle -= 0.1;
     }
    if(gpio_get(BOMA1_PIN) == BOMA_OFF)//��3������ر�
    {
       oled_cls();//OLED�����
       EnableGlobalIRQ(0);
      
       break;//�˳���whileѭ��
    }
  }
  
}
/**************************************************************************
*  ����˵����ȫ������������ԣ�OLED��ʾ
*  ����˵���� ��
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
*  ��ע��
***************************************************************************/
void All_Debug(void)
{
   //Balance_Debug();
   Direction_Debug();
   Boma_Show_Inductor_Data();
}