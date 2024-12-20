#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    char identificador;
    int vitado;
    int peso;
    struct Grafo *nodos_adyacentes;
    struct Nodo *sigueinte_directorio;
};

struct Grafo
{
    struct Nodo *nodo;
    // int peso;
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

struct Cola *obetener_dato_cola(struct Cola *cola);

struct Nodo *recorrido_anchura(struct Nodo *directorio, char nodoInicial);
int main()
{
    char nodos[9] = {'s', 'r', 't', 'u', 'y', 'v', 'w', 'x', 'z'};

    struct Nodo *directorio = NULL;

    for (int i = 0; i < 9; i++)
    {
        if (directorio == NULL)
        {
            directorio = crearDirectorio_listas_adyacentes(nodos[i]);
        }
        else
        {
            directorio = agregar_directorio_adyacente(directorio, nodos[i]);
        }
    }

    directorio = establecer_enlace_conexiones(directorio, 's', 'r');
    directorio = establecer_enlace_conexiones(directorio, 's', 'v');
    directorio = establecer_enlace_conexiones(directorio, 's', 'u');
    directorio = establecer_enlace_conexiones(directorio, 'r', 's');
    directorio = establecer_enlace_conexiones(directorio, 'r', 'w');
    directorio = establecer_enlace_conexiones(directorio, 'r', 't');
    directorio = establecer_enlace_conexiones(directorio, 't', 'u');
    directorio = establecer_enlace_conexiones(directorio, 't', 'r');
    directorio = establecer_enlace_conexiones(directorio, 'u', 't');
    directorio = establecer_enlace_conexiones(directorio, 'u', 's');
    directorio = establecer_enlace_conexiones(directorio, 'u', 'y');
    directorio = establecer_enlace_conexiones(directorio, 'y', 'u');
    directorio = establecer_enlace_conexiones(directorio, 'y', 'v');
    directorio = establecer_enlace_conexiones(directorio, 'y', 'x');
    directorio = establecer_enlace_conexiones(directorio, 'y', 'u');
    directorio = establecer_enlace_conexiones(directorio, 'v', 'y');
    directorio = establecer_enlace_conexiones(directorio, 'v', 's');
    directorio = establecer_enlace_conexiones(directorio, 'v', 'w');
    directorio = establecer_enlace_conexiones(directorio, 'v', 'y');
    directorio = establecer_enlace_conexiones(directorio, 'w', 'r');
    directorio = establecer_enlace_conexiones(directorio, 'w', 'v');
    directorio = establecer_enlace_conexiones(directorio, 'w', 'z');
    directorio = establecer_enlace_conexiones(directorio, 'w', 'x');
    directorio = establecer_enlace_conexiones(directorio, 'x', 'w');
    directorio = establecer_enlace_conexiones(directorio, 'x', 'y');
    directorio = establecer_enlace_conexiones(directorio, 'z', 'w');
    directorio = establecer_enlace_conexiones(directorio, 'z', 'x');

    directorio = recorrido_anchura(directorio, 's');

    getchar();
}

struct Nodo *crearDirectorio_listas_adyacentes(char identificador)
{

    struct Nodo *nuevo;

    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    nuevo->identificador = identificador;
    nuevo->nodos_adyacentes = NULL;
    nuevo->sigueinte_directorio = NULL;
    nuevo->vitado = 0;
    nuevo->peso = 0;

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
    // nuevo->peso = 0;
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
        enlace = crear_enlace_conexion(nodo_enlazar_adyacente);
        indice_directorio->nodos_adyacentes = enlace;
    }
    else
    {
        enlace = agregar_enlace_conexion(enlace, nodo_enlazar_adyacente);
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

    // free(aux);

    return (cola);
}

struct Cola *obetener_dato_cola(struct Cola *cola)
{
    struct Cola *aux = cola;

    return (aux);
}

// ahora el algoritmo que busca esas cosas.

struct Nodo *recorrido_anchura(struct Nodo *directorio, char nodoInicial)
{

    // ests funcion me ba a regresar el directorio pero esta ya tebdrs modificado los pesos que le tomars ir del nodo 1 a todos los femss

    struct Nodo *aux_directorio = directorio;

    // por lo que primeeo debemos buscar el modo el cual quiere incisr ls busqueda

    while (aux_directorio->sigueinte_directorio != NULL && aux_directorio->identificador != nodoInicial)
    {

        aux_directorio = aux_directorio->sigueinte_directorio;
    }

    // aqui sacara el nodo con el que se wuiere inicsr

    if (aux_directorio == NULL)
    {
        printf("el nodo que se quiere inicar ni se encuentra, compruebe el ingreso");
        return NULL;
    }
    else
    {

        // en este p8ntl necesito inicar la cola

        struct Cola *cola_prioridad = crear_cola(aux_directorio);
        aux_directorio->vitado = 1;
        // ahors nevsito agregar s la cola tofod los nodos los cuales edta enlazado este nodo

        // crro que aqui arriba debe ir un while miendtrss ls cola no este vscis

        while (cola_prioridad != NULL)
        {
            struct Nodo *nodo_obtenido = cola_prioridad->nodo;

            struct Grafo *aux_graf = nodo_obtenido->nodos_adyacentes;

            int peso = nodo_obtenido->peso;

            while (aux_graf != NULL)
            {

                if (aux_graf->nodo->vitado == 0)
                {

                    int peso_enlace = peso + 1;

                    aux_graf->nodo->peso = peso_enlace;

                    aux_graf->nodo->vitado = 1;

                    cola_prioridad = agregar_cola(cola_prioridad, aux_graf->nodo);
                    aux_graf = aux_graf->sigueinte_nodo_adyacente;
                }
                else
                {
                    aux_graf = aux_graf->sigueinte_nodo_adyacente;
                }
            }
            cola_prioridad = eliminar_cola(cola_prioridad);
        }
    }

    return (directorio);
}