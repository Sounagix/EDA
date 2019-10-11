// GRUPO VJ03
// Amaro Blest Polo
// Antonio Román Cerezo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(n)) donde 'n' es...
// *Es necesario calcular el coste de todas las funciones llamadas desde resolver()*
int resolver(int n) {
  return 2 * n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  int n;
  cin >> n;
  int doble = resolver(n);
  cout << doble << endl;
}

int main() { 
  int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) {
    resuelveCaso();
  }
  return 0;
}
