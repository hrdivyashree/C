/************************ prologue *******************/
/* University of California Extension, Santa Cruz */ 
/* Advanced C Programming */ 
/* Instructor: Rajainder A. */ 
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 1 */
/* Topic: Chapter 1 & Chapter 2*/
/* File name: assignment1.c*/
/* Date: July 20, 2017 */ 
/* Objective: Temperature Conversion from degree celcius 
	      to degree fahrenheit and vice versa */
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void) 
{
  int input; 
  float fh, cs, degrees; 
  
  printf("select an option for temperature conversion:\n");
  printf("1. Convert celsius to fahrenheit\n"); 
  printf("2. Convert fahrenheit to celsius\n"); 
  scanf("%d", &input);
  if(input !=1 && input !=2){
  	printf("You selected invalid option #%d. Please select 1 or2\n", input);
	exit(-1);
  } 
  if (input == 1){ 
	  printf("Enter a temperature value to convert to fahrenheit:\n");
	  scanf("%f",&degrees);
	  fh = (9.0/5.0)*degrees+32;
	  printf("%.2f C temperature in fahrenheit = %.2f F\n",degrees,fh);
  }
  else if(input == 2){
	  printf("Enter a temperature value to convert to celsius:\n");
	  scanf("%f",&degrees);
	  cs = (5.0/9.0)*(degrees-32);
	  printf("%.2f F temperature in celsius = %.2f C\n",degrees,cs);
  }
  return 0;
}
