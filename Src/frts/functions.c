#include "functions.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stmReusable.h"

void mainFreeRTOS(void)
{
//  xTaskCreate( vTask1, /* Pointer to the function that implements the task. */
//              "Task 1",/* Text name for the task. This is to facilitate 
//              debugging only. */
//              1000, /* Stack depth - small microcontrollers will use much
//              less stack than this. */
//              NULL, /* This example does not use the task parameter. */
//              1, /* This task will run at priority 1. */
//              NULL ); /* This example does not use the task handle. */
//  /* Create the other task in exactly the same way and at the same priority. */
//  xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );
  
  /* Start the scheduler so the tasks start executing. */
//  char *pcTaskName1 = "Task 1 is running\r\n";
//  char *pcTaskName2 = "Task 2 is running\r\n";
//  xTaskCreate( vTaskFunction, "Task 1", 1000,(void *)pcTaskName1, 1, NULL );
//  xTaskCreate( vTaskFunction, "Task 2", 1000,(void *)pcTaskName2, 2, NULL );
  
  char *pcTaskName3 = "Continuous Task 1 is running\r\n";
  char *pcTaskName4 = "Continuous Task 2 is running\r\n";
  
  xTaskCreate( vContinuousProcessingTask, "Task 1", 1000,(void *)pcTaskName3, 1, NULL );
  xTaskCreate( vContinuousProcessingTask, "Task 2", 1000,(void *)pcTaskName4, 1, NULL );
  xTaskCreate( vPeriodicTask, "Task 3", 1000,NULL, 2, NULL );
  vTaskStartScheduler();
}

void vPeriodicTask( void *pvParameters )
{
  TickType_t xLastWakeTime;
  const TickType_t xDelay3ms = pdMS_TO_TICKS( 100 );
  /* The xLastWakeTime variable needs to be initialized with the current tick
  count. Note that this is the only time the variable is explicitly written to.
  After this xLastWakeTime is managed automatically by the vTaskDelayUntil()
  API function. */

  char *pcTaskName5 = "Periodic task is running\r\n";
  xLastWakeTime = xTaskGetTickCount();
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName5 );
    /* The task should execute every 3 milliseconds exactly – see the
    declaration of xDelay3ms in this function. */
    vTaskDelayUntil( &xLastWakeTime, xDelay3ms );
  } 
}

void vContinuousProcessingTask( void *pvParameters )
{
  char *pcTaskName;
  /* The string to print out is passed in via the parameter. Cast this to a
  character pointer. */
  pcTaskName = ( char * ) pvParameters;
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. This task just does this repeatedly
    without ever blocking or delaying. */
    vPrintString( pcTaskName );
    vTaskDelay(pdMS_TO_TICKS( 250 ));
  } 
}

void vTaskFunction( void *pvParameters )
{
  char *pcString = (char *)pvParameters;
  volatile uint32_t ul; /* volatile to ensure ul is not optimized away. */

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcString );
    /* Delay for a period. */
    vTaskDelay(pdMS_TO_TICKS( 250 ));
//    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
//    {
//      /* This loop is just a very crude delay implementation. There is
//      nothing to do in here. Later examples will replace this crude
//      loop with a proper delay/sleep function. */
//    } 

  } 
}


void vTask1( void *pvParameters )
{
  char *pcTaskName = "Task 1 is running\r\n";
  volatile uint32_t ul; /* volatile to ensure ul is not optimized away. */
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );
    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation. There is
      nothing to do in here. Later examples will replace this crude
      loop with a proper delay/sleep function. */
    } 
  } 
}

void vTask2( void *pvParameters )
{
  char *pcTaskName = "Task 2 is running\r\n";
  volatile uint32_t ul; /* volatile to ensure ul is not optimized away. */
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );
    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation. There is
      nothing to do in here. Later examples will replace this crude
      loop with a proper delay/sleep function. */
    } 
  } 
}
