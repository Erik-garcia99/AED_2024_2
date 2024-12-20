/*
garcia chavez erik 01275863
algoritmos y estrucuutra de datos
practica ordenamineto (quick-sort y heap-sort)*/

// por lo que nos piden, los datos deben ser una estrucutura

// primero antes qyue nada de hacer cualquier algoritmo debo de poder ingresar datos a la estructurra
#include <stdio.h>
#include <stdlib.h>

struct Infraccion
{
    char Placas[10];
    char Marca[15];
    char Modelo[30];
    int Anio;
    int Multa;
    char Motivo[100];
    char Fecha[15];
    struct Infraccion *sig;
};

struct Pila
{
    struct Infraccion *pivote;
    struct Pila *sig;
};

struct Arbol
{
    struct Infraccion *nodo;
    struct Arbol *izq;
    struct Arbol *drch;
};

struct Cola
{
    struct Arbol *nodo_arbol;
    struct Cola *sig;
};

struct Infraccion *
creacionTabala(char placas[], char marca[], char modelo[], int anio, int multa, char motivo[], char fecha[]);

struct Infraccion *agregar_tabla_infracciones(struct Infraccion *inicio, char placas[], char marca[], char modelo[], int anio, int multa, char motivo[], char fecha[]);

struct Infraccion *saldar_multa(char placas[], struct Infraccion *inicio);

int tamanio_cola(struct Infraccion *inicio);

struct Pila *crear_Pila(struct Infraccion *nuevo_pivote);

struct Pila *agregar_pila_pivotes(struct Pila *inicio, struct Infraccion *nuevo);

struct Infraccion *quick_sort(struct Infraccion *inicio, int tamanio_original, int tamanio, int contadorIzq, int contadorDrch, struct Infraccion *cola_ordenada, int direccion, struct Pila *pila_pivotes);

struct Infraccion *encontrar_nodo_ladoIZQ(struct Pila *pila_pivotes, struct Infraccion *inicio);

struct Infraccion *detectar_pivote_anterior(struct Pila *pila_pivotes, struct Infraccion *inicio_cola);

struct Infraccion *nodo_lado_derecho(struct Infraccion *pivote_anterior, struct Infraccion *cola_ordenada_total, struct Pila *pivotes);

void mostrar_conternido(struct Infraccion *cola_ordenada);

// heap sort

struct Cola *crear_Cola(struct Arbol *Nodo);
struct Cola *agregar_cola(struct Cola *inicio, struct Arbol *Nodo);

struct Cola *eliminar(struct Cola *inicio);

struct Infraccion *Max_heap_sort(struct Infraccion *inicio_cola, struct Arbol *raiz);

struct Arbol *crear_Raiz(struct Infraccion *raiz);

struct Arbol *agregar_arbol(struct Infraccion *Nodo, struct Arbol *raiz, struct Cola *inicio, struct Cola *cola_compacion);

struct Infraccion *Re_ordenacion(struct Infraccion *cola_original, struct Arbol *arbol_completo, struct Cola *cola, struct Cola *inicio_cola, int DRCH, int IZQ);

