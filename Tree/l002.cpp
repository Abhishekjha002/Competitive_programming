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

Node* constructBST(vector<int>& arr, int si, int ei){
    
    if(si > ei)
        return nullptr;
    
    int mid = (si+ei)/2;
    
    Node* root = new Node(arr[mid]);
    root->left = constructBST(arr, si, mid-1);
    root->right = constructBST(arr, mid+1, ei);

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

int height(Node* root){
    
    if(root == nullptr)
        return -1;
    
    return max(height(root->left), height(root->right)) + 1;
}

int size(Node* root){
    
    if(root == nullptr)
        return 0;
    
    return size(root->left) + size(root->right) + 1;
}

bool find(Node* root, int data){

    Node* curr = root;
    while(curr != nullptr){
        if(curr->data == data)
            return true;
        else if(curr->data < data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return false;
}

int maximum(Node* root){

    Node* curr = root;
    while(curr->right!=nullptr)
        curr = curr->right;
    return curr->data;

}

int minimum(Node* root){

    Node* curr = root;
    while(curr->left!=nullptr)
        curr = curr->left;
    return curr->data;

}

int LCAoFBST(Node* root, int a, int b)
{
    Node* curr = root;
    while(curr != nullptr){
        if(curr->data > a && curr->data > b)
            curr = curr->left;
        else if(curr->data < a && curr->data < b)
            curr = curr->right;
        else 
            return curr->data;
    }
    return -1;
}

int LCAoFBST_Rec(Node *node, int a, int b) 
{
    if (node == nullptr)
        return -1;

    if (b < node->data && a < node->data)
        return LCAoFBST_Rec(node->left, a, b);
    else if (a > node->data && b > node->data)
        return LCAoFBST_Rec(node->right, a, b);
    else
        return node->data; //LCA point.
}

void allNodesInRange_01(Node* root, int a, int b, vector<int>& arr){

    if(root == nullptr)
        return;

    allNodesInRange_01(root->left, a, b, arr);

    if(root->data >= a && root->data <= b)
        arr.push_back(root->data);
    
    allNodesInRange_01(root->right, a, b, arr);

}

void predAndSucc(Node* root, int data)
{
    Node* curr = root;
    Node* pred = nullptr;
    Node* succ = nullptr;

    while(curr != nullptr)
    {
        if(curr->data == data){
            if(curr->left == nullptr)
                cout<<"Pred : "<<((pred==nullptr) ? -1 : pred->data); 
            else
            {
                pred = curr->left;
                while(pred->right != nullptr)
                    pred = pred->right;
                cout<<"Pred : "<<pred->data;
            }

            if(curr->right == nullptr)
                cout<<"Succ : "<<((succ==nullptr) ? -1 : succ->data); 
            else
            {
                succ = curr->right;
                while(succ->left != nullptr)
                    succ = succ->left;
                cout<<"Succ : "<<succ->data;
            }   
            break;
        }
        else if(curr->data > data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if(curr->data < data)
        {
            pred = curr;
            curr = curr->right;
        }

    }

}

// Construct Binary Tree from PreOrder. - > O(N) ==========================================

int idx = 0;
Node* constructBSTfromPreOrder(vector<int>& arr, int lb, int ele, int rb)
{
    if(idx == arr.size() || ele < lb || ele > rb)
        return nullptr;
    
    Node* root = new Node(ele);
    idx++;

    if(idx != arr.size())
        root->left = constructBSTfromPreOrder(arr, lb, arr[idx], root->data);
    if(idx != arr.size())
        root->right = constructBSTfromPreOrder(arr, root->data, arr[idx], rb);

    return root;
}

Node* constructBSTfromPreOrder(vector<int>& arr, int lb, int rb)
{
    if(idx == arr.size() || arr[idx] < lb || arr[idx] > rb)
        return nullptr;

    Node* root = new Node(arr[idx]);
    idx++;

    root->left = constructBSTfromPreOrder(arr, lb, root->data);
    root->right = constructBSTfromPreOrder(arr, root->data, rb);

    return root;
}


int height(vector<int>& arr, int lb, int ele, int rb){
    if(idx == arr.size() || ele < lb || ele > rb)
        return -1;
    
    Node* root = new Node(ele);
    idx++;
    int lh, rh;

    if(idx != arr.size())
        lh = height(arr, lb, arr[idx], root->data);
    if(idx != arr.size())
        rh = height(arr, root->data, arr[idx], rb);

    return max(lh, rh) + 1;
}

void constructBSTfromPreOrder(vector<int>& arr){
    // Node* root = constructBSTfromPreOrder(arr, -1e8, arr[0], 1e8);
    Node* root = constructBSTfromPreOrder(arr, -1e8, 1e8);
    display(root); 
    idx = 0;
    cout<<height(arr, -1e8, arr[0], 1e8);
}

// Addition and Deletion in BST. =============================================================================
// Leetcode : 701.
Node* addData(Node* root, int data)
{
    if(root == nullptr)
        return new Node(data);

    if(root->data > data)
    {
        root->left = addData(root->left, data);
    }
    else
    {
        root->right = addData(root->right, data);    
    }

}

// Leetcode : 450.
Node* removeData(Node* root, int data)
{
    if(root == nullptr)
        return nullptr;
    
    if(root->data > data)
    {
        root->left = removeData(root->left, data);
    }
    else if(root->data < data)
    {
        root->right = removeData(root->right, data);
    }
    else  // Node is Found;
    {
        if(root->left == nullptr || root->right == nullptr)
            return root->left != nullptr ? root->left : root->right;

        int maxiInLeft = maximum(root->left);
        root->data = maxiInLeft;
        root->left = removeData(root->left, maxiInLeft);

    }
    
}


void InsertionAndDeletion(Node* root)
{
    int data = 75;
    Node* node = addData(root, data);
    display(node);
    cout<<"\n";
    Node* node1 = removeData(node, data);
    display(node1);
}


void basic(Node* root){
    // cout<<height(root);
    // cout<<size(root);
    // cout<<find(root, 600);
    // cout<<maximum(root);
    cout<<minimum(root);
}


void solve(){

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

    // vector<int> arr = {60,30,10,20,40,50,90,70,80,110,100,120};
    Node* root = constructBST(arr,0,arr.size() -1);

    // display(root);
    // basic(root);
    // predAndSucc(root, 90);
    // constructBSTfromPreOrder(arr);
    InsertionAndDeletion(root);

}



int main()
{
    solve();
    return 0;
}







