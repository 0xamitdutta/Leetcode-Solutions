class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string curr_str = "";
        int curr_num = 0;
        for(char c : s){
            if(c == '['){
                chars.push(curr_str);
                nums.push(curr_num);
                curr_str = "";
                curr_num = 0;
            }
            else if(c == ']'){
                int num = nums.top(); nums.pop();
                string prev_str = chars.top(); chars.pop();
                string temp = "";
                for(int i = 0; i < num; i++)
                    temp += curr_str;
                curr_str = prev_str + temp;
            }
            else if(isdigit(c)){
                curr_num = curr_num*10 + (c-'0');
            }
            else if(isalpha(c)){
                curr_str += c;
            }
        }
        return curr_str;
    }
};
