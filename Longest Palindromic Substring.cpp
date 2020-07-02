class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;                 //start marks the 'start' of string and end marks the 'end' of string
        for(int i = 0; i < s.size(); i++){
            int p1 = palindrome(s, i, i);       // For the Case : abba(even)
            int p2 = palindrome(s, i, i+1);     // For the Case : aba(odd)
            int len = max(p1, p2);
            if(len > end - start + 1){
                start = i - (len-1)/2;
                end = i + len/2;
            } 
        }
        return s.substr(start, end - start + 1);//substr takes 2 parameters : 1. Start of the string 2. Length
    }
    
    int palindrome(string s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--; j++;
        }
        return j-i-1;
    }
};
