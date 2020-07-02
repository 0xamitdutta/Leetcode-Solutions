// O(n^2)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        while(k--){
            for(i = 0; i < num.size()-1; i++){
                if(num[i] > num[i+1])
                    break;
            }
            num.erase(num.begin()+i);
        }
        while(num.size() > 0 && num[0] == '0')
            num.erase(num.begin());
        return num.size() > 0 ? num : "0";
    }
};

// O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        
        stack<char> s;
        for(char c : num){
            while(!s.empty() && s.top() > c && k > 0){
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        // In case the string is ascending partially or wholly
        while(k > 0){
            s.pop();
            k--;
        }
        
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        
        // Nice trick to remove starting zeroes
        while(res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
