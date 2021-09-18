// O(n^2)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            int curr = height[i];
            int left = 0, right = 0;
            for(int j = i-1; j >= 0; j--)
                left = max(left, height[j]);
            for(int j = i+1; j < n; j++)
                right = max(right, height[j]);
            if(curr < left && curr < right)
                res += min(left, right) - curr;
        }
        return res;
    }
};

// O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        vector<int> left(n), right(n); 
        // Left stores the maximum height of buiding to the left of i, not including i. Right stores the maximum height of building to the right of i, not including i
        
        left[0] = 0;
        int left_max = height[0];
        for(int i = 1; i < n; i++){
            left[i] = left_max;
            left_max = max(left_max, height[i]);
        }
        right[n-1] = 0;
        int right_max = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = right_max;
            right_max = max(right_max, height[i]);
        }        
        int res = 0;
        for(int i = 1; i < n-1; i++){
            if(left[i] > height[i] && right[i] > height[i])
                res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
