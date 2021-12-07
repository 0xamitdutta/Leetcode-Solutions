class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // From the starting string try all possible characters from 'a' to 'z' and see if it is present in the wordList. Then proceed via BFS
        set<string> notSeen(wordList.begin(), wordList.end());
        if(!notSeen.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        
        int wordCount = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for(int j = 0; j < cur.size(); j++) {
                    char curChar = cur[j];
                    for(int k = 0; k < 26; k++) {
                        cur[j] = 'a' + k;
                        if(cur == endWord) 
                            return ++wordCount;
                        if(notSeen.count(cur)) {
                            q.push(cur);
                            notSeen.erase(cur);
                        }
                    }
                    cur[j] = curChar;
                }
            }
            wordCount++;
        }
        return 0;
    }
};
