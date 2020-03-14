/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		总钻风
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 * @note		
					接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SDA(51的RX)         C6(UART3_TX_C6)
						SCL(51的TX)         C7(UART3_RX_C7)
						场中断(VSY)         B21
						行中断(HREF)		B22
						像素中断(PCLK)      B23
						数据口(D0-D7)		B31-B24 B31对应摄像头接口D0
					------------------------------------ 
	
					默认分辨率是            188*120
					默认FPS                 50帧
 ********************************************************************************************************************/



#ifndef _SEEKFREE_MT9V032_h
#define _SEEKFREE_MT9V032_h

#include "common.h"
#include "zf_uart.h"

//配置摄像头参数
#define MT9V032_DMA_CH          DMA_CH0         //定义摄像头的DMA采集通道
#define MT9V032_W               320             //图像宽度  范围1-752       RT102X RT105X RT106X 采集时列宽度必须为4的倍数
#define MT9V032_H               120             //图像高度	范围1-480



//--------------------------------------------------------------------------------------------------
//引脚配置
//--------------------------------------------------------------------------------------------------
#define MT9V032_COF_UART        USART_3         //配置摄像头所使用到的串口     
#define MT9V032_COF_UART_TX     UART3_TX_C6
#define MT9V032_COF_UART_RX     UART3_RX_C7

#define MT9V032_VSYNC_PIN       B21             //场中断引脚
#define MT9V032_VSYNC_IRQN      GPIO1_Combined_16_31_IRQn   //中断号


#define MT9V032_DATA_PIN        FLEXIO1_IO0_B31 //定义D0数据引脚  假设D0定义为FLEXIO1_IO8_B23 那么D1所使用的引脚则为FLEXIO1_IO9_B22，依次类推
#define MT9V032_PCLK_PIN        FLEXIO1_IO8_B23 //定义像素时钟引脚
#define MT9V032_HREF_PIN        FLEXIO1_IO9_B22 //定义行信号引脚

             
                        
//摄像头命令枚举
typedef enum
{
    INIT = 0,               //摄像头初始化命令
    AUTO_EXP,               //自动曝光命令
    EXP_TIME,               //曝光时间命令
    FPS,                    //摄像头帧率命令
    SET_COL,                //图像列命令
    SET_ROW,                //图像行命令
    LR_OFFSET,              //图像左右偏移命令
    UD_OFFSET,              //图像上下偏移命令
    GAIN,                   //图像偏移命令
    CONFIG_FINISH,          //非命令位，主要用来占位计数
    
    SET_EXP_TIME = 0XF0,    //单独设置曝光时间命令
    GET_STATUS,             //获取摄像头配置命令
    GET_VERSION,            //固件版本号命令
	
    SET_ADDR = 0XFE,        //寄存器地址命令
    SET_DATA                //寄存器数据命令
}CMD;
     
     
     
                            
                            

extern uint8 mt9v032_finish_flag;  //一场图像采集完成标志位
extern uint8 image[MT9V032_H][MT9V032_W];      //内部使用
                            
                            
void camera_init(void);
void mt9v032_vsync(void);
void mt9v032_dma(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);
void seekfree_sendimg_032(UARTN_enum uartn);




#endif

