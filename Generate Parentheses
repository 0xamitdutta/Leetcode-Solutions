class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    
    void helper(vector<string>& res, string curr, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(curr);
            return;
        }
        // Right brackets can only be placed when no. of remaining left brackets < np. of remaining right brackets
        if(left > 0)
            helper(res, curr + '(', left-1, right);
        if(right > left)
            helper(res, curr + ')', left, right-1);
    }
};
