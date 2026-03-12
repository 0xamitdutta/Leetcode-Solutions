class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(string& word : words) 
            m[word]++;
        
        // comp(a, b) == true means a has LOWER priority than b
        auto comp = [&](string& a, string& b){
            if(m[a] == m[b])
                return a < b;
            return m[a] > m[b];
        };

        priority_queue<string, vector<string>, decltype(comp)> pq(comp);
        for(auto& [word, _] : m) {
            pq.push(word);
            if(pq.size() > k) 
                pq.pop();
        }
        vector<string> res(k);
        for(int i = k-1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};
