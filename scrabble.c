#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Compare the two player´s scores and output who´s the winner
    if (score1 == score2)
    {
        printf("\nTie!");
    }
    else if (score1 > score2)
    {
        printf("\nPlayer 1 Wins!");
    }
    else
    {
        printf("\nPlayer 2 Wins!");
    }
}

int compute_score(string word)
{
    //Getting the size of the word the player inputed
    int length = strlen(word), score = 0, letter;

    //Going through each letter of the word
    for (int i = 0; i < length; i++)
    {
        //Capitalizing each letter of the word
        letter = toupper(word[i]);

        //Compare the letter the user inputed to see it´s score
        for (int j = 65; j < 90; j++)
        {
            //If the letter is not on the alphabet it´s score is 0
            if (letter < 65 || letter > 90)
            {
                letter = 0;
                score += letter;
            }
            //Assigning the letter to the respective points on the POINTS[] array
            else if (letter == j)
            {
                letter = POINTS[j - 65];
                score += letter;
            }
        }
    }
    //returning the score
    return score;
}
