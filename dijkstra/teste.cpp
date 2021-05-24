#include <fstream> // leitura de arquivos
#include <queue>
#include <bits/stdc++.h> 
using namespace std;
#define INFINITO 10000000
typedef pair<int, int> Edge;

void dijkstra(vector<Edge> *edges, int n, int origem){
    vector<int> d(n, INFINITO);
	vector<int> p(n, -1);
	vector<bool> v(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push(make_pair(0,origem));
    d[origem] = 0;
    while(!pq.empty())
	{
		int w =  pq.top().second;
		pq.pop();
		v[w] = true;
		for(auto item: edges[w])
		{
			if(!v[item.first] && d[item.first] > d[w] + item.second)
			{
				d[item.first] = d[w] + item.second;
				pq.push(make_pair(d[item.first], item.first));
				p[item.first] = w;
			}
		}
	}
    cout << "Árvore gerada a partir da origem " << origem << "\n";
    for(int i=1;i<n;i++) cout << p[i] << " -> " << i << "\n";
}

int main()
{
    ifstream arquivo;
    arquivo.open("grafo.dji"); // leitura do arquivo info.gph |V| e |E|: v,u,d
    int n, m, i=0, a,b,c;
    arquivo >> n >> m;
    vector<Edge> edges[m];
    cout << "Criando grafo...\n\n";
    while(m--){
        arquivo >> a >> b >> c; // v1 v2 peso
        edges[a].push_back(make_pair(b,c)); // adicionando arcos
    }
    cout << "Utilizando o algoritmo de Dijkstra\n\n";
    dijkstra(edges,n, 0);
	return 0;
}