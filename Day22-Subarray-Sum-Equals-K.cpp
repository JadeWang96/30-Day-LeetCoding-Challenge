/*
** Subarray Sum Equals K **

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

/*
Through the hash map to chech wether this sum exits before,
if exits, increse the counter
and also through calculating the diff with k to determine whether it is target sum
what we want to find is from i to j has the sum k, and current sum -k can help us find out whether there exits this interval i to j

Time complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         if (nums.empty()) return 0;
        int res = 0, sum = 0;
        unordered_map<int, int> mp = {{0, 1}};// if sum - k == 0, there is increment
        for (int num: nums) {
            sum += num;
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};