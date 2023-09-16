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
#include "lista.h"

using namespace std;


class cola {
    private:
        int frente;
        int fondo;
        pnodo Cola [5];

    public:
        cola(){
        frente = 0;//el primero que entro
        fondo = -1;// ultimo
        for(int i =0;i<5;i++){
            Cola[i]=new nodo("");
            }
        }
        pnodo getcola(int indice);
        bool ColaVacia(){return fondo < frente;}
        void insertar(nodo* v);
        void eliminar ();
        void imprimir();
        void insertarexpresion(int primero, string archivo);
        lista postfijo(nodo* primero);
        int getvalor(string elemento,bool inout);
    friend class pila;
};

