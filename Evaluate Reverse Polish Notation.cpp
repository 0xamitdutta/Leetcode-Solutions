class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string& str : tokens) {
            if(str != "+" && str != "-" && str != "*" && str != "/")
                stk.push(stoi(str));
            else {
                string opr = str;
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if(opr == "+") stk.push(a + b);
                if(opr == "-") stk.push(a - b);
                if(opr == "*") stk.push(a * b);
                if(opr == "/") stk.push(a / b);
            }
        }
        return stk.top();
    }
};
