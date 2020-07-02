class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // The BFS version of Topological sort ensures that there's at least 1 vertex with indegree 0 and outdegree 0.
        vector<int> indegree(numCourses);
        for(int i = 0; i < pre.size(); i++)
            indegree[pre[i][0]]++;
        
        // Put all nodes with indegree 0 in the queue
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(!indegree[i])
                q.push(i);
        }
        
        // Check if count is equal to numCourses
        int count = 0;
        while(!q.empty()){
            count++;
            int curr = q.front();
            q.pop();
            for(int i = 0; i < pre.size(); i++){
                if(pre[i][1] == curr){
                    indegree[pre[i][0]]--;
                    if(indegree[pre[i][0]] == 0)
                        q.push(pre[i][0]);
                }
            }
        }
        return count == numCourses;
    }
};
