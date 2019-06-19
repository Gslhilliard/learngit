#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "pwm.h"

//double du;
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
  delay_init(168);  //��ʼ����ʱ����//168
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM14_PWM_Init((2000-1),840-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.     
	while(1)
	{
		Angle(90);
		delay_ms(2000);//1000
		Angle(45);
		delay_ms(2000);//1000
		Angle(180);
		delay_ms(2000);//1000
	}
}


