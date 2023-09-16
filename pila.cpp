/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/


#include "pila.h"

using namespace std;

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

void pila:: push (string valor) {
    if (primero == NULL){
        primero = new nodo(valor);
        ultimo = primero;
    }else{
        pnodo aux = primero;
        while(aux->siguiente != NULL)
            aux= aux->siguiente;
        aux->siguiente=new nodo(valor);
        ultimo = aux->siguiente;
    }
}

string pila:: pop() {
    if (primero != NULL){
        string result;
        pnodo aux = primero;
        if(primero == ultimo) {
            primero = NULL;
            ultimo = NULL;
            result = aux->valor;
            delete aux;
            return result;
        }
        while (aux->siguiente != ultimo)
            aux = aux->siguiente;
        pnodo temp = aux->siguiente;
        result = temp->valor;
        aux->siguiente= NULL;
        ultimo = aux;
        delete temp;
        return result;
    }else{
        return "";
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
