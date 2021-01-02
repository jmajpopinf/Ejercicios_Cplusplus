#include<iostream>
#include<conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int); //prototipo de funcion
void sacarPila(Nodo *&, int &);	//prototipo de funcion

int main(){
	Nodo *pila = NULL;
	
	int dato;
	
	cout<<"\nDigite un numero 1: ";
	cin>>dato;
	agregarPila(pila, dato);
	
	cout<<"\nDigite un numero 2: ";
	cin>>dato;
	agregarPila(pila, dato);
	
	cout<<"\n Sacando los elementos de la pila: ";
	
	while(pila != NULL){
		sacarPila(pila, dato);
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<" . ";
		}
	}
	
	getch();
	return 0;
	
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();		//crear el espacio en memoria para almacenar nuevo nodo
	nuevo_nodo->dato = n;				//cargar el valor dentro de nodo(dato)
	nuevo_nodo->siguiente = pila;		//cargar el puntero pila dentro del nodo(siguiente)
	pila = nuevo_nodo;					//asignar el nuevo nodo a pila
	
	cout<<"\n Elemento  "<<n<<"  ha sido agregado a pila correctamente"<<endl;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila; 			//crara un nodo auxiliar igualandolo a pila
	n = aux->dato;				//igualamos n al puntero axuliar señalando a dato	
	pila = aux->siguiente;		//pasar pila al nodo siguiente asi poder eliminar
	delete aux;					//eliminar puntero auxiliar
}
