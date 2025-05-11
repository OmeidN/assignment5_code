#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>  // For std::pair
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"

using namespace std;

// Template class for a Graph
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool directed = false) : V(vertices), directed(directed) {
        adjList.resize(V);
    }

    // Add an edge
    void addEdge(int u, int v, T weight = T()) {
        // Prevent self-edges
        if (u == v) {
            return;
        }
        
        pair<int, T> edge(v, weight);
        adjList[u].add(edge);
        if (!directed) {
            pair<int, T> reverseEdge(u, weight);
            adjList[v].add(reverseEdge);
        }
    }

    // Get number of nodes
    int getNumVertices() const {
        return V;
    }

    // Print the adjacency list
    void printGraph() const {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            vector<pair<int, T>> neighbors = adjList[i].toVector();
            for (const auto& neighbor : neighbors) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    // Get neighbors of a vertex
    const LinkedBag<pair<int, T>>& getNeighbors(int vertex) const {
        return adjList[vertex];
    }

    // Depth First Traversal
    void DFT(int start, const vector<Product>& products) const {
        vector<bool> visited(V, false); // To keep track of visited vertices
        DFTRecursive(start, visited, products);
        cout << endl;
    }

    // Utility function for DFS (Recursive)
    void DFTRecursive(int v, vector<bool>& visited, const vector<Product>& products) const {
        visited[v] = true;
        
        // Print product information
        cout << "Product: " << products[v].getName() 
             << " (ID: " << v << ")"
             << "\nDescription: " << products[v].getDescription()
             << "\nRating: " << products[v].getRating()
             << "\nSold Count: " << products[v].getSoldCount()
             << "\n-------------------\n";

        // Recur for all the vertices adjacent to this vertex
        vector<pair<int, T>> neighbors = adjList[v].toVector();
        for (const auto& neighbor : neighbors) {
            if (!visited[neighbor.first]) {
                DFTRecursive(neighbor.first, visited, products);
            }
        }
    }

    // Depth First Search (by product name)
    bool DFS(const string& productName, const vector<Product>& products) const {
        vector<bool> visited(V, false);
        // Start DFS from each unvisited vertex to ensure we search the entire graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFSRecursive(i, productName, visited, products)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Utility function for DFS search (Recursive)
    bool DFSRecursive(int v, const string& productName, vector<bool>& visited, const vector<Product>& products) const {
        visited[v] = true;
        
        // Check if current vertex matches the product name
        if (products[v].getName() == productName) {
            return true;
        }
        
        // Recur for all the vertices adjacent to this vertex
        vector<pair<int, T>> neighbors = adjList[v].toVector();
        for (const auto& neighbor : neighbors) {
            if (!visited[neighbor.first]) {
                if (DFSRecursive(neighbor.first, productName, visited, products)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
    vector<LinkedBag<pair<int, T>>> adjList; // Adjacency list
};

#endif // GRAPH_H
