class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int K) {
        multiset<int> window(nums.begin(), nums.begin() + K);
        // next() gives an iterator from a base iterator moving forward and prev() gives an iterator from a base iterator moving backward
        auto medPos = next(window.begin(), K/2);
        vector<double> res;
        for(int i = K; ; i++) {
            res.push_back((double(*medPos) + (K % 2 != 0 ? *medPos : *prev(medPos, 1))) / 2);
            
            if(i == nums.size()) 
                return res;
            // insert
            window.insert(nums[i]); // If nums[i] == *medPos it will always be inserted after the same instance acc to C++ 11
            if(nums[i] < *medPos)
                medPos--;
            
            // remove
            if(nums[i-K] <= *medPos)
                medPos++;
            window.erase(window.lower_bound(nums[i-K])); // We are using lower_bound to ensure the 1st instance of nums[i-K] is deleted always 
        }
        return {};
    }
};

/*
  There are 4 possible scenarios for every Insertion and deletion I -> Insertion, D -> Deletion, M -> Median, E -> Rest of the elements
  ID...E...M...E
  E...M...E...ID
  For these cases Median position doesn't change as Insertion and Deletion position cancels the offset
  
  I...E...M...E...D Insertion before M and Deletion after M results in median_pos--
  D...E...M...E...I Deletion before M and Insertion after M results in median_pos++
*/
