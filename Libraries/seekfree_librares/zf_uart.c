/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2019,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		uart
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-02-18
 ********************************************************************************************************************/
 
 
 

#include "zf_iomuxc.h"
#include "board.h"
#include "zf_uart.h"

LPUART_Type * UARTN[] = LPUART_BASE_PTRS;

#define LPUART_PIN_CONF SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //配置UART引脚默认配置

void uart_iomuxc(UARTN_enum uartn, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin)
{
    switch(uartn)
    {
        case USART_1:
        {
            if      (UART1_TX_B6 == tx_pin)     iomuxc_pinconf(B6 ,ALT2,LPUART_PIN_CONF); 
            if      (UART1_RX_B7 == rx_pin)     iomuxc_pinconf(B7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_2:
        {
            if      (UART2_TX_B24 == tx_pin)    iomuxc_pinconf(B24,ALT2,LPUART_PIN_CONF); 
            else if (UART2_TX_C22 == tx_pin)    iomuxc_pinconf(C22,ALT2,LPUART_PIN_CONF); 
            
            if      (UART2_RX_B25 == rx_pin)    iomuxc_pinconf(B25,ALT2,LPUART_PIN_CONF); 
            else if (UART2_RX_C23 == rx_pin)    iomuxc_pinconf(C23,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_3:
        {
            if      (UART3_TX_B14 == tx_pin)    iomuxc_pinconf(B14,ALT2,LPUART_PIN_CONF); 
            else if (UART3_TX_C6  == tx_pin)    iomuxc_pinconf(C6 ,ALT2,LPUART_PIN_CONF); 
                                                               
            if      (UART3_RX_B15 == rx_pin)    iomuxc_pinconf(B15,ALT2,LPUART_PIN_CONF); 
            else if (UART3_RX_C7  == rx_pin)    iomuxc_pinconf(C7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_4:
        {
            if      (UART4_TX_B26 == tx_pin)    iomuxc_pinconf(B26,ALT2,LPUART_PIN_CONF); 
            else if (UART4_TX_C2  == tx_pin)    iomuxc_pinconf(C2 ,ALT2,LPUART_PIN_CONF); 
            else if (UART4_TX_D0  == tx_pin)    iomuxc_pinconf(D0 ,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART4_RX_B27 == rx_pin)    iomuxc_pinconf(B27,ALT2,LPUART_PIN_CONF); 
            else if (UART4_RX_C3  == rx_pin)    iomuxc_pinconf(C3 ,ALT2,LPUART_PIN_CONF); 
            else if (UART4_RX_D1  == rx_pin)    iomuxc_pinconf(D1 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_5:
        {
            if      (UART5_TX_B10 == tx_pin)    iomuxc_pinconf(B10,ALT2,LPUART_PIN_CONF); 
            else if (UART5_TX_D6  == tx_pin)    iomuxc_pinconf(D6 ,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART5_RX_B11 == rx_pin)    iomuxc_pinconf(B11,ALT2,LPUART_PIN_CONF); 
            else if (UART5_RX_D7  == rx_pin)    iomuxc_pinconf(D7 ,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_6:
        {
            if      (UART6_TX_C12 == tx_pin)    iomuxc_pinconf(C12,ALT2,LPUART_PIN_CONF); 
            else if (UART6_TX_D20 == tx_pin)    iomuxc_pinconf(D20,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART6_RX_C13 == rx_pin)    iomuxc_pinconf(C13,ALT2,LPUART_PIN_CONF); 
            else if (UART6_RX_D21 == rx_pin)    iomuxc_pinconf(D21,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_7:
        {
            if      (UART7_TX_D2  == tx_pin)    iomuxc_pinconf(D2 ,ALT2,LPUART_PIN_CONF); 
            else if (UART7_TX_D17 == tx_pin)    iomuxc_pinconf(D17,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART7_RX_D3  == rx_pin)    iomuxc_pinconf(D3 ,ALT2,LPUART_PIN_CONF); 
            else if (UART7_RX_D18 == rx_pin)    iomuxc_pinconf(D18,ALT2,LPUART_PIN_CONF); 
        }break;
        case USART_8:
        {
            if      (UART8_TX_C26 == tx_pin)    iomuxc_pinconf(C26,ALT2,LPUART_PIN_CONF); 
            else if (UART8_TX_D22 == tx_pin)    iomuxc_pinconf(D22,ALT2,LPUART_PIN_CONF); 
                                                                  
            if      (UART8_RX_C27 == rx_pin)    iomuxc_pinconf(C27,ALT2,LPUART_PIN_CONF); 
            else if (UART8_RX_D23 == rx_pin)    iomuxc_pinconf(D23,ALT2,LPUART_PIN_CONF); 
        }break;
        
        default: assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口初始化
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      baud            串口波特率
//  @param      tx_pin          串口发送引脚
//  @param      rx_pin          串口接收引脚
//  @return     uint32          实际波特率
//  Sample usage:               uart_init(USART_0,115200,UART0_TX_A25,UART0_RX_A24);       // 初始化串口0 波特率115200 发送引脚使用P025 接收引脚使用P024
//-------------------------------------------------------------------------------------------------------------------
void uart_init(UARTN_enum uartn, uint32 baud, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin)
{
    uint32_t uartClkSrcFreq;
    lpuart_config_t lpuartConfig;
    
    uart_iomuxc(uartn,tx_pin,rx_pin);
    uartClkSrcFreq = BOARD_DebugConsoleSrcFreq();
    LPUART_GetDefaultConfig(&lpuartConfig);
    lpuartConfig.baudRate_Bps = baud;
    lpuartConfig.enableTx = true;
    lpuartConfig.enableRx = true;
    
    LPUART_Init(UARTN[uartn],&lpuartConfig,uartClkSrcFreq); //第一次初始化便于打开时钟
    LPUART_Deinit(UARTN[uartn]);                            //复位外设
    LPUART_Init(UARTN[uartn],&lpuartConfig,uartClkSrcFreq); //重新初始化设置正确的参数
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口字节输出
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      dat             需要发送的字节
//  @return     void        
//  Sample usage:               uart_putchar(USART_1,0xA5);       // 串口1发送0xA5
//-------------------------------------------------------------------------------------------------------------------
void uart_putchar(UARTN_enum uartn, uint8 dat)
{
    while (!(UARTN[uartn]->STAT & LPUART_STAT_TDRE_MASK));
    LPUART_WriteByte(UARTN[uartn],dat);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口发送数组
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *buff           要发送的数组地址
//  @param      len             发送长度
//  @return     void
//  Sample usage:               uart_putbuff(USART_1,&a[0],5);
//-------------------------------------------------------------------------------------------------------------------
void uart_putbuff(UARTN_enum uartn, uint8 *buff, uint32 len)
{
    LPUART_WriteBlocking(UARTN[uartn], buff, len);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口发送字符串
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *str            要发送的字符串地址
//  @return     void
//  Sample usage:               uart_putstr(USART_1,"i lvoe you"); 
//-------------------------------------------------------------------------------------------------------------------
void uart_putstr(UARTN_enum uartn, const uint8 *str)
{
    while(*str)
    {
        uart_putchar(uartn, *str++);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      读取串口接收的数据（whlie等待）
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *dat            接收数据的地址
//  @return     void        
//  Sample usage:               uint8 dat; uart_getchar(USART_1,&dat);       // 接收串口1数据  存在在dat变量里
//-------------------------------------------------------------------------------------------------------------------
void uart_getchar(UARTN_enum uartn, uint8 *dat)
{
    while ((UARTN[uartn]->WATER & LPUART_WATER_RXCOUNT_MASK) >> LPUART_WATER_RXCOUNT_SHIFT);
    *dat = LPUART_ReadByte(UARTN[uartn]);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      读取串口接收的数据（查询接收）
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *dat            接收数据的地址
//  @return     uint8           1：接收成功   0：未接收到数据
//  Sample usage:               uint8 dat; uart_query(USART_1,&dat);       // 接收串口1数据  存在在dat变量里
//-------------------------------------------------------------------------------------------------------------------
uint8 uart_query(UARTN_enum uartn, uint8 *dat)
{
    if((UARTN[uartn]->WATER & LPUART_WATER_RXCOUNT_MASK) >> LPUART_WATER_RXCOUNT_SHIFT)
    {
        *dat = LPUART_ReadByte(UARTN[uartn]);
        return 1;
    }
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口发送空闲中断设置
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      status          1：打开中断   0：关闭中断
//  @return     void        
//  Sample usage:               uart_tx_irq(USART_1,1);       // 打开串口1发送完成中断
//-------------------------------------------------------------------------------------------------------------------
void uart_tx_irq(UARTN_enum uartn,uint8 status)
{
    if(status)  
    {
        LPUART_EnableInterrupts(UARTN[uartn], kLPUART_TransmissionCompleteInterruptEnable);
    }
    else
    {
        LPUART_DisableInterrupts(UARTN[uartn], kLPUART_TransmissionCompleteInterruptEnable);
    }
    
    //NVIC_SetPriority((IRQn_Type)((IRQn_Type)(uartn) + LPUART1_IRQn),0);//优先级设置 范围0-15 越小优先级越高
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口接收中断设置
//  @param      uartn           串口模块号(USART_1,USART_2,USART_3,USART_4,USART_5,USART_6,USART_7,USART_8)
//  @param      *handle			串口中断结构体变量	
//  @param      *callback		中断后需要执行的函数
//  @param      *tx_buff		需要发送数据的地址
//  @param      *tx_count	    需要发送的字节数
//  @param      *rx_buff		需要接收数据的地址
//  @param      *rx_count		需要接收的字节数	
//  @return     void        
//  Sample usage:               uart_set_handle(USART_1, &csi_g_lpuartHandle, uart1_call_back, NULL, 0, buff, 1);//串口1 的中断回调函数设置为uart1_call_back 不需要发送中断 接收缓存为buff 接收到1个字节就中断
//-------------------------------------------------------------------------------------------------------------------
void uart_rx_irq(UARTN_enum uartn,uint8 status)
{
    if(status)  
    {
        LPUART_EnableInterrupts(UARTN[uartn], kLPUART_RxDataRegFullInterruptEnable);
    }
    else
    {
        LPUART_DisableInterrupts(UARTN[uartn], kLPUART_RxDataRegFullInterruptEnable);
    }
    //NVIC_SetPriority((IRQn_Type)((IRQn_Type)(uartn) + LPUART1_IRQn),0);//优先级设置 范围0-15 越小优先级越高
}

void uart_set_handle(UARTN_enum uartn, lpuart_handle_t *handle, lpuart_transfer_callback_t callback, uint8 *tx_buff, uint32 tx_count, uint8 *rx_buff, uint32 rx_count)
{
    LPUART_TransferCreateHandle(UARTN[uartn], handle, callback, NULL);
    //设置接收缓冲区与发送缓冲区
    handle->txData = tx_buff;
    handle->txDataSize = tx_count;
    handle->rxData = rx_buff;
    handle->rxDataSize = rx_count;
    
}

//--------------------------------------------------------------------------
//  @brief      山外多功能调试助手上位机，虚拟示波器显示函数
//  @param      wareaddr    波形数组起始地址
//  @param      waresize    波形数组占用空间的大小
//  @since      v5.0
//  Sample usage:
//             具体用法参考这帖子:
//            【山外资料】陀螺仪和加速度 上位机显示例程 - 智能车资料区
//             http://vcan123.com/forum.php?mod=viewthread&tid=6253&ctid=27
//--------------------------------------------------------------------------
void vcan_sendware(void *wareaddr, uint32_t waresize)
{
    #define CMD_WARE     3
    uint8_t cmdf[2] = {CMD_WARE, ~CMD_WARE};    //串口调试 使用的前命令
    uint8_t cmdr[2] = {~CMD_WARE, CMD_WARE};    //串口调试 使用的后命令

    uart_putbuff(DEBUG_UART, cmdf, sizeof(cmdf));    //先发送前命令
    uart_putbuff(DEBUG_UART, (uint8_t *)wareaddr, waresize);    //发送数据
    uart_putbuff(DEBUG_UART, cmdr, sizeof(cmdr));    //发送后命令

}

