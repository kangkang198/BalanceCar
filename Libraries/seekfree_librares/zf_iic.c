/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		iic
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/

#include "zf_iomuxc.h"
#include "zf_iic.h"
 
#define IIC_PIN_CONF  SPEED_100MHZ | KEEPER_EN | PULLUP_22K | DSE_R0_6 | OD_EN  //配置IIC引脚默认配置


LPI2C_Type * IICN[] = LPI2C_BASE_PTRS;

#define LPI2C_CLOCK_SOURCE_DIVIDER (0x05)

#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1))



void iic_iomuxc(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin)
{
    switch(iic_n)
    {
        case IIC_1:
        {
            if      (IIC1_SDA_B31 == sda_pin) iomuxc_pinconf(B31 ,ALT0,IIC_PIN_CONF);
            else if (IIC1_SDA_C3  == sda_pin) iomuxc_pinconf(C3  ,ALT6,IIC_PIN_CONF);
            else    assert(0);
            
            if      (IIC1_SCL_B30 == scl_pin) iomuxc_pinconf(B30 ,ALT0,IIC_PIN_CONF);
            else if (IIC1_SCL_C2  == scl_pin) iomuxc_pinconf(C2  ,ALT6,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_2:
        {
            if      (IIC2_SDA_B25 == sda_pin) iomuxc_pinconf(B25 ,ALT0,IIC_PIN_CONF);
            else if (IIC2_SDA_C18 == sda_pin) iomuxc_pinconf(C18 ,ALT2,IIC_PIN_CONF);
            else    assert(0);                               
                                                             
            if      (IIC2_SCL_B24 == scl_pin) iomuxc_pinconf(B24 ,ALT0,IIC_PIN_CONF);
            else if (IIC2_SCL_C19 == scl_pin) iomuxc_pinconf(C19 ,ALT2,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_3:
        {
            if      (IIC3_SDA_B9  == sda_pin) iomuxc_pinconf(B9  ,ALT1,IIC_PIN_CONF);
            else if (IIC3_SDA_D14 == sda_pin) iomuxc_pinconf(D14 ,ALT4,IIC_PIN_CONF);
            else    assert(0);                                  
                                                                
            if      (IIC3_SCL_B8  == scl_pin) iomuxc_pinconf(B8  ,ALT1,IIC_PIN_CONF);
            else if (IIC3_SCL_D13 == scl_pin) iomuxc_pinconf(D13 ,ALT4,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        case IIC_4:
        {
            if      (IIC4_SDA_C10 == sda_pin) iomuxc_pinconf(C10 ,ALT2,IIC_PIN_CONF);
            else if (IIC4_SDA_D23 == sda_pin) iomuxc_pinconf(D23 ,ALT3,IIC_PIN_CONF);
            else    assert(0);                                  
                                                                
            if      (IIC4_SCL_C11 == scl_pin) iomuxc_pinconf(C11 ,ALT2,IIC_PIN_CONF);
            else if (IIC4_SCL_D22 == scl_pin) iomuxc_pinconf(D22 ,ALT3,IIC_PIN_CONF);
            else    assert(0);
        }break;
        
        default:assert(0);break;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      IIC初始化
//  @param      iic_n           IIC模块(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      sda_pin         选择IIC数据引脚
//  @param      scl_pin         选择IIC时钟引脚
//  @param      baud            设置IIC的波特率
//  @return     void
//  Sample usage:               iic_init(IIC_2, IIC2_SDA_B25, IIC2_SCL_B24,400*1000);//硬件IIC初始化     
//-------------------------------------------------------------------------------------------------------------------
void iic_init(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin, uint32 baud)
{
    lpi2c_master_config_t masterConfig;
    
    iic_iomuxc(iic_n, sda_pin, scl_pin);

    CLOCK_SetMux(kCLOCK_Lpi2cMux, 0);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);
    
    /*
     * masterConfig.debugEnable = false;
     * masterConfig.ignoreAck = false;
     * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
     * masterConfig.baudRate_Hz = 100000U;
     * masterConfig.busIdleTimeout_ns = 0;
     * masterConfig.pinLowTimeout_ns = 0;
     * masterConfig.sdaGlitchFilterWidth_ns = 0;
     * masterConfig.sclGlitchFilterWidth_ns = 0;
     */
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Hz = baud;
    LPI2C_MasterInit(IICN[iic_n], &masterConfig, LPI2C_CLOCK_FREQUENCY);//第一次初始化便于打开时钟
    LPI2C_MasterReset(IICN[iic_n]);                                     //复位外设
    LPI2C_MasterInit(IICN[iic_n], &masterConfig, LPI2C_CLOCK_FREQUENCY);//重新初始化设置正确的参数
    
    
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      写入一个字节数据到I2C设备指定寄存器地址
//  @param      iic_n       IIC模块(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     从机地址(7位地址)
//  @param      reg         从机寄存器地址
//  @param      data        需要发送的数据
//  @return                 返回的状态值 0：成功  1：失败
//  @since      v2.0
//  Sample usage:       	iic_write_reg(IIC_2, 0x2D, 0x50,2);     //写入数据2到0x50地址，从机地址为0x2D
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_write_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 data)
{
    status_t reVal = kStatus_Fail;
    
    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &data, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      读取I2C设备指定地址寄存器的数据
//  @param      iic_n       IIC模块(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     从机地址(7位地址)
//  @param      reg         从机寄存器地址
//  @param      *data       读取回来的数据
//  @return                 返回的状态值 0：成功  1：失败
//  @since      v2.0
//  Sample usage:       	uint8 value = iic_read_reg(IIC_2, 0x2D, 0x50);//读取0x50地址的数据，从机地址为0x2D
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_read_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data)
{
    status_t reVal = kStatus_Fail;

    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterRepeatedStart(IICN[iic_n], slaveid, kLPI2C_Read);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterReceive(IICN[iic_n], data, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      读取I2C设备指定地址寄存器的数据
//  @param      iic_n       IIC模块(IIC_1,IIC_2,IIC_3,IIC_4)
//  @param      slaveid     从机地址(7位地址)
//  @param      reg         从机寄存器地址
//  @param      data        读取的数据存储的地址
//  @param      num         读取字节数
//  @return                 返回的状态值 0：成功  1：失败
//  @since      v2.0
//  Sample usage:       	uint8 value = iic_read_reg(IIC_2, 0x2D, 0x50, 10, buf);//读取0x50地址的数据，从机地址为0x2D开始的10个字节
//-------------------------------------------------------------------------------------------------------------------
uint8 iic_read_reg_bytes(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data, uint8 num)
{
    status_t reVal = kStatus_Fail;
    
    reVal = LPI2C_MasterStart(IICN[iic_n], slaveid, kLPI2C_Write);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    while (LPI2C_MasterGetStatusFlags(IICN[iic_n]) & kLPI2C_MasterNackDetectFlag);
    
    reVal = LPI2C_MasterSend(IICN[iic_n], &reg, 1);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterRepeatedStart(IICN[iic_n], slaveid, kLPI2C_Read);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterReceive(IICN[iic_n], data, num);
    if (reVal != kStatus_Success)   return kStatus_Fail;
    
    reVal = LPI2C_MasterStop(IICN[iic_n]);
    if (reVal != kStatus_Success)   return kStatus_Fail;

    return kStatus_Success;
}