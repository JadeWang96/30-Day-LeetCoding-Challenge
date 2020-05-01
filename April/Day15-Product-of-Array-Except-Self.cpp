/*
** Product of Array Except Self **

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/


/*
Well, the given O(1) space solution claim the output space won't count, so I don't think any difference with this one.
Just a little bit optimization for the first loop

** Analysis of Algorithm:
n - the length of nums
Time Complexity: O(n)
Space Complexity: O(n)/O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> beginning(n, 1), ending(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            beginning[i] = beginning[i - 1] * nums[i - 1];
            ending[i] = ending[i - 1] * nums[n - i];
        }
        for (int i = 0; i < beginning.size(); i++) {
            beginning[i] = beginning[i] * ending[n - 1 - i];// first one multiple the last one
        }
        return beginning;
    }
};