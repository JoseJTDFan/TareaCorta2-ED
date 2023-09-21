/*
TAREA CORTA 2 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "lista.h"
#include "cola.h"
#include <cstdlib>
#include "nodo.h"

using namespace std;

int main(){
    /*
    Solo insertar el nombre de los archivos a usar en el array
    */
    string archivos[] = { "Arch1.txt", "Arch2.txt", "Arch3.txt", "Arch4.txt",  "Arch5.txt"}; //archivos a usar
    cola expresiones;// Crea la cola de nodos con referencia al primer elemento de la expresión de los archivos
    for (int i = 0; i < 5; i++){
    	system("cls");
	    expresiones.insertarexpresion(i,archivos[i]);//lector de archivos
	    cout<<endl<<"-------------------------------------------------------------------------"<<endl;
	    pnodo arbol = expresiones.ordenarArbol(expresiones.getcola(i));//crea el arbol
	    cout << endl << "PREFIJO:		";
	    expresiones.prefijo(arbol);
	    cout << endl << "INFIJO:			";
	    expresiones.infijo(arbol);
	    cout << endl << "POSTFIJO:		";
	    expresiones.postfijo(arbol);
	    try {
		    cout << endl << endl << "EVALUACION:		";
		    float result;
		    result = expresiones.evaluateExpression(arbol);
		    cout<<result;
		} catch (const runtime_error& e) {
        	cerr << e.what() << endl;
    	}
	    
	//    postFijo.evaluacion();//metodo para evaluar una lista postfijo
	    cout << endl << endl;
		system("pause");
		
    }
    return 0;
}
