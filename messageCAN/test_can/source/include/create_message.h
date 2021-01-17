#pragma once

#include "create_message.h"
#include "canmsgs.h"


/**
 * @brief This function calculates the data length
 * @param
 */
uint8_t data_length();


/**
 * @brief This function calculates the CRC
 * @param
 */
uint8_t calcul_crc();

/**
 * @brief auto creation of the CAN message to transmit
 * @param
 */
void create_msg(Can_tx_msg tx_msg,uint32_t ID, uint8_t data);