int main(void)
{
    char Placas[10];
    char Marca[15];
    char Modelo[30];
    int Anio;
    int Multa;
    char Motivo[100];
    char Fecha[15];

    struct Infraccion *infraccion = NULL;
    struct Pila *pila = NULL;

    // control del programa
    int opc;
    int i;
    char letra;

    do
    {
        printf("\n1)agregar infraccion");
        printf("\n2) saldar multa ");
        printf("\n3) mostrar infraccion por numero de placas ");
        printf("\n4) mostrar infraccoin ordenadas por marca y modelo");
        printf("\n:");
        scanf("%d", &opc);

        // limpiando el buffer el '\n'
        while (getchar() != '\n')
            ;

        switch (opc)
        {
        case 1:

            // fflush(stdin);
            i = 0;
            // char letra;

            printf("\ningrese el codigo de la placa (maximo 10 caracteres): ");

            // while (getchar() != '\n')
            //     ;

            while ((letra = getchar()) != '\n' && i < 10)
            {
                Placas[i] = letra;
                i++;
            }
            Placas[i] = '\0'; // dependindo de la extension le asigna en la ultima opcion un operador nulo

            // volvemos a reinicar el contador
            // fflush(stdin);
            i = 0;

            printf("\ningrese el codigo de la Marca (maximo 15 caracteres): ");

            // while (getchar() != '\n')
            //     ;

            while ((letra = getchar()) != '\n' && i < 15)
            {
                Marca[i] = letra;
                i++;
            }
            Marca[i] = '\0';

            i = 0;
            printf("\ningrese el modelo del carro (maximo 30 caracteres): ");

            while ((letra = getchar()) != '\n' && i < 15)
            {
                Modelo[i] = letra;
                i++;
            }
            Modelo[i] = '\0';

            printf("\n ingrese el anio del carro: ");
            scanf("%d", &Anio);

            while (getchar() != '\n')
                ;

            printf("\n ingresa la multa: ");
            scanf("%d", &Multa);
            while (getchar() != '\n')
                ;

            // fflush(stdin);
            i = 0;
            // letra = NULL;

            printf("\n ingresa el motivo de la multa (MAX 100 caracteres)");

            // while (getchar() != '\n')
            //     ;

            while ((letra = getchar()) != '\n' && i < 100)
            {
                Motivo[i] = letra;
                i++;
            }
            Motivo[i] = '\0';

            // fflush(stdin);
            i = 0;
            printf("\n ingresa la fecha en formato DD/MM/AAAA ");

            // letra = NULL;

            // while (getchar() != '\n')
            //     ;
            while ((letra = getchar()) != '\n' && i < 15)
            {
                Fecha[i] = letra;
                i++;
            }
            Fecha[i] = '\0';

            if (infraccion == NULL)
            {
                infraccion = creacionTabala(Placas, Marca, Modelo, Anio, Multa, Motivo, Fecha);
            }
            else
            {
                infraccion = agregar_tabla_infracciones(infraccion, Placas, Marca, Modelo, Anio, Multa, Motivo, Fecha);
            }
            break;

        case 2:
            for (i = 0; i < 10; i++)
            {
                Placas[i] = '\0';
            }
            // char letra;
            printf("ingrese la placa del vehiculo: ");

            i = 0;

            while ((letra = getchar()) != '\n' && i < 10)
            {
                Placas[i] = letra;
                i++;
            }

            if (infraccion != NULL)
            {
                infraccion = saldar_multa(Placas, infraccion);
            }
            else
            {
                printf("la base de datos se encuentra vacia!!\n");
            }

            break;

        case 3:
            // hmm, primero deberiamos de contar la cantidad de elemementos totales que tengo en mi cola

            int tamanio_original = tamanio_cola(infraccion);
            // ordenando por quicksort

            infraccion = quick_sort(infraccion, tamanio_original, tamanio_original, 0, 0, infraccion, 4, pila);

            mostrar_conternido(infraccion);
            break;

        case 4:
            infraccion = Max_heap_sort(infraccion, NULL);
            mostrar_conternido(infraccion);

            break;
        }
    } while (opc != 100);
}

struct Infraccion *creacionTabala(char placas[], char marca[], char modelo[], int anio, int multa, char motivo[], char fecha[])
{
    struct Infraccion *nuevo = (struct Infraccion *)malloc(sizeof(struct Infraccion));

    int i = 0;

    nuevo->Anio = anio;
    nuevo->Multa = multa;

    while (placas[i] != '\0' && i < 10)
    {
        nuevo->Placas[i] = placas[i];
        i++;
    }
    nuevo->Placas[i] = '\0';

    i = 0;
    while (marca[i] != '\0' && i < 15)
    {
        nuevo->Marca[i] = marca[i];
        i++;
    }
    nuevo->Marca[i] = '\0';

    i = 0;
    while (modelo[i] != '\0' && i < 30)
    {
        nuevo->Modelo[i] = modelo[i];
        i++;
    }
    nuevo->Modelo[i] = '\0';

    i = 0;
    while (motivo[i] != '\0' && i < 100)
    {
        nuevo->Motivo[i] = motivo[i];
        i++;
    }
    nuevo->Motivo[i] = '\0';

    i = 0;
    while (fecha[i] != '\0' && i < 15)
    {
        nuevo->Fecha[i] = fecha[i];
        i++;
    }
    nuevo->Fecha[i] = '\0';

    nuevo->sig = NULL;

    return nuevo;
}

struct Infraccion *agregar_tabla_infracciones(struct Infraccion *inicio, char placas[], char marca[], char modelo[], int anio, int multa, char motivo[], char fecha[])
{
    struct Infraccion *aux_infraccion = inicio;
    struct Infraccion *nuevo = creacionTabala(placas, marca, modelo, anio, multa, motivo, fecha);

    while (aux_infraccion->sig != NULL)
    {
        aux_infraccion = aux_infraccion->sig;
    }

    aux_infraccion->sig = nuevo;

    return (inicio);
}

