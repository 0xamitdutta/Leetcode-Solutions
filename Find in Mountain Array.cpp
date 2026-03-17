/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low  = 0, high = n-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                low = mid + 1;
            else
                high = mid;
        }
        int peakIdx = low;
        int isLeft = bSearch(target, mountainArr, 0, peakIdx);
        int isRight = rbSearch(target, mountainArr, peakIdx+1, n-1);
        if(isLeft == -1 && isRight == -1)
            return -1;
        return isLeft != -1 ? isLeft : isRight;
    }

    int bSearch(int target, MountainArray& mountainArr, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int rbSearch(int target, MountainArray& mountainArr, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};
