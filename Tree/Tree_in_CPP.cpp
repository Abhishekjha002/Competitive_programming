#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Node{
    
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
    Node(){        
    }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{
    if(arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node* root = new Node(arr[idx++]);
    root->left = constructTree(arr);
    root->right = constructTree(arr);

    return root;
}

void display(Node* root)
{
    if(root == nullptr)
        return;
    
    string str = "";
    str += (root->left != nullptr) ? to_string(root->left->data) : ".";
    str += " <- " + to_string(root->data) + " -> ";
    str += (root->right != nullptr) ? to_string(root->right->data) : ".";

    cout << str << "\n";

    display(root->left);
    display(root->right);

}

// Basic. =======================================

int size(Node* root)
{
    if(root == nullptr)
        return 0;
    
    return size(root->left) + size(root->right) + 1;
}

int height(Node* root)
{
    if(root == nullptr)
        return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int maximum(Node* root)
{
    if(root == nullptr)
        return -1e8;
    
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}


int minimum(Node* root)
{
    if(root == nullptr)
        return 1e8;
    
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool find(Node* root, int x)
{
    if(root == nullptr)
        return false;

    if(root->data == x)
        return true;

    return find(root->left, x) || find(root->right, x);

}

// Traversal. =============================================

void preOrder(Node* root)
{
    if(root == nullptr)
        return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if(root == nullptr)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if(root == nullptr)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

bool rootToNodePath_(Node* root, int data, vector<Node*>& path)
{
    if(root == nullptr)
        return false;

    if(root->data == data){
        path.push_back(root);
        return true;
    }

    bool res = rootToNodePath_(root->left, data, path) || rootToNodePath_(root->right, data, path);

    if(res){
        path.push_back(root);
    }

    return res;
}

vector<Node*> rootToNodePath_02(Node* root, int data){

    if(root == nullptr)
    {
        vector<Node*> base;
        return base;
    }

    if(root->data == data)
    {
        vector<Node*> ans;
        ans.push_back(root);
        return ans;
    }

    vector<Node*> left = rootToNodePath_02(root->left, data);
    if(left.size() != 0)
    {
        left.push_back(root);
        return left;
    }
    
    vector<Node*> right = rootToNodePath_02(root->right, data);
    if(right.size() != 0)
    {
        right.push_back(root);
        return right;
    }

    return {};
}

Node* LCA = nullptr;

bool lowestCommanAncestor(Node* root, int p, int q)
{
    if(root == nullptr)
        return false;
    
    bool selfDone = false;
    if(root->data == p || root->data == q){
        selfDone = true;
    }

    bool leftDone = lowestCommanAncestor(root->left, p, q);
    if(LCA != nullptr)
        return true;

    bool rightDone = lowestCommanAncestor(root->right, p, q);
    if(LCA != nullptr)
        return true;
    

    if((selfDone && leftDone) || (selfDone && rightDone) || (leftDone && rightDone))
        LCA = root;
    
    return selfDone || leftDone || rightDone;
}

void KDown(Node* root, int level, Node* blockNode)
{
    if(root == nullptr || root == blockNode)
        return;
    
    if(level == 0)
    {
        cout << root->data << " ";
    }

    KDown(root->left, level-1, blockNode);
    KDown(root->right, level-1, blockNode);
}


void allNodesKAway_(Node* root, int target, int K)
{
    vector<Node*> path;
    rootToNodePath_(root, target, path);

    Node* blockNode = nullptr;

    for(int i=0;i<path.size();i++)
    {
        if(K-i < 0)
            break;
        KDown(path[i], K - i, blockNode);
        blockNode = path[i];
    }

}

int allNodesKAway_02(Node* root, int target, int K)
{
    if(root == nullptr)
        return -1;
    
    if(root->data == target)
    {
        KDown(root, K, nullptr);
        return 1;
    }

    int leftDistance = allNodesKAway_02(root->left, target, K);
    if(leftDistance != -1)
    {
        if(K - leftDistance >= 0)
            KDown(root, K - leftDistance, root->left);
        return leftDistance + 1;
    }

    int rightDistance = allNodesKAway_02(root->right, target, K);
    if(rightDistance != -1)
    {
        if(K - rightDistance >= 0)
            KDown(root, K - rightDistance, root->right);
        return rightDistance + 1;
    }

    return -1;
}

int max_ = 0;
int maximumLeafToLeaf_(Node* root){

    if(root == nullptr){
        return 0;
    }

    int lv = maximumLeafToLeaf_(root->left);
    int rv = maximumLeafToLeaf_(root->right);

    if(root->left != nullptr && root->right != nullptr){
        max_ = max(max_, lv + rv + root->data);
        return max(lv, rv) + root->data;
    }

    return (root->left == nullptr ? rv : lv) + root->data;
}

int maximumLeafToLeaf(Node* root){
    maximumLeafToLeaf_(root);
    return max_;
}

void levelOrder(Node* root){

    queue<Node*> que;
    que.push(root);

    int level = 0;
    while(que.size() != 0)
    {
        cout<<"level : "<<level<<" -> ";
        int size = que.size();
        while(size--)
        {
            Node* rvtx = que.front();
            cout<<rvtx->data<<" ";
            que.pop();
            if(rvtx->left != nullptr)
                que.push(rvtx->left);
            if(rvtx->right != nullptr)
                que.push(rvtx->right);
        }
        cout<<"\n";
        level++;
    }

}

// View. ===============================================

void leftView(Node* root){

    queue<Node*> que;
    que.push(root);

    while(que.size() != 0){
        int size = que.size();
        cout<<que.front()->data<<" ";
        while(size--){
            Node* rvtx = que.front();
            que.pop();

            if(rvtx->left != nullptr)
                que.push(rvtx->left);

            if(rvtx->right != nullptr)
                que.push(rvtx->right);
            
        }
    }
}

void rightView(Node* root){

    queue<Node*> que;
    que.push(root);

    while(que.size() != 0){
        int size = que.size();
        Node* prev = nullptr;
        while(size--){
            Node* rvtx = que.front();
            que.pop();

            if(rvtx->left != nullptr)
                que.push(rvtx->left);

            if(rvtx->right != nullptr)
                que.push(rvtx->right);
            
            prev = rvtx;
        }
        cout<<prev->data<<" ";
    }
}

int minIdx = 0;
int maxIdx = 0;

void width(Node* root, int level)
{
    if(root == nullptr)
        return;
    
    minIdx = min(minIdx, level);
    maxIdx = max(maxIdx, level);

    width(root->left, level-1);
    width(root->right, level+1);
}

void verticalOrder(Node* root){

    width(root, 0);
    int size = maxIdx - minIdx + 1;
    vector<vector<int>> VO(size, vector<int>());

    queue<pair<Node*, int>> que;
    que.push({root, -minIdx});

    while(que.size() != 0)
    {
        int size = que.size();
        while(size--){
            pair<Node*, int> rvtx = que.front();
            que.pop();
            VO[rvtx.second].push_back(rvtx.first->data);
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second-1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second+1});
        }
    }
    
    for(vector<int> v : VO)
    {
        for(int ele : v)
            cout<<ele<<" ";
        cout<<"\n";
    }

}

void verticalOrderSum(Node* root){

    width(root, 0);
    int size = maxIdx - minIdx + 1;
    vector<int> sum(size, 0);

    queue<pair<Node*, int>> que;
    que.push({root, -minIdx});

    while(que.size() != 0)
    {
        int size = que.size();
        while(size--){
            pair<Node*, int> rvtx = que.front();
            que.pop();
            sum[rvtx.second] += rvtx.first->data;
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second-1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second+1});
        }
    }

    for(int ele : sum)
        cout<<ele<<" ";

}

