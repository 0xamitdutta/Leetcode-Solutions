class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums)
            m[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto& [key, val] : m){
            pq.push({val, key});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
