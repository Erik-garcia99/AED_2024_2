#include<stdio.h>
#include<stdlib.h>

/*
*garcia chavez erik 01275863
*practica de laboratorio 3
*pilas estaticas
*miercoles 11 de septiembre del 2024


*/


/*
	*****penditnes y a considerar****


*por ahora solo estas haciendo nomral,pero debes de consideras las opciones de cunado se esta llena ya el arreglo y 
se quier volver a ingresar algo, debes de decirle que las pilas estan llenas, debe de liberar espacio 

*el indice, de las pilas, cunado se inicio con X pila, a la hora de mostrar esta tendra una longitud de hasta n-1, 
se quedo en n, pero cunado se le pregunta si quier continuar esta en n+1, por lo que el numero real de elementos
de la pila es hasta n-1, por lo que debemso considerar eso a la hora de imprimir en una pila, eso lo estoy viendo 
con parametros, apsar cual ya esta empezado y asi considerarlo, asi como los indices de inicio y final talvez.



*/



//por ahora void no se que quiero que me devuelva, pero a como veo, quiero que me devuelva el indice
//mi funcion push que es lo que va a recibir?, va a recibir primero el arreglo
//el tamanio ingresado por el usuario
//recibira el indice inical pero no el final

//creo que aqui tendre que hacer mi ciclo.
int push(int arregloP[],int N,int indice,int dato){

	if(indice<N){

		arregloP[indice]=dato;
		indice++;
	}
	else{
		printf("la pila ya esta llena");
	}


	return indice;

}


//aqui debo pasarle parametros para indicarle cunado quier imprimir el idnice que empieza desde 0 o el idnicde que
//empieza en la ultima posicon de la primera pila ejecutada.
void mostrar(int arreglo[],int N,int indice,int termina){



}


