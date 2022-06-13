class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dirs[i][0], ny = y + dirs[i][1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || res[nx][ny] != INT_MAX) continue;
                    res[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
            dist++;
        }
        
        return res;
    }
};
