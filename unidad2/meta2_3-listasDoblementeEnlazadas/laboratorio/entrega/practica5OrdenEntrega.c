#include<stdio.h>
#include<stdlib.h>

/*
garcia chavez erik 01275863
listas doblemente enlazadas
algoritmo y estructura de datos




 */

struct Nodo {

	int calificacion;
	char nombre[15];
	struct Nodo *antAlf;
	struct Nodo *sigAlf;

	struct Nodo *antProm;
	struct Nodo *sigProm;

};

struct Nodo *crearNodo(int calificacion, int tamanio, char *nombre);

struct Nodo *insertar(struct Nodo *ordenAlfa,struct Nodo *ordenProm, char *nombre,int calificacion, int tamanio, int flag);

struct Nodo *eliminar(struct Nodo *inicioListaOr,struct Nodo *inicioOrdProm, char *nombre,int tamanio, int flag);


int CompararNombre(struct Nodo *inicio, char *nombre,int tamanio);

void mostrarElementos(struct Nodo *ordenAlfa, struct Nodo *ordenProm, int flag);

//esta solo va a afectar a la estrucutura que ordena por promedio
struct Nodo *modificarElementos(struct Nodo *inicioProm,char *nombre, int tamanio);

struct Nodo *reOrdendarProm(struct Nodo *incio);






int main(){


	//necesito 2 pilas 1 que haga refereciencia al orden 
	//este apunta a mi inicio del orden alfabetico
	struct Nodo *ordenAlfa=NULL;

	//este hace referenica a mi inicio en orden por promedio
	struct Nodo *ordenProm=NULL;

	int opc,calificacion;
	
	//varibales para el nombre
	char nombre[15];
	
	int i;
	int tamanio;

	//comprobacion de que no se repitio el nombre
	int noRepetido;


	do{
		
		printf("\n1) Insertar alumno");
		printf("\n2) Eliminar alumno");
		printf("\n3) Modificar alumno (sólo el promedio)");
		printf("\n4) Mostrar ordenados alfabéticamente");
		printf("\n5) Mostrar ordenados por promedio");
		printf("\n6) salir");
		scanf("%d",&opc);

		getchar(); //limpiamos el buffer

		switch(opc){


			case 1:

				i=0;
		
				printf("ingrese el nombre del alumno: ");
				char palabra;
				
				//capturara el nombre caracter por caracter con la ayuda de la funcion getchar, hasta que el usuasrio haya ingresado enter
				while((palabra = getchar()) != '\n'){	
					nombre[i]=palabra;
					i++;
				}
				
				//getchar(); //vovlemos a limpiar porque estuvumos usando caracteres 

				printf("ingrese la calificacion: ");
				scanf("%d",&calificacion);
				

				tamanio=i;

				if(ordenAlfa==NULL){
					//aqui ingresa la primera vez que se ingresara un dato a la lista
					//aqui ingreso ambos al mismo nivel, dado que es el primero nodo no hay nada con que comparar
					ordenAlfa=crearNodo(calificacion,tamanio,nombre);
					ordenProm=ordenAlfa;
				}

				else{

					//aqui ya hay al menos 1 elemento dentro de la lista 

					noRepetido=CompararNombre(ordenAlfa,nombre,tamanio);
					
					//el nombre no se encuentra repetido
					if(noRepetido==0){

						//ingresa el nombre a la pila, en forma ordenana alfabeticamente y por promedio

						ordenProm=insertar(ordenAlfa,ordenProm,nombre,calificacion,tamanio,1);
						ordenAlfa=insertar(ordenAlfa,ordenProm,nombre,calificacion,tamanio,0);
						

						
	
					}
					else{
						printf("\nel nombre ya se encuentra dentro de la lista");
					}

					
					
				}

				fflush(stdin);break;

			case 2: 

				//eliminar un alumno,el proceso va a hacer parecido, antes de ir debemos verificar uqe lapila tenda al menos 1 elemntos
	

				if(ordenProm!=NULL){

					//primreo ingresmos el nombre, aqui podemos verificar si el nombre se encuentra en la lista, cual sea
					//las 2 contienen lo mismo solo que en orden disitnto, como digimos vamos air con la lista alfabetica

					i=0;
		
					printf("ingrese el nombre del alumno: ");
					char palabra;
				
					//capturara el nombre caracter por caracter con la ayuda de la funcion getchar, hasta que el usuasrio haya 
					//ingresado enter
					
					while((palabra = getchar()) != '\n'){	
						nombre[i]=palabra;
						i++;
					}
					//el tamanio de la cadena
					tamanio=i;

					ordenProm=eliminar(ordenAlfa,ordenProm,nombre,tamanio,1);
					ordenAlfa=eliminar(ordenAlfa,ordenProm,nombre,tamanio,0);

				}

				else{
					//si ordenProm no es diferente a NULL, entonces la lista esta vacia 

					printf("la lista se enceuntra vacia");
				}
			
			
			break;


			case 3:  

				//verificar que las pilas contengas algo 

				if(ordenProm!=NULL){

					i=0;
		
					printf("ingrese el nombre del alumno: ");
					char palabra;
				
					//capturara el nombre caracter por caracter con la ayuda de la funcion getchar, hasta que el usuasrio haya 
					//ingresado enter
					
					while((palabra = getchar()) != '\n'){	
						nombre[i]=palabra;
						i++;
					}
					//el tamanio de la cadena
					tamanio=i;


					//antes de ingresar verificar que este en la lista 

					int nombreDentroLista=CompararNombre(ordenAlfa,nombre,tamanio);

					if(nombreDentroLista==1){
						ordenProm=modificarElementos(ordenProm,nombre,tamanio);

						//prueba 

						ordenProm=reOrdendarProm(ordenProm);

						
					}

					else{


						printf("\nel nombre no se enceuntra dentro de la lista\n");
					}
					


				


				}
				else{
					printf("la lista esta vacia\n");
				}
			
			
			break;

			case 4:

			mostrarElementos(ordenAlfa,ordenProm, 0); break;

	
			case 5:

			//mostrar promedio

				mostrarElementos(ordenAlfa,ordenProm, 1);


			break;
			
		}




	}while(opc!=6);


	




	return 0;

}





