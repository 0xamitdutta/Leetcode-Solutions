class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        
        unordered_map<char, int> v;
        for(char c : t)
            v[c]++;
        int i = 0, j = 0, left_i = 0;
        int min_len = INT_MAX, counter = t.size();
        while(j < s.size()){
            if(v[s[j]] > 0) counter--;
            v[s[j]]--;
            j++;
            while(counter == 0){
                if(j-i < min_len){
                    min_len = j-i;
                    left_i = i;
                }
                v[s[i]]++;
                if(v[s[i]] > 0) counter++;
                i++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(left_i, min_len);
    }
};
