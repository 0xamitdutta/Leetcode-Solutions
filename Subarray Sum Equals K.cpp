class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        
        /*
        .....i...j...k...l
        Let's say till i sum is x. Till j sum is x+k (Therefore, 1 subarray is from i to j)
        Let's say till k sum is again x and till l it is x+k. (Therefore, there is subarray from k to l and another from i to l. Hence we have add all ocurrrences of x when sum is x+k)
        */
        int sum = 0, count = 0;
        for(int& num : nums){
            sum += num;
            if(hash.count(sum-k)){
                count += hash[sum-k];
            }
            hash[sum] += 1;
        }
        return count;
    }
};
