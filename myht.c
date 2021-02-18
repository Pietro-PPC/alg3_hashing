#include <stdio.h>
#include "hash.h"

int main()
{
    cHash_t myHash;

    initialize_hash(&myHash);

    char op;
    long int key;

    while(scanf("%c %ld\n", &op, &key) != EOF)
    {
        if (op == 'i')
            insert_key(&myHash, key);
        else if (op == 'r')
            delete_key(&myHash, key);
    }

    print_output(&myHash);

    return 0;
}