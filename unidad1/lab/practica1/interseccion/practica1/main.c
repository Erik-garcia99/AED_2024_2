#include <stdio.h>
#include <stdlib.h>

/*
garcia chavez erik 01275863
algoritmos y estrucutra de datos
ingenieria en computacion 2024-2
practica 1

*/


//en esta funcion los vectores pueden ser de diferente valor, por lo que tenemos 2 opciones,
/*
1-cortar el ciclo aunque un arreglo aun tenga elementos
2-seguir comparando con espacios de memoria que contienen basura.

en mi opinion es mas apropiado es cortar con el mas chico.

la funcion recibe 2 vectors y 2 unidades de tipo enteros que representan el tamanio de cada vector.
mi idea es no pedirle al usuario el tamanio, creo que no seria lo adecuado si no contarlo por un ciclo.

*/
void interseccion(int vec1[], int vec2[],int n, int m){

    int i,j,valVec,contVec,*final;
    //este vector dinamico lo utilizare para hacer comparaciones, si tan solo se hace la compraracion de un numero con todo el segundo vector
    //nos imprimiria numeros repetidos, la idea viene de como lo hace en python que elimina o no agrega numeros repetidos dentre
    //los conjuntos, por lo que como los arreglos no tienen un tamanio definido, ocupo un tamanio dinamico para que este crezca conforme
    //se van agregando numero que estan en la interseccion.
    final=(int*)malloc(sizeof(int));

    for(i=0;i<n;i++){

        valVec=vec1[i]; //va a guardar el valor que esta en la posicion i del primer vector,
        //este se va a comprar con todos los elementos del segundo vector
        contVec=0; // porque lo vuelve a poner en 0, esto lo hago, porque primero, la idea del conjunto es como lo realiza python
                   // ya que python elimina los numero repetidos de cada conjunto, en el pero de los casos en mi algoritmo, se hara sobre la marcha
                   //por lo que usare otro vector de tamanio dinamico, el cual estara controlado por un contador.1
    //antes de ingresar, limpiamos nustros 2 vectores
        for(j=0;j<m;j++){

            if(valVec==vec2[j]){
                //si el valor del primer vector es igual al segundo vector, entonces se va a guardar en el vector dinamico, siempre y cunado este valor no se encuentre ya en el vector dinamico.
                for(int k=0;k<=contVec;k++){
                    //el como saber cunado estoy al inicio o al final de un vector dinamico, se me complico, lo que hice fue, asignar un contador, este contador va a reprsentar el tamanio total del vector
                    if(contVec==0){
                        //en este caso aun no inicalizamos el vector de espacio dinamico
                        *(final+contVec)=valVec;
                        contVec++;
                    }
                    //este pedazo de codigo, es el que mas complicado y sin sentido tiene, porque hace otra cosa a o que tenis planeado hacer, tiens un arreglo con los siguientes elemeos vec1=[1,2,3,4,7,9] y vec2=[1,2,5,6,7,9]
                    //que es lo que hace el codigo, como se mensiona arriba, pero agarra el primer digito de vec1[0]=1 y ese numero lo va a comprar con todos los digitos del vec2, en este caso la primera posicion de vec2 es igual que 1, vec2[0]=1
                    //por lo que en la condicion if(valVec==vec2[j]), entonces lo que tenis planeado, es hacer un arreglo dinamico, el cual guardara todos los elementos que esten en ambos arreglos pero sin reptir, para despues imprimirlos, pero no hace eso, lo que hace es que en la primera iteracion utilizo una variable llamada "contVec" la cual guarda la posicion+1 en el vector, esa era la idea, pero si le aumento en 1, en cualquier otra posicion del progrma este truena, por eso solo se agrego al inicio, por lo que solo hace 2 iteraciones en ciclo, en uno no imprime, pero en el otro si lo hace, 1



                    else if(valVec != *(final+k)){
                        //lo que esta haceindo en este linea y el porque no hago un suma en 1 del contador, que seria la logica en el porograma, esto es porque ahora mismo se puede decri que el vector, el apuntador final se ecuentra del arreglo,
                        *(final+contVec)=valVec;
                        printf("%d - ", valVec);

                    }

                }

            }
        }

    }

}