struct Infraccion *saldar_multa(char placas[], struct Infraccion *inicio)
{
    struct Infraccion *aux_infraccion = inicio;
    struct Infraccion *anterior = NULL;
    int i = 0;
    int compacion = 0;
    // buscamos la matriucla:
    while (aux_infraccion != NULL && compacion == 0)
    {
        if (placas[i] == aux_infraccion->Placas[i])
        {
            if (aux_infraccion->Placas[i] == '\0')
            {
                compacion = 1;
                break;
            }
            else
            {
                i++;
            }
        }
        else
        {
            anterior = aux_infraccion;
            aux_infraccion = aux_infraccion->sig;
        }
    }

    // digamso que lo ecnuentra por lo que ahjora debemos eliminarlo

    if (anterior == NULL)
    {
        // en este caso, el dato que se quiere eliminar se encuentra en la vcabeza
        inicio = inicio->sig;
        free(aux_infraccion);
    }
    else
    {
        if (aux_infraccion->sig != NULL)
        {
            // esta en medio de la cola
            anterior->sig = aux_infraccion->sig;
            free(aux_infraccion);
        }
        else
        {
            // esta al final de la cola.
            anterior->sig = NULL;
            free(aux_infraccion);
        }
    }

    return inicio;
}

// ahora siguen los algoritmos de ordenainiento pipipipppip

struct Infraccion *quick_sort(struct Infraccion *inicio, int tamanio_original, int tamanio, int contadorIzq, int contadorDrch, struct Infraccion *cola_ordenada, int direccion, struct Pila *pila_pivotes)
{
    // para una mayor practicidad solamente lo comparamos con las primreas letras del arreglo de las placas0

    struct Infraccion *aux_cola_ordenada = cola_ordenada;
    struct Infraccion *izq = NULL;
    struct Infraccion *inicioIzq = NULL;
    struct Infraccion *drch = NULL;
    struct Infraccion *inicio_derecha = NULL;
    struct Infraccion *segento = inicio;
    struct Infraccion *pivote_actual = inicio;
    struct Infraccion *nodo_anterior_pivote = NULL;
    struct Infraccion *inicio_nodo_a_ordenar = NULL;
    struct Infraccion *nodo_sigueinte_derecha = NULL;
    int contador_izq = 0;
    int contador_drch = 0;
    struct Pila *pila = pila_pivotes;
    // struct Infraccion *aux_cola_ordenada = cola_ordenada;

    inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

    nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

    nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

    // como voys a saber quien va a la izquierda y quien va a la derecha.

    // tamanio sera el tamanio actual con el que voy a estar trabajando, es la cantidad de nodos anteriores del lado izquierdo de mi pivote.

    // tengo la cantidad con la cual voy a estar trabajdno
    // por lo que para encontrar el dichoso pivote, voy a diviidir eso entre 2

    // primero antes que nada calculamos el pivote el cual sera con el que vamos a estar desplazandonos
    int inicde_pivote = 0;

    inicde_pivote = tamanio / 2;

    for (int i = 0; i < inicde_pivote; i++)
    {
        pivote_actual = pivote_actual->sig;
    }

    // nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

    // segun yo aqui ya tengo el segemento donde tengo todos los nodos a arreglar.

