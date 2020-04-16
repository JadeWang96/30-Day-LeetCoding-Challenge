/*
** Perform String Shifts **

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
*/

/*
Left will cancel right, compute the total shift and direction
get the mod is important
** Analysis of Algorithm:
n - the length of shifts
m - the length of s
Time Complexity: O(n + m)
Space Complexity: O(1)
*/
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if (s.empty() || shift.empty()) return s;
        int dir = 0, totalShift = 0, n = s.size();
        for (auto& pair: shift) {
            if (!pair[0]) totalShift -= pair[1];
            else totalShift += pair[1];
        }
        if (totalShift == 0) return s;
        // totalShift > 0 right, < 0 left
        totalShift %= n;
        int left = n - abs(totalShift);
        if (totalShift < 0) {
            s = s.substr(abs(totalShift)) + s.substr(0, abs(totalShift));
        } else {
            s = s.substr(left) + s.substr(0, left);
        }
        return s;
    }
};