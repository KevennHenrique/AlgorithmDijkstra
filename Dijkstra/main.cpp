#include <iostream>
#include <clocale>

#include "graph.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int vertices, edges;
    cout << "Digite o n�mero de v�rtices e arestas: ";
    cin >> vertices >> edges;

    graph g(vertices);

    cout<< "\nSe seu grafo for direcional digite 1, se for n�o direcional digite 2:"<<endl;
    int op;
    cin >> op;

    cout << "Digite as arestas no formato (origem destino peso):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(op == 1){
            g.addEdgeDirectional(u, v, w);
        }else if(op == 2) {
            g.addEdgeNonDirectional(u, v, w);
        }

    }
    cout<< endl;

    int start;
    cout << "Digite o n� de in�cio: ";
    cin >> start;

    g.dijkstra(start);
    //g.printShortestDistance();    //nao foi necessario
    g.printShortestPaths(start);

    return 0;
}
