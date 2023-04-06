#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int ejercicio1FuerzaBruta(int i, int j);
int ejercicio1DyV(int i, int j);

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
		//int result = ejercicio1FuerzaBruta(10, n);
		int result = ejercicio1DyV(10, n);
		tf = std::chrono::high_resolution_clock::now();

		tejecucion = std::chrono::duration_cast<std::chrono::nanoseconds>(tf - t0).count();

		cerr << "Resultado de multiplicar: " << 10 << "x" << n << " = " << result << endl;
		// cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;

		fsalida << tejecucion << "\n";
		n += INTERVALO;
	}

	fsalida.close();

	return 0;
}

int ejercicio1FuerzaBruta(int i, int j)
{
	int result = 0;

	if (j == 1)
	{
		result = i;
	}
	else if (j > 1)
	{
		result = ejercicio1FuerzaBruta(i, j - 1) + i;
	}

	return result;
}

int ejercicio1DyV(int i, int j)
{
	int result_aux = 0;
	int result = 0;
	bool exacto = false;

	if (j == 1)
	{
		result = i;
	}
	else if (j > 1)
	{

		if (j % 2 == 0)
		{
			exacto = true;
		}

		result_aux = ejercicio1DyV(i, (j / 2) - 1) + i;
		if (exacto)
			result = result_aux + result_aux;
		else
			result = result_aux + result_aux + i;

	
	}

	return result;
}