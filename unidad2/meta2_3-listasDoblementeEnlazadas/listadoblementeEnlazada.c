#include<stdio.h>
#include<stdlib.h>



struct Nodo{

	int dato;
	struct Nodo *ant;
	struct Nodo *sig;

};


struct Nodo *crearNodo(int dato);
struct Nodo *insertar(struct Nodo *inicio,int dato);
struct Nodo *eliminar(struct Nodo *inicio, int dato);
void mostrar(struct Nodo *inicio);


void main(){

	struct Nodo *inicio=NULL;

	int dato, opc;

	do{
		printf("\n 1. Insertar en la lista");
		printf("\n 2. Eliminar un elemento ");
		printf("\n 3. Imprimir la lista");
		printf("\n 4. Salir");
		printf("\n Opcion: [ ]\b\b");
		scanf(" %d", &opc);
		

		switch(opc){

			case 1:
				printf("\nDATO");
				scanf("%d",&dato);

				if(inicio==NULL){

					inicio=crearNodo(dato);
				}
				else{

					inicio=insertar(inicio,dato);
				}

				break;

			case 2: 
				if(inicio!=NULL){

					printf("\nEscribe dato a borrar:");
					scanf(" %d", &dato);
					inicio = eliminar(inicio, dato);
					
				}
				else{

					printf("lista vacia");
				}

				break;


			case 3:

				mostrar(inicio);break;

		}

	}while(opc!=4);







}



struct Nodo *crearNodo(int dato){


	struct Nodo *nuevo;

	nuevo=(struct Nodo*)malloc(sizeof(struct Nodo ));
	
	nuevo->dato=dato;
	nuevo->ant=NULL;
	nuevo->sig=NULL;

	return (nuevo);

}


struct Nodo *insertar(struct Nodo *inicio,int dato){

	struct Nodo *p,*q=NULL, *nuevo;

	nuevo=crearNodo(dato);

	p=inicio;


	while(p!=NULL && dato>= p->dato){

		q=p;
		p=p->sig;

	}
	//insertar cabecera
	if(q==NULL){

		p->ant=nuevo;
		nuevo->sig=p;
		inicio=nuevo;
	}
	else{

		q->sig=nuevo;
		nuevo->ant=q;
		nuevo->sig=p;
		if(p!=NULL){
			p->ant=nuevo;
		}
		

	}

	return (inicio);

}


struct Nodo *eliminar(struct Nodo *inicio,int dato){


	struct Nodo *p,*q=NULL;

	p=inicio;

	while(p!=NULL && p->dato!=dato){
		q=p;
		p=p->sig;

	}

	//elininar la cabecera
	if(q==NULL){
		inicio=p->sig;
		if(inicio!=NULL){
			inicio->ant=NULL;
		}
		free(p);
		
	}
	else{
		//tan solo para saber si el dato fue encontrado
	
		if(p!=NULL){

			q->sig=p->sig;
	

		}
		else{
			printf("el dato no se enecuentra en la lista");
		}

	}


	return inicio;

}


void mostrar(struct Nodo *inicio){
	
	struct Nodo *aux;

	if(!inicio){
		printf("esta vacia\n");
	}
	else{
		aux=inicio;
		do{
			printf("\n%d",aux->dato);
			aux=aux->sig;
		}while(aux!=NULL);
	}

}




