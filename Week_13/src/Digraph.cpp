//
// Created by aldin on 14/02/2025.
//

#include "../include/Digraph.h"

#include <fstream>
#include <vector>

Digraph::Digraph(int V) {
    this->V = V;
    adj = new std::vector<int>[V];
}

Digraph::Digraph(const char *file_path) {
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

Digraph::~Digraph() {
    delete[] adj;
}

Digraph::Digraph(const Digraph &src) {
    V = src.V;
    E = src.E;
    adj = new std::vector<int>[src.V];

    for (int i = 0; i < src.V; i++) {
        adj[i] = src.adj[i];
    }
}

Digraph &Digraph::operator=(const Digraph &src) {
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

Digraph::Digraph(Digraph &&src) noexcept {
    adj = src.adj;
    V = src.V;
    E = src.E;

    src.adj = nullptr;
    src.V = 0;
    src.E = 0;
}

Digraph &Digraph::operator=(Digraph &&src) noexcept {
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

void Digraph::add_edge(int u, int v) {
    adj[u].push_back(v);
    ++E;
}

int Digraph::get_E() const {
    return E;
}

int Digraph::get_V() const {
    return V;
}

std::vector<int> &Digraph::get_adj(const int v) const {
    return adj[v];
}

Digraph Digraph::reverse() const {
    Digraph reverse(V);
    for (int i = 0; i < V; i++) {
        for (const int v: get_adj(i)) {
            reverse.add_edge(v, i);
        }
    }
    return reverse;
}

