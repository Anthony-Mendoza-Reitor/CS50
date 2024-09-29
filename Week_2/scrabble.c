#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array with the points of each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype of a function
int compute_score(string word);

int main(void)
{
    // This part of the code gathers both players words
    string playerWord1 = get_string("Player 1: ");
    string playerWord2 = get_string("Player 2: ");

    // The Score is calculated for both players
    int playerScore1 = compute_score(playerWord1);
    int playerScore2 = compute_score(playerWord2);

    // Logic to select the winner
    if (playerScore1 > playerScore2)
    {
        printf("Player 1 wins!");
    }
    else if (playerScore2 > playerScore1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

// This function calculates the points
int compute_score(string word)
{
    int scoreSum = 0;
    for (int i = 0; i < (strlen(word)); i++)
    {
        char L = toupper(word[i]);
        if (L > 64 && L < 91)
        {
            scoreSum += POINTS[L - 65];
        }
    }
    return scoreSum;
}
