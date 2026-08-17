#ifndef LISTAGEN_H
#define LISTAGEN_H

struct listagen
{
    void *info;
    struct listagen* prox;
};
typedef struct listagen Listagen;

Listagen* listagen_cria ();

int listagen_vazia(Listagen* cabeca_lista);

Listagen* listagen_insere(Listagen* cabeca_lista, void* elemento);

void listagen_percorre(Listagen* cabeca_lista, void (*callback)(void*));

void* listagen_busca(Listagen* cabeca_lista, int (*callback)(void*, void*), void* dado);

Listagen* listagen_retira(Listagen* cabeca_lista, int (*callback)(void*, void*), void* dado);

Listagen* listagen_duplica(Listagen* cabeca_lista, void* (*callback)(void*)); 

void listagen_libera(Listagen* cabeca_lista);

Listagen* listagen_filtra(Listagen* cabeca_lista, int(*callback)(void*));

Listagen* listagen_ordena(Listagen* cabeca_lista, int(*callback)(void*, void*));

#endif
