#include<stdio.h>
#include<stdlib.h>



//�a fujcion que me va a retornar??
/*
lo que la funci9n me va a retornar rs la csntidad de gatos que tuve casa gata, me explico

en el problema principal nos dice que rn el primer a�o 1 fata tuvo 12 gatos, pero el 75% son henbras

para que la formula funcione con recurcibidad la formula sera por dar un ejemplo


total_gatos=((12*75)/100)*12

desglosando la forumla tenemos

total_gatos= ((nacimientosPerHembra*porcentajeHembras)/100)*nacimientosPerHembra -> esta primrea parte nos dara el total de hembras que hay por embarazo

se divide entre 100 porque estoy usando numeros enteros, cunado trabajo con porcentaje en numreos flotantes siempre me falla, para evitarme
dolores de cabeza con numeos enteros y entre 100 nunca falla, a esos le multiplico el total de gatos que tiene cada hembra, que me dara en
el primer ejemplo 108, ese valor es el total de gastos que nacdeiron en ese anio, y a ese se vuelve a aplicar lo mismo


totalGato=()
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
   
    nacimientos_anteriores=natalidad(nacimientosPerHembra,porcentajeDeHembras,anios-1);

    nacimientos_actuales=(nacimientos_anteriores*porcentajeDeHembras/100)*nacimientosPerHembra;

    return nacimientos_actuales;


    /* Calculamos el total acumulado hasta el año anterior
    int total_anterior = natalidad(nacimientosPerHembra, porcentajeDeHembras, anios - 1);
        
        // Calculamos los nacimientos actuales con base en los nacimientos del año anterior
    nacimientos_actuales = (total_anterior * porcentajeDeHembras / 100) * nacimientosPerHembra;
        
        // Total acumulado hasta el año actual
    int total_actual = total_anterior + nacimientos_actuales;
        
        // Imprimimos el resultado acumulado hasta el año actual
    printf("Año %d: %d\n", anios, total_actual);
        
    return total_actual;*/
    //nacimientos_actuales=((natalidad(nacimientosPerHembra,porcentajeDeHembras,anios-1)*porcentajeDeHembras)/100)*nacimientosPerHembra;

    //printf("%d\n",nacimientos_actuales);
    
    //return ((natalidad(nacimientosPerHembra,porcentajeDeHembras,anios-1)*porcentajeDeHembras)/100)*nacimientosPerHembra;

}


//esta funcion si que me va a regresar el total de gatos, se va a estar sumando cada vez que se mande a llamar. x
int gatos_totals(int nacimietosPorHembra,int porcentajeDeHembras,int anios){

    int total_gatos=0,gatos_actuales,gatos_anteriores;

    if(anios==1){
        return nacimietosPorHembra;
    }

    gatos_anteriores=gatos_totals(nacimietosPorHembra,porcentajeDeHembras,anios-1);
    gatos_actuales=natalidad(nacimietosPorHembra,porcentajeDeHembras,anios);

    printf("%d \n",gatos_actuales );

    total_gatos=gatos_anteriores+gatos_actuales;

    return total_gatos;
}


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

    //esta variable lo que hara es sumar el total de felinos por cada anio
    //para mostrar el total despues de los x anios.
    int natalidad_total;

	//lo que debe de regrrsar ew la cantidad de


	printf("ingrese la cantidad de nacimientos por hembra: ");
	scanf("%d",&nacimientosPorHembra);

	printf("ingrese el porcentaje de hembras por nacimeinto: ");
	scanf("%d",&porcentajeDeHembras);

	printf("ingrese la cantidad de anios a calcular: ");
	scanf("%d",&aniosCalcular);


    
    natalidad_total=gatos_totals(nacimientosPorHembra,porcentajeDeHembras,aniosCalcular);
    //total_felinos=natalidad(nacimientosPorHembra,porcentajeDeHembras,aniosCalcular);
    //esto enviarlo a recursividad
    /*for(int i=1;i<=aniosCalcular;i++){

        int nacimientos=natalidad(nacimientosPorHembra,porcentajeDeHembras,i);
        total_felinos+=nacimientos;
        printf("anio %d -> %d felinos\n",i,nacimientos);

    }*/


	//int gatosTotales=natalidad(nacimientosPorHembra,porcentajeDeHembras,aniosCalcular);

	printf("gatos totales: %d\n ",natalidad_total);


	return 0;


}

