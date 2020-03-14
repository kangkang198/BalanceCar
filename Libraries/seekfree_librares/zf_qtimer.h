/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		qtimer
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_qtimer_h
#define _zf_qtimer_h



#include "common.h"
#include "fsl_qtmr.h"

//此枚举定义不允许用户修改
typedef enum    //QTIMER引脚枚举
{
    QTIMER1_TIMER0_D0,QTIMER1_TIMER0_D13, //定时器0 同一时间只能有一个引脚与定时器相关联
    QTIMER1_TIMER1_D1,QTIMER1_TIMER1_D14, //定时器1 同一时间只能有一个引脚与定时器相关联 
    QTIMER1_TIMER2_D2,QTIMER1_TIMER2_D15, //定时器2 同一时间只能有一个引脚与定时器相关联 
    QTIMER1_TIMER3_D3,QTIMER1_TIMER3_D16, //定时器3 同一时间只能有一个引脚与定时器相关联 
    
    QTIMER2_TIMER0_B4,QTIMER2_TIMER0_C0, //定时器0 同一时间只能有一个引脚与定时器相关联  
    QTIMER2_TIMER1_B5,QTIMER2_TIMER1_C1, //定时器1 同一时间只能有一个引脚与定时器相关联 
    QTIMER2_TIMER2_B6,QTIMER2_TIMER2_C2, //定时器2 同一时间只能有一个引脚与定时器相关联 
    QTIMER2_TIMER3_B7,QTIMER2_TIMER3_C3, //定时器3 同一时间只能有一个引脚与定时器相关联 
    
}QTIMER_PIN_enum;

//此枚举定义不允许用户修改
typedef enum    //QTIMER编号枚举
{
    QTIMER_0,//RT1021没有QTIMER0 这里仅用于占位
    QTIMER_1,
    QTIMER_2,
}QTIMERN_enum;


void qtimer_quad_init(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA, QTIMER_PIN_enum phaseB);
int16 qtimer_quad_get(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA);
void qtimer_quad_clear(QTIMERN_enum qtimern, QTIMER_PIN_enum phaseA);

#endif
 
