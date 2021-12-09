class Solution {
    struct Log {
        int id;
        string status;
        int time;
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Log> s;
        vector<int> res(n);
        for(string& log : logs) {
            stringstream ss(log);
            string s1, s2, s3;
            getline(ss, s1, ':');
            getline(ss, s2, ':');
            getline(ss, s3, ':');
            Log item = {stoi(s1), s2, stoi(s3)};
            if(item.status == "start")
                s.push(item);
            else {
                int timeAdded = item.time - s.top().time + 1;
                res[item.id] += timeAdded;
                s.pop();
                if(!s.empty()) {
                    res[s.top().id] -= timeAdded;
                }
            }
        }
        return res;
    }
};
