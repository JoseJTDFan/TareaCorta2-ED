/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "lista.h"
#include "cola.h"

using namespace std;

int main(){
    /*
    Solo insertar el nombre de los archivos a usar en el array
    */
    string archivos[] = { "Arch1.txt", "Arch2.txt", "Arch3.txt", "Arch4.txt",  "Arch5.txt"}; //archivos a usar
    cola expresiones;// Crea la cola de nodos con referencia al primer elemento de la expresión de los archivos
    for (int i = 0; i < 5; i++)
    {
    expresiones.insertarexpresion(i,archivos[i]);//toma el primer nodo y crea la lista
    lista postFijo = expresiones.postfijo(expresiones.getcola(i));// metodo para crear lista postfijo a base de primer nodo de lista
    postFijo.evaluacion();//metodo para evaluar una lista postfijo
    cout << endl;
    }
    return 0;
}
