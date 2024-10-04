class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y)
            return false;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({0, 0});
        while(!q.empty()) {
            auto p = q.front();
            int a = p.first, b = p.second;
            q.pop();
            if(a + b == target)
                return true;

            vector<pair<int, int>> states;
            states.push_back({x, b}); // Fill jug x
            states.push_back({a, y}); // Fill jug y
            states.push_back({0, b}); // Empty jug x
            states.push_back({a, 0}); // Empty jug y
            states.push_back({a - min(a, y - b), b + min(a, y - b)}); // Transfer x to y
            states.push_back({a + min(b, x - a), b - min(b, x - a)}); // Transfer y to x
            for(auto& state : states) {
                if(!visited.count(state)) {
                    q.push(state);
                    visited.insert(state);
                }
            }
        }
        return false;
    }
};
