class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // We are tracking the next greater element of i using a hashmap. Thus hash[i] = j means j is the next greater element for i.
        unordered_map<int, int> m;
        stack<int> s;
        for(int i = 0; i < nums2.size(); i++){
            while(!s.empty() && nums2[i] > s.top()){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
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
