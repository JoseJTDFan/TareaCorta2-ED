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

using namespace std;

class pila {
    private:
        pnodo ultimo;
        pnodo primero;

    public:
        friend class cola;
        pila()
        {
        primero = NULL;
        ultimo = NULL;
        }
        bool pilaVacia(){return primero == NULL;}
        void push(string valor);     //insercion
        string pop();          //borrado
        string getultimo();      //oral
        void mostrarpila();
    };
