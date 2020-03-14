#ifndef _ALL_INIT_H
#define _ALL_INIT_H

#include "headfile.h"
//�ܽź궨��
/*------------------���--------------------*/
#define MOTOR_LEFT_UP  PWM2_MODULE1_CHA_D4  //���FTM��ͨ��  
#define MOTOR_LEFT_BK  PWM2_MODULE1_CHB_D5  //���FTM��ͨ��  
#define MOTOR_RIGHT_UP PWM2_MODULE0_CHA_D6 //���FTM��ͨ��  
#define MOTOR_RIGHT_BK PWM2_MODULE0_CHB_D7 //���FTM��ͨ��  
#define MOTOR_FREQ_HZ (15000)  //�����Ƶ�ʴ�С
/*------------------���--------------------*/ 
#define POWER_ADC1_MOD  ADC_1       //����ADCģ���
#define POWER_ADC2_MOD  ADC_2       //����ADCģ���
#define INDUCTOR1_PIN_CH  ADC1_CH3_B17//���� ADC���� 
#define INDUCTOR2_PIN_CH  ADC2_CH3_B18//����ADC����
#define INDUCTOR3_PIN_CH  ADC1_CH4_B19//����ADC����
#define INDUCTOR4_PIN_CH  ADC2_CH4_B20//����ADC����
/*------------------����(���ϵ��£�--------------------*/
#define KEY1_PIN C15 //���������� ��
#define KEY2_PIN C14 //���������� ��
#define KEY3_PIN C9  //���������� ��
#define KEY4_PIN C8  //���������� ��
#define KEY_DOWN (0) //����
#define KEY_UP (1)   //����
/*------------------�ದ����(���ϵ��£�--------------------*/
#define BOMA1_PIN C4  //���������
#define BOMA2_PIN C5 //���������

#define BOMA_ON (0)   //�����
#define BOMA_OFF (1)  //����ر�
/*------------------������--------------------*/
#define BEEP_PIN    D24 //����������
#define BEEP_ON()   gpio_set(BEEP_PIN,1) //�򿪷�����
#define BEEP_OFF()  gpio_set(BEEP_PIN,0) //�رշ�����

/*-----------------LED--------------------*/
#define LED1_PIN D7 //LED����
#define LED2_PIN D5 //LED����
#define LED3_PIN C15 //LED����
#define LED4_PIN C14 //LED����
#define LED1_ON()  gpio_set(LED1_PIN,0) //LED1��
#define LED2_ON()  gpio_set(LED2_PIN,0) //LED2��
#define LED3_ON()  gpio_set(LED3_PIN,0) //LED3��
#define LED4_ON()  gpio_set(LED4_PIN,0) //LED4��
#define LED1_OFF() gpio_set(LED1_PIN,1) //LED1�ر�
#define LED2_OFF() gpio_set(LED2_PIN,1) //LED2�ر�
#define LED3_OFF() gpio_set(LED3_PIN,1) //LED3�ر�
#define LED4_OFF() gpio_set(LED4_PIN,1) //LED4�ر�
/*------------------����--------------------*/
#define BLUETOOTH_BAUDRATE (115200) //����������
#define BLUETOOTH_UART USART_7      //�������ں�
#define BLUETOOTH_TX UART7_TX_D17
#define BLUETOOTH_RX UART7_RX_D18

/*------------------������--------------------*/
#define ENCODE_MODE QTIMER_1 
#define ENCODE_LEFT_A_PHASE QTIMER1_TIMER0_D0 
#define ENCODE_LEFT_B_PHASE QTIMER1_TIMER1_D1
#define ENCODE_RIGHT_A_PHASE QTIMER1_TIMER2_D2
#define ENCODE_RIGHT_B_PHASE QTIMER1_TIMER3_D3




/*****������������*************/

void All_init(void);//ֻ������ܳ�ʼ���������ⲿ����







#endif //_ALL_INIT_H