class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        vector<int> dp(s.size() + 1); // dp[i] represents no. of ways to decode string of length i
        dp[0] = 1; // Assume 1 considering case s.size() = 2. Eg : "12" and we take dp[i] += dp[i-2] when i = 2
        dp[1] = 1; // For 1 char only
        for(int i = 2; i <= s.size(); i++){
            int oneDigit = stoi(s.substr(i-1, 1)); // Take the current digit
            int twoDigit = stoi(s.substr(i-2, 2)); // Take the current and previous digit
            
            if(oneDigit >= 1){
                dp[i] += dp[i-1];
            }
            if(twoDigit >= 10 && twoDigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
