#include "Inductor_Process.h"

/**************************************************************************
*  �������ƣ�Adc_Data_Process(ADCN_enum adcn, ADCCH_enum ch)
*  ����˵������ģ��ת����adֵ���д���
*  ����˵���� adcn��adcģ��š�ch��adc�ܽ�
*  �������أ��з���16λ���ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
float Adc_Data_Process(ADCN_enum adcn, ADCCH_enum ch)
{
    uint8 i, j;
    uint16 adc_base[10], adc_temp = 0;
    uint16 adc_sum = 0;
//1���Ը�·��������ɼ�10��ADֵ
    for (i = 0; i < 10; i++)
        adc_base[i] = adc_convert(adcn,ch);
//2����10��ADֵ����ð������
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
//3��ȥ������2����ֵȡƽ��
    for (i = 2; i < 8; i++)
        adc_sum += adc_base[i];

    return ((float)adc_sum / 6);
}

/**************************************************************************
*  �������ƣ�Get_Inductor_data
*  ����˵������ȡ5·���ֵ
*  ����˵������
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
uint16 g_iL_Inductor = 0;   //��ˮƽ���
uint16 g_iMid_Inductor = 0; //��ˮƽ���
uint16 g_iR_Inductor = 0;   //��ˮƽ���
uint16 g_iLS_Inductor = 0;  //��ֱ���
uint16 g_iRS_Inductor = 0;  //�Ҵ�ֱ���

void Get_Inductor_data(void)
{
    uint8 i = 0;
    float car_base[4] = {0};
    float car_adc[4] = {0};
    uint16 adc_max[4] = {750, 750, 750, 750};
    uint16 adc_min[4] = {1, 1, 1, 1};
    //��λ����� ������ 0~5
    car_base[0] = Adc_Data_Process(POWER_ADC1_MOD,INDUCTOR1_PIN_CH);
    car_base[1] = Adc_Data_Process(POWER_ADC2_MOD,INDUCTOR2_PIN_CH);
    car_base[2] = Adc_Data_Process(POWER_ADC1_MOD,INDUCTOR3_PIN_CH);
    car_base[3] = Adc_Data_Process(POWER_ADC2_MOD,INDUCTOR4_PIN_CH);
   
    //��һ��1-1000
    for(i = 0; i < 4 ; i++ )
    {
        car_adc[i] = (car_base[i] - adc_min[i]) / (adc_max[i] - adc_min[i]);
        if( car_adc[i] >= 1 )
            car_adc[i] = 1;
        if( car_adc[i] <= 0.001 )
            car_adc[i] = 0.001;
        car_adc[i] *= 1000;
    }
    //��б��
    g_iL_Inductor = (uint16)car_adc[1];
    //g_iMid_Inductor = (uint16)car_adc[2];
    g_iR_Inductor = (uint16)car_adc[2];
   
   // g_iLS_Inductor = (uint16)car_adc[3];
   // g_iRS_Inductor = (uint16)car_adc[4];
   
   
    
}
/**************************************************************************
*  �������ƣ�Ad_Error_Cal
*  ����˵������Ⱥͼ���õ�����ƫ��
*  ����˵������
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
float g_fAd_Error;

void Ad_Error_Cal(void)
{
   
     g_fAd_Error = (float)(g_iL_Inductor - g_iR_Inductor) / (g_iL_Inductor + g_iR_Inductor);   
     g_fAd_Error *= 100; //�ʵ��Ŵ�  
    

    
}


/**************************************************************************
*  �������ƣ�Direction_Control
*  ����˵�����������
*  ����˵������
*  �������أ��޷��Ž��ֵ
*  �޸�ʱ�䣺2019-8-31
***************************************************************************/
float P_Dir = 9.0, D_Dir = 0.1;//8.0��0.8  16.0��1.2
float g_fDirection_Control_Out;
float g_fDirection_Gyro;
void Direction_Control(void)
{
    int8 gyro_offset = -23;
    Get_Inductor_data();//��д���
    
    Ad_Error_Cal();//��ȡ����ƫ����
    g_fDirection_Gyro = mpu_gyro_z - gyro_offset;
    g_fDirection_Control_Out = P_Dir * (int16)g_fAd_Error - D_Dir * g_fDirection_Gyro;
   
}




