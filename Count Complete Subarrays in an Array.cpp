// O(n*n) solutions
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int& num : nums) 
            s.insert(num);
      
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> sTemp;
            for(int j = i; j < nums.size(); j++) {
                sTemp.insert(nums[j]);
                if(sTemp.size() == s.size())
                    count++;
                if(sTemp.size() > s.size())
                    break;
            }
        }
        return count;
    }
};
