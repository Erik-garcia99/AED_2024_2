#include<stdio.h>

/*
*garcia chavez erik 01275863
*practica de laboratorio 3
*pilas estaticas
*miercoles 11 de septiembre del 2024


*/

//esta funcion push, funciona bajo algunas condiciones, no me agrada como lo hice, pero fue la unica
// forma en como ligre que funcionara, utilice varias bandera y condiciones, no logre que se coordinara,
// si inicaba una  pila luego en la otra no entraba, tal vez la logica, 

//por lo que esta funcion lo que me va a retornar va a hacer el valor del indice de la pila, 
//porque yo a las pilas las estoy viendo comomo un indice, 
int push(int arregloP[],int N,int pila,int pila2,int dato,int pilaSeleccionada){
    //la pila uno sera seelccionada, hagamos el caso en que se introduces siempre valores adecuados, 
    //porque si no, va a tronar
    if(pilaSeleccionada==1){
        
        if(pila<=pila2){

            arregloP[pila]=dato;
            pila++;
            return pila;

        }
        else{
            puts("la pila ya esta llena");
            return pila;
        }

    }

    else if(pilaSeleccionada==2){

        if(pila2>=pila){

            arregloP[pila2]=dato;
            pila2--;
            return pila2;

        }
        else{
            puts("la pila ya esta llena");
            return pila2;
        }

    }

    //considerando que nunca va a llegar a este punto. si llega el programa va a romper
    return 0;

}




void mostrar(int arregloP[],int N,int pila,int pila2,int pilaSeleccionada){

    //okay, no quiero modificar los indices=pilas, por lo que debo de pasarlo a una copia

    int i=pila,j=pila2;

    if(pilaSeleccionada==1){
        printf("valores de la pila 1\n");
        for(int k=0;k<i;k++){
            printf("%d -> %d\n",k,arregloP[k]);
        }


    }

    else if(pilaSeleccionada==2){
        printf("valores de la pila 2\n");
        for(int l=N-1;l>j;l--){
            printf("%d -> %d\n",l,arregloP[l]);
        }

    }

    else{
        puts("no se ha seleccionado ninguna pila");


    }


}

//funcion pop, parametros parecido a mostrar 


int pop(int arregloP[],int N,int pila,int pila2,int pilaSeleccionada){


    //para las pilas=indices, se hara lo contrario que en push, en la pila1 si se tienen 5 elementos
    //por ejemplo, y se va a quitar uno, entonces debemos asignarle un valor a 0 y decrementar el indice
    //de esa pila. la funcion va a hacer muy parecido a un push. 

    if(pilaSeleccionada==1){
        //porque mayor a igual a 0, porque 0 es mi primer elementos en un arreglo, por lo que 
        //para el arreglo la posicion 0 se toma en cuenta como una posicion que contiene un elementos
        
        if(pila>=0){
            //en este momento pila conetine el ultimo elemento que se le ingreso, porque -1, esto se debe 
            //a como tengo construido la llamada a la funcion, en el while, primero mando a la funcion
            //con pila=0, entonces ingresara un numero en el indice cero, despues incrementa y retorna el valor
            //incrementado, si solo ingresaria 1 valor, entonces pila1=1 seria en efecto el ultimo valor ingresado
            //pero este no se cuenta como parte de esa pila, pir lo que hasta en donde queda esa pila es en el
            //anterior a ese, aqui puede confundir si es 0, y se le resta 1 seria -1, pero no pasa aqui, 
            //porque el numero que se retorna es 1 en caso de solo ingresar 1 vez un valor por lo que solo
            //tendria en 0, siempre va a ser un numero mayor a 0. y cero tendra un valor asignado
            arregloP[pila-1]=0;

            pila--;

            return pila;

            
        }

        else{
            puts("la pila ya esta vacia");
            return pila;
        }


    }


    else if(pilaSeleccionada==2){
        //aqui pasa algo similar, la manera de la llamda es la misma, pero como esta vez
        //se inicia desde la ultima posicon, entonces el valro de pila2 que se va a retornar en caso 
        if(pila2<=N-1){
            arregloP[pila2+1]=0;
            pila2++;
            return pila2;
        }

        else{
            puts("la pila ya esta vacia");
            return pila2;
        }

    }

    else{
        puts("no se ha seleccionado ninguna pila");
        return 0;


    }
}

