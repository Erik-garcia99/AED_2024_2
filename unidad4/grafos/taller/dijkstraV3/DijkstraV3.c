/*
garcia chavez erik 01275863

algoritmos y estrucuctura de datos

practica recorrido de grafos dijsktra

 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

    // despues de crear el grafo por completo, vamos a crear nuestra lista de nodos por visitar

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

    // AHORA EMPIEZA DIJKSTRA

    struct tablaDijkstra *dijkstra = NULL;

    dijkstra = establecer_tabla_dijkstra(dijkstra, cola_nodosVisitar, listAdyacencia, cola_nodosVisitados, 'E');

    // mostrar el camino

    mostar_ruta_mas_corta_entre_nodos(dijkstra, 'E', 'N');
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
// crear y agregar las conexiones de los nodos asociados a los indices del directorio de listas de adyacencia
struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazar, int peso)
{
    // esta funcion me debe de regresar un nodo el cual se va a enlazar con el directorio incial, en otras palabras es la conexin en el grafo de un nodo en particular
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

    // se agrega al nodo que ya se habian agregado, por lo que aqui se trabaja con 1 solo noso

    /*

    | A | -> | B | 23 | -> | C | 45 |

    algo asi es lo que haria, uniria C a B con el peso de 25,que ambos con conexiones en el grafo de A
    */

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

// primero antes empezar a relaizar el alogrimto se debe de estbalecer la tabla

struct tablaDijkstra *establecer_tabla_dijkstra(struct tablaDijkstra *inicio_tabla, struct nodosVisitador_visitar *cola_nodos_visitar, struct Nodo *inicio_directorio_adyacencias, struct nodosVisitador_visitar *cola_nodos_visitados, char nodo_inicio)
{
    // esta funcion me va a regrear la tabla ya creada, con todos los nodos con el peso minimo

    // establcer varibales auxiliares para nuestros parametros

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

    // primero busco el inicio de mi tabla

    // la cola de nodos visitados es nuestra varible que nos dira si el grafo se ha completado con todos sus pesos minimos

    // aqui tan solo estoy creando la tabla pero el algoritmo aun no inical,
    /********************************************************************** */
    //                 inicio de tabla
    // while (aux_cola_nodos_visitar != NULL)
    // {

    //     if (aux_inicioTabla != NULL)
    //     {
    //         if (aux_cola_nodos_visitar->nodo->identificador != nodo_inicio)
    //         {
    //             nodo_agregar = aux_cola_nodos_visitar->nodo;
    //             aux_inicioTabla = agregar_siguiente_indice_tabla(aux_inicioTabla, nodo_agregar, 0);
    //             aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
    //         }
    //         else
    //         {
    //             aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
    //         }
    //     }
    //     else
    //     {
    //         while (aux_cola_nodos_visitar != NULL)
    //         {
    //             // porque pongo lo mismo que arriba, porque cunado entra en efecto tabla sera igual a NULL
    //             // por lo que puedeo poner eso

    //             nodo_agregar = aux_cola_nodos_visitar->nodo;

    //             if (nodo_agregar->identificador != nodo_inicio)
    //             {
    //                 aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
    //             }
    //             else
    //             {
    //                 aux_inicioTabla = crear_tabla_inicio(nodo_agregar, 1);
    //                 // por lo que ahora neceistmoas restablecer auxListaNodos
    //                 aux_cola_nodos_visitar = respaldo_global_cola_nodos_visitar;
    //                 break;
    //             }
    //         }
    //         if (aux_cola_nodos_visitar == NULL)
    //         {
    //             // quier decir que no se conetro por lo que volvemos de donde nos llamaron
    //             return inicio_tabla;
    //         }
    //     }
    // }

    /********************************************** */
    // inicmaos la tabla.
    aux_inicioTabla = inicar_tabla_dijkstra(inicio_tabla, aux_cola_nodos_visitar, nodo_inicio);
    respaldo_tabla = aux_inicioTabla;
    inicio_tabla = aux_inicioTabla;
    if (aux_inicioTabla == NULL)
    {
        // si no se encunera no se que madre regresa NULL. ahorita miramos que odna
        return NULL;
    }
    // inicio de tabla
    /********************************************************** */

    // volvemos a cargar el nodo
    aux_cola_nodos_visitar = respaldo_global_cola_nodos_visitar;

    mostrar_tabla(aux_inicioTabla);

