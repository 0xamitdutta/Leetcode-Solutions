class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1) return true;
        unordered_map<char, int> hash;
        for(int i = 0; i < order.size(); i++)
            hash[order[i]] = i;
        for(int i = 0; i < words.size() - 1; i++) {
            if(compare(words[i], words[i+1], hash) > 0) return false;
        }
        return true;
    }
    
    int compare(string& A, string& B, unordered_map<char, int>& hash) {
        int m = A.size(), n = B.size();
        int l = min(m, n);
        for(int i = 0; i < l; i++) {
            int a = hash[A[i]];
            int b = hash[B[i]];
            if(a != b) 
                return a - b;
        }
        return m == l ? -1 : 1;
    }
};
