class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<char, int>>> edges(26);
        int n = original.size();

        for (int i = 0; i < n; i++){
            edges[original[i]-'a'].push_back({changed[i], cost[i]});
        } 

        vector<vector<int>> min_cost(26, vector<int> (26, INT_MAX));

        for (int i = 0; i < 26; i++){
            priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
            pq.push({0, 'a' + i});
            min_cost[i][i] = 0;

            while (!pq.empty()){
                auto top = pq.top();
                pq.pop();

                int dist = top.first;
                char node = top.second;

                if (dist > min_cost[i][node-'a']) continue;

                for (auto& a: edges[node-'a']){
                    if (min_cost[i][a.first-'a'] > a.second + dist){
                        min_cost[i][a.first-'a'] = a.second + dist;
                        pq.push({min_cost[i][a.first - 'a'], a.first});
                    }
                }

            }
        }

        long long total_cost = 0;
        for (int i = 0; i < source.size(); i++){
            if (min_cost[source[i]-'a'][target[i]-'a'] != INT_MAX) total_cost += min_cost[source[i]-'a'][target[i]-'a'];
            else return -1;
        }

        return total_cost;



    }
};