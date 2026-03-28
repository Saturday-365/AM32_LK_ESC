// src file: main.c
#include "basic.h"
#include "hardware_init.h"
#include "hardware_config.h"
#include "lks32mc07x.h"
#include "rtt_debug.h"
#include "delay.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Defines */

/* USER CODE END Defines */


int main()
{
    __disable_irq();
    Clock_Init();
    /* USER CODE BEGIN Main */
    
    /* USER CODE END Main */

    Common_GPIOInit();

    delay_init(MAIN_CLOCK);

    __enable_irq();

    while(1)
    {
        /* USER CODE BEGIN MainWhile */
        
        GPIO_SetBits(GPIO3, GPIO_Pin_5);
        GPIO_ResetBits(GPIO3, GPIO_Pin_7);
        delay_ms(100);
        GPIO_ResetBits(GPIO3, GPIO_Pin_5);
        GPIO_SetBits(GPIO3, GPIO_Pin_7);
        delay_ms(100);
        /* USER CODE END MainWhile */
//        PRINTF("run main.while()...\r\n");
//        delay_ms(1000);
    }
}


/*************** (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE**************/

