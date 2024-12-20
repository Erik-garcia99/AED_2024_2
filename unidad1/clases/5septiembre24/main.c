/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

/*
que es lo que vamos a hacer aqui, esta funcion devulvera 

    1 -> si esta llena 
    0 -> si aun no esta llena 
    
lo  queremos hacer lo mas genreal posible, por lo que en efecto vamos a mandar un arrelo en forma de puntero, 
pero ojo aqui, lo que C me va a mandar el el inicio de ese arreglo, por lo que necesitamos mandar el tamanio real de ese arreglo
que se va calcular antes de llamarla. 
*/

int llena(int *cola,int tamanio){
    
    
    
    
}


void main(){
    
    int pila[5]={0,0,0,0,0}, tope=-1,opcion=0,i=0;
    
    while(opcion!=5){
        
        printf("1) ingresar \n");
        printf("2) remover  \n");
        printf("3) vacia  \n");
        printf("4) llena  \n");
        printf("5)salir \n");
        printf("eligir la operacion a ejecutar: ");
        scanf("%d",&opcion);
        
        
        switch(opcion){
            
            //push
            case 1: 
            
                if(tope<4){
                    //en caso de ingresar cola y tope se comportan de manera similar, es en remover
                    //cunado su comportamiento cambia, tope debe volver al punto inical
                    tope++;
                    printf("introduce un numero a la cola: ");
                    scanf("%d",&pila[tope]);
                }
                else{
                    
                    printf(" \nla cola esta llena");
                }
                
                break;
            
            //pop
            case 2:
                
                
                if(tope>=0){
                    
                    printf("el elemento que sale de la cabeza es : %d\n",pila[i]);
                    pila[i]=0;
                    i++;
                    tope--;
                }
                else{
                    
                    printf("la pila esta vacia \n");
                }
                break;
                
                
            case 3:
                /*forma de como calcular el tamanio de nuestro arrelo, porque es de esta manera?
                cuando se hace uso de la funcion <sizeof> lo que va a devolver es el tamanio en bytes que ocupa el arrelo en la memria.
                no su longitud esto: sizeof(pila) devolvera el tamanio en bytes de todo el arreglo. 
                
                
                */
                int tamanio= sizeof(pila);
                
                printf("tamanio de la pila: %d",tamanio);
                
                
        }
        
        
    }
    
}