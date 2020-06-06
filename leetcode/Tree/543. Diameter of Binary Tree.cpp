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
public:
    int diameter = 0;
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return -1;
        
        int lh = helper(root->left);
        int rh = helper(root->right);
        
        diameter = max(diameter, (lh + rh + 2));
        
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        helper(root);
        
        return diameter;
        
        
    }
};