#include "ALL_DEFINE.h"
#include "scheduler.h"
#include "flow.h"


void TIM1_UP_IRQHandler(void)   //TIM3中断 3ms
{
	
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		static uint8_t cnt_3ms = 0;
		static uint8_t cnt_6ms = 0;	 
		static uint8_t cnt_24ms = 0;			
		SysTick_count++;
		cnt_3ms++;
		cnt_6ms++;
		cnt_24ms++;	
		
		if(cnt_24ms>=8)
		{
				cnt_24ms = 0;				
				flow_data_sins();
				FlowPidControl(0.024);
		}		
		
		if(cnt_3ms == 1)  //3ms更新一次
		{
			cnt_3ms = 0;
			MpuGetData();
			RC_Analy();			
			FlightPidControl(0.003f);
			MotorControl();
		}		
		if(cnt_6ms == 2) //6ms更新一次
		{
			cnt_6ms = 0;
			GetAngle(&MPU6050,&Angle,0.00626f);
			HeightPidControl(0.006f); //高度控制 //仅供加装ZIN-34高度计的买家使用，基本版进入此函数会立刻返回
			flow_get_data();
		}		

		TIM_ClearITPendingBit(TIM1,TIM_IT_Update );  //清除TIMx的中断待处理位:TIM 中断源 
	}
}


