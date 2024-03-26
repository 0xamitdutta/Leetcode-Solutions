/*
 Explanation on Comparator of PQ : 
 https://leetcode.com/problems/top-k-frequent-words/discuss/1274279/CPP-or-C%2B%2B-or-priority-queue-or-Custom-Comparator-and-Solution-Explain-oror-O(nLogk)-Solution
*/

#define PIS pair<int, string> 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(string word : words) 
            m[word]++;
        
        priority_queue<PIS, vector<PIS>, Comparator> pq;
        for(auto [key, value] : m) {
            pq.push({value, key});
            if(pq.size() > k)
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

    struct Comparator {
        /* 
            The comparison is done from bottom to top.
            a.first > b.first means the higher frequency will be at bottom
            a.second < b.second means the lexicographically smaller string will be at bottom
        */
        bool operator()(const PIS& a,const PIS& b) {
            if(a.first == b.first) 
                return a.second < b.second;
            return a.first > b.first;
        }
    };
};

