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

void CalculoCosteEj3(const vector<vector<int>> &L, vector<vector<int>> &P, int F, int C)
{

    P[F-1][0] = 0;

    for (int i = (F-2); i >= 0; i--)
    {
        P[i][0] = P[i+1][0] + L[i][0]; 
    }

    for (int j = 1; j < C; j++)
    {
        P[F-1][j] = P[F-1][j-1] + L[F-1][j]; 
    }

     for (int i = (F-2); i >= 0; i--)
    {
        for (int j = 1; j < C; j++)
        {          
           P[i][j] = min(min(P[i+1][j] + L[i][j], P[i][j-1] + L[i][j]), P[i+1][j-1] + L[i][j]);
        }
    }

}

void RecuperacionEj3 (stack<pair<int,int>> pila, vector<vector<int>> &P, int F, int C)
{

    int i = 0;
    int j = C-1;
    pair<int,int> aux;
    aux.first = i;
    aux.second = j;
    pila.push(aux);

    while(i != (F-1) || j != 0){
       if (i < (F-1) && j > 0){
           if (P[i+1][j] <= P[i][j-1] && P[i+1][j] <= P[i+1][j-1]){
               aux.first = i+1;
               aux.second = j;
           } else if (P[i][j-1] < P[i+1][j] && P[i][j-1] < P[i+1][j-1]){
               aux.first = i;
               aux.second = j-1;
           }else{
               aux.first = i+1;
               aux.second = j-1;
           }
       } else if(i < (F-1)){
           aux.first = i+1;
           aux.second = j;

       }else{
           aux.first = i;
           aux.second = j-1;
       }

        pila.push(aux);
        i = aux.first;
        j = aux.second;
    
   }

    /*while(i != F-1 && j != 0){

           
           if ( P[i+1][j] >= P[i][j-1])
           {
               if (P[i+1][j] >= P[i+1][j-1] ){
                   aux.first = i+1;
                   aux.second = j;
               }else{
                   aux.first = i+1;
                   aux.second = j-1;
               }
           } else if (P[i][j-1] >= P[i+1][j-1]){
               aux.first = i;
               aux.second = j-1;
           }
           else{
               aux.first = i+1;
               aux.second = j-1;
           }

            i = aux.first;
            j = aux.second;
           pila.push(aux);

    }*/

    /*if (i == F-1){
        while(j-1 != 0){
            aux.first = i;
            aux.second = j-1;
            pila.push(aux);
            j-=1;

        }
    }else if (j == 0){
        while(i+1 != F-1){
            aux.first = i+1;
            aux.second = j;
            pila.push(aux);
            i+=1;
        }

    }*/

    //aux.first =  F-1;
    //aux.second = 0;
    //pila.push(aux);

    while(!pila.empty()){
        pair<int,int> aux;
        aux = pila.top();
        cout << aux.first <<"  "<< aux.second << endl;
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
                matriz_distancias[i][j] = terreno2;
            }
            else if (i % 2 == 0 && j % 5 == 0){
                matriz_distancias[i][j] = rand() % 100 +1 ;
            }
            else {
                matriz_distancias[i][j] = terreno2;
            }
        }
    }*/
    const int terreno1 = 1;
    const int terreno2 = 5;
    const int terreno3 = 100;
    const int bases = 0;
    // 0-2  -- 2-7 -- 7-6
    matriz_distancias[0][0] = terreno2;
    matriz_distancias[0][1] = terreno2;
    matriz_distancias[0][2] = terreno2;
    matriz_distancias[0][3] = terreno2;
    matriz_distancias[0][4] = terreno2;
    matriz_distancias[0][5] = terreno2;
    matriz_distancias[0][6] = terreno2;
    matriz_distancias[0][7] = terreno2;
    matriz_distancias[0][8] = terreno2;
    matriz_distancias[0][9] = bases;

    matriz_distancias[1][0] = terreno2;
    matriz_distancias[1][1] = terreno2;
    matriz_distancias[1][2] = terreno1;
    matriz_distancias[1][3] = terreno2;
    matriz_distancias[1][4] = terreno2;
    matriz_distancias[1][5] = terreno2;
    matriz_distancias[1][6] = terreno2;
    matriz_distancias[1][7] = terreno2;
    matriz_distancias[1][8] = terreno2;
    matriz_distancias[1][9] = terreno2;

    matriz_distancias[2][0] = terreno2;
    matriz_distancias[2][1] = terreno2;
    matriz_distancias[2][2] = terreno2;
    matriz_distancias[2][3] = terreno2;
    matriz_distancias[2][4] = terreno2;
    matriz_distancias[2][5] = terreno2;
    matriz_distancias[2][6] = terreno2;
    matriz_distancias[2][7] = terreno2;
    matriz_distancias[2][8] = terreno2;
    matriz_distancias[2][9] = terreno2;

    matriz_distancias[3][0] = terreno2;
    matriz_distancias[3][1] = terreno2;
    matriz_distancias[3][2] = terreno2;
    matriz_distancias[3][3] = terreno2;
    matriz_distancias[3][4] = terreno2;
    matriz_distancias[3][5] = terreno2;
    matriz_distancias[3][6] = terreno2;
    matriz_distancias[3][7] = terreno2;
    matriz_distancias[3][8] = terreno2;
    matriz_distancias[3][9] = terreno2;

    matriz_distancias[4][0] = terreno2;
    matriz_distancias[4][1] = terreno2;
    matriz_distancias[4][2] = terreno2;
    matriz_distancias[4][3] = terreno2;
    matriz_distancias[4][4] = terreno2;
    matriz_distancias[4][5] = terreno3;
    matriz_distancias[4][6] = terreno3;
    matriz_distancias[4][7] = terreno2;
    matriz_distancias[4][8] = terreno2;
    matriz_distancias[4][9] = terreno2;

    matriz_distancias[5][0] = terreno3;
    matriz_distancias[5][1] = terreno2;
    matriz_distancias[5][2] = terreno2;
    matriz_distancias[5][3] = terreno2;
    matriz_distancias[5][4] = terreno2;
    matriz_distancias[5][5] = terreno2;
    matriz_distancias[5][6] = terreno3;
    matriz_distancias[5][7] = terreno2;
    matriz_distancias[5][8] = terreno2;
    matriz_distancias[5][9] = terreno2;

    matriz_distancias[6][0] = terreno2;
    matriz_distancias[6][1] = terreno2;
    matriz_distancias[6][2] = terreno2;
    matriz_distancias[6][3] = terreno2;
    matriz_distancias[6][4] = terreno2;
    matriz_distancias[6][5] = terreno2;
    matriz_distancias[6][6] = terreno2;
    matriz_distancias[6][7] = terreno2;
    matriz_distancias[6][8] = terreno2;
    matriz_distancias[6][9] = terreno2;

    matriz_distancias[7][0] = terreno2;
    matriz_distancias[7][1] = terreno2;
    matriz_distancias[7][2] = terreno2;
    matriz_distancias[7][3] = terreno2;
    matriz_distancias[7][4] = terreno2;
    matriz_distancias[7][5] = terreno2;
    matriz_distancias[7][6] = terreno2;
    matriz_distancias[7][7] = terreno2;
    matriz_distancias[7][8] = terreno2;
    matriz_distancias[7][9] = terreno2;

    matriz_distancias[8][0] = terreno2;
    matriz_distancias[8][1] = terreno2;;
    matriz_distancias[8][2] = terreno2;
    matriz_distancias[8][3] = terreno2;
    matriz_distancias[8][4] = terreno2;
    matriz_distancias[8][5] = terreno2;
    matriz_distancias[8][6] = terreno2;
    matriz_distancias[8][7] = terreno2;
    matriz_distancias[8][8] = terreno2;
    matriz_distancias[8][9] = terreno2;

    matriz_distancias[9][0] = bases;
    matriz_distancias[9][1] = terreno2;
    matriz_distancias[9][2] = terreno2;
    matriz_distancias[9][3] = terreno2;
    matriz_distancias[9][4] = terreno2;
    matriz_distancias[9][5] = terreno1;
    matriz_distancias[9][6] = terreno1;
    matriz_distancias[9][7] = terreno1;
    matriz_distancias[9][8] = terreno2;
    matriz_distancias[9][9] = terreno2;

    // int i = 0;
    // int j = 4;

    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
    unsigned long tejecucion;

    t0 = std::chrono::high_resolution_clock::now();

    CalculoCosteEj3(matriz_distancias, P, numero_filas, numero_columnas);
    

    for (int i = 0; i < numero_filas; i++)
    {

        for (int j = 0; j < numero_columnas; j++)
        {
            cout << P[i][j] << "\t";
        }
        cout << endl;
    }

    RecuperacionEj3(pila_solucion, P , numero_filas, numero_columnas);

    tf = std::chrono::high_resolution_clock::now();



    /*for (it=lista_solucion.begin(); it!=lista_solucion.end(); ++it) {
        cout <<  (*it).first << " " << (*it).second << endl;

    }*/

    tejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();

    cout << "Tiempo ejecucion -> " << tejecucion << endl;

    return 0;
}
