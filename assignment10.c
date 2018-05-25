/************************ prologue *******************/
/*Copyrighted to Rajainder A. */
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 10 */
/* Topic: Pointers */
/* File name: assignment10.c*/
/* Date: August 22, 2017 */
/* Objective: Towers of Hanoi */
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void towers(int, char, char, char);
FILE* fp;

int main()
{
    int num;
    fp = fopen("assignment10.doc", "a+");
    fprintf(fp,"Enter the number of disks : \n");
    fflush(fp);
    scanf("%d", &num);
    fprintf(fp,"%d\n", num);
    fprintf(fp,"The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        fprintf(fp,"Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    fprintf(fp,"Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}