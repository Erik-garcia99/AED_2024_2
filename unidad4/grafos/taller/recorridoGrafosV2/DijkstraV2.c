
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
    /// struct Nodo *sigLista; // enlaza al sigueitne nodo dentro de la lista de adyacencia
    //_--------------------
    /*SI HACEMOS otra estruucutra, esto porque
    en el grafo qeu tenemos A es el que nos esta cagando todo bien maciso el palo, en que sentido, si lo hacemos asi, lo que pasara es que el el peso que va de A y D se va a modificar, por lo que podemos hacer alguna otra estruuctra, la cual, que comportamiento deveria de tener?
    int peso;              // el peso de la arista
    int distanciaMasCorta; // este es para dijstra
    //------------------------*/
    // struct Adyacentes *sigueinteAdyacente;
    int NodoCompletado; // cunaod ya se visiuto a todos sus nodos adyacentes por lo que ahora es pasarlo a la lista de nodos visitados
    int visitado;       // este man es cunado es nodo adyacente y ya se visitao pero el nodo del indice aun no se ha completado
    // struct Nodo *nodoPrevio;
    struct Grafo *nodos_adyacentes;
    struct Nodo *sigueinteDirectorio;
};

// esta y las funciones que son de este tipo quedaran igual, pero se modificaran para que tengan peso por lo que esta escturua sera borrada
struct Adyacentes
{
    struct Nodo *nodo;
    struct Adyacentes *sigueinte;
};
// lo que hace adyacentes quiero que lo haga grafo
/*este sera ya cunado una al grafo por lo qeu debe ser modificado*/
struct Grafo
{
    // aqui se tendra 2 pesos el peso de la arita como el peso de la distancia mas corta de Dijkstra

    // esta esturcutra su inica funcion que tiene es poder crear tal vez crear 2 conexiones con diferentes pesos a un solo nodo. en especial por la conexion de D y A.
    struct Nodo *nodo; // el nodo general a este nodo es alq ue se tiene que hacer referencia tanto con la tabala, como en la lista de adyacencia como los nodos adyacentes
    // struct Adyacentes *sigueinteAdyacente;
    //  struct Nodo *sigueinteDirectorio;
    // struct directorioAdyacentes *nodoSiguienteAdyacente;
    int pesoArista;
    // struct Grafo *siguienteListaAdy;
    struct Grafo *siguiente_nodo_adyacente;
};

// struct directorioAdyacentes
// {
//     struct Nodo *nodo;
//     struct directorioAdyacentes *sigueinteIndice;
// };

struct nodosVisitador_visitar
{
    struct Nodo *nodo;
    struct nodosVisitador_visitar *sig;
};

struct tablaDijkstra
{
    struct Nodo *indiceTabla;
    struct Nodo *NodoPrevio;
    int distanciaMasCorta;
    struct tablaDijkstra *sig;
};
// prototipos

/********************************************** */
// inicio y comienzo de direcotrios de lista de adyacencia:
struct Nodo *crear_directorio_lista_adyacencia(char identificador);
struct Nodo *agregar_directorio_lista_adyacencia(struct Nodo *inicio, char identificador);

/**********************************************/
// ahora toca empezaar a a hacer el grafo, hacer conexiones y asignar pesos en  los vertices entre nodos.
// porque las 2 van a recibir esto, porque primero se debe de crear la memoria dinamica para poder hacer las conexiones, la otra solo iterara hasta encontrasr el ultimo

// este crera el nodo, crearea la estrucutura del nodo adyacente, por lo que este nodo debe de recibir el peso
struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazado_adyacente, int peso);

struct Grafo *agregar_enlace_conexion(struct Grafo *nodo_inicio_directorio, struct Nodo *nodo_enlazado_adyacente, int peso);
/**********************************************/
// esta estrucutura se encarga de encapsular las 2 funciones de arriba en donde solo se solicita el directorio de listas de adyacencias asi como el nombre de los identificadores de los nodos que tinene relacion y el peso de su asrita
struct Grafo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazada, int peso, struct Grafo *inicio_grafo);
/**********************************************************************/

// struct Nodo *crearIndiceLSTADY(char indentificador);

// struct Nodo *agregarIndiceLSTADY(struct Grafo *inicio, char identificador);

// struct Nodo *agregarIndiceLSTADY(struct Nodo *inicio, char identificador);
// struct directorioAdyacentes *crearDirectorioAdyacentes(char Identificador);

