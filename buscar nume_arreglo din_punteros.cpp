/*  
hacer una función para almacenar N números en un arreglo dinámico, posteriormente en otra funcion
buscar un numero en particular.
NOTA: puedes utilizar cualquier método de busqueda (Secuencial o binaria)
*/

// EJERCICIO REALIZADO POR EL TIPO DE BUSQUDA SECUENCIAL.

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//prototipos de funciones
void pedirDatos();
void buscarDato(int *, int);

int nElementos, *elemento;

int main(){
	pedirDatos();
	buscarDato(elemento, nElementos);
	
	
	delete[] elemento;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de elementos para el arreglo: ";
	cin >> nElementos;
	
	elemento = new int[nElementos];
	
	for(int i = 0; i < nElementos; i++){
		cout<<"Digite un numero ["<<i<<"]: ";
		cin>>*(elemento+i);
	}
}

void buscarDato(int *elemento, int nElementos){
	int i, bdato;
	char band = 'F';
	
	cout<<"\n\nIngrese numero a buscar: ";
	cin>>bdato;
	
	//BUSQUEDA SECUENCIAL
	i = 0;
	while((band == 'F') && (i < nElementos)){
		if(*(elemento+i) == bdato){
			band = 'V';
		}
		i++;
	}
	
	if (band == 'V'){
		cout<<"El numero a sido encontrado en la posicion: "<<i-1<<endl;
	}
	else if(band == 'F'){
		cout<<"El numero no a sido encontrado en el arreglo."<<endl;
	}
	
}
