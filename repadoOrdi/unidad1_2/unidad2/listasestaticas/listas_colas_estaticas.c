#include <stdio.h>
#include <stdlib.h>

// int *push(int *inicio, int *tope, int tamanio, int dato);
void mostrar(int tamanio, int *inicio);
int vacia(int tamanio, int *inicio, int comienzoEstr);

int main(void)
{
    /*el primero lugar tenemos lo que son las colas y pílas estaticas, que con estas, son estructura de datos (en el caso de estaticas vectores) de un tamanio definido.
    por lo que podemos relaizar las operaciones bsicas que serian el push y pop para pila, porque en cola tiene un nombre diferetnei */

    int pila[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cola[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // podriamos hacerlo desde aqui, pero prefiero hacelo desde funciones,
    // porque en una cola no se puede llamar push y pop, porque estos reciben el nombre de una accion "natural" que se realizaria en una pila nomral, una pila sigue el orden LIFO, Last int, Firt out, y una cola sigue el orden de FIFO, First in First out.

    // una cola ese comportamiento se le conoce como (ingresoi -> enqueque) y eliminar (dequeque)

    // en este tipo de pilas y colas con arreglos, lo que me confunde mas que nada es en donde yo yomo el frente y el final, creo que esto se puede tomar como cada quien, pero yp tomare el < indice mas grande como el tope de la pila o cola el frente >

    // entonces para el ingreso de una pila nos iremos recorriente junto con el tope hasta llegar a llenar a la pila

    // en caso contrario en una cola, en una cola nos iremos a¿hasta el ultimo indice e iremode decrementanod hasta llegar al indice 0, la parte baja de nuestra cola
    int opc, dato;

    // variables para la pila
    int tope = -1;
    int tamanioPila = (sizeof(pila) / sizeof(pila[0]));
    // variables para la cola

    int tamanioCola = (sizeof(cola) / sizeof(cola[0]));
    int indiceCola = tamanioCola - 1;
    int incioCola = tamanioCola;
    // variamos en conjunto

    do
    {
        printf("\n1) push (pila) ");
        printf("\n2) pop (pila) ");

        printf("\n3) ingreso (cola) ");
        printf("\n4) eliminacion (cola)");

        printf("\n5) vacia Pila?");
        printf("\n6) vacia cola?");

        printf("\n10) mostrar Pila");
        printf("\n11) mostrar Cola");

        printf("\n:");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            if (tope < tamanioPila)
            {
                tope++;
                printf("\ningrese el dato a ingresar: ");
                scanf("%d", &pila[tope]);
            }
            else
            {
                printf("\nla pila ya se ecnuentra llena ");
            }
            break;
        case 2:
            // pop de una pila
            if (tope >= 0)
            {
                printf("\nel frente del tope es: %d", pila[tope]);
                pila[tope] = 0;
                tope--;
            }
            else
            {
                printf("\nla pila se cuentra vacia");
            }

            break;

        case 3:
            // INGREOS A la cola

            if (indiceCola >= 0)
            {
                printf("\ningrese el dato a la cola:");
                scanf("%d", &cola[indiceCola]);
                indiceCola--;
            }
            else
            {
                printf("\nla cola yta esta llena");
            }
            break;

        case 4:
            if (incioCola >= 0)
            {
                printf("\nel tope de la cola es: %d ", cola[incioCola]);
                cola[incioCola] = 0;
                incioCola--;
            }
            else
            {
                printf("\nla cola ya esta vacia");
            }
            break;

        case 5:

            break;

        default:
            printf("\nla opcion no se eneucentra registrada, por favor verfique la opcion.");
            break;
        }

    } while (opc != 100);
}

void mostrar(int tamanio, int *inicio)
{

    for (int i = 0; i < tamanio; i++)
    {
        printf("%d -", inicio[i]);
    }
}

int vacia(int tamanio, int *inicio, int comienzoEstr)
{
    // como va ser esto, para esot obivmanete necesito recorrer la estrucutra

    int c = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (inicio[comienzoEstr] == 0)
        {
            c++;
            comienzoEstr--;
            continue;
        }
        else if (inicio[comienzoEstr] != 0)
        {
            // si hay un dato diferente este retornar un 0 indiciando que no esta vacia
            return 0;
        }
    }

    if (c >= tamanio)
    {
        // indicnado que esta vacia
        return 1;
    }
}

// esta funcion buscara pero si cunetra un 0, regresara un 0 indicando un false que no esta llena
int llena(int tamanio, int *inicio, int comienzoEstr)
{
}