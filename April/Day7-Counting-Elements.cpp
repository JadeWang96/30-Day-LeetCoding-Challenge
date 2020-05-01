/*
** Counting Elements **
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.


Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
Example 3:

Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
Example 4:

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
 

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000
*/

/*
We only care about how many x + 1 for the current x, always the take the frequency of current x not x + 1
The corner cases worth noticing here:
[1,1,2]=>2
1->2 & 1->2

[4,10,11,11,1,9,6,2,4,5,8]=>7
1->2 & 4->5 & 4->5 & 5->6 & 8->9 & 9->10 & 10->11
(Although there are two '11', but only one '10')

** Analysis of Algorithm:
n - the length of arr
m - the unique number in arr
Time Complexity: O(n + m)
Space Complexity: O(m)
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.size() <= 1) return 0;
        unordered_map<int, int> num_freq;
        for (int num: arr) {
            num_freq[num]++;
        }
        int res = 0;
        for (auto& pair: num_freq) {
            int cur = pair.first;
            auto next = num_freq.find(cur + 1);// hashmap find() takes constant time
            if (next != num_freq.end()) {
                res += pair.second;
            }
        }
        return res;
    }
};


/*
A little bit optimization using unordered_set and reusing the arr
** Analysis of Algorithm:
n - the length of arr
m - the unique number in arr
Time Complexity: O(n + n) = O(n)
Space Complexity: O(m)
*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.size() <= 1) return 0;
        unordered_set<int> unique(arr.begin(), arr.end());
        int res = 0;
        for (int num: arr) {
            if (unique.count(num + 1)) res++;
        }
        return res;
    }
};