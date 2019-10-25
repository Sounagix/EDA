// GRUPO VJ03
// NOMBRE Amaro Blest Polo
// NOMBRE Antonio Román Cerezp

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vector_int = vector<int>;

//v[i] == i.
bool elemento_situado(const vector_int& v, int ini, int fin)
{
	if (fin - ini == 1)//sean adyacentes
	{
		return v[ini] == ini;
	}
	else if (fin == ini)
	{
		return false;
	}
	else //llamada recursiva
	{
		if (elemento_situado(v, ini, ((fin + ini) / 2)))
		{
			return true;
		}
		else
		{
			return elemento_situado(v, ((fin + ini) / 2), fin);
		}
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
	cout << (resolver(v) ? "SI" : "NO") << endl;
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

