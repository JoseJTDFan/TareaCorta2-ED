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
#include "lista.h"
#include <stdexcept>

using namespace std;


class cola {
    private:
        int frente;
        int fondo;
        int num_arch = 1;
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
        pnodo ordenarArbol(nodo* primero);
        int getvalor(string elemento,bool inout);
        void prefijo(pnodo raiz);
        void infijo(pnodo raiz);
        void postfijo(pnodo raiz);
        float evaluar(pnodo raiz);
        float power(float num1, float num2);
        void guardarEnArchivo(string nombreArchivo, string texto);
    friend class pila;
};

pnodo cola::getcola(int indice){
    return Cola[indice];
}

int cola::getvalor(string elemento,bool inout) {

    if (inout){
        if (elemento == "("){

            return 0;
        }
        else if(elemento == "+" || elemento == "-"){
            return 1;

        }else if(elemento == "*" || elemento == "/"){
            return 2;

        }else if(elemento == "^"){
            return 3;
        } else {
            return -1;
        }
    }
    else{
        if (elemento == "("){
            return 5;

        }else if(elemento == "+" || elemento == "-"){

            return 1;

        }else if(elemento == "*" || elemento == "/"){
            return 2;

        }else if(elemento == "^"){
            return 4;
        } else {
            return -1;
        }
    }
}

void cola:: insertar (nodo* v)
{
    if(fondo < 5-1){
        fondo++;
        Cola[fondo]= v;
    }
    else{
        cout<<"La cola esta llena";
    }
}

void cola:: eliminar ()
{
        if(!ColaVacia()){
            frente++;
        }
        else{
            cout<<"La cola esta vacia";
        }
}

void cola:: imprimir(){
    for(int i = frente;i<fondo+1;i++){
        cout<<Cola[i]<<"->"<<endl;
    }
}

void cola:: insertarexpresion(int indice, string archivo){//inserta expresiÃ³n en lista
    ifstream arch;
    string texto;

    arch.open(archivo,ios::in); //Abre el archivo en modo lectura

    if(arch.fail()){//Si el archivo no se puede abrir
        cout << "No se pudo abrir el archivo";
        exit(1);//cierra el programa
    }

    int lineas = 0;
    while(getline(arch,texto)){
        lineas++;
    }
    arch.close();//Cierra el archivo

    arch.open(archivo,ios::in); //Abre el archivo en modo lectura

    if(arch.fail()){//Si el archivo no se puede abrir
        cout << "No se pudo abrir el archivo";
        exit(1);//cierra el programa
    }
	cout << "LISTA ORIGINAL:	";
    bool primerocambia = true;
    while(getline(arch,texto)){//mientras el archivo no llegue al final
        if (Cola[indice] == NULL)
            Cola[indice] = new nodo(texto);
        else{
            pnodo aux = Cola[indice];
            if (primerocambia){
                Cola[indice] = new nodo(texto);
                primerocambia = false;
            }else{
                while ( aux->siguiente_Cola != NULL)
                    aux= aux->siguiente_Cola;
                aux->siguiente_Cola=new nodo(texto);
            }
        }
        
        cout << texto;
        cout << " ";
    }
    arch.close();
	cout << endl;

}

void cola::prefijo(pnodo raiz) {
    if (raiz) {
        cout << raiz->valor << " ";
        prefijo(raiz->hIzq);
        prefijo(raiz->hDer);
    }
}

void cola::infijo(pnodo raiz) {
    if (raiz) {
    	infijo(raiz->hIzq);
        cout << raiz->valor << " ";
        infijo(raiz->hDer);
    }
}

void cola::postfijo(pnodo raiz) {
    if (raiz) {
        postfijo(raiz->hIzq);
        postfijo(raiz->hDer);
        cout << raiz->valor << " ";
    }
}

void cola::guardarEnArchivo(string nombreArchivo, string texto){
	ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        //cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    archivo << texto;
    archivo.close();
}

