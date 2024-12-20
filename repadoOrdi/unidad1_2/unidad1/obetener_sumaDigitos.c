#include <stdio.h>

int sumaRecursiva(int n);

int main(void)
{
    int suma = 0;
    suma = sumaRecursiva(256);

    printf("%d", suma);
}

int sumaRecursiva(int n)
{
    // la razon de que es menor a 9, porque es el ultimo digito a sumar, ya esta dentro de las decenas,
    if (n <= 9)
    {
        return n;
    }
    else
    {
        // lo que hace aqui es descomponer los digitos, primeor descompone en sus partes dividiendolo entre 10, para sacar sus partes lo cual se enviara de regreso a la recursiion, se suma el modulo, el digito mas a la drecha del numero.
        return sumaRecursiva(n / 10) + n % 10;
    }
}
