#include <iostream>
#include <fstream> // leitura de arquivos
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> EdgeKruskal;
class GrafoKruskal
{
public:
    int V, E;
    vector<EdgeKruskal> adj;
    GrafoKruskal(int V, int E, vector<EdgeKruskal> edges);
    void adicionarAresta(int v1, int v2, int peso);
};

GrafoKruskal::GrafoKruskal(int V, int E, vector<EdgeKruskal> edges)
{
	this->V = V;
    this->E = E;
	adj = edges;
}

void GrafoKruskal::adicionarAresta(int v1, int v2, int peso)
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

void execute(GrafoKruskal *grafo, int origem){
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
    cout << "Custo minimo da arvore: " << wt << endl; 
}

void kruskal(string info)
{
    ifstream arquivo;
    arquivo.open(info); // leitura do arquivo info.gph |V| e |E|: v,u,d
    int n, m, a,b,c;
    arquivo >> n >> m;
    vector<EdgeKruskal> edges;
    cout << "Criando grafo...\n\n";
    GrafoKruskal *grafo = new GrafoKruskal(n, m, edges);
    while(m--){
        arquivo >> a >> b >> c;
        grafo->adicionarAresta(a, b, c);
    }
    cout << "Arvore Gerada de Kruskal" << endl;
    execute(grafo, 0);
    free(grafo);
}