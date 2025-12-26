#include <bits/stdc++.h>
using namespace std;

/* ============================================================
   1) UNDIRECTED GRAPH — CYCLE DETECTION (BFS)
   ============================================================ */
bool cycleUndirectedBFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            queue<pair<int,int>> q;   // {node, parent}
            q.push({i, -1});
            vis[i] = 1;

            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push({it, node});
                    }
                    else if (it != parent) {
                        return true; // cycle found
                    }
                }
            }
        }
    }
    return false;
}

/* ============================================================
   2) UNDIRECTED GRAPH — CYCLE DETECTION (DFS)
   ============================================================ */
bool dfsUndirected(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsUndirected(it, node, adj, vis)) return true;
        }
        else if (it != parent) {
            return true; // cycle
        }
    }
    return false;
}

bool cycleUndirectedDFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsUndirected(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

/* ============================================================
   3) DIRECTED GRAPH — CYCLE DETECTION (DFS + pathVis)
   ============================================================ */
bool dfsDirected(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsDirected(it, adj, vis, pathVis)) return true;
        }
        else if (pathVis[it]) {
            return true; // back-edge
        }
    }

    pathVis[node] = 0;
    return false;
}

bool cycleDirectedDFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0), pathVis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsDirected(i, adj, vis, pathVis)) return true;
        }
    }
    return false;
}

/* ============================================================
   4) DIRECTED GRAPH — CYCLE DETECTION (BFS / KAHN'S ALGO)
   ============================================================ */
bool cycleDirectedBFS(int V, vector<int> adj[]) {
    vector<int> indeg(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) indeg[it]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indeg[i] == 0) q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cnt++;

        for (auto it : adj[node]) {
            indeg[it]--;
            if (indeg[it] == 0) q.push(it);
        }
    }

    return cnt != V; // if topo sort not possible → cycle
}

/* ============================================================
   MAIN (sample usage)
   ============================================================ */
int main() {

    // ---------- Undirected Graph ----------
    int V1 = 4;
    vector<int> undirected[V1];
    undirected[0] = {1};
    undirected[1] = {0, 2};
    undirected[2] = {1, 3};
    undirected[3] = {2};

    cout << cycleUndirectedBFS(V1, undirected) << "\n";
    cout << cycleUndirectedDFS(V1, undirected) << "\n";

    // ---------- Directed Graph ----------
    int V2 = 4;
    vector<int> directed[V2];
    directed[0] = {1};
    directed[1] = {2};
    directed[2] = {3};
    directed[3] = {1};

    cout << cycleDirectedDFS(V2, directed) << "\n";
    cout << cycleDirectedBFS(V2, directed) << "\n";

    return 0;
}
