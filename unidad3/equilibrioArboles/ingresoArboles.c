#include <stdio.h>
#include <stdlib.h>

/*

garcia chavez erik 01275863
algortimo y estrucutura de datos
practica 7 recorrido de arboles


 */

struct Nodo
{
	// creo que puedo evitar tantos datos, si al final se limpiara con la cola
	int dato;
	// puede poner valores para tener guardado el nivel de sus sibarboles

	int pre; // este puede llevar otro nombre

	struct Nodo *izq;
	struct Nodo *drch;
	int raizIinical; // se queda
	int YaImpreso;	 // se queda
	// para el balanceo
	int nodosIZQ;
	int nodosDRCH;

	//-------------------------------------------
	// en riesgo se ser eliminados
	int post;		   // nodo que puede que se elimine
	int in;			   // nodo que puede que se elimine
	int YaImpresoIN;   // peude que se elimine
	int YaImpresoPOST; // puede que se elimine
					   // obvio que se quedan
					   //-----------------------------------------------
};

struct Cola
{

	int dato;
	struct Cola *ant;
	struct Cola *sig;
};

struct Pila
{
	struct Nodo *nodoArbol;
	struct Pila *ant;
};

struct Nodo *crearNodo(int dato);

struct Nodo *insertar(struct Nodo *raiz, int dato);

struct Nodo *eliminar(struct Nodo *raiz, int dato);

struct Nodo *preOrden(struct Nodo *raiz, struct Nodo *raizRespaldo);

struct Nodo *inOrden(struct Nodo *raiz, struct Nodo *raizRespaldo);

struct Nodo *postOrden(struct Nodo *raiz, struct Nodo *raizRespaldo);

struct Cola *crearCola(int dato);

struct Cola *ingresar(struct Cola *inicio, int dato);

struct Cola *eliminarCola(struct Cola *inicio, int dato);

void limpiarRecorrido(struct Nodo *raiz, int dato);

// equilibrio? pero cunatas o como?
//
void equilibrarArbol(struct Nodo *raiz, int dato);
void nivelArbol(struct Pila *inicioPila, struct Nodo *elemento);
// pila para hacer la "recusividad"

struct Pila *crearPila(struct Nodo *nodo);
struct Pila *ingresarPila(struct Nodo *nodo, struct Pila *tope);
struct Pila *elimimarPila(struct Pila *tope);
struct Nodo *obtenerNodo(struct Pila *tope);

void vaciar(struct Nodo *nodo);

int main()
{

	struct Nodo *raiz = NULL;
	struct Cola *cola = NULL;
	int opc, dato;
	do
	{

		printf("\n1) ingresar");
		printf("\n2) eliminar nodo");
		printf("\n3) recorrido Pre-Orden");
		printf("\n4) recorrido inOrden");
		printf("\n10) salir");
		printf("\n:");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			printf("ingrese el dato: ");
			scanf("%d", &dato);

			if (raiz != NULL)
			{
				raiz = insertar(raiz, dato);
				// tal vez uasar la propiedad que me dice cunado es la raiz
				// aqui se manda a llamar a la funcion para equilibrar
			}
			else
			{
				raiz = crearNodo(dato);
			}

			if (cola != NULL)
			{
				// aqui marcar a la raiz, que sera cambiada
				raiz->raizIinical = 0;
				cola = ingresar(cola, dato);
			}
			else
			{
				cola = crearCola(dato);
			}

			break;

		case 2:
			printf("ingrese el dato: ");
			scanf("%d", &dato);

			if (raiz != NULL)
			{
				raiz = eliminar(raiz, dato);
				// tal vez uasar la propiedad que me dice cunado es la raiz
				// aqui se manda a llamar a la funcion para equilibrar
			}
			else
			{
				printf("el arbol no contiene datos");
			}

			if (cola != NULL)
			{
				raiz->raizIinical = 0;
				cola = eliminarCola(cola, dato);
			}

			break;
		case 3:
			struct Cola *colaAux = cola;

			while (colaAux != NULL)
			{
				int dato = colaAux->dato;

				limpiarRecorrido(raiz, dato);
				colaAux = colaAux->sig;
			}

			raiz->raizIinical = 0;
			raiz = preOrden(raiz, raiz);

			break;

		case 4:
			raiz->raizIinical = 0;
			raiz = inOrden(raiz, raiz);

			break;
		}

	} while (opc != 10);
	return 0;
}

