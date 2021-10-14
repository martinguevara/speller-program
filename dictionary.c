// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int wordcount = 0;
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);

    node* nodeptr = table[key];

    while(nodeptr != NULL)
    {
        if (strcasecmp(nodeptr->word, word) == 0)
        {
            return true;
        }
        nodeptr = nodeptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;

    for(int i = 0; word[i]!='\0';i++)
    {
        value += tolower(word[i]);

    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file==NULL)
    {
        return false;
    }

    for(int i = 0;i<N;i++)
    {
        table[i]=NULL;
    }

    char tmpword[LENGTH+1];

    while(fscanf(file, "%s\n", tmpword) != EOF)
    {
        node *tmpnode = malloc(sizeof(node));

        strcpy(tmpnode->word, tmpword);

        int key = hash(tmpword);

        if(table[key]==NULL)
        {
            tmpnode->next = NULL;
            table[key] = tmpnode;
        }
        else
        {
            tmpnode->next = table[key];
            table[key] = tmpnode;
        }

        wordcount++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0;i<N;i++)
    {
        node *nodeptr = table[i];

        while(nodeptr != NULL)
        {
            node *deleted = nodeptr;
            nodeptr = nodeptr->next;
            free(deleted);
        }

        table[i] = NULL;
    }
    return true;
}