void diferencia_conjuntos(int vec1[],int vec2[],int n,int m){


    int i,j, valVec, validacion;
    int contador=0; //este valor nos va a servir para indicarle al algoritmo cuando se ha completado de recorrer el arreglo y no se ha encontrad
    //un numero que este en el otro arreglo, osea solo esta en ese mismo.

    //un vector dinamico per que no se de que tamanios son los arreglos que recibire como parametro, por lo que lo ideal es crear un
    //vector dinamico que nos diga
    //int *final=(int*)malloc(sizeof(int));

    for(i=0;i<n;i++){
        validacion=0;
        valVec=vec1[i];
        for(j=0;j<m;j++){

                if(valVec==vec2[j]){
                    //ojo en esta parte, porque si no ponias validacion en 0, el programa tomama el utlimo
                    //valor en 1,
                    validacion=0;
                    break;

                }
                else{


                    validacion=1;
                }
        }

        if(validacion){
            printf("%d -",valVec );
            contador++;
        }

    }
    //este solo es para mostrar un mensaje que todos los numeros dentro de ambos arreglos son iguales no hay diferencia entre ellos.
    //el contador solo cuenta las vece que entra en la conidcion, si esta es igual a 0. osea que nunca
    //entro, cunado salga del ciclo exterior, este
    if(contador==0){
        puts("todos los elementos de los 2 arreglos son iguales.");
    }
}




int main()
{



    int opc,n,m;

    do{
        printf("\n1) insercion de 2 arreglos\n");
        printf("2)diferencia entre el arreglo 1 y 2\n");
        printf("3) diferencia entre el arreglo 2 y 1\n");
        printf("4)salir\n:");
        scanf("%d",&opc);

        switch(opc){


            case 1:{

                /*---- ejercicio 1 -----*/
                puts("ingrese el tamanio del primer vector: ");
                scanf("%d",&n);
                int vec[n];


                printf("datos del vector 1\n\n");
                for(int i=0;i<n;i++){
                    printf("elementos en la posicion %d -> ",i);
                    scanf("%d",&vec[i]);
                }


                puts("\ningrese el tamanio del segundo vector: ");
                scanf("%d",&m);
                int vec2[m];

                puts("dato del vector 2: ");

                for(int i=0;i<m;i++){

                    printf("elementos en la posicin %d -> ",i);
                    scanf("%d",&vec2[i]);

                }

                interseccion(vec,vec2,n,m);
            }break;


            case 2:{

                /*----ejercicio 2 ----*/
                puts("\nejercicio 2\n ");

                puts("ingrese el tamanio del primer vector: ");
                scanf("%d",&n);
                int vec[n];


                printf("datos del vector 1\n\n");
                for(int i=0;i<n;i++){
                    printf("elementos en la posicion %d -> ",i);
                    scanf("%d",&vec[i]);
                }


                puts("\ningrese el tamanio del segundo vector: ");
                scanf("%d",&m);
                int vec2[m];

                puts("dato del vector 2: ");

                for(int i=0;i<m;i++){

                    printf("elementos en la posicin %d -> ",i);
                    scanf("%d",&vec2[i]);
                }

                diferencia_conjuntos(vec,vec2,n,m);

            }break;


            case 3:{
                //ahora este caso, estara al revez, se envia priemro en vector 2 y primero m que es el tamanio de ese vector
                //para comprar con los elementos del vec de tamanio n, esto nos tendria que imprimir todos los elementos que estan en el vector 2 pero no en el 1.


                /*----ejercicio 3 ----*/
    //cual es la diferencia entre el ejercicio 1 y el 2, el orden en como se mandan los arreglos a la funcion
    //el ejercicio pide que se impriman los numeros que estan en el arreglo 1 peri no en el arreglo 2
    //y el ejericio 3 pide que se imprimian los numeros que estan en el arreglo 2 pero no en el 1.

    //por ejemplo tenemos

    // vec1=[1,2,3,4] y vec2=[3,4,5,6]
    //esperarimos el resultado fuera vr=[5,6] dado que 3 y 4 estan en el vec1.
                puts("\nejercicio 3\n");

                puts("ingrese el tamanio del primer vector: ");
                scanf("%d",&n);
                int vec[n];


                printf("datos del vector 1\n\n");
                for(int i=0;i<n;i++){
                    printf("elementos en la posicion %d -> ",i);
                    scanf("%d",&vec[i]);
                }


                puts("\ningrese el tamanio del segundo vector: ");
                scanf("%d",&m);
                int vec2[m];

                puts("dato del vector 2: ");

                for(int i=0;i<m;i++){

                    printf("elementos en la posicin %d -> ",i);
                    scanf("%d",&vec2[i]);
                }

                diferencia_conjuntos(vec2,vec,m,n);






            }break;


            default:{
                puts("ingresaste un numero no valido, intenta de nuevo\n");
            }break;
        }



    }while(opc!=4);

    return 0;
}
