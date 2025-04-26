#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // (vertex, weight)
    vector<tuple<int, int, int>> edges;     // (weight, u, v) for Kruskal

    bool isValid(int v);

public:
    Graph(int vertices);
    void insertEdge(int u, int v, int weight);
    void primMST();
    void kruskalMST();
    void dijkstra(int start);
};

// ---------- MAIN STARTS IMMEDIATELY AFTER CLASS ----------
int main() {
    int vertices, choice;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Prim's Algorithm (MST)\n";
        cout << "3. Kruskal's Algorithm (MST)\n";
        cout << "4. Dijkstra's Algorithm\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int u, v, w, start;

        switch (choice) {
            case 1:
                cout << "Enter two vertices and weight (u v weight): ";
                cin >> u >> v >> w;
                g.insertEdge(u, v, w);
                break;

            case 2:
                g.primMST();
                break;

            case 3:
                g.kruskalMST();
                break;

            case 4:
                cout << "Enter starting vertex for Dijkstra's algorithm: ";
                cin >> start;
                g.dijkstra(start);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// ---------- FUNCTION DEFINITIONS AFTER MAIN ----------

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList.resize(vertices);
}

bool Graph::isValid(int v) {
    return (v >= 0 && v < numVertices);
}

void Graph::insertEdge(int u, int v, int weight) {
    if (isValid(u) && isValid(v)) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // Undirected
        edges.push_back({weight, u, v});
        cout << "Edge inserted between " << u << " and " << v << " with weight " << weight << ".\n";
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::primMST() {
    vector<bool> visited(numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0;
    pq.push({0, start});
    int totalWeight = 0;

    cout << "\nPrim's MST Edges:\n";

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += weight;

        cout << "Visited Vertex: " << u << " with Edge Weight: " << weight << endl;

        for (auto [v, w] : adjList[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
}

int findParent(vector<int>& parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent, parent[u]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end()); // Sort by weight
    vector<int> parent(numVertices), rank(numVertices, 0);

    for (int i = 0; i < numVertices; ++i) {
        parent[i] = i;
    }

    int totalWeight = 0;

    cout << "\nKruskal's MST Edges:\n";

    for (auto &[weight, u, v] : edges) {
        if (findParent(parent, u) != findParent(parent, v)) {
            cout << u << " -- " << v << " == " << weight << endl;
            totalWeight += weight;
            unionSets(parent, rank, u, v);
        }
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
}

void Graph::dijkstra(int start) {
    vector<int> dist(numVertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto [v, w] : adjList[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Distances from vertex " << start << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << " : ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << endl;
    }
}
