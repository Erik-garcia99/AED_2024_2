#include <stdio.h>
#include <stdlib.h>
int *acomodo_lista_ambosExtremos(int *listaOrdenada, int *numeros, int tamanio, int *izq, int *drch, int contadorIzq, int contadorDrch, int pivote, int *colaPivote, int *indice, int tamaniOriginal);

int *acomodo_lista_listaIzq(int *listaOrdenada, int *izq, int *drch, int contadorIzq, int pivote, int *colaPivote, int *indice, int tamaniOriginal, int tamanio, int *numeros);

int *acomodo_lista_listaDrch(int *listaOrdenada, int *izq, int *drch, int contadordrch, int pivote, int *colaPivote, int *indice, int tamaniOriginal, int tamanio, int *numeros);

int *quicksort(int *numeros, int tamanio, int tamanioOriginal, int *listaOrdenada, int *izq, int *drch, int *colaPivote, int *indice);

int *reasgigarRegistr(int *listaOrdenada, int tamanioOriginal, int *dimencion, int *colaPivote, int *indice, int pivote);

int *regresar_nuevoSubArreglo(int *numeros, int *dimencion, int *nuevoIzq, int *nuevoDrch, int contadorIzq, int contadordrch, int *nuevoSubArreglo, int pivote, int *listaOrdenada, int tamanioOriginal, int *indice);
int main()
{
    // en quick sort, necesito una lista de elementos que seran de que tamanio, no lo se.

    int lista[13] = {13, 6, 45, 32, 8, 11, 56, 3, 67, 5, 88, 76, 22};

    int tamanio = (sizeof(lista)) / (sizeof(lista[0]));
    // int pivote = tamanio / 2; // siempre eligire el del medio, este sera exactamento el del medio o un numero cercado truncado redondeado hacia atras

    int *listaElementos = (int *)malloc(tamanio * sizeof(int));

    for (int i = 0; i < tamanio; i++)
    {
        listaElementos[i] = lista[i];
    }

    int *indice = (int *)malloc(sizeof(int));
    *indice = 0;

    int listaResultante[tamanio];

    for (int i = 0; i < tamanio; i++)
    {
        listaResultante[i] = 0;
    }

    int *listaApoyo = quicksort(listaElementos, tamanio, tamanio, NULL, 0, 0, 0, indice);

    // con un ciclo voy agregando 1 a 1
}

// la funcion que ordenara el numero debe de recibir tanto la lista de elemento, como el pivote

