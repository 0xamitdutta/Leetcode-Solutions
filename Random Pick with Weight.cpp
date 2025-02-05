class Solution {
public:
    vector<int> cumSum;
    Solution(vector<int>& w) {
        cumSum.push_back(w[0]);
        for(int i = 1; i < w.size(); i++)
            cumSum.push_back(cumSum.back() + w[i]);
    }
    
    int pickIndex() {
        // rand() returns [0, sum-1] but we want the range to be [1, x]. Hence added +1 at end.
        int randNum = rand() % cumSum.back() + 1;
        return lower_bound(cumSum.begin(), cumSum.end(), randNum) - cumSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
