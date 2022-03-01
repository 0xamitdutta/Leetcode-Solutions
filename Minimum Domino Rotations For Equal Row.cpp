class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        for(int num : {tops[0], bottoms[0]}) {
            int missTop = 0, missBot = 0;
            int i;
            for(i = 0; i < tops.size(); i++) {
                if(!(tops[i] == num || bottoms[i] == num)) break;
                if(tops[i] != num) missTop++;
                if(bottoms[i] != num) missBot++;
            }
            if(i == tops.size()) return min(missTop, missBot);
        }
        return -1;
    }
};
