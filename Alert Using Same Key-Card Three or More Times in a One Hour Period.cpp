class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> nameTime;
        for(int i = 0; i < keyName.size(); i++) {
            nameTime[keyName[i]].push_back(getTime(keyTime[i]));
        }

        vector<string> res;
        for(auto& [name, times] : nameTime) {
            sort(times.begin(), times.end());
            for(int i = 2; i < times.size(); i++) {
                if(times[i] - times[i-2] <= 60) {
                    res.push_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    int getTime(string& s) {
        string hrs = s.substr(0, 2);
        string mins = s.substr(3);
        return stoi(hrs) * 60 + stoi(mins);
    }
};
