#ifndef __HASH__
#define __HASH__

#define SIZE 11

typedef struct cHash_s {
    long int t1[SIZE];
    long int t2[SIZE];
} cHash_t;

void initialize_hash(cHash_t *t);

int h1(long int k);

int h2(long int k);

void insert_key(cHash_t *t, long int key);

long int *search_key(cHash_t *t, long int key);

void delete_key(cHash_t *t, long int key);

void print_output(cHash_t *t);

void print_hash(cHash_t *t);

#endif