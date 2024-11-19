#include "uart_communication_fsm.h"

uint8_t str[MAX_BUFFER_SIZE];
uint32_t ADC_tmp = 0;

void uart_communication_fsm(UART_HandleTypeDef * huart, ADC_HandleTypeDef * hadc) {
	switch (status1) {
		case CHECK_RST_COMMAND:
			if (command_flag == 1 && !strcmp((char *)command_data, "RST"))
				status1 = GET_ADC;
			else command_flag = 0;
			break;
		case CHECK_OK_COMMAND:
			if (command_flag == 1 && !strcmp((char *)command_data, "OK"))
				status1 = EXIT;
			break;
		case GET_ADC:
				HAL_ADC_Start(hadc);
				ADC_value = HAL_ADC_GetValue(hadc);
				ADC_tmp = ADC_value;
				status = START_COMMAND;
				status1 = SEND_ADC;
				setTimer(1, 10);
			break;
		case SEND_ADC:
			if (timer_flag[1] == 1) {
				HAL_UART_Transmit(huart, str, sprintf((char *)str, "!ADC=%ld#\r\n", ADC_value), 100);
				setTimer(1, 3000);
			}
			break;
		case EXIT:
			command_flag = 0;
			status = START_COMMAND;
			status1 = CHECK_RST_COMMAND;
			break;
		default:
			break;
	}
}
