#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define BOARD_NUM 9
#define X_MOVES_MAX 5
#define O_MOVES_MAX 4

int game();
void posistion(char board[], int board_len, char index, char player);
void pretty_print();
void arr_sub(char arr[], int arr_len, char item_before, char item_after);
void arr_append(char arr[], int arr_len, char player);
int any_n_sum_to_k(int n, int k, char arr[], int start, int end);
void print_arr(char arr[], int arr_len);
int is_legal_move(char move);
