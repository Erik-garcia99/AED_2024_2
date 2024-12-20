#include<stdio.h>




int llena(int tamanio,int *pila);
int vacia(int tamanio, int *pila);
void vaciar(int tamanio, int *pila);


int main(){

	int pila[5]={0,0,0,0,0};
	int tope=-1;
	int opcion=0;
	int tamanio;


	while(opcion!=10){


		printf ("1) Push \n");
		printf ("2) Pop \n");
		printf ("3) llena \n");
		printf ("4) vacia \n");
		printf ("10) Salir \n");
		printf (" Elige la operacion a ejecutar : ");	
		scanf (" %d", & opcion );


		switch(opcion){


			case 1:
				if(tope<4){
					tope++;
					printf (" Introduce un numero a la pila : ");
					scanf("%d",&pila[tope]);


				}
				else{
					printf ("La pila esta llena .\n");
				}

				break;

			case 2:

				if(tope>=0){

					printf ("El elemento que sale de la pila es: %d.\n", pila [ tope ]);
					pila[tope]=0;
					tope--;

				}

				else{

					printf("la pula esta vacia");
				}



				break;


			case 3:

				//calcula el tamanio del arreglo
				
				tamanio=sizeof(pila)/sizeof(pila[0]);

				

				int pilaLLena=llena(tamanio,pila);

				if(pilaLLena==1){

					printf("\nla piula esta llena\n");
				}
				else{

					printf("\nla pila cuenta con al menso 1 posicion mas\n");
				}


				break;


			case 4: 
				tamanio=sizeof(pila)/sizeof(pila[0]);
				
				int pilaVacia=vacia(tamanio,pila);

				if(pilaVacia==1){

					printf("\npila vacia\n");
				}
				else{
					printf("\nla pila no se encuentra vacia\n");
				}
			

				break;

			case 5:

				tamanio=sizeof(pila)/sizeof(pila[0]);

				vaciar(tamanio,pila);

				
				

				break;




		}

	}



	return 0;
}



int llena(int tamanio,int *pila){


	int vacio=0,lleno;

	for(int i=0;i<tamanio;i++){

		if(pila[i]==0){

			vacio++;
		}
	}

	if(vacio==0){
		//los elementos estan incializados en 0, por lo que 
		//si en la p
		return 1; //la pila esta llena
	}
	else{

		return 0; //hay al menso 1 posicion que tiene un valor
		//0, por lo que al menso hay 1 posicion en la lista
	}

}




int vacia(int tamanio, int *pila){

	int vacia=0;


	for(int i=0;i<tamanio;i++){

		if(pila[i]!=0){
			vacia++;
		}
	}


	if(vacia!=0){
		return 0;
	}
	else{
		return 1; //no encoentre ningun elemento diferente de 0
		//por lo que la pila esta vacia

	}


}


void vaciar(int tamanio, int *pila){




	for(int i=0;i<tamanio;i++){
	
		printf("elemento tope de la pila %d \n",pila[i]);
		pila[i]=0;
		
		
	
	}



}



