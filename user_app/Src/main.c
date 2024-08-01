/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  *  Created on: Mar 14, 2024
  *      Author: hamada
  ******************************************************************************/
#include "../Inc/main.h"

PinConfig_t PC13 = { .Port = PORTC ,.Pin = PIN13,.Mode = OUTPUT ,.Type=PUSH_PULL
		, .Speed = MEDUIM , .PullType =NO_PULL
};
lcd_4bit_t lcd = { .lcd_port = PORTB , .lcd_en_pin = PIN8 ,.lcd_rs_pin = PIN9
				  ,.lcd_data[0] = PIN4, .lcd_data[1] = PIN5 ,.lcd_data[2] = PIN6,.lcd_data[3] = PIN7
};


int main(void)
{
	SystemClock_Config();
	Systick_init();
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOC_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	RCC_SYSCFG_CLK_ENABLE();
	scb_set_priority_group(GROUP_PRIORITIES_4_SUB_PRIORITIES_4);	  // preemption
	//cb_set_priority_group(GROUP_PRIORITIES_1_SUB_PRIORITIES_16);   // no preemption because 1 group
	GPIO_Pin_init(&PC13);

	lcd_4bit_intialize(&lcd);

	lcd_4bit_clear(&lcd);

	//lcd_4bit_send_string(&lcd , "Eng : Hamada");



	while(1)
	{

		lcd_4bit_send_string(&lcd , "HELLO FRIENDS");
		delay_ms(1000);
		//lcd_4bit_clear(&lcd);

		//lcd_4bit_send_string_pos(&lcd ,ROW2,COL1, "Thanks Eng:Amgad");

		//delay_ms(1000);
		lcd_4bit_clear(&lcd);
		delay_ms(200);
		GPIO_Toggle_Pin_Value(PORTC, PIN13);



	}

}


Std_RetType_t SystemClock_Config(void)
{
	Std_RetType_t ret = RET_OK;
	RCC_OscInitTypedef RCC_OscInitStruct ={0};
	RCC_ClkInitTypedef RCC_ClkInitStruct ={0};

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSE_State = RCC_HSE_ON;
	ret = HALL_RCC_OscConfig(&RCC_OscInitStruct);

	RCC_ClkInitStruct.AHBClkDivider  =RCC_SYSCLK_AHB_DIV1;
	RCC_ClkInitStruct.APB1ClkDivider =RCC_HCLK_APB1_DIV1;
	RCC_ClkInitStruct.APB2ClkDivider =RCC_HCLK_APB2_DIV1;
	ret = HALL_RCC_ClockConfig(&RCC_ClkInitStruct);
	return ret;
}



