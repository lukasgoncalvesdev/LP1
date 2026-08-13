#ifndef LISTAHET_H
#define LISTAHET_H

#define TRIANGULO 1
#define RETANGULO 2
#define CIRCULO 3
#define PI 3.14

typedef struct 
{
    float raio;
}circulo;

typedef struct 
{
    float base;
    float altura;
}retangulo;

typedef struct 
{
    float base;
    float altura;
}triangulo;

struct listahet
{
    void *dado;
    int tipo;
    struct listahet *prox;
};
typedef struct listahet ListaHet;

ListaHet* cria_retangulo (float base, float altura);
ListaHet* cria_triangulo (float base, float altura);
ListaHet* cria_circulo (float raio);

void insere (ListaHet **lista, ListaHet *novo);

float ret_area (retangulo *r);
float tri_area (triangulo *t);
float cir_area (circulo *c);

float area(ListaHet *p);
float area_max(ListaHet *lista);
void imprime(ListaHet *lista);
void libera(ListaHet *lista);

#endif
