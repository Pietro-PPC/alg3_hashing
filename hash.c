#include "hash.h"
#include <stdio.h>
#include <math.h>

void initialize_hash(cHash_t *t)
// Inicializa struct de cuckoo hash com valores -1 (vazio nunca preenchido).
{
    for (int i = 0; i < SIZE; ++i)
    {
        t->t1[i] = -1;
        t->t2[i] = -1;
    }
}

int h1(long int k)
// Aplica função hash da primeira tabela em k.
{
    return k % SIZE;
}

int h2(long int k)
// Aplica função hash da segunda tabela em k.
{
    return floor(SIZE * (k*0.9 - floor(k*0.9)));
}

void insert_key(cHash_t *t, long int key)
// Insere chave 'key' na struct de cuckoo hash.
{
    // Cálculo do endereço da chave caso ela seja inserida em T1.
    long int *t1_pos = t->t1 + h1(key); 

    if (*t1_pos == -1 || *t1_pos == -2)
        *t1_pos = key;
    else
    {
        // Cálculo do endereço da chave caso ela seja inserida em T2.
        long int *t2_pos = t->t2 + h2(*t1_pos);

        *t2_pos = *t1_pos;
        *t1_pos = key;
    }
}

long int *search_key(cHash_t *t, long int key)
// Procura chave 'key' e retorna endereço dela, caso exista no hash.
// Caso contrário, retorna NULL
{
    // Cálculo do endereço da chave caso ela esteja em T1.
    long int *t1_pos = t->t1 + h1(key);
    // Cálculo do endereço da chave caso ela esteja em T2.
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
// Exclui chave 'key' da estrutura hash, caso ela exista.
{
    // Cálculo do endereço da chave caso ela esteja em T1.
    long int *t1_pos = t->t1 + h1(key);
    // Cálculo do endereço da chave caso ela esteja em T2.
    long int *t2_pos = t->t2 + h2(key);

    if (*t2_pos == key)
        *t2_pos = -2;
    else if (*t1_pos == key)
        *t1_pos = -2;
}


void print_output(cHash_t *t)
// Imprime hash ordenado primariamente por chave, secundariamente pelo número da tabela
// e terciariamente pela posição na tabela. 
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (t->t1[i] >= 0)
            printf("%ld,T1,%d\n", t->t1[i], i);
        if (t->t2[i] >= 0)
            printf("%ld,T2,%d\n", t->t2[i], i);
    }
}