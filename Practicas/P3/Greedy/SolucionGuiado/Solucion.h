#ifndef __SOLUCION__
#define __SOLUCION__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Solucion {

private:
	int **v; // Aristas de la solución <v[0][0], v[1][0]>, <v[0][1], v[1][1]>, <v[0][2], v[1][2]>, ..., <v[0][n-1], v[1][n-1]>, 
	int tam; // Tamaño de las columnas de v
	int utiles; // Número de componentes utilizadas
	double coste; // Coste de la solución


	// Recorrido en profundidad sobre las aristas
	// MARCA: Vector de los nodos ya usados en el RP
	// USADAS: Vector de las aristas ya usadas en el RP
	// nodo: Nodo sobre el que se hace el RP
	bool rp(bool *MARCA, bool *USADAS, int nodo) {
		MARCA[nodo]= true;
		for (int i= 0; i<=utiles; i++) {
			if (!USADAS[i]) {
				USADAS[i]= true;
				if (v[0][i] == nodo) {

					if (MARCA[v[1][i]]) {
						return false;
					}
					if (!rp(MARCA, USADAS, v[1][i])) {
						return false;
					}

				} else if (v[1][i] == nodo) {

					if (MARCA[v[0][i]]) {
						return false;
					}
					if (!rp(MARCA, USADAS, v[0][i])) {
						return false;
					}
				}			
				USADAS[i]= false;
			}
		}
		MARCA[nodo]= false;
		return true;
	}

	bool Factible() {

		bool *MARCA= new bool[tam]; // Vector de nodos visitados
		bool *USADAS= new bool[tam]; // Vector de aristas de la solución usadas en el RP
		for (int i= 0; i<tam; i++) {
			MARCA[i]= false;
			USADAS[i]= false;
		}
		for (int i= 0; i<tam; i++) {
			if (!rp(MARCA, USADAS, i)) {
				delete [] MARCA;
				delete [] USADAS;
				return false;
			}
		}


		delete [] MARCA;
		delete [] USADAS;
		return true;
	}

public:
	Solucion() {
		v= 0;
		tam= 0;
		utiles= 0;
		coste= 0;
	}
	
	Solucion(const Solucion & otra) {
		v= 0;
		tam= 0;
		utiles= 0;
		coste= 0;
		*this= otra;
	}


	Solucion & operator=(const Solucion & otra) {

		if (this == &otra) return *this;
		if (v != 0) {

			delete [] v[0];
			delete [] v[1];
			delete [] v;
			v= 0;
			tam= 0;
			utiles= 0;
			coste= 0;
		}
		if (otra.v == 0)
			return *this;

		tam= otra.tam;
		utiles= otra.utiles;
		coste= otra.coste;
		v= new int *[2];
		v[0]= new int[tam];
		v[1]= new int[tam];
		for (int i= 0; i<utiles; i++) {
			v[0][i]= otra.v[0][i];
			v[1][i]= otra.v[1][i];
		}
		return *this;
	}


	~Solucion() {

		if (v != 0) {

			delete [] v[0];
			delete [] v[1];
			delete [] v;
		}
	}



	void setTam(int nuevotam) {

		if (v != 0) {

			delete [] v[0];
			delete [] v[1];
			delete [] v;
			v= 0;
			tam= 0;
			utiles= 0;
			coste= 0;
		}

		if (nuevotam <= 0)
			return;

		tam= nuevotam;
		v= new int *[2];
		v[0]= new int[tam];
		v[1]= new int[tam];
		utiles= 0;
		coste= 0;
	}


	int getTam() {

		return tam;
	}


	bool esSolucionFinal() {

		return utiles==tam && tam>0;
	}

	double getCoste() {

		return coste;
	}

	void getArista(int idxv, int &nodoOrigen, int &nodoDestino) {
		if (idxv < 0 || idxv>=utiles)
			return;

		nodoOrigen= v[0][idxv];
		nodoDestino= v[1][idxv];
	}


	bool insertarArista(int nodoOrigen, int nodoDestino, double costeArista) {

		if (utiles >= tam)
			return false;

		v[0][utiles]= nodoOrigen;
		v[1][utiles]= nodoDestino;
		if (!Factible())
			return false;

		utiles++;
		coste+= costeArista;
		return true;
}



};



#endif
