/*
** Move Zeroes **
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example::
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.
*/

/*
There are 2 ways to move in-place, both 2 pointers
1. Swap the 0 with numbers
2. Replace the 0 with numbers and fill the rest of vector with 0


** Analysis of Algorithm:
n - the length of nums
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int zeroLoc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == zeroLoc && nums[i]) {
                zeroLoc++;
            } else if (nums[i]) {
                nums[zeroLoc++] = nums[i];
            }
        }
        for (; zeroLoc < nums.size(); zeroLoc++) {
            nums[zeroLoc] = 0;
        }
    }
};