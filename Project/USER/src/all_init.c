#include "All_Init.h"
/*********************************************
 *  �������ƣ�Motor_Init
 *  ������������
 *  �������أ���
 *  ������ע����ֱ��������������(�ĸ�ͨ�����г�ʼ��)
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Motor_Init(void)
{
    pwm_init(MOTOR_LEFT_UP, MOTOR_FREQ_HZ,  0);
    pwm_init(MOTOR_LEFT_BK, MOTOR_FREQ_HZ,  0);
    pwm_init(MOTOR_RIGHT_UP, MOTOR_FREQ_HZ, 0);
    pwm_init(MOTOR_RIGHT_BK, MOTOR_FREQ_HZ, 0);
}

/*********************************************
 *  �������ƣ�Inductor_Init
 *  ������������
 *  �������أ���
 *  ������ע�����˷Ű�ĵ�Ŵ��������г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Inductor_Init(void)
{
    
    adc_init(POWER_ADC1_MOD,INDUCTOR1_PIN_CH,ADC_10BIT);  //ͬһ��ADCģ��ֱ���Ӧ������Ϊһ���ģ�������ò�һ���������һ����ʼ��ʱ���õķֱ�����Ч
    adc_init(POWER_ADC2_MOD,INDUCTOR2_PIN_CH,ADC_10BIT);
    adc_init(POWER_ADC1_MOD,INDUCTOR3_PIN_CH,ADC_10BIT);
    adc_init(POWER_ADC2_MOD,INDUCTOR4_PIN_CH,ADC_10BIT);
   
}

/*********************************************
 *  �������ƣ�Key_Init
 *  ������������
 *  �������أ���
 *  ������ע���������ϵ��ĸ��������г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Key_Init(void)
{
    
    gpio_init(KEY1_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
    gpio_init(KEY2_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);
    gpio_init(KEY3_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
    gpio_init(KEY4_PIN,GPI,KEY_UP,GPIO_PIN_CONFIG);	
}

/*********************************************
 *  �������ƣ�Boma_Init
 *  ������������
 *  �������أ���
 *  ������ע���������ϵĲ���(�ĸ�����)���г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Boma_Init(void)
{
   
    
    gpio_init(BOMA1_PIN,GPI,BOMA_OFF,GPIO_PIN_CONFIG);	
    gpio_init(BOMA2_PIN,GPI,BOMA_OFF,GPIO_PIN_CONFIG);	
    
   
}

/*********************************************
 *  �������ƣ�Beep_Init
 *  ������������
 *  �������أ���
 *  ������ע���������ϵķ��������г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Beep_Init(void)
{
     
     gpio_init(BEEP_PIN,GPO,0,GPIO_PIN_CONFIG);								

}


/*********************************************
 *  �������ƣ�MPU6050_Init
 *  ������������
 *  �������أ���
 *  ������ע�������������Ǽ��ٶȼƽ��г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void MPU6050_Init(void)
{
    simiic_init();
    mpu6050_init();
    systick_delay_ms(50);
    mpu6050_init();
    systick_delay_ms(50);
    mpu6050_init(); //������ʱһ���ٳ�ʼ��MPU6050����ֹ���ϵ�ʱ����������
}

/*********************************************
 *  �������ƣ�Encode_Init
 *  ������������
 *  �������أ���
 *  ������ע���Ա��������г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Encode_Init(void)
{
    qtimer_quad_init(ENCODE_MODE,ENCODE_LEFT_A_PHASE,ENCODE_LEFT_B_PHASE);
    qtimer_quad_init(ENCODE_MODE,ENCODE_RIGHT_A_PHASE,ENCODE_RIGHT_B_PHASE);
}
/*********************************************
 *  �������ƣ�Pit_Isr_Init
 *  ������������
 *  �������أ���
 *  ������ע����ʱ�жϳ�ʼ�������ڷ�������
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Pit_Isr_Init(void)
{
    pit_init();
    pit_interrupt_ms(PIT_CH0, 1);//�����жϷ�����PIT0,1ms 
    
}

/*********************************************
 *  �������ƣ�Oled_Init
 *  ������������
 *  �������أ���
 *  ������ע����OLED���г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Oled_Init(void)
{
    oled_init(); 
}
/*********************************************
 *  �������ƣ�LED_Init
 *  ������������
 *  �������أ���
 *  ������ע����LED���г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Led_Init(void)
{  
    gpio_init(LED1_PIN,GPO,1,GPIO_PIN_CONFIG);
    gpio_init(LED2_PIN,GPO,1,GPIO_PIN_CONFIG);
    //gpio_init(LED3_PIN,GPO,1,GPIO_PIN_CONFIG);
    //gpio_init(LED4_PIN,GPO,1,GPIO_PIN_CONFIG);//�밴�����ã���ʱ����
}
/*********************************************
 *  �������ƣ�Bluetooth_Init
 *  ������������
 *  �������أ���
 *  ������ע�����������ڽ��г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
static void Bluetooth_Init(void)
{
   
   uart_init(BLUETOOTH_UART,BLUETOOTH_BAUDRATE,BLUETOOTH_TX,BLUETOOTH_RX);
	
}

/*********************************************
 *  �������ƣ�All_init
 *  ������������
 *  �������أ���
 *  ������ע���������õ���ģ����г�ʼ��
 *  �޸����ڣ�2019-12-23
 ********************************************/
void All_init(void)
{
    
    
    Motor_Init();        //�����ʼ��
    Inductor_Init();     //��Ŵ�������ʼ��
    //Led_Init();          //K60���İ�led��ʼ��
    Key_Init();          //������ʼ��
    Boma_Init();         //�����ʼ��
    Beep_Init();         //��������ʼ��
    Oled_Init();         //OLED��ʼ��
    Bluetooth_Init();    //������ʼ��
    MPU6050_Init();      //����IMU��ʼ��
   // Encode_Init();       //���������ų�ʼ������ʱ����
    Pit_Isr_Init();      //��ʱ�жϳ�ʼ��
    
   
   
  
    
 
}
