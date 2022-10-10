#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//             {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y, z}

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%d\n", score1);
    printf("%d\n", score2);

    // TODO: Print the winner using if-elseif-else conditonal loop
    if  (score1 > score2)
    {

        printf("Player 1 wins!\n");

    }

    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    else
    {

        printf("Tie!\n");

    }

}


int compute_score(string word)
{

    // TODO: Compute and return score for string
    int sum = 0;


    for (int i=0; i < strlen(word); i++ )
    //for (int i = 0, n = strlen(word); i<n; i++)

    {

        if (islower(word[i]))
        {
            toupper(word[i]);
        }
        else
        {
            word[i];

        //sum += POINTS[i];
        //word=POINTS[];
        sum += POINTS[word[i]-'A'];

    }

    return sum;
}

