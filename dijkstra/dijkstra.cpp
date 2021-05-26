#include <fstream> // leitura de arquivos
#include <queue>
#include <bits/stdc++.h> 
using namespace std;
#define INFINITO 10000000
typedef pair<int, int> Edge;

void dijkstra(vector<Edge> *edges, int n, int origem){
    vector<int> d(n, INFINITO), p(n, -1);
    int custo = 0;
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
			if(!v[item.first] && d[item.first] > d[w] + item.second)
			{
				d[item.first] = d[w] + item.second;
				H.push(make_pair(d[item.first], item.first));
				p[item.first] = w;
			}
		}
	}
    cout << "Árvore gerada a partir da origem " << origem << "\n";
    for(int i=1;i<n;i++) cout << p[i] << " -> " << i << "\n";
    
    cout << "\nMenor caminho encontrado" << endl;
    for(int i=n-1;i!=origem;i=p[i]){
        cout << i << " <- ";
        for(int j=origem; j<n-1;j++) for(auto item: edges[j]) if(j == p[i] && item.first == i) custo += item.second;
    }
    cout << origem << "\nCom custo: " << custo << endl;
}

int main()
{
    ifstream arquivo;
    arquivo.open("grafo.dji"); // leitura do arquivo info.dji |V| e |E|: v,u,d
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
    free(edges);
	return 0;
}