//
// Created by aldin on 15/02/2025.
//

#ifndef EDGE_H
#define EDGE_H
#include <ostream>

class Edge {
private:
    int u{};
    int v{};
    double weight{};
public:
    Edge() = default;
    Edge(int u, int v, double w);
    double get_weight() const;
    int get_u() const;
    int get_v() const;
    int other(int vertex) const;

    friend bool operator<(const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; }
    friend bool operator>(const Edge &e1, const Edge &e2) { return operator<(e2, e1); }
    friend bool operator==(const Edge &e1, const Edge &e2) { return e1.weight == e2.weight; }
    friend bool operator!=(const Edge &e1, const Edge &e2) { return !operator==(e1, e2); }
    friend bool operator<=(const Edge &e1, const Edge &e2) { return !operator>(e1, e2); }
    friend bool operator>=(const Edge &e1, const Edge &e2) { return !operator<(e1, e2); }
    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

#endif //EDGE_H
