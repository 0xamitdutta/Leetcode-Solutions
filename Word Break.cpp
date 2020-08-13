class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        
        // dp[i] represents whether string ending with char i can be segmented
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && us.count(s.substr(j, i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
