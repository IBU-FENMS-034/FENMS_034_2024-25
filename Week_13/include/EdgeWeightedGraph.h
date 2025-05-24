//
// Created by aldin on 15/02/2025.
//

#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H
#include <vector>
#include "Edge.h"

class EdgeWeightedGraph {
private:
    int V{};
    int E{};
    std::vector<Edge>* adj{};
public:
    explicit EdgeWeightedGraph(int V);
    explicit EdgeWeightedGraph(const char* file_path);
    EdgeWeightedGraph(const EdgeWeightedGraph& src);
    EdgeWeightedGraph& operator=(const EdgeWeightedGraph& src);
    EdgeWeightedGraph(EdgeWeightedGraph&& src) noexcept;
    EdgeWeightedGraph& operator=(EdgeWeightedGraph&& src) noexcept;
    ~EdgeWeightedGraph();

    void add_edge(int u, int v, double w);
    int get_V() const;
    int get_E() const;
    std::vector<Edge>& get_adj(int v) const;
    std::vector<Edge> get_all_edges() const;
};

#endif //EDGEWEIGHTEDGRAPH_H
