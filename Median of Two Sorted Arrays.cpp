class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < n2){
            res.push_back(nums2[j]);
            j++;
        }
        int n = n1+n2;
        if(n % 2 != 0)
            return res[n/2];
        return (res[n/2 - 1] + res[n/2])/(2*1.0);
    }
};
