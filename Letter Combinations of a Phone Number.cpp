class Solution {
private:
    unordered_map<int, string> hash = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        return helper(digits);
    }
    
    vector<string> helper(string digits){
        if(digits.size() == 0){
            return {""};
        }
        
        // Grab the first digit
        int digit = digits[0] - '0';
        
        // Get the ans for rest of the digits
        vector<string> restDigits = helper(digits.substr(1));
        string currString = hash[digit];
        
        // Add the characters of first digit to the string of rest of the digits
        vector<string> res;
        for(char chr : currString){
            for(string str : restDigits){
                res.push_back(chr + str);
            }
        }
        return res;
    }
};
