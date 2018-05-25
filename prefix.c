#define SIZE 50 /* Size of Stack */
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include<stdio.h>

char s[SIZE]; int top=-1; /* Global declarations */

void push(char elem)
{ /* Function for PUSH operation */
    s[++top]=elem;
}

char pop()
{ /* Function for POP operation */
    return(s[top--]);
}

int pr(char elem)
{ /* Function for precedence */
    switch(elem)
    {
        case '#': return 0;
        case ')': return 1;
        case '^': return 2;
        case '+':
        case '-': return 3;
        case '*':
        case '%':
        case '/':return 4;
    }
    return -1;
}

char* strrev(char *str)
{
    int start, end, len;
    char temp, *ptr = NULL;
    // find length of string
    len = strlen(str);
    // create dynamic pointer char array
    ptr = malloc(sizeof(char)*(len+1));
    // copy of string to ptr array
    ptr = strcpy(ptr,str);
    // swapping of the characters
    for (start=0,end=len-1; start<=end; start++,end--)
    {
        temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
    }
    // return pointer of reversed string
    ptr[len]='\0';
    printf("Ptr %s ", ptr);
    return ptr;
}


char* load_file(char const* path)
{
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "rb"); //was "rb"

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        printf("lenghth %ld", length);
        fseek (f, 0, SEEK_SET);
        buffer = (char*)malloc((length+1)*sizeof(char));
        if (buffer)
        {
            fread (buffer, sizeof(char), length, f);
        }
        fclose (f);
    }
    buffer[length] = '\0';
    // for (int i = 0; i < length; i++) {
    //     printf("buffer[%d] == %c\n", i, buffer[i]);
    // }
    //printf("buffer = %s\n", buffer);

    return buffer;
}

int main()
{ /* Main Program */
    char infx[100],prfx[100],ch,elem;
    char* buffer;
    char* revbuffer;
    int i=-1,k=-1; int count;
    char val; int ival;
    printf("\n\nRead the Infix Expression ? ");
    FILE* ifp = fopen("infixin.txt","r" );
    if (NULL == ifp) {
        perror("File not found!");
        fclose(ifp);
        exit(-1);
    }
    int icount=0, scount=0, pnumc=0;
    //fprintf(ofp,"Reading input values to be inserted from file %s\n","btreeinput.doc");
    for (int i = 0; fscanf(ifp, "%c", &val) != EOF; i++) {
        printf("symbol %c ", val);
        if(isdigit(val)){
            num+=val;
            pnumc++;
        }
        else{
            symbols[scount]=val;
            if(pnumc != 0 && num !=0 ){
                numberlist[icount]=num;
                icount++;
                pnumc=0;
                num=0;
            }
            scount++;
        }
    }

//    buffer = load_file("infixin.txt" );
//    char revstr[count];
//    for (int i = count-1; i >=0 ; i--){
//        revstr[count-1-i] = infx[i];
//    }
//    push('#');
//    printf("Infix -->%s", buffer);
//    strcpy( infx, strrev(buffer));
//    printf("revstr-->%s\n", strrev(buffer));
//    for(int i =0; i < strlen(infx); i++)
//        printf("Infix --> %c ", infx[i]);
//    while( (ch=infx[i++]) != '\0')
//    {
//        if( ch == ')')
//            push(ch);
//        else if(isalnum(ch))
//            prfx[k++]=ch;
//        else if( ch == '(')
//        {
//            while( s[top] != ')')
//                prfx[k++]=pop();
//            elem=pop(); /* Remove ) */
//        }
//        else
//        { /* Operator */
//            while( pr(s[top]) >= pr(ch) )
//                prfx[k++]=pop(); push(ch);
//        }
//    }
//    while( s[top] != '#') /* Pop from stack till empty */
//        prfx[k++]=pop();
//    prfx[k]='\0'; /* Make prfx as valid string */
//    printf("Prefix %s", prfx);
//    //revbuffer = strrev(prfx);
//    buffer = strrev(infx);
//    printf("\n\nGiven Infix Expn: %s \nPrefix Expn: %s\n",buffer,revbuffer);
    return 0;
}
