// O(n^2)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            int curr = height[i];
            int left = 0, right = 0;
            for(int j = i-1; j >= 0; j--)
                left = max(left, height[j]);
            for(int j = i+1; j < n; j++)
                right = max(right, height[j]);
            if(curr < left && curr < right)
                total += min(left, right) - curr;
        }
        return total;
    }
};

// O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        for(int i = 1; i < n; i++){
            int left_max = max(left_max, height[i-1]);
            left[i] = left_max;
        }
        for(int i = n-2; i >= 0; i--){
            int right_max = max(right_max, height[i+1]);
            right[i] = right_max;
        }
        
        int total = 0;
        for(int i = 1; i < n-1; i++){
            if(left[i] > height[i] && right[i] > height[i])
                total = total + min(left[i], right[i]) - height[i];
        }
        return total;
    }
};
