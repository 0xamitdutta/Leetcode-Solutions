class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        int max_count = 0; //max_count is the count of max similar characters
        int max_len = 0;   //max_len is the length of max string possible
        while(j < s.size()){
            m[s[j]]++;
            max_count = max(max_count, m[s[j]]);
            j++;
            while(j-i-max_count > k){
                m[s[i]]--;
                i++;
            }
            max_len = max(max_len, j-i);
        }
        return max_len;
    }
};

IMP PONINTS:
1. max_count may be invalid at some points, but this doesn't matter, because it was valid earlier in the string, and all that matters is finding the max window that occurred anywhere in the string. Additionally, it will expand if and only if enough repeating characters appear in the window to make it expand. So whenever it expands, it's a valid expansion.

2. When end-start+1-maxCount == 0, then then the window is filled with only one character
When end-start+1-maxCount > 0, then we have characters in the window that are NOT the character that occurs the most. end-start+1-maxCount is equal to exactly the # of characters that are NOT the character that occurs the most in that window. Example: For a window "xxxyz", end-start+1-maxCount would equal 2. (maxCount is 3 and there are 2 characters here, "y" and "z" that are not "x" in the window.)
