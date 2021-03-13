class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";
        
        // Map all characters in t with their frequencies
        unordered_map<char, int> hash;
        for(char& c : t){
            hash[c]++;
        }
        int counter = t.size(); // When counter becomes 0, we know a substring in s contains t
        int min_len = INT_MAX, start_ind = 0; // These two var helps to find the minimum among all possible substrings
        for(int i = 0, j = 0; i < s.size(); i++){
            if(hash[s[i]] > 0){
                counter--;
            }
            hash[s[i]]--;
            
            // Keep shrinking while counter is still 0, i.e a smaller substring is possible
            while(counter == 0){
                if(i-j+1 < min_len){
                    min_len = i-j+1;
                    start_ind = j;
                }
                hash[s[j]]++;
                if(hash[s[j]] > 0){
                    counter++;
                }
                j++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start_ind, min_len);
    }
};
