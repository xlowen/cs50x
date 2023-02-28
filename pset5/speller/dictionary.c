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
const unsigned int N = 1000000;

//counter for size function
unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int cmp = hash(word);
    node *cursor = table[cmp];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    int hashresult = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashresult += toupper(word[i]);
    }

    return hashresult;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return false;
    }
    char tmp[LENGTH + 1];
    while (fscanf(dic, "%s", tmp) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }
        strcpy(n->word, tmp);
        int index = hash(n->word);
        n->next = table[index];
        table[index] = n;
        count++;
    }
    fclose(dic);
    return true;


}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int i = 0;
    for (i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *freetmp = table[i]->next;
            free(table[i]);
            table[i] = freetmp;
        }
    }
    return true;
}
