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


void basic(Node* root){
    // cout<<height(root);
    // cout<<size(root);
    // cout<<find(root, 600);
    // cout<<maximum(root);
    cout<<minimum(root);
}


void solve(){

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

    Node* root = constructBST(arr,0,arr.size() -1);

    // display(root);
    basic(root);

}



int main()
{
    solve();
    return 0;
}