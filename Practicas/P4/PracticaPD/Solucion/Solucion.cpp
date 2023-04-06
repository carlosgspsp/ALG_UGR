#include "Solucion.h"

Solucion::Solucion() {
    N= 0;
    coste= 0;
}



Solucion::Solucion(int N) {

    this->N= N;
    ValorMonedas= new double [N];
    for (int i= 0; i<N; i++)
        ValorMonedas[i]= 0;
    coste= 0;
}


Solucion::Solucion(const Solucion & otro) {

    N= 0;
    *this= otro;
}

Solucion::~Solucion() {

    if (N>0)
        delete [] ValorMonedas;
}


Solucion & Solucion::operator=(const Solucion & otro) {

    if (this == &otro)
        return *this;

    if (N>0)
        delete [] ValorMonedas;

    coste= otro.coste;
    N= otro.N;
    if (N>0) {

        ValorMonedas= new double[N];
        for (int i= 0; i<N; i++)
            ValorMonedas[i]= otro.ValorMonedas[i];
    }


    return *this;
}

void Solucion::setValorMoneda(int idx, double v) {

    ValorMonedas[idx]= v;
}


int Solucion::getN() {

    return N;
}


double Solucion::getValorMoneda(int idx) {

    return ValorMonedas[idx];
}


double Solucion::getCoste() {

    return coste;
}


void Solucion::setN(int valor) {

    if (N > 0)
        delete[] ValorMonedas;

    N= valor;

    if (N>0) {
        ValorMonedas= new double[N];
        for (int i= 0; i<N; i++)
            ValorMonedas[i]= 0;
    }
}



Solucion & Solucion::operator+=(double v) {

    double *aux;

    aux= new double [N+1];
    for (int i= 0; i<N; i++)
        aux[i]= ValorMonedas[i];
    aux[N]= v;

    if (N>0)
        delete [] ValorMonedas;

    ValorMonedas= aux;
    N++;

    return *this;
}


