class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        vector<int> res(T.size());
        for(int i = 0; i < T.size(); i++){
            while(!s.empty() && T[i] > s.top().first){
                res[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push({T[i], i});
        }
        while(!s.empty()){
            auto temp = s.top();
            s.pop();
            res[temp.second] = 0;
        }
        return res;
    }
};
