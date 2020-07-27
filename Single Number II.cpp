// Every number will either contribute 3 0s/1s OR 1 0s/1s
// Hece to find single element take mod 3 for all bit position from 0 to 31
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for(int num : nums){
            for(int j = 31; j >= 0; j--){
                bits[j] += (num & 1);
                num >>= 1;
                if(!num)
                    break;
            }
        }
        
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int val = bits[i] % 3;
            if(val)
                ans += 1 << (31-i);
        }
        return ans;
    }
};

/*
Eg : [2,2,2,3]
    1 0
    1 0
    1 0
  + 1 1
    ---
    4 1 = 1 1 (4%3 and 1%3) The mod cancels all multiple of 3 1s/0s  
*/