// struct Nodo *enlazarNodos(struct Nodo *inicio, char nodoIndice, char enlazado, int peso);

struct Adyacentes *crearListaAdyacentes(struct Nodo *indice);

struct Adyacentes *agregarListaAdyacentes(struct Adyacentes *inicio, struct Nodo *nodo);

int main()
{

    // struct Nodo *listAdyacencia = NULL; //<- repersentacion de mi grafo

    struct Nodo *listAdyacencia = NULL;

    // cremaos los infices de nuetra lista de adyacencias
    // char nodos[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char nodos[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};

    /*for (int i = 0; i < 20; i++)
    {
        if (listAdyacencia == NULL)
        {
            listAdyacencia = crearIndiceLSTADY(nodos[i]);
        }
        else
        {
            listAdyacencia = agregarIndiceLSTADY(listAdyacencia, nodos[i]);
        }
    }*/

    for (int i = 0; i < 6; i++)
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
    struct Grafo *grafo = NULL;

    grafo = establecer_enlace_conexiones(listAdyacencia, 'A', 'D', 85, grafo);
    grafo = establecer_enlace_conexiones(listAdyacencia, 'A', 'D', 30, grafo);
    grafo = establecer_enlace_conexiones(listAdyacencia, 'A', 'B', 100, grafo);
    grafo = establecer_enlace_conexiones(listAdyacencia, 'B', 'A', 100, grafo);
    grafo = establecer_enlace_conexiones(listAdyacencia, 'B', 'E', 40, grafo);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'A', 'D', 10);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'A', 'B', 50);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'A', 'C', 45);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'B', 'D', 15);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'B', 'C', 10);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'C', 'E', 30);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'D', 'E', 15);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'D', 'A', 10);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'E', 'F', 3);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'E', 'C', 35);

    // listAdyacencia = enlazarNodos(listAdyacencia, 'E', 'B', 20);
    // listAdyacencia = enlazarNodos(listAdyacencia, 'E', 'I', 10);

    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );
    // listAdyacencia = enlazarNodos(listAdyacencia, '', '', );

    getchar();

    // cremaos las conexiones de la lista de adyacencia
}

//***********repesentacion del grafo  ***********

/**************************************
 *
 *  crea un la rpresentacion de un nodo, con todas su variables en 0 o NULL

*/

// struct Nodo *crearIndiceLSTADY(char indentificador)
// {
// de primero para la creacion del grafo las distancias y pesos son 0, parejo para todos
// struct Nodo *nuevo;
// nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
// nuevo->identificador = indentificador;
// // nuevo->distanciaMasCorta = 0;
// nuevo->NodoCompletado = 0;
// // nuevo->NodosAdyacentes = NULL;
// // nuevo->NodoAdyacente = NULL;
// nuevo->sigueinteAdyacente = NULL;

// // nuevo->peso = 0;
// // nuevo->sigLista = NULL;
// nuevo->visitado = 0;
// nuevo->nodoPrevio = NULL;
// // nuevo->sigNodoAdyacente = NULL;

// version nuevoa con  grafo

// struct Grafo *nuevo;
// nuevo = (struct Grafo *)malloc(sizeof(struct Grafo));

// nuevo->pesoArista = 0;
// nuevo->siguienteListaAdy = NULL;
// nuevo->nodo = NULL;
// 8*****************

/**otra version*/

//     struct Nodo *nuevo;

//     nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

//     nuevo->identificador = indentificador;
//     nuevo->visitado = 0;
//     nuevo->NodoCompletado = 0;
//     // nuevo->sigueinteAdyacente = NULL;
//     // nuevo->sigueinteDirectorio = NULL;

//     return (nuevo);
// }

// el primer instanica lo que se debe de crear es la el directorio de listas de adyacencias, ya que este contendra todos los nodos y por lo tanto  estara asociado una direccion de memoria para cada nodo, que el cual s debe de relacionar si un nodo esta conectado con el en el grafo

// lo inicia
struct Nodo *crear_directorio_lista_adyacencia(char identificador)
{

    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    nuevo->identificador = identificador;
    nuevo->NodoCompletado = 0;
    nuevo->visitado = 0;
    nuevo->sigueinteDirectorio = NULL;

    return (nuevo);
}

