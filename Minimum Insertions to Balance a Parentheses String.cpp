class Solution {
public:
    int minInsertions(string s) {
        stack<char> stk;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                stk.push('(');
            else{
                // "())..."
                if(!stk.empty() && i < s.size()-1 && s[i+1] == ')'){
                    stk.pop();
                    i++;
                }
                // "...()" or "()())..."
                else if(!stk.empty() && (i == s.size() || s[i+1] != ')')){
                    count++;
                    stk.pop();
                }
                // "))..."
                else if(stk.empty() && i < s.size()-1 && s[i+1] == ')'){
                    count++;
                    i++;
                }
                // ")())..."
                else
                    count += 2;
            }
        }
        // If there are any opening brackets left
        while(!stk.empty()){
            count += 2;
            stk.pop();
        }
        return count;
    }
};
