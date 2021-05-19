class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        int len = 0;
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<int> x_dir = {1, 1, 1, 0, 0, -1, -1, -1};
        vector<int> y_dir = {1, 0, -1, 1, -1, 1, 0, -1};
        
        while(!q.empty()){
            len++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 && y == n-1)
                    return len;
                for(int i = 0; i < 8; i++){
                    int new_x = x + x_dir[i];
                    int new_y = y + y_dir[i];
                    // We don't need a visited matrix because if we get a 0 we are then changinging it to 1
                    if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size() || grid[new_x][new_y] == 1)
                        continue;
                    grid[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return -1;
    }
};
