/*********************************************************************************************************************
 * @file       		main
 * @company	   		����ѧԺ
 * @author     		Kangkang
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.26
 * @Target core		NXP RT1021DAG5A
 ********************************************************************************************************************/
#include "headfile.h"


 void main(void)
 {
     DisableGlobalIRQ();
     board_init();//��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
	
     All_init();//��ʼ��С���ϵ���������

     EnableGlobalIRQ(0);
     while(1)
     {
        All_Debug(); 
     }
 }






