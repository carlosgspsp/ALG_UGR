#include <iostream>
#include <fstream> 
#include <list>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;



void calculoCosteOptimoEj1 (const vector<vector<int>>  &L, vector<vector<int>>  &D, vector<vector<int>>  &P,  int N)
{
    
    for (int i = 0; i < N ; i++){
        for (int j = 0; j < N; j++){
            D[i][j] = L[i][j];
            P[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++){
        D[i][i] = 0;
    }

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (D[i][k]+D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
     }
    }

}


void RecuperacionEj1 (int i, int j, vector<vector<int>>  &P)
{
    
   int k = P[i][j];
    

   if (k != 0){
       
   
       RecuperacionEj1(i, k, P);
       cout << "La k es: " << k << endl;
       RecuperacionEj1(k, j, P);   
}


}





int main (){
   
 vector<vector<int>>  matriz_distancias;
 vector<vector<int>>  D;
 vector<vector<int>>  P;

int numero_nodos = 10 ;
 
 matriz_distancias.resize(numero_nodos);

    D.resize(numero_nodos);
    P.resize(numero_nodos);


 for (int i = 0; i < numero_nodos; i++)
 {
     matriz_distancias[i].resize(numero_nodos);
     D[i].resize(numero_nodos);
     P[i].resize(numero_nodos);
 }
 



/*for (int i = 0; i < numero_nodos; i++)
{
    
    for (int j  = 0; j < numero_nodos; j++)
    {
        if (i == j)
        {
            matriz_distancias[i][j] = no_hay_conexion;
        }
        else if (i % 2 == 0 && j % 5 == 0){
            matriz_distancias[i][j] = rand() % 100 +1 ;
        }
        else {
            matriz_distancias[i][j] = no_hay_conexion;
        }
    }
}*/
const int hay_conexion = 1;
const int no_hay_conexion = 9999;
                                                                    // 0-2  -- 2-7 -- 7-6
matriz_distancias[0][0] = no_hay_conexion;
matriz_distancias[0][1] = no_hay_conexion;
matriz_distancias[0][2] = no_hay_conexion;
matriz_distancias[0][3] = no_hay_conexion;
matriz_distancias[0][4] = no_hay_conexion;
matriz_distancias[0][5] = hay_conexion;
matriz_distancias[0][6] = no_hay_conexion;
matriz_distancias[0][7] = no_hay_conexion;
matriz_distancias[0][8] = no_hay_conexion;
matriz_distancias[0][9] = no_hay_conexion;

matriz_distancias[1][0] = no_hay_conexion;
matriz_distancias[1][1] = no_hay_conexion;
matriz_distancias[1][2] = hay_conexion;
matriz_distancias[1][3] = no_hay_conexion;
matriz_distancias[1][4] = hay_conexion;
matriz_distancias[1][5] = no_hay_conexion;
matriz_distancias[1][6] = no_hay_conexion;
matriz_distancias[1][7] = no_hay_conexion;
matriz_distancias[1][8] = no_hay_conexion;
matriz_distancias[1][9] = no_hay_conexion;

matriz_distancias[2][0] = no_hay_conexion;
matriz_distancias[2][1] = hay_conexion;
matriz_distancias[2][2] = no_hay_conexion;
matriz_distancias[2][3] = no_hay_conexion;
matriz_distancias[2][4] = no_hay_conexion;
matriz_distancias[2][5] = no_hay_conexion;
matriz_distancias[2][6] = no_hay_conexion;
matriz_distancias[2][7] = hay_conexion;
matriz_distancias[2][8] = no_hay_conexion;
matriz_distancias[2][9] = no_hay_conexion;

matriz_distancias[3][0] = no_hay_conexion;
matriz_distancias[3][1] = no_hay_conexion;
matriz_distancias[3][2] = no_hay_conexion;
matriz_distancias[3][3] = no_hay_conexion;
matriz_distancias[3][4] = hay_conexion;
matriz_distancias[3][5] = hay_conexion;
matriz_distancias[3][6] = no_hay_conexion;
matriz_distancias[3][7] = no_hay_conexion;
matriz_distancias[3][8] = no_hay_conexion;
matriz_distancias[3][9] = no_hay_conexion;

matriz_distancias[4][0] = no_hay_conexion;
matriz_distancias[4][1] = hay_conexion;
matriz_distancias[4][2] = no_hay_conexion;
matriz_distancias[4][3] = hay_conexion;
matriz_distancias[4][4] = no_hay_conexion;
matriz_distancias[4][5] = no_hay_conexion;
matriz_distancias[4][6] = no_hay_conexion;
matriz_distancias[4][7] = hay_conexion;
matriz_distancias[4][8] = no_hay_conexion;
matriz_distancias[4][9] = hay_conexion;

matriz_distancias[5][0] = hay_conexion;
matriz_distancias[5][1] = no_hay_conexion;
matriz_distancias[5][2] = no_hay_conexion;
matriz_distancias[5][3] = hay_conexion;
matriz_distancias[5][4] = no_hay_conexion;
matriz_distancias[5][5] = no_hay_conexion;
matriz_distancias[5][6] = no_hay_conexion;
matriz_distancias[5][7] = no_hay_conexion;
matriz_distancias[5][8] = no_hay_conexion;
matriz_distancias[5][9] = no_hay_conexion;

matriz_distancias[6][0] = no_hay_conexion;
matriz_distancias[6][1] = no_hay_conexion;
matriz_distancias[6][2] = no_hay_conexion;
matriz_distancias[6][3] = no_hay_conexion;
matriz_distancias[6][4] = no_hay_conexion;
matriz_distancias[6][5] = no_hay_conexion;
matriz_distancias[6][6] = no_hay_conexion;
matriz_distancias[6][7] = hay_conexion;
matriz_distancias[6][8] = no_hay_conexion;
matriz_distancias[6][9] = hay_conexion;

matriz_distancias[7][0] = no_hay_conexion;
matriz_distancias[7][1] = no_hay_conexion;
matriz_distancias[7][2] = hay_conexion;
matriz_distancias[7][3] = hay_conexion;
matriz_distancias[7][4] = hay_conexion;
matriz_distancias[7][5] = no_hay_conexion;
matriz_distancias[7][6] = hay_conexion;
matriz_distancias[7][7] = no_hay_conexion;
matriz_distancias[7][8] = no_hay_conexion;
matriz_distancias[7][9] = no_hay_conexion;

matriz_distancias[8][0] = no_hay_conexion;
matriz_distancias[8][1] = no_hay_conexion;
matriz_distancias[8][2] = no_hay_conexion;
matriz_distancias[8][3] = hay_conexion;
matriz_distancias[8][4] = no_hay_conexion;
matriz_distancias[8][5] = no_hay_conexion;
matriz_distancias[8][6] = no_hay_conexion;
matriz_distancias[8][7] = no_hay_conexion;
matriz_distancias[8][8] = no_hay_conexion;
matriz_distancias[8][9] = no_hay_conexion;

matriz_distancias[9][0] = no_hay_conexion;
matriz_distancias[9][1] = no_hay_conexion;
matriz_distancias[9][2] = no_hay_conexion;
matriz_distancias[9][3] = no_hay_conexion;
matriz_distancias[9][4] = hay_conexion;
matriz_distancias[9][5] = no_hay_conexion;
matriz_distancias[9][6] = hay_conexion;
matriz_distancias[9][7] = no_hay_conexion;
matriz_distancias[9][8] = no_hay_conexion;
matriz_distancias[9][9] = no_hay_conexion;


    //int i = 0;
    //int j = 4;
    
	chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
	unsigned long tejecucion;
	

    
    
		t0= std::chrono::high_resolution_clock::now();
	
    
        calculoCosteOptimoEj1(matriz_distancias, D, P, numero_nodos);

        for (int i = 0; i < numero_nodos; i++){
            
            for (int j = 0; j < numero_nodos; j++){
                cout << P[i][j] << "  ";
            }
            cout << endl;
        }

        RecuperacionEj1(0, 4, P);


		tf= std::chrono::high_resolution_clock::now();

  

    /*for (it=lista_solucion.begin(); it!=lista_solucion.end(); ++it) {
        cout <<  (*it).first << " " << (*it).second << endl;
        
    }*/


    
	
	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
	
	cout << "Tiempo ejecucion -> " << tejecucion << endl;
	
    

    return 0;
}