int main(){

	//declaracion de varibales

	//tengo que tener las 2 pilas claramente, que las voy a ver como si fueran indices para el arreglo prinicpal
	//no como otro arreglo independiente, porque se pide solo manjear un arreglo. por lo que en las funciones 
	//tendre que pasar el arreglo completo, no es eficiente, pero es a como se me ocurre.

	//primero debo verificar que las pilas, cualquiera de las 2 no ha sido incilaizada, inicializando la pila,
	//en -1

	//necsito algo mas que me indique que pila se inicio primero, porque puede iniciar en la pila 2 como en la
	//pila 1, por lo que necesito algo que me indique cual pila inicio primero.

	//inicia va a hacer mi inidcador que cual pila inicio primero, porque despues la otra pila que no ha 
	//iniclizado tendra como inicio la ultima posicon de la pila que ya inicio.

	//ahora el problema va a hacer con pop, porque con pop?, cunado se haga un pop en cualquiera de las 2 pilas
	//quiere decir que va a haber un lugar en ambas pilas que puede ser usado. asi que debo de decirle al programa
	//que estos espacios estan libres.

	
	int opc,N=-1,pila1=-1,pila2=-1,iniciaP1=0,iniciaP2=0;
	int seguir=1,dato;

	//pedir al usuario el tamanio del arreglo
	//va a verificar que el dato ingresado no sea un numero negativo, debe ser un numero positivo, mayor a 0
	while(N<=0){
		printf("introduzca el tamanio del arreglo: ");
                scanf("%d",&N);
                if(N<0){
                        printf("el numero debe ser mayor a 0\n");

                }
	}

	//declaramos el arreglo con las posciones que ingreso el usuario

	int arregloPrincipal[N];



	//inicio del ciclo principal un do-while


	do{

		printf("\n1) push - pila 1\n");
                printf("2) push - pila 2\n");
                printf("3) pop - pula 1\n");
                printf("4) pop - pila 2\n");
                printf("5) mostrar pila 1\n");
                printf("6) mostrar pila 2\n");
                printf("7) salir\n:");
                scanf("%d",&opc);

		switch(opc){


			case 1:{


				//antes que anda, como quiero ingresar los datos al arreglo?, he pensado en la manera en como
				//estoy haciendo el programa, es mediante un ciclo que se repita y el usuario pueda
				//ingreasr los datos en cun ciclo talvez while, creo que es lo mas optimo, verificar que los
				//datos no superen N del usuario,


				if(iniciaP1==iniciaP2){
				//esta condicion me dice que aun no ha incializado algo, por lo que inicilizamos P1
				//este me va a servir para saber a cual le debo de pasar el ultimo indice de la primera 
				//pila que se ingreso 

				iniciaP1=1;
				//como ninunga esta inicilizada, por loq ue se inicio primero con pila1, por lo que
				//ahora tiene el valor de 0. el indice, ahora, hmmm, deam, para ingresar, como le hare?
				//hmmmm..., interesante.

				//tengo 2 opciones, tengo la idea de con un ciclo que ingrese hasta que el usuario 
			//quiera pero no se si aqui, y solo llamar a push o hacerlo desde push.

			//hare el ciclo while desde este punto, solo mandare a llamar a la funcion push que se
			//se encargara de ingresar datos a la pila, el if solo ingresara 1 vez, cunado apenas
			//inicie el programa, por ejemplo si se haria un pop podrai ingresar una segunda 
			//vez perovesta vez en el else

			//la varibale seguir para mi representa que el usuario quiere ingresar de nvo datos.
			//cunado no este va a salir.
				while(pila1<N && seguir!=0){

					if(pila1<0){
						pila1++; //ahora pila1=0
						printf("ingrese el dato a la pila: ");
						scanf("%d",&dato);
						//se supone que este me deberia de devolver 1, en la priemra
						//iteracion porque solo se ha llamado una vez, 
						pila1=push(arregloPrincipal,N,pila1,dato);
					}
					else{
					//cuando ya no quiera ingresar mas elementos este se quedara en una
					//posicion la cual no es la suya, porque la ultima posicion en donde
					//hay datos que correspondes a esta pila es en pila1-1, porque la 
					//posicion en donde se quedo ya corresponderia a pila2.
						printf("ingrese el dato a la pila: ");
						scanf("%d",&dato);

						pila1=push(arregloPrincipal,N,pila1,dato);

					}

					printf("\nquires ingresar otro dato. \n1)si 0)no:");
					scanf("%d",&seguir);
				}



			}

			//else de afuera
			else{
				//en este otro caso, quiere decir que primero se ingreso en la pila 2, por lo que
				//pila1 toma el valor de indice incial del ultimo termino que tiene pila2.

				//en este punto, por ejemplo para esta condicion, se inciio primero con pila2, despuies
				//vamos con la 1, aqui no debo considerar inicarla, porque ya se inicio con pila2
				//pila 1 lo que hara es continuar con el arreglo,

				pila1=pila2;

				while(pila1<N && seguir!=0){

					printf("ingrese el dato a la pila: ");
					scanf("%d",&dato);

					pila1=push(arregloPrincipal,N,pila1,dato);

					printf("\nquires ingresar otro dato. \n1)si 0)no:");
                                        scanf("%d",&seguir);
				}
			}


			/*solo para pruebas borralo para la entrega
			for(int i=0;i<N;i++){

				printf("%d -> %d\n",i,arregloPrincipal[i]);
			}*/
		
			}break;

			case 2:{

				//push pila 2

			//la logica y la idea es la misma.peor en este caso es teniendo en cuenta lo que hay en pila2

				if(iniciaP2==iniciaP1){
			//si son iguales quiere decir que ninguno ha iniclaizado, por lo que en este caso incia P2

				iniciaP2=1;

				//no ha inicilizado por lo que tenemos que inciliazarla, solo ingresara cunado pila2
				//sea menor a 0, osea -1, osea que no ha iniciado
				while(pila2<N && seguir!=0){

					printf("ingrese el dato a pila: ");
					scanf("%d",&dato);

					if(pila2<0){

						pila2++;
						pila2=push(arregloPrincipal,N,pila2,dato);
					}
					else{

						pila2=push(arregloPrincipal,N,pila2,dato);
					}

					printf("\nquires ingresar otro dato. \n1)si 0)no:");
					scanf("%d",&seguir);
				}

			}

			else{
			//si no P2 tiene la ultima posicion que tenia P1

				pila2=pila1;

				while(pila2<N && seguir!=0){
					printf("\ningrese el dato a la pila:");
					scanf("%d",&dato);

					pila2=push(arregloPrincipal,N,pila2,dato);

					printf("\nquires ingresar otro dato. \n1)si 0)no:");
                                        scanf("%d",&seguir);

				}

			}

				


			}break;

			case 3:{

			}break;

			case 4:{

			}break;

			case 5:{


			}break;

			case 6:{

			}break;

			default:printf("se ha ingresado un indice no correcto, intenete de nuevo");break;



		}


	}while(opc!=7);






	return 0;
}
