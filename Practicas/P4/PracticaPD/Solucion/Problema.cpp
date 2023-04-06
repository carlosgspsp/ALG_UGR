#include "Problema.h"

#include <fstream>


Problema::Problema() {

    N= 0;
    ID= "";
    CantidadDevolver= 0;
}



Problema::Problema(const Problema & otro) {

    N= 0;
    *this= otro;
}



Problema::~Problema() {

    if (N>0) {

        delete [] CantidadTipo;
        delete [] ValoresTipos;
    }
}


Problema & Problema::operator=(const Problema &otro) {

    if (this == &otro)
        return *this;

    if (N>0) {

        delete [] CantidadTipo;
        delete [] ValoresTipos;
    }

    N= otro.N;
    ID= otro.ID;
    CantidadDevolver= otro.CantidadDevolver;

    if (N> 0) {

        ValoresTipos= new double [N];
        CantidadTipo= new int [N];

        for (int i= 0; i<N; i++) {

            ValoresTipos[i]= otro.ValoresTipos[i];
            CantidadTipo[i]= otro.CantidadTipo[i];
        }
    }

    return *this;
}


void Problema::LeerFichero(const char *nombre) {

    /* El firmato del fichero es:
        Linea 1: el ID del sistema monetario
        Linea 2: La cantidad a devolver
        Linea 3: Num. de tipos de monedas diferentes
        Restantes: X Y   (X=valor del tipo de moneda e Y la cantidad que hay en la máquina)

        Fichero de ejemplo: Problema.dat
    */

    ifstream fichero;

    fichero.open(nombre);
    if (!fichero)
        return;

    fichero >> ID;
    fichero >> CantidadDevolver;
    if (N>0) {

        delete [] CantidadTipo;
        delete [] ValoresTipos;
    }
    fichero >> N;
    CantidadTipo= new int [N];
    ValoresTipos= new double [N];

    for (int i= 0; i<N; i++)
        fichero >> ValoresTipos[i] >> CantidadTipo[i];

    fichero.close();

    Ordenar();

/*
    cout << "N= " << N << endl;
    cout << "ID= " << ID << endl;
    cout << "Devolver= " << CantidadDevolver << endl;
    for (int i= 0; i<N; i++)
        cout << ValoresTipos[i] << " -> " << CantidadTipo[i] << endl;
*/


}


double Problema::getValorTipo(int t) const {

    return ValoresTipos[t];
}

int Problema::getN() const {

    return N;
}

bool Problema::HayMonedasTipo(int t) const {

    return CantidadTipo[t] > 0;
}


void Problema::QuitarMonedaTipo(int t) {

    CantidadTipo[t]--;
}


string Problema::getID() const {

    return ID;
}


void Problema::Ordenar() {

    if (N <= 0)
        return;

    for (int i= 0; i<N-1; i++) {

        for (int j= i+1; j<N; j++) {

            if (ValoresTipos[j] < ValoresTipos[i]) {

                double auxd;
                int auxi;

                auxd= ValoresTipos[i];
                ValoresTipos[i]= ValoresTipos[j];
                ValoresTipos[j]= auxd;

                auxi= CantidadTipo[i];
                CantidadTipo[i]= CantidadTipo[j];
                CantidadTipo[j]= auxi;
            }
        }
    }
}


double Problema::getCantidadDevolver() const {

    return CantidadDevolver;
}
