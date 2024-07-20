// Worst Case: O(2*n) 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        for(int& num : nums) {
            if(!s.count(num - 1)) {
                int currLength = 1;
                int next = num + 1;
                while(s.count(next)) {
                    currLength++;
                    next++;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};
