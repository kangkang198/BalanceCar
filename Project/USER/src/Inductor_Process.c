#include "Inductor_Process.h"

/**************************************************************************
*  函数名称：Adc_Data_Process(ADCN_enum adcn, ADCCH_enum ch)
*  功能说明：对模数转换的ad值进行处理
*  参数说明： adcn：adc模块号、ch：adc管脚
*  函数返回：有符号16位结果值
*  修改时间：2019-8-31
***************************************************************************/
float Adc_Data_Process(ADCN_enum adcn, ADCCH_enum ch)
{
    uint8 i, j;
    uint16 adc_base[10], adc_temp = 0;
    uint16 adc_sum = 0;
//1、对该路电感连续采集10次AD值
    for (i = 0; i < 10; i++)
        adc_base[i] = adc_convert(adcn,ch);
//2、对10次AD值进行冒泡排序
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (adc_base[j] < adc_base[j + 1])
            {
                adc_temp = adc_base[j];
                adc_base[j] = adc_base[j + 1];
                adc_base[j + 1] = adc_temp;
            }
        }
    }
//3、去掉左右2个最值取平均
    for (i = 2; i < 8; i++)
        adc_sum += adc_base[i];

    return ((float)adc_sum / 6);
}

/**************************************************************************
*  函数名称：Get_Inductor_data
*  功能说明：获取5路电感值
*  参数说明：无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
uint16 g_iL_Inductor = 0;   //左水平电感
uint16 g_iMid_Inductor = 0; //中水平电感
uint16 g_iR_Inductor = 0;   //右水平电感
uint16 g_iLS_Inductor = 0;  //左垂直电感
uint16 g_iRS_Inductor = 0;  //右垂直电感

void Get_Inductor_data(void)
{
    uint8 i = 0;
    float car_base[4] = {0};
    float car_adc[4] = {0};
    uint16 adc_max[4] = {750, 750, 750, 750};
    uint16 adc_min[4] = {1, 1, 1, 1};
    //电位器编号 从左到右 0~5
    car_base[0] = Adc_Data_Process(POWER_ADC1_MOD,INDUCTOR1_PIN_CH);
    car_base[1] = Adc_Data_Process(POWER_ADC2_MOD,INDUCTOR2_PIN_CH);
    car_base[2] = Adc_Data_Process(POWER_ADC1_MOD,INDUCTOR3_PIN_CH);
    car_base[3] = Adc_Data_Process(POWER_ADC2_MOD,INDUCTOR4_PIN_CH);
   
    //归一化1-1000
    for(i = 0; i < 4 ; i++ )
    {
        car_adc[i] = (car_base[i] - adc_min[i]) / (adc_max[i] - adc_min[i]);
        if( car_adc[i] >= 1 )
            car_adc[i] = 1;
        if( car_adc[i] <= 0.001 )
            car_adc[i] = 0.001;
        car_adc[i] *= 1000;
    }
    //电感编号
    g_iL_Inductor = (uint16)car_adc[1];
    //g_iMid_Inductor = (uint16)car_adc[2];
    g_iR_Inductor = (uint16)car_adc[2];
   
   // g_iLS_Inductor = (uint16)car_adc[3];
   // g_iRS_Inductor = (uint16)car_adc[4];
   
   
    
}
/**************************************************************************
*  函数名称：Ad_Error_Cal
*  功能说明：差比和计算得到中线偏差
*  参数说明：无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
float g_fAd_Error;

void Ad_Error_Cal(void)
{
   
     g_fAd_Error = (float)(g_iL_Inductor - g_iR_Inductor) / (g_iL_Inductor + g_iR_Inductor);   
     g_fAd_Error *= 100; //适当放大  
    

    
}


/**************************************************************************
*  函数名称：Direction_Control
*  功能说明：方向控制
*  参数说明：无
*  函数返回：无符号结果值
*  修改时间：2019-8-31
***************************************************************************/
float P_Dir = 9.0, D_Dir = 0.1;//8.0、0.8  16.0、1.2
float g_fDirection_Control_Out;
float g_fDirection_Gyro;
void Direction_Control(void)
{
    int8 gyro_offset = -23;
    Get_Inductor_data();//电感处理
    
    Ad_Error_Cal();//获取中线偏移量
    g_fDirection_Gyro = mpu_gyro_z - gyro_offset;
    g_fDirection_Control_Out = P_Dir * (int16)g_fAd_Error - D_Dir * g_fDirection_Gyro;
   
}




