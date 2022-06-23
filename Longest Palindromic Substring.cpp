class Solution {
public:
    int start, len = 0;
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            extend(s, i, i);   // For the case aba
            extend(s, i, i+1); // For the case abba
        }
        return s.substr(start, len);
    }
    
    void extend(string& s, int j, int i){
        while(j >= 0 && i < s.size() && s[j] == s[i]){
            j--; i++;
        }
        if(i-j-1 > len){
            start = j+1;
            len = i-j-1;
        }
    }
};
