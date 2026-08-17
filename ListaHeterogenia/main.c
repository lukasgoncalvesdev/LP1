#include <stdio.h>
#include "listahet.h"

int main()
{
    ListaHet *lista = NULL;

    ListaHet *c;
    ListaHet *r;
    ListaHet *t;

    c = cria_circulo(5);
    r = cria_retangulo(10, 4);
    t = cria_triangulo(8, 6);

    insere(&lista, c);
    insere(&lista, r);
    insere(&lista, t);

    printf("===== LISTA HETEROGENEA =====\n\n");

    imprime(lista);

    printf("Maior area: %.2f\n", area_max(lista));

    libera(lista);

    return 0;
}

