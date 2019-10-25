
// Amaro Blest Polo
// Antonio Román Cerezo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vector_int = vector<int>;


void imprime(const vector_int* v) {
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << " ";
	}
	cout << endl;
}

void merge(vector_int* v,int ini,int mid,int fin) {
	vector_int n(v->size());
	int i = ini, m = mid, contador = ini;
	// i es el Indice del lado izquierdo
	// m es el indice del lado derecho

	while (i < mid && m < fin)			//Elige el menor de los elementos de ambos lados y lo almacena en el vector auxiliar
	{
		if (v->at(i) < v->at(m)){		//Si el elemento del lado izquierdo es menor 
			n.at(contador) = v->at(i);
			contador++;
			i++;
		}else {							//Si el elemento del lado derecho es menor
			n.at(contador) = v->at(m);
			contador++;
			m++;
		}
	}
	while (i < mid){					//Almacena los elementos sobrantes del lado izquierdo
		n.at(contador) = v->at(i);
		contador++;
		i++;
	}
	while (m < fin){					//Almacena los elementos sobrantes del lado derecho
		n.at(contador) = v->at(m);
		contador++;
		m++;
	}
	for (i = ini; i < contador; i++){	//Copio el vector auxiliar en v
		v->at(i) = n.at(i);
	}
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(vector_int* v, int ini, int fin) {

	if ((fin - ini) > 1){//Divide el vector por completo
		int mid = ((ini + fin) / 2);
		resolver(v,ini,mid);
		resolver(v,mid,fin);
		merge(v,ini,mid,fin);
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int n;
	cin >> n;
	vector_int v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	resolver(&v, 0, v.size());
	imprime(&v);
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