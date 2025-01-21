class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                stk.push({s[i], i});
            if(s[i] == ')') {
                if(!stk.empty() && stk.top().first == '(')
                    stk.pop();
                else
                    stk.push({s[i], i});
            }
        }
        unordered_set<int> indexes;
        while(!stk.empty()) {
            indexes.insert(stk.top().second);
            stk.pop();
        }   
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(!indexes.count(i))
                res += s[i];
        }
        return res;
    }
};
