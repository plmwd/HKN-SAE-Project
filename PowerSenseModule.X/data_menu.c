#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "globals.h"                        // Required for global vars
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include <libpic30.h>
#include "device_configuration.h"



#ifdef DATA_MENU
bool menuStatus = false;    // menuOn must be global & initially false (Decides if menuy)
bool programStatus = true;



// These functions must be commented out in the tmr1 files
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
    printf("Press Z to enter data menu.\r\n");
    TMR1 = 0;
    T1CONbits.TON = 1;

}


// This program requires a modified uart1.c
int main(void)
{
    int convertedInput;                     // Input converted into integer
    char inputBuffer[MAX_BUFFER_SIZE];      // Will hold current input
    bool lastStatusOff = true ;             // Only true if menu is off
    // initialize the device
    SYSTEM_Initialize();
    UART1_Initialize();
    UART1_Enable();
    Init_Timer1();
    
    
    printf("START OF PROGRAM\r\n");
    
    while(programStatus)
    {
        lastStatusOff = true;
        while(menuStatus)
        {
            // If mode was just changed then we toss the Z in the buffer
            if(lastStatusOff)
                UART1_Read();
            lastStatusOff = false;
            
            IEC0bits.T1IE = 0;  // Disable Timer1 interrupt
            IFS0bits.T1IF = 0;  // Reset Timer1 interrupt flag
            T1CONbits.TON = 0;  // Disable Timer1 and stop the counter

            printf("\r\n\n\n\n\n\n");
            printf("==============TEST MENU==============\r\n");
            printf("\t1. Print Hello World!\r\n");
            printf("\t2. Print collected data.\r\n");
            printf("\t3. Output collected data to file.\r\n");
            printf("\t4. See statistics.\r\n");
            printf("\t5. Set calibration data.\r\n");
            printf("\t6. Output calibration data.\r\n");
            printf("\t7. Exit menu mode.\r\n");
            printf("\t8. Stop program\r\n");
            printf("=====================================\r\n");



            getStringInput(inputBuffer);

            // Verifying if input is proper
            if(strlen(inputBuffer) != 1 || inputBuffer[0] < '1' || inputBuffer[0] > '8')
            {
                printf("Invalid input. Please try again.\r\n");
                __delay_ms(1500);   // Wait 1.5 seconds so the user can think about what they did
                continue;
            }

            convertedInput = atoi(inputBuffer);

            // Process user input
            switch(convertedInput)
            {
                // Print hello world
                case 1:
                    printf("Hello World!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 2:
                    printf("Heres some sick data!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 3:
                    printf("Heres some sick data sent to a file!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 4:
                    printf("Heres some sick stats!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 5:
                    printf("Time to calibrate some data, yo!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 6:
                    printf("Heres the calibration data, yo!\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    break;
                case 7:
                    printf("Leaving menu mode\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    menuStatus = false;
                    IEC0bits.T1IE = 1;  // Enable Timer1 interrupt
                    IFS0bits.T1IF = 0;  // Reset Timer1 interrupt flag
                    T1CONbits.TON = 1;  // Enable Timer1 and start the counter
                    break;
                case 8:
                    printf("Shutting off\r\n");
                    __delay_ms(2000);   // Wait 2 seconds
                    menuStatus = false;
                    return 0;
                    break;
            }
        }
    }
 

    
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
