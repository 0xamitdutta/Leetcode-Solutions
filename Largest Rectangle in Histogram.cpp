// O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            int curr = heights[i];
            int right, left;
            for(right = i; right < n; right++){
                if(heights[right] < curr)
                    break;
            }
            for(left = i; left >= 0; left--){
                if(heights[left] < curr)
                    break;
            }
            res = max(res, (right-left-1)*curr);
        }
        return res;
    }
};

// O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        
        
        int area = 0;
        int i = 0;
        while(i < heights.size()){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int h = heights[s.top()];
                s.pop();
                int j = (s.empty() ? -1 : s.top());
                area = max(area, h*(i-j-1));
            }
        }
        return area;
    }
};
