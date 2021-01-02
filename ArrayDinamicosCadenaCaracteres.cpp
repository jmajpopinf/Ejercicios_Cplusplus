//ARRAY DINÁMICO DE CADENA DE CARACTERES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int LeerCadenas(char **pcad, unsigned nFilas);
void OrdenarCadenas(char **pcad, unsigned filas);
void VisualizarCadenas(char **pcad, unsigned filas);

int main(){
	char **pcad = NULL;
	unsigned int nFilas = 0;
	unsigned int Ok = 0, filas = 0, f = 0;
	
	do{
		printf("Numero de filas del array:  	");
		Ok = scanf("%u", &nFilas);
		fflush(stdin);
	}while(!Ok);
	
	//asignar memeoria para el array de punteros
	if((pcad = (char **)malloc(nFilas * sizeof(char *))) == NULL){
		printf("Insuficiente espacio de memoria\n");
		exit(-1);
	}
	
	//Operaciones
	filas = LeerCadenas(pcad, nFilas);
	OrdenarCadenas(pcad, filas);
	VisualizarCadenas(pcad, filas);
	
	//Liberar la memoria asignada a cada una de las filas
	for(f = 0; f < filas; f++){
		free(pcad[f]);
	}
	//Liberar la memoria asignada al array de punteros
	free(pcad);
	
	return 0;
}

unsigned int LeerCadenas(char **pcad, unsigned nFilas){
		unsigned int f = 0, longitud = 0;
		char cadena[81];
		
		printf("Introducir cadenas de caracteres.\n");
		printf("Para finalizar introduzca una cadena nula.\n");
		printf("Esto es, pulse solo <Enter>.\n\n");
		
	while((longitud = strlen(gets(cadena))) > 0 && f < nFilas){
			//asignar espaco para una cadena de caracteres
		if((pcad[f] = (char *)malloc(longitud + 1)) == NULL){
			printf("insuficiente espacio de memoria disponible\n");
			exit(-1);
		}
		//cipiar la cadena en el espacio de memoria asignado
		strcpy(pcad[f], cadena);
		f++;
	}
	return(f);
}
	
void OrdenarCadenas(char **pcad, unsigned filas){
	char *aux;		//puntero auxiliar
	unsigned int i = 0, s = 1;
		
	while((s == 1) && (--filas > 0)){
		s = 0;		//no permutacion
		for(i = 1; i <= filas; i++){
			if(strcmp(pcad[i-1], pcad[i]) > 0){
				aux = pcad[i-1];
				pcad[i-1] = pcad[i];
				pcad[i] = aux;
				s = 1;		//permutacion
			}
		}
	}
}
	
void VisualizarCadenas(char **pcad, unsigned filas){
	unsigned int f = 0;
	
	for(f = 0; f < filas; f++){
		printf("%s\n", pcad[f]);
	}
}