struct Nodo *crearNodo(int calificacion, int tamanio, char *nombre){

	struct Nodo *nuevo;

	nuevo=(struct Nodo *)malloc(sizeof(struct Nodo));

	nuevo->calificacion=calificacion;

	
	//todos los indices apuntan a NULL
	nuevo->antAlf=NULL;
	nuevo->sigAlf=NULL;

	nuevo->antProm=NULL;
	nuevo->sigProm=NULL;
	
	//ahora a ingresar el nombre

	int i;

	for(i=0;i<tamanio;i++){
	
		nuevo->nombre[i]=nombre[i];
	}

	//agrego un caracer NULO al final del nombre, porque no se cunatas letras contiene el nombre, este va a hacer mi senial que indique que se termino el nombre y lo demas es basura
	 nuevo->nombre[tamanio] = '\0';



	return (nuevo);



}



int CompararNombre(struct Nodo *inicio, char *nombre,int tamanio){
	
	struct Nodo *ordenAux=inicio;
	
	
	
	//se necesita recorrer toda la lista para comprobrar nombre a nombre
	while(ordenAux!=NULL){

		int contador=0;


		for(int i=0;i<tamanio;i++){

			if(ordenAux->nombre[i] == nombre[i]){
				contador++;
				
				//en este caso llego al final y el contador es igual al tamanio que cada letra es igual, el nombre es el mismo

				if(i == tamanio-1 && contador == tamanio){

					return 1; //TRUE
				}
				
				//el caso que no son iguales
				else if(i == tamanio-1 && contador < tamanio){
					return 0;
				}
			}
			
	
		}

	ordenAux=ordenAux->sigAlf;
	}

	//si recorre toda la lista y no encuentra el nombre igual quiere decri que no esta por lo que regresa un 0=FALSE

	return 0;


}



//ingresar a al alista 

struct Nodo *insertar(struct Nodo *ordenAlfa,struct Nodo *ordenProm, char *nombre,int calificacion, int tamanio, int flag){
	
	//apuntadores al ordenar por promedio
	

	


	//si flag es 1 se va a orden por el promedio, este es primero porque es mas sencillo.
	if(flag ==1 ){
		//apuntadores 
		struct Nodo *Pp,*Pq=NULL,*Pnuevo;
		//struct Nodo *antProm;
		//struct Nodo *sigProm;


		
		//recibe la cabecera de orden por promedio;
		Pp=ordenProm;
		
		//crea el nodo nuevo 
		Pnuevo=crearNodo(calificacion, tamanio, nombre);

		while(Pp!=NULL && calificacion<=Pp->calificacion){

			Pq=Pp;
			Pp=Pp->sigProm;
		}

		if(Pq==NULL){
			Pnuevo->sigProm=Pp;
			Pp->antProm=Pnuevo;
			ordenProm=Pnuevo;

		}
		else{
			
			Pq->sigProm=Pnuevo;
			Pnuevo->antProm=Pq;
			Pnuevo->sigProm=Pp;
			if(Pp!=NULL){

				Pp->antProm=Pnuevo;

			}
			
		
		}

		return (ordenProm);

	}
	//en caso contrario, de preferencia 0, porque igual se puede mandar cualquier cosa que no sea 1, y entrara en este else, sera el ordenamineto 
	//alafabeticamente.

