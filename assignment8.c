/************************ prologue *******************/
/*Copyrighted to Rajainder A*/
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 4 */
/* Topic: Pointers */
/* File name: assignment8.c*/
/* Date: August 7, 2017 */
/* Objective: Stack Processing*/
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXSTACK 5
#define EMPTYSTACK -1
#define TRUE 1
#define FALSE 0

/* global declarations */
typedef struct stack {
    int top;
    char stackelement[MAXSTACK];
}chstack;

int empty(chstack*);
char pop(chstack*);
void push(chstack*, char);


void myPrint(){
        int fd, defout;
        defout = dup(1);
        fd=open("outfile.txt", O_RDWR|O_CREAT);
        dup2(fd, 1); // redirect output to the file
        close(fd);
        close(defout);
        printf("STAMPA1\n");
        dup2(defout, 1); // redirect output back to stdout
        close(fd);
        close(defout);
        printf("STAMPA2\n");
}

/* function verifies whether stack is empty */
int empty (chstack *ps)
{
    if (ps->top == -1)
        return (TRUE);
    else
        return (FALSE);
} /* end of empty function */


char pop (chstack *ps)
{
    if (empty (ps) )
    {
        printf ("%s", "stack underflow");
        exit (1);
    } /* end of empty if */
    return (ps-> stackelement[ps->top--] );
} /* end of pop function */

void push (chstack *ps, char x)
{
    if (ps->top == MAXSTACK - 1 )
    {
        printf ("%s", "stack overflow");
        exit (1);
    } /* end of if */
    else
        ps->stackelement[++(ps->top) ] = x;
    return;
} /* end of push function */

/* start of main program logic */
int main()
{
    chstack alphstack, *asp;
    char seq, ch, keystroke;
    alphstack.top = EMPTYSTACK;
    asp = &alphstack;
/* fill up the stack with input from the user */
    for (int i = 0; i < MAXSTACK; i++)
    {
        printf ("\n Please enter the next char in seq: ");
        scanf ("%c%c", &seq, &keystroke);
        push (asp, seq);
    } /* end of first for loop */

/* empty the stack and print values */
    for (int i = 0; i < MAXSTACK; i++)
    {
        ch = pop (asp);
        printf ("\n next char in seq is: %c", ch);
    }
    printf ("\n\n End of character seq **\n");
    return 0;
} /* end of main routine */


