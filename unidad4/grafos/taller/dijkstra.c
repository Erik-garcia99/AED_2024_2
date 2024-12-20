/*
garcia chavez erik 01275863

algoritmos y estrucuctura de datos

practica recorrido de grafos dijsktra

 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// necesito saber cunatas estrucutras seran las que usare

// creo que seran 2

// 1 - contiene el nodo y sus datos

// 2 - contiene la lista de adyacencia

// este nodo representara cada nodo del grafo dentro de la lista de adyacencia, pero
// si una union se repite se debe de crear otro nodo con otra direccion de memoria pero con el mismo identificador. para que no se sobre escriba las otras uniones.
struct Nodo
{

    char nombre;
    int peso;
    int visitado;
    struct Nodo *sig;
};

struct listaAdy
{
    // datos que necsitara para la representacion de mi grafo,
    // viendo la repersentacion.

    // el primro el indice del grafo, este es idependindo del nodo. este indice sera un identificador de tipo char
    char indiceListAdy;
    // la froma de como se ingresan es mas parecido a una cola que a una lista.

    struct listaAdy *sig; // este sigueinte, es hacia el sigueinte indice dentreo de la lista de adyacencia, (aunque parezca mas una cola. )

    // tengo el indice, el indice apuntara a un nodo, pero si ese puntero esta en NULL, quiere decir que
    struct Nodo *nodoInterior;
};

struct nodosVisitar_visitados
{

    struct listaAdy *nodoActual;
    struct nodosVisitar_visitados *sig;
};

// la representacion del camino mas corto con dijsktra
struct tablaDijkstra
{
    struct listaAdy *nodo;
    int distanciaCorta; // 2,174,483,647
    // para el nodo previo como lo estria representando,
    // primero podria trabajar con una trucutura de este mismo
    // struct Nodo *nodoPrevio;
    int NodoVisitado;

    struct tablaDijkstra *nodoPrevio;
    // para representar la tabala agregamos un sig, pero para el algoritmo no funciona para nada solo para la represencacion

    struct tablaDijkstra *sig;
};
// struct tablaDijkstra
// {

//     struct tabalaDijkstra *anterior;
//     // representea al sigueinte nodo dentro del indice

//     struct Nodo *sigueinteInterior;
// };

// declaraciones de funciones, recibe el nombre y el
struct Nodo *crearNodo(char nombre, int peso);
struct listaAdy *crearIndice(char nombre);
// en caso que la lista ya se haya inciado
struct listaAdy *agregarIndice(char nombre, struct listaAdy *inicio);
// ahora si, agregar un nodo con el indice que ser la rpresentacion del grafo.

// necsito el inicio de mi lista de adyacencia, para buscar el nodo con el idenficador el cual se asociara un nuevo conexion, ocupo los valores del la conexion, como
/*el indice A esya conextcado con B con una arista de peso 100.
por lo que va a crear el nodo B con el peso de 100, entonces buscara dentro
de ese indice en la parte derecha si no hay un nodo con ese identificador se crea y se agrega al final de la cola.
*/
struct listaAdy *agregarConexion(struct listaAdy *inicio, char identificadorIndice, char nombreNodo, int pesoConexion);

// algoritmo

struct nodosVisitar_visitados *crearCola_visitar(struct listaAdy *nodo);
struct nodosVisitar_visitados *agregarCola_visitar(struct nodosVisitar_visitados *inicio, struct listaAdy *nodo);
// struct nodosVisitados *crearCola_visitados(struct listaAdy *nodo);
struct tablaDijkstra *agregar_sigueinteNodo(struct tablaDijkstra *inicio, struct listaAdy *nodo, int nodoInicio);
struct tablaDijkstra *algoritmo(struct nodosVisitar_visitados *colaDeNodos, struct nodosVisitar_visitados *cola_nodosVisitados, struct listaAdy *listaNodos, char nodoInicio, char nodoFinal);
struct tablaDijkstra *crearTabla_inicio(struct listaAdy *nodo, int nodoIncio);
void mostrarTabla(struct tablaDijkstra *inicio);

struct nodosVisitar_visitados *traspaso(struct nodosVisitar_visitados *nodoPorVisitar, struct nodosVisitar_visitados *nodosVisitados);

