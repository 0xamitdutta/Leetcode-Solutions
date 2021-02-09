class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int max_count = 0;
        int max_len = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            max_count = max(max_count, ++hash[s[i]]);
            if(i-j+1 - max_count > k){
                hash[s[j]]--;
                j++;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};

/*
IMP PONINTS:
1. max_count may be invalid at some points, but this doesn't matter, because it was valid earlier in the string, and all that matters is finding the max window that occurred anywhere in the string. Additionally, it will expand if and only if enough repeating characters appear in the window to make it expand. So whenever it expands, it's a valid expansion.

2. When end-start+1-maxCount == 0, then then the window is filled with only one character
   When end-start+1-maxCount > 0, then we have characters in the window that are NOT the character that occurs the most. end-start+1-maxCount is equal to exactly the # of characters that are NOT the character that occurs the most in that window. 
*/