void bottomView(Node* root){

    width(root,0);
    int size = maxIdx - minIdx + 1;

    vector<int> arr(size);

    queue<pair<Node*, int>> que;
    que.push({root, -minIdx});

    while(que.size() != 0){
        int size = que.size();
        while(size--){
            pair<Node*, int> rvtx = que.front();
            que.pop();
            arr[rvtx.second] = rvtx.first->data;
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second - 1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second + 1});
        }
    }

    for(int ele : arr)
        cout << ele << " "; 
}

void topView(Node* root){

    width(root, 0);
    int size = maxIdx - minIdx + 1;

    vector<int> arr(size, -1);

    queue<pair<Node*, int>> que;
    que.push({root, -minIdx});

    while(que.size() != 0){
        int size = que.size();
        while(size--){
            pair<Node*, int> rvtx = que.front();
            que.pop();
            if(arr[rvtx.second] == -1)
                arr[rvtx.second] = rvtx.first->data;
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second - 1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second + 1});
        }
    }

    for(int ele : arr)
        cout << ele << " "; 

}

void leftSide(Node* root, vector<Node*>& arr){
    
    if(root != nullptr){
        if(root->left != nullptr)
        {
            arr.push_back(root);
            leftSide(root->left, arr);
        }
        else if(root->right != nullptr)
        {
            arr.push_back(root);
            leftSide(root->right, arr);
        }
    }
    
}

void rightSide(Node* root, vector<Node*>& arr){

    if(root != nullptr){
        if(root->right != nullptr)
        {
            arr.push_back(root);
            rightSide(root->right, arr);
        }
        else if(root->left != nullptr)
        {
            arr.push_back(root);
            rightSide(root->left, arr);
        }
    }

}

void onlyLeaf(Node* root, vector<Node*>& arr)
{
    if(root == nullptr)
        return;
    if(root != nullptr){
        if(root->left == nullptr && root->right == nullptr)
        {
            arr.push_back(root);
        }
    }
    onlyLeaf(root->left, arr);
    onlyLeaf(root->right, arr);
}

