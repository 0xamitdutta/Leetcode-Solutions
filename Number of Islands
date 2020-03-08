// DFS Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
    }
};

// BFS Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        
        int count = 0;
        vector<pair<int, int>> p = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int> curr = q.front();
                        q.pop();
                        for(int k = 0; k < p.size(); k++){
                            int nr = curr.first + p[k].first, nc = curr.second + p[k].second;
                            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1'){
                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
