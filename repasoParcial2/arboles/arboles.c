// repaso de arboles

#include <stdio.h>
#include <stdlib.h>

struct Arbol
{
    int numero;
    int raiz;
    int ya_impreso;
    int procesado;
    struct Arbol *izq;
    struct Arbol *drch;
};
struct Cola
{
    int dato;
    struct Cola *sig;
};

struct Arbol *crear_raiz(int numero);
struct Arbol *agregar_al_arbol(struct Arbol *raiz, int dato);
struct Arbol *eliminar_nodo(struct Arbol *raiz, int dato);
struct Cola *crearCola(int dato);
struct Cola *agregar_cola(struct Cola *inicio, int dato);
struct Cola *eliminar_cola(struct Cola *inicio, int dato);
void limpiarRecorrido(int dato, struct Arbol *raiz);
void postOrden(struct Arbol *raiz, struct Arbol *respaldo);

// struct Arbol *preOrden(struct Arbol *raiz, struct Arbol *respaldo);
// struct Arbol *inOrden(struct Arbol *raiz, struct Arbol *respaldo);

void preOrden(struct Arbol *raiz, struct Arbol *respaldo);
void inOrden(struct Arbol *raiz, struct Arbol *respaldo);

int main(void)
{
    struct Arbol *raiz = NULL;
    struct Arbol *limpieza = NULL;
    struct Cola *cola = NULL;
    struct Cola *cola_aux = NULL;
    int dato, opc;

    do
    {
        printf("\n*****ARBOLES BINARIOS*****\n");
        printf("1)ingresar al arbol \n");
        printf("2)Eliminar Nodo \n");
        printf("3) recorrido preOrden ( R - I - D )\n");
        printf("4) recorrido inOrden ( R - I - D )\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("ingrese el dato: ");
            scanf("%d", &dato);
            if (raiz == NULL)
            {
                raiz = crear_raiz(dato);
            }
            else
            {
                raiz = agregar_al_arbol(raiz, dato);
            }
            // la cola funciona, mas uqe nada para limpiar las banderas, porque cada vez que yo quiera hacer un recorrido necesito que todas las banderas, se vayan a 0, neceario que sea una cola, no, puede ser una pila, pero quiero que tenga el orden en como fueron entrando.
            if (cola == NULL)
            {
                cola = crearCola(dato);
            }
            else
            {
                cola = agregar_cola(cola, dato);
            }

            break;
        case 2:
            if (raiz != NULL)
            {
                printf("\n ingrese el dato: ");
                scanf("%d", &dato);

                raiz = eliminar_nodo(raiz, dato);
            }
            else
            {
                printf("\n el arbol se encunetra vacio");
            }
            if (cola != NULL)
            {
                cola = eliminar_cola(cola, dato);
            }

            break;

        case 3:
            // primero antes que nada debemos limpiar todo el arbol
            cola_aux = cola;
            limpieza = raiz;
            while (cola_aux != NULL)
            {
                limpiarRecorrido(cola_aux->dato, raiz);
                cola_aux = cola_aux->sig;
            }
            // marcamos el primero elemoento como la raiz
            raiz->raiz = 0;
            // raiz = preOrden(raiz, raiz);
            preOrden(raiz, raiz);

            break;

        case 4:
            cola_aux = cola;
            limpieza = raiz;
            while (cola_aux != NULL)
            {
                limpiarRecorrido(cola_aux->dato, raiz);
                cola_aux = cola_aux->sig;
            }
            raiz->raiz = 0;
            inOrden(raiz, raiz);
            break;
        }

    } while (opc != 100);
}

struct Arbol *crear_raiz(int numero)
{
    struct Arbol *aux;
    aux = (struct Arbol *)malloc(sizeof(struct Arbol));
    aux->numero = numero;
    aux->raiz = 10;
    aux->ya_impreso = 0;
    aux->procesado = 0;
    aux->drch = NULL;
    aux->izq = NULL;

    return aux;
}

// un arbol binario como ingresa datos a el, la logica es sencilla, si el nodo a ingresar es mayor que el nodo padre va del lado derecho, de caso contrario, que sea mas chico va del lado izquierd

