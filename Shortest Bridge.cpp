class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        bool isColored = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] == 1){
                    dfs(A, i, j);
                    isColored = true;
                    break;
                }
            }
            if(isColored){
                break;
            }
        }
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int flips = 0;
        vector<int> xdirs = {0, 0, 1, -1};
        vector<int> ydirs = {1, -1, 0, 0};
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(A[x][y] == 1){
                    return flips-1;
                }
                for(int j = 0; j < 4; j++){
                    int new_x = x + xdirs[j];
                    int new_y = y + ydirs[j];
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !vis[new_x][new_y]){
                        q.push({new_x, new_y});
                        vis[new_x][new_y] = 1;
                    }
                }
            }
            flips++;
        }
        return -1;
    }
    
    void dfs(vector<vector<int>>& A, int i, int j){
        if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != 1){
            return;
        }
        A[i][j] = 2;
        dfs(A, i+1, j);
        dfs(A, i-1, j);
        dfs(A, i, j+1);
        dfs(A, i, j-1);
    }
};
