class Solution {
public:
    unordered_map<string, multiset<string>> connections; // For lexicographically choosing the next airport
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket : tickets){
            connections[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(string dep){
        // Greedily choose the next and then retract
        while(!connections[dep].empty()){
            string next = *connections[dep].begin();
            connections[dep].erase(connections[dep].begin());
            dfs(next);
        }
        res.push_back(dep);
    }
};
