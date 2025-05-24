//
// Created by aldin on 14/02/2025.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/Graph.h"
#include "../include/Digraph.h"
#include "../include/EdgeWeightedGraph.h"
#include <algorithm>
#include <cstdio>

// Helper function to compare two graphs.
bool compareGraphs(const Graph &g1, const Graph &g2) {
    if (g1.get_V() != g2.get_V() || g1.get_E() != g2.get_E()) {
        return false;
    }
    for (int i = 0; i < g1.get_V(); i++) {
        std::vector<int> adj1 = g1.get_adj(i);
        std::vector<int> adj2 = g2.get_adj(i);
        std::ranges::sort(adj1);
        std::ranges::sort(adj2);
        if (adj1 != adj2)
            return false;
    }
    return true;
}

TEST_CASE("Undirected graph tests") {
    SUBCASE("Graph initialization and edge addition") {
        int V = 5;
        Graph g(V);
        CHECK_EQ(g.get_V(), 5);
        CHECK_EQ(g.get_E(), 0);

        // Add some edges.
        g.add_edge(0, 1);
        g.add_edge(0, 2);
        g.add_edge(1, 2);
        g.add_edge(3, 4);
        CHECK_EQ(g.get_E(), 4);

        // Check the adjacency list for vertex 0 (should contain 1 and 2).
        auto& adj0 = g.get_adj(0);
        CHECK_EQ(adj0.size(), 2);
        CHECK((std::find(adj0.begin(), adj0.end(), 1) != adj0.end()));
        CHECK((std::find(adj0.begin(), adj0.end(), 2) != adj0.end()));
    }

    SUBCASE("Graph file reading") {
        // Write a temporary file with graph data.
        std::ofstream ofs("tempGraph.txt");
        ofs << "5\n"   // number of vertices
            << "4\n"   // number of edges
            << "0 1\n"
            << "0 2\n"
            << "1 2\n"
            << "3 4\n";
        ofs.close();

        Graph g("tempGraph.txt");
        CHECK_EQ(g.get_V(), 5);
        CHECK_EQ(g.get_E(), 4);

        // Clean up the temporary file.
        std::remove("tempGraph.txt");
    }

    SUBCASE("Copy constructor") {
        // Create an original graph.
        Graph original(5);
        original.add_edge(0, 1);
        original.add_edge(0, 2);
        original.add_edge(1, 2);
        original.add_edge(3, 4);

        // Use the copy constructor.
        Graph copy(original);

        // Check that both graphs have the same number of vertices and edges.
        CHECK_EQ(copy.get_V(), original.get_V());
        CHECK_EQ(copy.get_E(), original.get_E());

        // Compare adjacency lists.
        CHECK(compareGraphs(original, copy));
    }

    SUBCASE("Copy assignment operator") {
        // Create two graphs with different contents.
        Graph graph1(5);
        graph1.add_edge(0, 1);
        graph1.add_edge(0, 2);
        graph1.add_edge(1, 2);
        graph1.add_edge(3, 4);

        Graph graph2(3);
        graph2.add_edge(0, 1); // dummy edge

        // Use copy assignment.
        graph2 = graph1;

        // Check that the assigned graph now matches graph1.
        CHECK_EQ(graph2.get_V(), graph1.get_V());
        CHECK_EQ(graph2.get_E(), graph1.get_E());
        CHECK(compareGraphs(graph1, graph2));
    }

    SUBCASE("Move constructor") {
        // Create an original graph.
        Graph original(5);
        original.add_edge(0, 1);
        original.add_edge(0, 2);
        original.add_edge(1, 2);
        original.add_edge(3, 4);

        int origV = original.get_V();
        int origE = original.get_E();

        // Move-construct a new graph from original.
        Graph moved(std::move(original));

        // The moved-to graph should have the original's data.
        CHECK_EQ(moved.get_V(), origV);
        CHECK_EQ(moved.get_E(), origE);

        // The moved-from graph should be empty (V and E reset to 0).
        CHECK_EQ(original.get_V(), 0);
        CHECK_EQ(original.get_E(), 0);
    }

    SUBCASE("Move assignment operator") {
        // Create a graph with data.
        Graph graph1(5);
        graph1.add_edge(0, 1);
        graph1.add_edge(0, 2);
        graph1.add_edge(1, 2);
        graph1.add_edge(3, 4);
        int g1V = graph1.get_V();
        int g1E = graph1.get_E();

        // Create another graph.
        Graph graph2(3);
        graph2.add_edge(0, 1);  // dummy data

        // Move-assign graph1 into graph2.
        graph2 = std::move(graph1);

        // The moved-to graph should have graph1's data.
        CHECK_EQ(graph2.get_V(), g1V);
        CHECK_EQ(graph2.get_E(), g1E);
        // The moved-from graph should now be empty.
        CHECK_EQ(graph1.get_V(), 0);
        CHECK_EQ(graph1.get_E(), 0);
    }
}

