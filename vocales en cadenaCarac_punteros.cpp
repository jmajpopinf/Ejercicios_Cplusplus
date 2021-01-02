/*
Ejercicio video 90: pedir una cadena de caracteres (string) al usuario, 
e indicar cuantas veces aparece la vocal a, e, i, o, u, en la cadena de caracteres
*/

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void pedirDatos();
void contarVocales();

string cadenaC;


int main(){
	
	pedirDatos();
	contarVocales();
	
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite una cadena de caracteres: ";
	cin>>cadenaC;
	
	//strupr(cadenaC); //transformando minuscula a mayuscula
}

void contarVocales(){
	int contadorA=0, contadorE=0, contadorI=0, contadorO=0, contadorU=0;
	
	char *pCadena = new char[cadenaC.length()+1]; 	// Declaro puntero de tipo char...con la longitud de la cadena mas 1 que indica el caracter nulo
	strcpy(pCadena, cadenaC.c_str());				// Copio la cadena cadenaC en la direccion de memoria del puntero pCadena
	
	
	while(*pCadena){	//mientras pCadena no sea nulo '\0'
		switch(*pCadena){
			case 'a':
				contadorA++;
				break;
			case 'e':
				contadorE++;
				break;
			case 'i':
				contadorI++;
				break;
			case 'o':
				contadorO++;
				break;
			case 'u':
				contadorU++;
				break;
		}
		pCadena++;
	}
	cout<<"\n\nSe repite la vocal a: "<<contadorA<<" veces"<<endl;
	cout<<"Se repite la vocal e: "<<contadorE<<" veces"<<endl;
	cout<<"Se repite la vocal i: "<<contadorI<<" veces"<<endl;
	cout<<"Se repite la vocal o: "<<contadorO<<" veces"<<endl;
	cout<<"Se repite la vocal u: "<<contadorU<<" veces"<<endl;
}
