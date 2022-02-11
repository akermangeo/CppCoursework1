#include <stdio.h>
#include <stdlib.h>
// #include "ttt.h"

#define FALSE 0
#define TRUE 1
#define BOARD_NUM 9
#define X_MOVES_MAX 5
#define O_MOVES_MAX 4


char MAGIC_BOARD[BOARD_NUM] = {'2', '9', '4', '7', '5', '3', '6', '1', '8'};

char X_MOVES[X_MOVES_MAX];
int X_MOVES_LEN = 0;
char O_MOVES[O_MOVES_MAX];
int O_MOVES_LEN = 0;
char BLANKS[BOARD_NUM];

int game(char board[]);
void posistion(char board[], int board_len, char index, char player);
void pretty_print();
void arr_sub(char arr[], int arr_len, char item_before, char item_after);
void arr_append(char arr[], int arr_len, char player);
int any_n_sum_to_k(int n, int k, char arr[], int start, int end);
void print_arr(char arr[], int arr_len);
int is_legal_move(char move);

int game(char board[])
{   
    int X_move;
    int O_move;

    int game_over = 0;

    char line[1024];

    pretty_print();
    
    while (X_MOVES_LEN < 5) {
        /* Get the X move */
        printf("X move: ");
        fgets(line, 1023, stdin);   // leave 1 character for null terminator
        sscanf(line, "%d", &X_move);
        while (is_legal_move((char) (X_move + '0')) != TRUE){
            /* Warning */
            printf("Please input one of the digit in the board!\n");
            printf("╯    乀\n");
            printf("ヘ   へ \n");
            printf("  '   \n");
            printf("  ﹀ \n");

            printf("X move: ");
            fgets(line, 1023, stdin);   // leave 1 character for null terminator
            sscanf(line, "%d", &X_move);
        }
        
        posistion(board, BOARD_NUM, (char) (X_move + '0'), 'X');
        pretty_print();

        /*Check wether X has win*/
        if (any_n_sum_to_k(3, 15, X_MOVES, 0, X_MOVES_LEN)){
            game_over = 1;
            return game_over;
        } 
        else if (X_MOVES_LEN == 5 && O_MOVES_LEN == 4) {
            return game_over;
        }

        /* Get the O move */
        printf("O move: ");
        fgets(line, 1023, stdin);   // leave 1 character for null terminator
        sscanf(line, "%d", &O_move);
        while (is_legal_move((char) (O_move + '0')) != TRUE){
            /* Warning */
            printf("Hey! Input one of the digit in the board!\n");

            printf("O move: ");
            fgets(line, 1023, stdin);   // leave 1 character for null terminator
            sscanf(line, "%d", &O_move);
        }
                
        posistion(board, BOARD_NUM, (char) (O_move + '0'), 'O');
        pretty_print();


        /*Check wether O has win*/
        if (any_n_sum_to_k(3, 15, O_MOVES, 0, O_MOVES_LEN)){
            game_over = -1;
            return game_over;
        } 
        else if (X_MOVES_LEN == 5 && O_MOVES_LEN == 4) {
            return game_over;
        }
    }

    return game_over;
}


int is_legal_move(char move)
{
    for (int i = 0; i < BOARD_NUM; i ++){
        // printf("*** %c %c %d", )
        if (MAGIC_BOARD[i] == move){
            return TRUE;
        }
    }    
    return FALSE;
}


void pretty_print()
{
    for (int i = 0; i < (int) BOARD_NUM / 3; i++){
        printf("\t %c %c %c \n", MAGIC_BOARD[3*i], MAGIC_BOARD[3*i+1], MAGIC_BOARD[3*i+2]);
    }
}


int any_n_sum_to_k(int n, int k, char arr[], int start, int end)
{
    /*Terminate state*/
    if (n == 0) {
        if (k == 0) {
            return TRUE;
        } 
        else {
            return FALSE;
        }
    }

    if (start < end) {
        if (any_n_sum_to_k(n-1, k-(int)(arr[start]-'0'), arr, start+1, end)) {
            return TRUE;  /*either the first element is counted*/
        }
        else if (any_n_sum_to_k(n, k, arr, start+1, end)) {
            return TRUE;  /*or the first element is not*/
        }       
    }

    return FALSE; 
}


void arr_sub(char arr[], int arr_len, char item_before, char item_after)
{
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == item_before) {
            arr[i] = item_after;
        }
    } 
}


void arr_append(char arr[], int arr_len, char player)
{
    for (int i = 0; i < arr_len; i ++) {
        if (arr[i] != player) {
            arr[i] = player;
        }
    }
}


void posistion(char board[], int board_len, char index, char player)
{
    arr_sub(board, board_len, index, player);
    if (player == 'X') {
        X_MOVES[X_MOVES_LEN] = index;
        X_MOVES_LEN += 1;
    }
    else if (player == 'O') {
        O_MOVES[O_MOVES_LEN] = index;
        O_MOVES_LEN += 1;

    }

}

void print_arr(char arr[], int arr_len)
{   
    printf(" MOVES: ");
    for (int i = 0; i < arr_len; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main()
{   
    printf("Welcome to lonely tic-tac-toe game where you can only play X and O with yourself. \n");
    printf("Look at this magical board! And the game has started! The losser will bite the dust, so play carefully! \n┗|｀O′|┛\n");

    int game_over = game(MAGIC_BOARD);

    if (game_over == 1){
        printf("X wins! As a result, O player must pay his/her life!\n(｀∀´)Ψ\n");
    }
    else if (game_over == -1)
    {
        printf("O wins! As a result, X player must pay his/her life!\n(｀∀´)Ψ\n");
    }
    else if (game_over == 0) {
        printf("Damn it! Looks like you find the only way to be alive in this game!\n");
        printf(".   (⌒﹀⌒ ⌒﹀⌒)\n");
        printf("  / ( * )  ( * ) \\ \n");
        printf(" / (\\  ╱ ︻ ╲  /) \\ \n");
        printf(" ( / \\ \\ __ / / \\ ) \n");
        printf("  ╲   ╲＿︶＿╱ ノ╱  \n");
        printf("  |＿ ＿\\＿＿/ ＿| \n");
    }


    return EXIT_SUCCESS;
}
