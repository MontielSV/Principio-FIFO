#include <iostream>
#include <stdexcept>

using namespace std;

// Nodo para la lista enlazada que soportará la cola dinámica
struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Implementación manual de una Cola FIFO desde cero
class ColaFIFO {
private:
    Nodo* frente; // Apunta al primer elemento (el próximo en salir)
    Nodo* final;  // Apunta al último elemento (el último en entrar)
    int tamano;

public:
    ColaFIFO() : frente(nullptr), final(nullptr), tamano(0) {}

    // Destructor para liberar memoria dinámica
    ~ColaFIFO() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    int obtenerTamano() const {
        return tamano;
    }

    // Operación Enqueue: inserta al final de la cola
    void encolar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (estaVacia()) {
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
        tamano++;
        cout << "[Enqueue] Se agrego el turno #" << valor << " al final de la cola." << endl;
    }

    // Operación Dequeue: elimina y retorna el elemento del frente
    int desencolar() {
        if (estaVacia()) {
            throw runtime_error("Error: La cola esta vacia, no se puede desencolar.");
        }
        Nodo* nodoTemp = frente;
        int valorFrente = frente->dato;
        
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr; // Si la cola quedó vacía, actualizamos el puntero final
        }

        delete nodoTemp;
        tamano--;
        return valorFrente;
    }

    // Operación Front / Peek: observa el primer elemento sin eliminarlo
    int verFrente() const {
        if (estaVacia()) {
            throw runtime_error("Error: La cola esta vacia.");
        }
        return frente->dato;
    }
};

int main() {
    ColaFIFO filaBanco;

    cout << "--- SIMULACION DE ATENCION BANCARIA (FIFO MANUAL) ---" << endl;
    filaBanco.encolar(101);
    filaBanco.encolar(102);
    filaBanco.encolar(103);

    cout << "\nSiguiente turno a atender (Front): #" << filaBanco.verFrente() << endl;
    cout << "Personas esperando: " << filaBanco.obtenerTamano() << "\n" << endl;

    while (!filaBanco.estaVacia()) {
        int turnoAtendido = filaBanco.desencolar();
        cout << "[Dequeue] Atendiendo al turno #" << turnoAtendido << endl;
    }

    return 0;
}
