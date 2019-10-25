
// Amaro Blest Polo
// Antonio Román Cerezo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vector_int = vector<int>;


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector_int& v, int ini,int fin) {


	if (fin - ini == 2 && v[ini] > v[fin-1])//si ini y fin son adyacentes
	{
		swap(v[ini], v[fin - 1]);
	}
	else if(ini == fin)//si el vector vale 0
	{
		return v[ini];
	}
	else
	{
		int mid = ((ini + fin) / 2) + 1;
		resolver(v,ini,mid);
		resolver(v,mid,fin);
	}
   
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	vector_int v;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> v[i];
	cout << resolver(v, 0, v.size());
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
