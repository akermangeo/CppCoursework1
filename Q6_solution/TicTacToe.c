#include <stdbool.h>

#include "TicTacToe.h"
#include "userInput.h"

static char magic_board[BOARD_SIZE] = { '2', '9', '4', '7', '5', '3', '6', '1', '8' };

static char x_moves[X_MOVES_MAX];
static int x_moves_len = 0;
static char o_moves[O_MOVES_MAX];
static int o_moves_len = 0;

int game()
{
    pretty_print_board();

    while (x_moves_len < 5) {
        /* Get the X move */
        printf("X move: ");
        int x_move = read_int();
        bool legal_move = is_legal_move(x_move);
        while (!legal_move) {
            /* Warning */
            warning_message();
            printf("X move: ");
            x_move = read_int();
            legal_move = is_legal_move(x_move);
        }

        play_move(magic_board, BOARD_SIZE, (char)(x_move + '0'), 'X');
        pretty_print_board();

        /*Check wether X has win*/
        if (any_n_sum_to_k(3, 15, x_moves, 0, x_moves_len)) {
            //represents an X win
            return 1;
        }
        else if (x_moves_len == 5) {
            //represents a draw
            return 0;
        }

        /* Get the O move */
        printf("O move: ");
        int o_move = read_int();
        legal_move = is_legal_move(o_move);
        while (!legal_move) {
            /* Warning */
            warning_message();
            printf("O move: ");
            o_move = read_int();
            legal_move = is_legal_move(o_move);
        }

        play_move(magic_board, BOARD_SIZE, (char)(o_move + '0'), 'O');
        pretty_print_board();


        /*Check wether O has win*/
        if (any_n_sum_to_k(3, 15, o_moves, 0, o_moves_len)) {
            //represents O win
            return -1;
        }
    }

    //represents draw
    return 0;
}

void warning_message()
{
    printf("Please input one of the digit in the board!\n");
    printf("/     \\\n");
    printf("/\\   /\\ \n");
    printf("  '   \n");
    printf("  - \n");
}

bool is_legal_move(int move)
{
    // Converts a 1-digit integer to its character representation.
    char char_move = (char)(move + '0');

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (magic_board[i] == char_move) {
            return true;
        }
    }
    return false;
}


void pretty_print_board()
{
    for (int i = 0; i < BOARD_SIZE / 3; i++) {
        printf("\t %c %c %c \n", magic_board[3 * i], magic_board[3 * i + 1], magic_board[3 * i + 2]);
    }
}


bool any_n_sum_to_k(int n, int k, char arr[], int start, int end)
{
    /*Terminate state*/
    if (n == 0) {
        if (k == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    if (start < end) {
        if (any_n_sum_to_k(n - 1, k - (arr[start] - '0'), arr, start + 1, end)) {
            return true;  /*either the first element is counted*/
        }
        else if (any_n_sum_to_k(n, k, arr, start + 1, end)) {
            return true;  /*or the first element is not*/
        }
    }

    return false;
}


void arr_append(char arr[], int arr_len, char player)
{
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] != player) {
            arr[i] = player;
        }
    }
}


void play_move(char board[], int board_len, char index, char player)
{

    for (int i = 0; i < board_len; i++) {
        if (board[i] == index) {
            board[i] = player;
        }
    }
    if (player == 'X') {
        x_moves[x_moves_len] = index;
        x_moves_len += 1;
    }
    else if (player == 'O') {
        o_moves[o_moves_len] = index;
        o_moves_len += 1;
    }

}

