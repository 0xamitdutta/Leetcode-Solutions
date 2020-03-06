class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(n == 0)
            return "";
        
        string prefix = s[0];
        for(int i = 0; i < n; i++){
            prefix = comp(prefix, s[i]);
        }
        return prefix;
    }
    
    string comp(string& s1, string& s2){
        string prefix = "";
        for(int i = 0, j = 0; i < s1.size(), j < s2.size(); i++, j++){
            if(s1[i] == s2[j])
                prefix.push_back(s1[i]);
            else
                break;
        }
        return prefix;
    }
};
