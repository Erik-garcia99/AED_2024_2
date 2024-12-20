/*
garcia chavez erik 01275863

algoritmos y estrucuctura de datos

practica recorrido de grafos dijsktra

 */

#include <stdio.h>
#include <stdlib.h>

/************************************************************ */
// estrucuturas
struct Nodo
{
    char identificador;
    int NodoCompletado;
    // int visitado;
    struct Grafo *nodos_adyacentes;
    struct Nodo *sigueinteDirectorio;
};

struct Grafo
{
    struct Nodo *nodo;
    int pesoArista;
    int Visitado;
    struct Grafo *siguiente_nodo_adyacente;
};

struct nodosVisitador_visitar
{
    struct Nodo *nodo;
    struct nodosVisitador_visitar *sig;
};

struct tablaDijkstra
{
    struct Nodo *indiceTabla;
    struct tablaDijkstra *NodoPrevio;
    int distanciaMasCorta;
    struct tablaDijkstra *sig;
};

struct pilaRecorrido
{
    struct tablaDijkstra *indice_tabla;
    struct pilaRecorrido *siguiente;
};
/************************************************************ */

// ************************************prototipos************************

// inicio y comienzo de direcotrios de lista de adyacencia:
struct Nodo *crear_directorio_lista_adyacencia(char identificador);
struct Nodo *agregar_directorio_lista_adyacencia(struct Nodo *inicio, char identificador);

// inicio y comienzo de los nodos adyacnetes a cada nodo,
struct Grafo *agregar_enlace_conexion(struct Grafo *nodo_inicio_directorio, struct Nodo *nodo_enlazado_adyacente, int peso);
struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazar, int peso);

struct Nodo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazada, int peso);

// crear nuestras colas de nodos visitados
struct nodosVisitador_visitar *agregarCola_visitar(struct nodosVisitador_visitar *inicio, struct Nodo *nodo);
struct nodosVisitador_visitar *crearCola_visitar(struct Nodo *listaAdyacencia);

// funciones para crear la cola asi como de traspaso de nodos por visitar a visitados
struct nodosVisitador_visitar *crearCola_visitar(struct Nodo *listaAdyacencia);

struct nodosVisitador_visitar *agregarCola_visitar(struct nodosVisitador_visitar *inicio, struct Nodo *nodo);

struct nodosVisitador_visitar *trasportar_nodos_visitados(struct Nodo *nodo_terminado, struct nodosVisitador_visitar *cola_nodosVisitados);

struct nodosVisitador_visitar *cambio_puntero_cola_visitar(struct nodosVisitador_visitar *inicioCola, struct Nodo *nodo);

// funciones para el algoritmo de dijstea
struct tablaDijkstra *establecer_tabla_dijkstra(struct tablaDijkstra *inicio_tabla, struct nodosVisitador_visitar *cola_nodos_visitar, struct Nodo *inicio_directorio_adyacencias, struct nodosVisitador_visitar *cola_nodos_visitados, char nodo_inicio);

struct tablaDijkstra *crear_tabla_inicio(struct Nodo *nodo, int nodoInicio);

struct tablaDijkstra *agregar_siguiente_indice_tabla(struct tablaDijkstra *inicio_tabla, struct Nodo *nodo, int nodoAgregado);

struct tablaDijkstra *inicar_tabla_dijkstra(struct tablaDijkstra *inicio_tabla, struct nodosVisitador_visitar *inicio_cola_vistar, char nodo_inicio);

struct tablaDijkstra *nodo_distancias_mas_corta(struct tablaDijkstra *inicio_tabla, struct tablaDijkstra *respaldo_tabla);

struct tablaDijkstra *anlaizando_nodos_adyacentes(struct tablaDijkstra *nodo_mas_chico, struct tablaDijkstra *inicio_tabla, struct Grafo *nodos_adyacentes);

// mostrar tabla
void mostrar_tabla(struct tablaDijkstra *inicio_tabla);

