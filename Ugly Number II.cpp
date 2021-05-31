class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugli(n);
        ugli[0] = 1;
        /* 
            The next number has to be the the smallest number among all the existing numbers multiplied by 2, 3, 5 that isn't in the list already.
            We could iterare from 0 to i-1 for each i and multiply every number with 2, 3 and 5 to find smallest. But that's O(n^2).
        */
        
        // We can do it in O(n) if we make use of Pointers of 2, 3 and 5
        int p2 = 0, p3 = 0, p5 = 0;
        
        int n2 = 2*ugli[p2], n3 = 3*ugli[p3], n5 = 5*ugli[p5];
        for(int i = 1; i < n; i++){
            ugli[i] = min(n2, min(n3, n5));
            
            // Use if and not if-else cuz for numbers like 6 both pointers of 2 and 3 have to be incremented
            if(ugli[i] == n2){
                p2++;
                n2 = 2*ugli[p2];
            }
            if(ugli[i] == n3){
                p3++;
                n3 = 3*ugli[p3];
            }
            if(ugli[i] == n5){
                p5++;
                n5 = 5*ugli[p5];
            }
        }
        return ugli[n-1];
    }
};

// Eg: min(2, 3, 4) -> min(4, 3, 5) -> min(4, 6, 5) ...
