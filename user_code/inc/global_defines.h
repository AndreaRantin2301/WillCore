/**
 ******************************************************************************
 * @file:           global_defines.h
 * @Author:         Andrea Rantin
 * Created on:      Nov 21, 2025 11:51:29 AM
 * @brief:          This file contains global definitions used across project modules like Status codes etc.
 ******************************************************************************
 */

#ifndef INC_GLOBAL_DEFINES_H_
#define INC_GLOBAL_DEFINES_H_

typedef enum {
	OK = 105,
	ERROR_BSP_INVALID_UART_ID = 106,
	ERROR_BSP_ERROR_UART_WRITE = 107,
}StatusCode;

#endif
