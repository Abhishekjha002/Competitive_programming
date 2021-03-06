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
    return max(height(node->left), height(node->right)) + 1;
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

bool rootToNodePath(Node* node, int data, vector<Node*>& arr)
{
    if(node == nullptr)
        return false;
    
    if(node->data == data)
    {
        arr.push_back(node);
        return true;
    }

    bool res = rootToNodePath(node->left, data, arr) || rootToNodePath(node->right, data, arr);

    if(res)
        arr.push_back(node);
    
    return res;
}

vector<Node*> rootToNodePath_02(Node* node, int data)
{
    if(node == nullptr)
        return {};
    
    if(node->data == data)
    {
        vector<Node*> base;
        base.push_back(node);
        return base;
    }

    vector<Node*> left = rootToNodePath_02(node->left, data); //In JAVA: O(1) & C++: O(1)
    if(left.size() != 0)
    {
        left.push_back(node);
        return left;
    }
    vector<Node*> right = rootToNodePath_02(node->right, data);
    if(right.size() != 0)
    {
        right.push_back(node);
        return right;
    }

    return {};
} 

vector<Node*> rootToNodePath_03(Node* node, int data)
{
    vector<Node*> res;
    if(node == nullptr)
        return res;
    
    if(node->data == data)
    {
        res.push_back(node);
        return res;
    }

    res = rootToNodePath_02(node->left, data); //In JAVA: O(1) & C++: O(N)
    if(res.size() != 0)
    {
        res.push_back(node);
        return res;
    }
    res = rootToNodePath_02(node->right, data);
    if(res.size() != 0)
    {
        res.push_back(node);
        return res;
    }

    return res;
}

// Leetcode 236. ===================================================================

Node* lowestCommonAncestor(Node* root, int p, int q)
{
    vector<Node*> path1;
    vector<Node*> path2;
    rootToNodePath(root, p, path1);
    rootToNodePath(root, q, path2);
    
    Node* prev = NULL;
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    
    while(i >= 0 && j >= 0)
    {
        if(path1[i]->data != path2[j]->data)
            break;
        prev = path1[i];
        i--;
        j--;
    }
    return prev;
}

Node* LCANode = nullptr;
bool lowestCommonAncestor_02(Node* root, int p1, int p2)
{
    if(root == nullptr)
        return false;
    
    bool selfDone = false;

    if(root->data == p1 || root->data == p2)
    {
        selfDone = true;
    }

    bool leftDone = lowestCommonAncestor_02(root->left, p1, p2);
    
    if(LCANode != nullptr)
        return true;
    
    bool rightDone = lowestCommonAncestor_02(root->right, p1, p2);

    if(LCANode != nullptr)
        return true;

    if((selfDone && leftDone) || (selfDone && rightDone) || (leftDone && rightDone))
        LCANode = root;

    return selfDone || leftDone || rightDone;

}

void KDown(Node* root, int level, Node* blockNode)
{
    if(root == nullptr || root == blockNode)
        return;
    
    if(level == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    KDown(root->left, level-1, blockNode);
    KDown(root->right, level-1, blockNode);

}

void allNodeKAway(Node* root, int target, int K)
{
    vector<Node*> path;
    rootToNodePath(root, target, path);

    Node* blockNode = nullptr;
    for(int i=0;i<path.size();i++)
    {
        if(K-i < 0)  
            break;
        KDown(path[i], K-i, blockNode);
        blockNode = path[i];
    }
}

int allNodeKAway_02_(Node* root, int target, int K)
{
    if(root == nullptr)
        return -1;
    
    if(root->data == target)
    {
        KDown(root, K, nullptr);
        return 1;
    }

    
    int leftDistance = allNodeKAway_02_(root->left, target, K);
    
    if(leftDistance != -1)
    {
        if(K - leftDistance >= 0)
            KDown(root, K - leftDistance, root->left);
        return leftDistance + 1;
    }

    int rightDistance = allNodeKAway_02_(root->right, target, K);
    
    if(rightDistance != -1)
    {
        if(K - rightDistance >= 0)
            KDown(root, K - rightDistance, root->right);
        return rightDistance + 1;
    }

    return -1;
}

void allNodeKAway_02(Node* root, int target, int K)
{
    int c = allNodeKAway_02_(root, target, K);
}

// Diameter of a Tree.###################################################################

int diameterOfTree(Node* root)
{
    if(root == nullptr)
        return 0;
    
    int ld = diameterOfTree(root->left);
    int rd = diameterOfTree(root->right);

    int lh = height(root->left);
    int rh = height(root->right);

    int myDia = lh + rh + 2;
    
    return max(ld, max(rd, myDia));
}

class diaPair{

public:
    int dia;
    int hei;
    
    diaPair(int dia, int hei)
    {
        this->dia = dia;
        this->hei = hei;
    }
};

diaPair diameterOfTree_02(Node* root)
{
    if(root == nullptr)
        return diaPair(0,-1);
    
    diaPair lr = diameterOfTree_02(root->left);
    diaPair rr = diameterOfTree_02(root->right);

    diaPair myRes = diaPair(0,-1);
    myRes.dia = max(max(lr.dia, rr.dia),(lr.hei + rr.hei + 2));

    myRes.hei = max(lr.hei, rr.hei) + 1;
    
    return myRes;
}

int diameter = 0;
int diameterOfTree_03(Node* root)
{
    if(root == nullptr)
        return -1;
    
    int lh = diameterOfTree_03(root->left);
    int rh = diameterOfTree_03(root->right);

    diameter = max(diameter, (lh + rh + 2));
    return max(lh,rh) + 1;
}

void solve()
{
    vector<int> arr = {10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    // vector<int> arr = {4, 3, 2, -1, -1, 1, -1, -1, 7, -1, -1};
    Node *root = constructTree(arr);
    //display(root);
    //preOrder(root);
    // vector<int> ans;
    // rootToNodePath(root, 100, ans);
    // for(int e : ans)
    //     cout<<e<<" ";

    // vector<Node*> ans = rootToNodePath_02(root, 100);
    // for(Node* n : ans)
    //     cout<<n->data<<"->";
    //Node* ans = lowestCommonAncestor(root, 50, 100);
    //cout<<ans->data;


    // lowestCommonAncestor_02(root, 40, 50);
    // cout<<LCANode->data;
    //allNodeKAway(root, 50, 4);
    //cout<<helper1(root, 60, 0);

    // allNodeKAway_02(root, 50 , 1);
    // cout<<diameterOfTree(root);
    
    diameterOfTree_03(root);
    cout<<diameter;
}



int main()
{
    solve();
    return 0;
}
