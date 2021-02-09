/* https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if(k == 0) return 0;
        
        unordered_map<char, int> hash;
        int len = 0, distinct = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            if(!hash[s[i]])
                distinct++;
            hash[s[i]]++;
            while(distinct > k){
                hash[s[j]]--;
                if(hash[s[j]] == 0)
                    distinct--;
                j++;
            }
            len = max(len, i-j+1);
        }
        return len;
    }
};
