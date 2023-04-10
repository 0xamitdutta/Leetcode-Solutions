class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int mid = l + (r - l)/2;
            if(isPossible(mid, h, piles))
              r = mid;
            else 
              l = mid + 1;
        }
        return r;
    }

    bool isPossible(int mid, int h, vector<int>& piles) {
        int ans = 0;
        for(int i = 0; i < piles.size(); i++) {
            ans += ceil((piles[i] * 1.0) / mid);
            if(ans > h) return false;
        }
        return true;
    }
};