    // en esta parte inica el algoritmo que establecera los caminnos mas cortos entre disitintos puntos.
    // struct tablaDijkstra *segundoComparador = NULL;
    // struct tablaDijkstra *indiceTabalaActual = NULL;
    struct nodosVisitador_visitar *nodo_inicar = NULL;
    int encontrado;
    // este nodo es el nodo que se esta analizando ya con el algoritmo de dijkstra
    struct tablaDijkstra *nodo_analizadno = NULL;
    while (aux_cola_nodos_visitar != NULL)
    {

        // para poder obtener el dato con el valor mas chico necesito hacerlo mediante la cola de nodos por visitar, esto porque, si lo hacia desde la tabla como lo tenis planeado. el nodo incial que es 0, siempre aparecera como el nodo mas chico y siempre estara anlizando el nodo incial, por lo que tenemos qeu encontrar una froma de que cuando se termine de analizar el nodo inical, este no cuente en la sigueitne busqueda.

        // esta variable me servira para salir del ciclo en donde encuentra a un nodo por el cual iniciar, este nodo no es el nodo con la distancia mas corta, lo que necetiro es un nodo para empezar a comprar, al final cunado esta cola este vacia saldra de la funcion
        encontrado = 0;

        // que voy a hacer es sacar el primer elemento de mi cola de nodos por visitar
        nodo_inicar = aux_cola_nodos_visitar;
        // porque, poruqe necesito recorrer la tabla, entonces al inciio tendra A pero tendre que validar que este nodo no este compleado
        // indiceTabalaActual = aux_inicioTabla;
        aux_inicioTabla = respaldo_tabla;

        while (encontrado == 0 && aux_inicioTabla != NULL)
        {
            // tienen la misma direccion
            if (nodo_inicar->nodo == aux_inicioTabla->indiceTabla)
            {
                if (aux_inicioTabla->indiceTabla->NodoCompletado != 0)
                {
                    // si el nodo ya fue completado, sigo al siguiente indice en la tabla
                    aux_inicioTabla = aux_inicioTabla->sig;
                }
                else
                {
                    encontrado = 1;
                }
            }
            else if (aux_inicioTabla == NULL)
            {
                // si por alguna razon entra aqui, quiere decir que ya todods los nodos fueron procesasos y nuca se encontro otro nodo de paoyo para empezar porque el grafo esta completo, por lo que regresa la tabla
                return aux_inicioTabla;
            }
            else
            {
                aux_inicioTabla = aux_inicioTabla->sig;
            }
        }

        /****************************************************************** */
        /**********OBITNE EL NODO CON EL NODO MAS CHICO */
        // que es procigue en nuestro algoritmos es cunado se termina de analziar un nodo se busca el proximo con la distancia mas corta

        // como ya tengo el nodo de referencia, este nodo que stengo ahirita mismo, no es el nodo filan, pero necesito un nodo con el cual empezar a hacer comparaciones en busca del nodo con el la distancia mas corta, por lo que en el siguiente diclo se buscara.

        // por lo que inicio mi seugndo comparador con el mismo valor de indiceTablaActual

        // segundoComparador = indiceTabalaActual;

        // while (segundoComparador != NULL || cambio == 1)
        // {
        //     cambio = 0;
        //     segundoComparador = aux_inicioTabla;

        //     while (cambio == 0)
        //     {
        //         // primero debemos comprar si aun no se ha llegado alf inal, si se llega al final quiere deicri que hubieron cambios o puede haber un error, por lo que salimo

        //         if (segundoComparador == NULL)
        //         {
        //             break;
        //         }
        //         if (aux_inicioTabla->distanciaMasCorta < segundoComparador->distanciaMasCorta || aux_inicioTabla->distanciaMasCorta == segundoComparador->distanciaMasCorta)
        //         {
        //             // neceito comparar nodos de tabla cuyo nodos ded Nodo no han sido completados, en el diagrama que aparezcan en forma de gris

        //             segundoComparador = segundoComparador->sig;
        //         }
        //         else
        //         {
        //             // en cunalquier nodo que sea menor va a parar y mirara, pero por ejemplo los nodos que ya han sido proecesados que ya estan establecidos que essos son los menores y provienen de X nodo, se dentrera en el, por lo que neceisot verificar que ese nodo no este procesado

        //             if (segundoComparador->indiceTabla->NodoCompletado == 0)
        //             {
        //                 // si es igual a cero osea, el nodo no ha completado por lo que podemos asignarlo o compararlo
        //                 aux_inicioTabla = segundoComparador;
        //             }
        //             else
        //             {
        //                 // el otro caso, es como en el ejemplo que D tiene como nodo adyacente A, pero como se mencionod, culquier nodo que ya ha sido comletado puede que tenda un valor menor, por lo que si ese nodo ya ha sido compleado, por lo que no se puede asignar o comprar.

        //                 // por lo que hacemos esseguir al siguiente nodo
        //                 segundoComparador = segundoComparador->sig;
        //             }
        //         }
        //     }
        // }
        aux_inicioTabla = nodo_distancias_mas_corta(aux_inicioTabla, respaldo_tabla);
        /************************************************************************/

        // ya se encontro el nodo con la distancia mas corta, por lo que vamos a poder inciar a hacer las comparaciones.

        // ahora mismo el nodo que trar para comprar el esl indiceTablaInical

        // paso los nodos adyacentes de la tabla, a una vairbale de tipo grasfo, para que sea mas legible sin tantos su parte, y su parte y la vrga
        // nodos_adyacente_INDTAC = indiceTabalaActual->indiceTabla->nodos_adyacentes;
        // while (nodos_adyacente_INDTAC != NULL)
        // {
        // }

        // otro while en donde, el cual va analizar los nodos adyacentes a el

        // para este punto ya obtuve el nodo con la distancia mas corta, que nos dice el algoritmo de dijkstra.el  algoritmo hace una buqueda a profundidad, por lo que va a todos los nodos los cuales se puede ir a 1 paso desde el nodo incial.
        // struct tablaDijkstra *anlaizando_nodos_adyacentes(struct tablaDijkstra * inicio_tabla, struct Grafo * nodos_adyacentes);
        // para el analizis de gradfo
        nodos_adyacente_INDTAC = aux_inicioTabla->indiceTabla->nodos_adyacentes;
        inicio_tabla = anlaizando_nodos_adyacentes(aux_inicioTabla, inicio_tabla, nodos_adyacente_INDTAC);

        // // struct tablaDijkstra *nodo_adyacente_tabajaDij = NULL;
        // while (nodos_adyacente_INDTAC != NULL)
        // {
        //     // que es lo primero que necesito hacer, necesito buscar dentro demi aux_tablaInicio, que es de tipo dijkstra, el indice que contenga el nodo al cual el aux_tablaInicio tiene en su nodo como indice adyacnete

        //     while ()
        // }

        /*¨************************************************************/
        // lo que siguie es quitar el nodo que tenia aux de la lista de los nodos por visitare a los nodos visitados
        nodos_visitados = trasportar_nodos_visitados(aux_inicioTabla->indiceTabla, nodos_visitados);

        aux_cola_nodos_visitar = cambio_puntero_cola_visitar(aux_cola_nodos_visitar, aux_inicioTabla->indiceTabla);
        mostrar_tabla(inicio_tabla);
        /********************************************************** */

        // inicamos el segundo comprador lo inicio con el inicio de mi tabla, para la demas vueltas.
        // segundoComparador = aux_inicioTabla;
        // indiceTabalaActual = aux_inicioTabla;
        // while (segundoComparador != NULL || cambio == 1)
        // {
        //     cambio = 0;
        //     segundoComparador = aux_inicioTabla;

        //     while (cambio == 0)
        //     {
        //         if (segundoComparador == NULL)
        //         {
        //             break;
        //         }
        //         else if (indiceTabalaActual->distanciaMasCorta < segundoComparador->distanciaMasCorta || indiceTabalaActual->distanciaMasCorta == segundoComparador->distanciaMasCorta)
        //         {
        //             segundoComparador = segundoComparador->sig;
        //         }
        //         else
        //         {
        //             indiceTabalaActual = segundoComparador;
        //             cambio = 1;
        //         }
        //     }
        // }

        // printf("%c", indiceTabalaActual->indiceTabla->identificador);

        // ya tengo el nodo con la distancia mas corta,
    }

