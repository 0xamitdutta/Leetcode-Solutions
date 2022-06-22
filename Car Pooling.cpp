// O(nlogn)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int people = 0;
        for(int i = 0; i < trips.size(); i++) {
            auto trip = trips[i];
            while(!pq.empty() && trip[1] >= pq.top().first) {
                people -= pq.top().second;
                pq.pop();
            } 
            people += trip[0];
            if(people > capacity) return false;
            pq.push({trip[2], trip[0]});
        }
        return true;
    }
};

// O(max(1000, n))
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001);
        int people = 0;
        for(auto trip : trips) {
            int persons = trip[0], start = trip[1], end = trip[2];
            stops[start] += persons;
            stops[end] -= persons;
        }
        for(int i = 0; i <= 1000; i++) {
            people += stops[i];
            if(people > capacity) return false;
        }
        return true;
    }
};
