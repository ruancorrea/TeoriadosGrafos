#include <iostream>
#include <fstream> // leitura de arquivos
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> Edge;
class Grafo
{
public:
    int V, E;
    vector<Edge> adj;
    Grafo(int V, int E, vector<Edge> edges);
    void adicionarAresta(int v1, int v2, int peso);
};

Grafo::Grafo(int V, int E, vector<Edge> edges)
{
	this->V = V;
    this->E = E;
	adj = edges;
}

void Grafo::adicionarAresta(int v1, int v2, int peso)
{
	adj.push_back(make_pair(peso, make_pair(v1, v2)));
}

int find(int i, int *p){
    if(p[i]==i) return i;
    return find(p[i],p);
}

void unite(int i, int j, int *p){
    p[find(i,p)] = find(j,p);
}

void kruskal(Grafo *grafo, int origem){
    int p[grafo->V], n=0, wt =0;
    for(int i=0; i<grafo->V;i++) p[i] = i;
    sort(grafo->adj.begin(), grafo->adj.end());
    cout << "(u,v,w)" << endl;
    while(n < grafo->V){
        if(find(grafo->adj[n].second.first, p) != find(grafo->adj[n].second.second, p)){
            unite(grafo->adj[n].second.first, grafo->adj[n].second.second, p);
            cout << "(" << grafo->adj[n].second.first << "," << grafo->adj[n].second.second << "," << grafo->adj[n].first << ")" << endl;
            wt += grafo->adj[n].first;
            //for(int i=0; i<grafo->V;i++) cout << "P[" << i << "] = " << p[i] << "\n";
        }
        //cout << "\n";
        n++;
    }
    free(p);
    cout << "Custo mínimo da árvore: " << wt << endl; 
}

int main()
{
    ifstream arquivo;
    arquivo.open("grafo.kk"); // leitura do arquivo grafo.kk |V| e |E|: v,u,p
    int n, m, a,b,c;
    arquivo >> n >> m;
    vector<Edge> edges;
    cout << "Criando grafo...\n\n";
    Grafo *grafo = new Grafo(n, m, edges);
    while(m--){
        arquivo >> a >> b >> c;
        grafo->adicionarAresta(a, b, c);
    }
    cout << "Árvore Gerada de Kruskal" << endl;
    kruskal(grafo, 0);
    free(grafo);
	return 0;
}