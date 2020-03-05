class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        int count = 0;
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return isValid(s, i+1, j) || isValid(s, i, j-1);
            }
        }
        return true;
    }
    
    bool isValid(string& s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else
                return false;
        }
        return true;
    }
};