	else{

		struct Nodo *Ap,*Aq=NULL, *Anuevo;


		//recibe la cabeza
		Ap=ordenAlfa;

		Anuevo=crearNodo(calificacion, tamanio, nombre);
		
		//en C se puede hacer comparaciones entre caracteres con los simbolos de control, esto porque en C se trabaja con ASCII, entonces 
		// a = 97, e= 101, etc. por lo que en la condicion del while es que mientras que Ap (alfabetico), sea disitndo a NULL que no haya
		//llegado al final de la lista y ademas la primera letra del arreglo de nombre sea mayor la primera letra de lo que hay 
		//en Ap en su parte nombre.

		while(Ap!=NULL && nombre[0]>=Ap->nombre[0]){

			Aq=Ap;
			Ap=Ap->sigAlf;

			
		}

		if(Aq==NULL){

			Anuevo->sigAlf=Ap;
			Ap->antAlf=Anuevo;
			ordenAlfa=Anuevo;
		
		}

		else{

			Aq->sigAlf=Anuevo;
			Anuevo->antAlf=Aq;
			Anuevo->sigAlf=Ap;
			if(Ap!=NULL){

				Ap->antAlf=Anuevo;
			}
			
		}

		return (ordenAlfa);		

		
	}




}


void mostrarElementos(struct Nodo *ordenAlfa, struct Nodo *ordenProm, int flag){


	if(flag==1){

		

		if(ordenProm!=NULL){
		

			struct Nodo *auxProm=ordenProm;

			do{
				
				int i=0;

				while(auxProm->nombre[i]!='\0'){
					printf("%c",auxProm->nombre[i]);
					i++;
				}
				

				printf(" -> calificacion: [%d] \n",auxProm->calificacion);

				auxProm=auxProm->sigProm;


			}while(auxProm!=NULL);

		}
		else{
			printf("\nla lista se ecnuentra vacia");
		}

	}
	else{

		//va a mostrar de manera alfabeticamente, tomando el incii0o de la pila que esta ordenana de manera alfabetica

		struct Nodo *auxAlfa=ordenAlfa;

		do{
			int i=0;

			//imprimimos el nombre caracter por caracter ya que se se hace de manera completa con %s, me va a imprirmi basura despues del nombre 
			//o toda la cadena sera basura. 

			while(auxAlfa->nombre[i]!='\0'){

				printf("%c",auxAlfa->nombre[i]);
				i++;
			}


			printf(" -> calificacion [%d]\n",auxAlfa->calificacion);

			auxAlfa=auxAlfa->sigAlf;

		}while(auxAlfa!=NULL);


	}


}


//si es necesario ambas estrucutras 
struct Nodo *eliminar(struct Nodo *inicioListaOr,struct Nodo *inicioOrdProm, char *nombre,int tamanio, int flag){

	//esta funcion sera llamada 2 veces seguidas igual a como se inserta, el codigo sera el mismo, porque esta buscando por el nombre, 
	//el alumno puede estar en 2 posiciones diferentes en cada lista, por lo que es necesario que se envie a llamar 2 veces.
	struct Nodo *Pp=inicioOrdProm,*Pq=NULL;

	struct Nodo *p=inicioListaOr,*q=NULL; 