struct Arbol *agregar_al_arbol(struct Arbol *raiz, int dato)
{
    struct Arbol *aux_raix = raiz;
    struct Arbol *nuevo = crear_raiz(dato);

    // el while tiene como condicion que el ciclo contoura siempre y cunado aux sea disitinto a NULL, osea que aun no ha llegado al final de algun lado del arbol y comprueba en la msima condicion que el numero que se ingreso sea diferente a algun dato dentro del arbol, si el dato se repite y ya esta dentro del arbol, el recorrido ques seguiria es el mismo, por lo que llegara al nodo y mirara que ambos en su parte numero son el mimos, por lo que sale de la codicion dado que se esta tratando de una operacion AND
    while (aux_raix != NULL && nuevo->numero != aux_raix->numero)
    {
        if (nuevo->numero > aux_raix->numero)
        {
            if (aux_raix->drch == NULL)
            {
                // aqui ira el nuero nodo
                aux_raix->drch = nuevo;
                break;
            }
            else
            {
                aux_raix = aux_raix->drch;
            }
        }
        else
        {
            // en caso que no sea mayor quiere decir que es emnor

            if (aux_raix->izq == NULL)
            {
                aux_raix->izq = nuevo;
                break;
            }
            else
            {
                aux_raix = aux_raix->izq;
            }
        }
    }
    return (raiz);
}

// haremos 2 uno como eliminacion de predecesor y otor como sucesor
struct Arbol *eliminar_nodo(struct Arbol *raiz, int dato)
{
    struct Arbol *aux_raiz = raiz;

    /*hay disitintas formas de eliminar un nodo dentro de un arbol
    -si el nodo a eliminar es una hoja simplemente se aplica el free
    -si el nodo a elimnar tiene 1 hijos, el padre del nodo a elimnar deberia de apuntar al nodo hija del nodo a elimnar
    -si el nodo tiene 2 hijos en este caso estaria aplicando
    --eliminacion por sucesion - numero mas grande (del sub arbol drecheo el nodo mas la izquiera )
    --eliminacion por predecesor - numero mas chicos  (del sub arbol izquierdo el mas a la derecha)*/

    // priemro cunado sea hpja o solo tenga un 1 hijos
    // en dicho necesitaremos 2 apuntadores, el segundo apuntador sera el padre del nodo a eliminar
    // dado qeu si eliminamos el nodo asi nomas perdemos lo sdemas nodos del hijo que tenia.

    struct Arbol *previo = aux_raiz;
    struct Arbol *nodoEliminar = NULL;
    struct Arbol *nodoRemplazo = NULL; // este es en el caso de tener 2 hijos
    struct Arbol *nodoRemplazoPrevio = NULL;
    // en caso que sea raiz igual sera un caso especial

