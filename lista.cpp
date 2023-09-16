/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/


#include "lista.h"

using namespace std;

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

void lista::evaluacion() {
    // metodo to_string: convierte datos primitivos INT a Strings
    // metodo stoi convierte strings a INT
    pnodo temp = primero;
    pila numeros;
    int num1;
    int num2;
    while (temp){
        if(isdigit(temp->valor[0])) {
            numeros.push(temp->valor);
        } else {
            num2 = stoi(numeros.pop());
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
    cout << "Resultado Final: " << numeros.pop() << endl;
}

int lista::power(int num1, int num2){
    int result = num1;
    int i = 1;

    while(i<num2){
        result *= num1;
        i++;
    }
    return result;


}
