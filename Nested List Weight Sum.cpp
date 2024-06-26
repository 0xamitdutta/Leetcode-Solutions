
/* https://www.lintcode.com/problem/nested-list-weight-sum/description */

/*
 * This is the interface that allows for creating nested lists.
 * You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
    int ans = 0;
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        dfs(nestedList, 1);
        return ans;
    }
    
    void dfs(vector<NestedInteger> nestedList, int depth){
        for(auto val : nestedList){
            if(val.isInteger())
                ans += val.getInteger()*depth;
            else
                dfs(val.getList(), depth+1);
        }
    }
};
