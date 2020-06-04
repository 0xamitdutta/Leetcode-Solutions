class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        int sum = 0;
        int n = 0;
        for(auto cost : costs){
            int f = cost[0];
            int s = cost[1];
            if(n < costs.size()/2) sum += f;
            else sum += s;
            n++;
        }
        return sum;
    }
    
    // Sorting based on savings. We want max savings first i.e a[1] - a[0] > b[1] - b[0]
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] - a[0] > b[1] - b[0];
    }
};
