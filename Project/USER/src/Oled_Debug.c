#include "Oled_Debug.h"
/**************************************************************************
*  功能说明：OLED显示直立环数据
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
*  备注：
***************************************************************************/
static void Show_Balance_Data(void)
{
  
   oled_p6x8str(2,1,"P_Balance");   oled_printf_float(80, 1, P_Balance, 3,0);//直立环参数P
   oled_p6x8str(2,2,"D_Balance");   oled_printf_float(80, 2, D_Balance, 3,2);//直立环参数D
   
 
}
/**************************************************************************
*  功能说明：OLED显示方向环数据
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
*  备注：
***************************************************************************/ 
static void Show_Direction_Data(void)
{
   oled_p6x8str(2,0,"P_Dir");       oled_printf_float(80, 0, P_Dir, 2,2);//方向环参数P
   oled_p6x8str(2,1,"D_Dir");       oled_printf_float(80, 1, D_Dir, 2,2);//方向环参数D
  
   
}
/**************************************************************************
*  功能说明：OLED显示电感数据
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
*  备注：
***************************************************************************/
static void Show_Inductor_Data(void)
{
   oled_p6x8str(2,0,"L_Inductor");    oled_uint16(80, 0, g_iL_Inductor);//左水平电感数据
   oled_p6x8str(2,1,"R_Inductor");    oled_uint16(80, 1, g_iR_Inductor);//中水平电感
   oled_p6x8str(2,2,"AD_Error");      oled_printf_float(80, 2, g_fAd_Error, 2,2);//中线偏差
   oled_p6x8str(2,3,"SpeedAngle");    oled_printf_float(80, 3,  g_ftarget_speed_angle, 2,2);//最终融合角度
   
 
}



/**************************************************************************
*  功能说明：直立环的按键拨码调参数，OLED显示
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-12-23
*  备注：打开拨码1
***************************************************************************/
static void Balance_Debug(void)
{
 
  while(gpio_get(BOMA1_PIN) == BOMA_ON)//第1个拨码打开
  {
     DisableGlobalIRQ();
    
     Show_Balance_Data();//OLED显示直立环数据
     if(gpio_get(KEY1_PIN) == KEY_DOWN)//第1个按键按下
     {
       systick_delay_ms(100);//按键消抖，时间设置长一点可以使长按时数据变化不会太大
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       P_Balance += 1;
     
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//第2个按键按下，可以长按
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       P_Balance -= 1;
        
     }
      if(gpio_get(KEY3_PIN) == KEY_DOWN)//第3个按键按下，可以长按
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY3_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       D_Balance += 0.01;
       
     }
      if(gpio_get(KEY4_PIN) == KEY_DOWN)//第4个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY4_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       D_Balance -= 0.01;
      
     }
     
     if(gpio_get(BOMA1_PIN) == BOMA_OFF)//第1个拨码关闭
     {
      
       oled_cls();//OLED清黑屏
       EnableGlobalIRQ(0);
      
       break;//退出大while循环
     }
      
  }
     
}

/**************************************************************************
*  功能说明：方向环的按键拨码调参数，OLED显示
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-3-3
*  备注：打开拨码2
***************************************************************************/
static void Direction_Debug(void)
{
  
  while(gpio_get(BOMA2_PIN) == BOMA_ON)//第1个拨码打开
  {
     DisableGlobalIRQ();
    
     Show_Direction_Data();//OLED显示方向环数据
    

     if(gpio_get(KEY1_PIN) == KEY_DOWN)//第1个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       P_Dir += 0.1;
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//第2个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       P_Dir -= 0.1;
     }
      if(gpio_get(KEY3_PIN) == KEY_DOWN)//第3个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY3_PIN) == KEY_DOWN)//等待按键弹起
       D_Dir += 0.01;
     }
      if(gpio_get(KEY4_PIN) == KEY_DOWN)//第4个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY4_PIN) == KEY_DOWN)//等待按键弹起
       D_Dir -= 0.01;
     }
     if(gpio_get(BOMA2_PIN) == BOMA_OFF)//第2个拨码关闭
     {
       oled_cls();//OLED清黑屏
       EnableGlobalIRQ(0);
    
       break;//退出大while循环
     }
  }
 
}

/**************************************************************************
*  功能说明：打开拨码看电磁传感器数据，OLED显示
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
*  备注：打开拨码1
***************************************************************************/
static void Boma_Show_Inductor_Data(void)
{
  
  while(gpio_get(BOMA1_PIN) == BOMA_ON)//第3个拨码打开
  {  
    
    DisableGlobalIRQ();
    
    Direction_Control();
  
    Show_Inductor_Data();//看电磁传感器数据
   
    if(gpio_get(KEY1_PIN) == KEY_DOWN)//第1个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY1_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       g_ftarget_speed_angle += 0.1;
     }
     if(gpio_get(KEY2_PIN) == KEY_DOWN)//第2个按键按下
     {
       systick_delay_ms(100);//按键消抖
       if(gpio_get(KEY2_PIN) == KEY_DOWN)//等待按键弹起，可以长按
       g_ftarget_speed_angle -= 0.1;
     }
    if(gpio_get(BOMA1_PIN) == BOMA_OFF)//第3个拨码关闭
    {
       oled_cls();//OLED清黑屏
       EnableGlobalIRQ(0);
      
       break;//退出大while循环
    }
  }
  
}
/**************************************************************************
*  功能说明：全部按键拨码调试，OLED显示
*  参数说明： 无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
*  备注：
***************************************************************************/
void All_Debug(void)
{
   //Balance_Debug();
   Direction_Debug();
   Boma_Show_Inductor_Data();
}