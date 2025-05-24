//
// Created by aldin on 14/02/2025.
//

#include "../include/Graph.h"

#include <fstream>

Graph::Graph(int V) {
    this->V = V;
    adj = new std::vector<int>[V];
}

Graph::Graph(const char *file_path) {
    std::fstream fs(file_path, std::fstream::in);
    int E{0};
    fs >> this->V;
    fs >> E;
    adj = new std::vector<int>[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        fs >> u >> v;
        add_edge(u, v);
    }

    fs.close();
}

Graph::~Graph() {
    delete[] adj;
}

Graph::Graph(const Graph &src) {
    V = src.V;
    E = src.E;
    adj = new std::vector<int>[src.V];

    for (int i = 0; i < src.V; i++) {
        adj[i] = src.adj[i];
    }
}

Graph &Graph::operator=(const Graph &src) {
    if (this != &src) {
        delete[] adj;

        V = src.V;
        E = src.E;
        adj = new std::vector<int>[src.V];
        for (int i = 0; i < src.V; i++) {
            adj[i] = src.adj[i];
        }
    }
    return *this;
}

Graph::Graph(Graph &&src) noexcept {
    adj = src.adj;
    V = src.V;
    E = src.E;

    src.adj = nullptr;
    src.V = 0;
    src.E = 0;
}

Graph &Graph::operator=(Graph &&src) noexcept {
    if (this != &src) {
        delete[] adj;

        adj = src.adj;
        V = src.V;
        E = src.E;

        src.adj = nullptr;
        src.V = 0;
        src.E = 0;
    }
    return *this;
}

void Graph::add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++E;
}

int Graph::get_E() const {
    return E;
}

int Graph::get_V() const {
    return V;
}

std::vector<int> &Graph::get_adj(const int v) const {
    return adj[v];
}