void mostar_ruta_mas_corta_entre_nodos(struct tablaDijkstra *inicioTabla, char inicio, char final);

struct pilaRecorrido *crear_pila_recorrido(struct tablaDijkstra *inicio);

struct pilaRecorrido *agregar_pila(struct pilaRecorrido *inicio, struct tablaDijkstra *indice);

struct pilaRecorrido *limpiarPila(struct pilaRecorrido *inicio);

int main(void)
{
    struct Nodo *listAdyacencia = NULL;

    char nodos[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

    for (int i = 0; i < 20; i++)
    {
        if (listAdyacencia == NULL)
        {
            listAdyacencia = crear_directorio_lista_adyacencia(nodos[i]);
        }
        else
        {
            listAdyacencia = agregar_directorio_lista_adyacencia(listAdyacencia, nodos[i]);
        }
    }

    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'A', 'D', 85);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'A', 'D', 30);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'A', 'B', 100);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'B', 'A', 100);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'B', 'E', 40);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'B', 'F', 45);

    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'B', 'G', 70);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'B', 'C', 100);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'C', 'B', 100);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'C', 'G', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'C', 'H', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'D', 'A', 30);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'D', 'A', 85);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'D', 'P', 50);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'E', 'I', 10);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'E', 'B', 40);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'I', 'E', 10);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'I', 'P', 90);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'I', 'J', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'P', 'I', 90);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'P', 'D', 50);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'P', 'R', 205);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'Q', 'J', 45);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'Q', 'R', 5);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'J', 'F', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'J', 'I', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'J', 'K', 80);

    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'J', 'Q', 45);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'F', 'B', 45);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'F', 'J', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'R', 'P', 205);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'R', 'T', 230);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'R', 'Q', 5);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'G', 'B', 70);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'G', 'C', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'G', 'L', 20);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'G', 'K', 15);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'K', 'G', 15);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'K', 'J', 80);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'K', 'M', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'M', 'S', 2);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'M', 'K', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'M', 'L', 50);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'S', 'M', 2);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'S', 'N', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'S', 'T', 25);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'T', 'S', 25);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'T', 'R', 230);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'T', 'N', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'T', 'O', 195);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'L', 'G', 20);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'L', 'H', 40);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'L', 'M', 50);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'N', 'S', 55);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'N', 'H', 85);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'N', 'T', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'N', 'O', 105);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'N', 'O', 120);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'O', 'N', 105);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'O', 'N', 120);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'O', 'T', 195);

    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'O', 'H', 70);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'H', 'O', 70);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'H', 'C', 60);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'H', 'N', 85);
    listAdyacencia = establecer_enlace_conexiones(listAdyacencia, 'H', 'L', 40);

    struct nodosVisitador_visitar *cola_nodosVisitar = NULL;
    struct nodosVisitador_visitar *cola_nodosVisitados = NULL;

    struct Nodo *aux = listAdyacencia;

    while (aux != NULL)
    {
        if (cola_nodosVisitar == NULL)
        {
            cola_nodosVisitar = crearCola_visitar(aux);
            aux = aux->sigueinteDirectorio;
        }
        else
        {
            cola_nodosVisitar = agregarCola_visitar(cola_nodosVisitar, aux);
            aux = aux->sigueinteDirectorio;
        }
    }

    struct tablaDijkstra *dijkstra = NULL;

    dijkstra = establecer_tabla_dijkstra(dijkstra, cola_nodosVisitar, listAdyacencia, cola_nodosVisitados, 'A');

    // mostrar el camino

    mostar_ruta_mas_corta_entre_nodos(dijkstra, 'A', 'L');
}

/******************************************************************** */

// funciones que crear en directorio de las listas de adyacencias
struct Nodo *crear_directorio_lista_adyacencia(char identificador)
{
    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo *));
    nuevo->identificador = identificador;
    nuevo->NodoCompletado = 0;
    // nuevo->visitado = 0;
    nuevo->nodos_adyacentes = NULL;
    nuevo->sigueinteDirectorio = NULL;
    return (nuevo);
}

