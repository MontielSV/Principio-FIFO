¿Qué es el principio FIFO?
FIFO significa First In, First Out, que en español se traduce como primero en entrar, primero en salir.
Es un principio que establece que el primer elemento que ingresa a una estructura de datos también debe ser el primero en salir.
Un ejemplo cotidiano es una fila de personas en un supermercado: la persona que llega primero es atendida primero.
  

Características principales
* Respeta el orden de llegada de los elementos.
* El primer elemento que entra es el primero que sale.
* Evita que los elementos más antiguos queden esperando detrás de los nuevos.
* Es el principio de funcionamiento de las colas.
Ejemplo práctico
Imaginemos que ingresan tres personas a una fila:
1. Primero ingresa Juan.
2. Después ingresa Pedro.
3. Finalmente ingresa María.
El orden de atención será:
Orden de entrada
1
Juan
2
Pedro
3
María
Orden de salida
1. Juan sale primero.
2. Pedro sale segundo.
3. María sale de última.
Se respeta el principio FIFO


Ejemplo en C++


#include <iostream>
#include <queue>
using namespace std;


int main() {


    queue<string> fila;


    fila.push("Juan");
    fila.push("Pedro");
    fila.push("Maria");


    while (!fila.empty()) {
        cout << "Atendiendo a: " << fila.front() << endl;
        fila.pop();
    }


    return 0;
}


Resultado:
Atendiendo a: Juan
Atendiendo a: Pedro
Atendiendo a: Maria


¿Dónde se utiliza FIFO?
* Filas de supermercados.
* Turnos médicos.
* Impresoras.
* Atención al cliente.
* Procesamiento de solicitudes en servidores.