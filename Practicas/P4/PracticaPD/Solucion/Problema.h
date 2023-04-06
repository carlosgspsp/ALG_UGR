#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>
#include <iostream>
using namespace std;


class Problema
{
    private:
        int N; // No. de tipos de monedas que tenemos
        string ID; // Identificador del sistema monetario
        double *ValoresTipos; // Vector de tam. N con los valores de los diferentes tipos de moneda,
                                // tomando como referencia la moneda de menor valor
        int *CantidadTipo; // Vector de tam. N con la cantidad de monedas de cada tipo
                            // que tiene la máquina

        double CantidadDevolver; // La cantidad a devolver en el cambio

    public:
        Problema();
        Problema(const Problema & otro);
        ~Problema();
        Problema & operator=(const Problema &otro);

        void LeerFichero(const char *nombre); // Lee una instancia de problema
                                              // desde fichero

        double getValorTipo(int t) const; // Devuelve el valor de la moneda de tipo t
                                    //  (0<=t<N)
        int getN() const; // Devuelve el número de tipos distintos de monedas

        bool HayMonedasTipo(int t) const; // Devuelve true si quedan monedas de tipo t

        void QuitarMonedaTipo(int t); // Quita una moneda de tipo t de la máquina

        string getID() const; // Devuelve el ID del sistema monetario

        void Ordenar(); // Ordena el problema por valor de tipo de monedas

        double getCantidadDevolver() const; // Devuelve la cantidad a devolver
};

#endif // PROBLEMA_H
