#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Nodo{
	int dato, fe;
	Nodo() {dato = 0; fe = 0;}
	Nodo *izquierda;
	Nodo *derecha;
	Nodo *padre;
};

void menu();

//------------funciones arbol ABB
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busquedaNodo(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *nodoMinimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);


//------------funciones arbol AVL
int obtenerFE(Nodo *);
int maxFE(Nodo *);
Nodo *rotacionIzquierda(Nodo *);
Nodo *rotacionDerecha(Nodo *);
Nodo *rotacionDobleIzquierda(Nodo *);
Nodo *rotacionDobleDerecha(Nodo *);



Nodo *arbol = NULL;

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int dato, opcion, contador = 0;
	
	do{
		cout<<"\t----MENU DE OPCIONES---"<<endl;
		cout<<"1-Insertar nuevo nodo"<<endl;
		cout<<"2-Mostar el arbol completo"<<endl;
		cout<<"3-Buscar dato en el arbol"<<endl;
		cout<<"4-Recorrer el arbol en preorden"<<endl;
		cout<<"5-Recorrer el arbol en inorden"<<endl;
		cout<<"6-Recorrer el arbol en postorden"<<endl;
		cout<<"7-Eliminar un nodo del arbol"<<endl;
		cout<<"8-Salir"<<endl;
		
		cout<<"Digite opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\n\nDigite un numero: ";
				cin>>dato;
				insertarNodo(arbol, dato, NULL);
				system("pause");
				break;
			case 2:
				cout<<"\n\nMostrando todos los elementos del arbol\n\n";
				mostrarArbol(arbol, contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
				
		}
		system("cls");
	}while(opcion != 8);
}

//----------------------------------------------------------------------------------
// funciones para ABB
//----------------------------------------------------------------------------------

Nodo *crearNodo(int num, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = num;
	nuevo_nodo->izquierda = NULL;
	nuevo_nodo->derecha = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int num, Nodo *padre){
	
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(num, padre);
		arbol = nuevo_nodo;
	}
	else{
		int nodoRaiz = arbol->dato;
		if(num < nodoRaiz){
			insertarNodo(arbol->izquierda,num, arbol);
			if((obtenerFE(arbol->izquierda) - obtenerFE(arbol->derecha) == 2)){
				int subArbolIz = arbol->izquierda->dato;
				if(num < subArbolIz){
					padre = rotacionIzquierda(arbol);
				}
				else{
					padre = rotacionDobleIzquierda(arbol);
				}
			}
		}
		else{
			insertarNodo(arbol->derecha,num, arbol);
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->derecha, cont+1);
		for(int i=0; i < cont; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izquierda, cont+1);
	}
}

bool busquedaNodo(Nodo *arbol, int numB){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == numB){
		return true;
	}
	else if(numB < arbol->dato){
		return busquedaNodo(arbol->izquierda, numB);
	}
	else{
		return busquedaNodo(arbol->derecha, numB);
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izquierda);
		preOrden(arbol->derecha);
	}
}

void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izquierda);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->derecha);
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izquierda);
		postOrden(arbol->derecha);
		cout<<arbol->dato<<" - ";
	}
}

void eliminar(Nodo *arbol, int numB){
	if(arbol == NULL){
		return;
	}
	else if(numB < arbol->dato){		//si el valor es menor
		eliminar(arbol->izquierda, numB);	//buscar por la izquierda
	}
	else if(numB > arbol->dato){		//si el valor es mayor
		eliminar(arbol->derecha, numB);	//buscar por la derecha
	}
	else{//si ya se encontro el valor
		eliminarNodo(arbol);
	}
}

Nodo *nodoMinimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	
	if(arbol->izquierda){ //si tiene hijo iz.
		return nodoMinimo(arbol->izquierda);	//buscamos en la parte mas izquierda posible
	}
	else{ // si no tienen hijo iz.
		return arbol; 	//retornamos el mismo nodo
	}
}

//funcion reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){	// si tiene padre
		//arbol->padre hay que asignarle su nuevo hijo.
		if(arbol->dato == arbol->padre->izquierda->dato){
			arbol->padre->izquierda = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->derecha->dato){
			arbol->padre->derecha = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

//funcion para destruir nodos
void destruirNodo(Nodo *nodo){
	nodo->izquierda = NULL;
	nodo->derecha = NULL;
	
	delete nodo;
}

//funcion para elimnar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izquierda && nodoEliminar->derecha){ //si el nodo tiene hijo iz y der.
		Nodo *nodo_menor = nodoMinimo(nodoEliminar->derecha);
		nodoEliminar->dato = nodo_menor->dato;
		eliminarNodo(nodo_menor);
	}
	else if(nodoEliminar->izquierda){	//si tiene hijo iz.
		reemplazar(nodoEliminar, nodoEliminar->izquierda);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->derecha){		//su tuebe hijo der.
		reemplazar(nodoEliminar, nodoEliminar->derecha);
		destruirNodo(nodoEliminar);
	}
	else{	//si no tiene hijos
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}






//----------------------------------------------------------------------------------
// funciones para AVL
//----------------------------------------------------------------------------------


int obtenerFE(Nodo *arbol){
	if(arbol == NULL){
		return -1;
	}else{
		return arbol->fe;
	}
}

//maximo factor equilibrio

int maxFE(Nodo *arbol){
	
	
	if((obtenerFE(arbol->izquierda->fe)) > (obtenerFE(arbol->derecha->fe))){
		return obtenerFE(arbol);
	}
	else{
		return obtenerFE(arbol->derecha->fe);
	}
}

//rotacion simple izquierda
Nodo *rotacionIzquierda(Nodo *arbol){
	Nodo *aux = arbol->izquierda;
	arbol->izquierda = aux->derecha;
	aux->derecha = arbol;
	arbol->fe = maxFE(arbol)+1;
	aux->fe = maxFE(arbol)+1;
	return aux;
}

//rotacion simple derecha
Nodo *rotacionDerecha(Nodo *arbol){
	Nodo *aux = arbol->derecha;
	arbol->derecha = aux->izquierda;
	aux->izquierda = arbol;
	arbol->fe = maxFE(arbol)+1;
	aux->fe = maxFE(arbol)+1;
	return aux;
}

//rotacion doble izquierda
Nodo *rotacionDobleIzquierda(Nodo *arbol){
	Nodo *aux = new Nodo();
	arbol->izquierda = rotacionDerecha(arbol->izquierda);
	aux = rotacionIzquierda(arbol);
	return aux;
	
}

//rotacion doble derecha
Nodo *rotacionDobleDerecha(Nodo *arbol){
	Nodo *aux = new Nodo();
	arbol->derecha = rotacionIzquierda(arbol->derecha);
	aux = rotacionDerecha(arbol);
	return aux;
}