// me va a regresar una lista ordenada de menor a mayor
// recicira el tamanio de este arreglo
int *quicksort(int *numeros, int tamanio, int tamanioOriginal, int *listaOrdenada, int *izq, int *drch, int *colaPivote, int *indice)
// falta la lista de los indices qwue ya fueron pivote padre
{
    // se hace mediante recursividad
    int inicioCola = 0;
    int inicioPila = 0;
    int contadorIzq = 0;
    int contadorDrch = 0;
    int contador_ingreso_arrOrdenado = 0;
    int indicePivote = 0;
    int pivote;

    if (listaOrdenada == NULL)
    {
        // solo entra aqui en un inicio
        // quiere decir que entamos inicando nuestro algoritmo de ordenamineto de quicksort

        // en este caso pues yo mande el tamanio, para ahorrarme ese paso
        // que prosigue ahora.
        // primero scar el pivote
        indicePivote = tamanio / 2;
        pivote = numeros[indicePivote];
        // inicar mi lista ordenada
        // tamanioOriginal -= 1;
        listaOrdenada = (int *)malloc((tamanioOriginal - 1) * sizeof(int));

        colaPivote = (int *)malloc(tamanioOriginal * sizeof(int));
        // int indiceApoyo = *indice;

        // como yo se que por ahora tengo todo el arreglo no hay pivotes, puedo ir hasta el final

        // lo que procisgue ahora es, contar cunatos elementos son menores que van a la izquiera y cuantos son mayores que van hacia la derecha.

        // entonces al parecer ya tenog el tamanio de lo que seran los arreglos.
        // por lo que asigno numeros

        // solo puede haber 3 casos,
        // en que el pivote esta en medio
        // el pivote es el primre elemeto
        // el pivote es el ultimo elemento
        // en otro caso ocurrio un fatal error

        for (int i = 0; i < tamanio; i++)
        {
            if (numeros[i] > pivote)
            {
                contadorDrch++;
                printf("%d - ", numeros[i]);
            }
            else if (numeros[i] == pivote)
            {
                continue;
            }
            else if (numeros[i] < pivote)
            {
                contadorIzq++;
                printf("%d - ", numeros[i]);
            }
        }

        if (contadorIzq != 0 && contadorDrch != 0)
        {

            izq = (int *)malloc((contadorIzq - 1) * sizeof(int));
            drch = (int *)malloc((contadorDrch - 1) * sizeof(int));
            printf("\n ");
            int asignacionDercha = 0;
            int asignacionIzq = (contadorIzq - 1);

            // ahora los ingreso a sus respectivas listas
            printf("\n ");
            for (int i = 0; i < tamanio; i++)
            {
                // quiero que sea lo mas parecido a la logica
                if (numeros[i] > pivote)
                {
                    drch[asignacionDercha] = numeros[i];
                    (asignacionDercha)++;
                    printf("%d - ", numeros[i]);
                }
                else if (numeros[i] == pivote)
                {
                    continue;
                }
                else
                {
                    izq[asignacionIzq] = numeros[i];
                    (asignacionIzq)--;
                    printf("%d - ", numeros[i]);
                }
            }
            printf("\n ");
            // primero organizando de izqueirda a drecha
            int O = 0;
            for (O = 0; O < contadorIzq; O++)
            {
                listaOrdenada[O] = izq[O];
                printf("%d - ", izq[O]);
            }

            listaOrdenada[O] = pivote;
            O++;

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                listaOrdenada[O] = drch[i];
                O++;
                printf("%d - ", drch[i]);
            }
            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d -", listaOrdenada[i]);
            }

            colaPivote[*indice] = pivote;
            (*indice)++;
            for (int i = *indice; i < tamanioOriginal; i++)
            {
                // poner lo que resta en 0.
                colaPivote[i] = 0;
            }

            free(numeros);
            numeros = NULL;
            numeros = (int *)realloc(numeros, contadorIzq * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", izq[i]);
                numeros[i] = izq[i];
            }

            listaOrdenada = quicksort(numeros, contadorIzq, tamanioOriginal, listaOrdenada, izq, drch, colaPivote, indice);

            // printf("\n ");
            // for (int i = 0; i <= contadorDrch; i++)
            // {
            //     printf("%d - ", drch[i]);
            // }

            // printf("\n ");
            // for (int i = 0; i <= contadorIzq; i++)
            // {
            //     printf("%d - ", izq[i]);
            // }
        }

        else if (contadorIzq == 0 && contadorDrch != 0)
        {
            // en pivote es el primer elemenot
            izq = NULL;

            drch = (int *)malloc((contadorDrch - 1) * sizeof(int));
            printf("\n ");
            int asignacionDercha = 0;

            printf("\n ");
            for (int i = 0; i < tamanio; i++)
            {
                if (numeros[i] == pivote)
                {
                    printf("%d - ", numeros[i]);
                    continue;
                }
                else
                {
                    drch[asignacionDercha] = numeros[i];
                    (asignacionDercha)++;
                    printf("%d - ", numeros[i]);
                }
            }
            int O = 0;
            listaOrdenada[0] = pivote;
            O++;

            for (int i = O; i < contadorDrch; i++)
            {
                listaOrdenada[i] = drch[i];
                printf("%d - ", drch[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d -", listaOrdenada[i]);
            }

            colaPivote[*indice] = pivote;
            indice++;
            free(numeros);
            numeros = (int *)realloc(numeros, contadorDrch * sizeof(int));

            printf("\n ");

            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", drch[i]);
                numeros[i] = drch[i];
            }

            listaOrdenada = quicksort(numeros, contadorDrch, tamanioOriginal, listaOrdenada, izq, drch, colaPivote, indice);
        }
        else if (contadorIzq != 0 && contadorDrch == 0)
        {
            // el pivote ultimo elemento
            drch = NULL;

            izq = (int *)malloc((contadorIzq - 1) * sizeof(int));

            int asignacionIzq = (contadorIzq - 1);

            printf("\n ");

            for (int i = 0; i < tamanio; i++)
            {
                if (numeros[i] == pivote)
                {
                    printf("%d - ", numeros[i]);
                    continue;
                }
                else
                {
                    // yo se que todos seran menores,
                    izq[asignacionIzq] = numeros[i];
                    asignacionIzq--;
                    printf("%d - ", numeros[i]);
                }
            }

            // hasta aqui tengo creado mi arreglo del lado izquierdo.

            int O = 0;
            for (O = 0; O < contadorIzq; O++)
            {
                listaOrdenada[O] = izq[O];
                printf("%d - ", izq[O]);
            }
            listaOrdenada[O] = pivote;

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d -", listaOrdenada[i]);
            }

            colaPivote[*indice] = pivote;
            indice++;

            free(numeros);
            numeros = (int *)realloc(numeros, contadorIzq * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", izq[i]);
                numeros[i] = izq[i];
            }

            listaOrdenada = quicksort(numeros, contadorIzq, tamanioOriginal, listaOrdenada, izq, drch, colaPivote, indice);
        }
        else
        {
            printf("ocurrio un fatakl errir");
            return NULL;
        }
    }

    if (izq != NULL && drch != NULL)
    {
        // hay algo en medio y se empieza de izquierda a derecha

        // ahora neceistmaos buscar el pivote

        // la lista Ordenada ya esta creado eso no entra ni la cola de pivote, ya etsa creada y tiene el primer pivote que se creo.

        // úede que si se pueda hacer en una funcion, lo hare todas y mirare que tanto se puede ir a una funcion y que se queda aqui.

        /*cosas similaes
        (si yo lo hago en funcion, los valores seran cambiados y tendre que usar los mimso apuntadores, en este caso si quiereo cambiar los valores. me regresara la lista ya ordenada, )
        -calcular el pivote
        */
        indicePivote = tamanio / 2;
        pivote = numeros[indicePivote];

        //    que prosigue contar cunatos son menores y cunatos son mayores

        // me ire por la izquierda
        printf("\n ");
        for (int i = 0; i < tamanio; i++)
        {
            if (numeros[i] > pivote)
            {
                contadorDrch++;
                printf("%d - ", numeros[i]);
            }
            else if (numeros[i] == pivote)
            {
                continue;
            }
            else if (numeros[i] < pivote)
            {
                contadorIzq++;
                printf("%d - ", numeros[i]);
            }
        }

        // lo agregamso a la cola que asigna nos numero que ya han sido pivote

        if (contadorIzq != 0 && contadorDrch != 0)
        {

            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
            int *nuevosDrch = (int *)malloc((contadorDrch - 1) * sizeof(int));
            listaOrdenada = acomodo_lista_ambosExtremos(listaOrdenada, numeros, tamanio, nuevoIzq, nuevosDrch, contadorIzq, contadorDrch, pivote, colaPivote, indice, tamanioOriginal);

            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevosDrch[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            printf("\n ");
            printf("%d - ", *indice);

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevosDrch, colaPivote, indice);
        }
        else if (contadorIzq != 0 && contadorDrch == 0)
        {
            drch = NULL;

            // aqui conzco mi pivote

            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
            // contadorIzq -= 1;

            listaOrdenada = acomodo_lista_listaIzq(listaOrdenada, nuevoIzq, NULL, contadorIzq, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");

            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, NULL, colaPivote, indice);
        }
        else if (contadorIzq == 0 && contadorDrch != 0)
        {
            izq = NULL;
            // contadorIzq -= 1;

            int *nuevoDerecho = (int *)malloc((contadorDrch - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_listaDrch(listaOrdenada, NULL, nuevoDerecho, contadorDrch, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevoDerecho[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorDrch - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d -", nuevoDerecho[i]);
                nuevoNumeros[i] = nuevoDerecho[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorDrch, tamanioOriginal, listaOrdenada, NULL, nuevoDerecho, colaPivote, indice);
        }
        else
        {
            // en este caso entramso en que es un pivote que ya esta ordenado en su lugar dentro del vector.
            // que va a pasar cunado solo se tenga a 1 pivote el cual no es ni mayor ni menor

            // en este caso el pivote esta en su lugar por lo que lo guardamos ahora toca lo feo, lo cual no queria hacer que es, encontrar la proxima interseccion.

            // int O = 0;
            // int encontrado = 0;
            // int contadorCola = 0;
            // while (encontrado = 0)
            // {
            //     int comparador = listaOrdenada[O];

            //     while (contadorDrch <= tamanioOriginal)
            //     {
            //         if (comparador = colaPivote[contadorCola])
            //         {
            //             contadorCola++;
            //             encontrado = 0;
            //         }
            //         else
            //         {
            //             encontrado = 1;
            //             break;
            //         }
            //     }

            //     if (encontrado == 0 && contadorCola == tamanioOriginal)
            //     {
            //         encontrado = 1;
            //         break;
            //     }
            //     else
            //     {
            //         O++;
            //         contadorCola = 0;
            //     }
            // }

            // listaOrdenada[O] = pivote;

            // colaPivote[*indice] = pivote;
            // (*indice)++;
            int *dimencion = (int *)malloc(sizeof(int));
            dimencion = 0;
            int *nuevoSubArreglo = reasgigarRegistr(listaOrdenada, tamanioOriginal, dimencion, colaPivote, indice, pivote);

            printf("\n ");

            if (nuevoSubArreglo != NULL)
            {
                for (int i = 0; i < (*dimencion); i++)
                {
                    printf("%d- ", nuevoSubArreglo[i]);
                }

                int indicePivote = (*dimencion) / 2;
                pivote = nuevoSubArreglo[indicePivote];

                int contadorIzq = 0;
                int contadordrch = 0;

                getchar();
                printf("\n ");
                for (int i = 0; i < (*dimencion); i++)
                {
                    if (nuevoSubArreglo[i] > pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadordrch++;
                    }
                    else if (nuevoSubArreglo[i] < pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadorIzq++;
                    }
                }

                int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
                int *nuevoDrch = (int *)malloc((contadordrch - 1) * sizeof(int));

                if (nuevoIzq == 0)
                {
                    nuevoIzq == NULL;
                }
                if (nuevoDrch == 0)
                {
                    nuevoDrch = NULL;
                }

                if (nuevoIzq != NULL && nuevoDrch != NULL)
                {
                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq != NULL && nuevoDrch == NULL)
                {
                    nuevoDrch = NULL;

                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq == NULL && nuevoDrch != NULL)
                {
                    nuevoIzq = NULL;

                    int *nuevoNumeros = (int *)malloc((contadordrch - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadordrch, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
            }

            else
            {
                // quiere decriq eu ya no hay mas datos que ordenar
                return listaOrdenada;
            }
        }
    }

    else if (izq != NULL && drch == NULL)
    {

        indicePivote = tamanio / 2;
        pivote = numeros[indicePivote];

        printf("\n ");
        for (int i = 0; i < tamanio; i++)
        {
            if (numeros[i] > pivote)
            {
                contadorDrch++;
                printf("%d - ", numeros[i]);
            }
            else if (numeros[i] == pivote)
            {
                continue;
            }
            else if (numeros[i] < pivote)
            {
                contadorIzq++;
                printf("%d - ", numeros[i]);
            }
        }

        if (contadorIzq != 0 && contadorDrch != 0)
        {
            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));

            int *nuevosDrch = (int *)malloc((contadorDrch - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_ambosExtremos(listaOrdenada, numeros, tamanio, nuevoIzq, nuevosDrch, contadorIzq, contadorDrch, pivote, colaPivote, indice, tamanioOriginal);

            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevosDrch[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            printf("\n ");
            printf("%d - ", *indice);

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevosDrch, colaPivote, indice);
        }
        else if (contadorIzq != 0 && contadorDrch == 0)
        {
            drch = NULL;
            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_listaIzq(listaOrdenada, nuevoIzq, NULL, contadorIzq, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");

            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, NULL, colaPivote, indice);
        }
        else if (contadorIzq == 0 && contadorDrch != 0)
        {
            izq = NULL;

            int *nuevoDerecho = (int *)malloc((contadorDrch - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_listaDrch(listaOrdenada, NULL, nuevoDerecho, contadorDrch, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevoDerecho[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorDrch - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d -", nuevoDerecho[i]);
                nuevoNumeros[i] = nuevoDerecho[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorDrch, tamanioOriginal, listaOrdenada, NULL, nuevoDerecho, colaPivote, indice);
        }
        else
        {

            int *dimencion = (int *)malloc(sizeof(int));

            dimencion = 0;
            int *nuevoSubArreglo = reasgigarRegistr(listaOrdenada, tamanioOriginal, dimencion, colaPivote, indice, pivote);

            printf("\n ");

            if (nuevoSubArreglo != NULL)
            {
                for (int i = 0; i < (*dimencion); i++)
                {
                    printf("%d- ", nuevoSubArreglo[i]);
                }

                int indicePivote = (*dimencion) / 2;
                pivote = nuevoSubArreglo[indicePivote];

                int contadorIzq = 0;
                int contadordrch = 0;

                getchar();
                printf("\n ");
                for (int i = 0; i < (*dimencion); i++)
                {
                    if (nuevoSubArreglo[i] > pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadordrch++;
                    }
                    else if (nuevoSubArreglo[i] < pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadorIzq++;
                    }
                }

                int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
                int *nuevoDrch = (int *)malloc((contadordrch - 1) * sizeof(int));

                if (nuevoIzq == 0)
                {
                    nuevoIzq == NULL;
                }
                if (nuevoDrch == 0)
                {
                    nuevoDrch = NULL;
                }

                if (nuevoIzq != NULL && nuevoDrch != NULL)
                {
                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq != NULL && nuevoDrch == NULL)
                {
                    nuevoDrch = NULL;

                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq == NULL && nuevoDrch != NULL)
                {
                    nuevoIzq = NULL;

                    int *nuevoNumeros = (int *)malloc((contadordrch - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadordrch, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
            }
            else
            {
                return listaOrdenada;
            }
        }
    }
    else if (izq == NULL && drch != NULL)
    {
        indicePivote = tamanio / 2;
        pivote = numeros[indicePivote];

        printf("\n ");
        for (int i = 0; i < tamanio; i++)
        {
            if (numeros[i] > pivote)
            {
                contadorDrch++;
                printf("%d - ", numeros[i]);
            }
            else if (numeros[i] == pivote)
            {
                continue;
            }
            else if (numeros[i] < pivote)
            {
                contadorIzq++;
                printf("%d - ", numeros[i]);
            }
        }

        if (contadorIzq != 0 && contadorDrch != 0)
        {
            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));

            int *nuevosDrch = (int *)malloc((contadorDrch - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_ambosExtremos(listaOrdenada, numeros, tamanio, nuevoIzq, nuevosDrch, contadorIzq, contadorDrch, pivote, colaPivote, indice, tamanioOriginal);

            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevosDrch[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            printf("\n ");
            printf("%d - ", *indice);

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevosDrch, colaPivote, indice);
        }
        else if (contadorIzq != 0 && contadorDrch == 0)
        {
            drch = NULL;
            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_listaIzq(listaOrdenada, nuevoIzq, NULL, contadorIzq, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");

            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d - ", nuevoIzq[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorIzq; i++)
            {
                printf("%d -", nuevoIzq[i]);
                nuevoNumeros[i] = nuevoIzq[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, NULL, colaPivote, indice);
        }
        else if (contadorIzq == 0 && contadorDrch != 0)
        {
            izq = NULL;

            int *nuevoDerecho = (int *)malloc((contadorDrch - 1) * sizeof(int));

            listaOrdenada = acomodo_lista_listaDrch(listaOrdenada, NULL, nuevoDerecho, contadorDrch, pivote, colaPivote, indice, tamanioOriginal, tamanio, numeros);

            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d - ", nuevoDerecho[i]);
            }

            printf("\n ");
            for (int i = 0; i < tamanioOriginal; i++)
            {
                printf("%d - ", listaOrdenada[i]);
            }

            int *nuevoNumeros = (int *)malloc((contadorDrch - 1) * sizeof(int));
            printf("\n ");
            for (int i = 0; i < contadorDrch; i++)
            {
                printf("%d -", nuevoDerecho[i]);
                nuevoNumeros[i] = nuevoDerecho[i];
            }

            listaOrdenada = quicksort(nuevoNumeros, contadorDrch, tamanioOriginal, listaOrdenada, NULL, nuevoDerecho, colaPivote, indice);
        }
        else
        {

            int *dimencion = (int *)malloc(sizeof(int));

            *dimencion = 0;
            int *nuevoSubArreglo = reasgigarRegistr(listaOrdenada, tamanioOriginal, dimencion, colaPivote, indice, pivote);

            printf("\n ");

            if (nuevoSubArreglo != NULL)
            {
                for (int i = 0; i < (*dimencion); i++)
                {
                    printf("%d- ", nuevoSubArreglo[i]);
                }

                int indicePivote = (*dimencion) / 2;
                pivote = nuevoSubArreglo[indicePivote];

                int contadorIzq = 0;
                int contadordrch = 0;

                getchar();
                printf("\n ");
                for (int i = 0; i < (*dimencion); i++)
                {
                    if (nuevoSubArreglo[i] > pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadordrch++;
                    }
                    else if (nuevoSubArreglo[i] < pivote)
                    {
                        printf("%d - ", nuevoSubArreglo[i]);
                        contadorIzq++;
                    }
                }

                int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
                int *nuevoDrch = (int *)malloc((contadordrch - 1) * sizeof(int));

                if (nuevoIzq == 0)
                {
                    nuevoIzq == NULL;
                }
                if (nuevoDrch == 0)
                {
                    nuevoDrch = NULL;
                }

                if (nuevoIzq != NULL && nuevoDrch != NULL)
                {
                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq != NULL && nuevoDrch == NULL)
                {
                    nuevoDrch = NULL;

                    int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    printf("\n ");

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
                else if (nuevoIzq == NULL && nuevoDrch != NULL)
                {
                    nuevoIzq = NULL;

                    int *nuevoNumeros = (int *)malloc((contadordrch - 1) * sizeof(int));

                    nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                    for (int i = 0; i < tamanioOriginal; i++)
                    {
                        printf("%d -", listaOrdenada[i]);
                    }

                    listaOrdenada = quicksort(nuevoNumeros, contadordrch, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
                }
            }
            else
            {
                return listaOrdenada;
            }
        }
    }
    else if (izq == NULL && drch == NULL)
    {
        // este sera el caso con el cual ya acabmos de hacer nuestro recorrido?
        // la busqueda si hay indices que no han sido pivotes, creo que deberia de estar aqui.

        // si llega aqui hya varias razones
        // no encontro ninun dato, por lo que el pivote ya esta ordenado.

        int *dimencion = (int *)malloc(sizeof(int));

        dimencion = 0;
        int *nuevoSubArreglo = reasgigarRegistr(listaOrdenada, tamanioOriginal, dimencion, colaPivote, indice, pivote);

        printf("\n ");

        if (nuevoSubArreglo != NULL)
        {
            for (int i = 0; i < (*dimencion); i++)
            {
                printf("%d- ", nuevoSubArreglo[i]);
            }

            int indicePivote = (*dimencion) / 2;
            pivote = nuevoSubArreglo[indicePivote];

            int contadorIzq = 0;
            int contadordrch = 0;

            getchar();
            printf("\n ");
            for (int i = 0; i < (*dimencion); i++)
            {
                if (nuevoSubArreglo[i] > pivote)
                {
                    printf("%d - ", nuevoSubArreglo[i]);
                    contadordrch++;
                }
                else if (nuevoSubArreglo[i] < pivote)
                {
                    printf("%d - ", nuevoSubArreglo[i]);
                    contadorIzq++;
                }
            }

            int *nuevoIzq = (int *)malloc((contadorIzq - 1) * sizeof(int));
            int *nuevoDrch = (int *)malloc((contadordrch - 1) * sizeof(int));

            if (nuevoIzq == 0)
            {
                nuevoIzq == NULL;
            }
            if (nuevoDrch == 0)
            {
                nuevoDrch = NULL;
            }

            if (nuevoIzq != NULL && nuevoDrch != NULL)
            {
                int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                printf("\n ");

                for (int i = 0; i < tamanioOriginal; i++)
                {
                    printf("%d -", listaOrdenada[i]);
                }

                listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
            }
            else if (nuevoIzq != NULL && nuevoDrch == NULL)
            {
                nuevoDrch = NULL;

                int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));

                nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                printf("\n ");

                for (int i = 0; i < tamanioOriginal; i++)
                {
                    printf("%d -", listaOrdenada[i]);
                }

                listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
            }
            else if (nuevoIzq == NULL && nuevoDrch != NULL)
            {
                nuevoIzq = NULL;

                int *nuevoNumeros = (int *)malloc((contadordrch - 1) * sizeof(int));

                nuevoNumeros = regresar_nuevoSubArreglo(nuevoSubArreglo, dimencion, nuevoIzq, nuevoDrch, contadorIzq, contadordrch, nuevoSubArreglo, pivote, listaOrdenada, tamanioOriginal, indice);

                for (int i = 0; i < tamanioOriginal; i++)
                {
                    printf("%d -", listaOrdenada[i]);
                }

                listaOrdenada = quicksort(nuevoNumeros, contadordrch, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
            }
        }
        else
        {
            return listaOrdenada;
        }
    }

    return (listaOrdenada);
}

int *acomodo_lista_ambosExtremos(int *listaOrdenada, int *numeros, int tamanio, int *izq, int *drch, int contadorIzq, int contadorDrch, int pivote, int *colaPivote, int *indice, int tamaniOriginal)
{

    int O = 0;
    int ContadorCola = 0;
    int econtrado = 0;

    // // amos a ver si no pierdo los datos
    // free(izq);
    // free(drch);
    // izq = NULL;
    // drch = NULL;
    // izq = (int *)realloc(izq, contadorIzq * sizeof(int));
    // drch = (int *)realloc(drch, contadorDrch * sizeof(int));
    int asignacionDercha = 0;
    int asignacionIzq = (contadorIzq - 1);
    /*********asignaodo derecha - izq */
    printf("\n ");
    for (int i = 0; i < tamanio; i++)
    {
        // quiero que sea lo mas parecido a la logica
        if (numeros[i] > pivote)
        {
            drch[asignacionDercha] = numeros[i];
            (asignacionDercha)++;
            printf("%d - ", numeros[i]);
        }
        else if (numeros[i] == pivote)
        {
            continue;
        }
        else
        {
            izq[asignacionIzq] = numeros[i];
            (asignacionIzq)--;
            printf("%d - ", numeros[i]);
        }
    }
    /*creo que esto esta mal, la logica, mejor seria el primer elmeneot de izquerda a dercha que no sea un pivote, es casi seguro que esos seran los registros. */
    while (econtrado == 0)
    {
        int comparador = listaOrdenada[O];
        while (ContadorCola < tamaniOriginal)
        {
            if (comparador != colaPivote[ContadorCola])
            {
                ContadorCola++;
                econtrado = 0;
            }
            else
            {
                econtrado = 1;
                break;
            }
        }
        if (econtrado == 0 && ContadorCola >= tamaniOriginal)
        {
            econtrado = 1;
            break;
        }
        if (econtrado == 1)
        {
            // esty preguntadno si se llego al final
            O++;
            ContadorCola = 0;
        }
    }

    // en este momneto O tiene hasta donde voy a parar
    // int Ord;
    printf("\n ");
    for (int i = 0; i < contadorIzq; i++)
    {
        printf("%d - ", izq[i]);
        listaOrdenada[O] = izq[i];
        O++;
    }
    printf("%d", pivote);
    listaOrdenada[O] = pivote;
    O++;
    printf("\n ");
    for (int i = 0; i < contadorDrch; i++)
    {
        printf("%d - ", drch[i]);
        listaOrdenada[O] = drch[i];
        O++;
    }
    printf("\n ");
    for (int i = 0; i < tamaniOriginal; i++)
    {
        printf("%d - ", listaOrdenada[i]);
    }

    // agregmaos el pivote a la cola

    colaPivote[*indice] = pivote;
    (*indice)++;
    return listaOrdenada;
}

int *acomodo_lista_listaIzq(int *listaOrdenada, int *izq, int *drch, int contadorIzq, int pivote, int *colaPivote, int *indice, int tamaniOriginal, int tamanio, int *numeros)
{

    int asignacionIzq = (contadorIzq - 1);
    int asigancionDrhc = 0;

    printf("\n ");
    for (int i = 0; i < tamanio; i++)
    {
        if (numeros[i] == pivote)
        {
            continue;
        }
        if (numeros[i] < pivote)
        {
            izq[asignacionIzq] = numeros[i];
            asignacionIzq--;
            printf("%d -", numeros[i]);
        }
        else
        {
            continue;
        }
    }

    // yp que todos los datos que se me mando estan edl lado izquierdo.

    int O = 0;
    int ContadorCola = 0;
    int econtrado = 0;

    while (econtrado == 0)
    {

        int comparador = listaOrdenada[O];

        while (ContadorCola < tamaniOriginal)
        {
            if (comparador != colaPivote[ContadorCola])
            {
                ContadorCola++;
                econtrado = 0;
            }
            else
            {
                econtrado = 1;
                break;
            }
        }

        if (econtrado == 0 && ContadorCola >= tamaniOriginal)
        {
            econtrado = 1;
            break;
        }
        if (econtrado == 1)
        {
            O++;
            ContadorCola = 0;
        }
    }

    for (int i = 0; i < contadorIzq; i++)
    {
        listaOrdenada[O] = izq[i];
        O++;
    }

    listaOrdenada[O] = pivote;

    printf("\n ");
    for (int i = 0; i < tamaniOriginal; i++)
    {
        printf("%d - ", listaOrdenada[i]);
    }

    colaPivote[*indice] = pivote;
    (*indice)++;
    return listaOrdenada;

    // ahora a buscar
}

int *acomodo_lista_listaDrch(int *listaOrdenada, int *izq, int *drch, int contadordrch, int pivote, int *colaPivote, int *indice, int tamaniOriginal, int tamanio, int *numeros)
{

    int asigancionDercha = 0;

    printf("\n ");
    for (int i = 0; i < tamanio; i++)
    {
        if (numeros[i] == pivote)
        {
            continue;
        }
        if (numeros[i] > pivote)
        {
            drch[asigancionDercha] = numeros[i];
            asigancionDercha++;
            printf("%d -", numeros[i]);
        }
        else
        {
            continue;
        }
    }

    // ahora toca encontrar en donde se ingresa

    int O = 0;
    int ContadorCola = 0;
    int econtrado = 0;

    while (econtrado == 0)
    {
        int comparador = listaOrdenada[O];

        while (ContadorCola < tamaniOriginal)
        {
            if (comparador != colaPivote[ContadorCola])
            {
                ContadorCola++;
                econtrado = 0;
            }
            else
            {
                econtrado = 1;
                break;
            }
        }

        if (econtrado == 0 && ContadorCola >= tamaniOriginal)
        {
            econtrado = 1;
            break;
        }
        if (econtrado == 1)
        {
            O++;
            ContadorCola = 0;
            econtrado = 0;
        }
    }

    printf("\n ");
    listaOrdenada[O] = pivote;
    O++;
    for (int i = 0; i < contadordrch; i++)
    {
        listaOrdenada[O] = drch[i];
        O++;
    }

    printf("\n ");
    for (int i = 0; i < tamaniOriginal; i++)
    {
        printf("%d - ", listaOrdenada[i]);
    }

    colaPivote[*indice] = pivote;
    (*indice)++;

    return listaOrdenada;
}

// otra funcion que devuelve el proximo livel a encontrar
int *reasgigarRegistr(int *listaOrdenada, int tamanioOriginal, int *dimencion, int *colaPivote, int *indice, int pivote)
{

    int O = 0;
    int encontrado = 0;
    int contadorCola = 0;
    while (encontrado = 0)
    {
        int comparador = listaOrdenada[O];

        while (contadorCola < tamanioOriginal)
        {
            if (comparador == colaPivote[contadorCola])
            {
                contadorCola++;
                encontrado = 0;
            }
            else
            {
                encontrado = 1;
                break;
            }
        }

        if (encontrado == 0 && contadorCola == tamanioOriginal)
        {
            encontrado = 1;
            break;
        }
        else
        {
            O++;
            contadorCola = 0;
        }
    }

    listaOrdenada[++O] = pivote;

    colaPivote[*indice] = pivote;
    (*indice)++;

    // ahora a buscar la proxima seccion

    // pero tomando en cuenta que si ya estan todos como pivote regresamos ya a todo.

    // si lo hago funciones este me deberia de devilver el arreglo de la nueva seccion

    // variables a tomar en cuneta
    // un indice que indicque el inicio
    // un indicque que indique el final
    // un contador para conocer el tamano del arreglo. (restamos los indices que me da el valor)
    int indiceInical = 0;
    int indiceFinal = 0;
    encontrado = 0;
    O = 0;
    int indiceCola = 0;
    while (encontrado == 0)
    {
        int comparador = listaOrdenada[O];

        while (indiceCola < tamanioOriginal)
        {
            if (comparador != colaPivote[indiceCola])
            {
                indiceCola++;
                encontrado = 1;
            }
            else if (comparador == colaPivote[indiceCola])
            {
                O++;
                comparador = listaOrdenada[O];
                indiceCola = 0;
            }
        }

        if (O == tamanioOriginal && encontrado == 0)
        {
            // si al inicio no se enceuntro se manda nnulo
            return NULL;
        }
        else
        {
            if (encontrado == 1 && (indiceInical == 0 || indiceFinal == 0) && indiceCola == tamanioOriginal)
            {
                indiceInical = O;
                O++;
                encontrado = 0;
                indiceCola = 0;
            }

            // ahora necesito buscar hasta el proximo pivote
            while (encontrado == 0)
            {
                comparador = listaOrdenada[O];
                while (indiceCola < tamanioOriginal)
                {
                    if (comparador != colaPivote[indiceCola])
                    {
                        indiceCola++;
                        encontrado = 1;
                    }
                    else if (comparador == colaPivote[indiceCola])
                    {
                        encontrado = 0;
                        break;
                    }
                }

                if (encontrado == 1 && indiceCola >= tamanioOriginal)
                {
                    // es un indicq el cual no esta dentro de la cola de pivotes por lo que no me interas, quiero buscar hasta el indice que se aun pivote.
                    // indiceFinal = O;
                    // encontrado = 1;
                    // break;
                    O++;
                    indiceCola = 0;
                    encontrado = 0;
                }
                else if (indiceCola < tamanioOriginal && encontrado == 0)
                {
                    // O++;
                    // contadorCola = 0;
                    // encontrado = 0;

                    indiceFinal = O;
                    encontrado = 1;
                    break;
                }
            }
        }
        int tamanio = (indiceFinal - indiceInical);
        // dimencion = (int *)malloc(tamanio * sizeof(int));
        *dimencion = tamanio;

        int *nuevoArreglo = (int *)malloc((tamanio - 1) * sizeof(int));

        int A = 0;
        for (int i = indiceInical; i < indiceFinal; i++)
        {
            nuevoArreglo[A] = listaOrdenada[i];
            printf("%d", listaOrdenada[i]);
            A++;
        }

        for (int i = 0; i < (*dimencion); i++)
        {
            printf("%d -", nuevoArreglo[i]);
        }

        return (nuevoArreglo);
    }
}

int *regresar_nuevoSubArreglo(int *numeros, int *dimencion, int *nuevoIzq, int *nuevoDrch, int contadorIzq, int contadordrch, int *nuevoSubArreglo, int pivote, int *listaOrdenada, int tamanioOriginal, int *indice)
{
    if (nuevoIzq != NULL && nuevoDrch != NULL)
    {
        int auxIzq = (contadorIzq - 1);
        int auxDrch = 0;
        printf("\n ");
        for (int i = 0; i < (*dimencion); i++)
        {
            if (nuevoSubArreglo[i] > pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                nuevoDrch[auxDrch++] = nuevoSubArreglo[i];
            }
            else if (nuevoSubArreglo[i] == pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                continue;
            }
            else if (nuevoSubArreglo[i] < pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                nuevoIzq[auxIzq--] = nuevoSubArreglo[i];
            }
        }

        int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
        printf("\n ");
        for (int i = 0; i < contadorIzq; i++)
        {
            nuevoNumeros[i] = nuevoIzq[i];

            printf("%d -", nuevoIzq[i]);
        }

        return (nuevoNumeros);

        // listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
    }
    else if (nuevoIzq != NULL && nuevoDrch == NULL)
    {
        int auxIzq = (contadorIzq - 1);
        printf("\n ");
        for (int i = 0; i < (*dimencion); i++)
        {

            if (nuevoSubArreglo[i] == pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                continue;
            }
            else if (nuevoSubArreglo[i] < pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                nuevoIzq[auxIzq--] = nuevoSubArreglo[i];
            }
        }

        int *nuevoNumeros = (int *)malloc((contadorIzq - 1) * sizeof(int));
        printf("\n ");
        for (int i = 0; i < contadorIzq; i++)
        {
            nuevoNumeros[i] = nuevoIzq[i];
            printf("%d -", nuevoIzq[i]);
        }

        return (nuevoNumeros);

        // listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
    }
    else if (nuevoIzq == NULL && nuevoDrch != NULL)
    {

        int auxDrch = 0;
        printf("\n ");
        for (int i = 0; i < (*dimencion); i++)
        {
            if (nuevoSubArreglo[i] > pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                nuevoDrch[auxDrch++] = nuevoSubArreglo[i];
            }
            else if (nuevoSubArreglo[i] == pivote)
            {
                printf("%d - ", nuevoSubArreglo[i]);
                continue;
            }
        }
        printf("\n ");
        int *nuevoNumeros = (int *)malloc((contadordrch - 1) * sizeof(int));

        for (int i = 0; i < contadordrch; i++)
        {
            printf("%d -", nuevoDrch[i]);
            nuevoNumeros[i] = nuevoDrch[i];
        }

        return (nuevoNumeros);
        // listaOrdenada = quicksort(nuevoNumeros, contadorIzq, tamanioOriginal, listaOrdenada, nuevoIzq, nuevoDrch, colaPivote, indice);
    }
}