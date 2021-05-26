#include <iostream>
#include <fstream> // leitura de arquivos
#include <bits/stdc++.h> 
#include <queue>
using namespace std;
#define INFINITO 1000
 
bool bfs(int **grafo, int *p, int tam, int origem, int destino)
{
    queue<int> fila;// queue *queue = create_queue();
    bool v[tam]; //graph->visited[source] = 1;
    memset(v,0,sizeof(v));
    v[origem] = true; //graph->visited[source] = 1;
    p[origem] = -1;
    fila.push(origem); //enqueue(queue, source);
    int u;
    while(!fila.empty()) {
        u = fila.front(); //dequeued = dequeue(queue);
        fila.pop();
        for (int i=0; i<tam; i++) {
            if (!v[i] && grafo[u][i] > 0) {
                p[i] = u;
                if(i == destino) return true;
                v[i] = true; //graph->visited[i] = 1;
                fila.push(i);//enqueue(queue, adj_list->item);
            }
        }
    }
    return false;
}
 
void fordFulkerson(int **grafo, int tam, int origem, int destino){
    int p[tam], max=0, v,u;
    while(bfs(grafo, p, tam, origem, destino)){
        int path = INFINITO;
        for(v = destino; v != origem; v = p[v]){
            u = p[v];
            path = min(path, grafo[u][v]);
        }
        for (v=destino; v != origem; v=p[v])
        {
            u = p[v];
            grafo[u][v] -= path;
            grafo[v][u] += path;
        }
        max += path;
        cout << "Aresta mínima removida -> " << path << endl;
    }
    cout << "Resultado encontrado: " << max << endl;
}
 
int main(){
    ifstream arquivo;
    arquivo.open("grafo.ff"); // leitura do arquivo grafo.ff |V| e |E|: v,u,d
    int n, m, infoGraph[3];
    arquivo >> n >> m;
    int **grafo = (int**)malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++) grafo[i] = (int*) malloc(sizeof(int)*n);
 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) grafo[i][j] = 0;
 
    while(m--){
        arquivo >> infoGraph[0] >> infoGraph[1] >> infoGraph[2];
        grafo[infoGraph[0]][infoGraph[1]] = infoGraph[2];
    }
    cout << "Utilizando o algoritmo de Ford Fulkerson\n";
    fordFulkerson(grafo,n, 0, n - 1); // origem 0
    for(int i=0;i<n;i++) free(grafo[i]);
    free(grafo);
    return 0;
}