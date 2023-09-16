/*
TAREA CORTA 1 - ESTRUCTURAS DE DATOS
Prof: Ivannia Cerdas
Autores: Jose Julian Brenes Garro y Gustavo Pacheco Morales
Fecha de Entrega: 24/08/2023
*/

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class nodo{
    private:
        // atributos
        string valor;
        nodo *siguiente;
    public:
        //constructores
        nodo(string v) {
            valor = v;
            siguiente = NULL;
        }

        nodo(string v, nodo * signodo) {
            valor = v;
            siguiente = signodo;
        }

        //metodos

        void setvalor(string nuevo);
        void setsiguiente(nodo* nuevo);

        string getvalor();
        nodo* getsiguiente();

        //friends
        friend class cola;
        friend class pila;
        friend class lista;
};


void nodo::setvalor(string nuevo){//Setter de atributo valor
    valor = nuevo;
}

void nodo::setsiguiente(nodo* nuevo){//Setter de atributo siguiente
    siguiente = nuevo;
}

string nodo::getvalor(){//Getter de atributo valor
    return valor;
}

nodo* nodo::getsiguiente(){//Getter de atributo siguiente
    return siguiente;
}

typedef nodo* pnodo;//alias

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
};

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

int getvalor(string elemento,bool inout) {

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
    friend class pila;
};

pnodo cola::getcola(int indice){
    return Cola[indice];
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


int power(int num1, int num2){
    int result = num1;
    int i = 1;

    while(i<num2){
        result *= num1;
        i++;
    }
    return result;


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