struct Nodo *crearNodo(int dato)
{
	struct Nodo *nuevo;
	nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
	nuevo->dato = dato;
	nuevo->pre = 0;
	nuevo->izq = NULL;
	nuevo->drch = NULL;
	nuevo->raizIinical = 10;
	nuevo->YaImpreso = 0;
	nuevo->nodosIZQ = 0;
	nuevo->nodosDRCH = 0;

	//-----------------------
	nuevo->post = 0;
	nuevo->in = 0;
	nuevo->YaImpresoIN = 0;
	nuevo->YaImpresoPOST = 0;

	return (nuevo);
}

struct Nodo *insertar(struct Nodo *raiz, int dato)
{

	struct Nodo *aux = raiz, *nuevo;
	int encontrado = 0;

	nuevo = crearNodo(dato);

	while (aux != NULL && aux->dato != dato)
	{

		if (dato > aux->dato)
		{

			if (aux->drch != NULL)
			{
				aux = aux->drch;
			}
			else
			{
				aux->drch = nuevo;
				encontrado = 1;
				break;
			}
		}
		else
		{
			if (aux->izq != NULL)
			{
				aux = aux->izq;
			}
			else
			{
				aux->izq = nuevo;
				encontrado = 1;
				break;
			}
		}
	}
	if (encontrado == 0)
	{
		printf("el numero que ingreso ya se ecuentra dentro del arbol");
	}

	return (raiz);
}

struct Nodo *eliminar(struct Nodo *raiz, int dato)
{

