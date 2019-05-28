// EJERCICIO 1 HOJA 3
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> 

using namespace std;

bool validarFactorial(double n);
double factorial(int n);
void menu(int *opcion);
void senox(int *n, double *x);
void digit(int *n, string *num);

/* FUNCION MENU */
void menu(int *opcion) {
	cout << "MENU PRINCIPAL" << endl;
	cout << "[1] Calcular el seno" << endl;
	cout << "[2] Hallar el enesimo digito" << endl;
	cout << "[3] Fin" << endl;
	cout << "Opcion: ";
	cin >> *opcion;
}

/* FUNCION SENOX*/

/* Subfuncion Factorial*/
bool validarFactorial(double n) {
	return (n >= 1);
}

double factorial(int n) {
	int *resultado; //Paso 1
	resultado = new int;// Paso 2
	*resultado = 1;//Paso 3

	if (validarFactorial(n)) {
		for (int i = 1; i <= n; i++)
		{
			*resultado = *resultado * i; //Paso 3
		}
	}
	else {
		cout << "Por favor ingresar un numero valido " << endl;
	}

	return *resultado;
}

void senox(int *n, double *x) {

	double *sen;//Paso 1
	int *exp;//Paso 1

	sen = new double;//Paso 2
	exp = new int;//Paso 2

	*sen = 0;

	for (int i = 0; i <= *n; i++)
	{
		*exp = 2 * i + 1;
		*sen = *sen + pow(-1, i) * pow(*x, *exp)/factorial(*exp) ;
	}

	cout << "El seno de " << *x << " radianes es: " << *sen<<endl;

}

/* FUNCION DIGIT*/

void digit(int *n, string *num)
{
	cout << (*num).length()<<endl;
	cout << (*num).length() - *n << endl;
	cout << (*num).substr(((*num).length() - *n), 1);
	
	*n = stoi((*num).substr(((*num).length()-*n), 1));
	cout << "El n-esimo digito es: "<< *n << endl;
}


/* FUNCION MAIN*/
int main()
{
	int *n = new int;// Paso 1 y 2
	double *x = new double;// Paso 1 y 2
	string *num = new string;// Paso 1 y 2

	int *opcion = new int; //Paso 1 y 2

	do
	{
		menu(opcion); // Paso 3
		switch (*opcion) //Paso 3
		{
		case 1:
			cout << "Ingrese el numero de terminos: ";
			cin >> *n;	//Paso 3
			cout << "Ingrese el grado en radianes: ";
			cin >> *x;	//Paso 3

			senox(n, x);
			break;
		case 2:
			cout << "Ingrese el numero: " ;
			cin >> *num;//Paso 3

			cout << "Ingrese el valor de N: ";
			cin >> *n;	//Paso 3

			digit(n, num);
			break;
		case 3:
			break;
		default:
			break;
		}
		
	} while (*opcion != 4);

	delete opcion; //Paso 4
	delete n; //Paso 4
	delete x; //Paso 4
	delete num; //Paso 4

	system("pause");
    return 0;
}

