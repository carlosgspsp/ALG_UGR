#include <Problema.h>
#include <Solucion.h>

Solucion Greedy(Problema p) {

	Solucion S;
	int ** C;
	int nC;
	int Cutilizados= 0;

	nC= 0;
	for (int i= 0; i<p.getNumPlazas(); i++) {
		for (int j= i+1; j<p.getNumPlazas(); j++) {
			if (p.getCosteCalle(i, j) != INF)
				nC++;
		}
	}
	C= new int * [2];
	C[0]= new int[nC];
	C[1]= new int[nC];

	int contador= 0;
	for (int i= 0; i<p.getNumPlazas(); i++) {
		for (int j= i+1; j<p.getNumPlazas(); j++) {
			if (p.getCosteCalle(i, j) != INF) {
				C[0][contador]= i;
				C[1][contador]= j;
				contador++;
			}
		}
	}

	for (int i= 0; i<nC; i++) {
		for (int j= i+1; j<nC; j++) {
			if (p.getCosteCalle( C[0][j], C[1][j]) <
					p.getCosteCalle( C[0][i], C[1][i])) {

				int aux= C[0][i];
				C[0][i]= C[0][j];
				C[0][j]= aux;
				aux= C[1][i];
				C[1][i]= C[1][j];
				C[1][j]= aux;
			}
		}
		
	}

	// Aquí ya tenemos la lista de candidatos C ordenada

	// Inicializando la solución a vacío
	S.setTam( p.getNumPlazas()-1 );
	while (!S.esSolucionFinal()) {

		int x= Cutilizados;
cout << "Cojo arista (";
cout << p.getNombrePlaza(C[0][x]) << ", ";
cout << p.getNombrePlaza(C[1][x])<<")"<<endl;
		S.insertarArista(C[0][x], C[1][x], 
										 p.getCosteCalle( C[0][x], C[1][x] ) 
										);
		Cutilizados++;
	}


	// Escribir el algoritmo greedy aquí

	delete [] C[0];
	delete [] C[1];
	delete [] C;
	return S;
}


int main() {
	Problema p;
	Solucion s;

	p.leerFichero("datos.dat");
	s= Greedy(p);

	cout << "Solucion: "<<endl;
	for (int i= 0; i<s.getTam(); i++) {

		int no, nd;
		s.getArista(i, no, nd);
		cout << "\t"<<p.getNombreCalle(no, nd)<<endl;
	}
	cout << endl<<"Coste: "<<s.getCoste() << endl;

	return 0;
}

