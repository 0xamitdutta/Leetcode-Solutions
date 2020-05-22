class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0) return 0;
        if(q.empty()) return -1;
        
        int count = 0;
        // This is how you iterate in 4 direections for BFS.
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto p = q.front();
                q.pop();
                for(auto dir : dirs){
                    int x = p.first + dir.first;
                    int y = p.second + dir.second;
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    fresh--;
                }
            }
        }
        // count-1 is there for the 1st time, when t == 0
        return fresh == 0 ? count-1 : -1;
    }
};
