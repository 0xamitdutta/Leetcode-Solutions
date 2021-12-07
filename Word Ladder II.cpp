class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Create a queue of vector<string> instead of normal strings. Also make sure to erase strings after a certain level has been traversed not immediately.
        set<string> notSeen(wordList.begin(), wordList.end());
        set<string> vis;
        if(!notSeen.count(endWord)) return {};
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<vector<string>> res;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto curList = q.front();
                q.pop();
                string cur = curList.back();
                for(int j = 0; j < cur.size(); j++) {
                    char curChar = cur[j];
                    for(int k = 0; k < 26; k++) {
                        cur[j] = 'a' + k;
                        if(notSeen.count(cur)) {
                            auto newList = curList;
                            newList.push_back(cur);
                            vis.insert(cur);
                            if(cur == endWord)
                                res.push_back(newList);
                            else 
                                q.push(newList);
                        }
                    }
                    cur[j] = curChar;
                }
            }
            for(auto& str : vis)
                notSeen.erase(str);
        }
        return res;
    }
};