    // aqui recorrere desde el pedazo de segemnto en un tamanio que yo le mando, e me ira agregando del lado drch o del lado izq.
    int i = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (segento == pivote_actual)
        {
            // aqui me estoy refirineo al nodo mismo
            segento = segento->sig;
            continue;
        }
        else if (segento->Placas[0] > pivote_actual->Placas[0])
        {
            if (drch == NULL)
            {
                drch = segento;
                inicio_derecha = drch;
                contador_drch++;
            }
            else
            {
                drch->sig = segento;
                drch = drch->sig;
                contador_drch++;
            }
            segento = segento->sig;
        }
        else if (segento->Placas[0] < pivote_actual->Placas[0])
        {
            if (izq == NULL)
            {
                izq = segento;
                inicioIzq = izq;
                contador_izq++;
            }
            else
            {
                izq->sig = segento;
                izq = izq->sig;
                contador_izq++;
            }

            segento = segento->sig;
        }
        else
        {
            // quiere decir que es el mimso, por lo que da igual si se va para el lado izq o el lado drch.
            if (izq == NULL)
            {
                izq = segento;
                inicioIzq = izq;
                contador_izq++;
            }
            else
            {
                izq->sig = segento;
                izq = izq->sig;
                contador_izq++;
            }

            segento = segento->sig;
            // por lpo que lo mandare del lado izq
        }
    }

    if ((izq != NULL && drch != NULL) || (izq != NULL && drch == NULL))
    {
        // esto no, para acelo lo mas genreal debemos hacerlo de la otra manera,

        // como se que tengo un lado izquierdo y lo quiero ordenar de izquierda a derecha,
        // por lo que primero verifico si el nodo anterior es un pivote

        // primero debemos obtener ese nodo y despues obtener si hay un nodo anterior a el que sea un pivote.

        // inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

        // nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

        // nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

        if (nodo_anterior_pivote != NULL)
        {
            nodo_anterior_pivote->sig = inicioIzq;
            izq->sig = pivote_actual;

            // pivote_actual->sig = inicio_derecha;

            if (drch == NULL)
            {
                pivote_actual->sig = nodo_sigueinte_derecha;
            }
            else if (drch != NULL)
            {
                pivote_actual->sig = inicio_derecha;
                drch->sig = nodo_sigueinte_derecha;
            }

            // if (nodo_sigueinte_derecha != NULL)
            // {
            //     drch->sig = nodo_sigueinte_derecha;
            // }

            // en este caso el inicio no se ha modificado.
        }
        else
        {
            // volvera NULL porque el primer nodo aun no es un pivote.
            // por lo que en esta ocacion pongo al incio de la cola el lado ziquierdo ordenado
            // esta condicional es en ambos
            izq->sig = pivote_actual;

            if (drch == NULL)
            {
                pivote_actual->sig = nodo_sigueinte_derecha;
            }
            else if (drch != NULL)
            {
                pivote_actual->sig = inicio_derecha;
                drch->sig = nodo_sigueinte_derecha;
            }

            aux_cola_ordenada = inicioIzq;
            // pivote_actual->sig = inicio_derecha;

            // aux_cola_ordenada = inicioIzq;

            // drch->sig = nodo_sigueinte_derecha;
            // if (nodo_sigueinte_derecha != NULL)
            // {
            //     // drch->sig = nodo_sigueinte_derecha;
            // }
        }

        struct Infraccion *aux_impresion = aux_cola_ordenada;
        printf("\n");
        while (aux_impresion != NULL)
        {
            int i = 0;
            while (aux_impresion->Placas[i] != '\0')
            {
                printf("%c", aux_impresion->Placas[i]);
                i++;
            }
            printf("-");

            aux_impresion = aux_impresion->sig;
        }

        // agregamos a la pila de pivotes el pivote actual que hemos agregado
        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }

        // vuelveo a llmarlo

        cola_ordenada = quick_sort(inicioIzq, tamanio_original, contador_izq, contador_izq, contador_drch, aux_cola_ordenada, 0, pila);
    }

    else if (drch != NULL && izq == NULL)
    {
        // antes que nada debo de encoentrar el nodo mas a la izquierda que no es nodo, ya que muy probablemente ese ese segmento es el que estoy analizando que eta del lado izq

        // inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

        // // por lo que tambien necesito detectar si hay un pivote anterior al inicio del lado izq.
        // nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

        // nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

        // esto parace que es igual, lo uqe va a cambiar son la forma de cambiar los apuntadores.
        // como no tengo lado izq el pivote anterior se unira al inciio del lado derecho

        if (nodo_anterior_pivote != NULL)
        {
            nodo_anterior_pivote->sig = pivote_actual;
            pivote_actual->sig = inicio_derecha;
            drch->sig = nodo_sigueinte_derecha;

            // if (nodo_sigueinte_derecha != NULL)
            // {
            //     drch->sig = nodo_sigueinte_derecha;
            // }
        }
        else
        {
            // cunado entrara aqui, si me regresa un NULL, quiero decri que el inciio de la cola aun no ha sido pivote por lo que no esta ordenado.

            aux_cola_ordenada = pivote_actual;
            pivote_actual->sig = inicio_derecha;
            drch->sig = nodo_sigueinte_derecha;

            // if (nodo_sigueinte_derecha != NULL)
            // {
            //     drch->sig = nodo_sigueinte_derecha;
            // }
        }
        struct Infraccion *aux_impresion = aux_cola_ordenada;
        printf("\n");
        while (aux_impresion != NULL)
        {
            int i = 0;
            while (aux_impresion->Placas[i] != '\0')
            {
                printf("%c", aux_impresion->Placas[i]);
                i++;
            }
            printf("-");
            aux_impresion = aux_impresion->sig;
        }

        // agregamos a la pila de pivotes el pivote actual que hemos agregado
        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }

        // hacemos la recursividad

        cola_ordenada = quick_sort(inicio_derecha, tamanio_original, contador_drch, 0, contador_drch, aux_cola_ordenada, 0, pila);
    }
    else
    {
        // quiere decir que en nodo enviado es el pivote que ya sesta ordenado
        // si no hay nada del lado izquierdo ni nada del lado derecho quiere deicr que ya esta ordenado en su lugar

        // por lo que me queda es econtrar el pivote anterior
        // nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

        // nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

        // HASTA ESTE punto solo conozco a pivote que ya deberia de estar irdenando por en que lado aun no lo sabemos.

        // primoero saber si es el inicio el pivote
        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }
        // arriba me regreso anto el pivote anterior, como el incio del pivote, asi como el pivote sigueitne,

        // por lo que podemesmo agregarlo asi
        nodo_anterior_pivote->sig = pivote_actual;
        pivote_actual->sig = nodo_sigueinte_derecha;

        // hasta este punto ya agregamos el pivote en su lugar en la cola asi como ya esta dentro de la pila para detectalor que es un pivote.

        // por lo que queda es primero obtener el primer nodo el cual no es pivote

        inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

        if (inicio_nodo_a_ordenar != NULL)
        {
            // como en efecto tenemos un nodo que no ha sido pivote, tenemso un pivote anterior.
            // por lo que lo buscamos

            nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

            // asi mismo el pivote sespues.

            nodo_sigueinte_derecha = nodo_lado_derecho(inicio_nodo_a_ordenar, aux_cola_ordenada, pila);

            struct Infraccion *cantidad_nodos = inicio_nodo_a_ordenar;
            int conteo;

            if (nodo_sigueinte_derecha != NULL)
            {
                // si regresa NULL, quiere decir que fue hasta el final de la cola, por lo que no hay proximo pivote de ese lado

                // por lo que contare el total de nodos hasta ese punto
                conteo = 0;
                while (cantidad_nodos != nodo_sigueinte_derecha && nodo_sigueinte_derecha != NULL)
                {
                    conteo++;
                    cantidad_nodos = cantidad_nodos->sig;
                }

                struct Infraccion *aux_impresion = aux_cola_ordenada;
                printf("\n");
                while (aux_impresion != NULL)
                {
                    int i = 0;
                    while (aux_impresion->Placas[i] != '\0')
                    {
                        printf("%c", aux_impresion->Placas[i]);
                        i++;
                    }
                    printf("-");
                    aux_impresion = aux_impresion->sig;
                }

                // por lo que ahora ya podrei hacer la recurcividad

                cola_ordenada = quick_sort(inicio_nodo_a_ordenar, tamanio_original, conteo, conteo, conteo, aux_cola_ordenada, 0, pila);
            }
            else
            {
                // se aplica la misma pero en este caso como no hay pivote prodimo despues de este nodo, me ire hasta que se termine
                conteo = 0;
                while (cantidad_nodos != NULL)
                {
                    conteo++;
                    cantidad_nodos = cantidad_nodos->sig;
                }

                struct Infraccion *aux_impresion = aux_cola_ordenada;
                printf("\n");
                while (aux_impresion != NULL)
                {
                    int i = 0;
                    while (aux_impresion->Placas[i] != '\0')
                    {
                        printf("%c", aux_impresion->Placas[i]);
                        i++;
                    }
                    printf("-");
                    aux_impresion = aux_impresion->sig;
                }

                cola_ordenada = quick_sort(inicio_nodo_a_ordenar, tamanio_original, conteo, conteo, conteo, aux_cola_ordenada, 0, pila);
            }
        }
        else
        {
            // que me quiere decri que si es ifual a NULL, que no se encontro el nodo, por lo que todos son pivote entonces la cola ya esta rreglada

            return aux_cola_ordenada;
        }
    }

    return (cola_ordenada);
}

