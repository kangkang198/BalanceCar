#ifndef _ALL_INIT_H
#define _ALL_INIT_H

#include "headfile.h"
//管脚宏定义
/*------------------电机--------------------*/
#define MOTOR_LEFT_UP  PWM2_MODULE1_CHA_D4  //电机FTM的通道  
#define MOTOR_LEFT_BK  PWM2_MODULE1_CHB_D5  //电机FTM的通道  
#define MOTOR_RIGHT_UP PWM2_MODULE0_CHA_D6 //电机FTM的通道  
#define MOTOR_RIGHT_BK PWM2_MODULE0_CHB_D7 //电机FTM的通道  
#define MOTOR_FREQ_HZ (15000)  //电机的频率大小
/*------------------电感--------------------*/ 
#define POWER_ADC1_MOD  ADC_1       //定义ADC模块号
#define POWER_ADC2_MOD  ADC_2       //定义ADC模块号
#define INDUCTOR1_PIN_CH  ADC1_CH3_B17//定义 ADC引脚 
#define INDUCTOR2_PIN_CH  ADC2_CH3_B18//定义ADC引脚
#define INDUCTOR3_PIN_CH  ADC1_CH4_B19//定义ADC引脚
#define INDUCTOR4_PIN_CH  ADC2_CH4_B20//定义ADC引脚
/*------------------按键(从上到下）--------------------*/
#define KEY1_PIN C15 //按键的引脚 上
#define KEY2_PIN C14 //按键的引脚 下
#define KEY3_PIN C9  //按键的引脚 左
#define KEY4_PIN C8  //按键的引脚 右
#define KEY_DOWN (0) //按下
#define KEY_UP (1)   //弹起
/*------------------侧拨开关(从上到下）--------------------*/
#define BOMA1_PIN C4  //拨码的引脚
#define BOMA2_PIN C5 //拨码的引脚

#define BOMA_ON (0)   //拨码打开
#define BOMA_OFF (1)  //拨码关闭
/*------------------蜂鸣器--------------------*/
#define BEEP_PIN    D24 //蜂鸣器引脚
#define BEEP_ON()   gpio_set(BEEP_PIN,1) //打开蜂鸣器
#define BEEP_OFF()  gpio_set(BEEP_PIN,0) //关闭蜂鸣器

/*-----------------LED--------------------*/
#define LED1_PIN D7 //LED引脚
#define LED2_PIN D5 //LED引脚
#define LED3_PIN C15 //LED引脚
#define LED4_PIN C14 //LED引脚
#define LED1_ON()  gpio_set(LED1_PIN,0) //LED1打开
#define LED2_ON()  gpio_set(LED2_PIN,0) //LED2打开
#define LED3_ON()  gpio_set(LED3_PIN,0) //LED3打开
#define LED4_ON()  gpio_set(LED4_PIN,0) //LED4打开
#define LED1_OFF() gpio_set(LED1_PIN,1) //LED1关闭
#define LED2_OFF() gpio_set(LED2_PIN,1) //LED2关闭
#define LED3_OFF() gpio_set(LED3_PIN,1) //LED3关闭
#define LED4_OFF() gpio_set(LED4_PIN,1) //LED4关闭
/*------------------蓝牙--------------------*/
#define BLUETOOTH_BAUDRATE (115200) //蓝牙波特率
#define BLUETOOTH_UART USART_7      //蓝牙串口号
#define BLUETOOTH_TX UART7_TX_D17
#define BLUETOOTH_RX UART7_RX_D18

/*------------------编码器--------------------*/
#define ENCODE_MODE QTIMER_1 
#define ENCODE_LEFT_A_PHASE QTIMER1_TIMER0_D0 
#define ENCODE_LEFT_B_PHASE QTIMER1_TIMER1_D1
#define ENCODE_RIGHT_A_PHASE QTIMER1_TIMER2_D2
#define ENCODE_RIGHT_B_PHASE QTIMER1_TIMER3_D3




/*****函数声明部分*************/

void All_init(void);//只有这个总初始化可用于外部调用







#endif //_ALL_INIT_H