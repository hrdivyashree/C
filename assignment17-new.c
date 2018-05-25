#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 1000

FILE * fp;
long int pop();
long int eval_pre();
char infix[MAX], prefix[MAX];
long int stack[MAX];
int top;
int isempty();
int white_space(char symbol);

void infix_to_prefix();
int priority(char symbol);
void push(long int symbol);
long int pop();
long int eval_pre();

void infix_to_prefix()
{
    top =-1;
    for (int i =0; i < MAX; i++)
        stack[i]=0;
    top++;
    stack[top]=0;
    top=-1;
    int i,j,p,n;
    char next ;
    char symbol;
    char temp, tempc;
    n=strlen(infix);
    p=0;
    int ucount=0;
    for(i=n-1; i>=0; i--)
    {
        symbol=infix[i];
        //if(!white_space(symbol))
        {
            fprintf(fp,"Processing symbol <%c> \n", symbol);
            if(white_space(symbol)){
                fprintf(fp,"to prefix array <%c> \n", symbol);
                prefix[p++] = symbol;
                continue;
            }
            /*if an operand comes*/
            if(symbol<='9' && symbol>='0'){
                fprintf(fp,"to prefix array <%c> \n", symbol);
                prefix[p++] = symbol;
                continue;
            }
            switch(symbol)
            {
                case ')':
                    push(symbol);
                    fprintf(fp,"push to  stack %c \n", symbol);
                    break;
                case '(':
                    while( (next=pop()) != ')')
                        prefix[p++] = next;
                        fprintf(fp,") pop to prefix array %c \n", next);
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
//                    fprintf(fp,"stack top %ld priotity stacktop %d priority symbol %d \n",stack[top], (priority(stack[top])-'0'), (priority(symbol) -'0')) ;
//                    fprintf(fp,"stack top %ld priotity stacktop %d priority symbol %d \n",stack[top], (priority(stack[top])), (priority(symbol))) ;
                    while( !isempty( ) &&  (priority(stack[top]))> (priority(symbol))){
                        tempc = pop();
//                        fprintf(fp,"tempc %c to prefix array \n", tempc);
                        prefix[p++] = tempc;
                    }
                    fprintf(fp,"push symbol %c to stack\n",symbol);
                    push(symbol);
                    break;
                default:
                    ucount ++;
                    if (ucount ==1){
                        fprintf(fp,"symbol %c , push - \n", symbol);
                        push('-');
                    }
                    if (ucount == 3) ucount=0;
                    break;
            }
        }
    }
    while(!isempty( ))
        prefix[p++] = pop();
    prefix[p] = '\0'; /*End prefix with'\0' to make it a string*/

    for(i=0,j=p-1;i<j;i++,j--)
    {
        temp=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=temp;
    }
}/*End of infix_to_prefix()*/

/* This function returns the priority of the operator */
int priority(char symbol )
{
    switch(symbol)
    {
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default :
            return 0;
    }/*End of switch*/
}/*End of priority()*/

void push(long int symbol)
{
    if(top > MAX)
    {
        fprintf(fp,"Stack overflow\n");
        exit(1);
    }
    else
    {
        top=top+1;
        stack[top] = symbol;
    }
//    fprintf(fp,"Stack top %d\n", top);
}/*End of push()*/

long int pop()
{
    if(top == -1 )
    {
        fprintf(fp,"Stack underflow \n");
        exit(2);
    }
    return (stack[top--]);
}/*End of pop()*/
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int white_space(char symbol)
{
    if(symbol==BLANK || symbol==TAB || symbol=='\0')
        return 1;
    else
        return 0;
}/*End of white_space()*/

long int eval_pre()
{
    long int a,b,temp,result;
    int i;
    long int num, tempi, ucount=0;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
//        fprintf(fp,"Processing %c \n", prefix[i]);
        if(white_space(prefix[i])){
//            fprintf(fp,"Whitespace continue..\n");
            continue;
        }
        num=0;
        if(prefix[i]<='9' && prefix[i]>='0'){

            num = prefix[i]-48;
            tempi=i-1;
            while(!white_space(prefix[tempi])){
                num += prefix[tempi]-48;
                i--;
                tempi = i-1;
            //push( prefix[i]-48 );
            }
//            fprintf(fp,"pushing num %ld\n", num);
            push(num);
        }
        else
        {
            switch(prefix[i])
            {
                case '+':
                    b=pop();
                    a=pop();
                    temp=b+a;
//                    fprintf(fp,"+ %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                case '-':
                    b=pop();
                    a=pop();
                    temp=b-a;
//                    fprintf(fp,"- %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                case '*':
                    b=pop();
                    a=pop();
                    temp=b*a;
//                    fprintf(fp,"* %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                case '/':
                    b=pop();
                    a=pop();
                    temp=b/a;
//                    fprintf(fp,"/ %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                case '%':
                    b=pop();
                    a=pop();
                    temp=b%a;
//                    fprintf(fp,"mod %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                case '^':
                    b=pop();
                    a=pop();
                    temp=pow(b,a);
//                    fprintf(fp,"pow %ld %ld %ld", b, a, temp);
                    push(temp);
                    break;
                default:
                    ucount ++;
                    if (ucount ==1){
                        b=pop();
                        a=pop();
                        temp=b-a;
//                        fprintf(fp,"- %ld %ld %ld", b, a, temp);
                        push(temp);
                    }
                    if (ucount == 3) ucount=0;
                    break;
            }
        }
    }
    result=pop();
    return result;
}/*End of eval_pre */


int main()
{
    long int value, val = 2;char inp;
    top = -1;
    FILE * ifp = fopen("infix.txt","r");
    fp = fopen("assignment17.doc","w+");
    if (NULL == ifp) {
        perror("File not found!");
        fclose(ifp);
        fclose(fp);
        exit(-1);
    }
    fprintf(fp,"Reading input values to be inserted from file %s\n","infix.doc");
    fflush(fp);
    for (int i = 0; fscanf(ifp, "%c", &inp) != EOF; i++) {
        infix[i]= inp;
    }
    fprintf(fp,"infix: %s\n",infix);
    //fprintf(fp,"Enter infix : ");
    gets(infix);
    infix_to_prefix();
    fprintf(fp,"prefix : %s\n",prefix);
    fflush(fp);
    value=eval_pre();
    fprintf(fp,"Value of expression : %ld\n",value);
    fflush(fp);
    return 0;

}/*End of main()*/


/*
 * ( 25 % 7 * 8 ) / ( 75 / 5 – 8 + ( 2 ^ 4 – ( 2 ^ 2 + 16 ) + 16 – 3 ) + 5 – 3 ^ 2 )


/*% 25  7  8   ^-++-/ 75  5  8  -+-^ 2  4  +^ 2  2  16   16  3   5  3  2


/*%25 7  8  +/75  5 – 8 -+^2  4  ++^2  2  16 -16 3 - 5 ^ 3  2

/32

+ 15 - 8 -+16 - 20
 */