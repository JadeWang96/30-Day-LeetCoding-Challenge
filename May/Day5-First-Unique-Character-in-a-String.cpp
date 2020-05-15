// O(n) O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() < 1) return -1;
        unordered_map<char, int> hash;
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            if (hash.count(s[i]) == 0) {
                hash[s[i]] = 1;
            } else {
                hash[s[i]]++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};