TEST_CASE("Directed graph tests") {
    SUBCASE("Digraph initialization and edge addition") {
        int V = 5;
        Digraph d(V);
        CHECK_EQ(d.get_V(), 5);
        CHECK_EQ(d.get_E(), 0);

        // Add directed edges.
        d.add_edge(0, 1);
        d.add_edge(0, 2);
        d.add_edge(1, 2);
        d.add_edge(3, 4);
        CHECK_EQ(d.get_E(), 4);

        // Check the adjacency list for vertex 0 (should point to 1 and 2).
        auto& adj0 = d.get_adj(0);
        CHECK_EQ(adj0.size(), 2);
        CHECK((std::find(adj0.begin(), adj0.end(), 1) != adj0.end()));
        CHECK((std::find(adj0.begin(), adj0.end(), 2) != adj0.end()));
    }

    SUBCASE("Digraph reverse operation") {
        int V = 5;
        Digraph d(V);
        // Build a small digraph.
        d.add_edge(0, 1);
        d.add_edge(0, 2);
        d.add_edge(1, 2);
        d.add_edge(3, 4);

        // Get the reverse digraph.
        Digraph rev = d.reverse();

        // In the reversed graph, edge 0->1 becomes 1->0.
        auto& revAdj1 = rev.get_adj(1);
        CHECK_EQ(revAdj1.size(), 1);
        CHECK_EQ(revAdj1[0], 0);

        // For edges 0->2 and 1->2 in the original,
        // the reversed graph should have edges 2->0 and 2->1.
        auto& revAdj2 = rev.get_adj(2);
        CHECK_EQ(revAdj2.size(), 2);
        std::vector<int> expected = {0, 1};
        std::sort(revAdj2.begin(), revAdj2.end());
        std::sort(expected.begin(), expected.end());
        CHECK_EQ(revAdj2, expected);

        // Edge 3->4 becomes 4->3.
        auto& revAdj4 = rev.get_adj(4);
        CHECK_EQ(revAdj4.size(), 1);
        CHECK_EQ(revAdj4[0], 3);
    }

    SUBCASE("Digraph file reading") {
        // Write a temporary file with digraph data.
        std::ofstream ofs("tempDigraph.txt");
        ofs << "5\n"   // number of vertices
            << "4\n"   // number of edges
            << "0 1\n"
            << "0 2\n"
            << "1 2\n"
            << "3 4\n";
        ofs.close();

        Digraph d("tempDigraph.txt");
        CHECK_EQ(d.get_V(), 5);
        CHECK_EQ(d.get_E(), 4);

        // Clean up the temporary file.
        std::remove("tempDigraph.txt");
    }
}

TEST_CASE("EdgeWeightedGraph tests") {
    SUBCASE("Graph initialization and edge addition") {
        int V = 5;
        EdgeWeightedGraph g(V);
        CHECK_EQ(g.get_V(), 5);
        CHECK_EQ(g.get_E(), 0);

        // Add some weighted edges.
        g.add_edge(0, 1, 0.5);
        g.add_edge(0, 2, 1.2);
        g.add_edge(1, 2, 0.7);
        g.add_edge(3, 4, 1.1);
        CHECK_EQ(g.get_E(), 4);

        // Check the adjacency list for vertex 0 (should contain edges to 1 and 2).
        auto &adj0 = g.get_adj(0);
        CHECK_EQ(adj0.size(), 2);

        bool foundEdge01 = false;
        bool foundEdge02 = false;
        for (const auto &edge : adj0) {
            int other = edge.other(0);
            // Assuming Edge has a get_weight() method.
            if (other == 1 && edge.get_weight() == 0.5) {
                foundEdge01 = true;
            } else if (other == 2 && edge.get_weight() == 1.2) {
                foundEdge02 = true;
            }
        }
        CHECK(foundEdge01);
        CHECK(foundEdge02);
    }

    SUBCASE("Graph file reading") {
        // Write a temporary file with weighted graph data.
        std::ofstream ofs("tempEdgeWeightedGraph.txt");
        // First line: number of vertices, second line: number of edges,
        // then each subsequent line: u v weight
        ofs << "5\n"   // number of vertices
            << "4\n"   // number of edges
            << "0 1 0.5\n"
            << "0 2 1.2\n"
            << "1 2 0.7\n"
            << "3 4 1.1\n";
        ofs.close();

        EdgeWeightedGraph g("tempEdgeWeightedGraph.txt");
        CHECK_EQ(g.get_V(), 5);
        CHECK_EQ(g.get_E(), 4);

        // Check the adjacency list for vertex 0.
        auto &adj0 = g.get_adj(0);
        CHECK_EQ(adj0.size(), 2);

        bool foundEdge01 = false;
        bool foundEdge02 = false;
        for (const auto &edge : adj0) {
            int other = edge.other(0);
            if (other == 1 && edge.get_weight() == 0.5) {
                foundEdge01 = true;
            } else if (other == 2 && edge.get_weight() == 1.2) {
                foundEdge02 = true;
            }
        }
        CHECK(foundEdge01);
        CHECK(foundEdge02);

        // Clean up the temporary file.
        std::remove("tempEdgeWeightedGraph.txt");
    }
}