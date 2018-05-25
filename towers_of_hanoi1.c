/************************ prologue *******************/
/*Copyrighted to Rajainder A. */
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 11 */
/* Topic: Pointers */
/* File name: assignment11.c*/
/* Date: August 22, 2017 */
/* Objective: Towers of Hanoi */
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

struct listnode {
    int data;
    struct listnode* next;
};
typedef struct listnode node;
typedef struct listnode* nodeptr;

void insertnode(nodeptr*, int);
int deletenode(nodeptr*, int);
void deletelist(nodeptr*);
int isempty(nodeptr);
void printlist(nodeptr);
void instructions(void);

void instructions(){
 printf("\nEnter your choice\n");
 printf("1. Insert an element into the list\n");
 printf("2. Delete an element from the list\n");
 printf("3. Display list\n");
 printf("4. End\n");
}

int isempty(nodeptr head){
    return(head==NULL);
}

void printlist (nodeptr currptr)
{
    if (currptr == NULL) {
        printf ("List is empty. \n\n ");
    }
    else{
        //printf ("List is not empty. \n\n");
        while ( currptr != NULL)
        {
            printf ("%d --> ", currptr->data );
            currptr = currptr->next;
        }
        printf ("NULL\n\n");
    }
}

void insertsortednode(nodeptr* head, int value){
    nodeptr newptr, prevptr, currptr;
    newptr = (nodeptr)malloc(sizeof(node));
    printf("Inserting node %d ", value);
    if (newptr != NULL) {
        newptr->data = value;
        newptr->next = NULL;
        prevptr=NULL;
        currptr=*head;
        newptr->next = *head;
        head = &newptr;
        while(currptr != NULL && (value> currptr->data)){
            prevptr = currptr;
            currptr=currptr->next;
        }
        if(prevptr==NULL){
            newptr->next = *head;
            *head =  newptr;
            printf("Inserted node %d at head", value);
        } else{
            prevptr->next = newptr;
            newptr->next = currptr;
            printf("Inserted node %d at tail", value);
        }
    }
    else{
        printf("%d not inserted, memory not avaialable\n", value);
    }
}

void insertnode(nodeptr* head, int value){
    nodeptr newptr, prevptr, currptr;
    newptr = (nodeptr)malloc(sizeof(node));
    //printf("Inserting node %d\n", value);
    if (newptr != NULL) {
        newptr->data = value;
        newptr->next = NULL;
        prevptr=NULL;
        currptr=*head;
        while(currptr != NULL){
            prevptr = currptr;
            currptr=currptr->next;
        }
        if(prevptr==NULL){
            newptr->next = *head;
            *head = newptr;
//            printf("Inserted node %d at head\n", value);
        } else{
            prevptr->next = newptr;
            newptr->next = currptr;
//            printf("Inserted node %d at tail\n", value);
        }
    }
    else{
        printf("%d not inserted, memory not avaialable\n", value);
    }
}

int deletenode (nodeptr *head, int value){
   nodeptr prevptr, currptr, tempptr;
   if (value == (*head)->data ){
     tempptr = *head;
     *head = (*head)->next;
     free (tempptr);
     return (value);
   }
   else {
    prevptr = *head;
    currptr = (*head)->next;
    while ((currptr != NULL) && currptr->data != value) {
     prevptr = currptr;
     currptr = currptr->next;
    }
    if (currptr != NULL) {
     tempptr = currptr;
     prevptr->next = currptr->next;
     currptr = currptr->next;
     free(tempptr);
     return (value);
    }
   }
   return('\0');
}

void deletelist (nodeptr* head){
    nodeptr  currptr, tempptr;
    currptr=*head;
    while (currptr != NULL) {
        tempptr = currptr;
        currptr = currptr->next;
        free(tempptr);
    }
    *head=NULL;
}

static void reverse(nodeptr* head){
    nodeptr prev   = NULL;
    nodeptr current = *head;
    nodeptr next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    nodeptr head = NULL;
    int choice;
    int item,data;
    FILE *ifp, *ofp;
    ifp = fopen("linkedlistin.doc", "r");
    ofp = fopen("linkedlistout.doc", "a+");
    while(fscanf(ifp, "%d%*c", &item) != EOF) {
//        printf("data %d\n", item);
        insertnode(&head, item);
    }
    printf("Input list as read from the input file\n");
    printlist(head);
    reverse(&head);
    printf("Reversed linked list\n");
    printlist(head);

    printf("Enter a number to be deleted or -1 to Quit: \n");
    scanf("%d", &data);
    while (data != -1){
        if (!isempty(head)) {
            if (deletenode(&head, data)) {
                printf("Deleted %d\n ", data);
                printlist(head);

            } else {
                printf("Node %d not found\n", data);
            }
            printf("Enter a number to be deleted or -1 to Quit: \n");
            scanf("%d", &data);
        } else {
            printf("Empty List found! Quitting\n");
            exit(0);
        }
    }
    deletelist(&head);
    printf("User Quitting\n");
    return 0;
    /*
    instructions();
    printf("? ");
    scanf("%d", &choice);
    while (choice != 4) {
        switch(choice){
        case 1:
            printf("Enter a inetger to be inserted in the list: ");
            scanf("\n%d", &item);
            insertnode(&head, item);
            printlist(head);
            break;
        case 2:
            if (!isempty(head)) {
                printf("Enter an integer to be deleted: ");
                scanf("%d", &item);
                if (deletenode(&head, item)) {
                    printf("Deleted %d ", item);
                    printlist(head);

                } else {
                    printf("Node %d not found\n", item);
                }
            } else {
                printf("Empty List found\n");
                break;
            }
        case 3:
            if (!isempty(head)) {
                printlist(head);
            } else {
                printf("Empty List found\n");
            }
            break;
        default:
            printf("Enter an inetger to be deleted: \n");
            instructions();
            break;
        }
        printf("?");
        scanf("%d", &choice);
    }
    deletelist(&head);
    printf("End of Run\n");
    return 0;
    */

}