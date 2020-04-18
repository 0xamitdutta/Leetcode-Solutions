class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for(int i = 0; i < nums2.size(); i++){
            while(!s.empty() && nums2[s.top()] < nums2[i]){
                m[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < nums1.size(); i++){
            if(m.find(nums1[i]) != m.end())
                nums1[i] = m[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};
