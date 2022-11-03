// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table. This is to create the linked-list.
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//declare variables created
int count;
int hash_value;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';

    int total = 0;
    for(int i = 0; i < strlen(word); i++)
    (
        total = total + toupper(word[i] - 'A');
    )
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

        if (file == NULL)
        {
            printf("There is an error. Unabe to load dictionary\n");
            return 1;
        }

    //create array to store words
    char word[LENGTH + 1];

    //scan file for string of words
    while(fscanf(file, "%s", word) != EOF)
    {
        //create memory for each new node
        node *n = malloc(sizeof(node));

            if (n == NULL)
            {
                return 1;
            }

        //copy word from dictionary into node
        strcpy(n->word, word);

        //obtain hash value
        hash_value = hash(word);

        //place node into linked-list. New word points onto location of first word in list
        //1. New word (next data) points onto location of first word in list
        //2. Header will now point to new word
        n->next = table[hash_value];
        table[hash_value] = n;

        //increase counter to keep track of words
        count = count + 1;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
