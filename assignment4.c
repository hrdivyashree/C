/************************ prologue *******************/
/* University of California Extension, Santa Cruz */ 
/* Advanced C Programming */ 
/* Instructor: Rajainder A. */ 
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 4 */
/* Topic: Functions */
/* File name: assignment4.c*/
/* Date: July 20, 2017 */ 
/* Objective: Call functions to find the average, minimum, and
	maximum score for each student. Call a
	function to assign the student number using a
	static variable for the student number which
	will automatically increment whenever the
	function is called. Show the student number
	along with the statics for the scores. Find the
	average, minimum, and maximum for all
	students. Print all scores for each student.
	Write all the output to a file. Assign a letter
	grade for each score and print. */
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int saveDatatoStudent(studentID, test1, test2, test3){ 
 int sum = test1+test2+test3; 
 float avg = (float)sum/3; 
 int scores[3];
 scores[0]=test1; 
 scores[1]=test2; 
 scores[2]=test3; 
 int min = scores[0];
 int max = scores[0];
 for (int i =0; i < 3; i++){
    if(scores[i] < min)
	min = scores[i]; 
 } 
 for (int i =0; i < 3; i++){
    if(scores[i] > min)
	max = scores[i]; 
 } 
 printf("------Student ID %d-------\n", studentID); 
 printf("Average=%f\n", avg);
 printf("Minimum=%d\n", min);
 printf("Maximum=%d\n", max);
 return 0;
}

int main(void) 
{
   int numberArray[6];
   int test1, test2, test3;
   char buffer[1024];
   char filename[] = "infile.txt";
   FILE *file = fopen (filename, "r" );
   char* buf; 

   int linen=0; 
   if (file != NULL) {
       while(fgets(buffer,sizeof buffer,file)!= NULL){ 
          fscanf(file, "%d,%d,%d", &test1,&test2, &test3);
	  linen++;
	  int rc = saveDatatoStudent(linen, test1, test2, test3);
	}
   fclose(file);
   }
   else {
      perror(filename); //print the error message on stderr.
   }
   return(0);
}