struct Nodo *agregar_directorio_lista_adyacencia(struct Nodo *inicio, char identificador)
{
    struct Nodo *aux = inicio;
    struct Nodo *nuevo = crear_directorio_lista_adyacencia(identificador);

    while (aux->sigueinteDirectorio != NULL)
    {
        aux = aux->sigueinteDirectorio;
    }

    aux->sigueinteDirectorio = nuevo;

    return (inicio);
}

/******************************************************************** */
// crear conexiones a los indices de la lista de adyacencia
struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazar, int peso)
{

    struct Grafo *nuevo;
    nuevo = (struct Grafo *)malloc(sizeof(struct Grafo));

    nuevo->nodo = nodo_enlazar;
    nuevo->pesoArista = peso;
    nuevo->Visitado = 0;
    nuevo->siguiente_nodo_adyacente = NULL;
    return (nuevo);
}

struct Grafo *agregar_enlace_conexion(struct Grafo *nodo_inicio_directorio, struct Nodo *nodo_enlazado_adyacente, int peso)
{

    struct Grafo *aux = nodo_inicio_directorio;
    struct Grafo *nuevo;
    nuevo = crear_enlace_conexion(nodo_enlazado_adyacente, peso);

    while (aux->siguiente_nodo_adyacente != NULL)
    {
        aux = aux->siguiente_nodo_adyacente;
    }

    aux->siguiente_nodo_adyacente = nuevo;

    return (nodo_inicio_directorio);
}

/******************************************************************* */
// logica de comenzar a crear al grafo

struct Nodo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazada, int peso)
{
    // primero debo buscar a mis nodos

    struct Nodo *indice_directorio = lista_de_directorios_adyacentes;
    struct Nodo *nodo_enlazar_adyacente = lista_de_directorios_adyacentes;
    // struct Grafo *enlace = inicio_grafo;

    while (indice_directorio->sigueinteDirectorio != NULL)
    {
        if (indice_directorio->identificador != nodo_Inicio)
        {
            indice_directorio = indice_directorio->sigueinteDirectorio;
        }
        else
        {
            break;
        }
    }

    while (nodo_enlazar_adyacente->sigueinteDirectorio != NULL)
    {
        if (nodo_enlazar_adyacente->identificador != nodo_enlazada)
        {
            nodo_enlazar_adyacente = nodo_enlazar_adyacente->sigueinteDirectorio;
        }
        else
        {
            break;
        }
    }

    // en caso que alguno de los 2 nodos no esten
    if (indice_directorio->sigueinteDirectorio == NULL && indice_directorio->identificador != nodo_Inicio)
    {
        struct Nodo *nuevo;
        nuevo = crear_directorio_lista_adyacencia(nodo_Inicio);
        lista_de_directorios_adyacentes = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazada, peso);
    }

    if (nodo_enlazar_adyacente->sigueinteDirectorio == NULL && nodo_enlazar_adyacente->identificador != nodo_enlazada)
    {
        struct Nodo *nuevo;
        nuevo = crear_directorio_lista_adyacencia(nodo_enlazada);
        lista_de_directorios_adyacentes = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazada, peso);
    }

    // em casp de que si se ecuntrasn nuestros nodos, podemos comenzar a establecer el enlace
    struct Grafo *enlace = indice_directorio->nodos_adyacentes;

    if (enlace == NULL)
    {
        // aun no se inicia ningun enlace, es el primero

        enlace = crear_enlace_conexion(nodo_enlazar_adyacente, peso);
        indice_directorio->nodos_adyacentes = enlace;
    }
    else
    {
        enlace = agregar_enlace_conexion(enlace, nodo_enlazar_adyacente, peso);
    }

    return (lista_de_directorios_adyacentes);
}

/*************************************************************************/

// creamos nuestras listas de nodos por viistar y la logica para traspasar de visitrar -> visitado

