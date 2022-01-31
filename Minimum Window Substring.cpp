// Check NeetCode on YouTube
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        map<char, int> window, countT;
        for(char c : t) countT[c]++;
        
        int have = 0, need = countT.size();
        int left = 0, right = 0, minLen = INT_MAX;
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if(countT.count(c) && window[c] == countT[c]) 
                have++;
            while(have == need) {
                // Update the len if len is smaller than minLen
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    left = l, right = r;
                }
                // Move the l pointer forward
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        return minLen != INT_MAX ? s.substr(left, minLen) : "";
    }
};
