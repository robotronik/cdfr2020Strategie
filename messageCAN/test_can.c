LED_ON = (255<<1);                        //[arbitraire] à faire interpréter par la carte réceptrice


led_setup(){
         //led is on PA5
        _gpio_setup_pin(RCC_GPIOA,GPIOA,GPIO5,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,GPIO_OTYPE_PP);
}

void blink_led(){
        gpio_toggle(GPIOA,GPIO5);
        delay_ms(1000);
}



//création du message
Can_tx_msg tx_msg = NULL;
tx_msg.std_id = (2047>>1);              //CAN 2.0A en 11bits
tx_msg.ext_id = 0;
tx_msg.rtr = 0;
tx_msg.fmi = NULL;                           //à redéfinir [nécessaire ici?]
tx_msg.dlc = 8;
tx_msg.data[8] = LED_ON;
tx_msg.crc=NULL;                           //15 bits à redéfinir [nécessaire ici?]
tx_msg.ack = 0;
tx_msg.ts = NULL;

main(){
   clock_setup();
   led_setup();
   can_setup();
   while(1){
      transmit(CAN1,tx_msg);
      if(CAN_ESR_LEC_NO_ERROR == CAN_ESR_LEC_MASK & CAN_ESR(CAN1)){
          blink_led();
      }
      else if (CAN_ESR_LEC_ACK_ERROR == CAN_ESR_LEC_MASK & CAN_ESR(CAN1)){
               //emission d'une erreur
               break;
      }
   }
}