// agrega mas indices en el directorio
// es cola
struct Nodo *agregar_directorio_lista_adyacencia(struct Nodo *inicio, char identificador)
{
    struct Nodo *aux = inicio;
    struct Nodo *nuevo;
    nuevo = crear_directorio_lista_adyacencia(identificador);

    while (aux->sigueinteDirectorio != NULL)
    {
        aux = aux->sigueinteDirectorio;
    }

    aux->sigueinteDirectorio = nuevo;

    return (inicio);
}

/**************************************************************************/

// funciones se relaizarion la conexiones entre los disitntos nodos

struct Grafo *crear_enlace_conexion(struct Nodo *nodo_enlazado_adyacente, int peso)
{
    struct Grafo *nuevo;

    nuevo = (struct Grafo *)malloc(sizeof(struct Grafo));
    nuevo->nodo = nodo_enlazado_adyacente;
    nuevo->pesoArista = peso;
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

    return (nodo_enlazado_adyacente);
}

struct Grafo *inicar_conexiones(struct Nodo *nodo_inicio_directorio, struct Nodo *nodo_enlazado_adyacente, int peso, struct Grafo *grafo)
{
    struct Grafo *nuevo;
    struct Grafo *indice = grafo;
    nuevo = crear_enlace_conexion(nodo_enlazado_adyacente, peso);
    grafo->nodo = nodo_inicio_directorio;
}

/**********************************************************************/
struct Grafo *establecer_enlace_conexiones(struct Nodo *lista_de_directorios_adyacentes, char nodo_Inicio, char nodo_enlazada, int peso, struct Grafo *inicio_grafo)
{
    struct Nodo *direccion_indice = lista_de_directorios_adyacentes;
    struct Nodo *direccion_enlazado = lista_de_directorios_adyacentes;
    struct Grafo *enlace = inicio_grafo;

    // buscamos los nodos a enlazar

    while (direccion_indice->sigueinteDirectorio != NULL)
    {
        if (direccion_indice->identificador != nodo_Inicio)
        {
            direccion_indice = direccion_indice->sigueinteDirectorio;
        }
        else
        {
            break;
        }
    }

    while (direccion_enlazado->sigueinteDirectorio != NULL)
    {
        if (direccion_enlazado->identificador != nodo_enlazada)
        {
            direccion_enlazado = direccion_enlazado->sigueinteDirectorio;
        }
        else
        {
            break;
        }
    }

    // por si acaso no se ecuentra el nodo, se hara lo sigueinte

    if (direccion_indice->sigueinteDirectorio == NULL && direccion_indice->identificador != nodo_Inicio)
    {
        struct Nodo *nuevo;
        nuevo = agregar_directorio_lista_adyacencia(lista_de_directorios_adyacentes, nodo_Inicio);
        // vuelve a llamar a la funcion, porque ahora si estara este nodo
        enlace = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazada, peso, enlace);
    }

    if (direccion_enlazado->sigueinteDirectorio == NULL && direccion_enlazado->identificador != NULL)
    {
        struct Nodo *nuevo;
        nuevo = agregar_directorio_lista_adyacencia(lista_de_directorios_adyacentes, nodo_enlazada);
        enlace = establecer_enlace_conexiones(lista_de_directorios_adyacentes, nodo_Inicio, nodo_enlazada, peso, enlace);
    }

    // en este punto ya entoncre los nodos que son los que voy a unir, el idnice y el nodo el cual se unira

    if (enlace == NULL)
    {
        enlace = inicar_conexiones(direccion_indice, direccion_enlazado, peso, enlace);
    }
    else
    {
    }
}
/**********************************************************************/

/*

    agrega un nuevo indice al directorio de lista de adyacencia

     ____
    | A |
    ----
      |  -> esta conexion es la que estaria haceindo en esta funcion, para tener referencia hacia el nuevo nodo que se esta creando
      v
     ____
    | B |
    ----


 */

/*struct Grafo *agregarIndiceLSTADY(struct Nodo *inicio, char identificador)
{
    // struct Nodo *aux = inicio;
    // struct Nodo *nuevo;
    // nuevo = crearIndiceLSTADY(identificador);

    // while (aux->sigLista != NULL)
    // {
    //     aux = aux->sigLista;
    // }

    // aux->sigLista = nuevo;

    /* version nueva con estrucuturda Grafo*/

// struct Grafo *aux = inicio;
// struct Grafo *nuevo;
// nuevo = crearIndiceLSTADY(identificador);
// while (aux->siguienteListaAdy != NULL)
// {
//     aux = aux->siguienteListaAdy;
// }

