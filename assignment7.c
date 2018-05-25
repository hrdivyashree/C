/************************ prologue *******************/
/* Chapter 23 -- Backtracking 8 queens problem */
/* Copyrighted to Rajainder A*/
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 7 */
/* Topic: Pointers */
/* File name: assignment7.c*/
/* Date: August 11, 2017 */
/* Objective: Backtracking*/
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define BOARDSIZE 8
#define DIAGONAL (2 * BOARDSIZE - 1)
#define DOWNOFFSET 7
#define FALSE 0
#define TRUE 1

int queencol[BOARDSIZE]; /*queen column*/
bool colfree[BOARDSIZE]; //is column free
bool upfree[DIAGONAL]; //up diagonal free
bool downfree[DIAGONAL]; //down diagonal free
int queencount = -1; //row queen is placed

void writeBoard (void);
void clearBoard (void);
void addQueen (void);

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

void addQueen(void)
{
	int col; /* column being tried for the queen */
	queencount++;
//    printf("queencount %d\n", queencount);
	for (col = 0; col < BOARDSIZE; col++)
	{
		if (colfree[col] && upfree[queencount + col] && downfree[queencount - col + DOWNOFFSET ] )
		{ // put the queen in position (queencount, col)
			queencol[queencount] = col;
			colfree[col] = FALSE;
			upfree[queencount + col] = FALSE;
			downfree[queencount - col + DOWNOFFSET] = FALSE;
			if (queencount == BOARDSIZE - 1)
			{ /* terminal condition */
				printf("\n %d Queen Solution\n\n", 8);
				writeBoard();
				printf("\n Found Solution Breaking \n");
				break;
			}
			else
			{
				addQueen (); /* recursive call */
			}
			if (queencount - 1 < 0)
			{
				printf("queencount is -1\n");
				continue;
			}
        	printf("Backtracking Queen QueenCount=%d\n",queencount);
			colfree [col] = TRUE; // backtrack queen
			upfree[queencount - 1 + col] = TRUE;
			downfree [queencount - 1 - col + DOWNOFFSET] = TRUE;
			queencount--;
		} /* end of if colfree */
	} /* end of for loop */
//	printf("queencount %d\n", queencount);
//	printf("Enf of addqueen\n");
} /* end of function addQueen */

/* prints the output of N queens placement */
void writeBoard(void)
{
	int col;
	static int qcount = 0;
	for (col = 0; col < BOARDSIZE; col++)
	{
		if (queencol[qcount] == col)
		printf("Q ");
		else
		printf("* ");
	} /* end of for loop */
	printf ("\n\n");
	if (qcount++ < BOARDSIZE - 1)
        writeBoard ();
	qcount = 0;
} /* end of writeBoard function */


/* clears the board for next placement */
void clearBoard(void)
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		colfree [i] = TRUE;
		queencol [i] = -1;
	} /* end of for loop */
	for (int j = 0; j < DIAGONAL; j++)
	{
		upfree [j] = TRUE;
		downfree [j] = TRUE;
	} /* end of for loop */
	queencount = -1;
} /* end of clearBoard function */

int main(void)
{
	int inputcol=0, queenc=0;
    char c, keystroke;
	printf("Enter a column number(1-8) or -1 to quit\n");
	scanf("%d%c", &inputcol, &keystroke);
    /*
	do {
		c = getchar();
	}
	while (!isdigit(c));
	ungetc(c, stdin);
    */

	while(inputcol != -1){
		clearBoard();
		if (inputcol < 1 || inputcol > 8){
			printf("Invalid column entry.\n");
			printf("Enter a column number(1-8) or -1 to quit\n");
			exit(-1);
		}
		queencol[++queencount] = inputcol-1;
		colfree[inputcol-1] = FALSE;
		upfree[ queencount + inputcol-1] = FALSE;
		downfree [queencount - inputcol-1 + DOWNOFFSET] = FALSE;
		addQueen();
		printf("Enter a column number(1-8) or -1 to quit\n");
		scanf("%d%c", &inputcol, &keystroke);
	}
	printf("Bye Bye\n");
    return 0;
} /* end of main function */
