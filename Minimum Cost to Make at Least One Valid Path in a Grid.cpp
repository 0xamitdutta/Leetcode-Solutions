class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<vector<int>> dq = {{0, 0, 0}};
        vector<vector<int>> vis(m, vector<int>(n));
        
        vector<int> xdirs = {0, 0, 1, -1};
        vector<int> ydirs = {1, -1, 0, 0};
        while(!dq.empty()){
            int x = dq.front()[0];
            int y = dq.front()[1];
            int cost = dq.front()[2];
            dq.pop_front();
            
            vis[x][y] = 1;
            if(x == m-1 && y == n-1){
                return cost;
            }
            for(int i = 0; i < 4; i++){
                int new_x = x + xdirs[i];
                int new_y = y + ydirs[i];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !vis[new_x][new_y]){
                    if(i+1 == grid[x][y]){
                        dq.push_front({new_x, new_y, cost});
                    }
                    else{
                        dq.push_back({new_x, new_y, cost+1});
                    }
                }
            }
        }
        return -1;
    }
};
