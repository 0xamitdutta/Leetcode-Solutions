class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // Adjacency List where, key = Stop No. and Value = Route No. that contains that stop
        unordered_map<int, unordered_set<int>> m;
        for(int i = 0; i < routes.size(); i++) {
            for(int stop : routes[i]) {
                m[stop].insert(i);
            }
        }
        // BFS
        queue<pair<int, int>> q; // First value = Stop No. and Second value = Count of buses till now
        unordered_set<int> s;    // Set contains route no. so that well.
        q.push({S, 0});
        while(!q.empty()) {
            int stop = q.front().first;
            int bus = q.front().second;
            q.pop();
            if(stop == T) return bus;
            for(int route : m[stop]) {
                if(!s.count(route)) {
                    for(int stopage : routes[route]) {
                        q.push({stopage, bus+1});
                    }
                }
                s.insert(route);
            }
        }
        return -1;
    }
};
