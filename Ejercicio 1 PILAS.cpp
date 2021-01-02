#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int); //prototipo de funcion
void sacarPila(Nodo *&, int &);	//prototipo de funcion
void mostrarElementosPila(Nodo *);

int main(){
	Nodo *pila = NULL;
	
	int dato, opcion;
	
	do{
		system("cls");
		
		cout<<"\n\n--MENU INGRESO DE DATOS EN PILA--"<<endl;
		cout<<"1-Insertar caracter a la pila"<<endl;
		cout<<"2-Sacar todos los elementos de la pila"<<endl;
		cout<<"3-mostrar elementos de la pila"<<endl;
		cout<<"4-Salir"<<endl;
		
		cout<<"\nIngrese opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nIngrese numero a ingresar a pila: ";
				cin>>dato;
				agregarPila(pila, dato);
				getch();
			break;
			case 2:
				cout<<"\nSacando los datos de la pila: ";
				while(pila != NULL){
					sacarPila(pila, dato);
					if(pila != NULL){
						cout<<dato<<" , ";
					}else{
						cout<<dato<<" . \n\n";
					}
				}
				getch();
			break;
			case 3:
				cout<<"\n\nMostrando elementos de la pila: ";
				mostrarElementosPila(pila);
				getch();
			break;	
		}
	}while(opcion != 4);
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();		//crear el espacio en memoria para almacenar nuevo nodo
	nuevo_nodo->dato = n;				//cargar el valor dentro de nodo(dato)
	nuevo_nodo->siguiente = pila;		//cargar el puntero pila dentro del nodo(siguiente)
	pila = nuevo_nodo;	
	
	cout<<"\n Elemento  "<<n<<"  ha sido agregado a pila correctamente"<<endl;
}


void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila; 			//crara un nodo auxiliar igualandolo a pila
	n = aux->dato;				//igualamos n al puntero axuliar señalando a dato	
	pila = aux->siguiente;		//pasar pila al nodo siguiente asi poder eliminar
	delete aux;					//eliminar puntero auxiliar
}

void mostrarElementosPila(Nodo *pila){
	Nodo *actual = new Nodo();
	actual = pila;
	
	while(actual != NULL){
		cout<<actual->dato<<" -> ";
		actual = actual->siguiente;
	}
}
