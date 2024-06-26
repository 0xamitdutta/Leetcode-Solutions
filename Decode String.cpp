class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> stack;
        for(char c : s) {
            if(c != ']')
                stack.push(c);
            else {
                string temp = "";
                while(stack.top() != '[') {
                    temp = stack.top() + temp;
                    stack.pop();
                }
                stack.pop();

                string number = "";
                while(!stack.empty() &&  isdigit(stack.top())) {
                    number = stack.top() + number;
                    stack.pop();
                }
                int num = stoi(number);
                for(int i = 0; i < num; i++) {
                    for(char c : temp)
                        stack.push(c);
                }
            }
        }
        while(!stack.empty()) {
            res = stack.top() + res;
            stack.pop();
        }
        return res;
    }
};
