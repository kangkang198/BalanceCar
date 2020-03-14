/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		gpio
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_gpio_h
#define _zf_gpio_h

#include "common.h"
#include "MIMXRT1021.h"

extern GPIO_Type * PORTPTR[];

#define GPIO_PIN_CONFIG SPEED_100MHZ | DSE_R0 | PULLUP_47K | PULL_EN    //宏定义GPIO引脚的默认配置，便于初始化GPIO时快速填写参数，如果需要其他参数可自行修改
#define GPIO_INT_CONFIG SPEED_100MHZ | HYS_EN | PULLUP_22K | PULL_EN    //宏定义GPIO中断引脚的默认配置，便于初始化GPIO中断时快速填写参数，如果需要其他参数可自行修改

typedef enum    // 枚举触发方式
{
    NO_INT,     //关闭中断模式
    LOW,
    HIGH,
    RISING,
    FALLING,
    BOTH,       //仅PINT模块 可用此触发方式
}TRIGGER_enum;



void gpio_init(PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pinconf);
void gpio_set(PIN_enum pin, uint8 dat);
uint8 gpio_get(PIN_enum pin);
void gpio_dir(PIN_enum pin, GPIODIR_enum dir);
void gpio_toggle(PIN_enum pin);



//中断标志位清除   
#define CLEAR_GPIO_FLAG(pin) GPIO_ClearPinsInterruptFlags(PORTPTR[pin>>5], 1<<(pin&0x1f));//





void gpio_interrupt_init(PIN_enum pin, TRIGGER_enum trigger, uint32 pinconf);



#define PORTB_DR           GPIO1->DR                   //B端口数据输出寄存器
#define PORTC_DR           GPIO2->DR                   //C端口数据输出寄存器
#define PORTD_DR           GPIO3->DR                   //D端口数据输出寄存器




#endif
