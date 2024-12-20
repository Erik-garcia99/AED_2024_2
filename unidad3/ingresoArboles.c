#include<stdio.h>
#include<stdlib.h>

/*

garcia chavez erik 01275863
algortimo y estrucutura de datos
practica 6 ingreso y eliminacion de arboles binarios


 */


struct Nodo{

	int dato;
	struct Nodo *izq;
	struct Nodo *drch;

};

struct Nodo *crearNodo(int dato);


struct Nodo *insertar(struct Nodo *raiz, int dato);

struct Nodo *eliminar(struct Nodo *raiz, int dato);






int main(){

	struct Nodo *raiz=NULL;
	int opc, dato;


	do{

		printf("\n1) ingresar");
		printf("\n2) eliminar nodo");
		printf("\n3) salir");
		printf("\n:");
		scanf("%d",&opc);

		switch(opc){


			//ingreso de datos
			case 1:


				printf("ingrese el dato: ");
				scanf("%d",&dato);

				if(raiz!=NULL){	

				/*se tiene que llmar primero a verificar que recorre el arbol como si lo fuera a enconrar
				pero si no lo encuentra, regresa 0, quiere decir que no esta y se pede ingresar 
				y devuelve 1 quiere decir que si esta y no puede ingresar.*/

					//ingresar 

					raiz=insertar(raiz,dato);
					
				}

				else{

					raiz=crearNodo(dato);
				}
			break;


			case 2:

				printf("ingrese el dato: ");
				scanf("%d",&dato);

				


				if(raiz!=NULL){
					raiz=eliminar(raiz,dato);
				}
				else{
					printf("el arbol no contiene datos");
				}
			

			break;

		}


		



	}while(opc!=10);



	return 0;


}



struct Nodo *crearNodo(int dato){

	

	struct Nodo *nuevo;
	nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
	nuevo->dato=dato;
	nuevo->izq=NULL;
	nuevo->drch=NULL;

	return (nuevo);

}



struct Nodo *insertar(struct Nodo *raiz, int dato){


	struct Nodo *aux=raiz,*nuevo;
	int encontrado=0;

	nuevo=crearNodo(dato);

	while(aux!=NULL && aux->dato!=dato){

		if(dato>aux->dato){

			if(aux->drch!=NULL){
				aux=aux->drch;
			}
			else{
				aux->drch=nuevo;
				encontrado=1;
				break;
			}
		}
		else{


			if(aux->izq!=NULL){
				aux=aux->izq;


			}
			else{
				aux->izq=nuevo;
				encontrado=1;
				break;
			}
		}

		

	}


	if(encontrado==0){
		printf("el numero que ingreso ya se ecuentra dentro del arbol");
	}
	


	return (raiz);




}


struct Nodo *eliminar(struct Nodo *raiz, int dato){



	struct Nodo *nodoPrev=raiz,*nodoEli=NULL,*nodoRemplazo=NULL,*nodoRemplazoPrevio=NULL;


	while(nodoPrev!=NULL){

		

		if(dato>nodoPrev->dato){

			if(dato==nodoPrev->drch->dato){
				
				nodoEli=nodoPrev->drch;

				if(nodoEli->izq==NULL && nodoEli->drch!=NULL){
					nodoPrev->drch=nodoEli->drch;
					free(nodoEli);
					return(raiz);
				}
				else if(nodoEli->izq!=NULL && nodoEli->drch==NULL){
					nodoPrev->drch=nodoEli->izq;
					free(nodoEli);
					return(raiz);
					
				}

				else if(nodoEli->izq==NULL && nodoEli->drch==NULL){
					nodoPrev->drch=NULL;
					free(nodoEli);
					return(raiz);
				}


				
				else{

					nodoRemplazo=nodoEli->drch;
					while(nodoRemplazo!=NULL){

						if(nodoRemplazo->izq!=NULL){

							nodoRemplazoPrevio=nodoRemplazo; //32
							nodoRemplazo=nodoRemplazo->izq; //27
						}

						else if(nodoRemplazoPrevio==NULL){

							nodoPrev->drch=nodoRemplazo;
							//nodoPrev->drch=nodoEli->drch; <-error
							nodoRemplazo->izq=nodoEli->izq; //<-correccion 
							free(nodoEli);
							return(raiz);

							
						}
						else{
							nodoPrev->drch=nodoRemplazo;
							nodoRemplazoPrevio->izq=nodoRemplazo->drch;
							nodoRemplazo->izq=nodoEli->izq;
							nodoRemplazo->drch=nodoEli->drch;
							free(nodoEli);
							return(raiz);

						}

						
					}
					
					//break;
				}
				
			}
			else{
				nodoPrev=nodoPrev->drch;
				
			}

			
		}

		else if(dato<nodoPrev->dato){
			if(dato==nodoPrev->izq->dato){
				nodoEli=nodoPrev->izq;
				if(nodoEli->drch==NULL && nodoEli->izq!=NULL){
					nodoPrev->izq=nodoEli->izq;
					free(nodoEli);
					return(raiz);
				}
				else if(nodoEli->drch!=NULL && nodoEli->izq==NULL){
					nodoPrev->izq=nodoEli->drch;
					free(nodoEli);
					return(raiz);
					
				}

				else if(nodoEli->drch==NULL && nodoEli->izq==NULL){
					nodoPrev->izq=NULL;
					free(nodoEli);
					return(raiz);
				}
				else{
					nodoRemplazo=nodoEli->drch;
				
					while(nodoRemplazo!=NULL){

						

						if(nodoRemplazo->izq!=NULL){
							nodoRemplazoPrevio=nodoRemplazo;
							nodoRemplazo=nodoRemplazo->izq;
						}

						else if(nodoRemplazoPrevio==NULL){
							nodoPrev->izq=nodoRemplazo;
							nodoRemplazo->izq=nodoEli->izq;
							free(nodoEli);
							return(raiz);
						}

						
						else{
							nodoPrev->izq=nodoRemplazo;
							nodoRemplazoPrevio->izq=nodoRemplazo->drch;
							nodoRemplazo->izq=nodoEli->izq;
							nodoRemplazo->drch=nodoEli->drch;
							free(nodoEli);
							return(raiz);
						}

						

					}
				}
			}
			else{
				nodoPrev=nodoPrev->izq;
			}
		}
	
		//caso especial raiz
		else{
			nodoEli=nodoPrev;
			nodoRemplazo=nodoEli->drch;

			
			while(nodoRemplazo!=NULL){

				if(nodoRemplazo->izq!=NULL){
					nodoRemplazoPrevio=nodoRemplazo;
					nodoRemplazo=nodoRemplazo->izq;
					
				}
				else if(nodoRemplazoPrevio==NULL){
						nodoRemplazo->izq=nodoEli->izq;
						raiz=nodoRemplazo;
						free(nodoEli);
						return(raiz);
				}
				else{

					nodoRemplazoPrevio->izq=nodoRemplazo->drch; //null
					
					nodoRemplazo->izq=nodoEli->izq;
					nodoRemplazo->drch=nodoEli->drch;

					raiz=nodoRemplazo;
					free(nodoEli);
					return(raiz);
				}

				

			}
			//break;
		}
		//break;
		//return (raiz);

	}

	if(nodoPrev==NULL){
		printf("no se encontro el nodo intente de nuevo: ");

	}





		

	

	

	return (raiz);


}