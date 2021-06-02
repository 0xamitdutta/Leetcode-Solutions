class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;

        /*
        Hose No. - 0 1 2 3 ...
        Same - No. of ways of painting fences such that there are no more than 2 consecutive fences but the last two being same
        Diff - No. of ways of painting fences such that there are no more than 2 consecutive fences but the last two being diff
        Total ways = Same + Diff
        */
        
        // Initialised for 2 Houses
        int same = k;
        int diff = k*(k-1);
        int total = same + diff;
        for(int i = 3; i <= n; i++){
            same = diff; // For a current house the condition for last 2 fences to be same = diff (to paint the last-1 and last-2 houses)
            diff = total*(k-1); // For a current house the condition for last 2 fences to be diff = total (to paint the last-1 and last-2 houses) * (k-1)
            total = same + diff;
        }
        return total;
    }
};
