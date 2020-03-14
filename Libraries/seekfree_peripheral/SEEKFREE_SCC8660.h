/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		凌瞳摄像头(SCC8660) RT FLEXIO接口
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598 & QQ2380006440)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.32.4 or MDK 5.24 或更高
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-09-04
 * @note		
					接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SDA(摄像头的RX)     查看SEEKFREE_SCC8660.h文件中的SCC8660_COF_UART_TX宏定义
						SCL(摄像头的TX)     查看SEEKFREE_SCC8660.h文件中的SCC8660_COF_UART_RX宏定义
                        场中断(VSY)         查看SEEKFREE_SCC8660.h文件中的SCC8660_VSYNC_PIN宏定义
						行中断(HREF)		查看SEEKFREE_SCC8660.h文件中的SCC8660_HREF_PIN宏定义
						像素中断(PCLK)      查看SEEKFREE_SCC8660.h文件中的SCC8660_PCLK_PIN宏定义
						数据口(D0-D7)		查看SEEKFREE_SCC8660.h文件中的SCC8660_DATA_PIN宏定义
					------------------------------------ 
	
					默认分辨率               160*120
					默认FPS                  20帧
 ********************************************************************************************************************/



#ifndef _SEEKFREE_SCC8660_h
#define _SEEKFREE_SCC8660_h


#include "common.h"
#include "zf_uart.h"




//由于RT1021RAM 不过 因此主要采集分辨率为160*120 180*160

#define SCC8660_PIC_W           180		            //实际图像分辨率宽度	可选参数为：160 180 240
#define SCC8660_PIC_H           160		            //实际图像分辨率高度	可选参数为：120 160 180

#define SCC8660_W		        SCC8660_PIC_W*2		//此参数为图像数据存储宽度 请勿修改
#define SCC8660_H		        SCC8660_PIC_H       //此参数为图像数据存储高度 请勿修改

//--------------------------------------------------------------------------------------------------
//引脚配置
//--------------------------------------------------------------------------------------------------
#define SCC8660_COF_UART        USART_3             //配置摄像头所使用到的串口     
#define SCC8660_COF_UART_TX     UART3_TX_C6
#define SCC8660_COF_UART_RX     UART3_RX_C7

#define SCC8660_VSYNC_PIN       B21                 //场中断引脚
#define SCC8660_VSYNC_IRQN      GPIO1_Combined_16_31_IRQn   //中断号
                                
                                
#define SCC8660_DATA_PIN        FLEXIO1_IO0_B31 //定义D0数据引脚  假设D0定义为FLEXIO1_IO8_B23 那么D1所使用的引脚则为FLEXIO1_IO9_B22，依次类推
#define SCC8660_PCLK_PIN        FLEXIO1_IO8_B23 //定义像素时钟引脚
#define SCC8660_HREF_PIN        FLEXIO1_IO9_B22 //定义行信号引脚



typedef enum
{
    SCC8660_INIT 			= 0x00, //摄像头初始化命令
    SCC8660_AUTO_EXP,               //自动曝光命令
    SCC8660_BRIGHT,                 //亮度命令
    SCC8660_FPS,                    //摄像头帧率命令
    SCC8660_SET_COL,                //图像列命令
    SCC8660_SET_ROW,                //图像行命令
    SCC8660_PCLK_DIV,               //像素时钟分频命令
    SCC8660_PCLK_MODE,              //像素时钟模式命令
    SCC8660_COLOR_MODE,             //色彩模式命令
    SCC8660_DATA_FORMAT,	        //数据格式命令
	SCC8660_MANUAL_WB,	            //手动白平衡命令
    SCC8660_CONFIG_FINISH,          //非命令位，主要用来占位计数
        
    SCC8660_GET_WHO_AM_I = 0xEF,    //我是谁命令，用于判断摄像头型号
    SCC8660_SET_BRIGHT = 0xF0,      //单独设置亮度
    SCC8660_GET_STATUS 	= 0XF1,     //获取摄像头配置命令
    SCC8660_GET_VERSION	= 0xF2,     //固件版本号
	SCC8660_SET_MANUAL_WB = 0xF3,   //单独设置手动白平衡
        
    SCC8660_SET_REG_ADDR	= 0xFE, 
    SCC8660_SET_REG_DATA	= 0xFF, 
}SCC8660_CMD;



extern uint16 scc8660_image[SCC8660_PIC_H][SCC8660_PIC_W];
extern uint8  scc8660_finish_flag;                  //一场图像采集完成标志位



void    scc8660_set_all_config(UARTN_enum uartn, uint16 buff[SCC8660_CONFIG_FINISH-1][2]);
void    scc8660_get_all_config(UARTN_enum uartn, uint16 buff[SCC8660_CONFIG_FINISH-1][2]);
uint16  scc8660_get_id(UARTN_enum uartn);
uint16  scc8660_get_config(UARTN_enum uartn, uint8 config);
uint16  scc8660_get_version(UARTN_enum uartn);
uint16  scc8660_set_bright(UARTN_enum uartn, uint16 data);
uint16  scc8660_set_maunal_wb(UARTN_enum uartn, uint16 data);
uint16  scc8660_set_reg_addr(UARTN_enum uartn, uint8 reg, uint16 data);

void scc8660_init(void);
void scc8660_vsync(void);
void scc8660_dma(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

void    csi_seekfree_sendimg_scc8660(UARTN_enum uartn, uint8 *image, uint16 width, uint16 height);
void inline color_camera_take_point(uint16 *dat, uint16 width, uint16 height, uint8 *r, uint8 *g, uint8 *b);


#endif