struct nodosVisitador_visitar *crearCola_visitar(struct Nodo *listaAdyacencia)
{

    struct nodosVisitador_visitar *nuevo;
    nuevo = (struct nodosVisitador_visitar *)malloc(sizeof(struct nodosVisitador_visitar));

    nuevo->nodo = listaAdyacencia;
    nuevo->sig = NULL;

    return (nuevo);
}

struct nodosVisitador_visitar *agregarCola_visitar(struct nodosVisitador_visitar *inicio, struct Nodo *nodo)
{

    struct nodosVisitador_visitar *aux = inicio;
    struct nodosVisitador_visitar *nuevo = crearCola_visitar(nodo);

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;

    return (inicio);
}

// primreo lo agrego a la cola de los visitados y despues cambio el punto de los por visitar.
struct nodosVisitador_visitar *trasportar_nodos_visitados(struct Nodo *nodo_terminado, struct nodosVisitador_visitar *cola_nodosVisitados)
{
    struct nodosVisitador_visitar *aux = cola_nodosVisitados;

    if (aux == NULL)
    {

        aux = crearCola_visitar(nodo_terminado);
    }
    else
    {
        aux = agregarCola_visitar(aux, nodo_terminado);
    }

    return (aux);
}

struct nodosVisitador_visitar *cambio_puntero_cola_visitar(struct nodosVisitador_visitar *inicioCola, struct Nodo *nodo)
{

    struct nodosVisitador_visitar *aux = inicioCola;
    struct nodosVisitador_visitar *anterior = NULL;
    // busco ese nodo

    while (aux != NULL && aux->nodo != nodo)
    {
        anterior = aux;
        aux = aux->sig;
    }

    if (anterior == NULL)
    {
        inicioCola = aux->sig;
    }
    else
    {
        if (aux->sig != NULL)
        {
            // en medio
            anterior->sig = aux->sig;
        }
        else
        {
            anterior->sig = aux->sig;
        }
    }

    return (inicioCola);
}

/*************************************************************************/
// algoritmo de dijkstra

struct tablaDijkstra *establecer_tabla_dijkstra(struct tablaDijkstra *inicio_tabla, struct nodosVisitador_visitar *cola_nodos_visitar, struct Nodo *inicio_directorio_adyacencias, struct nodosVisitador_visitar *cola_nodos_visitados, char nodo_inicio)
{

    struct tablaDijkstra *aux_inicioTabla = inicio_tabla;
    struct tablaDijkstra *respaldo_tabla = NULL;
    struct nodosVisitador_visitar *aux_cola_nodos_visitar = cola_nodos_visitar;
    struct nodosVisitador_visitar *respaldo_global_cola_nodos_visitar = cola_nodos_visitar;

    struct nodosVisitador_visitar *aux_quitar_nodo_lista = NULL;

    struct nodosVisitador_visitar *nodos_visitados = cola_nodos_visitados;
    struct Nodo *aux_inicio_adyacentes = inicio_directorio_adyacencias;
    struct Nodo *nodo_agregar;
    int cambio;
    struct Grafo *nodos_adyacente_INDTAC = NULL;
    struct nodosVisitador_visitar *nodos_visitador = NULL;

    aux_inicioTabla = inicar_tabla_dijkstra(inicio_tabla, aux_cola_nodos_visitar, nodo_inicio);

    respaldo_tabla = aux_inicioTabla;

    inicio_tabla = aux_inicioTabla;

    if (aux_inicioTabla == NULL)
    {

        return NULL;
    }

    // aux_cola_nodos_visitar = respaldo_global_cola_nodos_visitar; ->no deberia de ir aqui

    mostrar_tabla(aux_inicioTabla);

    struct nodosVisitador_visitar *nodo_inicar = NULL;
    int encontrado;

