#include <stdio.h>
#include <stdlib.h>

#include "canmsgs.h"
#include "led.h"
#include "gpio.h"
#include "create_message.h"

//[arbitrary]
#define LED_ON (255<<1)
#define ID     (2047>>1)

int main(){
   clock_setup();
   led_setup();
   can_setup();
   Can_tx_msg tx_msg;
   create_msg(tx_msg,ID,LED_ON);
   while(1){
      transmit(CAN1,tx_msg);
      if( (CAN_ESR_LEC_NO_ERROR) == (CAN_ESR_LEC_MASK & CAN_ESR(CAN1)) ){
          led_blink();
      }
      else if ( (CAN_ESR_LEC_ACK_ERROR) == (CAN_ESR_LEC_MASK & CAN_ESR(CAN1)) ){
               //emission d'une erreur
               break;
      }
   }
}
