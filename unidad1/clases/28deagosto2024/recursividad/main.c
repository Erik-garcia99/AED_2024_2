#include <stdio.h>
#include <stdlib.h>


int factorial(int n){


    if(n<=1){
        return 1;

    }
    else{
        return n + factorial(n-1);
    }
}

int main()
{
    int fac;
    fac=factorial(3);
    //este me esta regresando un numero entero, que es guardado en la variable.
    printf("%d",fac);
    return 0;
}
