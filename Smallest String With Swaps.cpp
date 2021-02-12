// Try to think the pairs as nodes having a connection. Find the connected components and sort them.

class Solution {
public:
    int par[100001];
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        memset(par, -1, sizeof(par));
        for(auto& pair : pairs){
            int a = find(pair[0]);
            int b = find(pair[1]);
            if(a != b)
                Union(a, b);
        }
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < s.size(); i++){
            hash[find(i)].push_back(i);
        }
        for(auto& [key, val] : hash){
            string temp = "";
            for(int& id : val)
                temp += s[id];
            sort(temp.begin(), temp.end());
            for(int i = 0; i < temp.size(); i++){
                s[val[i]] = temp[i];
            }
        }
        return s;
    }
    
    int find(int a){
        if(par[a] < 0) 
            return a;
        return par[a] = find(par[a]);
    }
    
    void Union(int a, int b){
        par[a] = b;
    }
};