    // regresara la tabla con todas las distiancias mas cortas
    return (inicio_tabla);
}

// funciones que para establecer los cambos dentro de la tabala como la de inciar la tabala y agregar mas elementos dentro de la tabala

// inicar o crear nuestra tabla

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

/*********************************************** */
// funcion que crea nuestra tabla, asigna como distanica mas corta en 0 nuestro nodo incial y los demas en "INF"

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
                // porque pongo lo mismo que arriba, porque cunado entra en efecto tabla sera igual a NULL
                // por lo que puedeo poner eso

                nodo_agregar = aux_cola_nodos_visitar->nodo;

                if (nodo_agregar->identificador != nodo_inicio)
                {
                    aux_cola_nodos_visitar = aux_cola_nodos_visitar->sig;
                }
                else
                {
                    aux_inicioTabla = crear_tabla_inicio(nodo_agregar, 1);
                    // por lo que ahora neceistmoas restablecer auxListaNodos
                    aux_cola_nodos_visitar = respaldo_global_cola_nodos_visitar;
                    break;
                }
            }
            if (aux_cola_nodos_visitar == NULL)
            {
                // quier decir que no se conetro por lo que volvemos de donde nos llamaron
                return inicio_tabla;
            }
        }
    }

    return (aux_inicioTabla);
}

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
            // primero debemos comprar si aun no se ha llegado alf inal, si se llega al final quiere deicri que hubieron cambios o puede haber un error, por lo que salimo

            if (segundoComparador == NULL)
            {
                break;
            }
            if (aux_inicioTabla->distanciaMasCorta < segundoComparador->distanciaMasCorta || aux_inicioTabla == segundoComparador)
            {
                // neceito comparar nodos de tabla cuyo nodos ded Nodo no han sido completados, en el diagrama que aparezcan en forma de gris

                segundoComparador = segundoComparador->sig;
            }
            else
            {
                // en cunalquier nodo que sea menor va a parar y mirara, pero por ejemplo los nodos que ya han sido proecesados que ya estan establecidos que essos son los menores y provienen de X nodo, se dentrera en el, por lo que neceisot verificar que ese nodo no este procesado

                if (segundoComparador->indiceTabla->NodoCompletado == 0)
                {
                    // si es igual a cero osea, el nodo no ha completado por lo que podemos asignarlo o compararlo
                    aux_inicioTabla = segundoComparador;
                }
                else
                {
                    // el otro caso, es como en el ejemplo que D tiene como nodo adyacente A, pero como se mencionod, culquier nodo que ya ha sido comletado puede que tenda un valor menor, por lo que si ese nodo ya ha sido compleado, por lo que no se puede asignar o comprar.

                    // por lo que hacemos esseguir al siguiente nodo
                    segundoComparador = segundoComparador->sig;
                }
            }
        }
    }

    return (aux_inicioTabla);
}

