class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> hash_map;
        for(int i = 0; i < cards.size(); i++) {
            hash_map[cards[i]].push_back(i);
        }
        int res = INT_MAX;
        for(auto& [key, val] : hash_map) {
            vector<int> values = val;
            for(int i = 0; i < values.size() - 1; i++) {
                res = min(res, values[i+1] - values[i] + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
