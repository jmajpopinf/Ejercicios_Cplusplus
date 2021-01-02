#include <stdio.h>

main() {

//declaracion de variables
int x, y;

//Ingresar primer numero en pantalla
printf("Escribe el primer numero: ");
//Ingreso de datos por el teclado
scanf("%d",&x);

//Ingresar primer numero en pantalla
printf("Escribe el segundo numero: ");
//Ingreso de datos por el teclado
scanf("%d",&y);

//condicion si x es mayor que y
if (x > y){
	//muestra el numero mayor es x
	printf("El mayor es: %d",x);
}
else{
	//condicion si y es mayor que x
	if ( y > x ){
		//muestra el numero mayor es y
		printf("El mayor es: %d",y);
	}
	else{
		//muestra que son iguales
		printf("Son iguales");
	}
}

}
