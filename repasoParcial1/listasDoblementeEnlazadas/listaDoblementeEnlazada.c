#include<stdio.h>
#include<stdlib.h>


struct Nodo{

	int dato;
	struct Nodo *sig;
	struct Nodo *ant;

};


struct Nodo *crearNodo(int dato);
struct Nodo *ingresar(struct Nodo *inicio,int dato);
struct Nodo *eliminar(struct Nodo *inicio, int dato);
void mostrar(struct Nodo *inicio);


int main(){


	struct Nodo *inicio=NULL;
	int dato, opc;

	do{
		printf("\n1. Insertarenla lista");
 		printf("\n2. Eliminarun elemento");
		printf("\n3. Imprimirla lista");
		printf("\n4. Salir");
		printf("\nOpcion: [ ]\b\b");
		scanf("%d",&opc );



		switch(opc){


			case 1: 
				printf("\ningrese el dato: ");
				scanf("%d",&dato);

				if(inicio!=NULL){

					inicio=ingresar(inicio,dato);

				}
				else{
					inicio=crearNodo(dato);
				}

				break;


			case 2: 
					
				
				if(inicio!=NULL){
					printf("\ningrese el dato: ");
					scanf("%d",&dato);

					inicio=eliminar(inicio,dato);

					
				}
				else{
					printf("\nla lista esta vacia");
				}

				break;

			case 3: 
				mostrar(inicio);

				break;

		}

	}while(opc!=4);



	return 0;

}


struct Nodo *crearNodo(int dato){

	struct Nodo *nuevo;

	nuevo=(struct Nodo *)malloc(sizeof(struct Nodo));

	nuevo->dato=dato;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	return (nuevo);
}




struct Nodo *ingresar(struct Nodo *inicio,int dato){

	

	struct Nodo *presente, *anterior=NULL, *nuevo;

	nuevo=crearNodo(dato);

	presente=inicio;


	while(presente!=NULL && dato>=presente->dato){
		
		anterior=presente;
		presente=presente->sig;
		
	}


	if(anterior==NULL){
		nuevo->sig=presente;
		presente->ant=nuevo;
		inicio=nuevo;
		

	}

	else{
		
		nuevo->ant=anterior;
		anterior->sig=nuevo;
		nuevo->sig=presente;
		if(presente!=NULL){
			presente->ant=nuevo;
		}

	}

	return (inicio);


}



struct Nodo *eliminar(struct Nodo *inicio, int dato){



	struct Nodo *presente=inicio,*anterior=NULL;


	while(presente!=NULL && dato!=presente->dato){

		anterior=presente;
		presente=presente->sig;
	}

	if(anterior==NULL){
		
		inicio=presente->sig;
		if(inicio!=NULL){
			inicio->ant=NULL;
		}
		free(presente);

	}


	else{

		if(presente!=NULL){

			anterior->sig=presente->sig;
			if(presente->sig!=NULL){
				presente->sig->ant=anterior;
			}

			free(presente);
		}
		else{
			printf("no se pudo encontrar el nodo\n");
		}
	}



	return (inicio);
}



void mostrar(struct Nodo *inicio){

	struct Nodo *aux;


	if(inicio!=NULL){
	
		aux=inicio;


		do{

			printf("%d -> ",aux->dato);
			aux=aux->sig;

		}while(aux!=NULL);

	}

	else{

		printf("la pila esta vacia");
	}
	


}



