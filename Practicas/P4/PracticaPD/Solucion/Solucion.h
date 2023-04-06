#ifndef SOLUCION_H
#define SOLUCION_H


class Solucion
{
    private:
        double *ValorMonedas; // Lista de valores de las monedas a devolver
        int N; // Tam. del vector valorMonedas
        double coste; // Suma de las componentes del vector ValorMonedas

    public:
        Solucion();
        Solucion(int N); // Da como param. el tam. de la solucion
        Solucion(const Solucion & otro);
        ~Solucion();
        Solucion & operator=(const Solucion & otro);

        void setValorMoneda(int idx, double v); // moneda ValorMonedas[idx]= v
        int getN();
        void setN(int valor);
        double getValorMoneda(int idx); // devuelve ValorMonedas[idx]
        double getCoste();

        Solucion & operator+=(double v);
};

#endif // SOLUCION_H
