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

using namespace std;

class nodo{
    private:
        // atributos
        string valor;
        nodo *siguiente;
        nodo * siguiente_Cola;
        nodo *hIzq;
        nodo *hDer;
    public:
        //constructores
        nodo(string v) {
            valor = v;
            siguiente = NULL;
            siguiente_Cola= NULL;
            hIzq = NULL;
            hDer = NULL;
        }

        nodo(string v, nodo * signodo) {
            valor = v;
            siguiente = signodo;
            siguiente_Cola= NULL;
            hIzq = NULL;
            hDer = NULL;
        }

        //metodos

        void setvalor(string nuevo);
        void setsiguiente(nodo* nuevo);

        string getvalor();
        nodo* getsiguiente();

        //friends
        friend class cola;
        friend class pila;
        friend class lista;
};


void nodo::setvalor(string nuevo){//Setter de atributo valor
    valor = nuevo;
}

void nodo::setsiguiente(nodo* nuevo){//Setter de atributo siguiente
    siguiente = nuevo;
}

string nodo::getvalor(){//Getter de atributo valor
    return valor;
}

nodo* nodo::getsiguiente(){//Getter de atributo siguiente
    return siguiente;
}

typedef nodo* pnodo;//alias