	if(flag==1){

		int bandera=0;

		while(Pp!=NULL && bandera==0){
			int contador=0;
			for(int i=0;i<tamanio;i++){
				
				if(Pp->nombre[i]==nombre[i]){
					contador++;

					if(i==tamanio-1 && contador==tamanio){
						bandera=1;
					}
					else if(i==tamanio-1 && contador<tamanio){
						bandera=0;
					}
				}

			}

			if(bandera==0){
				Pq=Pp;
				Pp=Pp->sigProm;
			}
		}

		if(Pq==NULL){

			inicioOrdProm=Pp->sigProm;
			if(inicioOrdProm!=NULL){
				inicioOrdProm->antProm=NULL;
			}
			//free(p);
		}

		else{

			if(Pp!=NULL){

				Pq->sigProm=Pp->sigProm;
				if(p->sigProm!=NULL){
					Pp->sigProm->antProm=Pq;
				}
				//free(p);

			}
			else{
				printf("el alumno no se econtro");
			}


		}


		return(inicioOrdProm);
	}
	else{
		//respaldo mis punteros
		//struct Nodo *p=inicioListaOr,*q=NULL; 
		//esta bandera me indicara que se ha encontrado el nodo con el nombre
		int bandera=0;

		while(p!=NULL && bandera==0){

			int contador=0;

			//(ordenAux->nombre[i] == nombre[i]);

			for(int i=0;i<tamanio;i++){

				if(p->nombre[i]==nombre[i]){
					contador++;

					if(i==tamanio-1 && contador==tamanio){

						bandera=1;
					}
					else if(i==tamanio-1 && contador< tamanio){
						bandera=0;
						
					}


				}

			}
			if(bandera==0){
				q=p;
				p=p->sigAlf;
			}

			

		}


		//le ndood a eliminar esta en la cabeza
		if(q==NULL){

			inicioListaOr=p->sigAlf;
			if(inicioListaOr!=NULL){

				inicioListaOr->antAlf=NULL;
			}
			free(p);


		}
		else{

			//la lista no llego hasta el final.
			if(p!=NULL){

				q->sigAlf=p->sigAlf;
				if(p->sigAlf!=NULL){
					p->sigAlf->antAlf=q;
				}

				free(p);


			}
			//la lista lelgo al final y no encoentro al alumno
			else{

				printf("el alumno no se encuentra en la lista");
			}
		}

		return (inicioListaOr);

	}
}


struct Nodo *modificarElementos(struct Nodo *inicioProm,char *nombre, int tamanio){


	struct Nodo *auxInicio=inicioProm;

	int bandera=0;
	//va a buscarel nodo con el nombre con la calificacion a modificar 

	int calificacion;
	


	while(auxInicio!=NULL && bandera==0){

		int contador=0;

		for(int i=0;i<tamanio;i++){

			if(auxInicio->nombre[i]==nombre[i]){
				contador++;
				
				//lo encoentro
				if(i==tamanio-1 && contador == tamanio){
					bandera=1;
				}
			}
			
		}

		if(bandera==0){
			auxInicio=auxInicio->sigProm;
		}

	}


	if(inicioProm!=NULL){

		printf("ingrese la nueva calificacion ");
		scanf("%d",&calificacion);

		auxInicio->calificacion=calificacion;

		printf("la calificacion de: ");
		int i=0;
		while(auxInicio->nombre[i]!='\0'){

			printf("%c",auxInicio->nombre[i]);
			i++;
		}
		printf(" se modifico a :%d\n",auxInicio->calificacion);

		
		


	}

	else{
		printf("\nocurrcio un error fatal!\n");
	}

	

	


	return(inicioProm);
	

}



//funcion que reordena la lista de promedio

struct Nodo *reOrdendarProm(struct Nodo *incio){

	
	struct Nodo *p=incio, *q=NULL,*prev,*ayudaQ;
	int cambio, finQ=0;
	int calificacion1, calificacion2;
	

	//compuerba si la lista solo contiene un dato, este devuelve el inicio.
	if(p->sigProm==NULL){
		return incio;

	}


	do{

		cambio=0;
		p=incio;
		prev=NULL;


		while(p!=NULL){

			q=p->sigProm;

			if(q==NULL){
				break;
			}
			calificacion1=p->calificacion;
			calificacion2=q->calificacion;


			if(calificacion1<calificacion2){

				//modifica el inicio

				//este si funciona
				if(prev==NULL){

					p->sigProm=q->sigProm;
					q->sigProm->antProm=p;
					q->sigProm=p;
					if(p->antProm==NULL){
						q->antProm=NULL;
					}

					incio=q;
					cambio=1;
				}


				// es donde esta fallando
				else if(q!=NULL){

					prev->sigProm=p->sigProm;
					q->antProm=p->antProm;
					
					if(q->sigProm!=NULL){
						q->sigProm->antProm=p;
						p->sigProm=q->sigProm;
					}
					if(q->sigProm==NULL){
						p->sigProm=NULL;
					}
					
					
					p->antProm=q;
					q->sigProm=p;
					cambio=1;


				}

				
			}
			else{
				//avanza en la list
					prev=p;
					p=p->sigProm;
					q=q->sigProm;

				
			}
		}


	}while(cambio == 1);

	//si recorre y sale, quiere decriq que el que se modifico fue el primero y por lo tanto no hace falta hacer cambios
	if(p==NULL){

		return incio;
	}



	return (incio);


}




