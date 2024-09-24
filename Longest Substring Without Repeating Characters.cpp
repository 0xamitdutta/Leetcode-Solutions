// Easier version but not optimal to use .erase() method. It has O(1) as best and average case but it is O(N) in worst case
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j = 0, res = 0;
        unordered_set<char> hash_set;
        for(i = 0; i < s.size(); i++) {
            while(hash_set.count(s[i])) {
                hash_set.erase(s[j]);
                j++;
            }
            hash_set.insert(s[i]);
            res = max(res, i-j+1);
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size() == 0) return 0;
        
        unordered_map<char, int> hash;
        int len = 0;
        for(int i = 0, j = 0; i < str.size(); i++){
            if(hash.count(str[i])){
                j = max(j, hash[str[i]]+1);
            }
            hash[str[i]] = i;
            len = max(len, i-j+1);
        }
        return len;
    }
};

/*
Keep a hashmap which stores the characters in string as keys and their positions as values, and keep two pointers which define the max substring. move the right pointer to scan through the string , and meanwhile update the hashmap. If the character is already in the hashmap, then move the left pointer to the right of the same character last found. 
Note that the two pointers can only move forward (especially don't forget that j = max(j, hash[str[i]]) so that j only goes forward).
*/
