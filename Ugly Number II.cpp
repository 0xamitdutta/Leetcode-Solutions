class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugli(n);
        ugli[0] = 1;
        
        // Pointers for count of 2, 3 and 5
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
