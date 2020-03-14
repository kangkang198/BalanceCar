/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		camera
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
#ifndef _zf_camera_h
#define _zf_camera_h

#include "common.h"
#include "fsl_flexio.h"
#include "fsl_dmamux.h"
#include "fsl_edma.h"




//此枚举定义不允许用户修改
typedef enum    //FLEXIO 引脚定义
{
    FLEXIO1_IO0_B31,
    FLEXIO1_IO1_B30,
    FLEXIO1_IO2_B29,
    FLEXIO1_IO3_B28,
    FLEXIO1_IO4_B27,
    FLEXIO1_IO5_B26,
    FLEXIO1_IO6_B25,
    FLEXIO1_IO7_B24,
    FLEXIO1_IO8_B23,
    FLEXIO1_IO9_B22,
    FLEXIO1_IO10_B21,
    FLEXIO1_IO11_B20,
    FLEXIO1_IO12_B19,
    FLEXIO1_IO13_B18,
    FLEXIO1_IO14_B17,
    FLEXIO1_IO15_B16,
    FLEXIO1_IO16_C4,
    FLEXIO1_IO17_C5,
    FLEXIO1_IO18_C6,
    FLEXIO1_IO19_C7,
    FLEXIO1_IO20_C8,
    FLEXIO1_IO21_C9,
    FLEXIO1_IO22_C18,
    FLEXIO1_IO23_C19,
    FLEXIO1_IO24_C20,
    FLEXIO1_IO25_C21,
    FLEXIO1_IO26_C22,
    FLEXIO1_IO27_C23,
    FLEXIO1_IO28_C24,
    FLEXIO1_IO29_C25,
    FLEXIO1_IO30_C26,
    FLEXIO1_IO31_C27,
}FLEXIO_PIN_enum;





void flexio_camera(FLEXIO_PIN_enum dat_pin_start, FLEXIO_PIN_enum pclk_pin, FLEXIO_PIN_enum href_pin);
void flexio_enable(uint8 enable);
void flexio_enable_rxdma(void);
void flexio_flag_clear(void);

void dma_mux_init(void);
void flexio_dma_init(uint8 *dest_addr, uint32 count, edma_callback callback);
void dma_restart(uint8 *dest_addr);


#endif