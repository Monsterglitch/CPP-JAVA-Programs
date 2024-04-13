#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        // Build adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        // s = src, d = dst, w = weight
        for (vector<int>& edge : edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }

        // Compute shortest paths
        unordered_map<int, int> shortest;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first, n1 = curr.second;

            if (shortest.find(n1) != shortest.end()) continue;
            shortest[n1] = w1;

            for (pair<int, int>& edge : adj[n1]) {
                int n2 = edge.first, w2 = edge.second;
                if (shortest.find(n2) == shortest.end()) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        // Fill in missing nodes
        for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }

        return shortest;
    }


int main()
{
    int n = 5, src = 0;
    vector<vector<int>> edges{{{0,1,1}, {0,2,3}, {1,3,2}, {2,1,4}, {2,3,8}, {2,4,2}, {3,4,5}}};
    unordered_map<int, int> res = shortestPath(n, edges, src);
    for (auto i : res)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
    return 0;
}