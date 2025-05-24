//
// Created by aldin on 14/02/2025.
//

#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <vector>

class Digraph {
private:
    int V{};
    int E{};
    std::vector<int>* adj{};
public:
    explicit Digraph(int V);
    explicit Digraph(const char* file_path);
    Digraph(const Digraph& src);
    Digraph& operator=(const Digraph& src);
    Digraph(Digraph&& src) noexcept;
    Digraph& operator=(Digraph&& src) noexcept;
    ~Digraph();

    void add_edge(int u, int v);
    int get_V() const;
    int get_E() const;
    std::vector<int>& get_adj(int v) const;
    Digraph reverse() const;
};

#endif //DIGRAPH_H
