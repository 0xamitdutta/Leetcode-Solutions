class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Check that the target is >= letters[0] and <= letters[-1]
        if(target < letters[0] || target > letters[letters.size() - 1])
            return letters[0];

        // We are now sure that a solution exists unless the target is the last letter itself. In that case simply return letters[0]
        int low = 0, high = letters.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] > target) 
                high = mid;
            else 
                low = mid + 1;
        }
        return letters[low] == target ? letters[0] : letters[low];
    }
};
