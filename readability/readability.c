#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//create function prototypes. Ends with semi-colon.
int count_letters(string text);
// int count_words(string text);
// int count_sentences(string text);

int main(void)
{
    int index;

    string user_text = get_string("Enter text: ");

    int L = count_letters(user_text);
    // int W = count_words(user_text);
    // int S = count_sentences(user_text);


index = round(0.0588 * 1 - 0.296 * 1 - 15.8);
printf("Grade:%d\n",index);
}

int count_letters(string text)
{
    int letters = 0;
        if (word[i] - 'A' >= 0 && word[i] - 'A' < 26)

        {

            sum += POINTS[word[i] - 'A'];

        }

        else

        {

            sum = sum + 0;

        }


    return letters;
}

int count_words(string text)
{
    int words = 0;

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;



    return sentences;
}
