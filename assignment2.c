/************************ prologue *******************/
/* University of California Extension, Santa Cruz */ 
/* Advanced C Programming */ 
/* Instructor: Rajainder A. */ 
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 2 */
/* Topic: Loops */
/* File name: assignment2.c*/
/* Date: July 21, 2017 */ 
/* Objective:Printing Average, minimum and maximum of 
	     of all inputs received */ 
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char * argv []) 
{
  int input; float avg=0; int min; int max; int sum=0; 
  if ( argc == 1 ) { 
	 printf("Enter student scores for exams separated by spaces\n");
	 printf("Usage Example: ./avgscores 91 95 80 72 100 98 89 94 92 96\n");
	 return -1;  
  }
  printf("Input entered\n");
  int numscores = argc-1; 
  for(int i=1; i<argc; i++) { 
     int score = atoi(argv[i]);
     sum += score;
     if (i==1) { 
	min=score; max=score;  
     }
     else { 
	if (score < min) 
	   min = score; 
	if (score > max) 
	   max = score; 	
     }
     if (i == (argc-1)) { 
       printf("%d", score);
     }
     else { 
       printf("%d, ", score);
     }
  }
  printf("\n");
 
  printf("Total Scores: %d\n", sum); 
  printf("Average of Scores: %0.2f\n", (float)sum/(float)numscores);
  printf("Minimum of Scores: %d \n", min); 
  printf("Maximum of Scores: %d \n", max); 
}
