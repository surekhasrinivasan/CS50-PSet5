// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// size of hashtable
#define SIZE 26

// struct for node
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

//create an array of hashtable
node* hashtable[SIZE];

//hash function
int hash(const char* word)
{
    int num=0;

    char firstLetter = tolower(word[0]);
    num = firstLetter - 'a'
    return num;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // if(word[] == NULL){
    //     return false;
    // }

    int bucket = hash(word);
    node *cursor = hashtable[bucket];
    while (cursor != NULL)
    {
	    //string comparison
	    //if the word from text file matches with the dictionary
	    //return true
	    //continuing checking the next word

	    if (strcasecmp (word, cursor->word)

	    cursor = cursor->next;
	    return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    while (fscan(file, "%s", word) != EOF)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node -> word, word);
        }

    //call the hash function
    int bucketNumber = hash(word);

    head = hashtable[bucketNumber];
    //insert the word in the linked list
    new_node -> next = head;
    head = new_node;

    //close the file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
