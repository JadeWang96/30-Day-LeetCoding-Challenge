/*
** Bitwise AND of Numbers Range **

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

/*
If use & directly, will exceed the time limit
right shift at first and then left shift
"The idea is that we shift both numbers to the right, until the numbers become equal, 
i.e. the numbers are reduced into their common prefix. 
Then we append zeros to the common prefix in order to obtain the desired result, by shifting the common prefix to the left."

SAD :( cannot figure out by myself

Time complexity: O(1)
Space Complexity: O(1)
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            res++;
        }
        return m<<res;
    }
};