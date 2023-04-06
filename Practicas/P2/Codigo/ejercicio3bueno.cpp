#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

int ejercicio3FuerzaBruta(int i);
int ejercicio3DyV(long int n, long int cini, long int cfin);

int main(int argc, char *argv[])
{

	const int NUM_REPETICIONES = 15;
	const int INTERVALO = 10000;
	int *v;
	int n;
	chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
	unsigned long tejecucion;
	unsigned long int semilla;
	ofstream fsalida;

	if (argc != 2)
	{
		cerr << "\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr << argv[0] << " NombreFicheroSalida\n\n";
		return 0;
	}

	fsalida.open(argv[1]);
	if (!fsalida.is_open())
	{
		cerr << "Error: No se pudo abrir fichero para escritura " << argv[1] << "\n\n";
		return 0;
	}

	n = INTERVALO;
	cerr << "Ejecutando Multiplicacion para tam. caso: " << n << endl;
	for (int i = 0; i <= NUM_REPETICIONES; i++)
	{

		t0 = std::chrono::high_resolution_clock::now();
		//long int result = ejercicio3FuerzaBruta(n);
		long int result = ejercicio3DyV(n, 0, n);
		tf = std::chrono::high_resolution_clock::now();

		tejecucion = std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();

		cerr << "Resultado para n = " << n << " : " << result << endl;
		cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;

		fsalida << tejecucion << "\n";
		n += INTERVALO;
	}

	fsalida.close();

	return 0;
}

int ejercicio3FuerzaBruta(int n)
{
	int result = -1;

	if (n == 0)
	{
		result = 0;
	}
	else
	{
		int x = 0;

		for (int i = 0; i <= n; i++)
		{
			x = i * (i + 1) * (i + 2);

			if (x == n)
				result = i;
		}
	}

	return result;
}

int ejercicio3DyV(long int n, long int cini, long int cfin)
{
	long int medio = (cini + cfin) / 2;

	if (cini > cfin)
	{
		return -1;
	}

	if (medio * (medio + 1) * (medio + 2) == n)
	{
		return medio;
	}
	else if (medio * (medio + 1) * (medio + 2) > n)
	{
		return ejercicio3DyV(n, cini, medio - 1);
	}
	else
	{
		return ejercicio3DyV(n, medio + 1, cfin);
	}
}
