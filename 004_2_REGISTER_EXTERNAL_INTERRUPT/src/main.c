
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint32_t time){

	while(time--);
}
void CLK_Config(){

	 RCC->CR |=0x00001000;             //HSEON high
	 while(!(RCC->CR & 0x00020000));   //waiting for HSERDY flag is high
	 RCC->CR |=0x00080000;             // CSSON is high
	 RCC->PLLCFGR |=0x00400000;        //PLL source HSE
	 RCC->PLLCFGR |=0x00000004;	   	   //PLLM is 4
   	 RCC->PLLCFGR |=(168<<6);          //pll N =168
	 RCC->PLLCFGR |=0x00000000;	   	   // p =2
	 RCC->CR |=0x01000000;			   // pll ayarlarý yapýldýktan sonra cr den pll on yapýlýr
   	 while(!(RCC->CR & (1<<25)));      // waiting  for pll  active
	 RCC->CFGR	 |=0x00000000;         // AHB prescaler=1
	 RCC->CFGR	 |=0x00080000;         // APB1 prescaler=2
	 RCC->CFGR	 |=0x00001400;         // APB2 prescaler=4

   	 RCC->CIR     |=0x00080000;		   // HSERDY Flag Clear
	 RCC->CIR     |=0x00800000;		   // CSS Flag Clear


}
void GPIO_Config(){

	RCC->AHB1ENR =0x00000009;

	GPIOD->MODER=0x55000000;
	GPIOD->OTYPER=0x00000000;
	GPIOD->OSPEEDR=0xFF000000;
	GPIOD->PUPDR=0x00000000;

}

void EXTI_Config(){
	RCC->APB2ENR =0x00004000;

	SYSCFG->EXTICR[0] =0x00000000;

	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);

	NVIC_SetPriority(EXTI0_IRQn,0);
	NVIC_SetPriority(EXTI1_IRQn,1);
	NVIC_SetPriority(EXTI2_IRQn,2);

	EXTI->IMR =0x00000007;   // PA0,PA1,PA2 active for interrupt
	EXTI->RTSR =0x00000007;  // rising trigger mode
}

void EXTI0_IRQHandler(){

	if(EXTI->PR & 0x00000001){

		GPIOD->ODR =0x00001000;
		delay(33600000);

		EXTI->PR =0x00000001;

	}
}
void EXTI1_IRQHandler(){

	if(EXTI->PR & 0x00000002){

		GPIOD->ODR =0x00002000;
		delay(33600000);

		EXTI->PR =0x00000002;

	}
}
void EXTI2_IRQHandler(){

	if(EXTI->PR & 0x00000004){

		GPIOD->ODR =0x00004000;
		delay(33600000);

		EXTI->PR =0x00000004;

	}
}
int main(void)
{
	CLK_Config();
	GPIO_Config();
	EXTI_Config();

  while (1)
  {
	  	 GPIOD->ODR = 0x0000F000;
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