    struct tablaDijkstra *nodo_analizadno = NULL;
    while (aux_cola_nodos_visitar != NULL)
    {

        encontrado = 0;

        nodo_inicar = aux_cola_nodos_visitar;

        aux_inicioTabla = respaldo_tabla;

        while (encontrado == 0 && aux_inicioTabla != NULL)
        {

            if (nodo_inicar->nodo == aux_inicioTabla->indiceTabla)
            {
                if (aux_inicioTabla->indiceTabla->NodoCompletado != 0)
                {

                    aux_inicioTabla = aux_inicioTabla->sig;
                }
                else
                {
                    encontrado = 1;
                }
            }
            else if (aux_inicioTabla == NULL)
            {

                return aux_inicioTabla;
            }
            else
            {
                aux_inicioTabla = aux_inicioTabla->sig;
            }
        }

        aux_inicioTabla = nodo_distancias_mas_corta(aux_inicioTabla, respaldo_tabla);

        nodos_adyacente_INDTAC = aux_inicioTabla->indiceTabla->nodos_adyacentes;

        inicio_tabla = anlaizando_nodos_adyacentes(aux_inicioTabla, inicio_tabla, nodos_adyacente_INDTAC);

        nodos_visitados = trasportar_nodos_visitados(aux_inicioTabla->indiceTabla, nodos_visitados);

        aux_cola_nodos_visitar = cambio_puntero_cola_visitar(aux_cola_nodos_visitar, aux_inicioTabla->indiceTabla);
        mostrar_tabla(inicio_tabla);
    }

    return (inicio_tabla);
}

/****************************crear la tabla de dijkstra************************ */

struct tablaDijkstra *crear_tabla_inicio(struct Nodo *nodo, int nodoInicio)
{
    struct tablaDijkstra *nuevo;
    nuevo = (struct tablaDijkstra *)malloc(sizeof(struct tablaDijkstra));
    nuevo->indiceTabla = nodo;
    nuevo->NodoPrevio = NULL;
    nuevo->sig = NULL;

    // verifiacmaos si es nodo inical el cual tendra 0 como distancias mas corta o es otro nodo, el cual tendra el valor de infinitio, o en caso de C el maximo numero que se puede representar en C como un tipo de dato entero.

    if (nodoInicio != 0)
    {
        nuevo->distanciaMasCorta = 0;
    }
    else
    {
        nuevo->distanciaMasCorta = 2147483647;
    }

    return (nuevo);
}
// agregar nodos indice a la tabla
struct tablaDijkstra *agregar_siguiente_indice_tabla(struct tablaDijkstra *inicio_tabla, struct Nodo *nodo, int nodoAgregado)
{
    struct tablaDijkstra *aux_tabla = inicio_tabla;
    struct tablaDijkstra *nuevo = crear_tabla_inicio(nodo, nodoAgregado);

    while (aux_tabla->sig != NULL)
    {
        aux_tabla = aux_tabla->sig;
    }
    aux_tabla->sig = nuevo;
    return (inicio_tabla);
}

/********************************************************* */
//         inicar la tabla de dikjstra
struct tablaDijkstra *inicar_tabla_dijkstra(struct tablaDijkstra *inicio_tabla, struct nodosVisitador_visitar *inicio_cola_vistar, char nodo_inicio)
{
    struct Nodo *nodo_agregar = NULL;
    struct tablaDijkstra *aux_inicioTabla = inicio_tabla;
    struct nodosVisitador_visitar *aux_cola_nodos_visitar = inicio_cola_vistar;
    struct nodosVisitador_visitar *respaldo_global_cola_nodos_visitar = inicio_cola_vistar;

    while (aux_cola_nodos_visitar != NULL)
    {

        if (aux_inicioTabla != NULL)
        {
            if (aux_cola_nodos_visitar->nodo->identificador != nodo_inicio)
            {
                nodo_agregar = aux_cola_nodos_visitar->nodo;
                aux_inicioTabla = agregar_siguiente_indice_tabla(aux_inicioTabla, nodo_agregar, 0);
                aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
            }
            else
            {
                aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
            }
        }
        else
        {
            while (aux_cola_nodos_visitar != NULL)
            {

                nodo_agregar = aux_cola_nodos_visitar->nodo;

                if (nodo_agregar->identificador != nodo_inicio)
                {
                    aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
                }
                else
                {
                    aux_inicioTabla = crear_tabla_inicio(nodo_agregar, 1);

                    aux_cola_nodos_visitar = respaldo_global_cola_nodos_visitar;
                    break;
                }
            }
            if (aux_cola_nodos_visitar == NULL)
            {

                return inicio_tabla;
            }
        }
    }