int main(void)
{

    struct Nodo *nodoInterior = NULL;
    struct listaAdy *lista_de_adyacencias = NULL;

    // primero debemos crear la lista de adyacencias
    char nodos[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // char nodos[20]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'};

    for (int i = 0; i < 6; i++)
    {
        if (lista_de_adyacencias == NULL)
        {
            lista_de_adyacencias = crearIndice(nodos[i]);
        }
        else
        {
            lista_de_adyacencias = agregarIndice(nodos[i], lista_de_adyacencias);
        }
    }
    //                                    (lista,indice de la lista, nodo de conexion, peso de la arista)
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'D', 10);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'B', 50);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'C', 45);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'D', 15);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'C', 10);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'C', 'E', 30);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'D', 'E', 15);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'D', 'A', 10);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'E', 'F', 3);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'E', 'C', 35);
    lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'E', 'B', 20);

    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'D', 85);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'D', 30);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'A', 'B', 100);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'A', 100);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'E', 40);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'F', 45);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'G', 70);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'B', 'C', 100);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'C', 'B', 100);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'C', 'G', 55);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'C', 'H', 60);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'D', 'A', 30);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'D', 'A', 85);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'D', 'P', 50);
    // lista_de_adyacencias = agregarConexion(lista_de_adyacencias, 'E', 'I', 10);

    // ahora a agregar esos datos de la listya de adyacencia a la cola de

    /*-----------creo que esto no deberia ir a qui, si no ser una representacion en */
    struct nodosVisitar_visitados *cola_nodosVisitar = NULL;
    struct nodosVisitar_visitados *cola_nodosVisitados = NULL;

    struct listaAdy *aux = lista_de_adyacencias;
    while (aux != NULL)
    {
        if (cola_nodosVisitar == NULL)
        {
            cola_nodosVisitar = crearCola_visitar(aux);
            aux = aux->sig; // sigueinte elemento dentro de la lista de adyacencias
        }
        else
        {
            cola_nodosVisitar = agregarCola_visitar(cola_nodosVisitar, aux);
            aux = aux->sig;
        }
    }

    // a como lo estoy poniendo preferible tal vez en un do-while por si el nodo no esta volver a ingresarlo, por por ahora no, por ahora los datos seran correctos.
    struct tablaDijkstra *dijkstra = NULL;
    // ahora mando a llamar ala algoritmo y me regresara la tabala completa
    dijkstra = algoritmo(cola_nodosVisitar, cola_nodosVisitados, lista_de_adyacencias, 'A', 'F');
    getchar();
}

/*--------------------CREACION DE LA LISTA DE ADYACENCIAS--------------------------------------------------*/
// crea la uncion entre el identificador de la lista de adyacencia y el nodo el cual esta relacionado
/*
por dar un ejemplo
(por cierto esta forma tal vez podremos hacer que A tenga 2 caminos hacia el mismo nodo, )
LA     NODO
A -> |D|30|0xF87| -> este va a apuntar al sigueinte nodo. cada nodo si se repite es diferente
                    en espacio de memoria



 */
struct Nodo *crearNodo(char nombre, int peso)
{
    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = NULL;
    nuevo->visitado = 0; // este es para los nodos que estan relacionados con el idnice de la lista de adyacencia no corresponde sobre la marca de visitados de dijkstra

    return (nuevo);
}

struct listaAdy *crearIndice(char nombre)
{

    struct listaAdy *nuevo;
    nuevo = (struct listaAdy *)malloc(sizeof(struct listaAdy));
    nuevo->indiceListAdy = nombre;
    nuevo->sig = NULL;
    nuevo->nodoInterior = NULL;

    return (nuevo);
}

struct listaAdy *agregarIndice(char nombre, struct listaAdy *inicio)
{
    struct listaAdy *nuevo;
    struct listaAdy *aux = inicio;
    nuevo = crearIndice(nombre);
    // como la lista se comporta mas bien como una cola, por lo que agregamos como si fuera una cola.

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;

    return (inicio);
}

struct listaAdy *agregarConexion(struct listaAdy *inicio, char identificadorIndice, char nombreNodo, int pesoConexion)
{
    struct listaAdy *aux = inicio;
    struct Nodo *nodoConexion;
    struct listaAdy *nodoInterior;
    struct Nodo *recorridoNodoInterior = NULL;
    // en este momento este nodo esta al aire, no esta asoaciado a nada.
    nodoConexion = crearNodo(nombreNodo, pesoConexion);
    int indiceEncontrado = 0;

    /* esto puede que al final no quede del todo

    int nodoEncontrado = 0; // solo funciona para yo saber si hay un nodo con ese nombre o no, mas alla no teiene una funcion mas alla de tal vez poder imprimir un mensaje.
    // ahora necsito buscar la direccion en donde esta el indice al cual quiero asociar el nodo con la conexion*/

