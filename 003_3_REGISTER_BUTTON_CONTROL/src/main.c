
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
int count=0;
void delay (uint32_t time){
	while(time--);
}

void GPIO_Config(){

	/*  RCC->CR |=1<<16;             // HSE on
	    while(!(RCC->CR & (1<<17))); //waiting for hse active
	    RCC->CR      |=1<<19;        //CSS On hse için on yapýlýr
	    RCC->PLLCFGR  =0x0000000;
	    RCC->PLLCFGR |=(1<<22);      //pll source HSE
	    RCC->PLLCFGR |=(4<<0);       //pll M
	    RCC->PLLCFGR |=(168<<6);     //pll N =168
	    RCC->CR      |=(1<<24);      // pll ayarlarý yapýldýktan sonra cr den pll on yapýlýr
	    while(!(RCC->CR & (1<<25))); // waiting  for pll  active
	    RCC->CFGR    &=~(1<<0);      //rcc cfgr den pll system clk seçilir
	    RCC->CFGR    |= (1<<1);
	    while(!(RCC->CFGR & (1<<1)));//wait for active
	    RCC->CFGR	 |=0x00000000;   // AHB prescaler=1
		RCC->CFGR	 |=0x00080000;   // APB1 prescaler=2
		RCC->CFGR	 |=0x00001400;   // APB2 prescaler=4

		RCC->CIR     |=0x00080000;
		RCC->CIR     |=0x00800000;*/
	RCC->CR &=~(1<<0); // HSI OFF
    RCC->CR |=1<<16;  // HSE on
    while(!(RCC->CR & (1<<17))); //waiting for hse active
    RCC->CR |=1<<19; //CSS On hse için on yapýlýr
    RCC->PLLCFGR =0x0000000;
    RCC->PLLCFGR |=(1<<22); //pll source HSE
    RCC->PLLCFGR |=(4<<0); //pll M
    RCC->PLLCFGR |=(168<<6);//pll N =168
    RCC->CR |=(1<<24); // pll ayarlarý yapýldýktan sonra cr den pll on yapýlýr
    while(!(RCC->CR & (1<<25)));// waiting  for pll  active
    RCC->CFGR &=~(1<<0); //rcc cfgr den pll system clk seçilir
    RCC->CFGR |= (1<<1);
    while(!(RCC->CFGR & (1<<1)));//wait for active

	    RCC->AHB1ENR |=0x00000009; // GPIOA ve GPIOD aktif

	    GPIOD->MODER |=0x55000000; //12,13,14,15. pinler output modda
	    GPIOD->OTYPER|=0x00000000; //12,13,14,15. pinler pushpull modda
	    GPIOD->OSPEEDR|=0xFF000000;//12,13,14,15. pinler 100MHz
	    GPIOD->PUPDR|=0x00000000; //12,13,14,15. pinler NOPULL modda

}
int main(void)
{
 GPIO_Config();
  while (1)
  {
	  if(GPIOA->IDR & 0x00000001){
		  while(GPIOA->IDR & 0x00000001);
		  delay(1680000);
		  count++;
	  }
	  if(count % 2==0)
		  GPIOD->ODR=0x00000000;


	  else
		  GPIOD->ODR=0x0000F000;


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
