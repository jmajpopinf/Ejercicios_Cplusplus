#include <conio.h>
#include <iostream>

using namespace std;

int main(){
	int numeros[5], *Pnumeros, mayor, arreglo;
	
	for(int i = 0; i < 5; i++){
		cout<<"Escribir un numero[ "<<i<<"]: ";
		cin>>numeros[i];
	}
	
	Pnumeros = numeros; 	//posicion de memoria donde comienza el arreglo 
	
	//compara los valores que apunta el puntero con los elementos del arreglo
	
	for(int i = 1; i < 5; i++){
		arreglo = numeros[i];
		
		if(*Pnumeros > arreglo){
			mayor = *Pnumeros;	//mayor va a ser igual al valor del puntero
			numeros[i] = mayor;	//arreglo va a ser igual al puntero
		}
		else{
			mayor = arreglo; //mayor va a ser igual al valor de la matriz
		}
		Pnumeros++;
	}
	
	cout<<"\nEl numero  mayor es: "<<mayor<<endl;
	
	getch();
	return 0;	
}
