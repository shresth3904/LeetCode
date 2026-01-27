class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges_in) {
        vector<vector<pair<int, int>>> edges(n);
        for (auto& i: edges_in){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            edges[u].push_back({v, w});
            edges[v].push_back({u, 2*w});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);

        dist[0] = 0;
        pq.push({dist[0], 0});

        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if (curr.first > dist[curr.second]) continue;
            for (auto& i: edges[curr.second]){
                if (dist[i.first] > dist[curr.second] + i.second){
                    dist[i.first] = dist[curr.second] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        return (dist[n-1] == INT_MAX)? -1: dist[n-1];


    }
};