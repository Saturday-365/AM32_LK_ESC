#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* 1. 引入标准整数类型 (uint32_t, uint16_t 等 AM32 极度依赖的类型) */
#include <stdint.h>

/* 2. 引入凌欧的底层驱动字典 (非常关键) */
/* 注意：请根据你凌欧原厂工程里的头文件名字修改下面这句！
   通常凌欧会有一个总的头文件，比如 lks32mc07x.h 或 lks32mc07x_lib.h */
#include "hal_lks32mc07x.h"
#include "lks32mc07x.h"
#include "hardware_init.h"
/* 如果凌欧没有总头文件，你就在这里把你用到的外设头文件一个个列出来，比如：
#include "lks32mc07x_adc.h"
#include "lks32mc07x_gpio.h"
#include "lks32mc07x_timer.h"

*/

/* 3. 错误处理函数打桩声明 (骗过 AM32 里的调用) */
void Error_Handler(void);

/* 4. 移植 ST 的中断优先级定义 (为了防止 AM32 编译报错，直接照抄过来) */
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0 ((uint32_t)0x00000007)
#define NVIC_PRIORITYGROUP_1 ((uint32_t)0x00000006)
#define NVIC_PRIORITYGROUP_2 ((uint32_t)0x00000005)
#define NVIC_PRIORITYGROUP_3 ((uint32_t)0x00000004)
#define NVIC_PRIORITYGROUP_4 ((uint32_t)0x00000003)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