// estrucuturas y funciones apoyo

int tamanio_cola(struct Infraccion *inicio)
{
    struct Infraccion *aux = inicio;
    int contador = 0;
    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }

    return contador;
}

// necesito una forma de controlar que un nodo haya sido pivote
struct Pila *crear_Pila(struct Infraccion *nuevo_pivote)
{
    struct Pila *nuevo = (struct Pila *)malloc(sizeof(struct Pila));

    nuevo->pivote = nuevo_pivote;
    nuevo->sig = NULL;

    return (nuevo);
}

struct Pila *agregar_pila_pivotes(struct Pila *inicio, struct Infraccion *nuevo)
{

    /*lo hacemos medinate aun pila, dado que en el tope se tendra el pivote mas proxicmo que se haya agregado. */
    struct Pila *aux = inicio;
    struct Pila *nuevo_pivote;

    nuevo_pivote = crear_Pila(nuevo);

    nuevo_pivote->sig = aux;

    inicio = nuevo_pivote;

    return (inicio);
}

struct Infraccion *encontrar_nodo_ladoIZQ(struct Pila *pila_pivotes, struct Infraccion *inicio)
{
    struct Pila *aux_pivotes = pila_pivotes;
    struct Infraccion *aux_inicio = inicio;

    // por lo que ahora voys a buscar, tomare un elemenot de la cola de la estrucuutra de infracciones y la comparare con todos los elementos de la funcion aux_pivortes que contednra los elementos que ya han sido pivotes.