int main(){



    int opc, pila1=0,pila2,N=-1,iniciaP1=0,iniciaP2=0,seguir=1,dato;
    int inicioP1=0,inicioP2=0;

    while(N<=0){
		printf("introduzca el tamanio del arreglo: ");
        scanf("%d",&N);
        if(N<0){
            printf("el numero debe ser mayor a 0\n");

        }
	}

    int arregloPrincipal[N];

    pila2=N-1; //va a optener el ultimo elemento del arreglo
    printf("pila2: %d\n",pila2);	



    do{

        printf("\n1) push - pila 1\n");
        printf("2) push - pila 2\n");
        printf("3) pop - pila 1\n");
        printf("4) pop - pila 2\n");
        printf("5) mostrar pila 1\n");
        printf("6) mostrar pila 2\n");
        printf("7) salir\n:");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            seguir=1;
            iniciaP1=1;
            while(seguir!=0 && pila1<=N && pila1<=pila2){

                printf("ingrese el dato que quiere ingresar a la pila 1: ");
                scanf("%d",&dato);
                //push me va a regresar el valor del indice de la pila 1
                pila1=push(arregloPrincipal,N,pila1,pila2,dato,1);

                printf("\nquires ingresar otro dato. \n1)si 0)no:");
                scanf("%d",&seguir);

            }

            if(pila1==N || pila1>=pila2){
                puts("la pila ya esta llena");
            }


           /* for(int i=0;i<N;i++){
                printf("%d -> %d\n",i,arregloPrincipal[i]);
            }*/


            break;



        case 2: 
            seguir=1;
            iniciaP2=1;
            while(seguir!=0 && pila2>=0 && pila2>=pila1){


                printf("\ningrese el dato a pila2: ");
                scanf("%d",&dato);

                pila2=push(arregloPrincipal,N,pila1,pila2,dato,2);

                printf("\nquires ingresar otro dato. \n1)si 0)no:");
                scanf("%d",&seguir);
            }


            if(pila2==0 || pila2<=pila1){
                puts("la pila ya esta llena");
            }
            /*for(int i=0;i<N;i++){
                printf("%d -> %d\n",i,arregloPrincipal[i]);
            }*/
        
            break;

        case 3: 

            seguir=1;
            //creo que va a haber un problema cunado la pula este llena y esten las 2 pilas seguidas.
            while(seguir!=0 && pila1>=0 && pila1<=pila2){

                pila1=pop(arregloPrincipal,N,pila1,pila2,1);

                printf("\nquires eliminar. \n1)si 0)no:");
                scanf("%d",&seguir);
            }

            if(pila1<0 || pila1>=pila2){
                puts("la pila ya esta vacia");
            }
        
            break;

        case 4: 

            seguir=1;

            while(seguir!=0 && pila2<=N-1 && pila2>=pila1){

                pila2=pop(arregloPrincipal,N,pila1,pila2,2);

                printf("\nquires eliminar. \n1)si 0)no:");
                scanf("%d",&seguir);
            }
        
            break;

        case 5: 
            if(iniciaP1==1){
                mostrar(arregloPrincipal,N,pila1,pila2,1);
            }
            else{
                puts("no se ha ingresado ningun dato a la pila 1");
            }
        
            break;

        case 6: 

            if(iniciaP2==1){
                mostrar(arregloPrincipal,N,pila1,pila2,2);
            }
            else{
                puts("no se ha ingresado ningun dato a la pila 2");
            }
        
            break;
        
        }





    }while(opc!=7);



    return 0;
}