    while (aux != NULL && indiceEncontrado == 0)
    {
        if (aux->indiceListAdy != identificadorIndice)
        {
            aux = aux->sig;
            indiceEncontrado = 0;
        }
        else
        {
            indiceEncontrado = 1;
        }
    }

    // en estos if-else if, verificare si se encontro o no el indice dentro de la lista (cola)
    if (aux != NULL)
    {
        // quier decir que el indice se enceuntra dentro de la lista de adyacencia
        // por lo que ahora necesito saber 2 cosas, si tiene conexiones si no es asi, se agrega y si tiene buscar el final de la cola
        if (aux->nodoInterior != NULL)
        {
            recorridoNodoInterior = aux->nodoInterior;

            while (recorridoNodoInterior->sig != NULL)
            {
                recorridoNodoInterior = recorridoNodoInterior->sig;
            }
            recorridoNodoInterior->sig = nodoConexion;

            /*---------------------------------------------
             // quiere decir que ya hay una conexion asociada a este idice
             // necitamosa concer el ultimo nodo asociado y que no hay un nodo con el mimso
             // identificador, esto para evitar redundacnai o errores a la hora se aplicar el algoritmo

             // while (aux->nodoInterior->sig != NULL)
             // {
             //     if (aux->nodoInterior->nombre != nodoConexion->nombre)
             //     {
             //         aux->nodoInterior = aux->nodoInterior->sig;
             //         nodoEncontrado = 0;
             //     }
             //     else
             //     {
             //         nodoEncontrado = 1;
             //         break; // salimos del ciclo
             //     }
             // }

             // if (nodoEncontrado != 0)
             // {
             //     // osea que hay un nodo con el miso identificador y muy posibklemente con el mimso peso, no se agregara
             //     printf("el nodo de conexion ya se cunetra asociado al indice ingreasdo\n");
             // }
             // else
             // {
             //     // en otro caso ahora aux tiene el nodo ultimo de ese indice
             // }
            ---------------------------------------------------------------*/
        }
        else
        {
            // no hay conexion asociada al indice, si no hay tan solo se asociada
            aux->nodoInterior = nodoConexion;
        }
    }
    // no se encontro por lo que se crea y se le asocia el nodo de conexcion
    // se puede dar el caso pero no es el ideal
    else if (aux == NULL)
    {
        struct listaAdy *nuevoIndice = agregarIndice(identificadorIndice, inicio);
        // el nodo de conexion ya ha sido creado.
        inicio = agregarConexion(inicio, identificadorIndice, nombreNodo, pesoConexion);
    }

    return (inicio);
}

/*-----------------------------------------------------------------------------------------------------*/
/*----------------------------algoritmo dijkstra-------------------------------------*/
/*


mi algoritmos constara de 2 colas, 1 en donde estan representados todos los nodos y otra en donde estan los

la profe quieroe se se represente la tabala cada que se procese un nodo

como necesito saber que nodos estan asociados a ¿mi nodo, necesito la lista de adyacencias para eso.

// necesito hacer saber como voy a representar la tabala aqui.

*/
/*------------------------------------------------------------------------------------ */

// creando la cola en donde se ingresaran todos los nodos que aun no han diso visitados, en primre ainstancia se ingresaran todos los de lña lista de adyacncia

struct nodosVisitar_visitados *crearCola_visitar(struct listaAdy *nodo)
{
    struct nodosVisitar_visitados *nuevo;
    nuevo = (struct nodosVisitar_visitados *)malloc(sizeof(struct nodosVisitar_visitados));

    nuevo->nodoActual = nodo;
    nuevo->sig = NULL;
    // no se si ira dentro.
    // nuevo->marcado=0;
}

struct nodosVisitar_visitados *agregarCola_visitar(struct nodosVisitar_visitados *inicio, struct listaAdy *nodo)
{
    struct nodosVisitar_visitados *aux = inicio;
    struct nodosVisitar_visitados *nuevo = crearCola_visitar(nodo);

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;

    return (inicio);
}

struct tablaDijkstra *algoritmo(struct nodosVisitar_visitados *colaDeNodos, struct nodosVisitar_visitados *cola_nodosVisitados, struct listaAdy *listaNodos, char nodoInicio, char nodoFinal)
{

    // es la lista de adyacncia que hace de representacion del grafo.
    struct listaAdy *auxListaNodos = listaNodos;
    // este sera el respaldo general, este nunca se debe de modificar.
    struct listaAdy *RespaldogeneralAdy = listaNodos;
    // cola de los nodos los cuales no han sido visitados
    struct nodosVisitar_visitados *visitar = colaDeNodos;
    // cola de nodos que ya han diso visitados.
    struct nodosVisitar_visitados *visitados = cola_nodosVisitados;

