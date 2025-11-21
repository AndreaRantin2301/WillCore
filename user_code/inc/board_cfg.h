/**
 ******************************************************************************
 * @file:           board_cfg.h
 * @Author:         Andrea Rantin
 * Created on:      Nov 21, 2025 11:37:39 AM
 * @brief:          This file contains definitions of Ids that are used in the BSP layer with a lookup table to access
 * different peripheral handles. This keeps everything separateed and avoids having too much code dependent on generated HAL code
 ******************************************************************************
 */

#ifndef INC_BOARD_CFG_H_
#define INC_BOARD_CFG_H_

/**
* Ids to access different UART handles of the board.
* This is used in the BSP layer with a lookup table to access the correct handle
*/
typedef enum {
	BOARD_UART_LOGGING,
	BOARD_UART_COMMANDS,
	BOARD_UART_SPECTRAL,
	BOARD_UART_COUNT,
}Board_UART_Id;

/**
* Ids to access different I2C handles of the board.
* This is used in the BSP layer with a lookup table to access the correct handle
*/
typedef enum {
	BOARD_I2C_CALENDAR,
	BOARD_I2C_ADC_CONVERTER,
	BOARD_I2C_COUNT,
}Board_I2C_Id;

/**
* Ids to access different FLASH handles of the board.
* This is used in the BSP layer with a lookup table to access the correct handle
*/
typedef enum {
	BOARD_SPI_FLASH,
	BOARD_SPI_COUNT,
}Board_SPI_Id;



#endif
