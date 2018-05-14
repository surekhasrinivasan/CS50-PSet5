// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// size of hashtable
#define SIZE 26

// struct for node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//create an array of hashtable
node *hashtable[SIZE];

//get the no. of words in dictionary
int wordCount = 0;


//hash function
int hash(const char *word)
{
    int num = 0;
    char firstLetter = tolower(word[0]);
    num = firstLetter - 'a';
    return num;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int bucket = hash(word);

    if (hashtable[bucket] == NULL)
    {
        return false;
    }
    node *cursor = hashtable[bucket];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        // malloc a node for each new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node -> word, word);
        }

        //increment the word count
        wordCount++;

        //call the hash function
        int bucketNumber = hash(word);

        //insert the word in the linked list
        new_node -> next = hashtable[bucketNumber];
        hashtable[bucketNumber] = new_node;
    }
    //close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // iterate through entire hashtable array
    for (int index = 0; index < SIZE; index++)
    {
        node *cursor = hashtable[index];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    // return true if successful
    return true;
}