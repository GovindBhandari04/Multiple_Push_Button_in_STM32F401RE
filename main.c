#include <stm32f4xx.h>


#define GPIOAEN (1U<<0)
#define GPIOBEN (1U<<1)

#define LED1 (1U<<0)
#define LED2 (1U<<1)
#define LED3 (1U<<2)
#define LED4 (1U<<3)
#define LED5 (1U<<4)

#define BUTTON1 (1U<<0)
#define BUTTON2 (1U<<1)
#define BUTTON3 (1U<<2)
#define BUTTON4 (1U<<3)
#define BUTTON5 (1U<<4)

int main()
{
	RCC -> AHB1ENR |= GPIOAEN|GPIOBEN;

	GPIOA -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10);
	GPIOA -> MODER &= ~(1U<<1) & ~(1U<<3) & ~(1U<<5) & ~(1U<<7) & ~(1U<<9) & ~(1U<<11);

	GPIOB -> MODER &= ~(1U<<0) & ~(1U<<1) & ~(1U<<2) & ~(1U<<3) & ~(1U<<4) & ~(1U<<5) & ~(1U<<6) & ~(1U<<7) & ~(1U<<8) & ~(1U<<9) & ~(1U<<10) & ~(1U<<11);

	while(1)
	{
		if(GPIOB -> IDR & BUTTON1)
		{
			GPIOA -> BSRR = LED1;
		}

		else
		{
			GPIOA -> BSRR = (1U<<16);
		}

		if(GPIOB -> IDR & BUTTON2)
		{
		    GPIOA -> BSRR = LED2;
		}

		else
		{
			GPIOA -> BSRR = (1U<<17);
		}

		if(GPIOB -> IDR & BUTTON3)
		{
			GPIOA -> BSRR = LED3;
		}

		else
		{
			GPIOA -> BSRR = (1U<<18);
		}

		if(GPIOB -> IDR & BUTTON4)
		{
			GPIOA -> BSRR = LED4;
		}

		else
		{
			GPIOA -> BSRR = (1U<<19);
		}

		if(GPIOB -> IDR & BUTTON5)
		{
			GPIOA -> BSRR = LED5;
		}

		else
		{
			GPIOA -> BSRR = (1U<<20);
		}

	}
}
