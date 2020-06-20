#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//next greater on right.
vector<int> ngor(vector<int>& arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for(int i=0;i<arr.size();i++)
    {
        while(st.size() != 0 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

//next greater on left.
vector<int> ngol(vector<int>& arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for(int i=0;i<arr.size();i++)
    {
        while(st.size() != 0 && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        if(st.size() != 0)
            ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> ngol_02(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i]) // for smaller replace to '<' to '>'
        {
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

//next smaller on right.
vector<int> nsor(vector<int>& arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for(int i=0;i<arr.size();i++)
    {
        while(st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

//next smaller on left.
vector<int> nsol(vector<int>& arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for(int i=arr.size()-1;i>=0;i--)
    {
        while(st.size() != 0 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

// Leetcode : 20. Valid Parentheses

bool isValid(string s) {
        
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if(st.size() == 0)
        {
            return false;
        }
        else
        {
            if(st.top() == '(' && ch != ')')
                return false;
            else if(st.top() == '{' && ch != '}')
                return false;
            else if(st.top() == '[' && ch != ']')
                return false;
            st.pop();
        }
    }
    
    return st.size() == 0 ? true : false;
    
}

// Leetcode : 1021. Remove Outermost Parentheses
string removeOuterParentheses(string str) {
        
    int count = 0;
    string ans = "";
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(' && count++ > 0)
            ans += str[i];
        if(str[i] == ')' && count-- > 1)
            ans += str[i];
    }
    
    return ans;
}

// Leetcode : 503. Next Greater Element II
vector<int> nextGreaterElements(vector<int>& arr) {
        
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=0;i<2*n;i++)
    {
        while(st.size() != 0 && arr[st.top()] < arr[i%n])
        {
            ans[st.top()] = arr[i%n];
            st.pop();
        }
        
        if(ans[i%n] == -1)
            st.push(i%n);
        
    }
    
    return ans;
}

// Leetcode : 901. Online Stock Span
class StockSpanner {
    stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
        st.push({-1,-1});
        i = 0;
    }
    
    int next(int price) {
        
        int ans = 1;
        while(st.top().first != -1 && st.top().second <= price)
        {
            st.pop();
        }
        
        ans = i - st.top().first;
        st.push({i,price});
        i++;
        
        return ans;
        
    }
};


// Leetcode : 921. Minimum Add to Make Parentheses Valid

int minAddToMakeValid(string str) {
        
    int openingReq = 0;
    int closingReq = 0;
    
    int n = str.size();
    
    for(int i=0;i<n;i++)
    {
        if(str[i] == '(')
            closingReq++;
        else if(closingReq > 0)
            closingReq--;
        else
            openingReq++;
    }
    
    return openingReq + closingReq;
        
}

// Leetcode : 1249. Minimum Remove to Make Valid Parentheses

    string minRemoveToMakeValid(string str) {
        
        int n = str.size();
        vector<bool> check(n,false);
        stack<int> st;
        st.push(-1);
        
        
        for(int i=0;i<n;i++)
        {
            if(st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
            {
                check[st.top()] = true;
                check[i] = true;
                st.pop();
            }
            else if(str[i] == '(')
                st.push(i);
            else if(str[i] != ')')
                check[i] = true;
        }
        
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(check[i])
                ans += str[i];
        }
        
        return ans;
    }

// Leetcode : 32. Longest Valid Parentheses

int longestValidParentheses(string str) {
        
        int n = str.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
            {
                st.pop();
                ans = max(ans, i-st.top());
            }
            else
                st.push(i);
        }
        
        return ans;
}

// Leetcode : 735. Asteroid Collision
vector<int> asteroidCollision(vector<int>& arr) {
    
    int n = arr.size();
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] > 0){
            st.push(arr[i]);
        }
        else
        {
            while(st.size() != 0 && st.top() > 0 && st.top() < -arr[i])
                st.pop();
            
            if(st.size() != 0 && st.top() == -arr[i])
                st.pop();
            
            else if(st.size() == 0 || st.top() < 0)
                st.push(arr[i]);
        }
    }
    
    vector<int> ans(st.size(),0);
    int i = st.size() - 1;
    
    while(st.size() != 0)
    {
        ans[i--] = st.top();
        st.pop();
    }
    
    return ans;
    
}
