#include<stdio.h>
#include<stdlib.h>



struct Nodo{

	int dato;
	struct Nodo *ant;


};


struct Nodo *crearNodo(int dato);

int vacio(struct Nodo *tope);

struct Nodo *push(struct Nodo *tope, int dato);

struct Nodo *pop(struct Nodo *tope);

void mostrar(struct Nodo *tope);




int main(){


	struct Nodo *tope=NULL;
	int dato,opc;

	do{

		printf("\n1) ingresar a la pila");
		printf("\n2)eliminar de la pila");
		printf("\n3)mostrar");
		printf("\n4)salir");
		scanf("%d",&opc);



		switch(opc){

			case 1: 
				printf("ingrese el dato: ");
				scanf("%d",&dato);

				if(tope!=NULL){
					tope=push(tope,dato);
				
				}
				else{

					tope=crearNodo(dato);
				}

				break;

			case 2:

				if(tope!=NULL){
					tope=pop(tope);
				}

				else{
					printf("la pila se encunetra vacia");
				}

				break;

			case 3: 
				mostrar(tope);break;

	

		}		

	}while(opc!=10);




	return 0;

}



struct Nodo *crearNodo(int dato){

	struct Nodo *nuevo;

	nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));

	nuevo->dato=dato;
	nuevo->ant=NULL;

	return(nuevo);


}


int vacio(struct Nodo *tope){



	return(!tope)?1:0;

}




struct Nodo *push(struct Nodo *tope, int dato){



	struct Nodo *aux;
	aux=crearNodo(dato);
	aux->ant=tope;
	tope=aux;


	return(tope);

}



struct Nodo *pop(struct Nodo *tope){


	struct Nodo *aux=tope;


	tope=tope->ant;

	free(aux);

	return(tope);

}



void mostrar(struct Nodo *tope){

	struct Nodo *aux;

	if(tope==NULL){
		
		printf("la pila se encurntra vacia");

	}

	else{
	


		aux=tope;


		do{
			printf("%d -> ",aux->dato);
			aux=aux->ant;

		}while(aux!=NULL);

	}
}
