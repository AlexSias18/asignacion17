
#include "stdafx.h"
#include <iostream>
using namespace std;

/*FUNCION FACTORIAL*/

bool validarFactorialPV(double n) {
	return (n >= 1);
}

/*1. Función de Paso parámetros por valor*/
void factorialParametroValor(int n) {
	double fact = 1;

	if (validarFactorialPV(n)) {
		for (int i = 1; i <= n; i++)
		{
			fact = fact * i;
		}
		cout << "[Paso de Parametro Valor] El factorial es: " << fact << endl;
	}
	else {
		cout << "Por favor ingresar un numero valido " << endl;
	}

}

/*2. Función de Paso parámetros por referencia*/

void factorialParametroReferencia(int &n) {
	int *resultado = new int; //Paso 1 y 2
	*resultado = 1; //Paso 3

	if (validarFactorialPV(n)) {
		for (int i = 1; i <= n; i++)
		{
			*resultado = *resultado * i; // Paso 3
		}

		cout << "[Paso de Parametro Referencia] El factorial es: " << *resultado << endl;
	}
	else {
		cout << "Por favor ingresar un numero valido " << endl;
	}
	delete resultado; //Paso 4
}

/*3. Función de Paso parámetros por referencia puntero*/
void factorialParametroReferenciaPuntero(int *n) {
	int *resultado; //Paso 1
	resultado = new int;// Paso 2
	*resultado = 1;//Paso 3

	if (validarFactorialPV(*n)) {
		for (int i = 1; i <= *n; i++)
		{
			*resultado = *resultado * i; //Paso 3
		}
		cout << "[Paso de Parametro Referencia Puntero] El factorial es: " << *resultado << endl;
	}
	else {
		cout << "Por favor ingresar un numero valido " << endl;
	}

	delete resultado; //Paso 4
}

/*FUNCION ROMBO*/
void romboParametroValor(int n) {

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}

	for (int j = n - 2; j >= 0; --j) {
		for (int i = 0; i < n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}
}

void romboParametroReferenciaPuntero(int *n) {

	for (int j = 0; j < *n; ++j) {
		for (int i = 0; i < *n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}

	for (int j = *n - 2; j >= 0; --j) {
		for (int i = 0; i < *n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}
}

void romboParametroReferencia(int &n) {

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}

	for (int j = n - 2; j >= 0; --j) {
		for (int i = 0; i < n - j - 1; ++i)
			cout << "  ";
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << i + 1 << " ";
		cout << endl;
	}
}

/*FUNCION MENU*/
void menu(int *opcion) {
	cout << "MENU PRINCIPAL" << endl;
	cout << "[1] Factorial" << endl;
	cout << "[2] Calcular e^a" << endl;
	cout << "[3] Imprime rombo" << endl;
	cout << "[4] Fin" << endl;
	cout << "Opcion: ";
	cin >> *opcion;
}

/*FUNCION MAIN*/
int main()
{
	int *n = new int;// Paso 1 y 2
	int *opcion = new int; //Paso 1 y 2

	do
	{
		menu(opcion); // Paso 3
		switch (*opcion) //Paso 3
		{
		case 1:

			cout << "Ingrese n: ";
			cin >> *n;	//Paso 3
			factorialParametroValor(*n); //Paso 3
			factorialParametroReferencia(*n);//Paso 3
			factorialParametroReferenciaPuntero(n);//Paso 3

			delete n; //Paso 4

			break;
		case 2:
			break;
		case 3:
			cout << " Ingrese un numero postivo menor a 11: ";
			cin >> *n;	//Paso 3

			romboParametroValor(*n); //Paso 3
			romboParametroReferencia(*n); //Paso 3
			romboParametroReferenciaPuntero(n); //Paso 3

			delete n; //Paso 4

			break;
		case 4:
			break;
		default:
			cout << "Por favor ingresar una alternativa correcta." << endl;
			break;
		}

	} while (*opcion != 4);

	delete opcion; //Paso 4

	system("pause");

	return 0;

}