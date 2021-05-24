#ifndef _CALCULUS_GPH_H_
#define _CALCULUS_GPH_H_
#include "../Headers/GrafoPD.h"
#define INFINITO 10000000

void iniciando(Grafo *grafo, int *ds, int *ps, int origem, bool *abertos){
    for(int i=0; i<grafo->V; i++){
        ps[i] = -1;
        ds[i] = INFINITO;
        abertos[i] = true;
    }
    ds[origem] = 0;
}

bool algumAberto(int v, bool *abertos){
    for(int i=0;i<v;i++) if(abertos[i]) return true;
    return false;
}

int menorDistancia(int v, int *d, bool *abertos){
    int i;
    for(i=0;i<v;i++) if(abertos[i]) break;
    if(i==v) return -1;
    int menor = i;
    for(i=menor+1;i<v;i++)if(abertos[i] && d[menor] > d[i]) menor = i;
    return menor;
}

#endif