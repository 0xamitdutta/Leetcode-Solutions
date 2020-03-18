class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int val, int newColor){
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != val)
            return;
        
        image[i][j] = newColor;
        dfs(image, i-1, j, val, newColor);
        dfs(image, i, j+1, val, newColor);
        dfs(image, i+1, j, val, newColor);
        dfs(image, i, j-1, val, newColor);
    }
};
