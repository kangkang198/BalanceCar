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


#include "zf_iomuxc.h"
#include "zf_pwm.h"


#define PWM_SRC_CLK_FREQ    CLOCK_GetFreq(kCLOCK_IpgClk)        //定义PWM输入时钟源频率
#define PWM_PIN_CONF        SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //配置PWM引脚默认配置   

static PWM_Type * PWMPTR[] = PWM_BASE_PTRS;


void pwm_iomuxc(PWMCH_enum pwmch)
{
    switch(pwmch)
    {
        case PWM1_MODULE0_CHA_B22:  iomuxc_pinconf(B22,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE0_CHA_C26:  iomuxc_pinconf(C26,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE0_CHB_B23:  iomuxc_pinconf(B23,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE0_CHB_C27:  iomuxc_pinconf(C27,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE1_CHA_B24:  iomuxc_pinconf(B24,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE1_CHA_C24:  iomuxc_pinconf(C24,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE1_CHB_B25:  iomuxc_pinconf(B25,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE1_CHB_C25:  iomuxc_pinconf(C25,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE2_CHA_B26:  iomuxc_pinconf(B26,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE2_CHA_C22:  iomuxc_pinconf(C22,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE2_CHB_B27:  iomuxc_pinconf(B27,ALT1,PWM_PIN_CONF); break;
        case PWM1_MODULE2_CHB_C23:  iomuxc_pinconf(C23,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE3_CHA_B28:  iomuxc_pinconf(B28,ALT6,PWM_PIN_CONF); break;
        case PWM1_MODULE3_CHA_C20:  iomuxc_pinconf(C20,ALT1,PWM_PIN_CONF); break;
        
        case PWM1_MODULE3_CHB_B29:  iomuxc_pinconf(B29,ALT6,PWM_PIN_CONF); break;
        case PWM1_MODULE3_CHB_C21:  iomuxc_pinconf(C21,ALT1,PWM_PIN_CONF); break;
        
        
        
        case PWM2_MODULE0_CHA_B14:  iomuxc_pinconf(B14,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE0_CHA_D6 :  iomuxc_pinconf(D6 ,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE0_CHB_B15:  iomuxc_pinconf(B15,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE0_CHB_D7 :  iomuxc_pinconf(D7 ,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE1_CHA_B12:  iomuxc_pinconf(B12,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE1_CHA_D4 :  iomuxc_pinconf(D4 ,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE1_CHB_B13:  iomuxc_pinconf(B13,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE1_CHB_D5 :  iomuxc_pinconf(D5 ,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE2_CHA_B10:  iomuxc_pinconf(B10,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE2_CHA_C30:  iomuxc_pinconf(C30,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE2_CHB_B11:  iomuxc_pinconf(B11,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE2_CHB_C31:  iomuxc_pinconf(C31,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE3_CHA_B6 :  iomuxc_pinconf(B6 ,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE3_CHA_C28:  iomuxc_pinconf(C28,ALT1,PWM_PIN_CONF); break;
        
        case PWM2_MODULE3_CHB_B7 :  iomuxc_pinconf(B7 ,ALT4,PWM_PIN_CONF); break;
        case PWM2_MODULE3_CHB_C29:  iomuxc_pinconf(C29,ALT1,PWM_PIN_CONF); break;

        default :assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM初始化
//  @param      pwmch       PWM通道号及引脚
//  @param      freq        PWM频率
//  @param      duty        PWM占空比
//  @return     void
//  Sample usage:           pwm_init(PWM1_MODULE0_CHB_B23, 50, 5000);     //初始化PWM1  子模块0 通道B 使用引脚B23  输出PWM频率50HZ   占空比为百分之 5000/PWM_DUTY_MAX*100
//							PWM_DUTY_MAX在fsl_pwm.h文件中 默认为50000 
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(PWMCH_enum pwmch, uint32 freq, uint32 duty)
{
    uint16 temp_prsc;
    pwm_config_t pwmConfig;
    
    pwm_iomuxc(pwmch);

    //pwmConfig.enableDebugMode = false;
    //pwmConfig.enableWait = false;
    //pwmConfig.reloadSelect = kPWM_LocalReload;
    //pwmConfig.faultFilterCount = 0;
    //pwmConfig.faultFilterPeriod = 0;
    //pwmConfig.clockSource = kPWM_BusClock;
    //pwmConfig.prescale = kPWM_Prescale_Divide_1;
    //pwmConfig.initializationControl = kPWM_Initialize_LocalSync;
    //pwmConfig.forceTrigger = kPWM_Force_Local;
    //pwmConfig.reloadFrequency = kPWM_LoadEveryOportunity;
    //pwmConfig.reloadLogic = kPWM_ReloadImmediate;
    //pwmConfig.pairOperation = kPWM_Independent;

    PWM_GetDefaultConfig(&pwmConfig);

    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    pwmConfig.pairOperation = kPWM_Independent;
    pwmConfig.enableDebugMode = true;
    

    //计算分频系数
    temp_prsc = (PWM_SRC_CLK_FREQ/freq)>>16;
    if      (1   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_1;
    else if (2   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_2;
    else if (4   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_4;
    else if (8   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_8;
    else if (16  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_16;
    else if (32  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_32;
    else if (64  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_64;
    else if (128 >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_128;
    else
    {
        assert(0) ;//频率过小 或者IPG频率过高
    }

    //初始化PWM模块 
    if (PWM_Init(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), &pwmConfig) == kStatus_Fail)//第一次初始化便于打开时钟
    {
        assert(0) ;//初始化失败
    }
    PWM_Deinit(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2));
    
    if (PWM_Init(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), &pwmConfig) == kStatus_Fail)//重新初始化设置正确的参数
    {
        assert(0) ;//初始化失败
    }

    //设置频率占空比等参数
    pwm_signal_param_t pwmSignal;

    pwmSignal.pwmChannel = (pwm_channels_t)(((pwmch%16)>>1)%2); 
    pwmSignal.level = kPWM_HighTrue;
    pwmSignal.dutyCyclePercent = duty;  //PWM_DUTY_MAX
    pwmSignal.deadtimeValue = 0;//((uint64_t)PWM_SRC_CLK_FREQ * 650) / 1000000000;

    //清除LOAD OKAY位  以设置新的参数
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), false);
    PWM_SetupPwm(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), &pwmSignal, 1, kPWM_EdgeAligned, freq, PWM_SRC_CLK_FREQ);     
    //设置LOAD OKAY位  以更新设置
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), true);

    //启动定时器
    PWM_StartTimer(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)));
    
    PWMPTR[pwmch>>4]->SM[(pwmch%16)>>2].DISMAP[0]=0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM占空比设置
//  @param      pwmch       PWM通道号及引脚
//  @param      freq        PWM频率
//  @param      duty        PWM占空比
//  @return     void
//  Sample usage:           pwm_duty(PWM1_MODULE0_CHB_B23, 5000);     //设置占空比为百分之 5000/PWM_DUTY_MAX*100
//							PWM_DUTY_MAX在fsl_pwm.h文件中 默认为50000
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty(PWMCH_enum pwmch, uint32 duty)
{
    //清除LOAD OKAY位  以设置新的参数
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), false);
    PWM_UpdatePwmDutycycle(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), (pwm_channels_t)(((pwmch%16)>>1)%2), kPWM_EdgeAligned, duty);
    //设置LOAD OKAY位  以更新设置
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), true);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM频率设置
//  @param      pwmch       PWM通道号及引脚
//  @param      freq        PWM频率
//  @param      duty        PWM占空比
//  @return     void
//  Sample usage:           pwm_freq(PWM1_MODULE0_CHB_B23, 50);     //设置频率为50HZ   
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(PWMCH_enum pwmch, uint32 freq, uint32 duty)
{
    uint16 temp_prsc;
    pwm_config_t pwmConfig;

    PWM_GetDefaultConfig(&pwmConfig);

    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    pwmConfig.pairOperation = kPWM_Independent;
    pwmConfig.enableDebugMode = true;
    
    //计算分频系数
    temp_prsc = (PWM_SRC_CLK_FREQ/freq)>>16;
    if      (1   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_1;
    else if (2   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_2;
    else if (4   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_4;
    else if (8   >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_8;
    else if (16  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_16;
    else if (32  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_32;
    else if (64  >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_64;
    else if (128 >= temp_prsc)  pwmConfig.prescale = kPWM_Prescale_Divide_128;
    else
    {
        assert(0) ;//频率过小 或者IPG频率过高
    }
    
    
    //初始化PWM模块 
    if (PWM_Init(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), &pwmConfig) == kStatus_Fail)
    {
        assert(0) ;//初始化失败
    }

    //设置频率占空比等参数
    pwm_signal_param_t pwmSignal;

    pwmSignal.pwmChannel = (pwm_channels_t)(((pwmch%16)>>1)%2); 
    pwmSignal.level = kPWM_HighTrue;
    pwmSignal.dutyCyclePercent = duty;  //PWM_DUTY_MAX
    pwmSignal.deadtimeValue = 0;//((uint64_t)PWM_SRC_CLK_FREQ * 650) / 1000000000;
    
    //清除LOAD OKAY位  以设置新的参数
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), false);
    PWM_SetupPwm(PWMPTR[pwmch>>4], (pwm_submodule_t)((pwmch%16)>>2), &pwmSignal, 1, kPWM_EdgeAligned, freq, PWM_SRC_CLK_FREQ);     
    //设置LOAD OKAY位  以更新设置
    PWM_SetPwmLdok(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)), true);

    //启动定时器
    PWM_StartTimer(PWMPTR[pwmch>>4], (pwm_module_control_t)(1<<((pwmch%16)>>2)));
    
    PWMPTR[pwmch>>4]->SM[(pwmch%16)>>2].DISMAP[0]=0;
}