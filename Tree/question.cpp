#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

// Leetcode : 987.================================================

int min_ = 0;
int max_ = 0;
void width(TreeNode* root, int lvl){
    
    if(root == nullptr)
        return;
    
    min_ = min(min_, lvl);
    max_ = max(max_, lvl);
    width(root->left, lvl-1);
    width(root->right, lvl+1);

}
class dpair{
    public:
    TreeNode* node;
    int lvl;
    dpair(TreeNode* node, int lvl){
        this->node = node; 
        this->lvl = lvl;
    }
};
struct comp{
    public:
        bool operator()(const dpair& p1, const dpair& p2){
            if(p1.lvl == p2.lvl)
                return p1.node->val > p2.node->val;
            return p1.lvl > p2.lvl;
            // return p1.node->val > p2.node->val;
        }
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    width(root, 0);
    int size = max_ - min_ + 1;

    vector<vector<int>> ans(size,vector<int>());
    
    priority_queue<dpair,vector<dpair>,comp> pq;
    priority_queue<dpair,vector<dpair>,comp> cq;
    
    pq.push(dpair{root,-min_});

    while(pq.size() != 0){
        int size = pq.size();
        while(size--){
            dpair rvtx = pq.top();
            pq.pop();
            
            ans[rvtx.lvl].push_back(rvtx.node->val);

            if(rvtx.node->left!=nullptr)
                cq.push(dpair{rvtx.node->left, rvtx.lvl - 1});
            
            if(rvtx.node->right!=nullptr)
                cq.push(dpair{rvtx.node->right, rvtx.lvl + 1});
        }
        
        priority_queue<dpair,vector<dpair>,comp> temp = pq;
        pq = cq;
        cq = temp;
        
    }
    return ans;
    
}





