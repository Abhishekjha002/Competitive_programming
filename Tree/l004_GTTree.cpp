#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Node{
    
    public:
        int data;
        vector<Node*> childs;
    Node(int data)
    {
        this->data = data;
    }
    Node(){        
    }
};

Node* constructGTTree(vector<int>& arr)
{
    stack<Node*> st;

    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i] != -1)
        {
            Node* node = new Node(arr[i]);
            st.push(node);
        }
        else
        {
            Node* node = st.top();  st.pop();
            st.top()->childs.push_back(node);
        }
        
    }

    return st.top();
}

void display(Node* root)
{
    string str = "";
    str += to_string(root->data) + " -> ";

    for(Node* child : root->childs)
    {
        str += to_string(child->data) + " ";
    }

    cout<<str<<"\n";

    for(Node* child : root->childs)
    {
        display(child);
    }

}

int height(Node* node)
{
    int h = -1;
    for(Node* child : node->childs)
        h = max(h, height(child));
    return h + 1;
}

int size(Node* node)
{
    int s = 0;
    for(Node* child : node->childs)
    {
        s += size(child);
    }

    return s + 1;
}

bool find(Node* node, int data)
{
    if(node->data == data)
        return true;
    
    bool res = false;
    for(Node* child : node->childs)
    {
        res = res || find(child, data);
    }

    return res;
}

bool rootToNodePath(Node* node, int data, vector<Node*>& path)
{
    if(node->data == data)
    {
        path.push_back(node);
        return true;
    }

    bool res = false;
    path.push_back(node);

    for(Node* child : node->childs)
    {
        res = res || rootToNodePath(child, data, path);
    }

    if(!res)
        path.pop_back();

    return res;

}

void levelOrder(Node* root)
{
    queue<Node*> que;
    que.push(root);

    while(que.size() != 0)
    {
        int size = que.size();
        while(size-->0)
        {
            Node* rvtx = que.front();
            cout<<rvtx->data<<" ";
            que.pop();
            for(Node* child : rvtx->childs)
                que.push(child);
        }
        cout<<"\n";
    }
}

bool isMirror(Node* root1, Node* root2)
{
    if(root1->data != root2->data || root1->childs.size() != root2->childs.size())
        return false;

    for(int i=0,j=root2->childs.size() - 1; j>=0 && i<root1->childs.size(); i++,j--)
    {
        Node* first = root1->childs[i];
        Node* last = root2->childs[j];

        if(!isMirror(first, last))
            return false;
    }

    return true;
}

Node* linearize(Node* root)
{
    if(root->childs.size() == 0)
        return root;
    
    int n = root->childs.size();
    Node* lastTail = linearize(root->childs[n-1]);

    for(int i=n-2;i>=0;i--)
    {
        Node* secondLastTail = linearize(root->childs[i]);

        secondLastTail->childs.push_back(root->childs[i+1]);   // connection between two linearize structure.

        root->childs.pop_back();  //remove last node.
    }

    return lastTail;
}


void flatten(Node* root)
{
    vector<Node*> nChilds;
    for(Node* child : root->childs)
    {
        flatten(child);
        nChilds.push_back(child);
        for(Node* ch : child->childs)
            nChilds.push_back(ch);
        child->childs.clear();
    }

    root->childs.clear();
    root->childs = nChilds;
}

int diam = 0;

int diameter(Node* root)
{
    if(root->childs.size() == 0)
        return -1;
    
    vector<int> h;
    for(int i=0;i<root->childs.size();i++)
    {
        h.push_back(height(root->childs[i]));
    }
    
    sort(h.begin(), h.end(), greater<int>());  //nLog(n)

    if(h.size() > 1)
        diam = max(diam, h[0] + h[1] + 2);
    
    return h[0];
}

int maxi(Node* root)
{
    int maxi_ = root->data;

    for(Node* child : root->childs)
    {
        maxi_ = max(maxi_, maxi(child));
    }

    return maxi_;
}


void solve()
{
    // vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1,-1};
    // vector<int> arr1 = {10, 20, 40, -1, 50, -1, 60, -1, -1, 30, 80, -1, 80, -1, -1, 20, 60, -1, 50, -1, 40, -1, -1, -1};
    // vector<int> arr2 = {10, 20, 40, -1, 50, -1, 60, -1, -1, 30, 80, -1, 80, -1, -1, 20, 60, -1, 50, -1, 40, -1, -1, -1};
    vector<int> arr = {1,2,4,-1,5,-1,-1,3,6,-1,7,-1,-1,-1};
    Node* root = constructGTTree(arr);
    // Node* root1 = constructGTTree(arr1);
    // Node* root2 = constructGTTree(arr2);
    // display(root);
    // cout<<height(root);
    // cout<<size(root);
    // cout<<find(root, 10000);
    // vector<Node*> path;
    // cout<<rootToNodePath(root, 1000, path)<<"\n";
    // for(Node* node : path)
    //     cout<<node->data<<" ";

    // levelOrder(root);
    // cout<<isMirror(root1, root2);
    // linearize(root);
    // flatten(root);
    // display(root);
    // diameter(root);
    // cout<<diam;
    cout<<maxi(root);
}


int main()
{
    solve();
    return 0;

}


