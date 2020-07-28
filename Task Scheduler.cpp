class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(char task : tasks)
            freq[task-'A']++;
        
        priority_queue<int> pq;
        for(int num : freq){
            if(num > 0)
                pq.push(num);
        }
        
        // Multiple iterations will take place for every n+1 time
        int time = 0;
        while(!pq.empty()){
            vector<int> remaining;
            int interval = n+1; // Represents number of task that can be completed including current
            
            while(interval > 0 && !pq.empty()){
                int count = pq.top();
                pq.pop();
                if(--count)
                    remaining.push_back(count);
                time++;
                interval--;
            }
            for(int num : remaining) // Frequency of every task for next iteration
                pq.push(num);
            if(pq.empty())
                break;
            time += interval;   // The time added is the idle time cuz pq is empty
        }
        return time;
    }
};
