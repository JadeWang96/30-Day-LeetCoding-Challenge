/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int prevDepth = -1;
    bool flag = false;
public:
    bool DFS(TreeNode* root, int level, int x, int y) {
        if (!root) return false;
        if (prevDepth != -1 && level > prevDepth) return false;// not same depth
        if (root->val == x || root->val == y) {
            if (prevDepth == -1) {
                prevDepth = level;
            }
            return prevDepth == level;
        }
        bool left = DFS(root->left, level + 1, x, y);
        bool right = DFS(root->right, level + 1, x, y);
        
        if (left && right && prevDepth != level + 1) flag = true;// not same parent
        return left || right;// find x or y
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        DFS(root, 0, x, y);
        return flag;
    }
};

// O(n) O(log n)