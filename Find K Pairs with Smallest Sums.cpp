class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                pq.push({nums1[i], nums2[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
    
    // Priority queue has opposite comparators. Lol
    struct comp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first + a.second < b.first + b.second;
        }  
    };
};
