/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		iomuxc
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 

#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "zf_iomuxc.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      IO复用设置与引脚配置
//  @param      pin         选择引脚（选择范围 详见common.h文件内 PIN_enum枚举中的值）
//  @param      alt         复用功能（ALT0-ALT7）
//  @param      pinconf     引脚配置（可设置参数由zf_iomuxc.h文件内PINCONF_enum枚举值确定，多个条件使用 | 相或）
//  @return     void
//  Sample usage:           iomuxc_pinconf(D5,ALT5,PULLUP_100K|SPEED_50MHZ|DSE_R0);     
//                          D5复用功能设置为ALT5，ALT5为GPIO功能，上拉100K IO速度50MHZ 驱动强度R0
//-------------------------------------------------------------------------------------------------------------------
void iomuxc_pinconf(PIN_enum pin, ALT_enum alt, uint32 pinconf)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);           /* iomuxc clock (iomuxc_clk_enable): 0x03u */
    if(B0<=pin && B31>=pin)//端口B
    {
        switch(pin)
        {
            case B0:
            {
                assert(0);              //不允许使用SWD引脚，避免出现问题。
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_00_JTAG_TMS,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_00_GPIO1_IO00,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_00_GPT1_COMPARE1,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_00_GPIO1_IO00,pinconf);
            }break;
            
            case B1:
            {
                assert(0);              //不允许使用SWD引脚，避免出现问题。
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_01_JTAG_TCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_01_GPIO1_IO01,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_01_GPT1_CAPTURE2,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_01_GPIO1_IO01,pinconf);
            }break;
            
            case B2:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_JTAG_MOD,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_GPIO1_IO02,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_GPT1_CAPTURE1,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_02_GPIO1_IO02,pinconf);
            }break;
            
            case B3:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_JTAG_TDI,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_USDHC2_CD_B,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_WDOG1_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_SAI1_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_USDHC1_WP,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_GPIO1_IO03,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_USB_OTG1_OC,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_CCM_PMIC_RDY,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_03_GPIO1_IO03,pinconf);
            }break;
            
            case B4:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_JTAG_TDO,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_FLEXCAN1_TX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_USDHC1_WP,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_QTIMER2_TIMER0,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_ENET_MDIO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_GPIO1_IO04,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_USB_OTG1_PWR,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_EWM_OUT_B,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_04_GPIO1_IO04,pinconf);
            }break;
            
            case B5:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_JTAG_TRSTB,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_FLEXCAN1_RX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_USDHC1_CD_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_QTIMER2_TIMER1,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_ENET_MDC,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_GPIO1_IO05,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_USB_OTG1_ID,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_NMI_GLUE_NMI,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_05_GPIO1_IO05,pinconf);
            }break;
            
            case B6:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_PIT_TRIGGER00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_MQS_RIGHT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_LPUART1_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_QTIMER2_TIMER2,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_FLEXPWM2_PWMA03,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_GPIO1_IO06,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_REF_32K_OUT,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_06_GPIO1_IO06,pinconf);
            }break;
            
            case B7:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_PIT_TRIGGER01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_MQS_LEFT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_LPUART1_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_QTIMER2_TIMER3,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_FLEXPWM2_PWMB03,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_GPIO1_IO07,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_REF_24M_OUT,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_07_GPIO1_IO07,pinconf);
            }break;
            
            case B8:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_ENET_TX_CLK,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_LPI2C3_SCL,1);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_LPUART1_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_KPP_COL00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_ENET_REF_CLK1,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_GPIO1_IO08,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_ARM_CM7_TXEV,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_08_GPIO1_IO08,pinconf);
            }break;
            
            case B9:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_ENET_RDATA01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_LPI2C3_SDA,1);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_LPUART1_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_KPP_ROW00,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_ARM_CM7_RXEV,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,pinconf);
            }break;
            
            case B10:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_ENET_RDATA00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_LPSPI1_SCK,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_LPUART5_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_KPP_COL01,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_FLEXPWM2_PWMA02,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_GPIO1_IO10,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_ARM_CM7_TRACE_CLK,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_10_GPIO1_IO10,pinconf);
            }break;
            
            case B11:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_ENET_RX_EN,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_LPSPI1_PCS0,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_LPUART5_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_KPP_ROW01,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_FLEXPWM2_PWMB02,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_GPIO1_IO11,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_ARM_CM7_TRACE_SWO,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_11_GPIO1_IO11,pinconf);
            }break;
            
            case B12:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_ENET_RX_ER,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPSPI1_SDO,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART3_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_KPP_COL02,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_FLEXPWM2_PWMA01,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_GPIO1_IO12,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_ARM_CM7_TRACE00,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_SNVS_HP_VIO_5_CTL,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_GPIO1_IO12,pinconf);
            }break;
            
            case B13:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_ENET_TX_EN,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPSPI1_SDI,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART3_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_KPP_ROW02,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_FLEXPWM2_PWMB01,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_GPIO1_IO13,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_ARM_CM7_TRACE01,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_SNVS_HP_VIO_5_B,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_GPIO1_IO13,pinconf);
            }break;
            
            case B14:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_ENET_TDATA00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_FLEXCAN2_TX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_LPUART3_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_KPP_COL03,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_FLEXPWM2_PWMA00,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_GPIO1_IO14,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_ARM_CM7_TRACE02,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_WDOG1_ANY,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_14_GPIO1_IO14,pinconf);
            }break;
            
            case B15:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_ENET_TDATA01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_FLEXCAN2_RX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_LPUART3_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_KPP_ROW03,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_FLEXPWM2_PWMB00,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_GPIO1_IO15,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_ARM_CM7_TRACE03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_15_GPIO1_IO15,pinconf);
            }break;
            
            case B16:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_SEMC_READY,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_FLEXSPI_A_DATA03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_FLEXCAN2_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_SAI1_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_FLEXIO1_FLEXIO15,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_GPIO1_IO16,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_ENET_1588_EVENT2_OUT,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_KPP_COL04,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_00_GPIO1_IO16,pinconf);
            }break;
            
            case B17:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_SEMC_CSX00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_FLEXSPI_A_SCLK,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_FLEXCAN2_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_SAI1_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_FLEXIO1_FLEXIO14,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_GPIO1_IO17,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_ENET_1588_EVENT2_IN,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_KPP_ROW04,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_01_GPIO1_IO17,pinconf);
            }break;
            
            case B18:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_SEMC_CSX01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_FLEXSPI_A_DATA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_LPSPI4_SCK,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_SAI1_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_FLEXIO1_FLEXIO13,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_GPIO1_IO18,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_ENET_1588_EVENT3_OUT,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_KPP_COL05,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_02_GPIO1_IO18,pinconf);
            }break;
            
            case B19:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_SEMC_CSX02,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_FLEXSPI_A_DATA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_LPSPI4_PCS0,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_SAI1_TX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_FLEXIO1_FLEXIO12,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_GPIO1_IO19,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_ENET_1588_EVENT3_IN,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_KPP_ROW05,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_03_GPIO1_IO19,pinconf);
            }break;
            
            case B20:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_SEMC_CSX03,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_FLEXSPI_A_DATA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_LPSPI4_SDO,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_SAI1_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_FLEXIO1_FLEXIO11,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_GPIO1_IO20,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_LPSPI1_PCS1,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_KPP_COL06,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_04_GPIO1_IO20,pinconf);
            }break;
            
            case B21:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_USDHC1_WP,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_FLEXSPI_A_SS0_B,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_LPSPI4_SDI,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_SAI1_RX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_FLEXIO1_FLEXIO10,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_GPIO1_IO21,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_LPSPI1_PCS2,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_KPP_ROW06,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_05_GPIO1_IO21,pinconf);
            }break;
            
            case B22:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_USDHC1_RESET_B,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_FLEXPWM1_PWMA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_LPUART2_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_SAI1_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_FLEXIO1_FLEXIO09,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_GPIO1_IO22,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_LPSPI1_PCS3,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_KPP_COL07,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_06_GPIO1_IO22,pinconf);
            }break;
            
            case B23:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_USDHC1_VSELECT,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_FLEXPWM1_PWMB00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_LPUART2_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_SAI1_TX_DATA01,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_FLEXIO1_FLEXIO08,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_GPIO1_IO23,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_LPSPI3_PCS3,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_KPP_ROW07,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_07_GPIO1_IO23,pinconf);
            }break;
            
            case B24:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_LPI2C2_SCL,1);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_FLEXPWM1_PWMA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_LPUART2_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_SAI1_TX_DATA02,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_FLEXIO1_FLEXIO07,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_GPIO1_IO24,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_LPSPI3_PCS2,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_XBAR1_INOUT12,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_08_GPIO1_IO24,pinconf);
            }break;
            
            case B25:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_LPI2C2_SDA,1);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_FLEXPWM1_PWMB01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_LPUART2_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_SAI1_TX_DATA03,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_FLEXIO1_FLEXIO06,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_GPIO1_IO25,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_LPSPI3_PCS1,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_XBAR1_INOUT13,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_09_GPIO1_IO25,pinconf);
            }break;
            
            case B26:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_USB_OTG1_PWR,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_FLEXPWM1_PWMA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_LPUART4_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_USDHC1_CD_B,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_FLEXIO1_FLEXIO05,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_GPIO1_IO26,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_GPT2_CAPTURE1,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_10_GPIO1_IO26,pinconf);
            }break;
            
            case B27:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_USB_OTG1_ID,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_FLEXPWM1_PWMB02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_LPUART4_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_USDHC1_WP,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_FLEXIO1_FLEXIO04,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_GPT2_COMPARE1,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27,pinconf);
            }break;
            
            case B28:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_USB_OTG1_OC,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_ACMP1_OUT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_LPSPI3_SCK,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_USDHC2_CD_B,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_FLEXIO1_FLEXIO03,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_GPIO1_IO28,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_FLEXPWM1_PWMA03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_12_GPIO1_IO28,pinconf);
            }break;
            
            case B29:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_LPI2C1_HREQ,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_ACMP2_OUT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_LPSPI3_PCS0,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_USDHC2_WP,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_FLEXIO1_FLEXIO02,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_GPIO1_IO29,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_FLEXPWM1_PWMB03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_13_GPIO1_IO29,pinconf);
            }break;
            
            case B30:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_LPI2C1_SCL,1);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_ACMP3_OUT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_LPSPI3_SDO,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_ENET_1588_EVENT0_OUT,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_FLEXIO1_FLEXIO01,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_GPIO1_IO30,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_14_GPIO1_IO30,pinconf);
            }break;
            
            case B31:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_LPI2C1_SDA,1);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_ACMP4_OUT,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_LPSPI3_SDI,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_ENET_1588_EVENT0_IN,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_FLEXIO1_FLEXIO00,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_GPIO1_IO31,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_15_GPIO1_IO31,pinconf);
            }break;
            
            default: break;
        }
    }
    
    else if(C0<=pin && C31>=pin)//端口C
    {
        switch(pin)
        {
            case C0:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_SEMC_DATA00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_QTIMER2_TIMER0,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_LPUART4_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_SPDIF_SR_CLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_LPSPI2_SCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_GPIO2_IO00,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_FLEXCAN1_TX,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_00_PIT_TRIGGER02,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_00_GPIO2_IO00,pinconf);
            }break;
            
            case C1:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_SEMC_DATA01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_QTIMER2_TIMER1,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_LPUART4_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_SPDIF_OUT,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_LPSPI2_PCS0,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_GPIO2_IO01,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_FLEXCAN1_RX,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_01_PIT_TRIGGER03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_01_GPIO2_IO01,pinconf);
            }break;
            
            case C2:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_SEMC_DATA02,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_QTIMER2_TIMER2,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_LPUART4_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_SPDIF_LOCK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_LPSPI2_SDO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_GPIO2_IO02,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_02_LPI2C1_SCL,1);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_02_GPIO2_IO02,pinconf);
            }break;
            
            case C3:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_SEMC_DATA03,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_QTIMER2_TIMER3,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_LPUART4_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_SPDIF_EXT_CLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_LPSPI2_SDI,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_GPIO2_IO03,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_03_LPI2C1_SDA,1);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_03_GPIO2_IO03,pinconf);
            }break;
            
            case C4:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_SEMC_DATA04,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_XBAR1_INOUT04,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_SPDIF_OUT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_SAI2_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_FLEXIO1_FLEXIO16,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_04_GPIO2_IO04,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_04_GPIO2_IO04,pinconf);
            }break;
            
            case C5:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_SEMC_DATA05,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_XBAR1_INOUT05,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_SPDIF_IN,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_SAI2_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_FLEXIO1_FLEXIO17,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_GPIO2_IO05,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_05_GPIO2_IO05,pinconf);
            }break;
            
            case C6:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_SEMC_DATA06,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_XBAR1_INOUT06,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_LPUART3_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_SAI2_TX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_FLEXIO1_FLEXIO18,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_06_GPIO2_IO06,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_06_GPIO2_IO06,pinconf);
            }break;
            
            case C7:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_SEMC_DATA07,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_XBAR1_INOUT07,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_LPUART3_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_SAI2_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_FLEXIO1_FLEXIO19,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_GPIO2_IO07,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_07_GPIO2_IO07,pinconf);
            }break;
            
            case C8:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_SEMC_DM00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_XBAR1_INOUT08,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_FLEXCAN2_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_SAI2_RX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_FLEXIO1_FLEXIO20,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_08_GPIO2_IO08,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_08_GPIO2_IO08,pinconf);
            }break;
            
            case C9:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_SEMC_WE,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_XBAR1_INOUT09,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_FLEXCAN2_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_SAI2_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_FLEXIO1_FLEXIO21,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_GPIO2_IO09,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_09_GPIO2_IO09,pinconf);
            }break;
            
            case C10:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_SEMC_CAS,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_XBAR1_INOUT10,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_LPI2C4_SDA,1);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_SAI1_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_LPSPI2_SCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_GPIO2_IO10,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_10_FLEXPWM2_PWMX00,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_10_GPIO2_IO10,pinconf);
            }break;
            
            case C11:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_SEMC_RAS,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_XBAR1_INOUT11,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_LPI2C4_SCL,1);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_SAI1_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_LPSPI2_PCS0,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_GPIO2_IO11,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_11_FLEXPWM2_PWMX01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_11_GPIO2_IO11,pinconf);
            }break;
            
            case C12:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_SEMC_CS0,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_XBAR1_INOUT12,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_LPUART6_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_SAI1_TX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_LPSPI2_SDO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_GPIO2_IO12,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_12_FLEXPWM2_PWMX02,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_12_GPIO2_IO12,pinconf);
            }break;
            
            case C13:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_SEMC_BA0,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_XBAR1_INOUT13,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_LPUART6_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_SAI1_RX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_LPSPI2_SDI,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_GPIO2_IO13,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_FLEXPWM2_PWMX03,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_CCM_PMIC_RDY,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_13_GPIO2_IO13,pinconf);
            }break;
            
            case C14:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_SEMC_BA1,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_XBAR1_INOUT14,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_LPUART6_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_SAI1_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_LPSPI2_PCS1,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_GPIO2_IO14,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_FLEXCAN1_TX,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_14_GPIO2_IO14,pinconf);
            }break;
            
            case C15:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_SEMC_ADDR10,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_XBAR1_INOUT15,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_LPUART6_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_SAI1_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_WDOG1_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_GPIO2_IO15,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_15_FLEXCAN1_RX,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_15_GPIO2_IO15,pinconf);
            }break;
            
            case C16:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_16_SEMC_ADDR00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_16_MQS_RIGHT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_16_SAI2_MCLK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_16_GPIO2_IO16,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_16_SRC_BOOT_MODE00,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_16_GPIO2_IO16,pinconf);
            }break;
            
            case C17:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_17_SEMC_ADDR01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_17_MQS_LEFT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_17_SAI3_MCLK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_17_GPIO2_IO17,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_17_SRC_BOOT_MODE01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_17_GPIO2_IO17,pinconf);
            }break;
            
            case C18:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_SEMC_ADDR02,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_XBAR1_INOUT16,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_LPI2C2_SDA,1);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_SAI1_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_FLEXIO1_FLEXIO22,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_GPIO2_IO18,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_18_SRC_BT_CFG00,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_18_GPIO2_IO18,pinconf);
            }break;
            
            case C19:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_SEMC_ADDR03,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_XBAR1_INOUT17,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_LPI2C2_SCL,1);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_SAI1_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_FLEXIO1_FLEXIO23,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_GPIO2_IO19,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_SRC_BT_CFG01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_19_GPIO2_IO19,pinconf);
            }break;
            
            case C20:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_SEMC_ADDR04,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_FLEXPWM1_PWMA03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_LPUART2_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_SAI1_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_FLEXIO1_FLEXIO24,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_GPIO2_IO20,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_SRC_BT_CFG02,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_20_GPIO2_IO20,pinconf);
            }break;
            
            case C21:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_SEMC_ADDR05,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_FLEXPWM1_PWMB03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_LPUART2_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_SAI1_RX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_FLEXIO1_FLEXIO25,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_GPIO2_IO21,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_21_SRC_BT_CFG03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_21_GPIO2_IO21,pinconf);
            }break;
            
            case C22:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_SEMC_ADDR06,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_FLEXPWM1_PWMA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_LPUART2_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_SAI1_TX_DATA03,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_FLEXIO1_FLEXIO26,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_GPIO2_IO22,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_22_SRC_BT_CFG04,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_22_GPIO2_IO22,pinconf);
            }break;
            
            case C23:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_SEMC_ADDR07,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_FLEXPWM1_PWMB02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_LPUART2_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_SAI1_TX_DATA02,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_FLEXIO1_FLEXIO27,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_GPIO2_IO23,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_SRC_BT_CFG05,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_23_GPIO2_IO23,pinconf);
            }break;
            
            case C24:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_SEMC_ADDR08,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_FLEXPWM1_PWMA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_LPUART8_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_SAI1_TX_DATA01,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_FLEXIO1_FLEXIO28,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_GPIO2_IO24,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_SRC_BT_CFG06,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_24_GPIO2_IO24,pinconf);
            }break;
            
            case C25:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_SEMC_ADDR09,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_FLEXPWM1_PWMB01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_LPUART8_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_SAI1_TX_DATA00,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_FLEXIO1_FLEXIO29,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_GPIO2_IO25,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_SRC_BT_CFG07,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_25_GPIO2_IO25,pinconf);
            }break;
            
            case C26:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_SEMC_ADDR11,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_FLEXPWM1_PWMA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_LPUART8_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_SAI1_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_FLEXIO1_FLEXIO30,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_GPIO2_IO26,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_SRC_BT_CFG08,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_26_GPIO2_IO26,pinconf);
            }break;
            
            case C27:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_SEMC_ADDR12,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_FLEXPWM1_PWMB00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_LPUART8_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_SAI1_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_FLEXIO1_FLEXIO31,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_GPIO2_IO27,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_27_SRC_BT_CFG09,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_27_GPIO2_IO27,pinconf);
            }break;
            
            case C28:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_SEMC_DQS,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_FLEXPWM2_PWMA03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_XBAR1_INOUT18,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_SAI3_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_EWM_OUT_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_GPIO2_IO28,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_GPT2_CAPTURE2,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_FLEXPWM1_PWMX00,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_28_GPIO2_IO28,pinconf);
            }break;
            
            case C29:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_SEMC_CKE,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_FLEXPWM2_PWMB03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_XBAR1_INOUT19,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_SAI3_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_WDOG2_RST_B_DEB,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_GPIO2_IO29,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_GPT2_COMPARE2,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_29_FLEXPWM1_PWMX01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_29_GPIO2_IO29,pinconf);
            }break;
            
            case C30:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_SEMC_CLK,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_FLEXPWM2_PWMA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_LPUART4_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_SAI3_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_WDOG1_RST_B_DEB,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_GPIO2_IO30,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_GPT2_COMPARE3,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_30_FLEXPWM1_PWMX02,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_30_GPIO2_IO30,pinconf);
            }break;
            
            case C31:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_SEMC_DM01,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_FLEXPWM2_PWMB02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_LPUART4_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_SAI3_RX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_WDOG2_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_GPIO2_IO31,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_GPT2_CLK,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_FLEXPWM1_PWMX03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_31_GPIO2_IO31,pinconf);
            }break;
            
            default: break;
        }
    }
    
    else if(D0<=pin && D31>=pin)//端口D
    {
        switch(pin)
        {
            case D0:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_SEMC_DATA08,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_QTIMER1_TIMER0,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_LPUART4_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_SAI3_TX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_LPSPI4_SCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_GPIO3_IO00,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_REF_24M_OUT,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_32_GPIO3_IO00,pinconf);
            }break;
            
            case D1:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_SEMC_DATA09,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_QTIMER1_TIMER1,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_LPUART4_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_SAI3_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_LPSPI4_PCS0,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_GPIO3_IO01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_33_GPIO3_IO01,pinconf);
            }break;
            
            case D2:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_SEMC_DATA10,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_QTIMER1_TIMER2,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_LPUART7_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_SAI3_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_LPSPI4_SDO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_GPIO3_IO02,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_ENET_CRS,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_34_GPIO3_IO02,pinconf);
            }break;
            
            case D3:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_SEMC_DATA11,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_QTIMER1_TIMER3,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_LPUART7_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_USDHC2_WP,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_LPSPI4_SDI,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_GPIO3_IO03,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_ENET_COL,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_35_GPIO3_IO03,pinconf);
            }break;
            
            case D4:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_SEMC_DATA12,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_FLEXPWM2_PWMA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_LPUART5_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_CCM_PMIC_RDY,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_LPSPI4_PCS1,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_GPIO3_IO04,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_ENET_RX_CLK,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_USDHC1_WP,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_36_GPIO3_IO04,pinconf);
            }break;
            
            case D5:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_SEMC_DATA13,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_FLEXPWM2_PWMB01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_LPUART5_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_MQS_RIGHT,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_LPSPI4_PCS2,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_GPIO3_IO05,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_37_ENET_RDATA03,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_37_GPIO3_IO05,pinconf);
            }break;
            
            case D6:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_SEMC_DATA14,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_FLEXPWM2_PWMA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_LPUART5_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_MQS_LEFT,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_LPSPI4_PCS3,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_GPIO3_IO06,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_ENET_RDATA02,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_USDHC1_CD_B,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_38_GPIO3_IO06,pinconf);
            }break;
            
            case D7:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_SEMC_DATA15,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_FLEXPWM2_PWMB00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_LPUART5_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_USB_OTG1_OC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_WDOG1_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_GPIO3_IO07,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_ENET_TX_ER,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_GPT1_CLK,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_39_GPIO3_IO07,pinconf);
            }break;
            
            case D8:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_SEMC_CSX00,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_XBAR1_INOUT18,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_SPDIF_OUT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_USB_OTG1_ID,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_ENET_MDIO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_GPIO3_IO08,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_ENET_TDATA03,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_GPT1_COMPARE3,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_40_GPIO3_IO08,pinconf);
            }break;
            
            case D9:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_SEMC_READY,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_XBAR1_INOUT19,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_SPDIF_IN,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_USB_OTG1_PWR,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_ENET_MDC,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_GPIO3_IO09,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_ENET_TDATA02,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_GPT1_COMPARE2,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_41_GPIO3_IO09,pinconf);
            }break;
            