    // es que si o si son 2 cilos
    int encontrado = 0;
    if (aux_pivotes != NULL)
    {
        while (encontrado == 0 && aux_inicio != NULL)
        {

            while (aux_pivotes != NULL)
            {
                if (aux_inicio != aux_pivotes->pivote)
                {
                    aux_pivotes = aux_pivotes->sig;
                    encontrado = 1;
                }
                else if (aux_inicio == aux_pivotes->pivote)
                {
                    encontrado = 0;
                    aux_inicio = aux_inicio->sig;
                    aux_pivotes = pila_pivotes;
                    break;
                }
            }
        }

        if (aux_inicio != NULL)
        {
            // retornamos el nodo el cual es e l primero de izquierda a derecha que no es pivote
            return (aux_inicio);
        }
        else
        {
            // ppude que ya sea el ultimo elemento

            return NULL;
        }
    }
    else
    {
        return aux_inicio;
    }
}

// reasignar el nuevo inicio de la cola.
struct Infraccion *detectar_pivote_anterior(struct Pila *pila_pivotes, struct Infraccion *inicio_cola)
{
    int inicio = 0;
    // en toeria ocupare 2 apuntadores para el analisi si el nodo de inicio ya es un pivote, si el nodo de inicio no ha sido pivote, entonces tendre que gresesar el nodo de inicio, en otro caso regresare el otro nodo.

    // necesiot algo que me diga si el nodo de inicio es pivote o no, al final, en la funcion de quick tendre solo la direccion, por lo que no me dira mucho,

    // tal vez mandar NULL en el caso que el nodo de incio no sera pivote, me explico, si yo mando NULL a la funcion de quick,me estara diciendo que el nodo de inicio de la cola ordenada no es pivote, por lo que puedo remplazarlo con el lado izquierdo que se registro despues de hacer la serparaion, me regresado un nodo en caso de que el inciio sea pivote, por lo que ya estara dentro de la cola.en que parte no se, pero se que lo que me devuelve es el nodo mas a la izquierda proxicmo y caso al 99% seguro que lo que esta despues de ahi estan los nodos que yo separe hacia ese lado.
    struct Infraccion *nodo_actual = inicio_cola;
    struct Infraccion *nodo_anterior = NULL;
    struct Pila *aux_pilas = pila_pivotes;
    // si nodo anterior es igual a NULL, quiere decir que el inicio de la cola aun no es pivote, por lo que regreamos eso, que de igual forma es igual a NULL en otro caso contendran el nodo que es el ultimo de izquirda a Drch en ser un pivote.
    int encontrado = 0;

    if (aux_pilas != NULL)
    {
        while (encontrado == 0 && nodo_actual != NULL)
        {
            while (aux_pilas != NULL)
            {
                if (nodo_actual != aux_pilas->pivote)
                {
                    encontrado = 1;
                    aux_pilas = aux_pilas->sig;
                }
                else if (nodo_actual == aux_pilas->pivote)
                {
                    encontrado = 0;
                    aux_pilas = pila_pivotes;
                    nodo_anterior = nodo_actual;
                    nodo_actual = nodo_actual->sig;
                    break;
                }
            }
        }
        return nodo_anterior;
    }
    else
    {
        return nodo_anterior;
    }
}

struct Infraccion *nodo_lado_derecho(struct Infraccion *pivote_anterior, struct Infraccion *cola_ordenada_total, struct Pila *pivotes)
{
    // buscara el nodo segundo que sea pivote para poder enlazar el lado derecho en caso que haya para unir el resto del pivote.

    struct Pila *aux_pila = pivotes;
    struct Infraccion *aux_pivote_anterior = pivote_anterior;
    struct Infraccion *aux_cola_ordenada = cola_ordenada_total;

