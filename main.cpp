#include <iostream>
#include <fstream> // leitura de arquivos
#include <vector>
#include <algorithm>
using namespace std;
#include "./dijkstra/dijkstra.h"
#include "./ford-fulkerson/fordFulkerson.h"
#include "./kruskal/kruskal.h"
#include "./prim/prim.h"

void menuInicial();
void algoritmos();
void verGrafos();

string grafos(){
    int entrada;
    while(true){
        printf("(1) Grafo 1, (2) Grafo 2, (3) Voltar\n >> ");
        scanf("%d", &entrada);
        printf("\n");
        switch(entrada){
            case 1:
                return "info1.gph";
                break;
            case 2:
                return "info2.gph";
                break;
            case 3:
                algoritmos();
                break;
        }
        if(entrada == 1 || entrada == 2 || entrada == 3) break;
    }
    return "info1.gph";
}

void algoritmos(){
    int entrada;
    while(true){
        printf("(1) Dijkstra, (2) Ford-Fulkerson, (3) Kruskal, (4) Prim, (5) Voltar\n >> ");
        scanf("%d", &entrada);
        printf("\n");
        switch(entrada){
            case 1:
                dijkstra(grafos());
                printf("\n");
                break;
            case 2:
                fordFulkerson(grafos());
                printf("\n");
                break;
            case 3:
                kruskal(grafos());
                printf("\n");
                break;
            case 4:
                prim(grafos());
                printf("\n");
                break;
            case 5:
                menuInicial();
                break;
        }
    }
}

void printGrafo(string info){
    ifstream arquivo;
    arquivo.open(info);
    string line;
    while (getline(arquivo, line)) {
        printf("%s\n", line.c_str());
    }
    arquivo.close();
    printf("\n\n");
    verGrafos();
}

void verGrafos(){
    int entrada;
    while(true){
        printf("(1) Grafo 1, (2) Grafo 2, (3) Voltar\n >> ");
        scanf("%d", &entrada);
        printf("\n");
        switch(entrada){
            case 1:
                printGrafo("Grafo_1.txt");
                break;
            case 2:
                printGrafo("Grafo_2.txt");
                break;
            case 3:
                menuInicial();
                break;
        }
    }
}

void menuInicial(){
    int entrada;
    while(true){
        printf("(1) Algoritmos, (2) Grafos, (3) Ajuda, (0) Finalizar\n >> ");
        scanf("%d", &entrada);
        printf("\n");
        switch(entrada){
            case 1:
                algoritmos();
                break;
            case 2:
                verGrafos();
                break;
            case 3:
                printf("A primeira opcao do menu inicial eh para ser redirecionado para a escolha dos algoritmos.\n");
                printf("Depois de escolher o algoritmo, sera o momento de escolher o grafo a ser executado, sao duas opcoes de grafos.\n");
                printf("A segunda opcao do menu inicial eh para visualizar nao tao focadamente os grafos no terminal.\n");
                printf("Para ver a imagem em melhor qualidade, veja o github do projeto.\n\n");
                break;
            case 0:
                return;
        }
    }
}

int main(){
    printf("Alunos: Joao Pedro Brito Tome, Ruan Heleno Correa da Silva\n\n");
    menuInicial();
    return 0;
}