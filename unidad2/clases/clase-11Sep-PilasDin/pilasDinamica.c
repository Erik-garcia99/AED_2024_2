#include<stdio.h>



int main(){

	int *direccion;
	int edad;


	printf("cuantos anios tienes: ");
	scanf("%d",&edad);

	direccion=&edad;
	//este me va a imprimir la direccion en memoria del apuntador direccion
	printf("\ntu edad esa guardada en la posicion de memoria: %d",direccion);
	//me va a devolver el valor que hay en la direccion en memoria guardad en direccion, osea va a ir a la direccion
	//de edad y imprimira ese valor
	printf("\ntu edad es: %d",*direccion);
	
	//va a imprimir la direccion de edad, porque ese valor es el que tiene guardado direccion
	printf("\nel apuntador a tu edad esta guardado en la posicion de memoria: %p",&direccion);



	return 0;
}
