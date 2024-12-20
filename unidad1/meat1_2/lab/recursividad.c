#include<stdio.h>
#include<stdlib.h>
/*garcia chavez erik 01275863
algoritmos y estrucutura de datos

practica 2 recursividad

ciclo 2024-2*/


//�a fujcion que me va a retornar??
/*
lo que la funci9n me va a retornar rs la csntidad de gatos que tuve casa gata, me explico

en el problema principal nos dice que rn el primer a�o 1 fata tuvo 12 gatos, pero el 75% son henbras

para que la formula funcione con recurcibidad la formula sera por dar un ejemplo


total_gatos=((12*75)/100)*12

desglosando la forumla tenemos

total_gatos= ((nacimientosPerHembra*porcentajeHembras)/100)*nacimientosPerHembra -> esta primrea parte nos dara el total de
hembras que hay por embarazo

se divide entre 100 porque estoy usando numeros enteros, cunado trabajo con porcentaje en numreos flotantes siempre me falla,
para evitarme dolores de cabeza con numeos enteros y entre 100 nunca falla, a esos le multiplico el total de gatos que
 tiene cada hembra, que me dara en el primer ejemplo 108, ese valor es el total de gastos que nacdeiron en ese anio, y
 a ese se vuelve a aplicar lo mismo



*/
int natalidad(int nacimientosPerHembra,int porcentajeDeHembras,int anios){

    int nacimientos_actuales,nacimientos_anteriores;
	//nuestro caso base es cuando los anios sean 1

	if(anios==1){
        //nuestro caso base, que se resuelve sin la necesidad de la recursividad
        //es para en caso del primer anio, como al usuario se le pide la cantidad de
        //hijos que tiene cada gata por anio, ese es lo que se manda para atras de nuevo.

        return nacimientosPerHembra;
	}

    return ((natalidad(nacimientosPerHembra,porcentajeDeHembras,anios-1)*porcentajeDeHembras)/100)*nacimientosPerHembra;
}


//esta funcion si que me va a regresar el total de gatos, se va a estar sumando cada vez que se mande a llamar. x

//


int main(){

/*informacion que ingresara 3l usuario

1-cantidad nacimi3ntos por h3mbra
2-pprcentaje de hembraa por nacimeintos
3-la canridad de a�ps que se desea calcular

*/

	puts("\t****control de natalidaa en felinos***\n");

	//por lo debelos pedirle al usuario 3sa infoemscion

	//punto importante es si el programa me va a regresar a
	//3l programa  regresara algo, esta implisito en la
	//recursividad

	int nacimientosPorHembra,porcentajeDeHembras,aniosCalcular;

/*esta variables me van a ayudar a llevar el control que m3 duvueleve la funcion, nacimi3nto_anio m3 ayuda para que
en cada iterwcion me devueleva el total de felinos que nacieron en cieeto año

el total va ir sumando cads retorno, los naciemientos del año paaado con los nacimientos del año presente para poder dar el
total de felinos que nacieron

i, esta variable es la clave de esto, el f7ncionamiento me notr de tecursividad fue, cuando le manda por ejemplo 5, a como la
tenia que le retaba 1 esl lo hice ppr ewta razon de que tengo que ir disminuy3nd los años para caocular de cada año y
acumularlo, la funcion se llaman a wi misma pero cada vrz con con menos 1 en añios hasta llegar a la condicion base que
ea cuando ea el priemer añp que es cuantos gatos tiene cada gata por año,  y despuws el otro compprtali3nto qu3 no se explicar
es cuando llega a 1 aumenya anios la condicon quw trngo hatsa llegar a n-1 donde devuelve, por lo que esta variable enviara
 1 a 1 los años hasta lkegar a los años ingreador por 3l usuairo. en cada iteracion se ira acumulando los felinos que nacieron
en n año empezando con el priemro por ejemplo 12 despues devuvoe 108 eso se wxplixa en la fomrila arriba. */
	int naciminto_anio=0,natalidad_total=0, i=1;


	printf("ingrese la cantidad de nacimientos por hembra: ");
	scanf("%d",&nacimientosPorHembra);

	printf("ingrese el porcentaje de hembras por nacimeinto: ");
	scanf("%d",&porcentajeDeHembras);

	printf("ingrese la cantidad de anios a calcular: ");
	scanf("%d",&aniosCalcular);

/*esta partr es ña que no me convence del todo dsdo que a lo que vi la recurcividad se hace pars estps caso y evitar loa ciclos,
pero no supo otra forma de acerlo tal vez con otta funcion pero no pude implementarla, bueno el clcio empieza en 1 ppr lo que
la funcion me va a regrrsar 12, esto porque? ppr la condicion de la misma funci9n que indixa que wi anio es igual a 1 devuelve
lps nacimientos pot hembra pongo el ejemplp de 12 pero puede ser cualquiera, por lo que aumneta i hasta llegar a los anios
introducidis, ahora anioa vale 2 hace el comportamiento que mencionamoa en la funcion tendra los nacimientos por hembra que
inteodujo eñ usuairo,  ahora calcuñara los del sigui3ntr año con respexto a los nacimi3ntos del año anterior. y asu haata
acabar 3l ciclo despues todos se van sumando y nomaa se imprime. */
	while(i<=aniosCalcular){
		naciminto_anio=natalidad(nacimientosPorHembra,porcentajeDeHembras,i);

		printf("anio %d -> %d. \n",i,naciminto_anio);
		natalidad_total+=naciminto_anio;
		i++;

	}



	printf("gatos totales: %d\n ",natalidad_total);


	return 0;


}

