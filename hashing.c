/************************ prologue *******************/
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 15 */
/* Topic: Hashing */
/* File name: assignment15.c*/
/* Date: August 24, 2017 */
/* Objective: Hashing*/
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash *hashTable = NULL;
int HASHTBLSZ = 15;

FILE* ifp;
FILE* ofp;

struct node {
    int key, record;
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct node * createNode(int key, int record) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->record = record;
    newnode->next = NULL;
    return newnode;
}


void insertToHash(int key, int record) {
    int hashIndex = key % HASHTBLSZ;
    struct node *newnode =  createNode(key, record);
    /* head of list for the bucket with index "hashIndex" */
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    /* adding new node to the list */
    newnode->next = (hashTable[hashIndex].head);
    /*
     * update the head of the list and no of
     * nodes in the current bucket
     */
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void display() {
    struct node *myNode;
    int i;
    for (i = 0; i < HASHTBLSZ; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        fprintf(ofp,"\nData at index <%d> in Hash Table:\n", i);
        fprintf(ofp,"Key     Record \n");
        fprintf(ofp,"--------------------------------\n");
        while (myNode != NULL) {
            fprintf(ofp,"%-12d", myNode->key);
            fprintf(ofp,"%d\n", myNode->record);
            myNode = myNode->next;
        }
    }
    return;
}

int main() {
    int n, ch, key, record;
    ifp = fopen("hashinput.doc", "r");
    ofp = fopen("assignment15out.doc", "w+");
    if (NULL == ifp) {
        perror("File not found!");
        fclose(ifp);
        fclose(ofp);
        exit(-1);
    }

    /* create hash table with "n" no of buckets */
    hashTable = (struct hash *)calloc(n, sizeof (struct hash));

    //16 Oct 2013 00:01:00.000,0.000,0.000000
    //fscanf(filefd, "\n%24[^,]s,%5s", data, data2);
    //:<produce>::<description>::<produce>::<description>:...
    //if ((fscanf(file, ":%99[^:]::%99[^:]:", produce, description) != 2)

    fprintf(ofp,"Reading input values to be inserted from file %s\n", "hashinput.doc");
    for (int i = 0; fscanf(ifp, "%d:%d,", &key, &record) != EOF; i++) {
        fprintf(ofp,"Inserting key %d --> val %d into hashtable\n", key, record);
        insertToHash(key, record);
    }

    fprintf(ofp,"Displaying output from separate chained HashTable\n");
    display();
    free(hashTable);
    fclose(ifp);
    fclose(ofp);
}
