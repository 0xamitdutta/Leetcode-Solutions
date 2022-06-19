// TC = O(nlogn) + O(m)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        
      // Keep on reducing or minimizing the search space through 2 pointers and then pick min(3, valid) choices left
        int l = 0, r = products.size()-1;
        for(int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            while(l <= r && (products[l].size() <= i || products[l][i] != c))
                l++;
            while(l <= r && (products[r].size() <= i || products[r][i] != c))
                r--;
            int words = r-l+1;
            vector<string> searches;
            for(int j = l; j < min(3, words); j++)
                searches.push_back(products[l + j]);
            res.push_back(searches);
        }
        return res;
    }
};
