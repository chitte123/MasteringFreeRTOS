#include "main.h"
#include "stmReusable.h"

extern UART_HandleTypeDef huart2;

void vPrintString( const char *string )
{
  uint16_t length = sizeof(string);
  
  HAL_UART_Transmit(&huart2,(uint8_t*)string,length,1000);
}
