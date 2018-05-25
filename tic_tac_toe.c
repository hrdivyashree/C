#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <fcntl.h>
#include <unistd.h> 
//#include <conio.h>

char square[17] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k','l','m','n','p','q'};

FILE *f;

int checkwin();
void board();

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

int main()
{

    f = fopen("outfile.txt", "w");
    if (f == NULL) {
       printf("Error opening file!\n");
       exit(1);
    }
  
    int player = 1, i; 
    char choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a boxname(a-q):  ", player);
        scanf("%c", &choice);

        mark = (player == 1) ? 'X' : '0';

        if (choice == 'a' && square[1] == 'a')
            square[1] = mark;
            
        else if (choice == 'b' && square[2] == 'b')
            square[2] = mark;
            
        else if (choice == 'c' && square[3] == 'c')
            square[3] = mark;
            
        else if (choice == 'd' && square[4] == 'd')
            square[4] = mark;
            
        else if (choice == 'e' && square[5] == 'e')
            square[5] = mark;
            
        else if (choice == 'f' && square[6] == 'f')
            square[6] = mark;
            
        else if (choice == 'g' && square[7] == 'g')
            square[7] = mark;
            
        else if (choice == 'h' && square[8] == 'h')
            square[8] = mark;
            
        else if (choice == 'i' && square[9] == 'i')
            square[9] = mark;

        else if (choice == 'j' && square[10] == 'j')
            square[10] = mark;
            
        else if (choice == 'k' && square[11] == 'k')
            square[11] = mark;
            
        else if (choice == 'l' && square[12] == 'l')
            square[12] = mark;
            
        else if (choice == 'm' && square[13] == 'm')
            square[13] = mark;
            
        else if (choice == 'n' && square[14] == 'n')
            square[14] = mark;
            
        else if (choice == 'p' && square[15] == 'p')
            square[15] = mark;
            
        else if (choice == 'q' && square[16] == 'q')
            square[16] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();
        player++;
    }while (i == - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win<==\n", --player);
    else
        printf("==>\aGame draw<==\n");
    getch();

    fclose(f);
    return 0;
}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3] && square[3] == square[4])
        return 1;
        
    else if (square[5] == square[6] && square[6] == square[7] && square[7] == square[8])
        return 1;
        
    else if (square[9] == square[10] && square[10] == square[11] && square[11] == square[12])
        return 1;
        
    else if (square[13] == square[14] && square[14] == square[15] && square[15] == square[16] )
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9] && square[9] == square[13])
        return 1;
        
    else if (square[2] == square[6] && square[6] == square[10] && square[10] == square[14])
        return 1;
        
    else if (square[3] == square[7] && square[7] == square[11] && square[11] == square[15])
        return 1;
        
    else if (square[4] == square[8] && square[8] == square[12] && square[12] == square[16])
        return 1;
        
    else if (square[1] == square[6] && square[6] == square[11] && square[11] == square[16])
        return 1;
        
    else if (square[4] == square[7] && square[7] == square[10] && square[10] == square[13])
        return 1;
        
    else if (square[1] != 'a' && square[2] != 'b' && square[3] != 'c' &&
        square[4] != 'd' && square[5] != 'e' && square[6] != 'f' && square[7] 
        != 'g' && square[8] != 'h' && square[9] != 'i' && square[10] != 'j'
	&& square[11] != 'k' && square[12]!= 'l' && square[13]!= 'm' &&
	square[14] != 'n' && square[15] != 'p' && square[16] != 'q')
        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (0)\n\n\n");


    printf("     |     |     |     \n");
    printf("  %c  |  %c  |  %c  |  %c \n", square[1], square[2], square[3], square[4]);

    printf("_____|_____|_____|_____\n");
    printf("     |     |     |     \n");

    printf("  %c  |  %c  |  %c  |  %c \n", square[5], square[6], square[7], square[8]);

    printf("_____|_____|_____|_____\n");
    printf("     |     |     |     \n");

    printf("  %c  |  %c  |  %c  |  %c\n", square[9], square[10], square[11], square[12]);

    printf("_____|_____|_____|_____\n");
    printf("     |     |     |     \n");

    printf("  %c  |  %c  |  %c  |  %c\n", square[13], square[14], square[15], square[16]);

    printf("     |     |     |     \n");
}

