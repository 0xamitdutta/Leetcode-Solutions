class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        int curr_pow = 1;
        for(int i = 1; i <= num; i++){
            if(curr_pow * 2 == i)
                curr_pow *= 2;
            dp[i] = dp[i-curr_pow]+1;
        }
        return dp;
    }
};

/*  Look at the pattern:
    
    Indexes : 0 1 2 3 4 5 6 7 8 9 10 11
    num:      0 1 1 2 1 2 2 3 1 2 2  3
              ----- --- ----- -------
    
    Basically dp[n] = dp[n - power] where power = nearest power of 2 <= n
*/
