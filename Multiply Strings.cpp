class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        // Multiplation without caring about carry
        vector<int> res(num1.size()+num2.size()); // Product size is max : m+n and min : m+n-1
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                res[i+j] += (num1[num1.size()-1-i]-'0')*(num2[num2.size()-1-j]-'0');
            }
        }
        // Handle the carry here
        int carry = 0;
        for(int i = 0; i < res.size(); i++){
            int sum = res[i]+carry;
            res[i] = sum%10;
            carry = sum/10;
        }
        
        string ans = "";
        if(res.back() != 0)
            ans.push_back(res.back()+'0');
        for(int i = res.size()-2; i >= 0; i--)
            ans.push_back(res[i]+'0');
        return ans;
    }
};
