#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagen.h"

/*=====ESTRUTURA DO PRODUTO=====*/

typedef struct
{
   int codigo;
   char nome[50];
   float preco;
} Produto;


/*====CALLBACK PARA IMPRIMIR O PRODUTO=====*/

void imprime_produto(void* info)
{
    Produto* produto = (Produto*) info;
    printf("CODIGO: %d | NOME: %s | PRECO: R$ %.2f\n", produto->codigo, produto->nome, produto->preco);
}

/*=====BUSCAR CODIGO=====*/

int compara_codigo(void* info, void* dado)
{
    Produto* produto = (Produto*) info;
    int* codigo = (int*)dado;
    return produto ->codigo == *codigo;
}

/*=====CALLBACK PARA FILTRAR PORDUTOS RETORNA 1 SE O PREÇO FOR MENOR OU IGUAL A 20=====*/

int filtra_preco(void* info)
{
    Produto* produto = (Produto*) info;
    return produto ->preco <= 20.00;
}

/*=====CALLBACK PARA ORDENAR POR PRECO RETORNA 1 SE PRECISAR TROCAR=====*/

int compara_preco(void* preco1, void* preco2)
{
    Produto* produto1 = (Produto*) preco1;
    Produto* produto2 = (Produto*) preco2;

    return produto1 ->preco > produto2->preco;
}

int main()
{
    printf("=====SISTEMA DE PRODUTOS=====\n");

    Listagen* lista = listagen_cria();

    printf("1 - CRIANDO LISTA\n");

    if(listagen_vazia(lista))
    {
        printf("A lista foi criada porem esta vazia!\n");
    }
    else
    {
        printf("A lista nao esta vazia!\n");
    }

    /*=====CRIA PRODUTOS=====*/

    Produto* produto1 = malloc(sizeof(Produto));
    Produto* produto2 = malloc(sizeof(Produto));
    Produto* produto3 = malloc(sizeof(Produto));
    Produto* produto4 = malloc(sizeof(Produto));
    Produto* produto5 = malloc(sizeof(Produto));

    produto1-> codigo =101;
    strcpy(produto1-> nome, "Arroz");
    produto1 -> preco = 3.50;

    produto2-> codigo =102;
    strcpy(produto2-> nome, "Feijao");
    produto2 -> preco = 8.70;

    produto3-> codigo =103;
    strcpy(produto3-> nome, "Cafe");
    produto3 -> preco = 13.60;

    produto4-> codigo =104;
    strcpy(produto4-> nome, "Macarrao");
    produto4 -> preco = 5.80;

    produto5-> codigo =105;
    strcpy(produto5-> nome, "Acucar");
    produto5 -> preco = 2.70;

    /*=====INSERE PRODUTOS=====*/

    lista = listagen_insere(lista,produto1);
    lista = listagen_insere(lista,produto2);
    lista = listagen_insere(lista,produto3);
    lista = listagen_insere(lista,produto4);
    lista = listagen_insere(lista,produto5);

    printf("2 - PRODUTOS INSERIDOS\n");

    listagen_percorre(lista, imprime_produto);

    /*=====VERIFICA A LISTA SE ESTA VAZIA=====*/

    printf("3 - VERIFICANDO LISTA\n");

    if(listagen_vazia(lista))
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        printf("A lista nao esta vazia!\n");
    }

    /*=====BUSCA PRODUTO=====*/

    int codigo_procurado = 103;

    Produto* encontrado = (Produto*)listagen_busca(lista, compara_codigo, &codigo_procurado);

    if(encontrado!= NULL)
    {
        printf("Procduto encontrado!\n");
        imprime_produto(encontrado);
    }
    else
    {
        printf("Produto nao encontrado!");
    }

    /*===FILTRA PRODUTOS=====*/

    printf("5 - PRODUTOS COM PRECO ATE R$ 20,00\n");

    Listagen* lista_filtrada = listagen_filtra(lista, filtra_preco);

    listagen_percorre(lista_filtrada, imprime_produto);

    /*=====ORDENA PRODUTOS=====*/

    printf("6 - PRODUTOS ANTES DA ORDENACAO\n");

    listagen_percorre(lista, imprime_produto);

    printf("\n");

    lista = listagen_ordena(lista, compara_preco);

    printf("PRODUTOS DEPOIS DA ORDENACAO POR PRECO\n");

    listagen_percorre(lista, imprime_produto);

    printf("\n");

    /*=====RETIRAR PRODUTOS=====*/

    int codigo_retirar = 103;

    printf("7 - RETIRANDO PRODUTO\n");
    printf("Codigo a retirar: %d\n", codigo_retirar);

    lista = listagen_retira(lista, compara_codigo, &codigo_retirar);

    printf("\nLista depois da retirada:\n");

    listagen_percorre(lista, imprime_produto);

    printf("\n");

    /*=====LIBERAR LISTA FILTRADA=====*/

    Listagen* lista_auxiliar = lista_filtrada;

    while (lista_auxiliar != NULL)
    {
        Listagen* proximo = lista_auxiliar->prox;
        free(lista_auxiliar);
        lista_auxiliar = proximo;
    }

    /*=====LIBERAR LISTA ORIGINAL=====*/

    printf("8 - LIBERANDO MEMORIA\n");

    listagen_libera(lista);

    printf("Memoria liberada com sucesso.\n");
    printf("Fim do programa!\n");
    
return 0;
}