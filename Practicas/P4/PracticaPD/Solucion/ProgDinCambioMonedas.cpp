
#include "ProgDinCambioMonedas.h"
#include <climits>

#define INFINITO INT_MAX




Solucion AlgoritmoProgDinCambioMonedas(const Problema & p) {

    Solucion sol;
    int **T;

    T= new int *[ p.getN() ];
    for (int i= 0; i<p.getN(); i++)
        T[i]= new int [ (int)p.getCantidadDevolver()+1 ];

    // Caso base
    for (int i= 0; i<p.getN(); i++)
        T[i][0]= 0;

    // Suponiendo que el sistema monetario tiene monedas de unidad
    for (int j= 1; j<=p.getCantidadDevolver(); j++)
        T[0][j]= j;

    for (int i= 1; i<p.getN(); i++)
        for (int j=1; j<=p.getCantidadDevolver(); j++) {

            int aux;

            if ( j >= p.getValorTipo(i) ) {
                aux= 1+T[i][j-(int)p.getValorTipo(i)];
            } else
                aux= INFINITO;


            if (T[i-1][j] < aux) {

                T[i][j]= T[i-1][j];

            } else {

                T[i][j]= aux;
            }
        }

    // Calculamos la solución
    //sol.setN( T[ p.getN()-1 ][ (int)p.getCantidadDevolver() ] );
    sol.setN(0);

    double cambioActual= p.getCantidadDevolver();
    int fila= p.getN()-1, columna= (int)p.getCantidadDevolver();
    int MonedasInsertadas= 0;
    Problema paux(p);

    while (cambioActual > 0) {

        if ((fila > 0 && T[fila][columna] == T[fila-1][columna]) ||
            !paux.HayMonedasTipo(fila)) {

            fila--;

            if (fila < 0) {

                for (int i= 0; i<p.getN(); i++)
                    delete [] T[i];
                delete [] T;
                sol.setN(0);
                return sol;
            }

        } else {

            if (!paux.HayMonedasTipo(fila)) {

                for (int i= 0; i<p.getN(); i++)
                    delete [] T[i];
                delete [] T;
                sol.setN(0);
                return sol;
            }
            sol+= p.getValorTipo(fila);

            //sol.setValorMoneda(MonedasInsertadas, p.getValorTipo(fila));
            paux.QuitarMonedaTipo(fila);
            MonedasInsertadas++;
            cambioActual-= p.getValorTipo(fila);
            columna= (int)cambioActual;
        }
    }


    for (int i= 0; i<p.getN(); i++)
        delete [] T[i];
    delete [] T;

    return sol;
}
