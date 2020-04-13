/*
** Contiguous Array **
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000. 
*/

/*
Two situations that an interval will have the same number 1s and 0s:
The sum is 0 or the sum seen before(several interval with the same sum can be accumulated)


** Analysis of Algorithm:
n - the length of nums
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> sum_idx;
        int maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += (!nums[i])? -1: 1;
            auto it = sum_idx.find(sum);
            if (!sum) {// from beginning to here, same number
                maxLen = max(maxLen, i + 1);
            } else if (it != sum_idx.end()) {// see this sum before, this interval has same number
                maxLen = max(maxLen, i - it->second);
            } else if (it == sum_idx.end()){// haven't seen this sum before
                sum_idx[sum] = i;
            }
        }
        return maxLen;
    }
};