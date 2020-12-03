# Interface H/L

## Documentation
Please refer to the doxygen documentation for further question

## F3
### Setup
* clock_setup()
* motor_setup()
* encoder_setup()

pour le debug
* uart_setup()

### clock
``` c
void delay_ms(uint32_t ms)
```
* @brief This function implements a delay in ms 
* @param **ms** value of delay in ms

### moteurs
``` c
void motor_set(enum motor_sel sel, int8_t value)
```
* @brief This function pilots the sel (MOTOR_A or MOTOR_B) with a value between -100(backward full speed) and +100 (forward full speed). The forward direction depends on the sign of MOTOR_X_INVER_DIR.
* @param **sel** The motor that will be piloted (motor_sel {MOTOR_A, MOTOR_B}) 
* @param **value** value is between -100 and +100, controls the speed and direction of the motor sel (eg +54)

### encodeurs
``` c
int encoder_update(enum encoder_sel sel, volatile int *prev_count)
```
* @brief delta steps in small time difference
* @param **sel** the encoder that is updated (encoder_sel {ENCODER_A, ENCODER_B})
* @param **prev_count** pointer on the previous
* @return **delta value** (difference between actual and previous)

vous avez besoin de deux variables en dehors de la fonction pour les steps

### CAN
TODO but something like transmit message (format to be defined) and receive message (unsure)

### debug
``` c
fprintf(stderr,str)
``` 
* stderr est le flot de debug
* str est une chaine de caractere comme en c 

## F4
### Setup
* clock_setup()
* actuator_setup()
* exti_setup()

pour le debug
* uart_setup()

TODO
setup for can and tof

### TOF
TODO but something like calibration command and get_measure for given TOF

### CAN
TODO but something like transmit message (format to be defined) and receive message (unsure)

### Cord-starter
TODO but something like an signal when the cord starter is pulled to start the FSM

### Actuator
``` c
void actuator_set(enum actuator_sel sel, int8_t value);
```
* @brief This function pilots the sel with a value between -100(backward fullspeed) and +100 (forward full speed). The forward direction depends on the sign of ACT_X_INVER_DIR.
* @param **sel**    The actuator that will be piloted (actuator_sel {ARM, FLAG}) 
* @param **value**    value is between -100 and +100, controls the speed and direction of the motor sel (eg +54)

### Exti
In lowlevel/exti.c routine for the limit switch of the FLAG and ARM
``` c 
void exti9_5_isr(){
    if(exti_get_flag_status(ARM_LIMITSWITCH_EXTI)){
        //TO DO: things to do when arm limit switch is pushed
        fprintf(stderr,"interrupt received from arm\n");       
        
        actuator_set(ARM,0);

        exti_reset_request(ARM_LIMITSWITCH_EXTI);
    }
    if(exti_get_flag_status(FLAG_LIMITSWITCH_EXTI)){
        //TO DO: things to do when flag limit switch is pushed
        fprintf(stderr,"interrupt received from flag\n");       
        actuator_set(FLAG,0);
        exti_reset_request(FLAG_LIMITSWITCH_EXTI);
    }
}
```

### Clock and Debug
as in F3




