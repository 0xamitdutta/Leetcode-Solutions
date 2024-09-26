/* https://leetcode.com/problems/verifying-an-alien-dictionary/description/ */
class Solution {
public:
    bool isAlienSorted(vector<string> &words, string &order) {
        unordered_map<char, int> hash_map;
        for(int i = 0; i < order.size(); i++)
            hash_map[order[i]] = i;
        for(int i = 0; i < words.size()-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            if(!isValid(word1, word2, hash_map))
                return false;
        }
        return true;
    }

    bool isValid(string& word1, string& word2, unordered_map<char, int>& hash_map) {
        int m = word1.size(), n = word2.size();
        for(int i = 0; i < min(m, n); i++) {
            int pos1 = hash_map[word1[i]], pos2 = hash_map[word2[i]];
            if(pos1 == pos2)
                continue;
            return pos1 < pos2 ? true : false;
        }
        return m <= n ? true : false;
    }
};
