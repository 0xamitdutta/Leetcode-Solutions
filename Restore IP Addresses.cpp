class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(res, "", s, 0);
        return res;
    }
    
    void helper(vector<string>& res, string path, string s, int slots){
        if(s.size() == 0 && slots == 4){
            res.push_back(path.substr(1)); // To remove the first dot
            return;
        }
        if(s.size() == 0 || slots == 4){
            return;
        }
        
        // The loop only chooses starting 1 or 2 or 3 characters cuz range is b/w [0, 255]
        // If the first digit is '0' then choose only 1 character
        for(int i = 1; i <= (s[0] == '0' ? 1 : 3) && i <= s.size(); i++){
            string str = s.substr(0, i);
            if(stoi(str) <= 255){
                helper(res, path + "." + str, s.substr(i), slots+1);
            }
        }
    }
};
