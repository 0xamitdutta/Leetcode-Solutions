// Link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> G;
        for(auto& time : times) {
            int u = time[0], v = time[1], d = time[2];
            G[u].push_back({v, d});
        }

        vector<int> distances(n+1, INT_MAX);
        distances[k] = 0;
        dijkstra(G, distances, k);
        
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(distances[i] == INT_MAX)
                return -1;
            res = max(res, distances[i]);
        }
        return res;
    }

    void dijkstra(unordered_map<int, vector<pair<int, int>>> G, vector<int>& distances, int& k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto& nbr : G[u]) {
                int v = nbr.first, w = nbr.second;
                if(d + w < distances[v]) {
                    distances[v] = d + w;
                    pq.push({distances[v], v});
                }
            }
        }
    }
};
