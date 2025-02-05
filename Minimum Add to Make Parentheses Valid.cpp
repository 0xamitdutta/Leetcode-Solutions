class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int extraClosing = 0;
        for(char& c : s) {
            if(c == '(')
                stk.push(c);
            else if(c == ')'){
                if(!stk.empty())
                    stk.pop();
                else
                    extraClosing++;
            }
        }
        return stk.size() + extraClosing;
    }
};
