/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		spi
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_spi_h
#define _zf_spi_h


#include "common.h"
#include "fsl_lpspi.h"



//此枚举定义不允许用户修改
typedef enum
{            
    SPI1_SCK_B10  = 1*21+0*3, SPI1_SCK_D15,
    SPI1_MOSI_B12 = 1*21+1*3, SPI1_MOSI_D17,
    SPI1_MISO_B13 = 1*21+2*3, SPI1_MISO_D18,
    SPI1_CS0_B11  = 1*21+3*3, SPI1_CS0_D16,
    SPI1_CS1_B20  = 1*21+4*3,
    SPI1_CS2_B21  = 1*21+5*3,
    SPI1_CS3_B22  = 1*21+6*3,
                                                 
    SPI2_SCK_C0   = 2*21+0*3, SPI2_SCK_C10,  SPI2_SCK_D27,
    SPI2_MOSI_C2  = 2*21+1*3, SPI2_MOSI_C12, SPI2_MOSI_D28,
    SPI2_MISO_C3  = 2*21+2*3, SPI2_MISO_C13, SPI2_MISO_D29,
    SPI2_CS0_C1   = 2*21+3*3, SPI2_CS0_C11,  SPI2_CS0_D26,
    SPI2_CS1_C14  = 2*21+4*3,
    SPI2_CS2_D30  = 2*21+5*3,
    SPI2_CS3_D31  = 2*21+6*3,
                                                 
    SPI3_SCK_B28  = 3*21+0*3,
    SPI3_MOSI_B30 = 3*21+1*3,
    SPI3_MISO_B31 = 3*21+2*3,
    SPI3_CS0_B29  = 3*21+3*3,
    SPI3_CS1_B25  = 3*21+4*3,
    SPI3_CS2_B24  = 3*21+5*3,
    SPI3_CS3_B23  = 3*21+6*3,
                                                 
    SPI4_SCK_B18  = 4*21+0*3, SPI4_SCK_D0,
    SPI4_MOSI_B20 = 4*21+1*3, SPI4_MOSI_D2,
    SPI4_MISO_B21 = 4*21+2*3, SPI4_MISO_D3,
    SPI4_CS0_B19  = 4*21+3*3, SPI4_CS0_D1,
    SPI4_CS1_D4   = 4*21+4*3,
    SPI4_CS2_D5   = 4*21+5*3,
    SPI4_CS3_D6   = 4*21+6*3,
                           
    SPI_CS_NOT_USE,

}SPI_PIN_enum;

//此枚举定义不允许用户修改
typedef enum //枚举串口号
{
    SPI_0,//RT1021没有SPI0 这里仅用于占位
    SPI_1,
    SPI_2,
    SPI_3,
    SPI_4,
}SPIN_enum;

void spi_init(SPIN_enum spi_n, SPI_PIN_enum sck_pin, SPI_PIN_enum mosi_pin, SPI_PIN_enum miso_pin, SPI_PIN_enum cs_pin, uint8 mode, uint32 baud);
void spi_mosi(SPIN_enum spi_n, SPI_PIN_enum cs_pin, uint8 *modata, uint8 *midata, uint32 len, uint8 continuous);

#endif