#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"



int main()
{
    printf("Welcome to lonely tic-tac-toe game where you can only play X and O with yourself. \n");
    printf("Look at this magical board! And the game has started! The losser will bite the dust, so play carefully! \n | ` O ′|\n");

    int game_over = game();

    if (game_over == 1) {
        printf("X wins! As a result, O player must pay his/her life!\n( `Q′)-->\n");
    }
    else if (game_over == -1)
    {
        printf("O wins! As a result, X player must pay his/her life!\n( `Q′)-->\n");
    }
    else if (game_over == 0) {
        printf("Damn it! Looks like you find the only way to be alive in this game!\n");
        printf(".    \\--     --/ \n");
        printf("    ( * )   ( * ) \\ \n");
        printf("   ( \\ / ... \\ / )  \n");
        printf("     \\ \\ ___ / /  \n");
        printf("   _   _ \\__/ _  \n");
    }


    return EXIT_SUCCESS;
}
