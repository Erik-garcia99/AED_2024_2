#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    char identificador;
    int vitado;
    struct Grafo *nodos_adyacentes;
    struct Nodo *sigueinte_directorio;
};

struct Grafo
{
    struct Nodo *nodo;
    int peso;
    struct Grafo *sigueinte_nodo_adyacente;
};

struct Cola
{
    struct Nodo *nodo;
    struct Cola *sig;
};

struct Nodo *crearDirectorio_listas_adyacentes(char identificador);

// agregar al directorio
struct Nodo *agregar_directorio_adyacente(struct Nodo *nodo, int identificador);

// crear un enlace de conexon
struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazar);

struct Grafo *agregar_enlace_conexion(struct Grafo *inicio, struct Nodo *nodo_enlazar);

struct Nodo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazadar);

struct Cola *crear_cola(struct Nodo *nodo);

struct Cola *agregar_cola(struct Cola *cola, struct Nodo *nodo);

struct Cola *eliminar_cola(struct Cola *cola);
int main()
{
}

struct Nodo *crearDirectorio_listas_adyacentes(char identificador)
{

    struct Nodo *nuevo;

    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    nuevo->identificador = identificador;
    nuevo->nodos_adyacentes = NULL;
    nuevo->sigueinte_directorio = NULL;
    nuevo->vitado = 0;

    return (nuevo);
}

struct Nodo *agregar_directorio_adyacente(struct Nodo *nodo, int identificador)
{

    struct Nodo *aux = nodo;
    struct Nodo *nuevo;

    nuevo = crearDirectorio_listas_adyacentes(identificador);

    while (aux->sigueinte_directorio != NULL)
    {
        aux = aux->sigueinte_directorio;
    }

    aux->sigueinte_directorio = nuevo;

    return (nodo);
}

// crearcion, agracion y conexion entre nodos a enlazar

struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazar)
{
    struct Grafo *nuevo;

    nuevo = (struct Grafo *)malloc(sizeof(struct Grafo));

    nuevo->nodo = nodo_enlazar;
    nuevo->peso = 0;
    nuevo->sigueinte_nodo_adyacente = NULL;

    return (nuevo);
}

struct Grafo *agregar_enlace_conexion(struct Grafo *inicio, struct Nodo *nodo_enlazar)
{
    struct Grafo *aux = inicio;
    struct Grafo *nuevo = crear_enlace_conexion(nodo_enlazar);

    while (aux->sigueinte_nodo_adyacente != NULL)
    {
        aux = aux->sigueinte_nodo_adyacente;
    }

    aux->sigueinte_nodo_adyacente = nuevo;

    return (inicio);
}

struct Nodo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazadar)
{

    struct Nodo *indice_directorio = lista_de_directorios_adyacentes;

    struct Nodo *nodo_enlazar_adyacente = lista_de_directorios_adyacentes;

    while (indice_directorio->sigueinte_directorio != NULL && indice_directorio->identificador != nodo_Inicio)
    {
        indice_directorio = indice_directorio->sigueinte_directorio;
    }

    // una vez que salga tengo el nodo el cual es el nodo al cual yo le agregare su nodo adyacente.

    // ahora necesito buscar el nodo al cual yo lo voy a enlzar con el primeor por lo que la busuqeda es la misma

    while (nodo_enlazar_adyacente->sigueinte_directorio != NULL && nodo_enlazar_adyacente->identificador != nodo_enlazadar)
    {
        nodo_enlazar_adyacente = nodo_enlazar_adyacente->sigueinte_directorio;
    }

    // ahora ya tengo los 2 nodos, por lo que ahora toca enlazarlos.

    if (indice_directorio == NULL)
    {
        struct Nodo *nuevo;
        nuevo = agregar_directorio_adyacente(lista_de_directorios_adyacentes, nodo_Inicio);

        lista_de_directorios_adyacentes = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazadar);
    }

    if (nodo_enlazar_adyacente == NULL)
    {
        struct Nodo *nuevo;
        nuevo = agregar_directorio_adyacente(lista_de_directorios_adyacentes, nodo_enlazadar);

        lista_de_directorios_adyacentes = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazadar);
    }

    struct Grafo *enlace = indice_directorio->nodos_adyacentes;

    if (enlace == NULL)
    {
        enlace = crear_enlace_conexion(nodo_enlazadar);
        indice_directorio->nodos_adyacentes = enlace;
    }
    else
    {
        enlace = agregar_enlace_conexion(enlace, nodo_enlazadar);
    }

    return (lista_de_directorios_adyacentes);
}

struct Cola *crear_cola(struct Nodo *nodo)
{
    struct Cola *nuevo = (struct Cola *)malloc(sizeof(struct Cola));

    nuevo->nodo = nodo;
    nuevo->sig = NULL;

    return (nuevo);
}

struct Cola *agregar_cola(struct Cola *cola, struct Nodo *nodo)
{

    struct Cola *aux_cola = cola;

    struct Cola *nuevo = crear_cola(nodo);

    while (aux_cola->sig != NULL)
    {
        aux_cola = aux_cola->sig;
    }

    aux_cola->sig = nuevo;

    return (cola);
}

struct Cola *eliminar_cola(struct Cola *cola)
{

    struct Cola *aux = cola;

    aux = cola;
    cola = cola->sig;

    free(aux);

    return (cola);
}

// ahora el algoritmo que busca esas cosas.

struct Nodo *recorrido_anchura()
{
}