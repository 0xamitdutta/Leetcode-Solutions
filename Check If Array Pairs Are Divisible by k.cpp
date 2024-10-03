class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> hash_map;
        for(int i = 0; i < arr.size(); i++) {
            hash_map[((arr[i] % k) + k) % k]++;
        }
        for(int i = 0; i < arr.size(); i++) {
            int rem = ((arr[i] % k) + k) % k;
            if(rem == 0 && hash_map[rem] % 2 != 0)
                return false;
            if(rem != 0 && hash_map[rem] != hash_map[k-rem])
                return false; 
        }
        return true;
    }
};
