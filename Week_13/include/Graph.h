//
// Created by aldin on 14/02/2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph {
private:
    int V{};
    int E{};
    std::vector<int>* adj{};
public:
    explicit Graph(int V);
    explicit Graph(const char* file_path);
    Graph(const Graph& src);
    Graph& operator=(const Graph& src);
    Graph(Graph&& src) noexcept;
    Graph& operator=(Graph&& src) noexcept;
    ~Graph();

    void add_edge(int u, int v);
    int get_V() const;
    int get_E() const;
    std::vector<int>& get_adj(int v) const;
};

#endif //GRAPH_H
