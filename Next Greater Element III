class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(!nextPermutation(s)) return -1;
        long long ans = stoll(s);
        return (ans < INT_MAX) ? ans : -1;
    }
    
    bool nextPermutation(string& s){
        int n = s.size();
        if(n == 0)
            return false;
        
        int i = n-1;
        while(i > 0 && s[i-1] >= s[i])
            i--;
        if(i == 0) return false;
        
        int j = n-1;
        while(s[i-1] >= s[j])
            j--;
        swap(s[i-1], s[j]);
        sort(s.begin()+i, s.end());
        return true;
    }
};
