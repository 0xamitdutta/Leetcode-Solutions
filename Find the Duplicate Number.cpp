/* 
Since the index range in [0, n] and numbers are from [1, n] there is guaranteed to be a duplicate.
We can take the advantage of the condition: If I use nums[i] as index to get next number as nums[nums[i]] and keep going, eventually, at some point, a duplicated value will be visited again because a duplicate value is mapped to more than one index.

When the first duplicate value is met, from there we start to entering into a cycle where the duplicate value is the entrance of the cycle.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
