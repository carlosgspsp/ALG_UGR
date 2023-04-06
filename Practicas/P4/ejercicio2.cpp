#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <stack>  
#include <utility> 
using namespace std;

void CalculoCosteEj2(const vector<vector<int>> &L, vector<vector<int>> &P, int F, int C)
{

    P[0][C-1] = 0;

    for(int i = 1;i < F; i++)
    {
        P[i][C-1] = P[i-1][C-1] + L[i][C-1];
    }

    for (int j = C-2; j >= 0; j--)
    {
        P[0][j] = P[0][j+1] + L[0][j];
    }

    for (int i = 1; i < F; i++)
    {
        for (int j = C-2; j >= 0; j--)
        {          
           P[i][j] = max(max(P[i-1][j] + L[i][j], P[i][j+1] + L[i][j]), P[i-1][j+1] + L[i][j]);
        }
    }
}

void RecuperacionEj2 (stack<pair<int,int>> pila, vector<vector<int>> &P, int F, int C)
{

    int i = F-1;
    int j = 0;
    pair<int,int> aux;
    aux.first = i;
    aux.second = j;
    pila.push(aux);

   while(i != 0 || j != (C-1)){
       if (i > 0 && j < (C-1)){
           if (P[i-1][j] >= P[i][j+1] && P[i-1][j] >= P[i-1][j+1]){
               aux.first = i-1;
               aux.second = j;
           } else if (P[i][j+1] > P[i-1][j] && P[i][j+1] > P[i-1][j+1]){
               aux.first = i;
               aux.second = j+1;
           }else{
               aux.first = i-1;
               aux.second = j+1;
           }
       } else if(i > 0){
           aux.first = i-1;
           aux.second = j;

       }else{
           aux.first = i;
           aux.second = j+1;
       }

        pila.push(aux);
        i = aux.first;
        j = aux.second;
    
   }

    /*while(i !=0 && j != C-1){

           
           if ( P[i-1][j] >= P[i][j+1])
           {
               if (P[i-1][j] >= P[i-1][j+1] ){
                   aux.first = i-1;
                   aux.second = j;
               }else{
                   aux.first = i-1;
                   aux.second = j+1;
               }
           } else if (P[i][j+1] >= P[i-1][j+1]){
               aux.first = i;
               aux.second = j+1;
           }
           else{
               aux.first = i-1;
               aux.second = j+1;
           }

            i = aux.first;
            j = aux.second;
           pila.push(aux);

    }

    if (i == 0){
        while(j+1 != C-1){
            aux.first = i;
            aux.second = j+1;
            pila.push(aux);
            j+=1;

        }
    }else if (j == C-1){
        while(i-1 != 0){
            aux.first = i-1;
            aux.second = j;
            pila.push(aux);
            i-=1;
        }

    }

    aux.first =  0;
    aux.second = C-1;
    pila.push(aux);*/

    while(!pila.empty()){
        pair<int,int> aux;
        aux = pila.top();
        cout << aux.first << "  " << aux.second << endl;
        pila.pop();
    }


}




