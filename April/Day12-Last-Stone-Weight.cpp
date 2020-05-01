/*
** Last Stone Weight **

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

/*
Everytime take the largest two -> sorted  -> priority_queue

 
** Analysis of Algorithm:
n - the number of stones
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for (int num: stones) Q.push(num);
        while (Q.size() > 1) {
            int first = Q.top(); Q.pop();
            int second = Q.top(); Q.pop();
            int minus = first - second;// first always >= second
            if (minus == 0) continue;
            Q.push(minus);
        }
        return Q.empty()? 0: Q.top();
    }
};


/*
Limited implementation will be bucket sort
Bucket sort is mainly useful when input is uniformly distributed over a range.

This approach is only viable when the maximum stone weight is small, 
or is at least smaller than the number of stones.

O(n + maxNum)
O(maxNum)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        int maxNum = *max_element(stones.begin(), stones.end());
        vector<int> bucket(maxNum + 1, 0);// what's going on with leetcode array initialization
        for (int stone: stones) bucket[stone]++;
        // bucket sort
        int leftW = 0;
        int currentW = maxNum;
        while (currentW > 0) {
            if (!bucket[currentW]) {// empty weight, move forward
                currentW--;
            } else if (!leftW) {// only currentWeight
                bucket[currentW] %= 2;
                if (bucket[currentW] == 1) {// single left
                    leftW = currentW;
                }
                currentW--;
            } else {// leftW left from the previous
                bucket[currentW]--;
                if (leftW - currentW <= currentW) {
                    bucket[leftW - currentW]++;
                    leftW = 0;
                } else {
                    leftW -= currentW;
                }
            }
        }
        return leftW;
    }
};