// GRUPO VJ03
// NOMBRE Amaro Blest Polo
// NOMBRE Antonio Román Cerezp

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <vector>
using namespace std;
using vector_int = vector<int>;

//v[i] == i.
bool elemento_situado(const vector_int& v, int ini, int fin) 
{
	if (fin - ini == 1)//sean adyacentes
	{
		return v[ini] == i;
	}
	else //llamada recursiva
	{
		bool izq,der = false;
		int mid = (fin + ini) / 2;//pivote del vector
		izq = elemento_situado(v,ini,mid);
		der = elemento_situado(v,mid,fin);
		return izq || der;
	}
}

// función que resuelve el problema
// comentario sobre el coste, O(f(n)) donde 'n' es...
// *Es necesario calcular el coste de todas las funciones llamadas desde resolver()*
bool resolver(const vector_int& v) {
  return elemento_situado(v, 0, v.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  int n;
  cin >> n;
  vector_int v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  cout << (resolver(v) ? "YES" : "NO") << endl;
}

int main() { 
  int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) {
    resuelveCaso();
  }
  return 0;
}
