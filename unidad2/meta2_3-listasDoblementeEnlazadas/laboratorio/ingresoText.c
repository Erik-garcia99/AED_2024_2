#include<stdio.h>



struct String{

	char nombre[20];


};



void capturar(struct String *nombre){


	printf("ingrese el nombre");
	gets(nombre->nombre);

}


int main(){

	struct String *persona;
	capturar(persona);

	printf("nombre: %c",persona->nombre);



	return 0;
}
