/*
** Maximum Subarray **
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/*
Intuitive solution: Dynamic Programming
- Subproblem:
OPT[i] = the largest sum from 0 to i including i

- Recurrence:
OPT[i] = including nums[i]: OPT[i - 1] + nums[i]
        not including nums[i]: nums[i]
- Base Case:
OPT[0] = nums[0]

- Algo:
OPT[i] = max(OPT[i - 1], 0) + nums[i]
return max{OPT[0], ..., OPT[n - 1]}

** Analysis of Algorithm:
n - the length of nums
Time Complexity: O(n)
Space Complexity: O(n) I don't like the solution changing the value in given vector
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), res = nums[0];
        vector<int> OPT(n, 0);
        OPT[0] = nums[0];
        for (int i = 1; i < n; i++) {
            OPT[i] = max(OPT[i - 1], 0) + nums[i];
            if (OPT[i] > res) res = OPT[i];
        }

        return res;
    }
};

/*
Divide and Conquer
Time complexity will be O(nlogn)
Tired of exploring this
*/
