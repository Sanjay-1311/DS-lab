#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int numVertices;
    list<int> *adjList;

    bool isValid(int v);
    bool edgeExists(int u, int v);

public:
    Graph(int vertices);
    ~Graph();
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    void searchEdge(int u, int v);
    void display();
};


int main() {
    int vertices, choice;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int u, v;

        switch (choice) {
            case 1:
                cout << "Enter two vertices to insert an edge (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;

            case 2:
                cout << "Enter two vertices to delete an edge (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;

            case 3:
                cout << "Enter two vertices to search an edge (u v): ";
                cin >> u >> v;
                g.searchEdge(u, v);
                break;

            case 4:
                g.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// ---------- FUNCTION DEFINITIONS AFTER MAIN ----------

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList = new list<int>[numVertices];
}

Graph::~Graph() {
    delete[] adjList;
}

bool Graph::isValid(int v) {
    return (v >= 0 && v < numVertices);
}

bool Graph::edgeExists(int u, int v) {
    for (int neighbor : adjList[u]) {
        if (neighbor == v) return true;
    }
    return false;
}

void Graph::insertEdge(int u, int v) {
    if (isValid(u) && isValid(v)) {
        if (!edgeExists(u, v)) {
            adjList[u].push_back(v);
            adjList[v].push_back(u); // Undirected graph
            cout << "Edge inserted between " << u << " and " << v << ".\n";
        } else {
            cout << "Edge already exists!\n";
        }
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::deleteEdge(int u, int v) {
    if (isValid(u) && isValid(v)) {
        adjList[u].remove(v);
        adjList[v].remove(u);
        cout << "Edge deleted between " << u << " and " << v << ".\n";
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::searchEdge(int u, int v) {
    if (isValid(u) && isValid(v)) {
        if (edgeExists(u, v)) {
            cout << "Edge exists between " << u << " and " << v << ".\n";
        } else {
            cout << "No edge exists between " << u << " and " << v << ".\n";
        }
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::display() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " -> ";
        }
        cout << "NULL\n";
    }
}
