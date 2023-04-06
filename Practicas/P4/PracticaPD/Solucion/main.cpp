#include <iostream>
#include "Problema.h"
#include "Solucion.h"
#include "ProgDinCambioMonedas.h"

using namespace std;

int main()
{
    Problema prob;
    Solucion sol;

    prob.LeerFichero("Problema.dat");

    sol= AlgoritmoProgDinCambioMonedas(prob);

    cout << "Cantidad de monedas: " << sol.getN() << endl;
    cout << "Las monedas son: ";
    for (int i= 0; i<sol.getN(); i++)
        cout << sol.getValorMoneda(i) << " ";
    cout << endl;

    return 0;
}
