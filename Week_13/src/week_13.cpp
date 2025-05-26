//
// Created by aldin on 14/02/2025.
//

#include <iostream>

#include "../include/Digraph.h"
#include "../include/Edge.h"
#include "../include/EdgeWeightedGraph.h"
#include "../include/Graph.h"

void undirected_graph_demo();
void directed_graph_demo();
void edge_weighted_graph_demo();

int main() {
    undirected_graph_demo();
    std::cout << std::endl << std::endl;
    directed_graph_demo();
    std::cout << std::endl << std::endl;
    edge_weighted_graph_demo();
}

void undirected_graph_demo() {
    // Manually create a graph
    Graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);

    std::cout << "Undirected graph:" << std::endl;
    std::cout << "Number of vertices: " << g1.get_V() << std::endl;
    std::cout << "Number of edges: " << g1.get_E() << std::endl;

    // See adjacent vertices of vertex 0
    // Expected: 1, 2, 3
    std::cout << "Adjacent vertices of 0 (manual): " << std::endl;
    std::vector<int> vertices1 = g1.get_adj(0);
    for (const int i : vertices1) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // Create a graph from a file
    Graph g2("../Week_13/resources/tinyG.txt");

    std::cout << "Number of vertices: " << g2.get_V() << std::endl;
    std::cout << "Number of edges: " << g2.get_E() << std::endl;

    // See adjacent vertices of vertex 0
    // Expected: 1, 2, 3
    std::cout << "Adjacent vertices of 0 (file): " << std::endl;
    std::vector<int> vertices2 = g2.get_adj(0);
    for (const int i : vertices2) {
        std::cout << i << " ";
    }
}

void directed_graph_demo() {
    Digraph g1("../Week_13/resources/tinyDG.txt");

    std::cout << "Directed graph:" << std::endl;
    std::cout << "Number of vertices: " << g1.get_V() << std::endl;
    std::cout << "Number of edges: " << g1.get_E() << std::endl;

    // See adjacent vertices of vertex 0
    // Expected: 1, 5
    std::cout << "Adjacent vertices of 0 (file): " << std::endl;
    std::vector<int> vertices1 = g1.get_adj(0);
    for (const int i : vertices1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Reverse the graph
    Digraph reversed = g1.reverse();

    // See adjacent vertices of vertex 0
    // Expected: 2, 6
    std::cout << "Adjacent vertices of 0 (reversed): " << std::endl;
    std::vector<int> vertices2 = reversed.get_adj(0);
    for (const int i : vertices2) {
        std::cout << i << " ";
    }
}

void edge_weighted_graph_demo() {
    EdgeWeightedGraph ewg("../Week_13/resources/tinyEWG.txt");

    std::cout << "Number of vertices: " << ewg.get_V() << std::endl;
    std::cout << "Number of edges: " << ewg.get_E() << std::endl;

    // See adjacent vertices of vertex 0
    // Expected: 7, 4, 2, 6
    std::cout << "Adjacent vertices of 0 (file): " << std::endl;
    std::vector<Edge> vertices = ewg.get_adj(0);
    for (const Edge& e : vertices) {
        std::cout << e.other(0) << " ";
    }

    // Get all edges
    std::cout << std::endl << std::endl;
    std::cout << "All edges: " << std::endl;
    std::vector<Edge> edges = ewg.get_all_edges();
    for (const Edge& e : edges) {
        std::cout << e << std::endl;
    }
}