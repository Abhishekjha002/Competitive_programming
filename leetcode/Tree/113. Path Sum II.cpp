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
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int sum, int target, vector<int>& temp)
    {
        
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum + root->val == target)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        
        
        temp.push_back(root->val);
        helper(root->left, sum + root->val, target, temp);
        helper(root->right, sum + root->val, target, temp);
        temp.pop_back();
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> temp;
        helper(root, 0, sum, temp);
        return ans;
        
    }
};