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

void solve()
{
    vector<int> arr = {2,-1,8,6,9,4,3,5};
    vector<int> ans = nsol(arr);
    for(int i : ans)
    {
        cout<<i<<" , ";
    }
}
int main()
{
    solve();
    return 0;
}