// GRUPO VJXX
// NOMBRE COMPLETO ALUMNO_1
// NOMBRE COMPLETO ALUMNO_2

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
bool resuelveCaso() {
  int n;
  cin >> n;
  if (n == 0) return false;

  int doble = resolver(n);
  cout << doble << endl;
  return true;
}

int main() { 
  while (resuelveCaso());
  return 0;
}
