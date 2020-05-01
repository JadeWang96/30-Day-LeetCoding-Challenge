/*
** Single Number **

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example:
Input: [2,2,1]
Output: 1

Input: [4,1,2,1,2]
Output: 4
*/


/* 
Intuitive solution: Bitwise operator XOR
Takes two numbers as operands and does XOR on every bit of two numbers.
The result of XOR is 1 if the two bits are different.
The number appears on even number will get the multiple result 1, and the number appear odd number will be left.

** Analysis of Algorithm:
n - The length of nums
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num: nums) {
            res ^= num;
        }
        return res;
    }
};