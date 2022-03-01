class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        for(string str : deadends)
            if(str == "0000") return -1;
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        set<string> vis(deadends.begin(), deadends.end());
        while(!q.empty()) {
            string code = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(code == target) return moves;
            
            for(string str : neighbours(code)) {
                if(!vis.count(str)) {
                    vis.insert(str);
                    q.push({str, moves + 1});
                }
            }
        }
        return -1;
    }
    
    vector<string> neighbours(string code) {
        vector<string> res;
        for(int i = 0; i < 4; i++) {
            string str1 = code, str2 = code;
            str1[i] = ((str1[i] - '0' + 1) % 10) + '0';
            res.push_back(str1);
            str2[i] = ((str2[i] - '0' - 1 + 10) % 10) + '0';
            res.push_back(str2);
        }
        return res;
    }
};
