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
        void push(pnodo valor);     //insercion
        pnodo pop();          //borrado
        string getultimo();      //oral
        void mostrarpila();
        string grabarpila();
    };
    
void pila::mostrarpila() {
    nodo *aux;
    if (primero == NULL)
        cout << "No hay elementos" << endl;
    else {
        aux = primero;
        while(aux) {
            cout << aux->valor;
            if(aux->siguiente)
                cout << " ->";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

string pila::grabarpila() {
    nodo *aux;
    string texto = "";
    if (primero == NULL)
        return "No hay elementos\n";
    else {
        aux = primero;
        while(aux) {
            texto = texto + aux->valor;
            if(aux->siguiente)
                texto = texto + " > ";
            aux = aux->siguiente;
        }
    }
    return texto + "\n";
}

void pila:: push (pnodo valor) {
    if (primero == NULL){
        primero = valor;
        ultimo = primero;
    }else{
        pnodo aux = primero;
        while(aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=valor;
        ultimo = aux->siguiente;
    }
}

pnodo pila:: pop() {
    if (primero != NULL){
        string result;
        pnodo aux = primero;
        if(primero == ultimo) {
            primero = NULL;
            ultimo = NULL;
//            result = aux->valor;
//            delete aux;
            return aux;
        }
        while (aux->siguiente != ultimo)
            aux = aux->siguiente;
        pnodo temp = aux->siguiente;
//        result = temp->valor;
        aux->siguiente= NULL;
        ultimo = aux;
//        delete temp;
        return temp;
    }else{
        return NULL;
    }
}

string pila::getultimo() {

    if (primero == NULL){
        return "";
    }
    else{
        if (primero->siguiente == NULL) {
            return primero->valor;
        }
        else {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;
            }
            return aux->siguiente->valor;
        }
    }
}
