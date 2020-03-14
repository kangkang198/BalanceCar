/*********************************************************************************************************************
 * @file       		main
 * @company	   		惠州学院
 * @author     		Kangkang
 * @version    		查看doc内version文件 版本说明
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 ********************************************************************************************************************/
#include "headfile.h"


 void main(void)
 {
     DisableGlobalIRQ();
     board_init();//务必保留，本函数用于初始化MPU 时钟 调试串口
	
     All_init();//初始化小车上的所有外设

     EnableGlobalIRQ(0);
     while(1)
     {
        All_Debug(); 
     }
 }






