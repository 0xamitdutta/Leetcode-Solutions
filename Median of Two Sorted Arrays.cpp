// Time Complexity : O(m+n)
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

// Time Complexity : O(log(min(m, n)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = m, half = (m+n+1)/2;
        // Apply binary search on smaller vector
        while(low <= high){
            int i = low + (high-low)/2;
            int j = half-i;
            if(i < m && nums2[j-1] > nums1[i])
                low++; // i is too small, must increase it
            else if(i > 0 && nums1[i-1] > nums2[j])
                high--; // i is too small, must increase it
            else{
                // i is perfect. 
                // Ans is max(nums1[i-1], nums2[j-1]) for odd OR 
                // max(nums1[i-1], nums2[j-1])+min(nums1[i], nums2[j])/2
                int max_left = 0;
                if(i == 0)
                    max_left = nums2[j-1];
                else if(j == 0)
                    max_left = nums1[i-1];
                else
                    max_left = max(nums1[i-1], nums2[j-1]);
                
                if((m+n)&1) 
                    return max_left;
                
                int min_right = 0;
                if(i == m)
                    min_right = nums2[j];
                else if(j == n)
                    min_right = nums1[i];
                else
                    min_right = min(nums1[i], nums2[j]);
                return (max_left+min_right)/2.0;
            }
        }
        return -1;
    }
};
