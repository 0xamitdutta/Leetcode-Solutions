// https://www.lintcode.com/problem/longest-substring-with-at-most-two-distinct-characters/description
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        unordered_map<char, int> hash;
        
        int len = 0, distinct = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            if(!hash[s[i]])
                distinct++;
            hash[s[i]]++;
            while(distinct > 2){
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