int main()
{

    vector<vector<int>> matriz_distancias;
    vector<vector<int>> P;
    stack<pair<int,int>> pila_solucion;

    int numero_filas = 10;
    int numero_columnas = 10;

    matriz_distancias.resize(numero_filas);
    P.resize(numero_filas);

    for (int i = 0; i < numero_filas; i++)
    {
        matriz_distancias[i].resize(numero_columnas);
        P[i].resize(numero_columnas);
    }

    /*for (int i = 0; i < numero_nodos; i++)
    {

        for (int j  = 0; j < numero_nodos; j++)
        {
            if (i == j)
            {
                matriz_distancias[i][j] = no_hay_bolsa;
            }
            else if (i % 2 == 0 && j % 5 == 0){
                matriz_distancias[i][j] = rand() % 100 +1 ;
            }
            else {
                matriz_distancias[i][j] = no_hay_bolsa;
            }
        }
    }*/
    const int hay_bolsa = 1;
    const int no_hay_bolsa = 0;
    const int muro = -100;
    // 0-2  -- 2-7 -- 7-6
    matriz_distancias[0][0] = no_hay_bolsa;
    matriz_distancias[0][1] = no_hay_bolsa;
    matriz_distancias[0][2] = no_hay_bolsa;
    matriz_distancias[0][3] = no_hay_bolsa;
    matriz_distancias[0][4] = no_hay_bolsa;
    matriz_distancias[0][5] = no_hay_bolsa;
    matriz_distancias[0][6] = no_hay_bolsa;
    matriz_distancias[0][7] = no_hay_bolsa;
    matriz_distancias[0][8] = muro;
    matriz_distancias[0][9] = no_hay_bolsa;

    matriz_distancias[1][0] = no_hay_bolsa;
    matriz_distancias[1][1] = no_hay_bolsa;
    matriz_distancias[1][2] = no_hay_bolsa;
    matriz_distancias[1][3] = no_hay_bolsa;
    matriz_distancias[1][4] = no_hay_bolsa;
    matriz_distancias[1][5] = no_hay_bolsa;
    matriz_distancias[1][6] = no_hay_bolsa;
    matriz_distancias[1][7] = no_hay_bolsa;
    matriz_distancias[1][8] = no_hay_bolsa;
    matriz_distancias[1][9] = muro;

    matriz_distancias[2][0] = no_hay_bolsa;
    matriz_distancias[2][1] = no_hay_bolsa;
    matriz_distancias[2][2] = no_hay_bolsa;
    matriz_distancias[2][3] = no_hay_bolsa;
    matriz_distancias[2][4] = no_hay_bolsa;
    matriz_distancias[2][5] = no_hay_bolsa;
    matriz_distancias[2][6] = no_hay_bolsa;
    matriz_distancias[2][7] = no_hay_bolsa;
    matriz_distancias[2][8] = no_hay_bolsa;
    matriz_distancias[2][9] = no_hay_bolsa;

    matriz_distancias[3][0] = no_hay_bolsa;
    matriz_distancias[3][1] = no_hay_bolsa;
    matriz_distancias[3][2] = no_hay_bolsa;
    matriz_distancias[3][3] = no_hay_bolsa;
    matriz_distancias[3][4] = no_hay_bolsa;
    matriz_distancias[3][5] = no_hay_bolsa;
    matriz_distancias[3][6] = no_hay_bolsa;
    matriz_distancias[3][7] = no_hay_bolsa;
    matriz_distancias[3][8] = no_hay_bolsa;
    matriz_distancias[3][9] = no_hay_bolsa;

    matriz_distancias[4][0] = no_hay_bolsa;
    matriz_distancias[4][1] = no_hay_bolsa;
    matriz_distancias[4][2] = no_hay_bolsa;
    matriz_distancias[4][3] = no_hay_bolsa;
    matriz_distancias[4][4] = hay_bolsa;
    matriz_distancias[4][5] = no_hay_bolsa;
    matriz_distancias[4][6] = no_hay_bolsa;
    matriz_distancias[4][7] = no_hay_bolsa;
    matriz_distancias[4][8] = no_hay_bolsa;
    matriz_distancias[4][9] = no_hay_bolsa;

    matriz_distancias[5][0] = muro;
    matriz_distancias[5][1] = no_hay_bolsa;
    matriz_distancias[5][2] = no_hay_bolsa;
    matriz_distancias[5][3] = no_hay_bolsa;
    matriz_distancias[5][4] = hay_bolsa;
    matriz_distancias[5][5] = no_hay_bolsa;
    matriz_distancias[5][6] = muro;
    matriz_distancias[5][7] = no_hay_bolsa;
    matriz_distancias[5][8] = no_hay_bolsa;
    matriz_distancias[5][9] = no_hay_bolsa;

    matriz_distancias[6][0] = no_hay_bolsa;
    matriz_distancias[6][1] = no_hay_bolsa;
    matriz_distancias[6][2] = no_hay_bolsa;
    matriz_distancias[6][3] = no_hay_bolsa;
    matriz_distancias[6][4] = hay_bolsa;
    matriz_distancias[6][5] = no_hay_bolsa;
    matriz_distancias[6][6] = no_hay_bolsa;
    matriz_distancias[6][7] = no_hay_bolsa;
    matriz_distancias[6][8] = no_hay_bolsa;
    matriz_distancias[6][9] = no_hay_bolsa;

    matriz_distancias[7][0] = no_hay_bolsa;
    matriz_distancias[7][1] = no_hay_bolsa;
    matriz_distancias[7][2] = no_hay_bolsa;
    matriz_distancias[7][3] = no_hay_bolsa;
    matriz_distancias[7][4] = hay_bolsa;
    matriz_distancias[7][5] = no_hay_bolsa;
    matriz_distancias[7][6] = no_hay_bolsa;
    matriz_distancias[7][7] = no_hay_bolsa;
    matriz_distancias[7][8] = no_hay_bolsa;
    matriz_distancias[7][9] = no_hay_bolsa;

    matriz_distancias[8][0] = no_hay_bolsa;
    matriz_distancias[8][1] = no_hay_bolsa;;
    matriz_distancias[8][2] = no_hay_bolsa;
    matriz_distancias[8][3] = no_hay_bolsa;
    matriz_distancias[8][4] = hay_bolsa;
    matriz_distancias[8][5] = no_hay_bolsa;
    matriz_distancias[8][6] = no_hay_bolsa;
    matriz_distancias[8][7] = no_hay_bolsa;
    matriz_distancias[8][8] = no_hay_bolsa;
    matriz_distancias[8][9] = no_hay_bolsa;

    matriz_distancias[9][0] = no_hay_bolsa;
    matriz_distancias[9][1] = no_hay_bolsa;
    matriz_distancias[9][2] = hay_bolsa;
    matriz_distancias[9][3] = hay_bolsa;
    matriz_distancias[9][4] = hay_bolsa;
    matriz_distancias[9][5] = hay_bolsa;
    matriz_distancias[9][6] = hay_bolsa;
    matriz_distancias[9][7] = hay_bolsa;
    matriz_distancias[9][8] = hay_bolsa;
    matriz_distancias[9][9] = hay_bolsa;

    // int i = 0;
    // int j = 4;

    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
    unsigned long tejecucion;

    t0 = std::chrono::high_resolution_clock::now();

    CalculoCosteEj2(matriz_distancias, P, numero_filas, numero_columnas);
    

    for (int i = 0; i < numero_filas; i++)
    {

        for (int j = 0; j < numero_columnas; j++)
        {
            cout << P[i][j] << "\t";
        }
        cout << endl;
    }

    RecuperacionEj2(pila_solucion, P , numero_filas, numero_columnas);

    tf = std::chrono::high_resolution_clock::now();



    /*for (it=lista_solucion.begin(); it!=lista_solucion.end(); ++it) {
        cout <<  (*it).first << " " << (*it).second << endl;

    }*/

    tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

    cout << "Tiempo ejecucion -> " << tejecucion << endl;

    return 0;
}
