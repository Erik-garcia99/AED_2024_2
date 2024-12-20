
#include<stdio.h>
#include<stdlib.h>
/*
garcia chavez erik 01275863
algoritmos y estrucutra de datos
ing. en computacion
practica No. 3 pilas y colas estaticas 



okay, ya vi lo que se quiere en el programa.

requeriminentos del programa. 

-Se desea implementar dos pilas, y se dispone de un solo vector de N componentes. Implementar ambas pilas de manera 
que se pueda aprovechar al máximo el vector. Las operaciones de pila tendrán que llevar un parámetro adicional que 
indique sobre qué pila se quiere realizar la operación (pila 1 ó pila 2).

-Las dos pilas crecen partiendo de los extremos del arreglo.

-El tamaño de cada pila es máximo N.

-El tope de cada pila puede ir de 0 a N, por ejemplo: Si el vector tiene tamaño N=10, y se meten 7 elementos a la pila
1, la pila dos tendría máximo 3 espacios. Si el vector tiene tamaño N=8 y se meten 8 elementos a la pila 1, la pila
dos tendría máximo 0 espacios.

-La cantidad de elementos entre ambas pilas no puede ser mayor a N.

-Solamente puede usar un solo arreglo para implementar ambas pilas.

-Las capturas de valores deben estar validadas.

-El programa debe tener una opción mostrar para ver el contenido de las pilas sin sacar los elementos de ella.

-Sólo debe existir una función pop, push y mostrar.

-El programa debe repetirse N veces hasta que se seleccione la opción de salida.

-Una de las pilas debe iniciar en 0 mientras que la otra en la última posición del vector.

lo del punto 3 es lo que me tenia confundido, lo que quiere decir es que

en efecto se tendran 2 pilas, pila 1 y pila 2, con un solo vector, por ejemplo le pido al usuario el tamanio del vector
porque seran estaticos, en el menu tendremos las opcioens de hacer push con la pila 1 o 2 y pop de la pila 1 o 2,
de modod que se rian repartiendo el tamanio del arreglo si el usuario ingreso una arrelo de 10 posicioes en la pila 1 
se ingresaron 5 elementos la pila 2 tiene 5 elementos restantes, pero estos deberian de volver, me explico 

se hace push 3 veces a la pila 1, despues de hacen 2 push a la pila 2, pero despus quiero hacer otro push a la pila 1
por lo que deberia de poder, ahora pila1 tiene 4 lugares ocupados y pila 2 solo tenria 4 posibles posiciones, y esto 
pasa de la misma manera para pila 1, si se hace un push en la pila 2 ahora pila 1 solo tendria 3 posbles posiciones
en las que se pueden hacer push y ya el pop seria independiente de cada uno.

*/




int calcularEspacio(int *arreglo,int tamanio){





	//ahorita lo cambiamos
	return 0;

}


//funcion push
//pila representa sobre que pila se quiere hacer la operacion.
//el tamanio sera el tamanio que el usuario ingreso

//este push lo que me va a devolver va a hacer indice en donde se quedo la pila, en caso que fuera la primera vez que
//ingresa

//el idice, es el indice del arreglo dependiendo la pila a la cual se esta accediendo.
int push(int pila,int tamanio,int *arreglo,int indice){


	return 0;
}



//funcion pop


//funcion mostrar



int main(){

	//donde N representa el tamanio del arreglo que introdujo el usuairio
	//donde i y j seran mis indices, los topes de mis pilas.
	//lo hago de esta manera porque no se si el usuario quiere empezar primero desde la pila 2 o desde la pila 1
	//por lo que es mejor incializarlas de la mejor manera, asi depende de cual incialice primero el otro
	//tendra el ultimo indice del primero.


	//iniciarI e InicarJ, estan en el momento incializados en 0,estas variables me serviran de apoyo para saber
	//con cual pila se inicio primero y asi poder pasarle el indice de valor al siguente.
	int opc,N=-1,pila1=-1,pila2=-1,iniciarI=0,iniciarJ=0;
	int seguir=0;


	//en este while, lo que esta comprobando es que N ingresado por el usuario sera mayor a 0, en primero
	//lo ponemos en -1, 
	while(N<0){
		printf("introduzca el tamanio del arreglo: ");
        	scanf("%d",&N);
		if(N<0){
			printf("el numero debe ser mayor a 0\n");

		}
	}
	//solo se puede usar un solo arreglo.
	//declaracion del arreglo principal, este sera de tamanio N.

	int arregloPrincipal[N];


	//inicializacion:
	//con un if,como la iniclaizacion de estas vairbales ocurre fuera del ciclo, por lo que permanezara con el 
	//mismo valor siempre y cunado no se salga de este.

	do{

		printf("1) push - pila 1\n");
		printf("2) push - pila 2\n");
		printf("3) pop - pula 1\n");
		printf("4) pop - pila 2\n");
		printf("5) mostrar pila 1\n");
		printf("6) mostrar pila 2\n");
		printf("7) salir\n:");
		scanf("%d",&opc);



	switch(opc){


	//antes de enviar un pop por ejemplo, si al incio quiere hacer un pop debemos verificar si la pila tiene
	//algun elemento

		case 1:
			//en este punto solo 1 deberia de ser diferente. en este caso como se va a empezar con la pila1
			//por lo que inicializamos el indice i, que es el que nos va apoyar con la pila 1
			//para el control de los indices
			if(iniciarI==iniciarJ){
				iniciarI=1;
			}
			else{
				i=j;
			}

			//operacion 
			if(i<0){
			//la pila no esta inicilizada

			}

		case 3:
			//si la pila aun no esta inicializada, quiere decir que no hay elementos aun.
			if(i<0){
				printf("ups!\nla pila 1 no tiene elementos aun.");
			}

			else{

			}

	}


	}while(opc!=7);



}