struct tablaDijkstra *anlaizando_nodos_adyacentes(struct tablaDijkstra *nodo_mas_chico, struct tablaDijkstra *inicio_tabla, struct Grafo *nodos_adyacentes)
{
    struct Grafo *aux_nodos_adyacentes = nodos_adyacentes;
    struct tablaDijkstra *aux_inicio_tabla = inicio_tabla;
    struct tablaDijkstra *nodo_adyacente_tabajaDij = NULL;
    int distancia;
    while (aux_nodos_adyacentes != NULL)
    {
        // aux_inicio_tabla = inicio_tabla;
        // primero nececito buiscar el nodo con el cual dentro de la tabla por ejemplo A esta conectado en la lisdya de adyacencias
        if (aux_inicio_tabla == NULL)
        {
            break;
        }
        if (aux_inicio_tabla->indiceTabla == aux_nodos_adyacentes->nodo)
        {
            if (aux_nodos_adyacentes->nodo->NodoCompletado == 0)
            {
                nodo_adyacente_tabajaDij = aux_inicio_tabla;
                // aqui mismo hacemo el analisis porque ocupamos el while para los sigueintes nodos.
                distancia = nodo_mas_chico->distanciaMasCorta;
                distancia = distancia + aux_nodos_adyacentes->pesoArista;

                if (distancia < nodo_adyacente_tabajaDij->distanciaMasCorta)
                {
                    // aqui etablecemos que nodo_mas_chico es nu nodo previo y cambiamos el peos
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

    // if (nodo_adyacente_tabajaDij == NULL)
    // {

    //     // esto que me quiere decir, que todos sus nodos adyacentes ya han sido procesados por lo que no queda mas por ahcer por lo que mandamso el inicio de nuevo

    //     return (inicio_tabla);
    // }
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

        // if (aux_nodo_segundo != NULL)
        // {
        //     nodo_adyacente = pila->indice_tabla->indiceTabla;
        //     while (nodo_adyacente != aux_nodo_segundo->nodo)
        //     {
        //         aux_nodo_segundo->siguiente_nodo_adyacente->siguiente_nodo_adyacente;
        //     }
        //     valor += aux_nodo_segundo->pesoArista;
        // }
        // else
        // {
        //     break;
        // }
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
