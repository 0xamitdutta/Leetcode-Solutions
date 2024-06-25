class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> G;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1, INT_MAX);
        for(auto time : times) {
            int a = time[0], b = time[1], t = time[2];
            G[a].push_back({b, t});
        }
        distance[k] = 0;
        dijkstra(distance, k);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
    
    void dijkstra(vector<int>& distance, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int v = node.second;
            for(auto nbr : G[v]) {
                int nv = nbr.first, nd = nbr.second;
                if(distance[v] + nd < distance[nv]) {
                    distance[nv] = distance[v] + nd;
                    pq.push({distance[nv], nv});
                }
            }
        }
    }
};