    // primero debemos buscar el nodo que queremos eliminar
    while (previo != NULL)
    {
        if (dato > previo->numero)
        {
            if (previo->drch != NULL)
            {
                if (previo->drch->numero == dato)
                {
                    nodoEliminar = previo->drch;
                    if (nodoEliminar->drch == NULL && nodoEliminar->izq == NULL)
                    {
                        previo->drch = NULL;
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else if (nodoEliminar->izq != NULL && nodoEliminar->drch == NULL)
                    {
                        // tiene un solo nodo en el lado izquirdo
                        previo->drch = nodoEliminar->izq;
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else if (nodoEliminar->izq == NULL && nodoEliminar->drch != NULL)
                    {
                        previo->drch = nodoEliminar->drch;
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else
                    {
                        // el nodo tiene 2 hijos, en esta funcion lo haremos mediante el sucesor
                        nodoRemplazo = nodoEliminar->drch;
                        while (nodoRemplazo->izq != NULL)
                        {
                            nodoRemplazoPrevio = nodoRemplazo;
                            nodoRemplazo = nodoRemplazo->izq;
                        }
                        if (nodoRemplazoPrevio == NULL)
                        {
                            // en el caso que cunado giramso a la drecha, este es su unico hijo, entonces la operacoin solo es de intercambio

                            nodoRemplazo->izq = nodoEliminar->izq;
                            previo->drch = nodoRemplazo;
                            free(nodoEliminar);
                            return (raiz);
                        }
                        else
                        {
                            // en este caso tine al menos 1 nodo mas a la izquirda
                            nodoRemplazoPrevio->izq = nodoRemplazo->drch;
                            nodoRemplazo->izq = nodoEliminar->izq;
                            nodoRemplazo->drch = nodoEliminar->drch;
                            previo->drch = nodoRemplazo;
                            free(nodoEliminar);
                            return (raiz);
                        }
                    }
                }
                else
                {
                    previo = previo->drch;
                }
            }
            else
            {
                printf("el dato no se cnuentra ");
                return (raiz);
            }
        }
        else if (dato < previo->numero)
        {
            if (previo->izq != NULL)
            {
                // en este caso hay algo, pero pude que no sea el dato, por lo que debemos conocerlo, manteniednondonos un nodo anterior a ese

                if (previo->izq->numero == dato)
                {
                    nodoEliminar = previo->izq;

                    if (nodoEliminar->izq == NULL && nodoEliminar == NULL)
                    {
                        previo->izq = NULL; // debo indicar NULL, porqeu este aun apunta a algo que habia ahi, en compialdor redirecciona a algo, basura solamente, por lo que debemos inicar que ahora punte a NULL
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else if (nodoEliminar->izq != NULL && nodoEliminar->drch == NULL)
                    {
                        previo->izq = nodoEliminar->izq;
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else if (nodoEliminar->izq == NULL && nodoEliminar->drch != NULL)
                    {
                        previo->izq = nodoEliminar->drch;
                        free(nodoEliminar);
                        return (raiz);
                    }
                    else
                    {
                        nodoRemplazo = nodoEliminar->drch;
                        while (nodoRemplazo->izq != NULL)
                        {
                            nodoRemplazoPrevio = nodoRemplazo;
                            nodoRemplazo = nodoRemplazo->izq;
                        }
                        if (nodoRemplazoPrevio == NULL)
                        {
                            nodoRemplazo->izq = nodoEliminar->izq;
                            previo->izq = nodoRemplazo;
                            free(nodoEliminar);
                            return (raiz);
                        }
                        else
                        {
                            nodoRemplazoPrevio->izq = nodoRemplazo->drch;
                            nodoRemplazo->izq = nodoEliminar->izq;
                            nodoRemplazo->drch = nodoEliminar->drch;
                            previo->izq = nodoRemplazo;
                            free(nodoEliminar);
                            return (raiz);
                        }
                    }
                }
                else
                {
                    previo = previo->izq;
                }
            }
            else
            {
                // peude que el usurio hya ingresado un dato que no esta la lista, por lo que siguio hasta el modo en que deberia haber ingresado pero no hya nada, por lo que debemos decir que el nodo no se eucnuentra en el arbol.
                printf("el dato no se cnuentra ");
                return (raiz);
            }
        }
        else
        {
            // si el dato no es mayor, pero no es menor, en el caso ideal es que son numero enteros positivos, la raiz, esto poruqe puede psar, por como estoy operando la froma de eliinar, de ir desde un arbol anterior a este. por lo que si ingresa y no es mayor ni es menor el dato, quiere decir que es la raiz.

            // esto es algo especial ya que se tendra que modificar la raiz del arbol.
            nodoEliminar = previo;

            if (nodoEliminar->drch == NULL && nodoEliminar->izq == NULL)
            {
                // puede que ibngresp algo a la raiz y lo va a eliminar
                free(nodoEliminar);
                raiz = NULL;
                return (raiz);
            }
            else if (nodoEliminar->drch != NULL && nodoEliminar->izq == NULL)
            {
                // solo tiene 1 hijos
                raiz = nodoEliminar->drch;
                free(nodoEliminar);
                return (raiz);
            }
            else if (nodoEliminar->drch == NULL && nodoEliminar->izq != NULL)
            {
                // tiene solo 1 hijo en la parte izquierda
                raiz = nodoEliminar->izq;
                free(nodoEliminar);
                return (raiz);
            }
            else
            {
                // tiene 2 hijos

                nodoRemplazo = nodoEliminar->drch;
                while (nodoRemplazo->izq != NULL)
                {
                    nodoRemplazoPrevio = nodoRemplazo;
                    nodoRemplazo = nodoRemplazo->izq;
                }
                if (nodoRemplazoPrevio == NULL)
                {
                    nodoRemplazo->izq = nodoEliminar->izq;
                    raiz = nodoRemplazo;
                    free(nodoEliminar);
                    return (raiz);
                }
                else
                {
                    nodoRemplazoPrevio->izq = nodoRemplazo->drch;
                    nodoRemplazo->drch = nodoEliminar->drch;
                    nodoRemplazo->izq = nodoEliminar->izq;
                    free(nodoEliminar);
                    raiz = nodoRemplazo;
                    return (raiz);
                }
            }
        }
    }
}

// recorrrido de arboles, los recorrido de arboles son funciones que van a recorrer todos los nodos de un arbol para eso existen 3 tipos de desto

// recorrido preOrden : R I D
// recorrido inOrden :  I R D
// recorrido postOrden : I D I

// este tipo de reocrrido, se hacen medinate recusrividad.
// struct Arbol *preOrden(struct Arbol *raiz, struct Arbol *respaldo)
void preOrden(struct Arbol *raiz, struct Arbol *respaldo)
{
    struct Arbol *aux = raiz; // me movere sobre aux
    struct Arbol *respaldo_aux = respaldo;

    // if (respaldo_aux->izq->procesado == 1 && respaldo_aux->drch->procesado == 1)
    // {
    //     return (respaldo);
    // }

    if (respaldo_aux->drch->procesado != 1 || respaldo_aux->izq->procesado != 1)
    {
        if (respaldo_aux->raiz == 0 && respaldo_aux->procesado != 1)
        {
            if (respaldo_aux->ya_impreso == 0)
            {
                printf("%d -> ", aux->numero);
                aux->ya_impreso = 1;
                respaldo_aux->procesado = 1;
            }
            preOrden(aux->izq, respaldo);
        }

        if (aux->izq != NULL && aux->izq->procesado == 0)
        {
            // antes de hacer cualquier ocas necesito saber si hay algo a la izquierda
            if (aux->ya_impreso == 0)
            {
                printf("%d -> ", aux->numero);
                aux->ya_impreso = 1;
            }

            preOrden(aux->izq, respaldo);
        }
        else if (aux->drch != NULL && aux->drch->procesado == 0)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d -> ", aux->numero);
                aux->ya_impreso = 1;
            }
            preOrden(aux->drch, respaldo);
        }

        else if (aux->izq == NULL && aux->drch == NULL)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d ->", aux->numero);
                aux->ya_impreso = 1;
                aux->procesado = 1;
            }
            preOrden(respaldo_aux, respaldo); // volvemos al inciio
        }

        else if (aux->izq != NULL && aux->drch == NULL && aux->izq->procesado == 1)
        {
            aux->procesado = 1;
            preOrden(respaldo, respaldo);
        }
        else if (aux->izq == NULL && aux->drch != NULL && aux->drch->procesado == 1)
        {
            aux->procesado = 1;
            preOrden(respaldo, respaldo);
        }

        else if (aux->drch != NULL && aux->izq != NULL && aux->drch->procesado == 1 && aux->izq->procesado == 1)
        {
            aux->procesado = 1;
            preOrden(respaldo_aux, respaldo);
        }
    }
}

// struct Arbol *inOrden(struct Arbol *raiz, struct Arbol *respaldo)
void inOrden(struct Arbol *raiz, struct Arbol *respaldo)
{
    struct Arbol *aux = raiz;
    struct Arbol *respaldo_aux = respaldo;

    // if (respaldo_aux->procesado == 1)
    // {
    //     return (respaldo);
    // }

    // else if (respaldo_aux->drch->procesado != 1 || respaldo_aux->izq->procesado != 1)
    if (respaldo_aux->procesado != 1)
    {
        // if (respaldo_aux->izq->procesado == 0)
        // {
        //     aux = inOrden(aux->izq, respaldo_aux);
        // }

        if (aux->izq != NULL && aux->izq->procesado != 1)
        {
            inOrden(aux->izq, respaldo);
        }

        else if (aux->izq != NULL && aux->izq->procesado == 1)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d ->", aux->numero);
                aux->ya_impreso = 1;
            }
            if (aux->drch != NULL && aux->drch->procesado != 1)
            {
                inOrden(aux->drch, respaldo);
            }
            else
            {
                aux->procesado = 1;
                inOrden(respaldo, respaldo);
            }
        }
        else if (aux->izq == NULL && aux->drch != NULL && aux->drch->procesado != 1)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d ->", aux->numero);
                aux->ya_impreso = 1;
            }
            inOrden(aux->drch, respaldo);
        }

        else if (aux->drch == NULL && aux->izq == NULL)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d ->", aux->numero);
                aux->ya_impreso = 1;
                aux->procesado = 1;
            }
            inOrden(respaldo, respaldo);
        }

        else if (aux->izq == NULL && aux->drch != NULL && aux->drch->procesado == 1)
        {
            aux->procesado = 1;
            inOrden(respaldo, respaldo);
        }
        else if (aux->izq != NULL && aux->drch == NULL && aux->izq->procesado == 1)
        {
            aux->procesado = 1;
            inOrden(respaldo, respaldo);
        }
        else if (aux->drch != NULL && aux->izq != NULL && aux->drch->procesado == 1 && aux->izq->procesado == 1)
        {
            aux->procesado = 1;
            inOrden(respaldo, respaldo);
        }
    }
}

