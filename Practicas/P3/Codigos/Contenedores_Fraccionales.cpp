#include <iostream>
#include <fstream> 
#include <list>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

struct  Conjunto_Contenedor{
    int num_contenedores;
    int peso;
    float numcont_peso;
    bool operator < (Conjunto_Contenedor & obj1) {
        return (numcont_peso > obj1.numcont_peso);
    }
    friend ostream & operator<< (ostream & os, const Conjunto_Contenedor & o) {
        os << "Peso(toneladas) " << o.peso << '\t' << "Numero de contenedores: " << 	    o.num_contenedores    << '(' << o.numcont_peso << ')';
        return os;
    }
    Conjunto_Contenedor (int nc, int p) {
        num_contenedores = nc;
        peso = p;
        numcont_peso = (float)num_contenedores/peso;
    }
};

list<float> Barco (int lim_peso, list<Conjunto_Contenedor> & contenedores) {
    list<float> sol;
    int peso_actual = 0;
    list<Conjunto_Contenedor>::iterator rit;

    for (rit=contenedores.begin(); rit!=contenedores.end() && lim_peso > peso_actual; ++rit) {
        if ((peso_actual + (*rit).peso) <= lim_peso) {
            sol.push_back(1);
            peso_actual += (*rit).peso;
        }

        else {
            float num_c = (float)(lim_peso-peso_actual)/((*rit).peso);
            sol.push_back(num_c);
            peso_actual = lim_peso;
        }
    }

    while (rit != contenedores.end()){
        sol.push_back(0);
        ++rit;
    }

    return sol;
}

float CalculaNum_ContenedoresTotal (list<float> & m, list<Conjunto_Contenedor> & contenedores) {
    float num_c = 0;
    list<float>::iterator it_f;
    list<Conjunto_Contenedor>::iterator rit_o;
    for (it_f = m.begin(), rit_o = contenedores.begin(); it_f != m.end() && 
        rit_o != contenedores.end(); ++it_f, ++rit_o)
        num_c += (*it_f) * (*rit_o).num_contenedores; 

    return num_c;
}
float CalculaPesoTotal (list<float> & m, list<Conjunto_Contenedor> & contenedores) {
    float peso = 0;
    list<float>::iterator it_f;
    list<Conjunto_Contenedor>::iterator rit_o;
    for (it_f = m.begin(), rit_o = contenedores.begin(); it_f != m.end() && 
        rit_o != contenedores.end(); ++it_f, ++rit_o)
        peso += (*it_f) * (*rit_o).peso; 

    return peso;
}


int main (){
    int iteraciones, cantidad, peso_contenedor, pesobarco;
    int *cantidades;
    int *pesos;
    ifstream mi_fichero_entrada;
    mi_fichero_entrada.open("datosEntrada.txt");
	chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
	unsigned long tejecucion;
	
    if(mi_fichero_entrada.is_open()){
	
	mi_fichero_entrada >> iteraciones;
	cantidades = new int [iteraciones];
	pesos = new int [iteraciones];
	for(int i=0 ; i < iteraciones; i++){
	    mi_fichero_entrada >> cantidad;
	    mi_fichero_entrada >> peso_contenedor;
	    cantidades[i]=cantidad;
	    pesos[i]=peso_contenedor;
        }
	mi_fichero_entrada >> pesobarco;
    }
    
		t0= std::chrono::high_resolution_clock::now();
	
    list<Conjunto_Contenedor> candidatos;
    for (int i=0; i<iteraciones; i++) {
        int nc = cantidades[i]; 
	int p = pesos[i];
        Conjunto_Contenedor obj (nc, p);
        candidatos.push_back(obj);
    }

    

    
    candidatos.sort();

    // cout << "Los objetos de la mochila ordenados de mayor a menor son:" << endl;
    // list<Conjunto_Contenedor>::iterator rit;
    // for (rit=candidatos.begin(); rit!=candidatos.end(); ++rit)
    //     cout << (*rit).num_contenedores << " " << (*rit).peso << "\t";
    // cout << endl;

    list<float> m = Barco(pesobarco, candidatos);
    

		tf= std::chrono::high_resolution_clock::now();

    cout << "La proporcion de cada uno que cogemos es:" << endl;
    list<float>::iterator it; list<Conjunto_Contenedor>::iterator rit = candidatos.begin();
    for (it=m.begin(); it!=m.end(); ++it) {
        cout << *rit << " -> " <<  *it << endl;
        ++rit;
    }


    cout << "Numero de contenedores -> " <<
        CalculaNum_ContenedoresTotal(m, candidatos) << endl;
    cout << "Peso total -> " <<
        CalculaPesoTotal(m, candidatos) << endl;
	
	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
	
	cout << "Tiempo ejecucion -> " << tejecucion << endl;
	
    

    return 0;
}
