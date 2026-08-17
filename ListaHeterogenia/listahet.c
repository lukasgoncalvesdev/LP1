#include <stdlib.h>
#include <stdio.h>
#include "listahet.h"

ListaHet* cria_retangulo (float base, float altura)
{
    retangulo* r;
    ListaHet* p;
    r = (retangulo*)malloc(sizeof(retangulo));
    r -> base = base;
    r -> altura = altura;
    p = (ListaHet*)malloc(sizeof(ListaHet));
    p -> tipo = RETANGULO;
    p -> dado = r;
    p -> prox = NULL;
    return p;
}

ListaHet* cria_triangulo (float base, float altura)
{
    triangulo* t;
    ListaHet* p;
    t = (triangulo*)malloc(sizeof(triangulo));
    t -> base = base;
    t -> altura = altura;
    p = (ListaHet*)malloc(sizeof(ListaHet));
    p -> tipo = TRIANGULO;
    p -> dado = t;
    p -> prox = NULL;
    return p;
}

ListaHet* cria_circulo (float raio)
{
    circulo* c;
    ListaHet* p;
    c = (circulo*)malloc(sizeof(circulo));
    c -> raio = raio;
    p = (ListaHet*)malloc(sizeof(ListaHet));
    p -> tipo = CIRCULO;
    p -> dado = c;
    p -> prox = NULL;
    return p;
}

void insere (ListaHet **lista, ListaHet *novo)
{
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        ListaHet *p;

        p = *lista;

        while (p -> prox != NULL)
        {
            p = p-> prox;

        }
        
        p-> prox = novo;

    }

}


float ret_area (retangulo* r)
{
    return r-> base * r->altura;
}

float tri_area (triangulo* t)
{
    return (t-> base * t->altura) / 2;
}

float cir_area (circulo* c)
{
    return PI * c->raio * c->raio;
}


float area (ListaHet* p)
{
    switch (p->tipo)
    {
    case RETANGULO:
        {
            return ret_area((retangulo*) p->dado);
        }
        break;
    case TRIANGULO:
        {
            return tri_area((triangulo*)p->dado);
        }
        break;
    case CIRCULO:
        {
            return cir_area((circulo*)p->dado);
        }
        break;
    }
    return 0;
}

float area_max(ListaHet *lista)
{
    float amax = 0.0;
    ListaHet *p;

    for (p = lista; p != NULL; p = p->prox)
    {
        float a = area(p);

        if (a > amax)
            amax = a;
    }

    return amax;

}

void imprime(ListaHet *lista)
{
    ListaHet *p;

    for (p = lista; p != NULL; p = p->prox)
    {
        switch (p->tipo)
        {
            case CIRCULO:
            {
                circulo *c = (circulo*)p->dado;

                printf("CIRCULO\n");
                printf("Raio: %.2f\n", c->raio);
                printf("Area: %.2f\n\n", area(p));

                break;
            }

            case RETANGULO:
            {
                retangulo *r = (retangulo*)p->dado;

                printf("RETANGULO\n");
                printf("Base: %.2f\n", r->base);
                printf("Altura: %.2f\n", r->altura);
                printf("Area: %.2f\n\n", area(p));

                break;
            }

            case TRIANGULO:
            {
                triangulo *t = (triangulo*)p->dado;

                printf("TRIANGULO\n");
                printf("Base: %.2f\n", t->base);
                printf("Altura: %.2f\n", t->altura);
                printf("Area: %.2f\n\n", area(p));

                break;
            }
        }
    }
}

void libera(ListaHet *lista)
{
    ListaHet *p;

    while (lista != NULL)
    {
        p = lista;
        lista = lista->prox;

        free(p->dado);
        free(p);
    }
}