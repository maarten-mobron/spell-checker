// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// initialize file size
int SIZE = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word
    int index = hash(word);

    // Checks if word is in dictionary
    node *ptr = table[index];

    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5380;
    int c;

    while ((c = *word++))
    {
        hash += hash * 32 + tolower(c);
    }

    // returns index between 0 and N-1
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // buffer to save read data to
    char buffer[LENGTH + 1];

    // read one string at the time
    while (fscanf(input, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not create node.\n");
            return false;
        }
        strcpy(n->word, buffer);
        n->next = NULL;

        // Hash word
        int index = hash(buffer);

        // Prepend node to list
        n->next = table[index];
        table[index] = n;

        // Keep track of file size
        SIZE++;
    }

    // closes file
    fclose(input);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (SIZE == 0)
    {
        return 0;
    }
    return SIZE;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        node *next;
        while (ptr != NULL)
        {
            next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
