/*
** Jump Game **

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

/*
Intuitive solution is dynamic progamming, but it cannot pass the test, exceed time limit
Time complexity: O(n*n)
Space complexity: O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int n = nums.size();
        vector<bool> jump(n, false);
        jump[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= nums[i] && i + j < n; j++) {
                if (jump[i + j]) {
                    jump[i] = true;
                    break;
                }
            }
        }
        return jump[0];
    }
};

/*
But the greedy seems to work well here
reach indicates how far you can go from start point
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        for (int reach = 0; count < nums.size() && count <= reach; count++) {
            reach = max(nums[count] + count, reach);
        }
        return count == nums.size();
    }
};