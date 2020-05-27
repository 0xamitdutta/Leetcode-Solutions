/* https://www.lintcode.com/problem/alien-dictionaryeasy/description */
class Solution {
public:
    bool isAlienSorted(vector<string> &words, string &order) {
        if(words.size() == 0 || words.size() == 1) return words.size();
        
        unordered_map<char, int> m;
        for(int i = 0; i < order.size(); i++)
            m[order[i]] = i+1;
        for(int i = 0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int len = min(word1.size(), word2.size());
            for(int j = 0; j < len; j++){
                if(m[word1[j]] < m[word2[j]]) break;
                else if(m[word1[j]] == m[word2[j]]) continue;
                else return false;
            }
        }
        return true;
    }
};
