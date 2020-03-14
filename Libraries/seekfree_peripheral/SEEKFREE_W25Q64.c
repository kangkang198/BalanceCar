/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		W25Q64 FLASH
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-07-17
 * @note		
					接线定义：
					------------------------------------ 
						芯片管脚            单片机管脚
                        
						CLK                 查看FLASH_SPI_SCK_PIN宏定义的引脚     硬件SPI引脚不可随意切换
						DI                  查看FLASH_SPI_MOSI_PIN宏定义的引脚    硬件SPI引脚不可随意切换
						DO                  查看FLASH_SPI_MISO_PIN宏定义的引脚    硬件SPI引脚不可随意切换
						CS                  查看FLASH_SPI_CS_PIN宏定义的引脚      
                    
                        VCC                 3.3V
                        GND                 GND
                        WP                  3.3V
                        HOLD                3.3V

 ********************************************************************************************************************/

#include "zf_spi.h"
#include "zf_gpio.h"
#include "zf_iomuxc.h"
#include "zf_systick.h"
#include "SEEKFREE_W25Q64.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_spi_reg_bytes(uint8 * val, uint16 num)
{
    gpio_set(FLASH_SPI_CS_PIN,0);
    spi_mosi(FLASH_SPI_NUM,SPI_CS_NOT_USE,val,val,num,1);
    gpio_set(FLASH_SPI_CS_PIN,1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_read_status(void)
{
    struct
    {
        uint8 instruction;  //指令
        uint8 status;   
    }buf;
    buf.instruction = 0x05;
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
    return buf.status;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_read_status2(void)
{
    struct
    {
        uint8 instruction;  //指令
        uint8 status;   
    }buf;
    buf.instruction = 0x35;
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
    return buf.status;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//  @note    	用于FV后缀芯片的 状态寄存器写入
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_status1(uint16 status)
{
    struct
    {
        uint8 instruction;  //指令
        uint8 status1;   
        uint8 status2;   
    }buf;
    buf.instruction = 0x01;
    buf.status1 = status&0xff;
    buf.status2 = status>>8;
    
    w25qxx_spi_reg_bytes(&buf.instruction, 3);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//  @note    	用于JV后缀芯片的 状态寄存器写入
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_status2(uint8 status)
{
    struct
    {
        uint8 instruction;  //指令
        uint8 status;   
    }buf;
    buf.instruction = 0x31;
    buf.status = status;
    
    w25qxx_spi_reg_bytes(&buf.instruction, 2);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_enable(void)
{
    uint8 instruction;

    instruction = 0x06;
    w25qxx_spi_reg_bytes(&instruction, 1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      内部调用，用户无需关心
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_wait_busy(void)
{
    uint8 status;
    uint8 isBusy;
    
    do
    {
        status = w25qxx_read_status();
        isBusy = status&0x01;
    }
    while(isBusy);
    
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      擦除整个falsh
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_erase_chip(void)
{
    uint8 instruction;

    instruction = 0x06;
    
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&instruction, 1);
    w25qxx_wait_busy();
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      擦除一个扇区
//  @param      sector      扇区编号                W25Q64XX 参数范围是0-2047
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   需要注意 W25Q64XX sector参数范围是0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_erase_sector(uint32 sector)
{
    struct
    {
        uint8 instruction;  //指令
        uint8 address[3];   //24位地址
    }buf;
    buf.instruction = 0x20;
    buf.address[0] = (sector * SECTOR_SIZE)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE)&0xff;
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&buf.instruction, 4);
    w25qxx_wait_busy();
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      写入数据到指定扇区 指定页面
//  @param      sector      扇区编号                W25Q64XX 参数范围是0-2047
//  @param      page        扇区第几页              参数范围0-15
//  @param      *dat        数据存储地址
//  @param      length      读取数据的字节数        参数范围1-256
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   需要注意 W25Q64XX sector参数范围是0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_read_page(uint16 sector, uint16 page, uint8 *dat, uint16 length)
{
    uint16 i;
    struct
    {
        uint8 instruction;  //指令
        uint8 address[4];   //24位地址
        uint8 dat_buf[256]; //数据缓冲区
    }buf;
    buf.instruction = 0x0b;
    buf.address[0] = (sector * SECTOR_SIZE)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE)&0xff;
    buf.address[3] = 0;     //dummy clocks
    
    w25qxx_spi_reg_bytes(&buf.instruction, 5+length);
    
    i=0;
    while(i<length)
    {
        dat[i] = buf.dat_buf[i];
        i++;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      检查指定页是否为全空白
//  @param      sector      扇区编号                W25Q64XX 参数范围是0-2047
//  @param      page        扇区第几页              参数范围0-15
//  @return     uint8       0:页为全空白  1：该页有数据
//  @since      v1.0
//  Sample usage:
//  @note                   需要注意 W25Q64XX sector参数范围是0-2047 
//-------------------------------------------------------------------------------------------------------------------
uint8 w25qxx_check_page(uint16 sector, uint16 page)
{
    uint16 i;
    uint8 buf[256];
    
    w25qxx_read_page(sector,page,buf,256);
    i=0;
    while(i<256)
    {
        if(0xff != buf[i])  return 1;
		i++;
    }
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      写入数据到指定扇区 指定页面
//  @param      sector      扇区编号                W25Q64XX 参数范围是0-2047
//  @param      page        扇区第几页              参数范围0-15
//  @param      *dat        写入数据的地址          
//  @param      length      写入数据的字节数        参数范围1-256
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   需要注意 W25Q64XX sector参数范围是0-2047 
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_write_page(uint16 sector, uint16 page, uint8 *dat, uint16 length)
{
    uint16 i;
    struct
    {
        uint8 instruction;  //指令
        uint8 address[3];   //24位地址
        uint8 dat_buf[256]; //数据缓冲区
    }buf;
    buf.instruction = 0x02;
    buf.address[0] = (sector * SECTOR_SIZE)>>16&0xff;
    buf.address[1] = (sector * SECTOR_SIZE)>>8&0xff;
    buf.address[2] = (sector * SECTOR_SIZE)&0xff;
    
    i=0;
    while(i<length)
    {
        buf.dat_buf[i] = dat[i];
        i++;
    }
    
    w25qxx_write_enable();
    w25qxx_spi_reg_bytes(&buf.instruction, 4+length);
    w25qxx_wait_busy();
}




//-------------------------------------------------------------------------------------------------------------------
//  @brief      flash初始化
//  @param      sector      扇区编号
//  @param      page        扇区第几页 参数范围0-15
//  @param      *dat        数据存储地址
//  @param      length      读取数据的字节数
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note                   需要自己外接falsh芯片，如何接线查看最上方接线定义。 自己画板子时  最好在flash芯片的电源引脚附近放置一个0.1uf的电容和一个10uf的电容
//							切记这里并不是操作核心板上的flash，是需要自己多接一个flash然后对齐进行操作。
//-------------------------------------------------------------------------------------------------------------------
void w25qxx_init(void)
{
    uint16 status2;
    
    //这里需要注意，flash所用到的SPI是与ICM用到的SPI是一样的，仅仅通过CS引脚来控制SPI访问不同的模块
    //这里用到的CS引脚是软件模拟的，可以任意修改
    (void)spi_init(FLASH_SPI_NUM, FLASH_SPI_SCK_PIN, FLASH_SPI_MOSI_PIN, FLASH_SPI_MISO_PIN, SPI_CS_NOT_USE, 3, 10*1000*1000);//硬件SPI初始化
    gpio_init(FLASH_SPI_CS_PIN,GPO,1,GPIO_PIN_CONFIG);
    
    
    status2 = w25qxx_read_status2();
    
    if(status2&0x02)//如果Quad Enable，则关闭
    {
        status2 &= ~0x02;//QE位 置零
		w25qxx_write_status2(status2);//JV后缀的芯片用此命令
		status2 = w25qxx_read_status2();
		//FV后缀的芯片用以下代码
		//status2 <<= 8;
		//status2 |= w25qxx_read_status();
		//w25qxx_write_status1(status2);
    }
    
}