	struct Nodo *nodoPrev = raiz, *nodoEli = NULL, *nodoRemplazo = NULL, *nodoRemplazoPrevio = NULL;
	while (nodoPrev != NULL)
	{
		if (dato > nodoPrev->dato)
		{
			if (dato == nodoPrev->drch->dato)
			{
				nodoEli = nodoPrev->drch;
				if (nodoEli->izq == NULL && nodoEli->drch != NULL)
				{
					nodoPrev->drch = nodoEli->drch;
					free(nodoEli);
					return (raiz);
				}
				else if (nodoEli->izq != NULL && nodoEli->drch == NULL)
				{
					nodoPrev->drch = nodoEli->izq;
					free(nodoEli);
					return (raiz);
				}
				else if (nodoEli->izq == NULL && nodoEli->drch == NULL)
				{
					nodoPrev->drch = NULL;
					free(nodoEli);
					return (raiz);
				}
				else
				{
					nodoRemplazo = nodoEli->drch;
					while (nodoRemplazo != NULL)
					{
						if (nodoRemplazo->izq != NULL)
						{
							nodoRemplazoPrevio = nodoRemplazo; // 32
							nodoRemplazo = nodoRemplazo->izq;  // 27
						}
						else if (nodoRemplazoPrevio == NULL)
						{
							nodoPrev->drch = nodoRemplazo;
							// nodoPrev->drch=nodoEli->drch; <-error
							nodoRemplazo->izq = nodoEli->izq; //<-correccion
							free(nodoEli);
							return (raiz);
						}
						else
						{
							nodoPrev->drch = nodoRemplazo;
							nodoRemplazoPrevio->izq = nodoRemplazo->drch;
							nodoRemplazo->izq = nodoEli->izq;
							nodoRemplazo->drch = nodoEli->drch;
							free(nodoEli);
							return (raiz);
						}
					}
				}
			}
			else
			{
				nodoPrev = nodoPrev->drch;
			}
		}
		else if (dato < nodoPrev->dato)
		{
			if (dato == nodoPrev->izq->dato)
			{
				nodoEli = nodoPrev->izq;
				if (nodoEli->drch == NULL && nodoEli->izq != NULL)
				{
					nodoPrev->izq = nodoEli->izq;
					free(nodoEli);
					return (raiz);
				}
				else if (nodoEli->drch != NULL && nodoEli->izq == NULL)
				{
					nodoPrev->izq = nodoEli->drch;
					free(nodoEli);
					return (raiz);
				}
				else if (nodoEli->drch == NULL && nodoEli->izq == NULL)
				{
					nodoPrev->izq = NULL;
					free(nodoEli);
					return (raiz);
				}
				else
				{
					nodoRemplazo = nodoEli->drch;

					while (nodoRemplazo != NULL)
					{
						if (nodoRemplazo->izq != NULL)
						{
							nodoRemplazoPrevio = nodoRemplazo;
							nodoRemplazo = nodoRemplazo->izq;
						}
						else if (nodoRemplazoPrevio == NULL)
						{
							nodoPrev->izq = nodoRemplazo;
							nodoRemplazo->izq = nodoEli->izq;
							free(nodoEli);
							return (raiz);
						}

						else
						{
							nodoPrev->izq = nodoRemplazo;
							nodoRemplazoPrevio->izq = nodoRemplazo->drch;
							nodoRemplazo->izq = nodoEli->izq;
							nodoRemplazo->drch = nodoEli->drch;
							free(nodoEli);
							return (raiz);
						}
					}
				}
			}
			else
			{
				nodoPrev = nodoPrev->izq;
			}
		}
		// caso especial raiz
		else
		{
			nodoEli = nodoPrev;
			nodoRemplazo = nodoEli->drch;
			while (nodoRemplazo != NULL)
			{
				if (nodoRemplazo->izq != NULL)
				{
					nodoRemplazoPrevio = nodoRemplazo;
					nodoRemplazo = nodoRemplazo->izq;
				}
				else if (nodoRemplazoPrevio == NULL)
				{
					nodoRemplazo->izq = nodoEli->izq;
					raiz = nodoRemplazo;
					free(nodoEli);
					return (raiz);
				}
				else
				{
					nodoRemplazoPrevio->izq = nodoRemplazo->drch; // null
					nodoRemplazo->izq = nodoEli->izq;
					nodoRemplazo->drch = nodoEli->drch;
					raiz = nodoRemplazo;
					free(nodoEli);
					return (raiz);
				}
			}
		}
	}
	if (nodoPrev == NULL)
	{
		printf("no se encontro el nodo intente de nuevo: ");
	}
	return (raiz);
}

// ahora con este trabajare con el arbol
struct Nodo *preOrden(struct Nodo *raiz, struct Nodo *raizRespaldo)
{

	struct Nodo *aux = raiz;
	struct Nodo *inicioRaiz = raizRespaldo;

	if (inicioRaiz->drch->pre == 1 && inicioRaiz->izq->pre == 1)
	{
		return (inicioRaiz);
	}