    return (aux_inicioTabla);
}

/**************************************************************************/
//         busca entre todos los nodos aun no prcesados quien tiene la distancia mas corta
struct tablaDijkstra *nodo_distancias_mas_corta(struct tablaDijkstra *inicio_tabla, struct tablaDijkstra *respaldo_tabla)
{

    struct tablaDijkstra *segundoComparador = respaldo_tabla;
    struct tablaDijkstra *aux_inicioTabla = inicio_tabla;
    int cambio = 0;
    while (segundoComparador != NULL || cambio == 1)
    {
        cambio = 0;
        segundoComparador = respaldo_tabla;

        while (cambio == 0)
        {

            if (segundoComparador == NULL)
            {
                break;
            }
            if (aux_inicioTabla->distanciaMasCorta < segundoComparador->distanciaMasCorta || aux_inicioTabla == segundoComparador)
            {

                segundoComparador = segundoComparador->sig;
            }
            else
            {

                if (segundoComparador->indiceTabla->NodoCompletado == 0)
                {

                    aux_inicioTabla = segundoComparador;
                }
                else
                {

                    segundoComparador = segundoComparador->sig;
                }
            }
        }
    }

    return (aux_inicioTabla);
}
/****************************************************************************** */

struct tablaDijkstra *anlaizando_nodos_adyacentes(struct tablaDijkstra *nodo_mas_chico, struct tablaDijkstra *inicio_tabla, struct Grafo *nodos_adyacentes)
{
    struct Grafo *aux_nodos_adyacentes = nodos_adyacentes;
    struct tablaDijkstra *aux_inicio_tabla = inicio_tabla;
    struct tablaDijkstra *nodo_adyacente_tabajaDij = NULL;
    int distancia;
    while (aux_nodos_adyacentes != NULL)
    {

        if (aux_inicio_tabla == NULL)
        {
            break;
        }
        if (aux_inicio_tabla->indiceTabla == aux_nodos_adyacentes->nodo)
        {
            if (aux_nodos_adyacentes->nodo->NodoCompletado == 0)
            {
                nodo_adyacente_tabajaDij = aux_inicio_tabla;

                distancia = nodo_mas_chico->distanciaMasCorta;

                distancia = distancia + aux_nodos_adyacentes->pesoArista;

                if (distancia < nodo_adyacente_tabajaDij->distanciaMasCorta)
                {

                    nodo_adyacente_tabajaDij->NodoPrevio = nodo_mas_chico;
                    nodo_adyacente_tabajaDij->distanciaMasCorta = distancia;
                    aux_nodos_adyacentes->Visitado = 1;
                    mostrar_tabla(inicio_tabla);
                    aux_inicio_tabla = inicio_tabla;
                    aux_nodos_adyacentes = aux_nodos_adyacentes->siguiente_nodo_adyacente;
                }
                else
                {
                    aux_nodos_adyacentes = aux_nodos_adyacentes->siguiente_nodo_adyacente;
                    aux_inicio_tabla = inicio_tabla;
                    mostrar_tabla(inicio_tabla);
                }
            }
            else
            {
                aux_nodos_adyacentes = aux_nodos_adyacentes->siguiente_nodo_adyacente;
            }
        }

        else
        {
            aux_inicio_tabla = aux_inicio_tabla->sig;
        }
    }

    // nodo completado
    nodo_mas_chico->indiceTabla->NodoCompletado = 1;
    return (inicio_tabla);
}

/************************************************************************/
// funcion que muestra la tabla

