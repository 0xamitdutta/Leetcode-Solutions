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
        int maxDigit = INT_MIN, maxIdx = -1;
        int lIdx = -1, rIdx = -1;
        for(int i = numString.size()-1; i >= 0; i--) {
            if(numString[i] > maxDigit) {
                maxDigit = numString[i];
                maxIdx = i;
                continue;
            }

            if(numString[i] < maxDigit) {
                lIdx = i; 
                rIdx = maxIdx;
            }
        }
        if(lIdx == -1)
            return stoi(numString);
        swap(numString[lIdx], numString[rIdx]);
        return stoi(numString);
    }
};
