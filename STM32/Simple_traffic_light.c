#include "stm32c0xx.h"

#define Pin1 1U
#define Pin4 4U
#define Pin11 11U
#define clock 47U
#define reset 16U
#define Pin12 12U

void delay_us(uint32_t us){
  TIM1 -> CNT =0;

  while((uint16_t)(TIM1 -> CNT) < us){

  }
}
void delay_ms(uint32_t ms){
  while(ms--){

    delay_us(1000);
  }
}

int main(void){
  RCC->APBENR2 |= RCC_APBENR2_TIM1EN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

  GPIOA->MODER = (GPIOA->MODER & ~(GPIO_MODER_MODE1_Msk|GPIO_MODER_MODE4_Msk|GPIO_MODER_MODE11_Msk|GPIO_MODER_MODE12_Msk))|GPIO_MODER_MODE1_0|GPIO_MODER_MODE4_0|GPIO_MODER_MODE11_0|GPIO_MODER_MODE12_0;
  
  TIM1 -> PSC= clock;
  TIM1 -> CR1 |= TIM_CR1_CEN;

  while(1U){
    GPIOA -> BSRR = (1U << Pin1);
    delay_ms(3000);
    GPIOA -> BSRR = (1U << (Pin1 + reset));
    
    GPIOA -> BSRR = (1U << Pin4);
    delay_ms(1000);
    GPIOA -> BSRR = (1U <<(Pin4 + reset));

    GPIOA -> BSRR = (1U << Pin11);
    for(int i=0; i<1000; i++){
      GPIOA -> BSRR =(1U<<Pin12);
      delay_us(500);
      GPIOA->BSRR=(1U<<(Pin12 + reset));
      delay_us(500);
    }
    delay_ms(2000);
    GPIOA -> BSRR = (1U << (Pin11 + reset));
    
  }
}
