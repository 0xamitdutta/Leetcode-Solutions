class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> subArrays;
        for(int i = 0; i < nums.size(); i++) {
            int divisors = 0;
            vector<int> temp;
            for(int j = i; j < nums.size(); j++) {
                temp.push_back(nums[j]);
                if(nums[j] % p == 0) 
                    divisors++;
                if(divisors > k)
                    break;
                subArrays.insert(temp);
            }
        }
        return subArrays.size();
    }
};

class Trie {
public:
    unordered_map<int, Trie*> children;
    int count = 0;
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie *root = new Trie();
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            Trie *node = root;
            int count = 0;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] % p == 0)
                    count++;
                if(count > k)
                    break;
                
                if(!node->children.count(nums[j])) {
                    node->children[nums[j]] = new Trie();
                    res++;
                }
                node = node->children[nums[j]];
            }
        }
        return res;
    }
};
