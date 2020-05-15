class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, temp = mid * mid;
            if (temp == num) return true;
            if (temp < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// O(logn) O(1)