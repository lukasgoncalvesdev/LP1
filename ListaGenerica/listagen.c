#include "listagen.h"
#include <stdlib.h>
#include <stdio.h>

/* cria lista vazia e retorna null*/

Listagen* listagen_cria()
{
    return NULL;
}

/* verifica se a lista está vazia*/

int listagen_vazia(Listagen* cabeca_lista)
{
    return cabeca_lista == NULL;
}

/*insere um elemento na lista e depois retorna a cabeça da lista atualizada*/

Listagen* listagen_insere(Listagen* cabeca_lista, void* elemento)
{
    Listagen* novo = (Listagen*)malloc(sizeof(Listagen));

    if (!novo)
    {
        printf("Acabou a memoria para guardar o proximo elemento!\n");
        return cabeca_lista;
    }
    
    novo -> info = elemento;
    novo ->prox = cabeca_lista;

    return novo;
}

/*percorre todos os elemntos da lista*/

void listagen_percorre(Listagen* cabeca_lista, void (*callback)(void*))
{
    while (cabeca_lista!= NULL)
    {
        callback(cabeca_lista->info);
        cabeca_lista = cabeca_lista->prox;
    }
}

/*retorna o ponteiro para info, se nao achar retorna nulo*/

void* listagen_busca(Listagen* cabeca_lista, int(*callback)(void*,void*), void* dado)
{
    Listagen* ponteiro = cabeca_lista;

    while (ponteiro != NULL)
    {
        if (callback(ponteiro->info, dado))
        {
            return ponteiro->info;
        }
        ponteiro = ponteiro->prox;
    }

    return NULL;
}

/*Retira o primeiro elemento da lista encontrado que retorna 1 ao comparar dado com info do elemento presente na lista.*/

Listagen* listagen_retira(Listagen* cabeca_lista,int(*callback)(void*, void*),void* dado)
{
    Listagen* ponteiro = cabeca_lista;
    Listagen* anterior = NULL;

    while (ponteiro != NULL)
    {
        if (callback(ponteiro->info, dado))
        {
            if (anterior == NULL)
            {
                cabeca_lista = ponteiro->prox;
            }
            else
            {
                anterior->prox = ponteiro->prox;
            }

            free(ponteiro);
            return cabeca_lista;
        }

        anterior = ponteiro;
        ponteiro = ponteiro->prox;
    }

    return cabeca_lista;
}

/* libera a memória ocupada pela lista genérica.*/

void listagen_libera(Listagen* cabeca_lista)
{
    Listagen* ponteiro = cabeca_lista;

    while (ponteiro != NULL)
    {
        free(ponteiro->info);
        Listagen* ponteiro_temp = ponteiro->prox;
        free(ponteiro);
        ponteiro = ponteiro_temp;
    }
}

/*  Retorna uma lista contendo apenas os elementos filtrados pelo critério. Esta função não copia as informações ela
retorna o ponteiro para uma lista contendo a referência aos elementos da lista original.*/

Listagen* listagen_filtra(Listagen* cabeca_lista, int (*callback)(void*))
{
    Listagen* nova_lista = listagen_cria();
    Listagen* ponteiro = cabeca_lista;

        while (ponteiro!= NULL)
        {
            if (callback(ponteiro->info))
            {
                nova_lista = listagen_insere(nova_lista, ponteiro->info);
            }
            ponteiro = ponteiro -> prox;
        }
        return nova_lista;
}

/**  Ordena a lista genérica de acordo com a função compara. 
Caso compara retorne 1, a troca de posição entre os elementos será realizada, do contrário, não. esta função usa o algoritmo selection sort.*/

Listagen* listagen_ordena(Listagen* cabeca_lista, int (*callback)(void*, void*))
{
    Listagen* ponteiro = cabeca_lista;

    while (ponteiro != NULL)
    {
        Listagen* menor = ponteiro;
        Listagen* atual = ponteiro->prox;

        while (atual != NULL)
        {
            if (callback(menor->info, atual->info))
            {
                menor = atual;
            }

            atual = atual->prox;
        }

        if (menor != ponteiro)
        {
            void* aux = ponteiro->info;
            ponteiro->info = menor->info;
            menor->info = aux;
        }

        ponteiro = ponteiro->prox;
    }

    return cabeca_lista;
}
