#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//create function prototypes. Ends with semi-colon.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string user_text = get_string("Enter text: ");

    float uL = count_letters(user_text);
    printf("Letters:%f\n",uL);

    float uW = count_words(user_text);
    printf("Words:%f\n",uW);

    float uS = count_sentences(user_text);
    printf("Sentences:%f\n",uS);

    float L = (uL/uW)*100;
     printf("L:%f\n",L);
    float S = (uS/uW)*100;
     printf("S:%f\n", S);

    int index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Index:%d\n",index);

    if (index >= 16)
    {

        printf("Grade 16+\n");

    }

    else if (index < 1)
    {

         printf("Before Grade 1\n");

    }

    else
    {

         printf("Grade %d\n",index);

    }


}

//Function to count number of letter
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


//Function to count number of sentences. Number of sentences is always equal to number of punctuations.
int count_sentences(string text)
{
    int sentences;
    int punctuations = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == 33 || text[i] == 46 || text[i] == 63)

        {

            punctuations++;

        }

        else

        {

            punctuations = punctuations + 0;

        }

    }

    sentences = punctuations;
    return sentences;
}


//Function to count number of words. Number of words is always 1 more than number of spaces.
int count_words(string text)
{
    int words;
    int spaces = 0;


    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == 32)

        {

            spaces++;

        }

        else

        {

            spaces = spaces + 0;

        }

    }

    words = spaces + 1;
    return words;

}
