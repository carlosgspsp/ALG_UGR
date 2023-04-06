#include<iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int tiempoEnvioMin(int *tiempoEnvio, bool *visitados, int N)
{
    int nodo_min;
    int minimum = 999999;
   
    
    for(int i = 0; i < N; i++) 
    {
        if(tiempoEnvio[i] <= minimum && visitados[i] == false)      
        {
            minimum = tiempoEnvio[i];
            nodo_min = i;
            
        }
    }
    
    return nodo_min;
}

void redSensoresGreedy(int **L, int N, int nodo_inicial)
{
    bool *visitados = new bool[N];
    int *tiempoEnvio = new int[N];    
    vector<int> intermedios;
    intermedios.resize(N);                      
     
    for(int i = 0; i < N; i++)
    {
        tiempoEnvio[i] = 999999;
        visitados[i] = false;
        intermedios[i] = 1;
    }
    
    tiempoEnvio[nodo_inicial] = 0;            
    
    for(int j = 0; j < N; j++)                           
    {
        int min = tiempoEnvioMin(tiempoEnvio, visitados, N); 
        visitados[min] = true;

        for(int i = 0; i < N; i++)                  
        {
            if(tiempoEnvio[i] > tiempoEnvio[min] + L[min][i] && !visitados[i] && L[min][i] > 0)
            {
                tiempoEnvio[i] = tiempoEnvio[min] + L[min][i];
                intermedios[i] = min+1;
            }
        }
    }
    
    cout << "Sensor\t\t";
    cout << "Tiempo de envío" << "\t\t";
    cout << "Nodo anterior" << endl;

    for(int i = 0; i < N; i++)                      
        cout << i+1 << "\t\t\t" << tiempoEnvio[i] << "\t\t\t" << intermedios[i]<< endl;

    
}

int main()
{
    int N = 5;
    int** L = new int*[N];

    for(int i = 0; i < N; i++)
        L[i] = new int[N];


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            L[i][j] = 0;
        }
    }

    L[0][1] = 10;
    L[0][4] = 100;
    L[0][3] = 30;
    L[1][2] = 50;
    L[2][4] = 10;
    L[3][2] = 20;
    L[3][4] = 60;

    redSensoresGreedy(L, N, 0);

    return 0;                           
}