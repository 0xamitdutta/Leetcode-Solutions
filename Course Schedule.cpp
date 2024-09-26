class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // The BFS version of Topological sort ensures that there's at least 1 vertex with indegree 0 and outdegree 0.
        vector<int> indegree(numCourses);
        for(vector<int>& prereq : prerequisites) 
            indegree[prereq[0]]++;
        
        // Put all nodes with indegree 0 in the queue
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(!indegree[i])
                q.push(i);
        }
        
        // Check if count is equal to numCourses
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            numCourses--;
            for(vector<int>& prereq : prerequisites) {
                if(prereq[1] == course) {
                    indegree[prereq[0]]--;
                    if(indegree[prereq[0]] == 0)
                        q.push(prereq[0]);
                }
            }
        }
        return numCourses == 0;
    }
};
