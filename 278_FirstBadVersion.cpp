// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool isFirstBadVersion(int ver) {
        if (ver == 1 && isBadVersion(1)) {
            return true;
        }
        return isBadVersion(ver) && !isBadVersion(ver - 1);
    }
    
    // O(logn) time, O(1) space
    int firstBadVersion(int n) {
        long start = 1;
        long end = n;
        while (start <= end) {
            long middle = (start + end) / 2;
            if (isFirstBadVersion(middle)) {
                return middle;
            }
            else if (isBadVersion(middle)) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }
        return -1;
    }
};
