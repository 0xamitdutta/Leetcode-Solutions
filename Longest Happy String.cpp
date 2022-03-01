class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        if(a != 0) pq.push({a, 'a'}); if(b != 0) pq.push({b, 'b'}); if(c != 0) pq.push({c, 'c'});
        
        while(!pq.empty()) {
            int count1 = pq.top().first;
            char char1 = pq.top().second;
            pq.pop();
            if(res.size() > 1 && res[res.size()-1] == res[res.size()-2] && res[res.size()-1] == char1) {
                if(pq.empty()) break;
                int count2 = pq.top().first;
                char char2 = pq.top().second;
                pq.pop();
                res += char2;
                count2--;
                if(count2) pq.push({count2, char2});
            } else {
                res += char1;
                count1--;
            }
            
            if(count1) pq.push({count1, char1});
        }
        return res;
    }
};
