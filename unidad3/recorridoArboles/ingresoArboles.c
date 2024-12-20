#include <stdio.h>
#include <stdlib.h>

/*

garcia chavez erik 01275863
algortimo y estrucutura de datos
practica 7 recorrido de arboles


 */

struct Nodo
{

	int dato;
	int pre;
	int in;
	int post;
	int raizIinical;

	int YaImpreso;
	int YaImpresoIN;
	int YaImpresoPOST;

	struct Nodo *izq;
	struct Nodo *drch;
};

struct Cola
{

	int dato;
	struct Cola *ant;
	struct Cola *sig;
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
			}
			else
			{
				raiz = crearNodo(dato);
			}

			if (cola != NULL)
			{
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
			}
			else
			{
				printf("el arbol no contiene datos");
			}

			if (cola != NULL)
			{
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
	nuevo->post = 0;
	nuevo->in = 0;
	nuevo->raizIinical = 10;
	nuevo->YaImpreso = 0;
	nuevo->YaImpresoIN = 0;
	nuevo->YaImpresoPOST = 0;
	nuevo->izq = NULL;
	nuevo->drch = NULL;
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
	}
}