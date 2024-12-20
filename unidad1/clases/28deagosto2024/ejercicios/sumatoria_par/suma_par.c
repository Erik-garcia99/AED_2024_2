#include<stdio.h>


int suma_par(int n){


	
	if(n==2){
		/*este es nuestro caso base, cual es el numero positivo par mas pequenio que conocemos el 2, por lo que la suma de todos los nuermos 
		enteros postivos hasta 2, es igual a 2 */
		return 2;
	}

	else if(n%2==0){
	/*cual es la logica, la logica es casi la misma que en el primer ejercicio, en el cual se vana a sumar los numeros de N hasta 1, pero aqui es de N hasta 2, por lo que la logica es practicamente la misma, en esta condicion solo ingresaran los datos que sean pares, que cumplan con la condicion, por lo que la logica sigue siendo igual en donde es parecido al factorial en donde tomamos n por ejempolo 10 al cual lo sumamos cunado se manda a llamar otra vez, pero este siga siendo par, pero en caso que no es, no ingresa */
		return n+suma_par(n-1);
	}

	else if(n%2!=0){
		/*cunado entra o porque esta la condicion, esta condicion esta porque, en el caso que el residuo del valor al dividirse entre 2 es diferente
		a cero, eso quiere decir que el numeor no es par, por lo que no se hace ninguna operacion, se vuelve a llamar a si misma, pero decrementando
		su valor, por ejemplo 7, 7 no es un numero par, por lo que entra en esta condicion pero se va a volver a llamar con el numero 6 el cual
		ya es par, por lo que en esta ocacion no entrara en esta condicion.*/
		return suma_par(n-1);
	}

}



int main(){

	int sumaPar;
	int dato;


	puts("conocer la suma de todos los numeros pares positivos de N\n");
	printf("ingres el numero: ");
	scanf("%d",&dato);

	sumaPar=suma_par(dato);

	printf("sumatoria: %d",sumaPar);
	


	return 0;

}