#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"

using namespace std;

// Function to print product information during DFS traversal
void printProductInfo(int vertex, const vector<Product>& products) {
	cout << "Product: " << products[vertex].getName() 
		 << " (ID: " << vertex << ")"
		 << "\nDescription: " << products[vertex].getDescription()
		 << "\nRating: " << products[vertex].getRating()
		 << "\nSold Count: " << products[vertex].getSoldCount()
		 << "\n-------------------\n";
}

int main() {
	// Create 10 distinct products
	vector<Product> products = {
		Product("Laptop", "High-performance laptop with 16GB RAM", 4.5, 1200),
		Product("Smartphone", "Latest model with 5G capability", 4.8, 2500),
		Product("Headphones", "Noise-cancelling wireless headphones", 4.3, 800),
		Product("Tablet", "10-inch tablet with stylus support", 4.2, 1500),
		Product("Smartwatch", "Fitness tracker with heart rate monitor", 4.6, 900),
		Product("Camera", "Professional DSLR camera", 4.7, 600),
		Product("Printer", "Wireless all-in-one printer", 4.0, 400),
		Product("Monitor", "27-inch 4K display", 4.4, 700),
		Product("Keyboard", "Mechanical gaming keyboard", 4.1, 500),
		Product("Mouse", "Wireless gaming mouse", 4.2, 800)
	};

	// Initialize a graph with 10 vertices (one for each product)
	// Using an undirected graph since co-purchases are bidirectional
	// Comment: The graph is undirected because if product A is frequently bought with product B,
	// then product B is also frequently bought with product A. This represents a natural
	// co-purchase relationship between products.
	Graph<double> productGraph(10, false);

	// Add 15-20 edges with random weights (representing purchase frequency)
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> weightDist(0.1, 1.0);
	uniform_int_distribution<> vertexDist(0, 9);

	// Add 18 edges (ensuring no self-edges)
	for (int i = 0; i < 18; i++) {
		int u = vertexDist(gen);
		int v = vertexDist(gen);
		// Ensure we don't add the same edge twice
		while (u == v) {
			v = vertexDist(gen);
		}
		double weight = weightDist(gen);
		productGraph.addEdge(u, v, weight);
	}

	// Print the adjacency list
	cout << "Graph Structure (Adjacency List):\n";
	productGraph.printGraph();
	cout << "\n";

	// Depth First traversal printing product information
	cout << "Depth First Traversal (with product details):\n";
	int start = 0;
	productGraph.DFT(start, products);

	// Depth First search
	string prodName1 = "Laptop"; // Product that exists
	bool found = productGraph.DFS(prodName1, products);
	if (found) {
		cout << prodName1 << " has been found in the graph!" << endl;
	} else {
		cout << prodName1 << " has not been found in the graph!" << endl;
	}

	string prodName2 = "NonExistentProduct"; // Product that doesn't exist
	found = productGraph.DFS(prodName2, products);
	if (found) {
		cout << prodName2 << " has been found in the graph!" << endl;
	} else {
		cout << prodName2 << " has not been found in the graph!" << endl;
	}

	return 0;
}
