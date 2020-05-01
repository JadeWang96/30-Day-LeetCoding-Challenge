/*
** Construct Binary Search Tree from Preorder Traversal **

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.
*/


/*
** Analysis of Algorithm:
n - the length of vector
Time Complexity: O(n)// worst case: extreme unbalanced bst
Space Complexity: O(n) call stack
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
    int count = 0;
public:
    TreeNode* build(vector<int>& preorder, int bound) {
        if (count == preorder.size() || preorder[count] > bound) return NULL;// to guarantte the left < root and right > root
        TreeNode* root = new TreeNode(preorder[count++]);
        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};