    if (aux_pila == NULL)
    {
        return NULL;
    }
    else
    {
        if (aux_pivote_anterior == NULL)
        {
            aux_pivote_anterior = aux_cola_ordenada;
        }
        else
        {
            aux_pivote_anterior = aux_pivote_anterior->sig;
        }

        // quiere decir que se se esta ingresando desde el incio dellado izq.

        // ahora a buscar rl proximo pivote, porque si ahy algo
        int encontrado = 0;
        while (encontrado == 0 && aux_pivote_anterior != NULL)
        {

            // si lo dejo normal

            while (aux_pila != NULL)
            {
                // if (aux_pila == NULL)
                // {
                //     aux_pivote_anterior = aux_pivote_anterior->sig;
                //     aux_pila = pivotes;
                //     encontrado = 0;
                //     break;
                // }
                if (aux_pivote_anterior != aux_pila->pivote)
                {
                    aux_pila = aux_pila->sig;
                    encontrado = 0;
                }
                else if (aux_pivote_anterior == aux_pila->pivote)
                {
                    encontrado = 1;
                    break;
                }
            }
            if (aux_pila == NULL)
            {
                aux_pivote_anterior = aux_pivote_anterior->sig;
                aux_pila = pivotes;
            }
        }
        // este me va a regresar 2 cosas, un nodo por lo que puedeo anclar el segmeneto
        return (aux_pivote_anterior);
    }
}

// heap sort
struct Infraccion *Max_heap_sort(struct Infraccion *inicio_cola, struct Arbol *raiz)
{

    // aqui adentro primero necesito en otra estrucutra crear el arbol completo con los datos que se tenemos.
    struct Infraccion *aux_inicio_cola = inicio_cola;
    struct Arbol *arbol = raiz;
    struct Cola *cola = NULL;
    struct Cola *cola_compacion = NULL;
    // lo que se hace es recorrer la cola hatsa el final.

    // pdoria tener una condicional por si en esta funcion le tecgo que hacer recursividad que no vuelva a ahcer el arbol, que se brincque el pedazo de codigo, por ejemplo cunado arbol sea igual a NULL,

    // tal vez no es buena idea, ya que es igual a NULL al inicio que eta OK y akl final, por lo que despues puede que lo vuleve a hacer, creo que la comparacion y todo lo hagamos en otra funcion,

    while (aux_inicio_cola != NULL)
    {
        if (arbol == NULL)
        {

            arbol = crear_Raiz(aux_inicio_cola);
            cola = crear_Cola(arbol);
            cola_compacion = crear_Cola(arbol);
            aux_inicio_cola = aux_inicio_cola->sig;
        }
        else
        {

            // este va a ser el pedo, el crear mi arbol completo.
            if (cola->nodo_arbol->drch != NULL && cola->nodo_arbol->izq != NULL)
            {
                cola = eliminar(cola);
            }
            arbol = agregar_arbol(aux_inicio_cola, arbol, cola, cola_compacion);
            aux_inicio_cola = aux_inicio_cola->sig;
            // cola = agregar_cola(cola, arbol);
        }
    }

    // ahora la funcion que va a relizar lo de comparar e intercambiar, pero esto que me va a devolver, me devolvera la lista ya ordenada, por lo que es de tipo Infraccionm que me devolovera un puntero a ese arreglo ordenado
    // essta fiuncopn hara los de hipify

    // while (arbol != NULL)
    // {
    // }
    while (arbol != NULL)
    {
        struct Infraccion *cola_re_ordenada = Re_ordenacion(inicio_cola, arbol, cola_compacion, cola_compacion, 0, 0);
    }

    // struct Infraccion *Re_ordenacion =

    //     getchar();
}

struct Arbol *crear_Raiz(struct Infraccion *raiz)
{
    struct Arbol *aux = (struct Arbol *)malloc(sizeof(struct Arbol));

    aux->nodo = raiz;
    aux->izq = NULL;
    aux->drch = NULL;

    return (aux);
}

struct Arbol *agregar_arbol(struct Infraccion *Nodo, struct Arbol *raiz, struct Cola *inicio, struct Cola *cola_compacion)
{
    // muy bien, tengo que tener mi cola

    struct Cola *aux_cola = inicio;

    // debo de checar, primero voy a chechar si hay espacio, primero del lado izquierdo

    if (aux_cola->nodo_arbol->izq == NULL)
    {
        struct Arbol *nuevo = crear_Raiz(Nodo);
        aux_cola->nodo_arbol->izq = nuevo;
        aux_cola = agregar_cola(aux_cola, nuevo);
        cola_compacion = agregar_cola(cola_compacion, nuevo);
        return (raiz);
    }
    else if (aux_cola->nodo_arbol->drch == NULL)
    {
        struct Arbol *nuevo = crear_Raiz(Nodo);
        aux_cola->nodo_arbol->drch = nuevo;
        aux_cola = agregar_cola(aux_cola, nuevo);
        cola_compacion = agregar_cola(cola_compacion, nuevo);
        return (raiz);
    }
    // else if (aux_cola->nodo_arbol->drch != NULL && aux_cola->nodo_arbol->izq != NULL)
    // {
    //     // que quiere decir que ese nodo ya esta completo por lo que lo saco

