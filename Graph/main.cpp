#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Pointer to adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Insert edge in an undirected graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list
        adj[w].push_back(v); // Since the graph is undirected
    }

    // Delete edge from the graph
    void removeEdge(int v, int w) {
        adj[v].remove(w); // Remove w from v's list
        adj[w].remove(v); // Remove v from w's list
    }

    // DFS traversal of the vertices reachable from v
    void DFSUtil(int v, bool visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS traversal starting from vertex v
    void DFS(int v) {
        // Initially all vertices are unvisited
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, visited);
        cout << "\n";
    }

    // BFS traversal starting from vertex v
    void BFS(int v) {
        // Initially all vertices are unvisited
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            int current = q.front();
            cout << current << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // Search for a vertex in the graph
    bool search(int v, int target) {
        // If vertex v is out of range
        if (v >= V) return false;

        // BFS-based search starting from vertex v
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> q;
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == target) {
                return true;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }

    // Print the adjacency list representation of the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "\nAdjacency list of vertex " << v << "\nhead ";
            for (auto x : adj[v])
                cout << "-> " << x;
            cout << "\n";
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print adjacency list
    g.printGraph();

    // Perform DFS and BFS
    cout << "\nDFS starting from vertex 0: ";
    g.DFS(0);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    // Search for a vertex
    int target = 3;
    if (g.search(0, target)) {
        cout << "Vertex " << target << " found in the graph.\n";
    } else {
        cout << "Vertex " << target << " not found in the graph.\n";
    }

    // Remove an edge
    g.removeEdge(1, 3);
    cout << "\nGraph after removing the edge (1, 3):\n";
    g.printGraph();

    return 0;
}