	else if (inicioRaiz->drch->pre != 1 || inicioRaiz->izq->pre != 1)
	{

		if (inicioRaiz->raizIinical == 0)
		{
			printf("%d -> ", aux->dato);
			inicioRaiz->raizIinical = 1;
			inicioRaiz->YaImpreso = 1;
			inicioRaiz->pre = 1;
			aux = preOrden(aux->izq, inicioRaiz);
		}

		if (aux->izq != NULL && aux->izq->pre == 0)
		{
			if (aux->YaImpreso == 0)
			{
				printf("%d -> ", aux->dato);
				aux->YaImpreso = 1;
			}
			preOrden(aux->izq, inicioRaiz);
		}

		if (aux->drch != NULL && aux->drch->pre == 0)
		{
			if (aux->YaImpreso == 0)
			{
				printf("%d -> ", aux->dato);
				aux->YaImpreso = 1;
			}
			preOrden(aux->drch, inicioRaiz);
		}

		if (aux->izq == NULL && aux->drch == NULL)
		{
			if (aux->YaImpreso == 0)
			{
				printf("%d -> ", aux->dato);
				aux->YaImpreso = 1;
				aux->pre = 1;
			}
			preOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->izq != NULL && aux->drch == NULL && aux->izq->pre == 1)
		{
			aux->pre = 1;
			preOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->drch != NULL && aux->izq == NULL && aux->drch->pre == 1)
		{
			aux->pre = 1;
			aux = preOrden(inicioRaiz, inicioRaiz);
		}

		if (aux != NULL && aux->izq != NULL && aux->izq->pre == 1 && aux->drch != NULL && aux->drch->pre == 1)
		{

			aux->pre = 1;
			aux = preOrden(inicioRaiz, inicioRaiz);
		}

		return (inicioRaiz);
	}
}

struct Nodo *inOrden(struct Nodo *raiz, struct Nodo *raizRespaldo)
{

	struct Nodo *aux = raiz;
	struct Nodo *inicioRaiz = raizRespaldo;

	if (inicioRaiz->drch->in == 1 && inicioRaiz->izq->in == 1)
	{

		return (inicioRaiz);
	}

	else if (inicioRaiz->drch->in != 1 || inicioRaiz->drch->in != 1)
	{

		if (inicioRaiz->izq->in == 1 && inicioRaiz->YaImpresoIN != 1)
		{
			printf("%d -> ", aux->dato);
			inicioRaiz->YaImpresoIN = 1;
			inicioRaiz->raizIinical = 1;
			inicioRaiz->in = 1;
		}

		if (aux->izq != NULL && aux->izq->in != 1)
		{

			if (aux->izq->in == 1 && aux->YaImpresoIN == 0)
			{
				printf("%d -> ", aux->dato);
				aux->YaImpresoIN = 1;
				aux = inOrden(aux->drch, inicioRaiz);
			}
			else
			{
				aux = inOrden(aux->izq, inicioRaiz);
			}
		}

		if (aux->drch != NULL && aux->drch->in != 1)
		{
			if (aux->izq != NULL)
			{
				if (aux->izq->in == 1 && aux->YaImpresoIN == 0)
				{
					printf("%d -> ", aux->dato);
					aux->YaImpresoIN = 1;
					aux = inOrden(aux->drch, inicioRaiz);
				}
			}

			else if (aux->drch->in == 0 && aux->in != 1)
			{
				printf("%d -> ", aux->dato);
				aux->YaImpresoIN = 1;
				aux = inOrden(aux->drch, inicioRaiz);
			}
			else
			{
				aux = inOrden(aux->drch, inicioRaiz);
			}
		}

		if (aux->drch->in != 0)
		{
			aux = inOrden(aux->drch, inicioRaiz);
		}

		if (aux->izq == NULL && aux->drch == NULL)
		{
			if (aux->YaImpreso == 0 && aux->in == 0)
			{
				printf("%d ->", aux->dato);
				aux->YaImpresoIN = 1;
				aux->in = 1;
			}

			aux = inOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->drch == NULL && aux->izq == NULL && aux->in == 0)
		{
			printf("%d -> ", aux->dato);
			aux->in = 1;
			aux->YaImpresoIN = 1;
			aux = inOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->izq == NULL && aux->in == 0)
		{
			printf("%d -> ", aux->dato);
			aux->in = 1;
			aux->YaImpresoIN = 1;
			aux = inOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->drch != NULL && aux->izq == NULL && aux->drch->in == 1)
		{
			aux->in = 1;
			aux = inOrden(inicioRaiz, inicioRaiz);
		}

		if (aux->izq != NULL && aux->drch == NULL && aux->izq->in == 1)
		{
			aux->in = 1;
			aux = inOrden(inicioRaiz, inicioRaiz);
		}

		if (aux != NULL && aux->izq != NULL && aux->izq->in == 1 && aux->drch != NULL && aux->drch->in == 1)
		{
			aux->in = 1;
			aux = inOrden(inicioRaiz, inicioRaiz);
		}
	}
}

