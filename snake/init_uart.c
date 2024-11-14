/*
 * init_UART.c
 *
 *  Created on: 12 Nov 2024
 *      Author: gergelytamasy
 */

/** 
@file init_UART.c
@brief initialising UART

*/

#include "init_uart.h"
#include "objects.h"
#include "sl_component_catalog.h"
#include "sl_system_init.h"

volatile int UARTflag = false;
volatile int UARTvalue;

void UART_init(void)
{
  // Enable clock for GPIO
  CMU->HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;
  // Set PF7 to high
  GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);

  // Configure UART0
  // (Now use the "emlib" functions whenever possible.)

  // Enable clock for UART0
  CMU_ClockEnable(cmuClock_UART0, true);

  // Initialize UART0 (115200 Baud, 8N1 frame format)

  // To initialize the UART0, we need a structure to hold
  // configuration data. It is a good practice to initialize it with
  // default values, then set individual parameters only where needed.

  USART_InitAsync_TypeDef UART0_init = USART_INITASYNC_DEFAULT;

  USART_InitAsync(UART0, &UART0_init);
  // USART0: see in efm32ggf1024.h

  // Set TX (PE0) and RX (PE1) pins as push-pull output and input resp.
  // DOUT for TX is 1, as it is the idle state for UART communication
  GPIO_PinModeSet(gpioPortE, 0, gpioModePushPull, 1);
  // DOUT for RX is 0, as DOUT can enable a glitch filter for inputs,
  // and we are fine without such a filter
  GPIO_PinModeSet(gpioPortE, 1, gpioModeInput, 0);

  // Use PE0 as TX and PE1 as RX (Location 1, see datasheet (not refman))
    // Enable both RX and TX for routing
  UART0->ROUTE |= UART_ROUTE_LOCATION_LOC1;
    // Select "Location 1" as the routing configuration
  UART0->ROUTE |= UART_ROUTE_TXPEN | UART_ROUTE_RXPEN;

  USART_IntClear(UART0, _USART_IFC_MASK);
  USART_IntEnable(UART0, USART_IEN_RXDATAV);
  NVIC_ClearPendingIRQ(UART0_RX_IRQn);
  NVIC_EnableIRQ(UART0_RX_IRQn);
}

int USART_RxNonblocking(USART_TypeDef *usart)
  { int retVal = -1;
    if (usart->STATUS & USART_STATUS_RXDATAV)
      { retVal = (int)(usart->RXDATA); }
    return retVal;
  }

void UART0_RX_IRQHandler(void){
  //1. egyszerű lekezelés
  //USART_Tx(UART0, USART_RxDataGet(UART0));

  //Gyors lekezelés IT-ben, feldolgozás main-ben
  UARTflag = true;
  UARTvalue = USART_RxDataGet(UART0);



  USART_IntClear(UART0, _USART_IFC_MASK);
}

void UART_test1()
{
  if (UARTflag){
          UARTflag = false;

          USART_Tx(UART0, UARTvalue);
      }
}

void UART_switchdir(irany* dir, irany* prev_dir)
{
  *prev_dir = *dir;
  if (UARTflag){
          UARTflag = false;
          if (UARTvalue == 'j'){
              switch (*dir) {
                case UP: {*dir = RIGHT; USART_Tx(UART0, 'r');} break;
                case RIGHT: {*dir = DOWN; USART_Tx(UART0, 'd');} break;
                case DOWN: {*dir = LEFT; USART_Tx(UART0, 'l');} break;
                case LEFT: {*dir = UP; USART_Tx(UART0, 'u');} break;
              }
              //UARTvalue = dir;
              //USART_Tx(UART0, *dir);
              //printf("cock");
          }
          if (UARTvalue == 'b'){
              switch (*dir) {
                case UP: {*dir = LEFT;USART_Tx(UART0, 'l');} break;
                case RIGHT: {*dir = UP;USART_Tx(UART0, 'u');} break;
                case DOWN: {*dir = RIGHT;USART_Tx(UART0, 'r');} break;
                case LEFT: {*dir = DOWN;USART_Tx(UART0, 'd');} break;
              }

              //UARTvalue = dir;
              //USART_Tx(UART0, *dir);
              //printf("cock");
          }
          //printf("cock");
      }
}

int _write(int file, char *data, int len) {
    int ww;
    for (ww=0; ww<len; ww++){
    USART_Tx(UART0, data[ww]);
    }
    return len;
}



