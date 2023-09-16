/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/

#include "cola.h"

using namespace std;

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

void cola:: insertarexpresion(int indice, string archivo){//inserta expresión en lista
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
                while ( aux->siguiente != NULL)
                    aux= aux->siguiente;
                aux->siguiente=new nodo(texto);
            }
        }
    }
    arch.close();//Cierra el archivo

    pnodo aux2 = Cola[indice];
    cout << "Lista Original: ";
	while(aux2) {
        cout << aux2->valor;
        if(aux2->siguiente)
            cout << " -> ";
        aux2 = aux2->siguiente;
	}
	cout << endl;

}

lista cola:: postfijo(nodo* primero){

    pila pilaoperadores;
    lista listaexpresiones;
    pnodo aux = primero;
    string elemento;

    while(aux){
        elemento = aux->valor;
        if (isdigit(elemento[0])){
            listaexpresiones.InsertarFinal(elemento);
        }else{
            if(elemento == ")"){
                string temp = ")";
                while (temp != "("){
                    temp = pilaoperadores.pop();
                    if (temp != "(")
                        listaexpresiones.InsertarFinal(temp);
                }
            } else if(pilaoperadores.getultimo() == ""){
                pilaoperadores.push(elemento);
            } else if(getvalor(elemento,false) > getvalor(pilaoperadores.getultimo(),true)){
                pilaoperadores.push(elemento);
            } else {
                if(getvalor(elemento,false) != -1) {
                    listaexpresiones.InsertarFinal(pilaoperadores.pop());
                    pilaoperadores.push(elemento);
                }
            }
        }
        aux = aux->siguiente;
    }

    while(true){//inserta lo que queda
        string temp = pilaoperadores.pop();
        if(temp != ""){
            listaexpresiones.InsertarFinal(temp);
        }else{
            break;
        }
    }
    cout << "Lista PostFijo: ";
    listaexpresiones.Mostrar();
    return listaexpresiones;
}
