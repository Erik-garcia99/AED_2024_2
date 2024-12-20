#include<stdio.h>
#include<stdlib.h>


/*
que elementls ba a contrner nuestta estrucutura??

de lleno los apuntadores a sig, ant y un int de dsto
y un arrrglo de caracteres wue contendrs el nombre 


se solicita que por medio de listas doblemente enlazadas se ordenen de
forma alafeticamsnte usuarios, y otro caso en forma decendente 
conforme las calificaciones, 

por lo que se haran uso de 2 listas, cunado se ingresa un nuevo usuario 
este se va a acomodar dentro de ambas listas, dependiedno su caso

es 1 funcion para ingresar y otra para eliminar, pero como haremos para
saber cual es cual, creo que deberiamos de hacer uso de alguna variable
la cual la vamos a pasar la cual primero ordenara una, y despes, otra
que ordenara la otra, pero tal vez si 2 listas que hagan referencia a la misma
pero solo hacer uso de 1 funcion.

parapoder editar la calificacion, este tendria que buscar por el nombre, por lo que podemos hacer uso de la misma 
funcion que usamos para saber si el nombre es igual o diferente, en caso qeu sea igual regresara un 1 = TRUE pero si es diferente regresara un 0= FALSE, por lo que para ingresar normal necesitamos que sea diferente, 0, pero para editar necesitamos que sea igual TRUE.


hacer el orden como quien dice en un solo case, primero llamo con una bandera para que ordene el promedop y despues para que ordene el nombre 

con el editar una calificacion despues llamar a esta misma, pera ordenar por calificacion solamente, porque el nombre no cambio



el nombre lo ingresaremos y lo capturaremos con el getchar, 
creo que igual, dentro de un while hasta que encuentre el salto de liena, 
el nombre sera un arreglo estastico de 15 elememtnos, no me agrada tanto
esto, pero seria lo mas adecuado, aparte que no es un tamanio muy grande

1 funcion la cual compruebe si el nombre ya se encunetra dentro de la 
lista. 

las listas en su forma ordenada debe imprimri nombre y promedio. 


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

						/*la funcion tendra 2 apuntadores que apuntan al inicio, tendra el tamanio del nombre, tendra 
						la calificacion, y una bandera donde indicara cual se arregla primero, primero se arrega 1 despues
						regresa el inicio para despues ingresar el otro incio, en este momento no hay comprobaciones
						porque ya nombre se verifico que no este repetido */


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


					//se manda a llamar a alafuncio.
					/*
					int nombreDentroDLista=CompararNombre(ordenAlfa, nombre, tamanio);

					if(nombreDentroDLista==1){
						//si esa funcion me devuelve un 1 quiero decir que si hay un nombre igual al ingresado en la lista
						//por lo que va a la funcion de eliminar

						ordenarAlfa=

						
					}
					else{
						printf("el nombre ingresado no se encuentra dentro de la lista.\nintente de nuevo\n");
						
					}*/



					

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

						//ordenProm=reOrdendarProm(ordenProm);

						
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




/*ahora para crear el nodo se tendran 3 variables en cuenta, pero solo
2 entran en la estrucutrua, la cual es la calificacion la cual es un 
numero flotante, el tamanio representara el numoer de elementos que tendra
el arreglo nombre, este se calculara antes de ser envidado, una vez 
capturado el nombre y el nombre que es de tipo char, que es un apuntador
al primer elementos del arreglo.*/


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
		/*
		no creo que sea necesario sacar el tamanio del nombre de la estrucutura ya que este solo va a recorrer el del nombre si no  es se ira al 
		otro nodo.

		este va a regresar cunando el tamanio sea igual al contador
		
		*/

		for(int i=0;i<tamanio;i++){

			if(ordenAux->nombre[i] == nombre[i]){
				contador++;
				
				//en este caso llego al final y el contador es igual al tamanio que cada letra es igual, el nombre es el mismo

				if(i == tamanio-1 && contador == tamanio){

					return 1; //TRUE
				}
				
				//el caso que no son iguales
				/*el primero parametro de la condicional me dice que si "i" ya llego al final del nombre (tamanio-1)
				pero ademas el contador es menor al tamanio, por lo que hay ciertas letreas que son iguales pero no todas, queire
				decir que el nombre no es igual*/
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


		/*

		apuntadores


		struct Nodo *antAlf;
		struct Nodo *sigAlf;

		*/
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
	int cambio;
	

	//compuerba si la lista solo contiene un dato, este devuelve el inicio.
	if(p->sigProm==NULL){
		return incio;

	}


	do{

		cambio=0;
		p=incio;
		prev=NULL;


		while(p!=NULL && p->sigProm!=NULL){

			q=p->sigProm;


			if(p->calificacion<=q->calificacion){

				//modifica el inicio

				//este si funciona
				if(prev==NULL){

					p->sigProm=q->sigProm;
					q->sigProm->antAlf=p;
					q->sigProm=p;
					if(p->antProm==NULL){
						q->antProm=NULL;
					}

					incio=q;
					cambio=1;
				}


				// es donde esta fallando
				else{

					q->antProm=prev;
					prev->sigProm=q;
					p->antProm=q;
					if(q->antProm!=NULL){
						q->sigProm->antProm=p;
						p->sigProm=q->sigProm;

					}
					q->antProm=p;

					
					/*
					q->antProm=p->antProm;
					p->antProm->sigProm=q;
					//solo guardo minodo Q de manera temporal

					q->sigProm=p;
					p->antProm=q;
						//en medio,
					if(ayudaQ->sigProm!=NULL){
						p->sigProm=ayudaQ->sigProm;
					}*/

					

					


					/*
					p->antProm->sigProm=q;
					q->antProm=p->antProm;
					q->sigProm=p;
					p->antProm=q;
					if(p->sigProm!=NULL){

					}

					p->sigProm=q->sigProm;
					q->antProm=p->antProm;
					p->antProm->sigProm=q;
					q->sigProm=p;
					cambio=1;
					if(q->sigProm!=NULL){
						q->sigProm->antProm=p;
					}*/

				}

				
			}
			else{
				//avanza en la lista
					p=p->sigProm;
					q=q->sigProm;
					prev=p;
				
			}
		}


	}while(cambio == 1);

	//si recorre y sale, quiere decriq que el que se modifico fue el primero y por lo tanto no hace falta hacer cambios
	if(p==NULL){

		return incio;
	}



	return (incio);






}