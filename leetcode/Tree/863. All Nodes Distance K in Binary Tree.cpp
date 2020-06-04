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
    vector<int> ans;
    void KDown(TreeNode* root, int level, TreeNode* blockNode)
    {
        if(root == NULL || root == blockNode)
            return;
        
        if(level == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        KDown(root->left, level-1, blockNode);
        KDown(root->right, level-1, blockNode);
    }
    int helper(TreeNode* root, TreeNode* target, int K){
        
        if(root == NULL)
            return -1;
        
        if(root->val == target->val)
        {
            KDown(root, K, NULL);
            return 1;
        }
        
        int leftDistance = helper(root->left, target, K);
        if(leftDistance != -1)
        {
            if(K - leftDistance >= 0)
                KDown(root, K - leftDistance, root->left);
            return leftDistance + 1;
        }
        int rightDistance = helper(root->right, target, K);
        if(rightDistance != -1)
        {
            if(K - rightDistance >= 0)
                KDown(root, K - rightDistance, root->right);
            return rightDistance + 1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        int c = helper(root, target, K);
            
        return ans;
    }
};