#include <fstream> // leitura de arquivos
#include "../Headers/GrafoPD.h"
#include "../Headers/calculus_gph.h"
using namespace std;

void calculoArestas(Grafo *grafo, int *d, int *p, int u, int v, bool *abertos){
    for(auto item: grafo->adj[u]){
        if(item.first == v && abertos[item.first]){
            if(d[v] > d[u] + item.second){
                d[v] = d[u] + item.second;
                p[v] = u;
            }
            break;
        }
    }
}

void dijkstra(Grafo *grafo, int origem){
    int d[grafo->V], p[grafo->V], i;
    bool abertos[grafo->V];
    iniciando(grafo, d, p, origem, abertos);
    while(algumAberto(grafo->V, abertos)){
        int u = menorDistancia(grafo->V,d,abertos);
        abertos[u]= false;
        for(auto item : grafo->adj[u]) calculoArestas(grafo,d,p,u,item.first, abertos);
    }
    cout << "Árvore gerada a partir da origem " << origem << "\n";
    for(i=1;i<grafo->V;i++) cout << p[i] << " -> " << i << "\n";
    free(d);
    free(p);
}

int main()
{
    ifstream arquivo;
    arquivo.open("grafo.dji"); // leitura do arquivo info.gph |V| e |E|: v,u,d
    int n, m, i=0, a,b,c;
    arquivo >> n >> m;
    vector<Edge> edges[m];
    Grafo *grafo = new Grafo(n, m, edges);
    cout << "Criando grafo...\n\n";
    while(m--){
        arquivo >> a >> b >> c;
        grafo->adicionarAresta(a, b, c, true);
    }
    cout << "Utilizando o algoritmo de Dijkstra\n\n";
    dijkstra(grafo, 0);
    free(grafo);
	return 0;
}