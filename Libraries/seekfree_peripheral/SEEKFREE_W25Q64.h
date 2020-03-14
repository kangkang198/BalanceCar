/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		W25Q64FV FLASH
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


#include "common.h"



#define FLASH_SPI_NUM         SPI_2           
#define FLASH_SPI_SCK_PIN     SPI2_SCK_C10    //接模块CLK
#define FLASH_SPI_MOSI_PIN    SPI2_MOSI_C12   //接模块DI
#define FLASH_SPI_MISO_PIN    SPI2_MISO_C13   //接模块DO
#define FLASH_SPI_CS_PIN      D23             //接模块CS


//W25Q64 最大扇区数量为2048 
//W25Q32 最大扇区数量为1024 
//W25Q16 最大扇区数量为512
#define SECTOR_NUM          2048   

#define SECTOR_SIZE         4096    //扇区大小 单位：字节
#define PAGE_SIZE           256     //页大小   单位：字节   
#define SECTOR_PAGE_NUM     16      //一个扇区页的数量  (SECTOR_SIZE/FLASH_PAGE_SIZE)


void w25qxx_erase_chip(void);
void w25qxx_erase_sector(uint32 sector);
void w25qxx_read_page(uint16 sector, uint16 page, uint8 *dat, uint16 length);
uint8 w25qxx_check_page(uint16 sector, uint16 page);
void w25qxx_write_page(uint16 sector, uint16 page, uint8 *dat, uint16 length);
void w25qxx_init(void);