    // crear mi tabla
    struct tablaDijkstra *tabla = NULL; // esto es lo que debe de devolver esta funcion, la tabala que es la represetncacion de la tabla con su recorrido
    int cambio = 0;

    // ------------quiero iniciar mi tabala de dijkstra--------------
    while (auxListaNodos != NULL)
    {
        // estamos incializando la tabla de dijkstra

        // recibe como parametro el nodo con el que se quiere inicar. por lo que el primero elemento en nuestra tabla es ese nodo de la lista de adyacencias
        /*
        como sera el algoritmo para asignar en la tabla de dikstra
        -primero como se menciono, se buscara el nodo con el cual se quiere inicar, entonces ese sera mi primer item en la tabla,
        -despues de eso se regresara al incio de la lista, en el cual se agregaran los siguientes nodos siem,pre y cunado no sea el nodo de inciio, si es asi se debe de brincar al sigueinte
        */

        if (tabla != NULL)
        {
            // si se inicio correctamnete la tabla, entonces despues de eso siempre inicara aqui.
            if (auxListaNodos->indiceListAdy != nodoInicio)
            {

                // siempre que sea diferente se agrega a la tabala (lista)
                // como la tabla en este punto ya esta iniciada por lo que ahora tan solo estamos agregando
                tabla = agregar_sigueinteNodo(tabla, auxListaNodos, 0);
                auxListaNodos = auxListaNodos->sig;
            }
            else
            {
                // si se topa con el nodo que es igual al nodo icnial tan solo lo brincamos por que el ya esta
                auxListaNodos = auxListaNodos->sig;
            }
        }
        else
        {
            /*
            la unica vez que entrara a esye if, es bastante obvio, es cunado no se ha enconetrado el nodo con el que se quiere inciar, por lo que aqui adentro

            -primero se buscra el nodo como ya se menciono
            */

            while (auxListaNodos != NULL)
            {
                // porque pongo lo mismo que arriba, porque cunado entra en efecto tabla sera igual a NULL
                // por lo que puedeo poner eso

                if (auxListaNodos->indiceListAdy != nodoInicio)
                {
                    // si es diferente que es lo que quiero?, seguir buscando, por lo que mientras que
                    auxListaNodos = auxListaNodos->sig;
                }
                else
                {
                    // lo encontro siiiii
                    // inicamos la tabla
                    // auxListaNodos contiene el nodo de inicio
                    tabla = crearTabla_inicio(auxListaNodos, 1);
                    // por lo que ahora neceistmoas restablecer auxListaNodos
                    auxListaNodos = RespaldogeneralAdy; // se restablece la lista adyacente}
                    break;                              // cortamos este ciclo
                }
            }
            if (auxListaNodos == NULL)
            {
                // quier decir que no se conetro por lo que volvemos de donde nos llamaron
                return tabla; // <- va a retornal NULL
            }
            // si no va a salir y ahora ingresara los demas
        }
    }

