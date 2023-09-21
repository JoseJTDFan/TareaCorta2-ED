/*
TAREA CORTA 2 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 21/09/2023
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



