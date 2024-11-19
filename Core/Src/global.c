#include "global.h"

int status = START_COMMAND, status1 = CHECK_RST_COMMAND;
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t command_flag = 0;
uint8_t command_data[MAX_BUFFER_SIZE];
uint32_t ADC_value = 0;
