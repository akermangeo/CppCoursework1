#include <stdio.h>
#include "ttt.h"


int main() {
    char BOARD[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    printf("Noughts and Crosses Game. Start! \n");
    game(BOARD);
    scanf("The End.");
}

