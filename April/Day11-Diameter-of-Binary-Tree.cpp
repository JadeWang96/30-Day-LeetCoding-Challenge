/*
** Diameter of Binary Tree **
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

/*
For the current node, the diameter is the sum of right and left subtree,
if it returns to the upper level of recursion, returns to parent node,
only cares about the longest subtree in left and right
 
** Analysis of Algorithm:
n - the number of nodes
Time Complexity: O(n)
Space Complexity: O(n) // call stack for all nodes
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxLen;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxLen = 0;
        DFS(root);
        return maxLen;
    }
    
    int DFS(TreeNode* root) {
        if (!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        maxLen = max(maxLen, right + left);
        return max(right, left) + 1;
    }
};