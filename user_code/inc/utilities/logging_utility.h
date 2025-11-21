/**
******************************************************************************
* @file:           logging_utility.h
* @Author:         Andrea Rantin
* Created on:      Nov 21, 2025 12:41:42 PM
* @brief:          This file contains definitions for the Logging utility. This API allows to easily print and filter logs
* depending on their category. Logs can be configured to be filtered on a selected level.
* This API provides the following functionalities:
* - Macros to print a log for every level(LOG_ERROR, LOG_DEBUG etc)
* - Log_Bare: Prints a "bare" log or simply a log with just the string argument, without the file name or line where it's printed
* - Log_Set_Level: Sets the filtering level of logs, where a higher level means less filtering.
******************************************************************************
*/

#ifndef INC_UTILITIES_LOGGING_UTILITY_H_
#define INC_UTILITIES_LOGGING_UTILITY_H_

/**
* @brief: Max length that is printable trough the logging USART
*/
#define LOGS_MAX_LEN	512

/**
* @brief: Logging level used to filter logs. This must be
* set in the @ref Logger_Init function. Any logs that have a logging level
* lower than the set one will not be shown
*/
typedef enum {
	LOG_LEVEL_NONE = 0,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_SYSTEM,
	LOG_LEVEL_WARN,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_VERBOSE,
	LOG_LEVELS_COUNT,
}LogLevel;

/**
* @brief: Default log level to filter on
*/
#define LOGS_DEFAULT_LEVEL	LOG_LEVEL_VERBOSE

/**
* @brief: Prints a log with LOG_LEVEL_ERROR priority
*/
#define LOG_ERROR(fmt, ...) __Log_Write_Internal(LOG_LEVEL_ERROR, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Prints a log with LOG_LEVEL_SYSTEM priority
*/
#define LOG_SYSTEM(fmt, ...) __Log_Write_Internal(LOG_LEVEL_SYSTEM, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Prints a log with LOG_LEVEL_WARN priority
*/
#define LOG_WARN(fmt, ...) __Log_Write_Internal(LOG_LEVEL_WARN, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Prints a log with LOG_LEVEL_DEBUG priority
*/
#define LOG_DEBUG(fmt, ...) __Log_Write_Internal(LOG_LEVEL_DEBUG, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Prints a log with LOG_LEVEL_INFO priority
*/
#define LOG_INFO(fmt, ...) __Log_Write_Internal(LOG_LEVEL_INFO, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Prints a log with LOG_LEVEL_VERBOSE priority
*/
#define LOG_VERBOSE(fmt, ...) __Log_Write_Internal(LOG_LEVEL_VERBOSE, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

/**
* @brief: Internal function used by the logger util to print logs through USART.
* It is highly discouraged to call this function, the provided macros should be used
* instead.
*
* @param logLevel: Log level of the log to print
* @param file: Name of the file where the log is printed
* @param line: Line in the file where the log is printed
* @param fmt: Formatted string to be printed
*/
void __Log_Write_Internal(LogLevel logLevel, const char *file, int line, const char *fmt, ...);

/**
* @brief: Prints a "bare" log. A bare log is one that has no information such as file name and line of the log.
* It just prints the argument string given to it.
*
* @param fmt: Formatted string to be printed
*/
void Log_Bare(const char *fmt, ...);

/**
* @brief: Sets a new logging level for the logging utility
*/
void Log_Set_Level(LogLevel newLevel);

#endif
