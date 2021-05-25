#include <fstream> // leitura de arquivos
#include <queue>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
#define INFINITO 100000
typedef pair<int, int> Edge;

void prim(vector<Edge> *edges, int n, int origem){
    vector<int> d(n, INFINITO);
	vector<int> p(n, -1);
	vector<bool> v(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> H;
    H.push(make_pair(0,origem));
    d[origem] = 0;
    while(!H.empty())
	{
		int w =  H.top().second;
		H.pop();
		v[w] = true;
		for(auto item: edges[w])
		{
			if(!v[item.first] && d[item.first] > item.second)
			{
				d[item.first] = item.second;
				H.push(make_pair(d[item.first], item.first));
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
    arquivo.open("grafo.prim"); // leitura do arquivo info.gph |V| e |E|: v,u,d
    int n, m, i=0, a,b,c;
    arquivo >> n >> m;
    vector<Edge> edges[m];
    cout << "Criando grafo...\n\n";
    while(m--){
        arquivo >> a >> b >> c;
        edges[a].push_back(make_pair(b,c));
        edges[b].push_back(make_pair(a,c));
    }
    cout << "Utilizando o algoritmo de Prim\n\n";
    prim(edges,n, 0);
	return 0;
}