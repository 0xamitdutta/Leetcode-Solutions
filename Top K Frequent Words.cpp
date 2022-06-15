/*
 Explanation on Comparator of PQ : 
 https://leetcode.com/problems/top-k-frequent-words/discuss/1274279/CPP-or-C%2B%2B-or-priority-queue-or-Custom-Comparator-and-Solution-Explain-oror-O(nLogk)-Solution
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int K) {
        map<string, int> m;
        for(auto word : words) m[word]++;
        
        auto comp = [](pair<int, string>& a, pair<int, string>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for(auto [key, val] : m) {
            pq.push({val, key});
            if(pq.size() > K)
                pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
