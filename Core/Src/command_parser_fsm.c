#include "command_parser_fsm.h"

int idx = 0;
void command_parser_fsm(UART_HandleTypeDef * huart) {
	switch (status) {
		case START_COMMAND:
			if (temp == '!') {
				for (int i = 0; i < MAX_BUFFER_SIZE; i++) command_data[i] = '\0';
				idx = 0;
				status = COMMAND;
				status1 = command_flag ? CHECK_OK_COMMAND : CHECK_RST_COMMAND;
			}
			break;
		case COMMAND:
			if (temp == '#') status = END_COMMAND;
			else command_data[idx++] = temp;
			break;
		case END_COMMAND:
			command_flag = 1;
			status = START_COMMAND;
			break;
		default:
			break;
	}
}
