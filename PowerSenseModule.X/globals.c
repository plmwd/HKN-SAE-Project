#include "globals.h"


//can_msg_t canTXBuffer[NUM_CANTX_MSGS] __attribute__((aligned)) = {{ 0 }};
//can_msg_t canRXBuffer[NUM_CANRX_MSGS] __attribute__((aligned)) = {{ 0 }};

can_msg_t canMSGBuffer[NUM_CANRX_MSGS + NUM_CANTX_MSGS] __attribute__((aligned)) = {{ 0 }};

can_msg_t* canTXBuffer = canMSGBuffer;
can_msg_t* canRXBuffer = canMSGBuffer + NUM_CANTX_MSGS;