#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


//declare functions used at beginning
int only_digits(string numcheck);
int rotate(char letter, int key);

//main function
int main(int argc, string argv[])
{
    char code[1000];    //create a char array

    // Make sure program was run with just one command-line argument by using argc == 2
    if (argc == 2 && only_digits(argv[1]) == 0)
    {

        // Convert argv[1] from a `string` to an `int`
        int num = atoi(argv[1]);

        //Get plaintext
        string plaintext = get_string("plaintext:");

        //Apply rotate function to encipher
        for (int i = 0; i < strlen(plaintext) + 1; i++)
        {

            char letter = plaintext[i];

            code[i] = rotate(letter, num);

        }

        printf("ciphertext:%s\n", code);
        return 0;
    }

    else
    {

        printf("Usage: %s key\n", argv[0]);
        return 1;

    }

}


// Make sure every character in argv[1] is a digit
int only_digits(string numcheck)
{
    string digit = numcheck;
    int val;

    for (int i = 0; i < strlen(digit); i++)
    {
        if (digit[i] - 48 >= 0 && digit[i] - 48 <= 9)
        {
            val = 0;

        }
        else
        {
            val = 1;
        }

    }

    return val;
}

//Encryption function. For each character in the plaintext, rotate if it's a letter.
int rotate(char letter, int key)
{
    char encipher;
    char symbol;

//use when it is letter and in lowercase
    if (isalpha(letter) && islower(letter))
    {
        encipher = ((letter - 97 + key) % 26) + 97;

        return encipher;
    }

//use when it is letter and in uppercase
    else if (isalpha(letter) && isupper(letter))
    {
        encipher = ((letter - 65 + key) % 26) + 65;

        return encipher;
    }

//return the symbol. 
    else
    {
        symbol = letter;

        return symbol;
    }
}