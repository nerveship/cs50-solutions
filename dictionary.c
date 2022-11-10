// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
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

//size of dictionary
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //gets hash value for word
    int hash_value = hash(word);
    //access linked list at index for hash value
    node *n = table[hash_value];

    //search list looking for word with strcasecmp and return true if it is there
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open dictionary file
    FILE * dict = fopen(dictionary, "r");

    //check if NULL
    if (dict == NULL)
    {
        printf("Dictionary does not exist\n");
        return false;
    }
    //initialise word array
    char next_word[LENGTH + 1];

    //read strings from file one word at a time until no words remain
    while (fscanf(dict, "%s", next_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //copy word from dictionary into node
        strcpy(n->word, next_word);
        //find hash value of the word
        int hash_value = hash(next_word);
        //insert word into hash table location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //iterate over table
    for (int i = 0; i < N; i++)
    {
        //point to first node in table
        node *n = table[i];
        while (n != NULL)
        {
            //create temp variable to point to n
            node *tmp = n;
            //set n to the next position
            n = n->next;
            //free tmp
            free(tmp);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
