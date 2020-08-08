// Both have a Time Complexity : O(log(m*n))

// Creating a big fat array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(matrix.size() == 0)
            return false;
        int n = matrix[0].size();
        
        int low = 0, high = m*n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int mid_val = matrix[mid/n][mid%n];
            if(mid_val == target)
                return true;
            else if(target > mid_val)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};

// Apply binary search on column 0 and then apply binary search on that row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        if(high < 0)
            return false;
        
        int row = high;
        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};
