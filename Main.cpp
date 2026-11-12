
#include <iostream>
using namespace std;

// Crear un nodo
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

// RECORRIDO PREORDEN
void preOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    cout << raiz->dato << " ";
    preOrden(raiz->izq);
    preOrden(raiz->der);
}

// RECORRIDO INORDEN
void inOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    inOrden(raiz->izq);
    cout << raiz->dato << " ";
    inOrden(raiz->der);
}

// RECORRIDO POSTORDEN
void postOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    postOrden(raiz->izq);
    postOrden(raiz->der);
    cout << raiz->dato << " ";
}

int main() {

    // Construir el árbol
    Nodo* raiz = crearNodo(1);

    raiz->izq = crearNodo(2);
    raiz->der = crearNodo(3);

    raiz->izq->izq = crearNodo(4);
    raiz->izq->der = crearNodo(5);

    raiz->der->izq = crearNodo(6);
    raiz->der->der = crearNodo(7);

    // Mostrar recorridos
    cout << "RECORRIDOS DEL ARBOL BINARIO" << endl;

    cout << "Preorden: ";
    preOrden(raiz);

    cout << "\nInorden: ";
    inOrden(raiz);

    cout << "\nPostorden: ";
    postOrden(raiz);

    return 0;
}
