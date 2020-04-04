/*
** Happy Number **
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example:
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

/* 
Intuitive solution: Recursion
Find the special situation 1 and 7 within 10 (the single digit number),
Once the recursion hits 1 and 7, return true,
otherwise, return false.

** Analysis of Algorithm:
m - the number of digits of n
Time Complexity: O(m)
Space Complexity: O(m) regarding call stack
*/
class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) return true;
        if (n < 10) return false;
        int next = 0;
        while (n) {
            int unit = n % 10;
            next += unit * unit;
            n /= 10;
        }
        return isHappy(next);
    }
};


/*
Optimal solution: Detecting the cycle
1. Detect Cycles with a set (Implement same as my first solution, just use a set record every number we see)
2. Floyd's Cycle-Finding Algorithm (Fast and slow pointers)

** Analysis of Algorithm:
Time Complexity: O(logn)
Space Complexity: O(1)
*/
class Solution {
public:
    int getNext(int n) {
        int total = 0;
        while (n) {
            int unit = n % 10;
            total += unit * unit;
            n /= 10;
        }
        return total;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};