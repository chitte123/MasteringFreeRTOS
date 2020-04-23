#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void mainFreeRTOS(void);
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
void vTaskFunction( void *pvParameters );


#define mainDELAY_LOOP_COUNT    1000

#endif