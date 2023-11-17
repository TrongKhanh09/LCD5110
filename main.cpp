
#include "Delay.h"
#include "LCD5110_Graph.h"
#include "SPI.h"

//LCD5110::LCD5110(GPIO_TypeDef *_SPI_Port,int SCK, int MOSI, GPIO_TypeDef *_LCD_Port, int DC, int RST, int CS)
//LCD5110 Cs_LCD5110(GPIOA, GPIO_Pin_7, GPIO_Pin_5, GPIOA, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3);

int main (void){
	GPIO_InitTypeDef GPIO_InitStruct;
	void Fn_SPI_Init();
	SystemInit();
	SystemCoreClockUpdate();
	Fn_DELAY_Init(72);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE, ENABLE);
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	LCD5110 Cs_LCD5110(GPIOA, GPIO_Pin_7, GPIO_Pin_5, GPIOA, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3);
    GPIO_Init(GPIOA, &GPIO_InitStruct);
	Cs_LCD5110.InitLCD();	
	//Cs_LCD5110.clrScr();
	Cs_LCD5110.drawCircle(20, 20, 10);
	Cs_LCD5110.drawRoundRect(5,5,40,40);
	Cs_LCD5110.setFont(SmallFont);
	Cs_LCD5110.print("Hello", 0,0);
	Cs_LCD5110.update();
}


