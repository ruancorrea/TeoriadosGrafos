#ifndef GRAFOPD_H_
#define GRAFOPD_H_
#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;
typedef pair<int, int> Edge;

class Grafo
{
public:
    int V, E;
    vector<Edge> *adj;

    Grafo(int V, int E, vector<Edge> *edges){
        this->V = V;
        this->E = E;
        adj = edges;
    }

    void adicionarAresta(int v1, int v2, int peso, bool dir){
        if(dir) adj[v1].push_back(make_pair(v2,peso));
        else{
            adj[v1].push_back(make_pair(v2,peso));
            adj[v2].push_back(make_pair(v1,peso));
        }
    }
};

#endif