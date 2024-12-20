/*
garcia chavez erik 01275863
algoritmos y estrucuutra de datos
practica ordenamineto (quick-sort y heap-sort)*/

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
            Placas[i] = '\0';

            i = 0;

            printf("\ningrese el codigo de la Marca (maximo 15 caracteres): ");

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

            i = 0;

            printf("\n ingresa el motivo de la multa (MAX 100 caracteres)");

            while ((letra = getchar()) != '\n' && i < 100)
            {
                Motivo[i] = letra;
                i++;
            }
            Motivo[i] = '\0';

            i = 0;
            printf("\n ingresa la fecha en formato DD/MM/AAAA ");

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

            int tamanio_original = tamanio_cola(infraccion);

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

    if (anterior == NULL)
    {

        inicio = inicio->sig;
        free(aux_infraccion);
    }
    else
    {
        if (aux_infraccion->sig != NULL)
        {

            anterior->sig = aux_infraccion->sig;
            free(aux_infraccion);
        }
        else
        {

            anterior->sig = NULL;
            free(aux_infraccion);
        }
    }

    return inicio;
}

struct Infraccion *quick_sort(struct Infraccion *inicio, int tamanio_original, int tamanio, int contadorIzq, int contadorDrch, struct Infraccion *cola_ordenada, int direccion, struct Pila *pila_pivotes)
{

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

    inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

    nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

    nodo_sigueinte_derecha = nodo_lado_derecho(nodo_anterior_pivote, cola_ordenada, pila);

    int inicde_pivote = 0;

    inicde_pivote = tamanio / 2;

    for (int i = 0; i < inicde_pivote; i++)
    {
        pivote_actual = pivote_actual->sig;
    }

    int i = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (segento == pivote_actual)
        {

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
    }

    if ((izq != NULL && drch != NULL) || (izq != NULL && drch == NULL))
    {

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
        }
        else
        {

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
            printf(" - ");

            aux_impresion = aux_impresion->sig;
        }

        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }

        cola_ordenada = quick_sort(inicioIzq, tamanio_original, contador_izq, contador_izq, contador_drch, aux_cola_ordenada, 0, pila);
    }

    else if (drch != NULL && izq == NULL)
    {

        if (nodo_anterior_pivote != NULL)
        {
            nodo_anterior_pivote->sig = pivote_actual;
            pivote_actual->sig = inicio_derecha;
            drch->sig = nodo_sigueinte_derecha;
        }
        else
        {

            aux_cola_ordenada = pivote_actual;
            pivote_actual->sig = inicio_derecha;
            drch->sig = nodo_sigueinte_derecha;
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
            printf(" - ");
            aux_impresion = aux_impresion->sig;
        }

        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }

        cola_ordenada = quick_sort(inicio_derecha, tamanio_original, contador_drch, 0, contador_drch, aux_cola_ordenada, 0, pila);
    }
    else
    {

        if (pila == NULL)
        {
            pila = crear_Pila(pivote_actual);
        }
        else
        {
            pila = agregar_pila_pivotes(pila, pivote_actual);
        }

        nodo_anterior_pivote->sig = pivote_actual;
        pivote_actual->sig = nodo_sigueinte_derecha;

        inicio_nodo_a_ordenar = encontrar_nodo_ladoIZQ(pila, aux_cola_ordenada);

        if (inicio_nodo_a_ordenar != NULL)
        {

            nodo_anterior_pivote = detectar_pivote_anterior(pila, aux_cola_ordenada);

            nodo_sigueinte_derecha = nodo_lado_derecho(inicio_nodo_a_ordenar, aux_cola_ordenada, pila);

            struct Infraccion *cantidad_nodos = inicio_nodo_a_ordenar;
            int conteo;

            if (nodo_sigueinte_derecha != NULL)
            {

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
                    printf(" - ");
                    aux_impresion = aux_impresion->sig;
                }

                cola_ordenada = quick_sort(inicio_nodo_a_ordenar, tamanio_original, conteo, conteo, conteo, aux_cola_ordenada, 0, pila);
            }
            else
            {

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
                    printf(" - ");
                    aux_impresion = aux_impresion->sig;
                }

                cola_ordenada = quick_sort(inicio_nodo_a_ordenar, tamanio_original, conteo, conteo, conteo, aux_cola_ordenada, 0, pila);
            }
        }
        else
        {

            return aux_cola_ordenada;
        }
    }

    return (cola_ordenada);
}

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

struct Pila *crear_Pila(struct Infraccion *nuevo_pivote)
{
    struct Pila *nuevo = (struct Pila *)malloc(sizeof(struct Pila));

    nuevo->pivote = nuevo_pivote;
    nuevo->sig = NULL;

    return (nuevo);
}

struct Pila *agregar_pila_pivotes(struct Pila *inicio, struct Infraccion *nuevo)
{

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

            return (aux_inicio);
        }
        else
        {

            return NULL;
        }
    }
    else
    {
        return aux_inicio;
    }
}

struct Infraccion *detectar_pivote_anterior(struct Pila *pila_pivotes, struct Infraccion *inicio_cola)
{
    int inicio = 0;

    struct Infraccion *nodo_actual = inicio_cola;
    struct Infraccion *nodo_anterior = NULL;
    struct Pila *aux_pilas = pila_pivotes;

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

        int encontrado = 0;
        while (encontrado == 0 && aux_pivote_anterior != NULL)
        {

            while (aux_pila != NULL)
            {

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

        return (aux_pivote_anterior);
    }
}

struct Infraccion *Max_heap_sort(struct Infraccion *inicio_cola, struct Arbol *raiz)
{

    struct Infraccion *aux_inicio_cola = inicio_cola;
    struct Arbol *arbol = raiz;
    struct Cola *cola = NULL;
    struct Cola *cola_compacion = NULL;

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

            if (cola->nodo_arbol->drch != NULL && cola->nodo_arbol->izq != NULL)
            {
                cola = eliminar(cola);
            }
            arbol = agregar_arbol(aux_inicio_cola, arbol, cola, cola_compacion);
            aux_inicio_cola = aux_inicio_cola->sig;
        }
    }
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

    struct Cola *aux_cola = inicio;

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
}

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

void mostrar_conternido(struct Infraccion *cola_ordenada)
{
    struct Infraccion *aux_cola_ordenada = cola_ordenada;
    printf("\n\n");
    printf("Placas  | Marca | Modelo | anio | Multa | Motivo | fecha |");

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
        printf("\n\n");
    }
}