#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// A structure to represent a node in the priority queue
struct Node {
    long long weight;
    int vertex;
    bool operator>(const Node& other) const {
        return weight > other.weight;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<long long> vertexWeights(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> vertexWeights[i];
    }
    
    vector<vector<pair<int, long long>>> adj(N+1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        adj[U].emplace_back(V, B);
        adj[V].emplace_back(U, B);
    }
    
    // Dijkstra's algorithm
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<long long> minDist(N+1, numeric_limits<long long>::max());
    
    minDist[1] = vertexWeights[1];
    pq.push({vertexWeights[1], 1});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int u = current.vertex;
        long long distU = current.weight;
        
        if (distU > minDist[u]) continue;
        
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            long long weightUV = neighbor.second;
            long long newDist = distU + weightUV + vertexWeights[v];
            
            if (newDist < minDist[v]) {
                minDist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    for (int i = 2; i <= N; ++i) {
        cout << minDist[i] << " ";
    }
    cout << endl;
    
    return 0;
}
