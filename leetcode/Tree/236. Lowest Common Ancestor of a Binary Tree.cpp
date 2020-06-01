/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool rootToNodePath(TreeNode* root, TreeNode* find, vector<TreeNode*>& path)
{
    if(root == NULL)
        return false;
    if(root->val == find->val)
    {
        path.push_back(root);
        return true;
    }
    
    bool res = rootToNodePath(root->left, find, path) || rootToNodePath(root->right, find, path);
    if(res)
        path.push_back(root);
    
    return res;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);
        
        TreeNode* prev = NULL;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        
        while(i >= 0 && j >= 0)
        {
            if(path1[i]->val != path2[j]->val)
                break;
            prev = path1[i];
            i--;
            j--;
        }
        return prev;
    }
};