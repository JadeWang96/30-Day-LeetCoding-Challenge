/*
** Binary Tree Maximum Path Sum **

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


/*
Same as diameter of tree
Time complexity: O(n)
Space complexity: O(log n)// call stack
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
public:
    int maxValue = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        // maxValue = INT_MIN;
        maxPathDown(root);
        return maxValue;
    }
    
    int maxPathDown(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));
        maxValue = max(left + right + root->val, maxValue);
        return max(left, right) + root->val;
    }
};