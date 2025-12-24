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
void bfsList(int start, vector<vector<int>> &adj) {
    vector<bool> vis(adj.size(), false);
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
void bfsMatrix(int start, vector<vector<int>> &mat) {
    int n = mat.size();
    vector<bool> vis(n, false);
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
    int V = 5;

    // Adjacency List
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Adjacency Matrix
    vector<vector<int>> mat = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,0,1},
        {0,1,0,0,0},
        {0,0,1,0,0}
    };

    cout << "DFS using List: ";
    vector<bool> vis1(V, false);
    dfsList(0, adj, vis1);
    cout << "\n";

    cout << "DFS using Matrix: ";
    vector<bool> vis2(V, false);
    dfsMatrix(0, mat, vis2);
    cout << "\n";

    cout << "BFS using List: ";
    bfsList(0, adj);
    cout << "\n";

    cout << "BFS using Matrix: ";
    bfsMatrix(0, mat);
    cout << "\n";

    return 0;
}
