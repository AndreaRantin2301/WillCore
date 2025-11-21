/**
******************************************************************************
* @file:           logging_utility.c
* @Author:         Andrea Rantin
* Created on:      Nov 21, 2025 12:46:05 PM
* @brief:          Implementation file for logging_utility.c
******************************************************************************
*/

#include "utilities/logging_utility.h"
#include "bsp/bsp_uart.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
* @brief: Timeout value in milliseconds after which UART transmit for logs time out
*/
#define LOGS_DEFAULT_TIMEOUT	0XFF

/**
* @brief: Current logLevel of the firmware used to filter logs
*/
static LogLevel currentLogLevel = LOGS_DEFAULT_LEVEL;

/**
* @brief: Symbols for each logging level
*/
static const char logLevelS[LOG_LEVELS_COUNT] = {'N', 'E', 'S', 'W', 'D', 'I', 'V'};

void __Log_Write_Internal(LogLevel logLevel, const char *file, int line, const char *fmt, ...) {

	//If the log to pring has a higher level than the one that's being filtered on then don't do anything
	if(logLevel > currentLogLevel) return;

	char buffer[LOGS_MAX_LEN] = {0};
	int offset = snprintf(buffer, sizeof(buffer), "[%c](%s:%d): ",logLevelS[logLevel], file, line);

	va_list args;
	va_start(args, fmt);
	size_t remaining = sizeof(buffer) - (size_t)offset;
	vsnprintf(buffer + offset, remaining, fmt, args);;
	va_end(args);

	uint16_t length = (uint16_t)strlen(buffer);
	BSP_UART_Transmit_Blocking(BOARD_UART_LOGGING, (uint8_t*)buffer, length, LOGS_DEFAULT_TIMEOUT);
}

void Log_Bare(const char *fmt, ...) {

    char buffer[LOGS_MAX_LEN] = {0};

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    uint16_t length = (uint16_t)strlen(buffer);
    BSP_UART_Transmit_Blocking(BOARD_UART_LOGGING, (uint8_t*)buffer, length, LOGS_DEFAULT_TIMEOUT);
}

void Log_Set_Level(LogLevel newLevel) {
	currentLogLevel = newLevel;
}
