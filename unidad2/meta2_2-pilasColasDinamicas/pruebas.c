#include<stdio.h>

double potencia(double base, int exponente) {
    double resultado = 1.0;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

void main(){


	char caracter;
	long double numero;
	caracter=2;

	numero=1056799123934L;

	printf("%lf",numero);

	double exponente=5;

	for(int i=0;i<3;i++){
	
		exponente=(exponente,i);

	}

	printf("\n\n%i",exponente);
}