void postOrden(struct Arbol *raiz, struct Arbol *respaldo)
{

    struct Arbol *aux = raiz;
    struct Arbol *respaldo_aux = respaldo;

    if (respaldo_aux->izq->procesado == 0 || respaldo_aux->drch->procesado == 0)
    {
        if (aux->izq != NULL && aux->izq->procesado == 0)
        {
            postOrden(aux->izq, respaldo);
        }

        else if (aux->drch != NULL && aux->drch->procesado == 0)
        {
            postOrden(aux->drch, respaldo);
        }

        else if (aux->izq == NULL && aux->drch != NULL && aux->drch->procesado == 0)
        {
        }
        else if (aux->izq != NULL && aux->drch != NULL && aux->izq->procesado == 1)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d", aux->numero);
                aux->ya_impreso = 1;
                aux->procesado = 1;
            }
            postOrden(respaldo, respaldo);
        }

        else if (aux->izq == NULL && aux->drch == NULL)
        {
            if (aux->ya_impreso == 0)
            {
                printf("%d", aux->numero);
                aux->ya_impreso = 1;
                aux->procesado = 1;
            }

            postOrden(respaldo, respaldo);
        }
    }
}

// metodos para limpiar las banderas

struct Cola *crearCola(int dato)
{
    struct Cola *nuevo;
    nuevo = (struct Cola *)malloc(sizeof(struct Cola));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return (nuevo);
}
struct Cola *agregar_cola(struct Cola *inicio, int dato)
{
    struct Cola *aux = inicio;
    struct Cola *nuevo = crearCola(dato);

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;
    return (inicio);
}

