#include<stdio.h>
#include<stdlib.h> 

/*
garcia chavez erik 01275863
algoritmos y estrucutra de datos
practica 4 pilas dinamicas


*/


/*
--instrucciones

Los enteros en cualquier lenguaje de programación están limitados en su tamaño. Se pide definir un nuevo tipo de entero que no tenga dicha limitación. Para ello se elegirá una BASE suficientemente grande y se representarán los números como listas de cifras en esta base. Si BASE=1000, el número 10567991238934 se puede representar como: 

	934 -> 238 -> 991 -> 567 -> 10  
	 0      1      2      3      4

Debido a que:

10 567 991 238 934 = 10x10004 + 567x10003 + 991x10002 + 238x10001 + 934x10000. 


Los números deben ser separados en grupos después de haber sido capturados.  
Utilice listas enlazadas para separar los números.
Valide que el usuario sólo pueda teclear números
La cantidad de dígitos es variable. 
No se debe preguntar al usuario cuantos dígitos va a capturar.



*/


/*
procedimoento

-al aprecer se comporta como una pila

-podemos relizar casting, que es convertir un tipo de dato a otro, como lo que hace java

char numoer=52;



*/


struct Nodo{

	int dato;
	
	//otro dato que represente la base:
	//represetna a que potencia esta en el numero ingresado
	int numBase;

	struct Nodo *ant;

};



struct Nodo *crearNodo(int n,int base);


struct Nodo *push(struct Nodo *tope, int n,int base);

struct Nodo *pop(struct Nodo *tope);

void librearMemoria(struct Nodo *tope);

struct Nodo *separarDigitos(struct Nodo *tope, struct Nodo *numero);

void mostrarBase100(struct Nodo *tope);



void main(){

	struct Nodo *tope=NULL;
	struct Nodo *numeros=NULL; //<- representa la pila de numeros, no la pila
	//prila principal donde se separan en base 100

	
	printf("\ningrese el numero : ");
	char digito;
	//la funcion getchar, lo que hace es leer el caracter en la posicion actual, despues sigue hacia el sig.
	//caracter, en este caso hasta que encuentra un salto de linea.

	while((digito=getchar())!='\n'){ //-> stdin

		//los digitos los toma en fromato ascii, restar 48 -> 0
		digito-=48; // -> '0' en ascii
		digito=(int)digito; //-> convertido a entero

		//validamos que los datos ingresados sean numero validos

		if(digito>10 || digito <0){
		
			printf("el numero contiene un caracter no valido");
			exit(1);
		}
		else{

			//uso otra variable dentro de la estrucutra de pila para identificar la base, del grupo de numeros
		//como en esta pila la cual se encarga de guardar un numero de n elementos, digito a ditigo, 
		//no necesito saber su base por lo que tan solo le asigno 0 a esa posicion.
			if(numeros==NULL){
				numeros=crearNodo(digito,0);
			}
			else{
				numeros=push(numeros,digito,0);
			}


			}
		
		

	}

	//cunado acaba de recorrer todos los numeros, que sigue?
	//el agregarlos a al pila princpal
	tope=separarDigitos(tope,numeros);

	

	mostrarBase100(tope);

	//liberamos tope
	librearMemoria(tope);
	
	
}




struct Nodo *crearNodo(int n,int base){

	struct Nodo *aux;

	aux=(struct Nodo*)malloc(sizeof(struct Nodo));

	aux->dato=n;
	aux->numBase=base;
	aux->ant=NULL;

	return (aux);
}



struct Nodo *push(struct Nodo *tope, int n,int base){
	

	struct Nodo *aux;

	aux=crearNodo(n,base);

	aux->ant=tope;
	tope=aux;

	return (tope);
}

struct Nodo *pop(struct Nodo *tope){

	struct Nodo *aux;

	aux=tope;

	tope=tope->ant;

	free(aux);
	

	return (tope);


}



void librearMemoria(struct Nodo *tope){


	while(tope->ant != NULL){
		
		struct Nodo *aux=tope;
		
		tope=tope->ant;

		free(tope);
	}
}


//estare trbajando con las 2 pilas, estare sacando los digitos de la pila numeros que contiene todos los digitos del //numero que ingreso el usario, tope sera la pila principal.

struct Nodo *separarDigitos(struct Nodo *tope, struct Nodo *numero){

	//lo hago con otro puntero, para no perder esa pila para despues liberarla, porque no la ocupo mas que para
	//guardar un dato de n elemtnos, porque un tipo de dato me quedo corto.

	struct Nodo *aux=numero;

	//hacemos uso de un contador 

	int contador=0;
	

	int digito=0;
	int potencia=1; 
	int base=0;

	//tal vez esta condicion de mi while no sea la adecuada

	
	while(aux!=NULL){
		
		//calcular el numero en grupo de base 1000
		//esto lo tenia planeado hacer con potencia, en 10^0 - 10^1 - 10^2 que comprotan la base 1000
		digito += aux->dato * potencia;

		potencia *=10; //-> para elevar, en la priemra iteracion 1 -> 10 -> 100

		aux=aux->ant;
		//aumentamos el contador para veficiar que sean cifras de 3 digitos, base 1000		
		contador++;
		
		//inicia la pila, aqui solo va a entrasr unaa vez, cunado la pila esta vacia
		if(contador==3 && tope==NULL){
			//ahora estare sacando el 
			tope=crearNodo(digito,base);
			//despues que que se ingrese cualquier valor a a la pila se deben de reinciaar los valores
			base ++;
			contador=0;
			potencia=1;
			digito=0;
		}
		else{

			//la razon de este if, es para comprobar que el numero sea de 3 digitos completos, si no es asi
			//es que esta en el ultimo grupo de 3 digitos, que puede ser 1 o 2 sigitos solamente, 
			//si sigue llengo a otro digito peude que tome basura o algo asi, esto es para que solo 
			//tome hasta donde llega la pila, el or, es que al menenos unos de los 2 se va a cumploir
			
			//este agregara siempre que sean 3
			if(contador==3 || aux == NULL){
			
				tope=push(tope,digito,base);
				contador=0;
				potencia=1;
				digito=0;
				base++;

			}

		}

		
	}
	//libreamos la pila memoria, que ya no se involucra mas en nada mas, por lo que no tiene caso que siga
	//asi que libreamos esa memoria.
	librearMemoria(numero);
	

	return (tope);

}

//se mostrara la pila de pares de numeros base 1000, 

void mostrarBase100(struct Nodo *tope){

	struct Nodo *aux=tope;

	while(aux!=NULL){

		printf("[ %d - %d ] ->",aux->dato,aux->numBase);

		aux=aux->ant;

	}
	
}
