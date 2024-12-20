/*garcia chavez erik 01275863
algoritmo y estructura de datos
practica algoritmos de ordenamineto */

#include <stdio.h>
#include <stdlib.h>

// lo haremos de manera min-heap para evitarnos dolores de cabeza en los idnices del arreglo.
struct Heap
{
    int dato;
    struct Heap *izq;
    struct Heap *drch;
};

struct Heap *creacionArbol(struct Heap *inicio, int *datos, int tamanio);
struct Heap *inicarArbol(int dato);

struct Heap *agregar_arbol(struct Heap *inicio, struct Heap *moviemineto, int dato, int control);
// va a llevar el arbol y el tamanio de arreglo, no quiero una pila mas grande, estaria desperdiciendo memmoetia.
int colaDatos(struct Heap *raiz, int tamanio);

int main(void)
{
    /*en que consiste heap sort.  */
    int datos[10] = {42, 7, 19, 85, 23, 56, 34, 12, 91, 67};

    // en heap sort, la creacion del arbol binario, se hace de manera secuncial, para tener un arbol completo, (creo o lleno, no me acuerdo muy de aqullas), por lo que si es menor va del lado izquirda y mayor del lado derecho, eso ya no cuenta en heap sort, se van ir agregando tratando de llenar todos los niveles con los datos que hay en el arreglo
    struct Heap *heap = NULL;

    // como saber el tamanio de un arreglo, en este momento yo claramente se que el arreglo mide 10, pero esto igual puede haber sido ingresado por el usuario. no se cuantos elementos el usuario va a querer.

    int tamanio = sizeof(datos) / (sizeof(datos[0]));
    // el tamanio se obtiene obteniendo el tamano total del arrelgo, este nos dara el tamano total den bytes del arreglo, en un caso ideal el arreglo estara lleno,y lo divido entre el tamano en bytes de algun dato de el, si es entero auqnue tenga 1 o el maximo numero que se puede represnetar en C, el tamano de una vairbale entera siempre sera la misma. lo cual nos dara un numero entero.

    heap = creacionArbol(heap, datos, tamanio);
}

struct Heap *creacionArbol(struct Heap *inicio, int *datos, int tamanio)
{
    struct Heap *aux = inicio;
    for (int i = 0; i < tamanio; i++)
    {
        if (aux == NULL)
        {
            aux = inicarArbol(datos[i]);
        }
        else
        {
            aux = agregar_arbol(aux, NULL, datos[i], 2);
        }
    }

    return (inicio);
}

struct Heap *inicarArbol(int dato)
{
    struct Heap *nuevo;
    nuevo = (struct Heap *)malloc(sizeof(struct Heap));
    nuevo->dato = dato;
    nuevo->drch = NULL;
    nuevo->izq = NULL;

    return (nuevo);
}

struct Heap *agregar_arbol(struct Heap *inicio, struct Heap *moviemineto, int dato, int control)
{
    struct Heap *raiz = inicio;
    struct Heap *nuevo;
    struct Heap *mov = moviemineto;
    int agregado = 0;
    nuevo = inicarArbol(dato);

    // ahoraa buscar en donde lo voy a guardar
    while (raiz != NULL)
    {

        if (mov == NULL)
        {
            // quiere decir que no me he movido dentro del arbol
            // vacio o tiene algo dentro de el.
            if (raiz->drch == NULL && raiz->izq == NULL)
            {
                raiz->drch = nuevo;
                return (inicio);
            }
            else if (raiz->drch != NULL && raiz->izq == NULL)
            {
                raiz->izq = nuevo;
                return (inicio);
            }
            else
            {
            }
        }

        // antes entrasr aqui necesito ver si el apntador que se movera sobre la raiz esta
    }
}