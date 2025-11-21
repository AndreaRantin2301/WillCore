/**
 ******************************************************************************
 * @file:           bsp_uart.h
 * @Author:         Andrea Rantin
 * Created on:      Nov 21, 2025 11:44:59 AM
 * @brief:          BSP layer for UART control, this provides function for Transmitting/Receiving with UART.
 * The current funtionalities provided by this API are:
 * - BSP_UART_Transmit_Blocking: Transmits a buffer trough UART in blocking mode.
 ******************************************************************************
 */

#ifndef INC_BSP_BSP_UART_H_
#define INC_BSP_BSP_UART_H_

#include "board_cfg.h"
#include "global_defines.h"
#include <stdint.h>

/**
* @brief:  Transmit a buffer trough UART in blocking mode.
*
* @param uartId: Indentifier of the UART handle to use(For example BOARD_UART_LOGGING)
* @param data: Pointer to the data to transfer
* @param len: Length of the data to transfer
* @param timeoutMs: Timeout in milliseconds after which the transmit will go in error if not completed.
*
* @return: This function can return the following values:
* 	- OK(105): If the transmit was completed successfully
* 	- ERROR_BSP_INVALID_UART_ID(106): If the provided uartId is not a valid one
* 	- ERROR_BSP_ERROR_UART_WRITE(107): If the transmit timed out or there was an error
*/
StatusCode BSP_UART_Transmit_Blocking(Board_UART_Id uartId, const uint8_t* data, uint16_t len, uint8_t timeoutMs);


#endif
