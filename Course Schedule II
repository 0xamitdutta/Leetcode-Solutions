class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses);
        for(int i = 0; i < pre.size(); i++)
            indegree[pre[i][0]]++;
        
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(int i = 0; i < pre.size(); i++){
                if(pre[i][1] == temp){
                    indegree[pre[i][0]]--;
                    if(indegree[pre[i][0]] == 0)
                        q.push(pre[i][0]);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};
