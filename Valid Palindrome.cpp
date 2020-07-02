class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0)
            return true;
        
        int i = 0, j = n-1;
        while(i < j){
            if(!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))){
                i++;
                continue;
            }
            if(!((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122) || (s[j] >= 48 && s[j] <= 57))){
                j--;
                continue;
            }
            int c1 = tolower(s[i]);
            int c2 = tolower(s[j]);
            if(c1 != c2)
                return false;
            
            i++; j--;
        }
        return true;
    }
};
