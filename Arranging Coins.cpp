class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long coins = 1LL*mid*(mid+1)/2;
            if(coins == n) return mid;
            else if(coins > n) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};
