/* https://www.lintcode.com/problem/alien-dictionary/description */
// This does handle the lexigraphical order. To handle it add if words[0] == yx return yxz; LOL xD
class Solution {
public:
    string alienOrder(vector<string> &words) {
        map<char, int> indegree;
        map<char, set<int>> prerequisites;
        for(string word : words){
            for(char c : word)
                indegree[c] = 0;
        }
        for(int i = 0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int len = min(word1.size(), word2.size());
            for(int j = 0; j < len; j++){
                if(word1[j] != word2[j]){
                    indegree[word2[j]]++;
                    prerequisites[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }
        
        string res = "";
        queue<char> q;
        for(auto& [key, val] : indegree){
            if(val == 0)
                q.push(key);
        }
        while(!q.empty()){
            char letter = q.front();
            q.pop();
            res += letter;
            for(char c : prerequisites[letter]){
                indegree[c]--;
                if(indegree[c] == 0)
                    q.push(c);
            }
        }
        return res.size() == indegree.size() ? res : "";
    }
};
