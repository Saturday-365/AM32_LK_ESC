// header file: hardware_init.h
#ifndef _HARDWAREINIT_H
#define _HARDWAREINIT_H

#include "basic.h"
#include "lks32mc07x_lib.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

void Common_GPIOInit(void);
/* USER CODE BEGIN GPIOs */

/* USER CODE END GPIOs */
//////////////////////////////////////////////////////////////////////////

void Clock_Init(void);
/* USER CODE BEGIN Periphs */

/* USER CODE END Periphs */
void SoftDelay(u32 cnt);

#endif

/*************** (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE**************/

