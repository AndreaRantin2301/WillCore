/**
 ******************************************************************************
 * @file:           bsp_uart.c
 * @Author:         Andrea Rantin
 * Created on:      Nov 21, 2025 11:55:19 AM
 * @brief:          Implementatio file for bsp_uart.c
 ******************************************************************************
 */

#include "bsp/bsp_uart.h"
#include "usart.h"

/**
*  @brief: Lookup table for UART handles. This takes a @ref Board_UART_Id member and
*  returns the pointer to the corresponding handle.
*/
static UART_HandleTypeDef* const UART_HANDLES_MAP[BOARD_UART_COUNT] = {
		[BOARD_UART_LOGGING] = &huart2,
		[BOARD_UART_COMMANDS] = &huart2,
		[BOARD_UART_SPECTRAL] = &huart3
};

/**
 *
 */
static StatusCode BSP_Validate_UART_Id(Board_UART_Id uartId) {
	switch(uartId) {
		case BOARD_UART_LOGGING:
		case BOARD_UART_COMMANDS:
		case BOARD_UART_SPECTRAL:
			return OK;
		case BOARD_UART_COUNT:
		default:
			return ERROR_BSP_INVALID_UART_ID;
	}
	return ERROR_BSP_INVALID_UART_ID;
}

StatusCode BSP_UART_Transmit_Blocking(Board_UART_Id uartId, const uint8_t* data, uint16_t len, uint8_t timeoutMs) {

	StatusCode checkError = BSP_Validate_UART_Id(uartId);
	if(checkError != OK) return checkError;

	UART_HandleTypeDef* huart = UART_HANDLES_MAP[uartId];
	if(HAL_UART_Transmit(huart, data, len, timeoutMs) != HAL_OK) return ERROR_BSP_ERROR_UART_WRITE;

	return OK;
}
