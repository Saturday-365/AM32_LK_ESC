#include "IO.h"
#include "targets.h"  // AM32用来存引脚宏定义的头文件
// 下面包含凌欧的库头文件，根据你的实际名字修改
#include "hal_lksmcu_gpio.h" 

/* =========================================================
 * 第一部分：占位变量 (为防止外部 extern 找不到而报错)
 * ========================================================= */
char ic_timer_prescaler = 0;
uint32_t dma_buffer[64];
char out_put = 0;
uint8_t buffer_padding = 0;

/* =========================================================
 * 第二部分：极其复杂的 Timer/DMA 逻辑 (目前全部打桩为空)
 * ========================================================= */
void changeToOutput(void) {
    // 以后在这里写：关闭定时器捕获，将引脚切为推挽输出
}

void changeToInput(void) {
    // 以后在这里写：将引脚切为输入，开启定时器捕获
}

void sendDshotDma(void) {
    // 以后在这里写：配置凌欧的 DMA 进行 Dshot 遥测回传
}

void receiveDshotDma(void) {
    // 以后在这里写：配置凌欧的 DMA 接收 Dshot 信号
}

void enableHalfTransferInt(void) {
    // 以后在这里写：开启 DMA 半传输中断
}

void setInputPolarityRising(void) {
    // 以后在这里写：设置凌欧定时器捕获极性为上升沿
}

/* =========================================================
 * 第三部分：纯 GPIO 操作 (使用你提供的凌欧库完美实现)
 * 注意：需要在 targets.h 里定义好 SIGNAL_PIN，例如传入 HAL_GPIO_P0_1
 * ========================================================= */

// 读取输入信号引脚的高低电平
uint8_t getInputPinState(void) {
    // 调用凌欧库读取输入电平 (假设 targets.h 里定义了 INPUT_PIN 宏)
    // 实际移植时，你需要把 INPUT_PIN 换成凌欧的格式，比如 HAL_GPIO_P0_0
    return HAL_GPIO_GetInData(INPUT_PIN); 
}

// 设置信号引脚为浮空输入 (无上下拉)
void setInputPullNone(void) {
    // 凌欧的模式：BIT0是输入使能(PIE)。只使能输入，不使能上下拉。
    // 假设凌欧库的宏是这样的（如果报错请查阅 hal_lksmcu_gpio.h 里的枚举名）
    HAL_GPIO_SetMode(INPUT_PIN, BIT0); 
}

// 设置信号引脚为上拉输入
void setInputPullUp(void) {
    // 凌欧的模式：BIT0(输入使能) + BIT2(上拉使能 PUE)
    HAL_GPIO_SetMode(INPUT_PIN, BIT0 | BIT2);
}

// 设置信号引脚为下拉输入
void setInputPullDown(void) {
    // 【硬件差异警告！】
    // 从你提供的凌欧库源码来看，只看到了上拉(PUE)，没看到下拉使能(PDE)。
    // 很多国产芯片为了节约成本，GPIO 是没有内置下拉电阻的。
    // 如果凌欧确实没有内部下拉，这里就只能配置为浮空输入，或者外部硬件加下拉电阻。
    HAL_GPIO_SetMode(INPUT_PIN, BIT0); // 暂定为浮空输入
}