class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses);
        for(vector<int>& prereq : prerequisites) 
            indegree[prereq[0]]++;
        
        // Put all nodes with indegree 0 in the queue
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(!indegree[i])
                q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            numCourses--;
            res.push_back(course);
            for(vector<int>& prereq : prerequisites) {
                if(prereq[1] == course) {
                    indegree[prereq[0]]--;
                    if(indegree[prereq[0]] == 0)
                        q.push(prereq[0]);
                }
            }
        }
        return numCourses == 0 ? res : vector<int>();
    }
};
