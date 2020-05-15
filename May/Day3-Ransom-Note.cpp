// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// You may assume that both strings contain only lowercase letters.


// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mCnt(26, 0);
        for (char ch: magazine) {
            mCnt[ch - 'a']++;
        }
        for (char ch: ransomNote) {
            mCnt[ch - 'a']--;
            if (mCnt[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
