class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else{
                if(c == ')'){
                    if(!stk.empty() && stk.top() == '(')
                        stk.pop();
                    else
                        return false;
                }
                else if(c == '}'){
                    if(!stk.empty() && stk.top() == '{')
                        stk.pop();
                    else
                        return false;
                }
                else if(c == ']'){
                    if(!stk.empty() && stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                }
            }
        }
        if(stk.empty() == true)
            return true;
        return false;
    }
};
