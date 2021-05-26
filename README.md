<div align = "justify">
    <h1>Teoria dos Grafos</h1>
    <h2>Implementação de algoritmos em C++</h2>
    <p> Professor Rian Gabriel Pinheiro </p>
    <p>Alunos:</br>
        <small><a href="https://github.com/joaopedrobritot">João Pedro Brito Tomé</a></small></br>
        <small><a href="https://github.com/ruancorrea">Ruan Heleno Correa da Silva</a></small>
     </p></br>
     <table style="width:100%">
        <tr>
            <th></th>
            <th>Algoritmo</th>
        </tr>
        <tr>
            <td>1</td>
            <td><a href="https://github.com/ruancorrea/TeoriadosGrafos/tree/main/dijkstra">Dijkstra</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td><a href="https://github.com/ruancorrea/TeoriadosGrafos/tree/main/floyd-warshall">Floyd Warshall</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td><a href="https://github.com/ruancorrea/TeoriadosGrafos/tree/main/ford-fulkerson">Ford Fulkerson</a></td>
        </tr>
        <tr>
            <td>4</td>
            <td><a href="https://github.com/ruancorrea/TeoriadosGrafos/tree/main/kruskal">Kruskal</a></td>
        </tr>
        <tr>
            <td>5</td>
            <td><a href="https://github.com/ruancorrea/TeoriadosGrafos/tree/main/prim">Prim</a></td>
        </tr>
    </table>
    </br>
    
Para compilar cada algoritmo, acesse sua determinada pasta e insira:
```
make all
```

<div align="justify">
	<h1> Arquivo dos grafos: </h1>
</div>

O arquivo contendo as informações de um grafo está organizado da seguinte forma:

```
n m
v1 v2 p1             // Aresta v1-v2 com peso p1
.
.
.
vn v4 p2            // Aresta vn-v4 com peso p2

```
<div>
    <b><small><p>Leve em consideração que os algoritmos foram organizados para lerem grafos de <i>origem (0)</i> até o <i>destino (n-1)</i></p></small></b>
    <b><small><p>Em cada pasta de cada algoritmo há um arquivo contém um grafo como exemplo.</p></small></b>
</div>


<div align="center">
	<h1> Execução: </h1>
</div>

Após a compilação de cada algoritmo, é gerado o arquivo executavel do determinado algoritmo, para executar insira no determinado diretório do algoritmo:


Dijkstra:
```
./dij
```

Floyd Warshaal:
```
./fw 
```

Ford fulkerson:
```
./ff 
```

Kruskal:
```
./kruskal 
```

Prim:
```
./prim
```

</div></br></br>
