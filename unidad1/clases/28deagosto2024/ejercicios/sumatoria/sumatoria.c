#include<stdio.h>


int suma(int n){

	/*razon de esta solucion, el problema se me hizo muy parecido en el factorial, esto porque, el problema quiere la sumatoria de los primeros 
	N numeros, donde N es el numero maximo, por ejemplo si el usuario quiere la suma de 5 la solucion matematicamente seria, 5+4+3+2+1 = 15, porque no
	no tomo en cuenta en 0, porque el cero no tiene relevancia en el ejercicio, por lo que nos lo podemos evitar, para calcular el factorial seria 
	n*factorial(n-1), porque si queremos 5, el resultado de esa suma es 5, si nosotros acemos lo siguiente 5+(4+3+2+1) -> 15, por loq ue si hacemos 4+(3+2+1) -> 10 y a esto le sumo 5 nos da 15, y asi hasta acabar al llegar al 1, porque 1 es nuestro caso base, porque si nos manda 1, la suma de los numeros positivos hasta 1 es igual a 1.*/


	if(n==1){
		return 1;


	}
	else{

		return n+suma(n-1);
	}
}


int main(){
	


	int sumatoria;
	int dato;

	printf("ingrese el numero que se le quiere hacer la suma: ");
	scanf("%d",&dato);


	sumatoria=suma(dato);

	printf("la sumatoria es %d",sumatoria);
	 

	return 0;

}