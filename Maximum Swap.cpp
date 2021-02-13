// O(n^3)
class Solution {
public:
    int maximumSwap(int num) {
        // Try every i, j and swap them to check if we get a bigger number.
        string numString = to_string(num);
        string A = numString;
        for(int i = 0; i < numString.size(); i++){
            for(int j = i+1; j < numString.size(); j++){
                swap(numString[i], numString[j]);
                if(numString > A)
                    A = numString;
                swap(numString[i], numString[j]);
            }
        }
        return stoi(A);
    }
};

// O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        vector<int> digits(10); 
        for(int i = 0; i < numString.size(); i++){ // Store the last index of a digit in range [0-9]
            digits[numString[i]-'0'] = i;
        }
        // If there's a digit > numString[i] which is occuring later than swap it with numString[i];
        for(int i = 0; i < numString.size(); i++){
            for(int d = 9; d > numString[i]-'0'; d--){
                if(digits[d] > i){
                    swap(numString[i], numString[digits[d]]);
                    return stoi(numString);
                }
            }
        }
        return stoi(numString);
    }
};
