class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0)
            return 0;
        
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int val = m[s[s.size()-1]];
        for(int i = s.size()-2; i >= 0; i--){
            if(m[s[i]] >= m[s[i+1]])
                val += m[s[i]];
            else
                val -= m[s[i]];
        }
        return val;
    }
};
