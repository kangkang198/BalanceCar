#include "All_Init.h"
/*********************************************
 *  函数名称：Motor_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对直立车的两个轮子(四个通道进行初始化)
 *  修改日期：2019-12-23
 ********************************************/
static void Motor_Init(void)
{
    pwm_init(MOTOR_LEFT_UP, MOTOR_FREQ_HZ,  0);
    pwm_init(MOTOR_LEFT_BK, MOTOR_FREQ_HZ,  0);
    pwm_init(MOTOR_RIGHT_UP, MOTOR_FREQ_HZ, 0);
    pwm_init(MOTOR_RIGHT_BK, MOTOR_FREQ_HZ, 0);
}

/*********************************************
 *  函数名称：Inductor_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对运放板的电磁传感器进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Inductor_Init(void)
{
    
    adc_init(POWER_ADC1_MOD,INDUCTOR1_PIN_CH,ADC_10BIT);  //同一个ADC模块分辨率应该设置为一样的，如果设置不一样，则最后一个初始化时设置的分辨率生效
    adc_init(POWER_ADC2_MOD,INDUCTOR2_PIN_CH,ADC_10BIT);
    adc_init(POWER_ADC1_MOD,INDUCTOR3_PIN_CH,ADC_10BIT);
    adc_init(POWER_ADC2_MOD,INDUCTOR4_PIN_CH,ADC_10BIT);
   
}

/*********************************************
 *  函数名称：Key_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对主板上的四个按键进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Key_Init(void)
{
    
    gpio_init(KEY1_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
    gpio_init(KEY2_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);
    gpio_init(KEY3_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
    gpio_init(KEY4_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
}

/*********************************************
 *  函数名称：Boma_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对主板上的拨码(四个引脚)进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Boma_Init(void)
{
   
    
    gpio_init(BOMA1_PIN,GPI,BOMA_OFF,GPIO_PIN_CONFIG);	
    gpio_init(BOMA2_PIN,GPI,BOMA_OFF,GPIO_PIN_CONFIG);	
    
   
}

/*********************************************
 *  函数名称：Beep_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对主板上的蜂鸣器进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Beep_Init(void)
{
     
     gpio_init(BEEP_PIN,GPO,0,GPIO_PIN_CONFIG);								

}


/*********************************************
 *  函数名称：MPU6050_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对六轴陀螺仪加速度计进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void MPU6050_Init(void)
{
    simiic_init();
    mpu6050_init();
    systick_delay_ms(50);
    mpu6050_init();
    systick_delay_ms(50);
    mpu6050_init(); //反复延时一会再初始化MPU6050，防止刚上电时读不到数据
}

/*********************************************
 *  函数名称：Encode_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对编码器进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Encode_Init(void)
{
    qtimer_quad_init(ENCODE_MODE,ENCODE_LEFT_A_PHASE,ENCODE_LEFT_B_PHASE);
    qtimer_quad_init(ENCODE_MODE,ENCODE_RIGHT_A_PHASE,ENCODE_RIGHT_B_PHASE);
}
/*********************************************
 *  函数名称：Pit_Isr_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：定时中断初始化，用于分配任务
 *  修改日期：2019-12-23
 ********************************************/
static void Pit_Isr_Init(void)
{
    pit_init();
    pit_interrupt_ms(PIT_CH0, 1);//设置中断服务函数PIT0,1ms 
    
}

/*********************************************
 *  函数名称：Oled_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对OLED进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Oled_Init(void)
{
    oled_init(); 
}
/*********************************************
 *  函数名称：LED_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对LED进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Led_Init(void)
{  
    gpio_init(LED1_PIN,GPO,1,GPIO_PIN_CONFIG);
    gpio_init(LED2_PIN,GPO,1,GPIO_PIN_CONFIG);
    //gpio_init(LED3_PIN,GPO,1,GPIO_PIN_CONFIG);
    //gpio_init(LED4_PIN,GPO,1,GPIO_PIN_CONFIG);//与按键复用，暂时不用
}
/*********************************************
 *  函数名称：Bluetooth_Init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对蓝牙串口进行初始化
 *  修改日期：2019-12-23
 ********************************************/
static void Bluetooth_Init(void)
{
   
   uart_init(BLUETOOTH_UART,BLUETOOTH_BAUDRATE,BLUETOOTH_TX,BLUETOOTH_RX);
	
}

/*********************************************
 *  函数名称：All_init
 *  函数参数：无
 *  函数返回：无
 *  函数备注：对所有用到的模块进行初始化
 *  修改日期：2019-12-23
 ********************************************/
void All_init(void)
{
    
    
    Motor_Init();        //电机初始化
    Inductor_Init();     //电磁传感器初始化
    //Led_Init();          //K60核心板led初始化
    Key_Init();          //按键初始化
    Boma_Init();         //拨码初始化
    Beep_Init();         //蜂鸣器初始化
    Oled_Init();         //OLED初始化
    Bluetooth_Init();    //蓝牙初始化
    MPU6050_Init();      //六轴IMU初始化
   // Encode_Init();       //编码器引脚初始化，暂时不用
    Pit_Isr_Init();      //定时中断初始化
    
   
   
  
    
 
}
