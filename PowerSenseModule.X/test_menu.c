#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include <libpic30.h>
#include "device_configuration.h"


// DEFINITIONS
#define MAX_BUFFER_SIZE 64            // Maximum size input string can be

#ifdef DEBUG_TEST_MENU
void main(void)
{
    int convertedInput;                     // Input converted into integer
    char inputBuffer[MAX_BUFFER_SIZE];      // Will hold current input
    bool menuStatus = true;                 // Menu programs runs as long as menuStatus = true
    
    // initialize the device
    SYSTEM_Initialize();
    UART1_Initialize();
    UART1_Enable();
 
    // Loop the menu until user quits
    while(menuStatus)
    {
        printf("\r\n\n\n\n\n\n");
        printf("==============TEST MENU==============\r\n");
        printf("\t1. Print Hello World!\r\n");
        printf("\t2. Sum two numbers.\r\n");
        printf("\t3. Parrot back a string!\r\n");
        printf("\t4. Infinite counter.\r\n");
        printf("\t5. Exit\r\n");
        printf("=====================================\r\n");
        
        
        
        getStringInput(inputBuffer);
        
        // Verifying if input is proper
        if(strlen(inputBuffer) != 1 || inputBuffer[0] < '1' || inputBuffer[0] > '5')
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
                sumTwoNums();
                break;
            case 3:
                printf("Please enter a string\r\n");
                getStringInput(inputBuffer);
                printf("You said : %s\r\n", inputBuffer);
                printf("It was %d characters long.\r\n", strlen(inputBuffer));
                break;
            case 4:
                infiniteCounter();
                break;
            case 5:
                menuStatus = false;
                break;
        }
        
        
        
    }
    
    printf("END OF PROGRAM\r\n");
    

    
}


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

// The following function uses UART to prompt the user for two numbers.
// The function then adds the two numbers together and sends the result
// back to the user through UART. Uses getStringInput.
// Works with negative numbers
void sumTwoNums(void)
{
    char currentInput[6];
    int inputOne, inputTwo, i;
    bool isNum = true;
    strcpy(currentInput, "");
    
    printf("\r\n\n\n\nWelcome to the adding function!\r\n");
    printf("Please enter a number\r\n");
    
    // Checking if given input is a number
    do
    {
        getStringInput(currentInput);
        isNum = true;
        for(i = 0; currentInput[i] != '\0'; i++)
        {
            if(isdigit(currentInput[i]) || currentInput[i] =='-')
                continue;
            else
            {
                isNum = false;
                printf("Hey! That wasn't a number. Try again.\r\n");
                __delay_ms(2000);   // Wait 2 seconds
                break;
            }
        }
    }while(!isNum);
    
    inputOne = atoi(currentInput);
    
    printf("Please enter another number\r\n");    
    // Checking if given input is a number
    do
    {
        getStringInput(currentInput);
        isNum = true;
        for(i = 0; currentInput[i] != '\0'; i++)
        {
            if(isdigit(currentInput[i]) || currentInput[i] =='-')
                continue;
            else
            {
                isNum = false;
                printf("Hey! That wasn't a number. Try again.\r\n");
                __delay_ms(2000);   // Wait 2 seconds
                break;
            }
        }
    }while(!isNum);
    
    inputTwo = atoi(currentInput);
    printf("%d + %d = %d\r\n", inputOne, inputTwo, inputOne + inputTwo);
    
}

// The following program is an infinite counter that only stops
// when the user preses ctrl + c (ASCII 3) or when the user presses q
void infiniteCounter(void)
{
    int i = 0;
    char readInput;
    bool counterStatus = true;
    
    printf("Welcome to the infinite counter!\r\n");
    printf("To stop the counter press q or ctrl + c\r\n");
    printf("The timer will begin in 5 seconds\r\n");
    __delay_ms(5000);
    while(counterStatus)
    {
        printf("%d\r\n", i++);
        while(!UART1_ReceiveBufferIsEmpty())
        {
            readInput = UART1_Read();
            if(readInput == 'q' || readInput == 3)
                counterStatus = false;
        }
        __delay_ms(500);
    }
    printf("You stopped the counter!\r\n");
    printf("Have a nice day!\r\n");
    __delay_ms(2000);
    
}

#endif