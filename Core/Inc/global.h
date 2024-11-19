#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include <stdio.h>
#include <string.h>
#include "software_timer.h"

#define MAX_BUFFER_SIZE 30

#define START_COMMAND 0
#define COMMAND 1
#define END_COMMAND 2

#define CHECK_RST_COMMAND 10
#define CHECK_OK_COMMAND 11
#define GET_ADC 12
#define SEND_ADC 13
#define EXIT 14

extern int status, status1;
extern uint8_t temp, buffer[MAX_BUFFER_SIZE], index_buffer, buffer_flag;
extern uint8_t command_flag, command_data[MAX_BUFFER_SIZE];
extern uint32_t ADC_value;

#endif /* INC_GLOBAL_H_ */
