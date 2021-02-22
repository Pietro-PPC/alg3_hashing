#ifndef __HASH__
#define __HASH__

#define SIZE 11

// Definição da struct de cuckoo hash, com duas tabelas de tamanho SIZE.
// Valores nulos ou positivos representam chaves armazenadas na estrutura;
// -1 representa espaço ainda não preenchido na estrutura.
// -2 representa espaço que teve chave excluída.
typedef struct cHash_s {
    long int t1[SIZE];
    long int t2[SIZE];
} cHash_t;

// Definição da struct de output
typedef struct output_s {
    long int v[2*SIZE][3];
    int s;
} output_t;

void initialize_hash(cHash_t *t);

int h1(long int k);

int h2(long int k);

void insert_key(cHash_t *t, long int key);

long int *search_key(cHash_t *t, long int key);

void delete_key(cHash_t *t, long int key);

void print_output(cHash_t *t);

#endif