// aux->siguienteListaAdy = nuevo;
/****************************
// terceera version en donde Nodo tiene el apuntador al sigueinte indice del directorio de lista de adyacencia

// struct Nodo *aux = inicio;
// struct Nodo *nuevo = crearIndiceLSTADY(identificador);

// while (aux->sigueinteDirectorio != NULL)
// {
//     aux = aux->sigueinteDirectorio;
// }

// aux->sigueinteDirectorio = nuevo;

********************
struct Nodo *aux return (inicio);
*******************
}*/

/******************************************************************** */
/*estas funcion de lo que se encargan es de inicar y agregar a los indices del directorio de lista de adyacencias los nodos adyacentes, en otras palabra enpieza a crear las ariatas*/
struct Adyacentes *crearListaAdyacentes(struct Nodo *indice)
{
    struct Adyacentes *nuevo;
    nuevo = (struct Adyacentes *)malloc(sizeof(struct Adyacentes));

    nuevo->nodo = indice;
    nuevo->sigueinte = NULL;

    return (nuevo);
}

struct Adyacentes *agregarListaAdyacentes(struct Adyacentes *inicio, struct Nodo *nodo)
{

    struct Adyacentes *nuevo;
    nuevo = crearListaAdyacentes(nodo);
    struct Adyacentes *aux = inicio;
    while (aux->sigueinte != NULL)
    {
        aux = aux->sigueinte;
    }

    aux->sigueinte = nuevo;

    return (inicio);
}
/********************************************************************************** */

/**funccion enlazada los nodos como indices en el direcorio con los nodos que estan repersentados en el grafo
// como la unon la arista ya contiene un peso dentreo de si, por lo que la funcion deberia e ser de tipo Grafo?

struct Grafo *enlazarNodos(struct Nodo *inicioDIrectorio, char identificadorInicio, char IdentificadorUnion, int peso)
{
    // nates que nada necesito los paunadores de mis 2 nodos, loss cuales se unirann pero cada nodo se buscara dentro del indice de adyacencias, porque para esto primero creamos las direcciones de memoria para cada uno

    struct Nodo *incio = inicioDIrectorio;
    struct Nodo *enlazado = inicioDIrectorio;
    struct Grafo *grafo = NULL;
    struct Adyacentes *enlace;

    /*primero debemso buscar a nuestro nodo indice, el cual es el indice de nuestra lista de adyacencias para despues enlzar los nodos adyacentes a el

    // porque si en sigueinte es diferente a NULL, porque si esta inicio!=NULL, llegara  aNULL y el apuntador se hbra perdido, lo que quiero es poder agregar mas indices, por lo que necesito guardar el ultimo indice que es cunado en ese nodo su apuntador es NULL.
    while (incio->sigueinteDirectorio != NULL)
    {
        if (incio->identificador != identificadorInicio)
        {
            incio = incio->sigueinteDirectorio;
        }
        else
        {
            // si lo encontramso, tan solo salimos del ciclo
            break;
        }
    }

    while (enlazado->sigueinteDirectorio != NULL)
    {
        if (enlazado->identificador != IdentificadorUnion)
        {
            enlazado = enlazado->sigueinteDirectorio;
        }
        else
        {
            // aplica lo mismo.
            break;
        }
    }

    // si llegamos al ultimo nodo yh aparte no es el nodo que buscamos quiere deir qque no esta por lo que debemos crar yune nelzar el nodo
    if (incio->sigueinteDirectorio == NULL && identificadorInicio != incio->identificador)
    {
        struct Nodo *nuevoEnlace = NULL;
        // primero necesito tener una direccion
        nuevoEnlace = agregarIndiceLSTADY(inicioDIrectorio, identificadorInicio);
        // vualve a llaamr a eta funcion, con recursividad
        incio = enlazarNodos(inicioDIrectorio, identificadorInicio, IdentificadorUnion, peso);
    }
    if (enlazado->sigueinteDirectorio == NULL && IdentificadorUnion != enlazado->identificador)
    {
        // hago lo mismo. pero ahora con el nodo que quiero unir
        struct Nodo *nuevoEnlace = NULL;
        nuevoEnlace = agregarIndiceLSTADY(inicioDIrectorio, IdentificadorUnion);

        // hacremo recursividad

        incio = enlazarNodos(inicioDIrectorio, identificadorInicio, IdentificadorUnion, peso);
    }

    // si no aplica los otros 2, quiere decir que si encoentro el nodo al cual quiere unir
    enlace = grafo->sigueinteAdyacente;

    if (grafo == NULL)
    {
        // crear
        grafo = crearConexion(incio, enlazado, peso);
    }
    else
    {
        // agregar
    }
}*/

