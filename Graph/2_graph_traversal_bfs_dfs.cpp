#include <bits/stdc++.h>
using namespace std;

/* 1) DFS using Adjacency List */
void dfsList(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    cout << node << " ";
    for (int adjacentNode : adj[node]) {
        if (!vis[adjacentNode]) {
            dfsList(adjacentNode, adj, vis);
        }
    }
}

/* 2) DFS using Adjacency Matrix */
void dfsMatrix(int node, vector<vector<int>> &mat, vector<bool> &vis) {
    vis[node] = true;
    cout << node << " ";
    for (int j = 0; j < mat.size(); j++) {
        if (mat[node][j] == 1 && !vis[j]) {
            dfsMatrix(j, mat, vis);
        }
    }
}

/* 3) BFS using Adjacency List */
void bfsList(int start, vector<vector<int>> &adj, vector<bool> &vis) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                vis[adjacentNode] = true;
                q.push(adjacentNode);
            }
        }
    }
}

/* 4) BFS using Adjacency Matrix */
void bfsMatrix(int start, vector<vector<int>> &mat, vector<bool> &vis) {
    int n = mat.size();
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int j = 0; j < n; j++) {
            if (mat[node][j] == 1 && !vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }
}

int main() {
    int V = 7;

    // Adjacency List (Disconnected)
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {0, 2};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {3};
    // 5 and 6 are isolated nodes

    // Adjacency Matrix (Disconnected)
    vector<vector<int>> mat = {
        {0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };

    // -------- DFS List (Disconnected) --------
    cout << "DFS using List: ";
    vector<bool> vis1(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis1[i]) {
            dfsList(i, adj, vis1);
        }
    }
    cout << "\n";

    // -------- DFS Matrix (Disconnected) --------
    cout << "DFS using Matrix: ";
    vector<bool> vis2(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis2[i]) {
            dfsMatrix(i, mat, vis2);
        }
    }
    cout << "\n";

    // -------- BFS List (Disconnected) --------
    cout << "BFS using List: ";
    vector<bool> vis3(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis3[i]) {
            bfsList(i, adj, vis3);
        }
    }
    cout << "\n";

    // -------- BFS Matrix (Disconnected) --------
    cout << "BFS using Matrix: ";
    vector<bool> vis4(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis4[i]) {
            bfsMatrix(i, mat, vis4);
        }
    }
    cout << "\n";

    return 0;
}
