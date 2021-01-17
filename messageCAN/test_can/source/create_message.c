#include "create_message.h"

void create_msg(Can_tx_msg tx_msg, uint32_t ID, uint8_t data){
  //CAN 2.0A => 11bits
  tx_msg.std_id = ID;
  tx_msg.ext_id = 0;
  tx_msg.rtr = 0;
  //TO MODIFY [if useful here?]
  tx_msg.fmi = NULL;
  tx_msg.dlc = 8;
  tx_msg.data[8] = data;
  //15 bits | TO MODIFY [useful here?]
  tx_msg.crc=NULL;
  tx_msg.ack = 0;
  tx_msg.ts = NULL;
}
