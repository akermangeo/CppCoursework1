#include "TicTacToe.h"

static char magic_board[BOARD_NUM] = { '2', '9', '4', '7', '5', '3', '6', '1', '8' };

static char X_moves[X_MOVES_MAX];
static int X_moves_len = 0;
static char O_moves[O_MOVES_MAX];
static int O_moves_len = 0;
static char blank_positions[BOARD_NUM];

int game()
{
    int X_move;
    int O_move;

    int game_over = 0;

    char line[1024];

    pretty_print();

    while (X_moves_len < 5) {
        /* Get the X move */
        printf("X move: ");
        fgets(line, 1023, stdin);   // leave 1 character for null terminator
        sscanf_s(line, "%d", &X_move);
        while (is_legal_move((char)(X_move + '0')) != TRUE) {
            /* Warning */
            warning_message();

            fgets(line, 1023, stdin);   // leave 1 character for null terminator
            sscanf_s(line, "%d", &X_move);
        }

        posistion(magic_board, BOARD_NUM, (char)(X_move + '0'), 'X');
        pretty_print();

        /*Check wether X has win*/
        if (any_n_sum_to_k(3, 15, X_moves, 0, X_moves_len)) {
            game_over = 1;
            return game_over;
        }
        else if (X_moves_len == 5 && O_moves_len == 4) {
            return game_over;
        }

        /* Get the O move */
        printf("O move: ");
        fgets(line, 1023, stdin);   // leave 1 character for null terminator
        sscanf_s(line, "%d", &O_move);
        while (is_legal_move((char)(O_move + '0')) != TRUE) {
            /* Warning */
            warning_message();

            fgets(line, 1023, stdin);   // leave 1 character for null terminator
            sscanf_s(line, "%d", &O_move);
        }

        posistion(magic_board, BOARD_NUM, (char)(O_move + '0'), 'O');
        pretty_print();


        /*Check wether O has win*/
        if (any_n_sum_to_k(3, 15, O_moves, 0, O_moves_len)) {
            game_over = -1;
            return game_over;
        }
        else if (X_moves_len == 5 && O_moves_len == 4) {
            return game_over;
        }
    }

    return game_over;
}

void warning_message()
{
    printf("Please input one of the digit in the board!\n");
    printf("/     \\\n");
    printf("/\\   /\\ \n");
    printf("  '   \n");
    printf("  - \n");

    printf("X move: ");
}

int is_legal_move(char move)
{
    for (int i = 0; i < BOARD_NUM; i++) {
        if (magic_board[i] == move) {
            return TRUE;
        }
    }
    return FALSE;
}


void pretty_print()
{
    for (int i = 0; i < (int)BOARD_NUM / 3; i++) {
        printf("\t %c %c %c \n", magic_board[3 * i], magic_board[3 * i + 1], magic_board[3 * i + 2]);
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
        if (any_n_sum_to_k(n - 1, k - (int)(arr[start] - '0'), arr, start + 1, end)) {
            return TRUE;  /*either the first element is counted*/
        }
        else if (any_n_sum_to_k(n, k, arr, start + 1, end)) {
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
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] != player) {
            arr[i] = player;
        }
    }
}


void posistion(char board[], int board_len, char index, char player)
{
    arr_sub(board, board_len, index, player);
    if (player == 'X') {
        X_moves[X_moves_len] = index;
        X_moves_len += 1;
    }
    else if (player == 'O') {
        O_moves[O_moves_len] = index;
        O_moves_len += 1;

    }

}

