#include "hash.h"
#include <stdio.h>
#include <math.h>

void initialize_hash(cHash_t *t)
{
    for (int i = 0; i < SIZE; ++i)
    {
        t->t1[i] = -1;
        t->t2[i] = -1;
    }
}

int h1(long int k)
{
    return k % SIZE;
}

int h2(long int k)
{
    return floor(SIZE * (k*0.9 - floor(k*0.9)));
}

void insert_key(cHash_t *t, long int key)
{
    long int *t1_pos = t->t1 + h1(key);

    if (*t1_pos == -1 || *t1_pos == -2)
        *t1_pos = key;
    else
    {
        long int *t2_pos = t->t2 + h2(*t1_pos);
        *t2_pos = *t1_pos;
        *t1_pos = key;
    }
}

long int *search_key(cHash_t *t, long int key)
{
    long int *t1_pos = t->t1 + h1(key);
    long int *t2_pos = t->t2 + h2(key);

    if (*t1_pos == -1)
        return NULL;
    else if (*t1_pos == key)
        return t1_pos;
    else if (*t2_pos == key)
        return t2_pos;
    else
        return NULL;
}

void delete_key(cHash_t *t, long int key)
{
    long int *t1_pos = t->t1 + h1(key);
    long int *t2_pos = t->t2 + h2(key);

    if (*t2_pos == key)
        *t2_pos = -2;
    else if (*t1_pos == key)
        *t1_pos = -2;
}

void print_hash(cHash_t *t)
{
    for (int i = 0; i < SIZE; ++i)
        printf("%2d %4ld %4ld\n", i, t->t1[i], t->t2[i]);
}

void print_output(cHash_t *t)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (t->t1[i] >= 0)
            printf("%ld,T1,%d\n", t->t1[i], i);
        if (t->t2[i] >= 0)
            printf("%ld,T2,%d\n", t->t2[i], i);
    }
}