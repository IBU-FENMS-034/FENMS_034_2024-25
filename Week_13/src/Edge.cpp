//
// Created by aldin on 15/02/2025.
//

#include "../include/Edge.h"

#include <stdexcept>

Edge::Edge(int u, int v, double w) {
    this->u = u;
    this->v = v;
    this->weight = w;
}

int Edge::get_u() const {
    return u;
}

int Edge::get_v() const {
    return v;
}

double Edge::get_weight() const {
    return weight;
}

int Edge::other(int vertex) const {
    if (vertex == u) {
        return v;
    } else if (vertex == v) {
        return u;
    } else {
        throw std::invalid_argument("Inconsistent edge");
    }
}

std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << "[(" << edge.u << "," << edge.v << "): " << edge.weight << "]";
    return os;
}


