#include<stdio.h>
#include<stdlib.h>


int fibonacci(int n){



	if(n==0 || n==1){
		return n;

	}

	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}

}


int main(){

	int fibo;
	int ingresar;

	printf("ingrese el el termino de la sucesion de fibonacci quiere encontrar: ");
	scanf("%d",&ingresar);
	
	fibo=fibonacci(ingresar);

	printf("%d",fibo);

	return 0;
}

