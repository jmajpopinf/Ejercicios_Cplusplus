/*
V92. Realice un programa que lea una matriz dinámica NxM y cree su matriz traspuesta
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void pedirdatos();
void mostrarMatriz(int **, int, int);


int **puntero_matriz1, nFilas, nCol;

int main(){
	
	pedirdatos();
	mostrarMatriz(puntero_matriz1, nFilas, nCol);
	
	getch();
	return 0;
}

void pedirdatos(){
	cout<<"ingrese el numero de filas: ";
	cin>>nFilas;
	cout<<"ingrese el numero de columnas: ";
	cin>>nCol;
	
	//reservando memoria para la matriz 1
	puntero_matriz1 = new int *[nFilas];
	for(int i = 0; i < nFilas; i++){
		puntero_matriz1[i] = new int [nCol];
	}
	
	cout<<"\nIngrese elementos de la primera matriz: \n";
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<<"Digite numero ["<<i<<"] ["<<j<<"]: ";
			cin>>*(*(puntero_matriz1+i)+j);
		}
	}
	
}

void mostrarMatriz(int **puntero_matriz1, int nFilas, int nCol){
		cout<<"\nMostrando la matriz original: \n";
	
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<< *(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nMostrando la matriz traspuesta: \n";
	
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<< *(*(puntero_matriz1+j)+i)<<" ";//solo se cambia la posicion de i , j -> j , i
		}
		cout<<"\n";
	}
}


