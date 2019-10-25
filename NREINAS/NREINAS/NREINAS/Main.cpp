
// Amaro Blest Polo
// Antonio Román Cerezo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
using Tablero = vector<vector<int>>;
using Reinas = vector<int>;

bool esValido(Reinas& sol, int colum) {
	bool correcto = true;
	int fila = 0;
	while (fila < colum && correcto) {
		if ((sol[fila] == sol[colum]) || abs(sol[fila] - sol[colum]) == colum - fila)
		{
			return false;
		}
		++fila;
	}
	return correcto;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(Reinas& r,int colum) {
	int contador = 0;
	for (int fila = 0; fila < r.size(); fila++) {
		r.at(colum) =  fila;
		if (esValido(r,colum)) {
			if (colum == r.size() - 1) {
				contador++;
			}
			else
			{
				contador += resolver(r, colum + 1);
			}
		}
	}
	return contador;

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n;
	cin >> n;
	Reinas reinas(n);
	cout << resolver(reinas,0) << endl;
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