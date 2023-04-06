
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

	GPIO_InitTypeDef GPIO_InitStructure ;

// this function makes pins configure
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE); //GPIOD CLK ENABLE

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_InitStructure);

}
int main(void)
{
	GPIO_Config();
  while (1)
  {
    GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15); //this command makes pin high
   /* GPIO_SetBits(GPIOD,GPIO_Pin_13);
    GPIO_SetBits(GPIOD,GPIO_Pin_14);
    GPIO_SetBits(GPIOD,GPIO_Pin_15);*/
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
