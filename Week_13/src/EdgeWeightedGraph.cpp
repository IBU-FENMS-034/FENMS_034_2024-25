//
// Created by aldin on 15/02/2025.
//

#include "../include/EdgeWeightedGraph.h"

#include <fstream>

EdgeWeightedGraph::EdgeWeightedGraph(int V) {
    this->V = V;
    adj = new std::vector<Edge>[V];
}

EdgeWeightedGraph::EdgeWeightedGraph(const char *file_path) {
    std::fstream fs(file_path, std::fstream::in);
    int E{0};
    fs >> this->V;
    fs >> E;
    adj = new std::vector<Edge>[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        double w;
        fs >> u >> v >> w;
        add_edge(u, v, w);
    }

    fs.close();
}

EdgeWeightedGraph::~EdgeWeightedGraph() {
    delete[] adj;
}

EdgeWeightedGraph::EdgeWeightedGraph(const EdgeWeightedGraph &src) {
    V = src.V;
    E = src.E;
    adj = new std::vector<Edge>[src.V];

    for (int i = 0; i < src.V; i++) {
        adj[i] = src.adj[i];
    }
}

EdgeWeightedGraph &EdgeWeightedGraph::operator=(const EdgeWeightedGraph &src) {
    if (this != &src) {
        delete[] adj;

        V = src.V;
        E = src.E;
        adj = new std::vector<Edge>[src.V];
        for (int i = 0; i < src.V; i++) {
            adj[i] = src.adj[i];
        }
    }
    return *this;
}

EdgeWeightedGraph::EdgeWeightedGraph(EdgeWeightedGraph &&src) noexcept {
    adj = src.adj;
    V = src.V;
    E = src.E;

    src.adj = nullptr;
    src.V = 0;
    src.E = 0;
}

EdgeWeightedGraph &EdgeWeightedGraph::operator=(EdgeWeightedGraph &&src) noexcept {
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

void EdgeWeightedGraph::add_edge(int u, int v, double w) {
    adj[u].push_back(Edge(u, v, w));
    adj[v].push_back(Edge(v, u, w));
    ++E;
}

int EdgeWeightedGraph::get_E() const {
    return E;
}

int EdgeWeightedGraph::get_V() const {
    return V;
}

std::vector<Edge> &EdgeWeightedGraph::get_adj(const int v) const {
    return adj[v];
}

std::vector<Edge> EdgeWeightedGraph::get_all_edges() const {
    std::vector<Edge> edges;
    for (int v = 0; v < V; v++) {
        for (Edge e : adj[v]) {
            if (e.other(v) > v) {
                edges.push_back(e);
            }
        }
    }
    return edges;
}



