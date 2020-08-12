/* https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if(k == 0) return 0;
        
        unordered_map<char, int> m;
        int res = 0, counter = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            m[s[j]]++;
            if(m[s[j]] == 1) 
                counter++;
            j++;
            while(counter > k){
                m[s[i]]--;
                if(m[s[i]] == 0) 
                    counter--;
                i++;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
