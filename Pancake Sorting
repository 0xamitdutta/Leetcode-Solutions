class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for(int i = A.size()-1; i >= 0; i--){
            // Choose the next greatest element
            int maxIndex = i;
            for(int j = i; j >= 0; j--){
                if(A[j] > A[maxIndex])
                    maxIndex = j;
            }
            
            // Make maximum element come at A[0]
            flip(A, maxIndex+1);
            res.push_back(maxIndex+1);
            
            // Make that element come at last
            flip(A, i+1);
            res.push_back(i+1);
        }
        return res;
    }
    
    void flip(vector<int>& A, int k){
        int i = 0, j = k-1;
        while(i < j){
            swap(A[i], A[j]);
            i++; j--;
        }
    }
};
