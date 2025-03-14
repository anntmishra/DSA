#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
int V;
vector<vector<pair<int, int>>> adj;

public:
Graph(int vertices) : V(vertices) {
adj.resize(V);
}

void addEdge(int u, int v, int w) {
adj[u].push_back({v, w});
adj[v].push_back({u, w});
}

bool isPrimMST(vector<pair<int, int>>& mstEdges) {
vector<bool> visited(V, false);
priority_queue<pair<int, pair<int, int>>, 
vector<pair<int, pair<int, int>>>, 
greater<pair<int, pair<int, int>>>> pq;

int totalCost = 0;
int startVertex = 0;
visited[startVertex] = true;

for(auto edge : adj[startVertex]) {
pq.push({edge.second, {startVertex, edge.first}});
}

while(!pq.empty()) {
int weight = pq.top().first;
int u = pq.top().second.first;
int v = pq.top().second.second;
pq.pop();

if(visited[v]) continue;

visited[v] = true;
totalCost += weight;
mstEdges.push_back({u, v});

for(auto edge : adj[v]) {
if(!visited[edge.first]) {
pq.push({edge.second, {v, edge.first}});
}
}
}

for(bool v : visited) {
if(!v) return false;
}

return true;
}
};

int main() {
int N, M;
cin >> N >> M;

Graph g(N);

for(int i = 0; i < M; i++) {
int u, v, w;
cin >> u >> v >> w;
g.addEdge(u, v, w);
}

vector<pair<int, int>> mstEdges;

if(g.isPrimMST(mstEdges)) {
cout << "Graph is fully connected. Minimum Spanning Tree (MST) edges:" << endl;
for(const auto& edge : mstEdges) {
cout << edge.first << " -- " << edge.second << endl;
}
} else {
cout << "The graph is not fully connected." << endl;
}

return 0;
}
