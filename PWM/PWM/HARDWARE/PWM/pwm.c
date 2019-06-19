#include "pwm.h"

u16 comp;

//extern double du;
void TIM14_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//LED0��LED1��ӦIO��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//(��ͨ���ģʽ)
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//shang��
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM14);//GPIOA7����ӳ�䵽TIM14����ΪTIM14����������ţ�
	
	TIM_TimeBaseInitStructure.TIM_Period = arr;//Ԥװ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;//��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
	
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//ģʽ1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//�Ƚ��������(��Ч�ĵ�ƽ)
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//���ʹ��

	
	TIM_OC1Init(TIM14,&TIM_OCInitStructure);//TIM14ͨ��1��ʼ������
	
	TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
 
	TIM_ARRPreloadConfig(TIM14,ENABLE);//ARPEʹ��Ԥװ��
	TIM_Cmd(TIM14,ENABLE);  //ʹ��TIM14
	
}


void Angle(int  DU)
{
		comp = (u16)(10 * (DU / 9)) + 50;////comp=18000-(18000*(0.5+2/180*DU)/20);//comp = (u16)(10 * (DU / 9)) + 50;//
		TIM_SetCompare1(TIM14,comp-1);//Ŀ��ռ�ձȻ����ת������
}
