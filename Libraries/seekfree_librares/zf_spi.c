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
 

#include "zf_iomuxc.h"
#include "zf_spi.h"


#define LPSPI_PIN_CONF  SPEED_100MHZ | KEEPER_EN | DSE_R0_6 //配置SPI引脚默认配置
#define LPSPI_CLK_DIV   3
#define LPSPI_CLK_SRC   2



LPSPI_Type * SPIN[] = LPSPI_BASE_PTRS;

void spi_iomuxc(SPIN_enum spi_n, SPI_PIN_enum sck_pin, SPI_PIN_enum mosi_pin, SPI_PIN_enum miso_pin, SPI_PIN_enum cs_pin)
{
    switch(spi_n)
    {
        case SPI_1:
        {
            if      (SPI1_SCK_B10  == sck_pin)  iomuxc_pinconf(B10,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_SCK_D15  == sck_pin)  iomuxc_pinconf(D15,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI1_MOSI_B12 == mosi_pin) iomuxc_pinconf(B12,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_MOSI_D17 == mosi_pin) iomuxc_pinconf(D17,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
                                                               
            if      (SPI1_MISO_B13 == miso_pin) iomuxc_pinconf(B13,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_MISO_D18 == miso_pin) iomuxc_pinconf(D18,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI1_CS0_B11  == cs_pin)   iomuxc_pinconf(B11,ALT1,LPSPI_PIN_CONF);
            else if (SPI1_CS0_D16  == cs_pin)   iomuxc_pinconf(B20,ALT4,LPSPI_PIN_CONF);
            else if (SPI1_CS1_B20  == cs_pin)   iomuxc_pinconf(B20,ALT6,LPSPI_PIN_CONF);
            else if (SPI1_CS2_B21  == cs_pin)   iomuxc_pinconf(B21,ALT6,LPSPI_PIN_CONF);
            else if (SPI1_CS3_B22  == cs_pin)   iomuxc_pinconf(B22,ALT6,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//不使用片选引脚
            else                                assert(0);//引脚错误 进入断言失败
        }break;
        
        case SPI_2:
        {
            if      (SPI2_SCK_C0   == sck_pin)  iomuxc_pinconf(C0 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_SCK_C10  == sck_pin)  iomuxc_pinconf(C10,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_SCK_D27  == sck_pin)  iomuxc_pinconf(D27,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI2_MOSI_C2  == mosi_pin) iomuxc_pinconf(C2 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MOSI_C12 == mosi_pin) iomuxc_pinconf(C12,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MOSI_D28 == mosi_pin) iomuxc_pinconf(D28,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
                                                               
            if      (SPI2_MISO_C3  == miso_pin) iomuxc_pinconf(C3 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MISO_C13 == miso_pin) iomuxc_pinconf(C13,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_MISO_D29 == miso_pin) iomuxc_pinconf(D29,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI2_CS0_C1   == cs_pin)   iomuxc_pinconf(C1 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS0_C11  == cs_pin)   iomuxc_pinconf(C11,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS0_D26  == cs_pin)   iomuxc_pinconf(D26,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS1_C14  == cs_pin)   iomuxc_pinconf(C14,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS2_D30  == cs_pin)   iomuxc_pinconf(D30,ALT4,LPSPI_PIN_CONF);
            else if (SPI2_CS3_D31  == cs_pin)   iomuxc_pinconf(D31,ALT4,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//不使用片选引脚
            else                                assert(0);//引脚错误 进入断言失败
        }break;
        
        case SPI_3:
        {
            if      (SPI3_SCK_B28  == sck_pin)  iomuxc_pinconf(B28,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI3_MOSI_B30 == mosi_pin) iomuxc_pinconf(B30,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
                                                               
            if      (SPI3_MISO_B31 == miso_pin) iomuxc_pinconf(B31,ALT2,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI3_CS0_B29  == cs_pin)   iomuxc_pinconf(B29,ALT2,LPSPI_PIN_CONF);
            else if (SPI3_CS1_B25  == cs_pin)   iomuxc_pinconf(B25,ALT6,LPSPI_PIN_CONF);
            else if (SPI3_CS2_B24  == cs_pin)   iomuxc_pinconf(B24,ALT6,LPSPI_PIN_CONF);
            else if (SPI3_CS3_B23  == cs_pin)   iomuxc_pinconf(B23,ALT6,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//不使用片选引脚
            else                                assert(0);//引脚错误 进入断言失败
        }break;
        
        case SPI_4:
        {
            if      (SPI4_SCK_B18  == sck_pin)  iomuxc_pinconf(B18,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_SCK_D0   == sck_pin)  iomuxc_pinconf(D0 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI4_MOSI_B20 == mosi_pin) iomuxc_pinconf(B20,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_MOSI_D2  == mosi_pin) iomuxc_pinconf(D2 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
                                                               
            if      (SPI4_MISO_B21 == miso_pin) iomuxc_pinconf(B21,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_MISO_D3  == miso_pin) iomuxc_pinconf(D3 ,ALT4,LPSPI_PIN_CONF);
            else                                assert(0);//引脚错误 进入断言失败
            
            if      (SPI4_CS0_B19  == cs_pin)   iomuxc_pinconf(B19,ALT2,LPSPI_PIN_CONF);
            else if (SPI4_CS0_D1   == cs_pin)   iomuxc_pinconf(D1 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS1_D4   == cs_pin)   iomuxc_pinconf(D4 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS2_D5   == cs_pin)   iomuxc_pinconf(D5 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI4_CS3_D6   == cs_pin)   iomuxc_pinconf(D6 ,ALT4,LPSPI_PIN_CONF);
            else if (SPI_CS_NOT_USE  == cs_pin)   ;//不使用片选引脚
            else                                assert(0);//引脚错误 进入断言失败
        }break;
        
        default:assert(0);break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      SPI初始化
//  @param      spi_n           选择SPI模块(SPI_1-SPI_4)
//  @param      cs_pin          选择SPI片选引脚
//  @param      sck_pin         选择SPI时钟引脚
//  @param      mosi_pin        选择SPI MOSI引脚
//  @param      miso_pin        选择SPI MISO引脚
//  @param      mode            SPI模式 0：CPOL=0 CPHA=0    1：CPOL=0 CPHA=1   2：CPOL=1 CPHA=0   3：CPOL=1 CPHA=1 //具体细节可自行百度
//  @param      baud            设置SPI的波特率
//  @return     void
//  Sample usage:               spi_init(SPI_1, SPI1_SCK_B10, SPI1_MOSI_B12, SPI1_MISO_B13, SPI1_CS0_B11, 1*1000*1000);//硬件SPI初始化     
//-------------------------------------------------------------------------------------------------------------------
void spi_init(SPIN_enum spi_n, SPI_PIN_enum sck_pin, SPI_PIN_enum mosi_pin, SPI_PIN_enum miso_pin, SPI_PIN_enum cs_pin, uint8 mode, uint32 baud)
{
    lpspi_master_config_t masterConfig;
    uint32 src_clock;
    
    spi_iomuxc(spi_n, sck_pin, mosi_pin, miso_pin, cs_pin);

    CLOCK_SetMux(kCLOCK_LpspiMux, LPSPI_CLK_SRC);    //选择PLL2作为LPSPI时钟源
    CLOCK_SetDiv(kCLOCK_LpspiDiv, LPSPI_CLK_DIV);
    
    LPSPI_MasterGetDefaultConfig(&masterConfig);

    masterConfig.baudRate = baud;
    masterConfig.bitsPerFrame = 8;
    masterConfig.whichPcs = (lpspi_which_pcs_t)(cs_pin%21/3-3);
    
    switch(mode)
    {
        case 0:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh; 
            masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge; 
        }break;
        
        case 1:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh; 
            masterConfig.cpha = kLPSPI_ClockPhaseSecondEdge; 
        }break;
        
        case 2:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveLow; 
            masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge; 
        }break;
        
        case 3:
        {
            masterConfig.cpol = kLPSPI_ClockPolarityActiveLow; 
            masterConfig.cpha = kLPSPI_ClockPhaseSecondEdge; 
        }break;
    }

    masterConfig.pcsToSckDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.lastSckToPcsDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    src_clock = (CLOCK_GetFreq(kCLOCK_SysPllClk) / (LPSPI_CLK_DIV + 1U));
    
    LPSPI_MasterInit(SPIN[spi_n], &masterConfig, src_clock);//第一次初始化便于打开时钟
    LPSPI_Reset(SPIN[spi_n]);                               //复位外设
    LPSPI_MasterInit(SPIN[spi_n], &masterConfig, src_clock);//重新初始化设置正确的参数
    
    LPSPI_Enable(SPIN[spi_n], false);
    SPIN[spi_n]->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);
    LPSPI_Enable(SPIN[spi_n], true);

    LPSPI_FlushFifo(SPIN[spi_n], true, true);                       //刷新FIFO
    LPSPI_ClearStatusFlags(SPIN[spi_n], kLPSPI_AllStatusFlag);      //清除状态标志
    LPSPI_DisableInterrupts(SPIN[spi_n], kLPSPI_AllInterruptEnable);//关闭中断
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      SPI发送接收函数
//  @param      spi_n           选择SPI模块   (SPI_1-SPI_4)
//  @param      cs_pin          选择SPI片选引脚
//  @param      modata          发送的数据缓冲区地址
//  @param      midata          发送数据时接收到的数据的存储地址(不需要接收则传 NULL)
//  @param      len             发送的字节数
//  @param      continuous      本次通信是CS是否持续保持有效状态 1:持续保持  0:每传输完一个字节关闭CS(一般设置为1 即可)
//  @return     void				
//  @since      v2.0
//  Sample usage:       		spi_mosi(SPI_1,SPI1_CS0_A13,buf,buf,1);    //发送buff的内容，并接收到buf里，长度为1字节
//-------------------------------------------------------------------------------------------------------------------
void spi_mosi(SPIN_enum spi_n, SPI_PIN_enum cs_pin, uint8 *modata, uint8 *midata, uint32 len, uint8 continuous)
{
    lpspi_transfer_t transfer;

    assert(0 != len);               //断言字节数不为0
    
    if(continuous)  transfer.configFlags = ((cs_pin%21/3-3)<<LPSPI_MASTER_PCS_SHIFT) | kLPSPI_MasterPcsContinuous;
    else            transfer.configFlags = ((cs_pin%21/3-3)<<LPSPI_MASTER_PCS_SHIFT);
    transfer.txData = modata;
    transfer.rxData = midata;
    transfer.dataSize = len;
    LPSPI_MasterTransferBlocking(SPIN[spi_n], &transfer);
}



