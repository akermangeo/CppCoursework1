#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define BOARD_NUM 9
#define X_MOVES_MAX 5
#define O_MOVES_MAX 4

/// <summary>
/// play the game of Tic-Tac-Toe. 
/// </summary>
/// <returns> (int) The result of the game. return 1 if X win, 0 if draw, and -1 if O win.</returns>
int game();

/// <summary>
/// Given the player (X/O) and the selected index of the board, position (substitute) the move of the player on the board.
/// </summary>
/// /// <param name="board">The board array. By default I am using magic_board. </param>
/// /// <param name="board_len">The len of the board array.</param>
/// /// <param name="index">The index on the board ('1' - '9').</param>
/// /// <param name="player">The player (X/O).</param>
void posistion(char board[], int board_len, char index, char player);

/// <summary>
/// Print the board in a 3x3 matrix. 
/// </summary>
void pretty_print();

/// <summary>
/// Substitute `item_before` in an array to `item_after`. 
/// This function is mainly used for void position(char board[], int board_len, char index, char player). 
/// </summary>
void arr_sub(char arr[], int arr_len, char item_before, char item_after);

/// <summary>
/// Append char to an array. 
/// This function is mainly used for void position(char board[], int board_len, char index, char player). 
/// This game is functioning by recording the moves of X and O. Hence it is appending `player` to char[] `player`_moves.
/// </summary>
/// /// <param name="player">The player (X/O).</param>
void arr_append(char arr[], int arr_len, char player);

/// <summary>
/// Recursively check whether there exists a sub-set of the arrary (char -> int) of elements n that sums to k. 
/// This function is mainly used for checking whether X or O wins. 
/// For example, if any_n_sum_to_k(3, 15, X_moves, 0, len(X_moves)) == 1, then X wins.
/// </summary>
int any_n_sum_to_k(int n, int k, char arr[], int start, int end);


/// <summary>
/// Check whether a move is legal or not. 
/// </summary>
/// <param name="move">the move.</param>
/// <returns></returns>
int is_legal_move(char move);

/// <summary>
/// Print the warning message if a ilegal movement is made.
/// </summary>
void warning_message();
