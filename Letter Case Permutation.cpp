class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        letterPermutations(res, S, 0);
        return res;
    }
    
    void letterPermutations(vector<string>& res, string&S, int index){
        res.push_back(S);
        for(int i = index; i < S.size(); i++){
            if(isalpha(S[i])){
                // In ASCII diff b/w 'A' and 'a' is 32 which 1<<5. Hence we need to toggle that bit only for case conversion
                S[i] ^= (1 << 5);
                letterPermutations(res, S, i+1);
                
                // After choosing don't forget to unchoose it
                S[i] ^= (1 << 5);
            }
        }
    }
};
