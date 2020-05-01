/*
** Group Anagrams **
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

/*
Since the number of each char are same, sorted char will be the organized key

** Analysis of Algorithm:
n - the length of strs
k - maximum length of string
Time Complexity: O(n * k * logk)
Space Complexity: O(n * k)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (string& str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        for (auto pair: map) {
            res.push_back(pair.second);
        }
        return res;
    }
};

/*
Since the char is only in lower case, we know it is in a specific range by ASCII table
We can use counting sort to reduce the time complexity of sort from klogk to k + 26 (k)
https://www.geeksforgeeks.org/counting-sort/

Time Complexity: O(n * k)
Space Complexity: O(n * k)
*/
class Solution {
public:
    string countingSort(string& str) {
        int counter[26] = {0};
        for (char ch: str) {
            counter[ch - 'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; i++) {
            res += string(counter[i], i + 'a');
        }
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (string& str: strs) {
            map[countingSort(str)].push_back(str);
        }
        for (auto pair: map) {
            res.push_back(pair.second);
        }
        return res;
    }
};