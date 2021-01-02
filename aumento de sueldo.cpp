#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
float Sueldo, Total, Aumento;

	cout<<"\n\t***EJERCICIO 1 CONDICIONAL IF***\n\n";
	cout<<"\tEscriba el sueldo del trabajador\n\t";

	cin>>Sueldo;
	
	if (Sueldo<1000){
		Aumento=Sueldo*.15;
		Total=Sueldo+Aumento;
	}
	else{
		Aumento=Sueldo*.12;
		Total=Sueldo+Aumento;
	}
	cout<<"\n\tSu aumento es de: "<<Aumento<<" pesos\n";
	cout<<"\tEl sueldo con aumento es de: "<<Total<<" pesos\n\n\t";
	system("PAUSE");
	return 0;
}
