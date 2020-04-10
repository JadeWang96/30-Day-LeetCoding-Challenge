/*
** Backspace String Compare **
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/


/*
Loop from back to front
Count the number of #, if number of # > 0, skip the char
otherwise, add the char as res string 
** Analysis of Algorithm:
n - the length of S
m - the length of T
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/
class Solution {
public:
    string processingStr(const string& str) {
        int sharpCnt = 0;
        string res = "";
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '#') {
                sharpCnt++;
                continue;
            }
            if (sharpCnt == 0) {
                res = str[i] + res;
            } else {
                sharpCnt--;
            }
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        string realS = processingStr(S);
        string realT = processingStr(T);

        return realS == realT;
    }
};


/*
If in O(1) space, should use two pointers to compare the 2 strings directly
*/
class Solution {
public:

    bool backspaceCompare(string S, string T) {
        int sPtr = S.size() - 1, tPtr = T.size() - 1;
        int cntS = 0, cntT = 0;
        while (sPtr >= 0 || tPtr >= 0) {
            // find next eligible char for both S and T
            while (sPtr >= 0) {
                if (S[sPtr] == '#') {
                    cntS++; sPtr--;
                } else if (cntS > 0) {
                    cntS--; sPtr--;
                } else {
                    break;
                }
            }
            
            while (tPtr >= 0) {
                if (T[tPtr] == '#') {
                    cntT++; tPtr--;
                } else if (cntT > 0) {
                    cntT--; tPtr--;
                } else {
                    break;
                } 
            }
            
            if (sPtr >= 0 && tPtr >=0 && S[sPtr] != T[tPtr]) return false;// comparing the char value
            /*
            (sPtr >= 0) and (tPtr >= 0) will return boolean value and if they are different,
            indicating a char comparing with nothing 
            */
            if ((sPtr >= 0) != (tPtr >= 0)) return false;// positive verse negative
            sPtr--; tPtr--;
        }
        return true;
    }
};
