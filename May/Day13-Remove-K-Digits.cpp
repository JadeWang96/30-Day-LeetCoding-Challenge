class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (char ch: num) {
            while (res.size() && res.back() > ch && k) {
                res.pop_back();
                k--;
            }
            
            if (res.size() || ch != '0') res.push_back(ch);
        }
        
        while (res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
};

// Greedy
// O(n) O(1)