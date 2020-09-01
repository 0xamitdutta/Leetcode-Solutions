class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() == 0) return num2;
        if(num2.size() == 0) return num1;
        
        string res = "";
        int carry = 0;
        int p1 = num1.size()-1, p2 = num2.size()-1;
        while(p1 >= 0 || p2 >= 0 || carry){
            int sum = 0;
            if(p1 >= 0){
                sum += num1[p1]-'0';
                p1--;
            }
            if(p2 >= 0){
                sum += num2[p2] - '0';
                p2--;
            }
            sum += carry;
            carry = sum/10;
            res.push_back((sum%10)+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
