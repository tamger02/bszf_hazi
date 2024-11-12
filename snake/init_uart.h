#include "em_device.h"
#include "stdbool.h"
#include "em_cmu.h"
#include "em_usart.h"
#include "em_gpio.h"

void UART_init(void);
int USART_RxNonblocking(USART_TypeDef *usart);
void UART0_RX_IRQHandler(void);
void UART_test1();


