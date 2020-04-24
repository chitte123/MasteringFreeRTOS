#include "main.h"
#include "stmReusable.h"
#include <string.h>

extern UART_HandleTypeDef huart2;

void vPrintString( char *string )
{
  uint16_t length = strlen(string);
  
  HAL_UART_Transmit(&huart2,(uint8_t*)string,length,1000);
}
