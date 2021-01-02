#include <conio.h>
#include <iostream>

using namespace std;

int main(){
	int numero, *Pnumero, divisores= 0;
	
	cout<<"\nIngrese un numero: "; 
	cin>>numero;

	Pnumero = &numero;		//Pnumero guarda la posición de la variable numero
	
	for(int i=1; i <=numero; i++){
		if(*Pnumero % i == 0){
			divisores++;	
		}
	}
	
	if(divisores == 2){
		cout<<"el numero: " <<*Pnumero <<" Es primo" <<endl; //el puntero con el asterisco * muestra lo que hay guardada en la posición de la variable que apunta
		cout<<"Posicion en memoria: " <<Pnumero <<endl;
	}
	else{
		cout<<"el numero: " <<*Pnumero <<" No es primo" <<endl;
		cout<<"Posicion en memoria: " <<Pnumero <<endl;		//el puntero sin el asterisco * munestra la posición en memoria de la variable a que apunta
	}
	
	getch();
	return 0;
	
}