void boundaryView(Node* root){

    vector<Node*> arr1, arr2, arr3;
    leftSide(root, arr1);
    onlyLeaf(root, arr2);
    rightSide(root->right, arr3);
    reverse(arr3.begin(), arr3.end());

    for(Node* n : arr1)
        cout<<n->data<<" ";

    for(Node* n : arr2)
        cout<<n->data<<" ";

    for(Node* n : arr3)
        cout<<n->data<<" ";
}

void diagnalView(Node* root){

    width(root, 0);
    int size = -minIdx + 1;
    vector<vector<int>> arr(size, vector<int>());

    queue<pair<Node*, int>> que;
    que.push({root,-minIdx});

    while(que.size() != 0)
    {
        int size = que.size();
        while(size-->0)
        {
            pair<Node*, int> rvtx = que.front();
            que.pop();
            arr[rvtx.second].push_back(rvtx.first->data);
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second-1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second});
        }
    }

    for(vector<int>& v : arr)
    {
        for(int ele : v)
            cout<<ele<<" ";
        cout<<"\n";
    }

}

void diagnalSum(Node* root){

    width(root, 0);
    int size = -minIdx + 1;
    vector<int> arr(size,0);

    queue<pair<Node*, int>> que;
    que.push({root,-minIdx});

    while(que.size() != 0)
    {
        int size = que.size();
        while(size-->0)
        {
            pair<Node*, int> rvtx = que.front();
            que.pop();
            arr[rvtx.second]+=(rvtx.first->data);
            if(rvtx.first->left != nullptr)
                que.push({rvtx.first->left, rvtx.second-1});
            if(rvtx.first->right != nullptr)
                que.push({rvtx.first->right, rvtx.second});
        }
    }

    for(int v : arr)
    {
        cout<<v<<" ";
    }

}

// Convert a Binary Tree into Doubly Linked List -> Inorder
Node* DLLhead = nullptr;
Node* DLLprev = nullptr;

void DLL(Node* node)
{
    if(node == nullptr)
        return;
    
    DLL(node->left);
    if(DLLhead == nullptr){
        DLLhead = node;
    }else{
        DLLprev->right = node;
        node->left = DLLprev;
    }
    DLLprev = node;
    DLL(node->right);

}

void set2(Node* node){
    DLL(node);
    while(DLLhead!=nullptr){
        cout<<DLLhead->data<<" ";
        DLLhead = DLLhead->right;
    }
}

class allSolution{

    public:
        int size = 0;
        int height = 0;
        bool find = false;

        Node* prec = nullptr;
        Node* succ = nullptr;
        Node* prev = nullptr;

};


void allSol(Node* root, int level, int data, allSolution pair)
{
    if(root == nullptr)
        return;
    
    // pair.size++;
    // pair.height = max(pair.height, level);
    // pair.find = pair.find || (data == root->data);cout<<"hi";


    if(root->data == data && pair.prec == nullptr)
    {
        pair.prec = pair.prev;
        cout<<"Pred : "<<pair.prec->data<<"\n";
    }

    if(pair.prev != nullptr && pair.prev->data == data && pair.succ == nullptr)
    {
        pair.succ = root;
        cout<<"Succ :" << pair.succ->data<<"\n";
    }

    pair.prev = root;
    allSol(root->left, level + 1, data, pair);
    allSol(root->right, level + 1, data, pair);
}


void solution(Node* root){

    cout<<"hi";
    allSolution pair;
    allSol(root, 0, 60, pair);
    cout<<pair.succ->data<<" ";

}

void view(Node* root)
{
    // leftView(root);
    // rightView(root);
    // verticalOrder(root);
    // verticalOrderSum(root);
    // bottomView(root);
    // topView(root);
    // boundaryView(root);
    // diagnalView(root);
    diagnalSum(root);
}

void rootToNodePath(Node* root)
{
    // vector<Node*> path;
    // int data = 120;
    // // rootToNodePath_(root, data, path);

    // // for(Node* n : path){
    // //     cout << n->data << " ";
    // // }

    // path = rootToNodePath_02(root, data);
    // for(Node* n : path)
    //     cout << n->data << " ";

    allNodesKAway_02(root, 20, 2);
}


void Traversal(Node* root)
{
    postOrder(root);
}


void Basic(Node* root)
{
    cout<<find(root, 150);
}

void solve()
{
    vector<int> arr = {10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    // vector<int> arr = {11,6,4,-1,5,-1,-1,8,-1,10,-1,-1,19,17,-1,-1,43,31,-1,-1,49,-1,-1};
    Node* root = constructTree(arr);
    // cout << idx;
    // Basic(root);
    // Traversal(root);
    // rootToNodePath(root);
    // levelOrder(root);
    // view(root);
    // set2(root);
    solution(root);
}

int main()
{
    solve();
    return 0;
}