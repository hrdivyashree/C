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

typedef unsigned long ul;
static int studentID=1000;

int getStudentID()
{
  studentID++;
  return studentID;
}

static int testscores[60];

int readscores(){ 
    FILE* fp = fopen("scores.txt", "r");

    if (NULL == fp) {
        perror("File not found!");
        exit(-1);
    }

    for (int i = 0; fscanf(fp, "%d%*c", &testscores[i]) > 0 && i < 60; i++) {
	; 
    }

    fclose(fp);
    return 0;
}

int divideTestScores(int students){
	int arraysize = (int)sizeof(testscores)/sizeof(testscores[0]);
	//printf("Size of array %d\arraysize",n);
	int offset = arraysize/students;  
        return offset; 	
}

void printScores(id,offset,studid){
 printf("Student %d Scores --> [",studid);
 for(int i=(id*offset); i<((id+1)*offset); i++)
 {
	printf("%d, ",testscores[i]);
 }
 printf("]\n");
}

float average(id,offset){
 int sum=0;float avg;
 if (id == -1){ 
   for(int i=0; i<60; i++){ 
     sum+=testscores[i]; 
   }
 avg=(float)sum/60; 
 }
 else { 
   for(int i=(id*offset); i<((id+1)*offset); i++)
   { 
      sum+=testscores[i]; 
   }
 printf("Sum %d Offset %d \n", sum,offset);
 avg=(float)sum/offset; 
 }
 return avg;
}

int maximum(id,offset){
 int max;
 if (id == -1){
 max=testscores[0];
   for(int i=0; i<60; i++){
         if(testscores[i] > max)
           max=testscores[i];    
   }
 }
 else {
 max=testscores[id*offset];
 for(int i=(id*offset); i<((id+1)*offset); i++)
 {
	if(testscores[i] > max)
	   max=testscores[i];
 }
 }
 return max;
}

int minimum(id,offset){
 int min;
 if (id == -1){
 min=testscores[0];
   for(int i=0; i<60; i++){
         if(testscores[i] < min)
           min=testscores[i];
   }
 }
 else {
 min=testscores[id*offset];
 for(int i=(id*offset); i<((id+1)*offset); i++)
 {
        if(testscores[i] < min)
           min=testscores[i];
 }
 }
 return min;
}

int main(void){ 
  int students;
  readscores();
  printf("Enter the number of students (4,5,6) or enter -1 to quit \n");
  scanf("%d", &students);
  while (students != -1){
      if (students < 4 || students > 6){
		printf("Invalid input entry. Exiting\n");
		exit(-1);
      }
      int arraysize = (int)sizeof(testscores)/sizeof(testscores[0]);
      int offset = arraysize/students;
      for(int id=0; id<students; id++){ 
	int studid = getStudentID();
	printScores(id,offset,studid);
	printf("Student %d--> Average=%0.2f Maximum=%d Minimum=%d\n", studid,average(id,offset), maximum(id,offset), minimum(id,offset));
      }
      printf("Number of students %d \n", students);
      printf("Total Average %0.2f, Maximum for %d students %d, Minimum for %d students %d \n", average(-1,offset), students, maximum(-1,offset), students, minimum(-1,offset)); 
      printf("Enter the number of students (4,5,6) or enter -1 to quit \n");
      studentID=1000;
      scanf("%d", &students);
  }
  printf("Got -1, Bye Bye\n");
  return 0;
}
