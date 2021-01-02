//Ordenar cadenas de caracteres

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 25		//n�mero m�ximo de cadenas
#define CMAX 81		//n�mero m�ximo de caracteres por cadena

int LeerCadena(char cad[][CMAX], char *pcad[], int nmc);
void Ordenar(char *pcad[], int nc);
void Visualizar(char *pcad[], int nc);

int main(){
	char cad[NMAX][CMAX];	//array de cadenas
	char *pcad[NMAX];		//array de punteros a las cadenas
	int ncads;				//n�mero de cadenas le�das
	
	printf("Ordenacion de cadenas de caracteres.\n");
	printf("Introduzca las cadenas a ordenar. Pulse <Enter> para salir.\n");
	
	if((ncads = LeerCadena(cad, pcad, NMAX)) > 0){
		printf("Proceso de ordenacion.\n\n");
		Ordenar(pcad, ncads);
		Visualizar(pcad, ncads);
	}
	else{
		printf("Cero o demasiadas cadenas para ordenar\n");
	}
	return 0;
}

//FUNCI�N LEER CADENAS

int LeerCadena(char cad[][CMAX], char *pcad[], int nmc){
	//nmc=n�mero m�ximo de cadenas que se pueden leer
	int longitud, ncads=0;
	
	while((longitud = strlen(gets(cad[ncads]))) > 0){
		if(ncads >= nmc){
			return (-1);	//demasiadas cadenas a ordenar
		}
		else{
			//guardar el apuntador a la cadena en el array
			pcad[ncads++] = cad[ncads];
		}
	}
	return (ncads); 	//n�mero de cadenas leidas
}

//FUNCI�N ORDENAR CADENAS

void Ordenar(char *pcad[], int nc){
	char *aux;		//puntero auxiliar
	int i, s = 1;
	
	while ((s == 1) && (--nc > 0)){
		s = 0;		// no permutacion
		for(i = 1; i <= nc; i++){
			if(strcmp(pcad[i-1], pcad[i]) > 0){
				aux = pcad[i-1];
				pcad[i-1] = pcad[i];
				pcad[i] = aux;
				s = 1;		//permutacion
			}
		}
	}
}

//FUNCI�N VISUALIZAR CADENAS

void Visualizar(char *pcad[], int nc){
	//nc = n�mero de cadenas a Visualizar
	while(--nc >= 0){
		printf("%s\n", *pcad++);
	}
}
