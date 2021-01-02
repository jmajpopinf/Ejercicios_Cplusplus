/*
ejercicio 1 colas: hacer un programa utilizando colas que contenga el siguiente menu;

1-Insertar un caracter a una cola
2-Mostrar todos los elementos de la cola
3-Salir
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;
};

void menu();
void insertarCola(Nodo *&, Nodo *&, char);
void suprimirCola(Nodo *&, Nodo *&, char &);
void mostarDatosCola(Nodo *);
bool cola_vacia(Nodo *);


int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	
	int opc;
	char dato;
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		cout<<"\t MENU DE OPCIONES. \n";
		cout<<"1-Insertar un caracter a la cola"<<endl;
		cout<<"2-Mostrar todos los elementos de la cola"<<endl;
		cout<<"3-Eliminar elementos de la cola"<<endl;
		cout<<"4-Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"ingrese un caracter para agregar a cola: ";
				cin>>dato;
				insertarCola(frente, fin, dato);
				break;
			case 2:
				cout<<"Mostrando los elementos de la cola:  ";
				mostarDatosCola(frente);
				system("pause");
				break;
			case 3:
				cout<<"Eliminando elementos de la cola: ";
				while(frente != NULL){
					suprimirCola(frente, fin, dato);
					if(frente != NULL){
						cout<<dato<<" , ";
					}
					else{
						cout<<dato<<" . ";
					}
				}
				system("pause");
				break;
			case 4:
				cout<<"Salir.";
				break;
		}
		system("cls");
	}while(opc != 4);
}

void insertarCola(Nodo *&frente, Nodo *&fin, char n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, char &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}

void mostarDatosCola(Nodo *frente){
	Nodo *actual = new Nodo();
	actual = frente;
	
	while(actual != NULL){
		cout<<actual->dato<<" -> ";
		actual = actual->siguiente;
	}
}

bool cola_vacia(Nodo *frente){
	return(frente == NULL)? true: false;
	
}

