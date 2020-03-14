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
 
 
#ifndef _zf_iic_h
#define _zf_iic_h

#include "common.h"
#include "fsl_lpi2c.h"

//此枚举定义不允许用户修改
typedef enum //枚举IIC引脚
{
    IIC1_SDA_B31,  IIC1_SDA_C3 ,
    IIC1_SCL_B30,  IIC1_SCL_C2 ,
                               
    IIC2_SDA_B25,  IIC2_SDA_C18,
    IIC2_SCL_B24,  IIC2_SCL_C19,
                               
    IIC3_SDA_B9 ,  IIC3_SDA_D14,
    IIC3_SCL_B8 ,  IIC3_SCL_D13,
                              
    IIC4_SDA_C10,  IIC4_SDA_D23,
    IIC4_SCL_C11,  IIC4_SCL_D22,
    
}IIC_PIN_enum;

//此枚举定义不允许用户修改
typedef enum //枚举IIC编号
{
    IIC_0,//RT1021没有IIC_0 这里仅用于占位
    IIC_1,
    IIC_2,
    IIC_3,
    IIC_4,
}IICN_enum;



void iic_init(IICN_enum iic_n, IIC_PIN_enum sda_pin, IIC_PIN_enum scl_pin, uint32 baud);
uint8 iic_write_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 data);
uint8 iic_read_reg(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data);
uint8 iic_read_reg_bytes(IICN_enum iic_n, uint8 slaveid, uint8 reg, uint8 *data, uint8 num);


#endif