pnodo cola:: ordenarArbol(nodo* primero){

    pila pilaoperadores;
    pila pilaexpresiones;
    pnodo aux = primero;
    string elemento;
    string comparacion = "";
    string nombre = "Archivo_" + to_string(num_arch) +  "_Evaluacion.txt";
    
    num_arch++;

    while(aux){
    	pnodo tempOperador, HDer, HIzq;
        if (isdigit(aux->valor[0])){
           pilaexpresiones.push(aux);
        }else{
        	if(aux->valor == ")"){
                pnodo temp = aux;
                while (temp->valor != "("){
                	
                    temp = pilaoperadores.pop();
                    if (temp->valor != "("){
                    	//comparacion += "Dentro: " + pilaoperadores.getultimo() + "Fuera: " + aux->valor + " \n";
						tempOperador = temp;
						HDer = pilaexpresiones.pop();
						HIzq = pilaexpresiones.pop();
						tempOperador->hDer = HDer;
						tempOperador->hIzq = HIzq;
						pilaexpresiones.push(tempOperador);
					}     
                }
            }
        	else if (pilaoperadores.pilaVacia()){
        		pilaoperadores.push(aux);
			}
			else if(getvalor(aux->valor,false) > getvalor(pilaoperadores.getultimo(),true)){
				comparacion += "Dentro: " + pilaoperadores.getultimo() + "Fuera: " + aux->valor + " \n";
				//cout << comparacion << endl;
				pilaoperadores.push(aux);
			}
			else if(getvalor(aux->valor,false) <= getvalor(pilaoperadores.getultimo(),true)){
				comparacion += "Dentro: " + pilaoperadores.getultimo() + "Fuera: " + aux->valor + " \n";
				//cout << comparacion << endl;
				tempOperador = pilaoperadores.pop();
				HDer = pilaexpresiones.pop();
				HIzq = pilaexpresiones.pop();
				tempOperador->hDer = HDer;
				tempOperador->hIzq = HIzq;
				pilaexpresiones.push(tempOperador);
				pilaoperadores.push(aux);

			}
        }
        
        if(aux->siguiente_Cola==NULL){
		 		while(!pilaoperadores.pilaVacia()){
		 			comparacion += "Dentro: " + pilaoperadores.getultimo() + "Fuera: " + aux->valor + " \n";
					//cout << comparacion << endl;
					tempOperador = pilaoperadores.pop();
					HDer = pilaexpresiones.pop();
					HIzq = pilaexpresiones.pop();
					tempOperador->hDer = HDer;
					tempOperador->hIzq = HIzq;
					pilaexpresiones.push(tempOperador);
				}
            }

        aux = aux->siguiente_Cola;
    }
    pnodo arbol = pilaexpresiones.pop();
    guardarEnArchivo(nombre,comparacion);

    return arbol;
}

float cola::power(float num1, float num2){
    float result = num1;
    int i = 1;

    while(i<num2){
        result *= num1;
        i++;
    }
    return result*1.0;


}


float cola::evaluar(pnodo raiz) {
    if (!raiz) {
        // Si el nodo es nulo, devuelve 0 (puede ser un caso base en la recursión).
        return 0;
    }

    // Si el nodo es un número, convierte su valor a entero y devuélvelo.
    if (raiz->valor == "+" || raiz->valor == "-" || raiz->valor == "*" || raiz->valor == "/" || raiz->valor == "^") {
<<<<<<< HEAD
        float hIzq = evaluar(raiz->hIzq);
        float hDer = evaluar(raiz->hDer);
=======
    	
        float hIzq = evaluateExpression(raiz->hIzq);
        float hDer = evaluateExpression(raiz->hDer);
>>>>>>> 8f3b72f69b92ad24b76c212d7263314d6e5af56e
        
        cout<<endl<<hIzq<<" "<<raiz->valor<<" "<<hDer<<endl;
        
        // Realiza la operación correspondiente según el operador en el nodo actual.
        if (raiz->valor == "+") {
            return hIzq + hDer;
        } else if (raiz->valor == "-") {
            return hIzq - hDer;
        } else if (raiz->valor == "*") {
            return hIzq * hDer;
        } else if (raiz->valor == "/") {
            if (hDer != 0) {
                return hIzq / hDer;
            } else {
			throw runtime_error("Error: Division por cero.");
            }
        } else if(raiz->valor == "^"){
        	return power(hIzq, hDer);
		}
    }

    return stoi(raiz->valor)*1.0; // Si el nodo es un número, convierte y devuelve su valor.
}
