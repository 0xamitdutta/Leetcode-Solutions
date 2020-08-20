class Solution {
public:
    vector<int> res;
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for(int i = 1; i < 10; i++)
            dfs(N-1, K, i);
        return res;
    }
    
    void dfs(int N, int K, int num){
        if(N == 0){
            res.push_back(num);
            return;
        }
        int last_digit = num % 10;
        vector<int> next_digit = {last_digit+K};
        // To avoid duplicates when K == 0 cuz num + K == num - K
        if(K != 0)
            next_digit.push_back(last_digit-K);
        for(auto digit : next_digit){
            if(digit >= 0 && digit < 10){
                int new_num = num*10 + digit;
                dfs(N-1, K, new_num);
            }
        }
    }
};
