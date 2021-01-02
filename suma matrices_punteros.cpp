#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void pedirdatos();
void sumarMatrices(int **, int **, int, int);
void mostrarSumaMatriz(int **, int, int);

int **puntero_matriz1, **puntero_matriz2, nFilas, nCol;

int main(){
	
	pedirdatos();
	sumarMatrices(puntero_matriz1, puntero_matriz2, nFilas, nCol);
	mostrarSumaMatriz(puntero_matriz1, nFilas, nCol);
	
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
	
	cout<<"\nIngrese elementos de la primera matriz 1: \n";
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<<"Digite numero ["<<i<<"] ["<<j<<"]: ";
			cin>>*(*(puntero_matriz1+i)+j);
		}
	}
	
		//reservando memoria para la matriz 2
	puntero_matriz2 = new int *[nFilas];
	for(int i = 0; i < nFilas; i++){
		puntero_matriz2[i] = new int [nCol];
	}
	
	cout<<"\nIngrese elementos de la primera matriz 2: \n";
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<<"Digite numero ["<<i<<"] ["<<j<<"]: ";
			cin>>*(*(puntero_matriz2+i)+j);
		}
	}
	
}

void sumarMatrices(int **puntero_matriz1, int **puntero_matriz2, int nFilas, int nCol){
	
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			*(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
		}
	}
}

void mostrarSumaMatriz(int **puntero_matriz1, int nFilas, int nCol){
	cout<<"\nResultado de la suma de las matrices: \n";
	
	for(int i = 0; i < nFilas; i++){
		for(int j = 0; j < nCol; j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
	
}
