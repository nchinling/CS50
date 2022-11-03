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

// allocate memory for node
//node *n = malloc(sizeof(node));
//strcpy (n -> word, "Hello");
//n -> next = NULL;

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
    return toupper(word[0]) - 'A';
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

    while (file != EOF)
    {

    }

    // node *n = malloc(sizeof(node));
    //  if (n == NULL)
    // {
    //     return 1;
    // }




// use a loop to scan each word//
    //fopen(file, "%s", word)
    //fscanf(file, "%s", word);
    return false;
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
