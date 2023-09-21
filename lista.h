/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/

#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "nodo.h"
#include "pila.h"

using namespace std;

class lista {
    private:
        pnodo primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo
    public:
        //constructor
        lista(){primero=NULL;}
        //métodos
        ~lista();
        void InsertarFinal(string v);
        bool ListaVacia() { return primero == NULL; }
        void Mostrar();
        void evaluacion();
        int power(int num1, int num2);
};

lista::~lista() { //Destructor
    pnodo aux;
    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

void lista::Mostrar() {
    nodo *aux;
    if (primero== NULL)
        cout << "No hay elementos" << endl;
    else {
        aux = primero;
        while(aux) {
            cout << aux->valor;
            if(aux->siguiente)
                cout << " -> ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}



void lista::InsertarFinal(string v) {

    if (ListaVacia())
        primero = new nodo(v);
    else {
        pnodo aux = primero;
        while ( aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=new nodo(v);
    }
}
/*
void lista::evaluacion() {
    // metodo to_string: convierte datos primitivos INT a Strings
    // metodo stoi convierte strings a INT
    pnodo temp = primero;
    pila numeros;
    int num1;
    int num2;
    bool bandera=true;
    while (temp){
        if(isdigit(temp->valor[0])) {
            numeros.push(temp->valor);
        } else {
            num2 = stoi(numeros.pop());
            if(num2==0){
            	bandera=false;
            	break;
			}
            num1 = stoi(numeros.pop());
            switch (temp->valor[0]) {
                case '+':
                    numeros.push(to_string(num1 + num2));
                    break;
                case '-':
                    numeros.push(to_string(num1 - num2));
                    break;
                case '*':
                    numeros.push(to_string(num1 * num2));
                    break;
                case '/':
                    numeros.push(to_string(num1 / num2));
                    break;
                case '^':
                    numeros.push(to_string(power(num1,num2)));
                    break;
                default:
                    break;
            }
        }
        temp = temp->siguiente;
    }
    cout << "Resultado Final: ";
    if (bandera){
    	cout << numeros.pop() << endl;
	}
	else{
		cout<<"Error: division entre 0";
	}
    
}*/


