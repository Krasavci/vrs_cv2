/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;
  int j = 0;
  int BUTTON = 0;
  int BUTTON_OLD = 0;
  int Change_Mod = 0;
  GPIO_InitTypeDef GPIOinitS;
  GPIO_InitTypeDef GPIOinitC;
  int check = 0;
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

  /* TODO - Add your application code here */

  //uloha 1
  GPIOinitS.GPIO_Pin = GPIO_Pin_5;
  GPIOinitS.GPIO_Mode = GPIO_Mode_OUT;
  GPIOinitS.GPIO_OType = GPIO_OType_PP;
  GPIOinitS.GPIO_PuPd = GPIO_PuPd_UP;
  GPIOinitS.GPIO_Speed = GPIO_Speed_40MHz;

  GPIO_Init(GPIOA, &GPIOinitS);

  GPIOinitC.GPIO_Pin = GPIO_Pin_13;
  GPIOinitC.GPIO_Mode = GPIO_Mode_IN;
  GPIOinitC.GPIO_OType = GPIO_OType_PP;
  GPIOinitC.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(GPIOC, &GPIOinitC);

  GPIO_SetBits(GPIOA, GPIO_Pin_5);
  GPIO_ResetBits(GPIOA, GPIO_Pin_5);

  /*
  //uloha 1
  GPIOA->MODER |= (uint32_t) 0b01<<10;
  GPIOA->OTYPER &= ~(uint32_t) 0b1<<5;
  GPIOA->PUPDR |= (uint32_t) 0b01<<10;
  GPIOA->OSPEEDR |= (uint32_t) 0b11<<10;

  GPIOA->ODR |= (uint32_t) 0b1<<5;
  GPIOA->ODR &= ~(uint32_t) 0b1<<5;

  GPIOA->BSRRL |= (uint32_t) 0b1<<5;
  GPIOA->BSRRH |= (uint32_t) 0b1<<5;


  //uloha 2
  GPIOC->MODER &= ~(uint32_t) 0b11<<26;
  GPIOC->OTYPER &= ~(uint32_t) 0b1<<13;
  GPIOC->PUPDR &= ~(uint32_t) 0b11<<26;
*/

  /* Infinite loop */
  while (1)
  {
	i++;

	BUTTON = ((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13))+1)%2;

	//uloha3(2.1)
	/*
	j=0;
	while (j<100000){
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		j++;
	}
	while (j>0){
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		j--;
	}
*/
	//uloha(2.2)
/*
	if (BUTTON == 1){
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		}
	else if (BUTTON == 0){
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		}
*/
	//uloha3(2.3)
	if (check>1000){
		if ((BUTTON_OLD == 0) && (BUTTON == 1)){
			check = 0;
			Change_Mod = (Change_Mod + 1) % 2;
		}
	}
	check++;
	if (Change_Mod == 1){
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
	}
	else if (Change_Mod == 0){
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}
	BUTTON_OLD = BUTTON;

//uloha3(1.1)
/*
    j=0;
	while (j<100000){
		GPIOA->ODR |= (uint32_t) 0b01<<5;
		j++;
	}
	while (j>0){
			GPIOA->ODR &= ~(uint32_t) 0b01<<5;
			j--;
	}*/
//uloha3(1.2)
	/*
	if (BUTTON == 1){
		GPIOA->ODR |= (uint32_t) 0b01<<5;
	}
	else if (BUTTON == 0){
		GPIOA->ODR &= ~(uint32_t) 0b01<<5;
	}*/
//uloha3(1.3)
/*
    if (check>1000){
		if ((BUTTON_OLD == 0) && (BUTTON == 1)){
			check = 0;
			Change_Mod = (Change_Mod + 1) % 2;
		}
	}
	check++;
	if (Change_Mod == 1){
		GPIOA->ODR |= (uint32_t) 0b01<<5;
	}
	else if (Change_Mod == 0){
		GPIOA->ODR &= ~(uint32_t) 0b01<<5;
	}
	BUTTON_OLD = BUTTON;
*/
  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