void mostrar_tabla(struct tablaDijkstra *inicio_tabla)
{
    struct tablaDijkstra *aux = inicio_tabla;
    printf("\n\n||  NODO  ||  DISTANCIA MAS CORTA  || NODO PREVIO  ||\n");
    while (aux != NULL)
    {
        // printf("||  %c     ||          %d             ||      %c         ||\n", aux->indiceTabla->identificador, aux->distanciaMasCorta, aux->NodoPrevio->identificador);
        // aux = aux->sig;
        if (aux->indiceTabla != NULL)
        {
            printf("||  %c     ||", aux->indiceTabla->identificador);
        }
        else
        {
            printf("error, debe estar inicalizada la tabla");
        }

        printf("          %d             ||", aux->distanciaMasCorta);

        if (aux->NodoPrevio != NULL)
        {
            printf("      %c         ||\n", aux->NodoPrevio->indiceTabla->identificador);
        }
        else
        {
            printf("     NULL         ||\n");
        }
        aux = aux->sig;
    }
}

/************************************************************************/

void mostar_ruta_mas_corta_entre_nodos(struct tablaDijkstra *inicioTabla, char inicio, char final)
{
    // primreo busco
    int valor = 0;
    struct tablaDijkstra *aux_inicio = inicioTabla;
    struct pilaRecorrido *pila = NULL;
    struct tablaDijkstra *aux_sumatoria = NULL;
    struct Nodo *aux_nodo = NULL;
    struct Grafo *aux_nodo_segundo;
    struct Nodo *nodo_adyacente = NULL;

    // primero debo buscar el nodo el cual quiere inciar
    while (aux_inicio->indiceTabla->identificador != final)
    {
        aux_inicio = aux_inicio->sig;
    }
    int inicio_encontrado = 0;
    while (inicio_encontrado == 0)
    {
        if (aux_inicio->indiceTabla->identificador == inicio)
        {
            inicio_encontrado = 1;
        }
        if (pila == NULL)
        {
            pila = crear_pila_recorrido(aux_inicio);
        }
        else
        {
            pila = agregar_pila(pila, aux_inicio);
        }
        // printf(" %c -> ", aux_inicio->indiceTabla->identificador);
        aux_inicio = aux_inicio->NodoPrevio;
    }

    // sumatorio
    while (pila != NULL)
    {
        aux_nodo = pila->indice_tabla->indiceTabla;
        printf("%c -> ", aux_nodo->identificador);
        pila = limpiarPila(pila);
        aux_nodo_segundo = aux_nodo->nodos_adyacentes;
        if (pila != NULL)
        {
            nodo_adyacente = pila->indice_tabla->indiceTabla;
        }
        else
        {
            break;
        }

        if (aux_nodo_segundo != NULL)
        {
            while (aux_nodo_segundo->nodo != nodo_adyacente)
            {
                aux_nodo_segundo = aux_nodo_segundo->siguiente_nodo_adyacente;
            }
            valor += aux_nodo_segundo->pesoArista;
        }
    }

    printf("\ncosto: %d", valor);
}

struct pilaRecorrido *crear_pila_recorrido(struct tablaDijkstra *inicio)
{
    struct pilaRecorrido *nuevo;
    nuevo = (struct pilaRecorrido *)malloc(sizeof(struct pilaRecorrido));
    nuevo->indice_tabla = inicio;
    nuevo->siguiente = NULL;
    return (nuevo);
}

struct pilaRecorrido *agregar_pila(struct pilaRecorrido *inicio, struct tablaDijkstra *indice)
{
    struct pilaRecorrido *aux = inicio;
    struct pilaRecorrido *nuevo = crear_pila_recorrido(indice);

    nuevo->siguiente = aux;
    inicio = nuevo;

    return (inicio);
}

struct pilaRecorrido *limpiarPila(struct pilaRecorrido *inicio)
{
    struct pilaRecorrido *aux = inicio;

    inicio = aux->siguiente;
    return (inicio);
}