class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<>());
        for(int i = n-1; i >= 0; i--){
            if(citations[i] >= i+1)
                return i+1;
        }
        return 0;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1);
        for(int num : citations){
            if(num >= n) count[n]++;
            else count[num]++;
        }
        int total = 0;
        for(int i = n; i >= 0; i--){
            total += count[i];
            if(total >= i)
                return i;
        }
        return 0;
    }
};
