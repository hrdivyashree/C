/************************ prologue *******************/
/* University of California Extension, Santa Cruz */ 
/* Advanced C Programming */ 
/* Instructor: Rajainder A. */ 
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 3 */
/* Topic: Arrays */
/* File name: assignment3.c*/
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
  int input; 
  if ( argc == 1 ) { 
	 printf("Enter an array of numbers\n");
	 printf("Usage Example: ./array 91 95 80 72 100 98 89 94 92 96\n");
	 return -1;  
  }
  int numscores = argc-1; 
  int myArray[numscores];
  for(int i=1; i<argc; i++) { 
     int num = atoi(argv[i]);
     myArray[i-1]=num;
  }
  printf("Array as entered\n");
  for (int i = 0; i < numscores; i++)
  {
	printf("%d, ", myArray[i]); 
  }
  printf("\nArray Reversed \n");
  for (int i = numscores-1; i >= 0; i--)
  {
	printf("%d, ", myArray[i]); 
  }
  printf("\n");
  int temp; 
  int origarray[numscores]; 
  for (int i=0; i < numscores; i++) {
	origarray[i]=myArray[i];
  }
  for (int i=0; i < numscores; i++) { 
     for (int j = i+1; j < numscores; j++){ 
	if (myArray[i] > myArray[j]) { 
	    temp = myArray[i]; 
	    myArray[i] = myArray[j];
	    myArray[j] = temp; 
	} 
     }	 
  }
  printf("Array in ascending order\n");
  for (int i = 0; i < numscores; i++)
  {
        printf("%d, ", myArray[i]);
  }
  printf("\n");
  
  int numtoidx; 
  printf("Enter a Number to get the index, enter -1 to exit \n");
  scanf("%d", &numtoidx);
  while ( numtoidx != -1 ) {  
	  int found=0;int idx; 
	  for(int i = 0; i < numscores; i++) { 
		if(origarray[i] == numtoidx){ 
		    found=1;
		    idx = i; 
		}
	  }
	  if (found ==1){ 
		    printf("The index of %d is %d\n",numtoidx, idx); 
	  }
	  else { 
		    printf("Number %d not found in array \n",numtoidx);
	  }
	  printf("Enter a Number to get the index, enter -1 to exit \n");
	  scanf("%d", &numtoidx);
  }
  printf("Got -1, Bye Bye\n");
  
}
