class Solution {
public:
    int partitionString(string str) {
        int count = 1;
        unordered_set<char> s;
        for(int i = 0; i < str.size(); i++) {
            if(s.count(str[i])) {
                count++;
                s.clear();
            }
            s.insert(str[i]);
        }
        return count;
    }
};
