// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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
// int count;
// int hash_value;

unsigned int count = 0;
unsigned int hash_value = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hash_value = hash(word);

    //create cursor node to traverse linked-list
    node *cursor = table[hash_value];

    //Traverse the linked-list
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        //move to next node if doesn't match
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';

    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        //total = total + (toupper(word[i]) - 'A') ;
        total = total + tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("There is an error. Unable to load dictionary\n");
        return false;
    }

    //create array to store words
    char word[LENGTH + 1];

    //scan file for string of words
    while (fscanf(file, "%s", word) != EOF)
    {
        //create memory for each new node
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
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
    if (count != 0)
    {
        return count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *temp_cursor = table[i];

        while (cursor)
        {
            //create temporary cursor to hold cursor location
            //node *temp_cursor = cursor;
            temp_cursor = cursor;
            //move cursor to next node
            cursor = cursor->next;
            free(temp_cursor);
        }
    }

    return true;
}
