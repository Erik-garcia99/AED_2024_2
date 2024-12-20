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



int  main(){


	struct Nodo *inicio=NULL;
	int dato,op;

	do{

		printf("\n1. Insertarenla lista");
		printf("\n2. Eliminarun elemento");
		printf("\n3. Imprimirla lista");
		printf("\n4. Salir"); 
		printf("\nOpcion: [ ]\b\b"); 
		scanf(" %d", &op); 

		switch (op) { 

			case 1: 

				printf("\nDato:"); 
				scanf(" %d", &dato); 
				if (inicio== NULL) 

					inicio= crearNodo(dato); 

				else 

					inicio= insertar(inicio, dato); break; 


			case 2: 


				if(inicio!= NULL){ 


					printf("\nEscribedatoa borrar: "); 

					scanf(" %d", &dato); 


					inicio= eliminar(inicio, dato); 

				} 

				else 

					printf("Lista vacia\n"); break; 


			case 3: mostrar(inicio); break; 




		}


	}while(op!=4);


	return 0;
}

struct Nodo *crearNodo(int dato){

        struct Nodo *nuevo;

        nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));

        nuevo->dato=dato;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
	return(nuevo);

}





struct Nodo *insertar(struct Nodo *inicio,int dato){


	struct Nodo *p,*q=NULL, *nuevo;

	nuevo=crearNodo(dato);

	p=inicio;


	while(p!=NULL && dato>=p->dato){
		q=p;
		p=p->sig;

	}


	if(q==NULL){

		nuevo->sig=p;
		p->ant=nuevo;
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



struct Nodo *eliminar(struct Nodo *inicio, int dato){

	struct Nodo *p,*q=NULL;



	p=inicio;

	while(p!=NULL && p->dato!=dato){
		q=p;
		p=p->sig;

	}



	if(q==NULL){

		inicio=p->sig;
		if(inicio!=NULL){
			inicio->ant=NULL;

		}
		free(p);
	}

	else{

		if(p!=NULL){
			q->sig=p->sig;
			if(p->sig!=NULL)
				p->sig->ant=q;
			free(p);

		}
		else{
			printf("no se enconttl el dsto");
		}

	}


	return (inicio);
}




void mostrar(struct Nodo *inicio){

	struct Nodo *aux;

	if(!inicio){

		printf("pila vacia");
	}

	else{

		aux=inicio;


		do{
			printf("%d -> ", aux->dato);
			aux=aux->sig;


		}while(aux!=NULL);

	}

}
