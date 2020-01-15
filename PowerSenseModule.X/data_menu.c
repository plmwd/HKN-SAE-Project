#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "globals.h"                        // Required for two globals
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include <libpic30.h>
#include "device_configuration.h"



#ifdef DATA_MENU
bool menuOn;    // menuOn must be global & initially false


void Init_Timer1( void )
{
    T1CON = 0;          // Timer reset
    IFS0bits.T1IF = 0;  // Reset Timer1 interrupt flag
    IPC0bits.T1IP = 6;  // Timer1 Interrupt priority level=4
    IEC0bits.T1IE = 1;  // Enable Timer1 interrupt
    T1CONbits.TCKPS = 3; // Setting prescale to 1:256 (11)
    TMR1 = 0x0000;
    PR1 = 0xFFFF;       // Timer1 period register = ????? [Max time]
    T1CONbits.TON = 1;  // Enable Timer1 and start the counter
}

void __attribute__ ( (interrupt, no_auto_psv) ) _T1Interrupt( void )
{
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
    printf("Timer interrupt\r\n");
    TMR1 = 0;
    T1CONbits.TON = 1;

}



int main(void)
{
//    int convertedInput;                     // Input converted into integer
//    char inputBuffer[MAX_BUFFER_SIZE];      // Will hold current input
//    bool menuStatus = true;                 // Menu programs runs as long as menuStatus = true
    
    // initialize the device
    SYSTEM_Initialize();
    UART1_Initialize();
    UART1_Enable();
    Init_Timer1();
    menuOn = false;
    
    
    printf("START OF PROGRAM\r\n");
    
    while(1)
    {
        // wait
    }
 
    // Loop the menu until user quits
//    while(menuStatus)
//    {
//        printf("\r\n\n\n\n\n\n");
//        printf("==============TEST MENU==============\r\n");
//        printf("\t1. Print Hello World!\r\n");
//        printf("\t2. Sum two numbers.\r\n");
//        printf("\t3. Parrot back a string!\r\n");
//        printf("\t4. Infinite counter.\r\n");
//        printf("\t5. Exit\r\n");
//        printf("=====================================\r\n");
//        
//        
//        
//        getStringInput(inputBuffer);
//        
//        // Verifying if input is proper
//        if(strlen(inputBuffer) != 1 || inputBuffer[0] < '1' || inputBuffer[0] > '5')
//        {
//            printf("Invalid input. Please try again.\r\n");
//            __delay_ms(1500);   // Wait 1.5 seconds so the user can think about what they did
//            continue;
//        }
//        
//        convertedInput = atoi(inputBuffer);
//        
//        // Process user input
//        switch(convertedInput)
//        {
//            // Print hello world
//            case 1:
//                printf("Hello World!\r\n");
//                __delay_ms(2000);   // Wait 2 seconds
//                break;
//            case 2:
//                sumTwoNums();
//                break;
//            case 3:
//                printf("Please enter a string\r\n");
//                getStringInput(inputBuffer);
//                printf("You said : %s\r\n", inputBuffer);
//                printf("It was %d characters long.\r\n", strlen(inputBuffer));
//                break;
//            case 4:
//                infiniteCounter();
//                break;
//            case 5:
//                menuStatus = false;
//                break;
//        }
//        
//        
//        
//    }
    
    printf("END OF PROGRAM\r\n");
    

    return 0;
}
#endif

// The following function reads the input sent from the PC through UART.
// This function will read until a newline character is sent through UART (\n).
// This function will modify inputBuffer to contain the string read through UART.
// The string will contain the null terminator (\0). The input read from the user
// will be sent back to through UART one character at a time to represent a
// command line
// REQUIRES MAX_BUFFER_SIZE TO BE DEFINED
void getStringInput(char *inputBuffer)
{
    int len = 0;
    char lastReadChar;
    
    strcpy(inputBuffer, "");        // Emptying inputBuffer
    
    while(len < MAX_BUFFER_SIZE)
    {
        // Wait until the buffer contains something
        while(UART1_ReceiveBufferIsEmpty());
        
        // Read latest char sent through UART
        lastReadChar = UART1_Read();
        
        // If newline(ASCII 13) is encountered, then string has ended 
        if(lastReadChar == 13)
            break;
        
        // If backspace(ASCII 8) is encountered, then simulate a backspace through UART
        // Do not move cursor
        if(lastReadChar == 8)
        {
            printf("\b \b");            // Prints destructive backspace
            inputBuffer[--len] = '\0';  // Remove last character from buffer
            continue;
        }
            
        // Print latest char to console
        printf("%c", lastReadChar);
        inputBuffer[len++] = lastReadChar;
    }
    printf("\r\n");
    inputBuffer[len] = '\0';
    
    return;
}