struct Nodo *postOrden(struct Nodo *raiz, struct Nodo *raizRespaldo)
{

	struct Nodo *aux = raiz;
	struct Nodo *inicioRaiz = raizRespaldo;

	if (inicioRaiz->drch->in == 1 && inicioRaiz->izq->in == 1)
	{

		return (inicioRaiz);
	}
}

// primer versikon sin recursividad.
// solo recorrido simples
// banceo de arboles.
// RAIZ =0

// primero antes que nada, debemos corroborar que el arbol esta balanceado
// como puede saber si un arbol esta balanceado?

// una forma que aun no esta del todo seguro padre, es, buscar si el nodo superior y el nodo en el cual se va a reemplazar estan desvalanciados, se balancea el nodo interior.

// hagamos una pila para que haga lo que deberia de hacer la recurcividad pero si que reinicien las variables.

// necesito un caso, en donde debo saber si es la raiz lo que se cambio.
void equilibrarArbol(struct Nodo *raiz, int dato)
{
	// es un auxiliar que me va a ayudar a buscar el nodo con el numero que se ingreso

	// variabales que estoy usando actualemnte
	struct Nodo *nodoActual = raiz;
	struct Nodo *raizInicio = raiz;
	struct Nodo *numeroIngresado = NULL;
	struct Pila *ramaPila = NULL; // porque el recorrido terminara en una hoja
	int orientacion = 0;

	// primero vamos por el menor, que es con el que estamos trabajando

	// si esta en el subrbol derecho quiero que se mantenga ahi, para saber que tipo de insersion se hizo
	while (nodoActual != NULL)
	{
		// vamos por los casos de rotacion simple
		if (dato > nodoActual->dato)
		{

			// llevar la cuenta de en que lado esta

			if (ramaPila == NULL)
			{
				ramaPila = crearPila(nodoActual);
				nodoActual = nodoActual->drch;
			}
			else
			{
				ramaPila = ingresarPila(nodoActual, ramaPila);
				nodoActual = nodoActual->drch;
			}
		}
		else if (dato < nodoActual->dato)
		{

			// ingreso el nodo actual a la pila hasta encontrar el nodo cuyo dato es el que se ingreso.

			if (ramaPila == NULL)
			{
				ramaPila = crearPila(nodoActual);
				nodoActual = nodoActual->izq;
			}
			else
			{
				ramaPila = ingresarPila(nodoActual, ramaPila);
				nodoActual = nodoActual->izq;
			}
			// al final recorremos a la izquierda

			// necsito saber en el caso de rotacion sincilla no tanto si nodo con el dato
		}
		else
		{
			// si no es menor si no es mayor quiere decir que es el nodo con el numero
			// cunado ingrese aqui quiere decir que encoentro el nodo con el dato
			// que se ingreso, ahora hara el proceos de la recursividad, pero lo hare manual, buscando entre los nodos si hay alguno desbalanceado.

			// guardo el nodo con el dato que se ingreso, para que, creo que despues lo voy a necsitar para hacer los cambios como el de doble giro, el simple no lo es tanto
			numeroIngresado = nodoActual;
			// ingreso el ulrimo nodo
			// igual necesito ver si la pila esta vacia si es asi quiere decir que es la raiz.
			if (ramaPila = NULL)
			{
				// seria la raiz
				ramaPila = crearPila(nodoActual);
			}
			else
			{
				ramaPila = ingresarPila(nodoActual, ramaPila);
			}

			nivelArbol(ramaPila, numeroIngresado);
		}
		break;
	}

	// hacer el cambio?
}

