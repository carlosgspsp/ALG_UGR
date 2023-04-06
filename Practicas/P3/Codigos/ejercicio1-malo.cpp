#include <iostream>
#include <fstream> 
#include <list>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;


typedef pair<int, int> arista;

void Prim (const vector<vector<int>>  &L , list<arista> & T, vector<int> vertices_candidatos, int S,vector<int> &P, vector<float> &D )
{
    int n = L.size();
    vector<float> D;
    D.resize(n);
    
    vector<int> P;
    P.resize(n);
    
    for (int i = 1 < n; i++)
    {
        
       D[i] = L[S][i];
       P[i] = S: 

    }

    for (int i = 0; i < n-2; i++)
    {
        int min = 9999999999;
        auto it = vertices_candidatos.begin();
        int v;
        for (int j = 0; j < vertices_candidatos.size(); j++){
            if (D[j] < min){
            min = D[j];    
            v = vertices_candidatos[j];
            vertices_candidatos.erase(it);
            }
            ++it;

        }

        for (int j = 0; j < vertices_candidatos; j++)
        {
            if (D[j] > D[v]+L[v][j])
            {
                D[j] = D[v]+L[v][j];
                P[j] = v
            }
        }

    }

   
}



int main (){
   
 vector<vector<int>>  matriz_distancias;

int numero_nodos = 10 ;
 matriz_distancias.resize(numero_nodos);
 for (int i = 0; i< matriz_distancias.size(); i++)
 {
     matriz_distancias[i].resize(numero_nodos);
 }
 
 list<arista> lista_solucion;
 vector<int> vertices_candidatos

 vector<float> D;
    D.resize(matriz_distancias.size());
    
    vector<int> P;
    P.resize(matriz_distancias.size());

 vertices_candidatos.push_back(0);
 vertices_candidatos.push_back(1);
 vertices_candidatos.push_back(2);
 vertices_candidatos.push_back(3);
 vertices_candidatos.push_back(4);
 vertices_candidatos.push_back(5);
 vertices_candidatos.push_back(6);
 vertices_candidatos.push_back(7);
 vertices_candidatos.push_back(8);
 vertices_candidatos.push_back(9);


/*for (int i = 0; i < numero_nodos; i++)
{
    
    for (int j  = 0; j < numero_nodos; j++)
    {
        if (i == j)
        {
            matriz_distancias[i][j] = numero_invalido;
        }
        else if (i % 2 == 0 && j % 5 == 0){
            matriz_distancias[i][j] = rand() % 100 +1 ;
        }
        else {
            matriz_distancias[i][j] = numero_invalido;
        }
    }
}*/
int numero_invalido = -1;

matriz_distancias[0][0] = numero_invalido;
matriz_distancias[0][1] = numero_invalido;
matriz_distancias[0][2] = 8;
matriz_distancias[0][3] = 4;
matriz_distancias[0][4] = numero_invalido;
matriz_distancias[0][5] = 9;
matriz_distancias[0][6] = numero_invalido;
matriz_distancias[0][7] = numero_invalido;
matriz_distancias[0][8] = numero_invalido;
matriz_distancias[0][9] = numero_invalido;

matriz_distancias[1][0] = numero_invalido;
matriz_distancias[1][1] = numero_invalido;
matriz_distancias[1][2] = 3;
matriz_distancias[1][3] = numero_invalido;
matriz_distancias[1][4] = 4;
matriz_distancias[1][5] = numero_invalido;
matriz_distancias[1][6] = numero_invalido;
matriz_distancias[1][7] = numero_invalido;
matriz_distancias[1][8] = numero_invalido;
matriz_distancias[1][9] = numero_invalido;

matriz_distancias[2][0] = 8;
matriz_distancias[2][1] = 3;
matriz_distancias[2][2] = numero_invalido;
matriz_distancias[2][3] = 4;
matriz_distancias[2][4] = numero_invalido;
matriz_distancias[2][5] = numero_invalido;
matriz_distancias[2][6] = numero_invalido;
matriz_distancias[2][7] = 9;
matriz_distancias[2][8] = numero_invalido;
matriz_distancias[2][9] = numero_invalido;

matriz_distancias[3][0] = 4;
matriz_distancias[3][1] = numero_invalido;
matriz_distancias[3][2] = 4;
matriz_distancias[3][3] = numero_invalido;
matriz_distancias[3][4] = 5;
matriz_distancias[3][5] = 8;
matriz_distancias[3][6] = numero_invalido;
matriz_distancias[3][7] = 3;
matriz_distancias[3][8] = 7;
matriz_distancias[3][9] = numero_invalido;

matriz_distancias[4][0] = numero_invalido;
matriz_distancias[4][1] = 4;
matriz_distancias[4][2] = numero_invalido;
matriz_distancias[4][3] = 5;
matriz_distancias[4][4] = numero_invalido;
matriz_distancias[4][5] = numero_invalido;
matriz_distancias[4][6] = numero_invalido;
matriz_distancias[4][7] = 2;
matriz_distancias[4][8] = numero_invalido;
matriz_distancias[4][9] = 1;

matriz_distancias[5][0] = 9;
matriz_distancias[5][1] = numero_invalido;
matriz_distancias[5][2] = numero_invalido;
matriz_distancias[5][3] = 8;
matriz_distancias[5][4] = numero_invalido;
matriz_distancias[5][5] = numero_invalido;
matriz_distancias[5][6] = numero_invalido;
matriz_distancias[5][7] = numero_invalido;
matriz_distancias[5][8] = numero_invalido;
matriz_distancias[5][9] = numero_invalido;

matriz_distancias[6][0] = numero_invalido;
matriz_distancias[6][1] = numero_invalido;
matriz_distancias[6][2] = numero_invalido;
matriz_distancias[6][3] = numero_invalido;
matriz_distancias[6][4] = numero_invalido;
matriz_distancias[6][5] = numero_invalido;
matriz_distancias[6][6] = numero_invalido;
matriz_distancias[6][7] = 7;
matriz_distancias[6][8] = numero_invalido;
matriz_distancias[6][9] = 8;

matriz_distancias[7][0] = numero_invalido;
matriz_distancias[7][1] = numero_invalido;
matriz_distancias[7][2] = 9;
matriz_distancias[7][3] = 3;
matriz_distancias[7][4] = 2;
matriz_distancias[7][5] = numero_invalido;
matriz_distancias[7][6] = 7;
matriz_distancias[7][7] = numero_invalido;
matriz_distancias[7][8] = numero_invalido;
matriz_distancias[7][9] = numero_invalido;

matriz_distancias[8][0] = numero_invalido;
matriz_distancias[8][1] = numero_invalido;
matriz_distancias[8][2] = numero_invalido;
matriz_distancias[8][3] = 7;
matriz_distancias[8][4] = numero_invalido;
matriz_distancias[8][5] = numero_invalido;
matriz_distancias[8][6] = numero_invalido;
matriz_distancias[8][7] = numero_invalido;
matriz_distancias[8][8] = numero_invalido;
matriz_distancias[8][9] = numero_invalido;

matriz_distancias[9][0] = numero_invalido;
matriz_distancias[9][1] = numero_invalido;
matriz_distancias[9][2] = numero_invalido;
matriz_distancias[9][3] = numero_invalido;
matriz_distancias[9][4] = 1;
matriz_distancias[9][5] = numero_invalido;
matriz_distancias[9][6] = 8;
matriz_distancias[9][7] = numero_invalido;
matriz_distancias[9][8] = numero_invalido;
matriz_distancias[9][9] = numero_invalido;


    
	chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
	unsigned long tejecucion;
	

    
    
		t0= std::chrono::high_resolution_clock::now();
	
    
       Prim (matriz_distancias, lista_solucion, vertices_candidatos, P, D);
    

		tf= std::chrono::high_resolution_clock::now();

    cout << "La proporcion de cada uno que cogemos es:" << endl;
    list<arista>::iterator it; 

    for (it=lista_solucion.begin(); it!=lista_solucion.end(); ++it) {
        cout <<  (*it).first << " " << (*it).second << endl;
        
    }


    
	
	tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
	
	cout << "Tiempo ejecucion -> " << tejecucion << endl;
	
    

    return 0;
}
