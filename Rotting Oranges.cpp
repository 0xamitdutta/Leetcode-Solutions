class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j] == 1)
                    freshOranges++;
            }
        }
        if(freshOranges == 0) return 0;
        if(q.size() == 0) return -1;
        
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int j = 0; j < 4; j++) {
                    int nx = x + directions[j].first, ny = y + directions[j].second;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshOranges--;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        return freshOranges == 0 ? time-1 : -1;
    }
};
