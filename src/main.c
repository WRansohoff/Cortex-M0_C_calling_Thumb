#include "main.h"

/**
 * Main program. For now, just a test to blink some LEDs.
 */
int main(void) {
    // Enable the GPIOA peripheral's clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    // Initialize GPIO pin A0 as push/pull output, no pupdr, low-speed.
    GPIO_InitTypeDef gpio_init_struct;
    gpio_init_struct.GPIO_Pin   = GPIO_Pin_1;
    gpio_init_struct.GPIO_Mode  = GPIO_Mode_OUT;
    gpio_init_struct.GPIO_OType = GPIO_OType_PP;
    gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_init_struct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &gpio_init_struct);

    // Since this is a microcontroller, there's no point in
    // exiting our program before power-off.
    while (1) {
        GPIOA->BSRR = GPIO_Pin_1;
        delay_us(500000);
        GPIOA->BRR = GPIO_Pin_1;
        delay_us(500000);
    }
}
