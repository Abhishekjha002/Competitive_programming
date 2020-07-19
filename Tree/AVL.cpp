#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    
    public:
        int data;
        int height = 0;
        int bal = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    Node(int data)
    {
        this->data = data;
        this->height = 0;
        this->bal = 0;
    }
    Node(){        
    }
};



void updateHeightAndBalance(Node* node){ // O(1)

    int lh = -1;
    int rh = -1;

    if(node->left != nullptr)
        lh = node->left->height;
    
    if(node->right != nullptr)
        rh = node->right->height;

    node->height = max(lh, rh) + 1;
    node->bal = lh - rh;
}

Node* constructBST(vector<int>& arr, int si, int ei){
    
    if(si > ei)
        return nullptr;
    
    int mid = (si+ei)/2;
    
    Node* root = new Node(arr[mid]);
    root->left = constructBST(arr, si, mid-1);
    root->right = constructBST(arr, mid+1, ei);

    updateHeightAndBalance(root);
    return root;
}

void display(Node *node) // O(n)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data) + "[" + to_string(node->left->bal) + "," + to_string(node->left->height) + "]" : ".");
    str += " <- " + to_string(node->data) + "[" + to_string(node->bal) + "," + to_string(node->height) + "]" + " -> ";
    str += ((node->right != nullptr) ? to_string(node->right->data) + "[" + to_string(node->right->bal) + "," + to_string(node->right->height) + "]" : ".");
    cout << (str) << endl;

    display(node->left);
    display(node->right);
}

//ll Rotation. ==============================================

Node* ll(Node* A){  // O(1)
    
    Node* B = A->left;
    Node* BkaRight = B->right;
    B->right = A;
    A->left = BkaRight;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);
    
}


//rr Rotation. ==============================================

Node* rr(Node* A){  // O(1)
    
    Node* B = A->right;
    Node* BkaLeft = B->left;
    B->left = A;
    A->right = BkaLeft;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);    
}

Node* getRotation(Node* node)
{
    updateHeightAndBalance(node);
    if(node->bal == 2)  // ll or lr
    {
        if(node->left->bal == 1) // ll
        {
            return ll(node);
        }
        else if(node->left->bal == -1) //lr
        {
            node->left = rr(node->left);
            return ll(node);
        }
    }
    else if(node->bal == -2) // rr or rl
    {
        if(node->right->bal == -1) // rr
        {
            return rr(node);
        }
        else if(node->right->bal == 1) // rl
        {
            node->right = ll(node->right);
            return rr(node);
        }
    }

    return node;
}

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
    return getRotation(root);
}

int maximum(Node *node) // O(logn)
{
    Node *curr = node;
    while (curr->right != nullptr)
        curr = curr->right;

    return curr->data;
}

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

    return getRotation(root);
}


void solve()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node* root = constructBST(arr,0,arr.size() -1);

    root = addData(root, 55);
    root = addData(root, 57);
    display(root);
    cout<<endl<<endl<<endl;

    root = removeData(root, 50);
    display(root);
}

int main()
{
    solve();
    return 0;
}