// funcion para crear la primrea conexion a un indice

// struct Grafo *crearConexion(struct Nodo *nodoDirectorio, struct Nodo *nodoEnladazo, struct Adyacentes *listaAsociado, int peso)
// {

//     struct Grafo *nuevo;

//     nuevo = (struct Grafo *)malloc(sizeof(struct Grafo));

//     nuevo->pesoArista = peso;
// }

// funcion para crear y agregar indices de tipo GRAFO

// para crear la lista de adyacencia,debemos enlazar ese identificador con l direccion que se encuentra dentro de los idnices de la lita de adyacencia

// struct Nodo *enlazarNodos(struct Nodo *inicio, char nodoIndice, char enlazado, int peso)
// {

//     struct Nodo *nodoIndeice = inicio;
//     struct Nodo *enlazadar = inicio;
//     struct Adyacentes *nuevo;
//     int encontrado = 0;
//     /*primero debemso buscar a nuestro nodo indice, el cual es el indice de nuestra lista de adyacencias para despues enlzar los nodos adyacentes a el*/
//     while (nodoIndeice->sigLista != NULL)
//     {
//         if (nodoIndeice->identificador != nodoIndice)
//         {
//             nodoIndeice = nodoIndeice->sigLista;
//         }
//         else
//         {
//             // cunado enceintre el nodod donde el identificador sea igual al que se paso por parametros entonces cortamso el bucle,
//             break;
//         }
//     }

//     // puede que el nodo que se quiere ingresar no este dentro de la lista por lo que podriamos agergarlo, como ahora nos enocntrados el el ultimo elemento de la lista
//     while (enlazadar->sigLista != NULL)
//     {

//         if (enlazadar->identificador != enlazado)
//         {
//             enlazadar = enlazadar->sigLista;
//         }
//         else
//         {
//             break;
//         }
//     }

//     if (nodoIndeice == NULL || enlazadar == NULL)
//     {
//         struct Nodo *nuevo;

//         if (nodoIndeice == NULL)
//         {
//             // agrego a la lista el nuevo nodo entonces lo que hacemos es recursividad, por lo que a la sigueinte vuelta deberia de tener ese nodo creado con el dientificador.
//             nuevo = agregarIndiceLSTADY(inicio, nodoIndice);
//             inicio = enlazarNodos(inicio, nodoIndice, enlazado, peso);
//         }
//         else
//         {
//             nuevo = agregarIndiceLSTADY(inicio, enlazado);
//             inicio = enlazarNodos(inicio, nodoIndice, enlazado, peso);
//         }
//     }

//     nuevo = nodoIndeice->sigueinteAdyacente;

//     if (nuevo != NULL)
//     {
//         while (nuevo->sigueinte != NULL)
//         {
//             nuevo = nuevo->sigueinte;
//         }
//         // funcion para agregar como adyacecia

//         nuevo = agregarListaAdyacentes(nuevo, enlazadar);
//         nodoIndeice->sigueinteAdyacente = nuevo;
//     }
//     else
//     {
//         nuevo = crearListaAdyacentes(enlazadar);
//         nodoIndeice->sigueinteAdyacente = nuevo;
//     }

//     return (inicio);

//     // while (nodoIndeice->sigueinteAdyacente != NULL && nodoIndeice->sigueinteAdyacente->nodo != NULL)
//     // {
//     //     nodoIndeice->sigueinteAdyacente = nodoIndeice->sigueinteAdyacente->sigueinte;
//     // }

//     // nodoIndeice->sigueinteAdyacente->nodo = enlazadar;
//     // return (inicio);
// }

//****************************representacion del grafo****************************

// como antes primero debemos crear nustra lista de adyacencias

// ----------crear nuestro grafo--------------

// ------------cosas a tomar en cuent a

/*
para la creacion de mi grafo asi como de mi tabal de dikjstra

el nodo que representa un nodo en mi grafo debe tener la misma direccion que el indice que esta en la

por lo que los nodos que ason adyacentes al indice de mi lista, deben eapuntar a quella direccion en donde esta guaradado con el mismo dientificador.

*/