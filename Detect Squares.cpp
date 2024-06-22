class DetectSquares {
private:
    vector<vector<int>> pointsList;
    int points[1001][1001];
public:
    DetectSquares() {
        memset(points, 0, sizeof(points));
    }
    
    void add(vector<int> point) {
        pointsList.push_back(point);
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> pointA) {
        int count = 0;
        int x1 = pointA[0], y1 = pointA[1];
        for(auto pointB : pointsList) { 
            int x2 = pointB[0], y2 = pointB[1];
            if(x1 == x2 || y1 == y2 || abs(x1 - x2) != abs(y1 - y2))
                continue;
            // auto pointC = {x1, y2}; 
            // auto pointD = {x2, y1};
            // We don't need x2, y2 in count because multiple x2, y2 will be covered in the for loop itself. If you want to include x2, y2 in count make sure pointsList has only one occurence of all points
            count += points[x1][y2] * points[x2][y1];
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
