class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 0)
            return matrix;
        
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> p = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(int i = 0; i < p.size(); i++){
                int nr = curr.first + p[i].first, nc = curr.second + p[i].second;
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    if(dist[nr][nc] > dist[curr.first][curr.second] + 1){
                        dist[nr][nc] = dist[curr.first][curr.second] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
};
