class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMost(A, K) - atMost(A, K-1);
    }
    
    // Refer to longest substring with at most k diff chars and at most 2 diff chars
    int atMost(vector<int>& A, int K){
        unordered_map<int, int> m;
        int res = 0, counter = 0;
        int i = 0, j = 0;
        while(j < A.size()){
            m[A[j]]++;
            if(m[A[j]] == 1)
                counter++;
            j++;
            
            while(counter > K){
                m[A[i]]--;
                if(m[A[i]] == 0)
                    counter--;
                i++;
            }
            res += j-i;
        }
        return res;
    }
};
