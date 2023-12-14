class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < parents.size(); i++) 
            graph[parents[i]].push_back(i);
        
        int totalNodes = parents.size();
        unordered_map<long long, int> res;
        // Product of leftNodes, rightNodes and topNodes starting from node 0
        dfs(0, graph, totalNodes, res);

        long long highestKey = 0;
        for(auto& [key, val] : res) 
            highestKey = max(highestKey, key);
        return res[highestKey];
    }

    int dfs(int node, unordered_map<int, vector<int>>& graph, int& totalNodes, unordered_map<long long, int>& res) {
        long long sumNodes = 0, prodNodes = 1;
        for(int child : graph[node]) {
            int count = dfs(child, graph, totalNodes, res);
            prodNodes *= count;
            sumNodes += count;
        }
        prodNodes *= max(1*1LL, totalNodes - 1 - sumNodes);
        res[prodNodes] += 1;
        return sumNodes + 1;
    }
};
