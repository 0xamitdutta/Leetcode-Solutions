class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        // dp[i] represents whether string ending with char i can be segmented
        vector<bool> dp(s.size() + 1);
        
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && hash.count(s.substr(j, i-j))){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
