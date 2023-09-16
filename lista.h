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

