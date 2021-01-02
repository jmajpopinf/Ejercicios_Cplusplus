/*
Defina una estructura que indique el tiempo empleado  por un ciclista en recorrer una etapa.
la estructura debe tener tres campo: horas, munutos y segundos.
escriba un programa que dado 3 etapas calcule el tiempo total empleado en correr todas las etapas.
*/

#include<iostream>
#include<conio.h>

using namespace std;

struct Etapa{
	int horas;
	int minutos;
	int segundos;
}etapa[3], *puntero_etapa = etapa;

void pedirDatos();
void sumarTiempo(Etapa *);

int main(){
	pedirDatos();
	sumarTiempo(puntero_etapa);
}

void pedirDatos(){
	for(int i = 0; i < 3; i++){
		cout<<"ingrese las horas: ";
		cin>>(puntero_etapa+i)-> horas;
		cout<<"ingrese los minutos: ";
		cin>>(puntero_etapa+i)-> minutos;
		cout<<"ingrese los segundos: ";
		cin>>(puntero_etapa+i)-> segundos;
		cout<<"\n";
	}
}

void sumarTiempo(Etapa *puntero_etapa){
	int sumaH = 0, sumaM = 0, sumaS = 0;
	
	for(int i = 0; i < 3; i++){
		sumaH += (puntero_etapa+i)->horas;
		sumaM += (puntero_etapa+i)->minutos;
		sumaS += (puntero_etapa+i)->segundos;
	}
	
	//imprimir la suma de los tiempos
	cout<<"El tiempo total acumulado en las etapas es: \n";
	cout<<sumaH<<" Horas, "<<sumaM<<" Segundos, "<<sumaS<<" Segundos en total.";
}
