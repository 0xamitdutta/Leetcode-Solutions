class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        
        // A visited 8x8 visited boolean vector to check the positions of queens
        vector<vector<bool>> vis(8, vector<bool>(8, false));
        for(auto vec : queens)
            vis[vec[0]][vec[1]] = true;
        
        // Direction vectors *Pretty Interesting technique tbh*
        vector<int> dir = {-1, 0, 1};
        
        for(int dx : dir){
            for(int dy : dir){
                if(dx == 0 && dy == 0) continue;
                
                int x = king[0], y = king[1];
                while(x+dx >= 0 && x+dx < 8 && y+dy >= 0 && y+dy < 8){
                    x = x+dx;
                    y = y+dy;
                    if(vis[x][y]){
                        res.push_back({x, y});
                        break;
                    }
                }
            }
        }
        return res;
    }
};
