/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		pwm
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_pwm_h
#define _zf_pwm_h

#include "common.h"
#include "fsl_pwm.h"

//此枚举定义不允许用户修改
typedef enum
{
    PWM1_MODULE0_CHB_B23=16,PWM1_MODULE0_CHB_C27,//PWM1 子模块0 通道B  引脚可选范围
    PWM1_MODULE0_CHA_B22,   PWM1_MODULE0_CHA_C26,//PWM1 子模块0 通道A  引脚可选范围 同一个子模块不同通道只能输出相同频率的PWM，占空比可设置不同
    
    PWM1_MODULE1_CHB_B25,   PWM1_MODULE1_CHB_C25,//PWM1 子模块1 通道B  引脚可选范围
    PWM1_MODULE1_CHA_B24,   PWM1_MODULE1_CHA_C24,//PWM1 子模块1 通道A  引脚可选范围
    
    PWM1_MODULE2_CHB_B27,   PWM1_MODULE2_CHB_C23,//PWM1 子模块2 通道B  引脚可选范围
    PWM1_MODULE2_CHA_B26,   PWM1_MODULE2_CHA_C22,//PWM1 子模块2 通道A  引脚可选范围

    PWM1_MODULE3_CHB_B29,   PWM1_MODULE3_CHB_C21,//PWM1 子模块3 通道B  引脚可选范围
    PWM1_MODULE3_CHA_B28,   PWM1_MODULE3_CHA_C20,//PWM1 子模块3 通道A  引脚可选范围
    
    //-----------------------------------------------------------------------------
    PWM2_MODULE0_CHB_B15,   PWM2_MODULE0_CHB_D7, //PWM2 子模块0 通道B  引脚可选范围
    PWM2_MODULE0_CHA_B14,   PWM2_MODULE0_CHA_D6, //PWM2 子模块0 通道A  引脚可选范围

    PWM2_MODULE1_CHB_B13,   PWM2_MODULE1_CHB_D5, //PWM2 子模块1 通道B  引脚可选范围
    PWM2_MODULE1_CHA_B12,   PWM2_MODULE1_CHA_D4, //PWM2 子模块1 通道A  引脚可选范围

    PWM2_MODULE2_CHB_B11,   PWM2_MODULE2_CHB_C31,//PWM2 子模块2 通道B  引脚可选范围
    PWM2_MODULE2_CHA_B10,   PWM2_MODULE2_CHA_C30,//PWM2 子模块2 通道A  引脚可选范围

    PWM2_MODULE3_CHB_B7,    PWM2_MODULE3_CHB_C29,//PWM2 子模块3 通道B  引脚可选范围
    PWM2_MODULE3_CHA_B6,    PWM2_MODULE3_CHA_C28,//PWM2 子模块3 通道A  引脚可选范围
    
}PWMCH_enum;




void pwm_init(PWMCH_enum pwmch, uint32 freq, uint32 duty);
void pwm_duty(PWMCH_enum pwmch, uint32 duty);
void pwm_freq(PWMCH_enum pwmch, uint32 freq, uint32 duty);



#endif