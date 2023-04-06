
#ifndef __PROBLEMA__
#define __PROBLEMA__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Fichero para implementar el problema del guión de laboratorio de Greedy

// Valor Infinito
#define INF 1e20

// Cadena nula
#define SINNOMBRE ""


class Problema {

private:
	double **pesos; // Coste de embaldosar cada calle
	string **nombresCalles; // Nombres de las calles
	string *nombresPlazas; // Nombres de las plazas
	int n; // Número de plazas

	void Inicializar() {

		n= 0;
		pesos= 0;
		nombresCalles= 0;
		nombresPlazas= 0;
	}

	void Liberar() {  // Libera la memoria e inicializa a NULL todo

		if (n> 0) {

			for (int i= 0; i<n; i++) {
				delete [] nombresCalles[i];
				delete [] pesos[i];
			}

			delete [] pesos;
			delete [] nombresCalles;
			delete [] nombresPlazas;
			Inicializar();
		}
	}

	void Reservar() { // Reserva nombresCalles, pesos, nombresPlazas suponiendo que n es válido. 

		// Vamos a reservar. Los nombres de todo se inicializarán a
		// SINNOMBRE y los pesos a INF
		if (n>0) {

			nombresPlazas= new string[n];
			nombresCalles= new string *[n];
			pesos= new double *[n];
			for (int i= 0; i<n; i++) {

				nombresPlazas[i]= SINNOMBRE;
				nombresCalles[i]= new string[n];
				pesos[i]= new double[n];

				for (int j= 0; j<n; j++) {
					nombresCalles[i][j]= SINNOMBRE;
					pesos[i][j]= INF;
				}
			}
		}
	}

public:
	Problema() { // Crear un problema vacío
		Inicializar();
	}


	Problema(const Problema &otro) {

		Inicializar();
		*this= otro;
	}

	Problema & operator=(const Problema &otro) {

		Liberar();

		n= otro.n;
		Reservar();
		for (int i= 0; i<n; i++)
			nombresPlazas[i]= otro.nombresPlazas[i];

		for (int i= 0; i<n; i++) {
			for (int j= 0; j<n; j++) {
				nombresCalles[i][j]= otro.nombresCalles[i][j];
				pesos[i][j]= otro.pesos[i][j];
			}
		}

		return *this;
	}

	~Problema() {
		Liberar();
	}


	void setNumPlazas(int otran) { // Reserva para "otran" plazas. Si ya estaba reservado, se pierde todo lo que había
		
		if (otran >= 0) {
			Liberar();

			n= otran;
			Reservar();
		}
	}

	int getNumPlazas() {
		return n;
	}



	void setNombrePlaza(int idx, string nombre) {
		
		if (idx >= 0 && idx < n)
			nombresPlazas[idx]= nombre;
	}



	string getNombrePlaza(int idx) {

		if (idx >= 0 && idx < n)
			return nombresPlazas[idx];
		return SINNOMBRE;
	}

	// Precondición: El coste debe ser > 0
	void setCalle(int pOrigen, int pDestino, string nombre, double coste) {

		if (pOrigen >= 0 && pDestino >= 0 && pOrigen < n && pDestino < n
			&& coste > 0) {

			pesos[ pOrigen ][ pDestino ]= coste;
			nombresCalles[ pOrigen ][ pDestino ]= nombre;
		}
	}

	double getCosteCalle(int pOrigen, int pDestino) {

		if (pOrigen >= 0 && pDestino >= 0 && pOrigen < n && pDestino < n)
			return pesos[ pOrigen ][ pDestino ];
		return INF;
	}

	string getNombreCalle(int pOrigen, int pDestino) {

		if (pOrigen >= 0 && pDestino >= 0 && pOrigen < n && pDestino < n)
			return nombresCalles[ pOrigen ][ pDestino ];
		return SINNOMBRE;
	}
	

	bool leerFichero(const char *nombrefich) {

		ifstream fich;
		int numPlazas;
		double numPeso;
		char nombres[1001];
		char c;

		fich.open(nombrefich);
		if (!fich)
			return false;

		fich >> numPlazas;
		fich.get(c);
		if (numPlazas <= 0) {

			fich.close();
			return false;
		}

		Liberar();
		n= numPlazas;
		Reservar();

		for (int i= 0; i<n; i++) { // Leemos las plazas
			fich.getline(nombres, 1000);
			if (!fich.eof())
				setNombrePlaza(i, nombres);
			else {

				Liberar();
				fich.close();
				return false;
			}
		}

		// Leemos las calles
		for (int i= 0; i<n; i++) {
			for (int j= 0; j<n; j++) {

				fich >> numPeso;
				if (fich.eof() && i!=n-1 && j!=n-1) {
					Liberar();
					fich.close();
					return false;
				}

				if (numPeso > -1) {

					fich.getline(nombres, 1000);
					setCalle(i, j, nombres, numPeso);
				}
			}
		}

		fich.close();
		return true;
	}
};


/*
int main() {

	Problema p;
	p.leerFichero("datos.dat");
	cout << "Hay " << p.getNumPlazas() << endl;
	for (int i= 0; i<p.getNumPlazas(); i++) 
		cout << "PLAZA " << p.getNombrePlaza(i)<<endl;

	for (int i= 0; i<p.getNumPlazas(); i++) 
		for (int j= 0; j<p.getNumPlazas(); j++) 
			cout << "CALLE " << p.getNombreCalle(i, j)<<p.getCosteCalle(i,j)<<endl;
}
*/

#endif










