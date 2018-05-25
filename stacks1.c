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
#include <string.h>
#include <curses.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXSTACK 1000
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
    char expression[100]="{x+(y–[a+b])*(c–[(d+e)] +k)}/(h–(j–(k–[l–n])))+{u+ [m *(p – q)] / r }\0";
    //char expression[100]="{x+y–[a+b])*(c–[(d+e)]+k)}/(h–(j–(k–[l–n])))+{u+[m *(p–q)]/r}\0";
    char val, stackval;
    printf("Evaluating Expression\n %s \n", expression);

/* fill up the stack with input from the user */
    for (int i = 0; i < strlen(expression); i++)
    {
        val = expression[i];
        switch (val)
        {
            case '(':
            case '{':
            case '[':
                printf("Pushing \'%c\' to stack\n", val);
                push(asp, val);
                break;
            case ')':
            case '}':
            case ']':
                printf("Reached a closing \'%c\' in the expression\n", val);
                stackval = pop(asp);
                switch(stackval){
                    case '(':
                        if( val == ')'){
                            printf("Matched \'%c\' on stack with \'%c\'\n", stackval, val);
                            break;
                        }
                        else
                        {
                            printf("Unbalanced expression, unmatched \'%c\'\n", val);
                            exit(-1);
                        }
                    case '[':
                        if( val == ']') {
                            printf("Matched \'%c\' on stack with \'%c\'\n", stackval, val);
                            break;
                        }
                        else
                        {
                            printf("Unbalanced expression, unmatched \'%c\'\n", val);
                            exit(-1);
                        }
                    case '{':
                        if( val == '}'){
                            printf("Matched \'%c\' on stack with \'%c\'\n", stackval, val);
                            break;
                        }
                        else
                        {
                            printf("Unbalanced expression, unmatched \'%c\'\n", val);
                            exit(-1);
                        }
                    default:
                        printf("Unbalanced expression");
                        exit(-1);
                }
                break;
            default:
                printf("Not pushing \'%c\' to stack\n", val);
                break;
        }
    } /* end of first for loop */

    if (empty (asp) )
    {
        printf("Expression is balanced\n");
    } /* end of empty if */
    return 0;
} /* end of main routine */


