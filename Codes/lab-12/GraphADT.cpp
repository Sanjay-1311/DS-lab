#include <iostream>
using namespace std;

class Graph {
private:
    int **adjMatrix;
    int numVertices;
    bool isValid(int u, int v);   // This line moved up into same private section

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
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::insertEdge(int u, int v) {
    if (isValid(u, v)) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Undirected graph
        cout << "Edge inserted between " << u << " and " << v << ".\n";
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::deleteEdge(int u, int v) {
    if (isValid(u, v)) {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0; // Undirected graph
        cout << "Edge deleted between " << u << " and " << v << ".\n";
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::searchEdge(int u, int v) {
    if (isValid(u, v)) {
        if (adjMatrix[u][v] == 1) {
            cout << "Edge exists between " << u << " and " << v << ".\n";
        } else {
            cout << "No edge exists between " << u << " and " << v << ".\n";
        }
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Graph::isValid(int u, int v) {
    return (u >= 0 && u < numVertices && v >= 0 && v < numVertices);
}