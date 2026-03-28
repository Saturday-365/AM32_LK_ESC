// src file: hardware_init.c
#include "hardware_init.h"
#include "lks32mc07x_gpio.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */


void Clock_Init(void)
{
    SYS_InitTypeDef SYS_InitStruct;

    SYS_StructInit (&SYS_InitStruct);
    SYS_InitStruct.PLL_SrcSel = SYS_PLLSRSEL_RCH;
    SYS_InitStruct.Clk_Sel = CLK_SEL_PLL;
    SYS_InitStruct.PLL_DivSel = BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7;
    SYS_InitStruct.Clk_DivSPI = SYS_Clk_SPIDiv1;
    SYS_InitStruct.Clk_DivUART = SYS_Clk_UARTDiv1;
    SYS_InitStruct.Clk_FEN = 0;
    SYS_InitStruct.WDT_Ena = DISABLE;
    SYS_InitStruct.PORFilter_Ena = DISABLE;
    /* USER CODE BEGIN Clock_Init */
    
    /* USER CODE END Clock_Init */
    SYS_Init(&SYS_InitStruct);
}

void Common_GPIOInit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_PODEna = ENABLE;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_PODEna = DISABLE;
    GPIO_Init(GPIO3, &GPIO_InitStruct);
    
    /* USER CODE BEGIN Common_GPIOInit */
    
    /* USER CODE END Common_GPIOInit */
}
//////////////////////////////////////////////////////////////////////////

void SystemInit(void)
{
    Clock_Init();
}

void SoftDelay(u32 cnt)
{
    for(u32 i = 0; i < cnt; i++)
    {
    }
}


/*************** (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE**************/

