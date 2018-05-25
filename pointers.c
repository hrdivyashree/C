/************************ prologue *******************/
/* University of California Extension, Santa Cruz */ 
/* Advanced C Programming */ 
/* Instructor: Rajainder A. */ 
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 4 */
/* Topic: Pointers */
/* File name: assignment4.c*/
/* Date: July 25, 2017 */ 
/* Objective: Pointers understanding */ 
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){ 
    int intv = 25; 
    float flv = 3.142; 
    double dblv = 1.73217; 
    char strv[] = "Hello C programmer\0"; 
    char* strv1[] = {"Hello World\0","Good Day!\0"};
    char chv = 'x';
    char* strv2 = "Hello World, it's me, C programmer\0"; 
    
    int* intptr = &intv; 
    float* flptr = &flv; 
    double* dblptr = &dblv; 
    char* strptr = strv;
    char* charptr = &chv; 
    char** strarrptr = &*strv1;
    char* strptr2 = strv2 ;
    
    printf("Integer Value %d, Interger Pointer dereference %d \n", intv, *intptr);
    printf("Float Value %f, Float Pointer dereference %f \n", flv, *flptr);
    printf("Double Value %lf, double Pointer dereference %lf \n", dblv, *dblptr);
    printf("Char Value %c, Char Pointer dereference %c \n", chv, *charptr);
    printf("String Value %s, String Pointer dereference %s \n", strv, strptr);
    for (int i=0; i < 2; i++){ 
	    printf("String Multi Value %s, String Pointer dereference %s\n", strv1[i], strarrptr[i]);
    }
    printf("String Value %s, String Pointer dereference %s \n", strv2, strptr2);
    return 0;
}

