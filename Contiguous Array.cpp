class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int count = 0, len = 0;
        for(int i = 0; i < nums.size(); i++){
            count = count + (nums[i] == 0 ? -1 : 1);
            if(m.find(count) != m.end())
                len = max(len, i-m[count]);
            else
                m[count] = i;
        }
        return len;
    }
};
