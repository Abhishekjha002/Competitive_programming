#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    
        Node(int data)
        {
            this->data = data;
        }
        //default
        Node()
        {

        }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{
    if(arr.size() <= idx || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node* node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);

    return node;
}

void display(Node* node)
{
    if(node == nullptr)
        return;

    string str = "";

    str += ((node->left != nullptr) ? to_string(node->left->data) : ".");
    str += "<-" + to_string(node->data) + "->";
    str += ((node->right != nullptr) ? to_string(node->right->data) : ".");

    cout<<str<<"\n";

    display(node->left);
    display(node->right);

}

//Basic.================================================================
int size(Node* node)
{
    if(node == nullptr)
        return 0;   
    return (size(node->left) + size(node->right) + 1);
}

int height(Node* node)
{
    if(node == nullptr)
        return -1;          // return -1, height w.r.t edge, return 0, height w.r.t node.
    return max(max(height(node->left), height(node->right)), node->data);
}

int Maximum(Node* node)
{
    if(node == nullptr)
        return INT_MIN;
    return max(max(Maximum(node->left), Maximum(node->right)), node->data);
}

int Minimum(Node* node)
{
    if(node == nullptr)
        return INT_MAX;
    return min(min(Minimum(node->left), Minimum(node->right)), node->data);
}

int Minimum_02(Node* node)
{
    int min_ = node->data;
    if(node->left != nullptr)   min_ = min(min_, Minimum_02(node->left));
    if(node->right != nullptr)   min_ = min(min_, Minimum_02(node->right));
}

bool find(Node* node, int data)
{
    if(node == nullptr)
        return false;
    
    if(node->data == data)
        return true;
    
    return find(node->left, data) || find(node->right, data);
}

//Traversal.============================================================

void preOrder(Node* node)
{
    if(node == nullptr)
        return;

    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node)
{
    if(node == nullptr)
        return;

    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

void postOrder(Node* node)
{
    if(node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}


void solve()
{
    vector<int> arr = {10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    Node *root = constructTree(arr);
    //display(root);
    preOrder(root);
}
int main()
{
    solve();
    return 0;
}
