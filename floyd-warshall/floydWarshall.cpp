#include <iostream>
#include <fstream> // leitura de arquivos
#include <bits/stdc++.h> 
#include <queue>
using namespace std;
#define INFINITO 1000
#define NIL -1000

void floydWarshall(int **grafo, int **pi, int tam){
    // falta add pi
    for (int k = 0; k < tam; k++) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if (grafo[i][j] > grafo[i][k] + grafo[k][j]){
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
                    pi[i][j] = pi[k][j];
                }else {
                    grafo[i][j] = grafo[i][j];
                }
            }
        }
    }
    cout << "\n" << "Matriz resultante" << "\n";
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if(grafo[i][j] == INFINITO){
               cout << "INF" << " "; 
            } else cout << grafo[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n" << "Matriz predecessora" << "\n" ;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if(pi[i][j] == NIL){
               cout << "NIL" << " "; 
            } else cout << pi[i][j] << " ";
        }
        cout << "\n";
    }
}


int main(){
    ifstream arquivo;
    arquivo.open("grafo.fw"); // leitura do arquivo grafo.fw |V| e |E|: v,u,d
    int n, m, infoGraph[3];
    arquivo >> n >> m;
    int **grafo = (int**)malloc(sizeof(int*) * n);
    int **pi = (int**)malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++){
        grafo[i] = (int*) malloc(sizeof(int)*n);
        pi[i] = (int*) malloc(sizeof(int)*n);
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pi[i][j] = NIL;
            if(i == j){
                grafo[i][j] = 0;
            }else grafo[i][j] = INFINITO;
        }
    }
 
    while(m--){
        arquivo >> infoGraph[0] >> infoGraph[1] >> infoGraph[2];
        grafo[infoGraph[0]][infoGraph[1]] = infoGraph[2];
        pi[infoGraph[0]][infoGraph[1]] = infoGraph[0]+1;
    }

    cout << "Utilizando o algoritmo de Floyd Warshall\n";
    floydWarshall(grafo,pi, n);
    for(int i=0;i<n;i++) free(grafo[i]);
    free(grafo);
    return 0;
}