    //     inicio = eliminar(inicio);
    //     // me va a regresar la nuevo puntero de la cola
    //     // recursividad

    //     return agregar_arbol(Nodo, raiz, inicio);
    // }

    // return (raiz);
}

// okay, para poder realizar el proceismineto para crear mi arbol completo se hara mediante una cola.

// que va hacer, es que, tomare el elemento que quiero ingresar al arbol, por lo que yo debo de tener una cola de los elementos que ya entraron y saber si en sus aoubtnadores al lado izq o lado dercheo ya tiene algo, si no lo agrego, si, si, lo saco de la pila

struct Cola *crear_Cola(struct Arbol *Nodo)
{
    struct Cola *nuevo = (struct Cola *)malloc(sizeof(struct Cola));

    nuevo->nodo_arbol = Nodo;
    nuevo->sig = NULL;

    return (nuevo);
}

struct Cola *agregar_cola(struct Cola *inicio, struct Arbol *Nodo)
{

    struct Cola *aux = inicio;
    struct Cola *nuevo = crear_Cola(Nodo);

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;

    return (inicio);
}

// la eliminacionsera una eliminacion nrmal de una cola

struct Cola *eliminar(struct Cola *inicio)
{
    struct Cola *aux = inicio;

    inicio = inicio->sig;

    free(aux);

    return (inicio);
}

struct Infraccion *Re_ordenacion(struct Infraccion *cola_original, struct Arbol *arbol_completo, struct Cola *cola, struct Cola *inicio_cola, int DRCH, int IZQ)
{
    struct Infraccion *aux_infracciones = cola_original;
    struct Arbol *aux_arbol = arbol_completo;
    struct Cola *aux_cola_compatacion = cola;
    struct Infraccion *aux_enlaces = NULL;

    struct Infraccion *nodo_anterior = NULL;
    struct Infraccion *nodo_sigueinte = NULL;
    struct Infraccion *ordenamineto_aux = NULL;
    // para detercatr si ha vido un cambio dentro de un subarbol.
    int cambio = 0;
    int contador = 0;

    while (arbol != NULL)
    {

                while (aux_cola_compatacion != NULL)
        {
        }
        // al final vuevlo a recargar la pila

        // sacar la raiz

        // ordenar dentro de la varibale

        // llevar un contador sobre en que poscion va a estar

        // posicion anterior, presente y siguiente
    }

    // ahora tengo que hacer estas comparaciones, porque al parecer va a haber recursividad.
}

// struct Infraccion

// funcion de impresion, el algoritmo de quick sort ya quedo

void mostrar_conternido(struct Infraccion *cola_ordenada)
{
    struct Infraccion *aux_cola_ordenada = cola_ordenada;
    printf("\n\n");
    printf("Placas  | Marca | Modelo | anio | Multa | Motivo | fecha |");

    // struct Infraccion *aux_impresion = aux_cola_ordenada;
    // printf("\n");
    // while (aux_impresion != NULL)
    // {
    //     int i = 0;
    //     while (aux_impresion->Placas[i] != '\0')
    //     {
    //         printf("%c", aux_impresion->Placas[i]);
    //         i++;
    //     }
    //     printf("-");
    //     aux_impresion = aux_impresion->sig;
    // }

    printf("\n\n");
    int i;
    while (aux_cola_ordenada != NULL)
    {
        i = 0;
        while (aux_cola_ordenada->Placas[i] != '\0')
        {
            printf("%c", aux_cola_ordenada->Placas[i]);
            i++;
        }
        printf(" - ");

        i = 0;

        while (aux_cola_ordenada->Marca[i] != '\0')
        {
            printf("%c", aux_cola_ordenada->Marca[i]);
            i++;
        }
        printf(" - ");

        i = 0;

        while (aux_cola_ordenada->Modelo[i] != '\0')
        {
            printf("%c", aux_cola_ordenada->Modelo[i]);
            i++;
        }
        printf(" - ");

        printf("%d", aux_cola_ordenada->Anio);
        printf(" - ");

        printf("%d", aux_cola_ordenada->Multa);
        printf(" - ");

        i = 0;
        while (aux_cola_ordenada->Motivo[i] != '\0')
        {
            printf("%c", aux_cola_ordenada->Motivo[i]);
            i++;
        }

        printf(" - ");

        i = 0;
        while (aux_cola_ordenada->Fecha[i] != '\0')
        {
            printf("%c", aux_cola_ordenada->Fecha[i]);
            i++;
        }
        printf(" - ");

        aux_cola_ordenada = aux_cola_ordenada->sig;
        printf("\n");
    }
}