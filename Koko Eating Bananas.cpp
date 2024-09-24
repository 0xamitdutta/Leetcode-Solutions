class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool isValid(vector<int>& piles, int& h, int& mid) {
        long hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            // Instead of doing hours += ceil((piles[i] * 1.0) / 2), we can also do this
            long div = piles[i] / mid;
            hours += div;
            if(piles[i] % mid != 0) hours++;
        }
        return hours <= h;
    }
};
