#include "graph.h"
graph::graph(int v){
    this->vertices = v;
    this->adjList.resize(v);
    for(int i = 0; i < v; i++){
        this->vertexList.emplace_back(i);      //inicializa todos os vertices
    }
}

//para grafos direcioais
//lista de adjacencia   //pair(vertice, peso)
void graph::addEdgeDirectional(int u, int v, int w){
    this->adjList[u].push_back({v,w});                //adiciona um vertice/aresta a lista de adjacencia, colocando tambem seu peso
}

//para grafos nao direcionais
void graph::addEdgeNonDirectional(int u, int v, int w){
    this->adjList[u].push_back({v,w});                //adiciona um vertice/aresta a lista de adjacencia, colocando tambem seu peso
    this->adjList[v].push_back({u, w});
}


//inicializa todos os vertices com predecessor nulo e d infinito , start é meu vertice de partida
void graph::initializeSingleSource(int start) {
    for (auto &vertex : this->vertexList) {
        vertex.d = INF;
        vertex.predecessor = -1;
        }
    this->vertexList[start].d = 0;
}

//atualiza o peso das arestas caso a condicao seja verdadeira
void graph::relax(int u, int v, int weight) {
    if(this->vertexList[v].d > this->vertexList[u].d + weight){
        this->vertexList[v].d = this->vertexList[u].d + weight;
        this->vertexList[v].predecessor = u;
    }
}

void graph::dijkstra(int start) {
    this->initializeSingleSource(start);

    //fila de prioridade - pair<distancia, vertice>
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        //lista de adjacencia - pair(vertice, peso)
        for(auto &edge : this->adjList[u]){
            int v = edge.first;        //vertice adjacente de u (vertice v)
            int weight = edge.second; //peso da aresta de u ate v
            if(this->vertexList[v].d > this->vertexList[u].d + weight){ //essa condição existe, para que o peso das arestas na fila de prioridade seja atualizado quando for necessario
                this->relax(u, v, weight);
                pq.push({this->vertexList[v].d, v});
            }
        }
    }
}

void graph::printShortestDistance() {
    cout << endl;
    cout << "Distancia total até chegar ao vertice em questão e seu predecessor:\n";
    for(const auto & vertex : this->vertexList){
        cout << "Vértice: "<< vertex.id << " - Distância: " << (vertex.d == INF ? "Inalcançavel " : to_string(vertex.d))
        << " - Predecessor " << (vertex.predecessor == -1 ? "N/A" : to_string(vertex.predecessor))<< "\n";
    }
    cout << endl;
}

void graph::printShortestPaths(int start) {
    cout << endl;
    for (const auto &vertex : vertexList) {  //em cada iteração irá criar um caminho path para imprimir, cada caminho pertece ao vertex que está sendo analisado
        //pula para a proxima iteracao caso nao sejá um vertice alcançavel apartir do vertice de origem
        if (vertex.d == INF) {
            cout << "Vértice " << vertex.id << " é inalcançável a partir do vértice " << start << ".\n";
            continue;
        }

        //cria o caminho path de start ate o vertice atual
        stack<int> path;
        for (int v = vertex.id; v != -1; v = vertexList[v].predecessor) {
            path.push(v);
        }

        //imprime o caminho criado em path
        cout << "Caminho até o vértice " << vertex.id << ": ";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }

        cout << " (Distância: " << vertex.d << ")\n";
    }
}