    // busc ala distancias mas corta dentro de la tabala.
    // -----------------------------------------
    mostrarTabla(tabla);
    // guardo mi inicio, un respaldo
    // restablesco los valores por defecto en la tabala
    struct tablaDijkstra *respaldoInicioTabala = tabla;
    struct tablaDijkstra *indiceTablaActual = NULL;
    struct tablaDijkstra *indiceTablaVisitando = NULL;
    // este es el nodo de apoyo con el que voy a comparar los pesos
    struct tablaDijkstra *segundoComparador = NULL;
    struct tablaDijkstra *indiceComparador = NULL;
    int distanciaMinima;
    // mientras yo tenga datos en mi cola de nodos por visitar aun no termino con mi algoritmo
    while (visitar != NULL)
    {
        // como ya sabemos cual es nuestro nodo de referencia, es el primero elemento en nuetra tabala.

        /*que dicta el algoritmo?
        se tiene en primero lugar  */

        // cunado inicia quien tiene la distancia mas corta?, el nodo inicial que tiene 0 mienttras que los demas tiene distancia "INF", por lo que este necsesita buscar el nodo con la distancia mas corta y marcarlo como definitivo

        // primero buscamos el indice con la distacnaic mas corta
        // while (segundoComparador != NULL && cambio == 0)
        // {
        //     segundoComparador = tabla;

        //     while (cambio == 0 && segundoComparador != NULL)
        //     {
        //         if (indiceTablaActual->distanciaCorta < segundoComparador->distanciaCorta)
        //         {
        //             segundoComparador = segundoComparador->sig;
        //         }
        //         else
        //         {
        //             indiceTablaActual = segundoComparador;
        //             cambio = 1;
        //         }
        //     }
        // }

        // al parecer esto sera algo un poco mas dificl
        /*
        como quiero que busque el nodo con la distancia mas corta.
        se tomara
        */
        cambio = 0;
        // antes de eso debo establecer el nodo incial, que lo vamsoa  adejar el primero que aparece en la tabla
        // esto porque no se tabla la modificare despues o que onda, pero por si las coasas esa varibale siempre contendra el incio.
        // indiceTablaActual = respaldoInicioTabala;
        // indiceComparador = respaldoInicioTabala;
        segundoComparador = respaldoInicioTabala;
        while (segundoComparador != NULL || cambio == 1)
        {
            // la condicion no debe ser donde tabla!=NULL, porque como lo que queremos hacer es comparar con toda la tabala por lo que se estara recargando constantemente, por lo que la condicion debe ser diferetne.

            // la cosnicion debe ser una en donde si se han revisado todos los nodos con todos los nodos y no ha sirgido un cambio entonces este debe salir porque
            // tabalaNodoActual -> tiene el nodo con la distancia mas corta
            cambio = 0;
            indiceTablaActual = respaldoInicioTabala;
            segundoComparador = respaldoInicioTabala;
            while (cambio == 0)
            {
                if (segundoComparador == NULL)
                {
                    break;
                }

                else if (indiceTablaActual->distanciaCorta < segundoComparador->distanciaCorta || indiceTablaActual->distanciaCorta == segundoComparador->distanciaCorta)
                {
                    // lo que eta de la parte derecha del OR solo aplica cuando en el recorrido se compara al mismo nodo.
                    segundoComparador = segundoComparador->sig;
                }
                else
                {
                    indiceTablaActual = segundoComparador;
                    cambio = 1;
                }
            }
        }

        // printf("%c -> %d", indiceTablaActual->nodo->indiceListAdy, indiceTablaActual->distanciaCorta);

        // getchar();
        // hasta este punto he obtenido el nodo mas bajo, por lo que ahora falta pro analizar cada nodo e imprimirlo

        while ()
        {
            indiceTablaActual->nodo->
        }
    }
}

struct tablaDijkstra *crearTabla_inicio(struct listaAdy *nodo, int nodoIncio)
{
    struct tablaDijkstra *nuevo;
    nuevo = (struct tablaDijkstra *)malloc(sizeof(struct tablaDijkstra));
    // nuevo->nodo = nodos->nodoActual;
    nuevo->nodo = nodo;
    if (nodoIncio != 0)
    {
        // si es difernte a 0, osea es 1 entonces quiere decir que es el nodo de inciio cuyo distancia mas corta es 0
        nuevo->distanciaCorta = 0;
    }
    else
    {
        nuevo->distanciaCorta = 2147483647;
    }
    nuevo->NodoVisitado = 0;
    nuevo->sig = NULL;
    nuevo->nodoPrevio = NULL;
    return (nuevo);
}

struct tablaDijkstra *agregar_sigueinteNodo(struct tablaDijkstra *inicio, struct listaAdy *nodo, int nodoInicio)
{

    struct tablaDijkstra *aux = inicio;
    struct tablaDijkstra *nuevo = crearTabla_inicio(nodo, nodoInicio);

    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;

    return (inicio);
}

void mostrarTabla(struct tablaDijkstra *inicio)
{

    struct tablaDijkstra *aux = inicio;

    printf("||  NODO  ||  DISTANCIA MAS CORTA  || NODO PREVIO  ||\n");
    while (aux != NULL)
    {

        printf("||  %c     ||          %d             ||      %c         ||\n", aux->nodo->indiceListAdy, aux->distanciaCorta, aux->nodoPrevio);
        aux = aux->sig;
    }
}

// quitar de nodos por visitar y pasar a nodos visitados
// no es eliminar si no que dejamos de apuntar a el.
// yo le voy a pasar el nodo el cual ya se ha procesado.
struct nodosVisitar_visitados *traspaso(struct nodosVisitar_visitados *inicioNodoPorVisitar, struct nodosVisitar_visitados *inicioNodosVisitados)
{
    struct nodosVisitar_visitados *auxPorVisitar = inicioNodoPorVisitar;
    // struct nodosVisitar_visitados *

    return (inicioNodoPorVisitar);
}