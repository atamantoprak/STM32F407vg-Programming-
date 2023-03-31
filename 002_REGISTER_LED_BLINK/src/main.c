
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

// external clock activation and frequency setting function
void RCC_Config(void){
	RCC->CR &=~(1<<0);             // HSI OFF
    RCC->CR |=1<<16;               // HSE ON
    while(!(RCC->CR & (1<<17)));   //waiting for HSE active
    RCC->CR |=1<<19;               //  CSS On hse için on yapýlýr
    RCC->PLLCFGR =0x0000000;
    RCC->PLLCFGR |=(1<<22);        //pll source HSE
    RCC->PLLCFGR |=(4<<0);         //pll M value
    RCC->PLLCFGR |=(168<<6);       //pll N =168
    RCC->CR |=(1<<24);             // pll ayarlarý yapýldýktan sonra CR register'dan pll on yapýlýr
    while(!(RCC->CR & (1<<25)))  ; // waiting  for pll  active
    RCC->CFGR &=~(1<<0);           //rcc cfgr den pll system clk seçilir
    RCC->CFGR |= (1<<1);
    while(!(RCC->CFGR & (1<<1)));  //wait for active
}

void GPIO_Config(){

    RCC->AHB1ENR |=1<<3 ;     //GPIOD CLK ENABLE

    GPIOD->MODER |=1<<24;     // GPIOD 12. Pin Output
    GPIOD->MODER &=~(1<<25);
    GPIOD->MODER |=1<<26 ;    // GPIOD 13. Pin Output
    GPIOD->MODER &=~(1<<27);
    GPIOD->MODER |=1<<28;     // GPIOD 14. Pin Output
    GPIOD->MODER &=~(1<<29);
    GPIOD->MODER |=1<<30;     // GPIOD 15. Pin Output
    GPIOD->MODER &=~(1<<31);

    GPIOD->OSPEEDR|=(0xFF<<24); // GPIOD High Speed Mode
}

int main(void)
{

	RCC_Config();
	SystemCoreClockUpdate();
    GPIO_Config();

  while (1)
  {
	     GPIOD->ODR |=1<<12;  //12. Pin SET
	     GPIOD->ODR |=1<<13;  //13. Pin SET
	     GPIOD->ODR |=1<<14;  //14. Pin SET
	     GPIOD->ODR |=1<<15;  //15. Pin SET

	     for(int i=0;i<1680000;i++); // delay code

	     GPIOD->ODR &=~(1<<12); //12. Pin RESET
	     GPIOD->ODR &=~(1<<13); //12. Pin RESET
	     GPIOD->ODR &=~(1<<14); //12. Pin RESET
	     GPIOD->ODR &=~(1<<15); //12. Pin RESET

	     for(int i=0;i<1680000;i++);  // delay code

  }
}




void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
