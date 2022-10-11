#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//create function prototypes. Ends with semi-colon.
int count_letters(string text);
int count_words(string text);
// int count_sentences(string text);

int main(void)
{
    int index;

    string user_text = get_string("Enter text: ");

    int L = count_letters(user_text);
    printf("Letters:%d\n",L);
    int W = count_words(user_text);
    printf("Words:%d\n",W);
    // int S = count_sentences(user_text);


index = round(0.0588 * 1 - 0.296 * 1 - 15.8);
printf("Grade:%d\n",index);
}

//Function to count number of words
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) )

        {

            letters++;

        }

        else

        {

            letters = letters + 0;

        }

    }

    return letters;
}


//Function to count number of words. Number of words is always 1 more than punctuations. 
int count_words(string text)
{
    int words
    int punctuations = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) )

        {

            letters++;

        }

        else

        {

            letters = letters + 0;

        }

    }

    words = punctuations + 1;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;



    return sentences;
}
