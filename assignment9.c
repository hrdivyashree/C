/************************ prologue *******************/
/*Copyrighted to Rajainder A. */
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 9 */
/* Topic: Pointers */
/* File name: assignment9.c*/
/* Date: August 8, 2017 */
/* Objective: Stack Processing*/
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//#include <curses.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXQUEUE 25
#define MINQUEUE -1
#define TRUE 1
#define FALSE 1

typedef struct queue{
    int front, rear;
    char data[MAXQUEUE];
} myQueue;

int IsEmpty(myQueue* );
void Insert(myQueue* ,char);
char Remove(myQueue*);

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

int IsEmpty(myQueue* q){
    if (q->front == q->rear){
//        printf("Queue is Empty\n");
        return TRUE;
    }
    else return FALSE;
}

char Remove(myQueue* q){
    if (q->front == q->rear){
        printf("Queue Underflow, cannot remove elements. Exiting\n");
        exit(1);
    }
    if(q->front == MAXQUEUE-1) q->front = 0;
    else ++(q->front);
    return q->data[q->front];
}

void Insert(myQueue* q, char value){
    if(q->rear == MAXQUEUE-1) q->rear=0;
    else ++(q->rear);
    if(q->rear == q->front){
        printf("Queue Overflow, cannot add anymore elements. Exiting");
        exit(1);
    }
    q->data[q->rear]=value;
    return;
}

void Display(myQueue* q){
    int qf, qr;
    qf=q->front; qr=q->rear;
    printf("Queue Contents: ");
    for(int i=qf+1 ; i <= qr; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(void) {
    myQueue q, *qp;
    q.rear = q.front = -1;
    qp = &q;
    char op, keystroke;
    int input, data;

//    for(int i=0;  i < MAXQUEUE; i++){
//        printf("Please enter the next character in the sequence\n");
//        scanf("%c%c", &seq, &keystroke);
//        Insert(qp, seq);
//    }
//    for(int i=0; i< MAXQUEUE; i++){
//        ch = Remove(qp);
//        printf("Next character in the sequence %c\n", ch);
//    }
//    printf("Reached the end of queue\n");
    printf("Enter operation to be performed:\'E/e\'-Enqueue \'D/d\'-Dequeue \'q/Q\'-Quit: ");
    scanf("%c%c", &op, &keystroke);
    while(op != 'q' && op != 'q'){
        switch (op) {
            case 'E':
            case 'e':
                printf("Enter number to be enqueued: ");
                scanf("%d%c", &input, &keystroke);
                printf("Inserting %d into Queue \n", input);
                Insert(qp, input);
                Display(qp);
                break;
            case 'D':
            case 'd':
                data = Remove(qp);
                printf("Dequeued %d from queue \n", data);
                Display(qp);
                break;
            case 'q':
            case 'Q':
                printf("Quitting program\n");
                exit(0);
            default:
                printf("Invalid operation entered %c\n", op);
                break;
        }
        printf("Enter operation to be performed:\'E/e\'-Enqueue \'D/d\'-Dequeue \'q/Q\'-Quit: ");
        scanf("%c%c", &op, &keystroke);
    }
}