//            case D10:
//            {
//                assert(0);//无此引脚 断言失败
//            }break;
//            
//            case D11:
//            {
//                assert(0);//无此引脚 断言失败
//            }break;
//            
//            case D12:
//            {
//                assert(0);//无此引脚 断言失败
//            }break;
            
            case D13:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_USDHC1_DATA2,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_QTIMER1_TIMER0,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_SAI1_MCLK,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_SAI2_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_LPI2C3_SCL,1);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_GPIO3_IO13,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_FLEXSPI_A_SS1_B,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_XBAR1_INOUT14,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_00_GPIO3_IO13,pinconf);
            }break;
            
            case D14:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_USDHC1_DATA3,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_QTIMER1_TIMER1,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_REF_24M_OUT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_SAI2_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_LPI2C3_SDA,1);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_GPIO3_IO14,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_FLEXSPI_B_SS1_B,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_XBAR1_INOUT15,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_01_GPIO3_IO14,pinconf);
            }break;
            
            case D15:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_USDHC1_CMD,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_QTIMER1_TIMER2,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_LPUART7_CTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_SAI2_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_LPSPI1_SCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_GPIO3_IO15,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_ENET_MDIO,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_XBAR1_INOUT16,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_02_GPIO3_IO15,pinconf);
            }break;
            
            case D16:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_USDHC1_CLK,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_QTIMER1_TIMER3,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_LPUART7_RTS_B,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_SAI2_RX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_LPSPI1_PCS0,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_GPIO3_IO16,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_ENET_MDC,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_03_GPIO3_IO16,pinconf);
            }break;
            
            case D17:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_USDHC1_DATA0,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_FLEXCAN2_TX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_LPUART7_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_SAI2_TX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_LPSPI1_SDO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_GPIO3_IO17,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_FLEXSPI_B_SS0_B,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_04_GPIO3_IO17,pinconf);
            }break;
            
            case D18:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_USDHC1_DATA1,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_FLEXCAN2_RX,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_LPUART7_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_SAI2_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_LPSPI1_SDI,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_GPIO3_IO18,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_FLEXSPI_B_DQS,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_05_GPIO3_IO18,pinconf);
            }break;
            
            case D19:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_USDHC1_CD_B,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_USDHC1_RESET_B,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_REF_32K_OUT,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_SAI2_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_WDOG1_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_GPIO3_IO19,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_06_XBAR1_INOUT17,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_06_GPIO3_IO19,pinconf);
            }break;
            
            case D20:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_USDHC2_DATA2,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_FLEXSPI_B_DATA03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_LPUART6_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_XBAR1_INOUT10,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_FLEXCAN1_TX,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_GPIO3_IO20,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_00_GPIO3_IO20,pinconf);
            }break;
            
            case D21:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_USDHC2_DATA3,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_FLEXSPI_B_SCLK,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_LPUART6_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_FLEXSPI_A_SS1_B,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_FLEXCAN1_RX,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_GPIO3_IO21,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_01_GPIO3_IO21,pinconf);
            }break;
            
            case D22:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_USDHC2_CMD,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_FLEXSPI_B_DATA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_LPUART8_TX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_LPI2C4_SCL,1);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_ENET_1588_EVENT1_OUT,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_GPIO3_IO22,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_CCM_CLKO1,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_02_GPIO3_IO22,pinconf);
            }break;
            
            case D23:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_USDHC2_CLK,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_FLEXSPI_B_DATA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_LPUART8_RX,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_LPI2C4_SDA,1);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_ENET_1588_EVENT1_IN,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_GPIO3_IO23,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_CCM_CLKO2,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_03_GPIO3_IO23,pinconf);
            }break;
            
            case D24:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_USDHC2_DATA0,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_FLEXSPI_B_DATA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_ENET_TX_CLK,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_ENET_REF_CLK1,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_EWM_OUT_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_GPIO3_IO24,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_04_CCM_WAIT,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_04_GPIO3_IO24,pinconf);
            }break;
            
            case D25:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_USDHC2_DATA1,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_FLEXSPI_A_DQS,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_ENET_RDATA01,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_SAI3_MCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_FLEXSPI_B_SS0_B,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_GPIO3_IO25,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_05_CCM_PMIC_RDY,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_05_GPIO3_IO25,pinconf);
            }break;
            
            case D26:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_USDHC2_CD_B,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_FLEXSPI_A_DATA03,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_ENET_RDATA00,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_SAI3_TX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_LPSPI2_PCS0,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_GPIO3_IO26,0);
                else if (ALT6 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_06_CCM_STOP,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_05_GPIO3_IO25,pinconf);
            }break;
            
            case D27:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_USDHC2_RESET_B,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_FLEXSPI_A_SCLK,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_ENET_RX_EN,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_SAI3_TX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_LPSPI2_SCK,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_07_GPIO3_IO27,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_07_GPIO3_IO27,pinconf);
            }break;
            
            case D28:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_USDHC2_DATA4,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_FLEXSPI_A_DATA00,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_ENET_RX_ER,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_SAI3_TX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_LPSPI2_SDO,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_GPIO3_IO28,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_08_GPIO3_IO28,pinconf);
            }break;
            
            case D29:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_USDHC2_DATA5,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_FLEXSPI_A_DATA02,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_ENET_TX_EN,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_SAI3_RX_BCLK,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_LPSPI2_SDI,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_GPIO3_IO29,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_09_GPIO3_IO29,pinconf);
            }break;
            
            case D30:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_USDHC2_DATA6,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_FLEXSPI_A_DATA01,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_ENET_TDATA00,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_SAI3_RX_SYNC,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_LPSPI2_PCS2,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_10_GPIO3_IO30,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_10_GPIO3_IO30,pinconf);
            }break;
            
            case D31:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_USDHC2_DATA7,0);
                else if (ALT1 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_FLEXSPI_A_SS0_B,0);
                else if (ALT2 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_ENET_TDATA01,0);
                else if (ALT3 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_SAI3_RX_DATA,0);
                else if (ALT4 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_LPSPI2_PCS3,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_11_GPIO3_IO31,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_11_GPIO3_IO31,pinconf);
            }break;
            
            default: assert(0);break;//复用错误 进入断言失败
        }
    }

    else if(F0<=pin && F31>=pin)//端口F
    {
        switch(pin)
        {
            case F0:
            {
                //设置引脚复用
                if      (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_WAKEUP_GPIO5_IO00,0);
                else if (ALT7 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_WAKEUP_NMI_GLUE_NMI,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_SNVS_WAKEUP_GPIO5_IO00,pinconf);
            }break;
            
            case F1:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_PMIC_ON_REQ_SNVS_LP_PMIC_ON_REQ,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_PMIC_ON_REQ_GPIO5_IO01,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_SNVS_PMIC_ON_REQ_GPIO5_IO01,pinconf);
            }break;
            
            case F2:
            {
                //设置引脚复用
                if      (ALT0 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_PMIC_STBY_REQ_CCM_PMIC_VSTBY_REQ,0);
                else if (ALT5 == alt)   IOMUXC_SetPinMux(IOMUXC_SNVS_PMIC_STBY_REQ_GPIO5_IO02,0);
                else                    assert(0);//复用错误 进入断言失败
                //配置引脚
                if      (pinconf)       IOMUXC_SetPinConfig(IOMUXC_SNVS_PMIC_STBY_REQ_GPIO5_IO02,pinconf);
            }break;
            
            default: assert(0);break;//复用错误 进入断言失败
        }
    }
}