//-------------------------------------------------------------------------------------
// para encontrar el nivel, como devolver al valor del nivel si es que esta balanceado el arbol, sera con esta funcion
void nivelArbol(struct Pila *inicioPila, struct Nodo *elemento)
{

	// variables utilizadas
	struct Pila *nodoActual = inicioPila;
	struct Pila *aux;
	struct Nodo *padre = NULL;
	int padreNodo = 0;
	int blanceado = 0;
	int *izq = 0;
	int *drch = 0;
	struct Nodo *elementoIng = elemento;
	struct Nodo *obtencionNodo = NULL;

	// primnero comprobamos que la raiz no este desbalanceada.

	while (nodoActual != NULL && blanceado == 0)
	{
		// pimero obtengo el nodo que voy a comprobar su nivel
		obtencionNodo = obtenerNodo(nodoActual);

		if (obtencionNodo->dato > elementoIng)
		{
			obtencionNodo = obtencionNodo->drch;
		}

		else
		{
			obtencionNodo = obtencionNodo->izq;
			izq++;
		}
	}

	// el orden dependiento en como ingreso el nodo.
}

// extra

struct Cola *crearCola(int dato)
{

	struct Cola *nuevo;

	nuevo = (struct Cola *)malloc(sizeof(struct Cola));

	nuevo->dato = dato;
	nuevo->ant = NULL;
	nuevo->sig = NULL;

	return (nuevo);
}

struct Cola *ingresar(struct Cola *inicio, int dato)
{

	struct Cola *aux = inicio;
	struct Cola *nuevo;

	nuevo = crearCola(dato);

	while (aux->sig != NULL)
	{

		aux = aux->sig;
	}

	aux->sig = nuevo;
	nuevo->ant = aux;

	return (inicio);
}

struct Cola *eliminarCola(struct Cola *inicio, int dato)
{

	struct Cola *presente = inicio;
	struct Cola *anterior = NULL;

	while (presente != NULL && presente->dato != dato)
	{

		anterior = presente;
		presente = presente->sig;
	}

	if (anterior == NULL)
	{

		inicio = presente->sig;
		free(presente);
	}
	else
	{

		if (presente != NULL)
		{
			anterior->sig = presente->sig;
			if (presente->sig != NULL)
			{
				presente->sig->ant = anterior;
			}
			free(presente);
		}
	}
	return (inicio);
}

void limpiarRecorrido(struct Nodo *raiz, int dato)
{

	struct Nodo *aux = raiz;

	while (aux != NULL && aux->dato != dato)
	{
		if (dato > aux->dato)
		{
			aux = aux->drch;
		}
		else if (dato < aux->dato)
		{
			aux = aux->izq;
		}
	}

	if (aux != NULL)
	{
		aux->in = 0;
		aux->post = 0;
		aux->pre = 0;
		aux->raizIinical = 10;
		aux->YaImpreso = 0;
		aux->YaImpresoIN = 0;
		aux->YaImpresoPOST = 0;
		aux->nodosIZQ = 0;
		aux->nodosDRCH = 0;
	}
}

// estrucuturas auxiliares para el equilibrio

struct Pila *crearPila(struct Nodo *nodo)
{

	struct Pila *nuevo;
	nuevo = (struct Pila *)malloc(sizeof(struct Pila));

	nuevo->nodoArbol = nodo;
	nuevo->ant = NULL;
}

struct Pila *ingresarPila(struct Nodo *nodo, struct Pila *tope)
{

	struct Pila *aux;

	aux = crearPila(nodo);

	aux->ant = tope;
	tope = aux;

	return (tope);
}

struct Pila *elimimarPila(struct Pila *tope)
{
	struct Pila *aux = tope;

	tope = tope->ant;
	free(aux);

	return (tope);
}

struct Nodo *obtenerNodo(struct Pila *tope)
{

	struct Pila *aux = tope;
	struct Nodo *nodoActual = NULL;
	if (aux != NULL)
	{

		nodoActual = aux->nodoArbol;
	}

	return (nodoActual);
}
