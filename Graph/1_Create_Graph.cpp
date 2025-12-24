#include <bits/stdc++.h>
using namespace std;

/* ---------- Create Graph using Adjacency List ---------- */
void createAdjList(int V, int E, vector<vector<int>> &adj, bool directed) {
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }
}

/* ---------- Create Graph using Adjacency Matrix ---------- */
void createAdjMatrix(int V, int E, vector<vector<int>> &mat, bool directed) {
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        if (!directed)
            mat[v][u] = 1;
    }
}

/* ---------- Print Adjacency List ---------- */
void printAdjList(vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int adjacentNode : adj[i])
            cout << adjacentNode << " ";
        cout << "\n";
    }
}

/* ---------- Print Adjacency Matrix ---------- */
void printAdjMatrix(vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    bool directed = false; // change to true for directed graph

    vector<vector<int>> adj(V);
    vector<vector<int>> mat(V, vector<int>(V, 0));

    cout << "Enter edges (u v):\n";
    createAdjList(V, E, adj, directed);
    cout << "\nAdjacency List:\n";
    printAdjList(adj);

    //cin.clear(); cin.seekg(0, ios::beg); // reset input if needed


    //cout << "Enter edges (u v):\n";
    // cout << "\nAdjacency Matrix:\n";
    // createAdjMatrix(V, E, mat, directed);
    // printAdjMatrix(mat);

    return 0;
}