struct Cola *eliminar_cola(struct Cola *inicio, int dato)
{
    struct Cola *actual = inicio, *anterior = NULL;

    while (actual != NULL && actual->dato != dato)
    {
        anterior = actual;
        actual = actual->sig;
    }
    if (anterior == NULL)
    {
        //    esta cola, lo unico que me va a hacer referencia es para poder limpiar el recorrido, por lo que cada vez que se este llmando al recorrido, estaremos sacando un dato de la cola.

        inicio = inicio->sig;
    }
    else
    {
        if (actual->sig != NULL)
        {
            anterior->sig = actual->sig;
            free(actual);
        }
        else
        {
            anterior->sig = NULL;
            free(actual);
        }
    }
    return (inicio);
}

void limpiarRecorrido(int dato, struct Arbol *raiz)
{

    struct Arbol *aux_arbol = raiz;

    while (aux_arbol != NULL && aux_arbol->numero != dato)
    {
        if (dato > aux_arbol->numero)
        {
            aux_arbol = aux_arbol->drch;
        }
        else
        {
            aux_arbol = aux_arbol->izq;
        }
    }

    if (aux_arbol != NULL)
    {
        aux_arbol->procesado = 0;
        aux_arbol->raiz = 10;
        aux_arbol->ya_impreso = 0;
    }
}