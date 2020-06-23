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


// Leetcode : 84. Largest Rectangle in Histogram

vector<int> nsor(vector<int>& arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    
    vector<int> ans(n,n);
    
    for(int i=0;i<n;i++)
    {
        while(st.top() != -1 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
}
vector<int> nsol(vector<int>& arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    
    vector<int> ans(n,-1);
    
    for(int i=n-1;i>=0;i--)
    {
        while(st.top() != -1 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    
    int n = heights.size();
    vector<int> sol = nsol(heights);
    vector<int> sor = nsor(heights);
    
    int maxArea = 0;
    
    for(int i=0;i<n;i++)
    {
        int area = heights[i] * (sor[i] - sol[i] - 1);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}


int largestRectangleArea_02(vector<int>& heights) {
    
    int n = heights.size();
    
    stack<int> st;
    st.push(-1);
    
    int maxArea = 0;
    
    for(int i=0;i<n;i++)
    {
        while(st.top() != -1 && heights[st.top()] > heights[i])
        {
            int h = heights[st.top()];
            st.pop();
            int w = (i - st.top() - 1);
            int area = h*w;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    
    while(st.size() != 1)
    {
        int h = heights[st.top()];
        st.pop();
        int w = (n - st.top() - 1);
        int area = h*w;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
    
}

// Leetcode : 85. Maximal Rectangle

int maximalRectangle(vector<vector<char>>& matrix) {
        
    if(matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }
    
    int n = matrix.size();
    int m = matrix[0].size();
    int maxArea = 0;
    
    vector<int> temp(m,0);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x = matrix[i][j] - '0';
            if(x == 0)
                temp[j] = 0;
            else
                temp[j] += x;
        }
        
        int area = largestRectangleArea(temp);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}


// Leetcode : 42. Trapping Rain Water

int trap(vector<int>& height) {
        
    int n = height.size();
    
    vector<int> lMax(n,-1);
    vector<int> rMax(n,-1);
    
    int prev = -1;
    for(int i=0;i<n;i++)
    {
        lMax[i] = max(prev, height[i]);
        prev = lMax[i];
    }
    
    prev = -1;
    for(int i=n-1;i>=0;i--)
    {
        rMax[i] = max(prev, height[i]);
        prev = rMax[i];
    }
    
    int water = 0;
    for(int i=0;i<n;i++)
    {
        water += min(lMax[i], rMax[i]) - height[i];
    }
    
    return water;
    
}

int trap02(vector<int>& height) {
        
    int n = height.size();
    
    stack<int> st;
    st.push(-1);
    
    int water = 0;
    
    for(int i=0;i<n;i++)
    {
        while(st.top() != -1 && height[st.top()] <= height[i])
        {
            int w1 = height[st.top()];
            st.pop();
            if(st.top() != -1)
            {
                int h = i - st.top() - 1;
                int w2 = min(height[i], height[st.top()]) - w1;
                water += h * w2;
            }
        }
        st.push(i);
    }
    
    return water;
}

int trap03(vector<int>& height) {
        
    int n = height.size();
    
    int li = 0, ri = n-1, lMaxBH = 0, rMaxBH = 0;
    
    int water = 0;
    

    while(li < ri)
    {
        lMaxBH = max(lMaxBH, height[li]);
        rMaxBH = max(rMaxBH, height[ri]);
        
        if(lMaxBH <= rMaxBH)
            water += lMaxBH - height[li++];
        else
            water += rMaxBH - height[ri--];
    }
    
    return water;
    
}


// Leetcode : 155. Min Stack
class MinStack {
public:
    stack<long> st;
    long minSF;
    
    MinStack() {
        minSF = 0;
    }
    
    void push(int x) {
        
        if(st.size() == 0)
        {
            st.push(x);
            minSF = x;
            return;
        }
        
        if(minSF > x)
        {
            st.push(x - minSF + x);
            minSF = x;
        }
        else
        {
            st.push(x);
        }
        
        
    }
    
    void pop() {
        
        if(st.top() >= minSF)
        {
            st.pop();
        }
        else
        {
            minSF = minSF - st.top() + minSF;
            st.pop();
        }
    }
    
    int top() {
        
        if(st.top() > minSF)
            return st.top();
        
        return minSF; 
        
    }
    
    int getMin() {
        return (int) minSF;
    }
};

// Leetcode : 946. Validate Stack Sequences

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
    stack<int> st;
    int n = pushed.size();
    int j = 0;
    
    for(int i=0;i<n;i++)
    {
        while(st.size() != 0 && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
        st.push(pushed[i]);
    }
    
    while(st.size() != 0 && st.top() == popped[j])
    {
        st.pop();
        j++;
    }
    
    return st.size() == 0 ? true : false;
}

// Leetcode : 402. Remove K Digits
string removeKdigits(string num, int k) {
        
    int n = num.size();
    stack<char> st;
    
    for(int i=0;i<n;i++)
    {
        while(st.size() != 0 && st.top() > num[i] && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while(k--)
    {
        st.pop();
    }
    
    string s = "";
    while(st.size() != 0)
    {
        s += st.top();
        st.pop();
    }
    
    reverse(s.begin(),s.end());
    
    string ans = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '0')
            continue;
        else
        {
                ans = s.substr(i);
            break;
        }
    }
    
    return ans.size() == 0 ? "0" : ans;
}


// Leetcode : 316. Remove Duplicate Letters
string removeDuplicateLetters(string s) {
        
    stack<char> st;
    vector<int> freq(26,0);
    vector<int> seen(26,false);
    int n = s.size();
    
    
    for(int i=0;i<n;i++)
    {
        freq[s[i] - 'a']++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(seen[s[i] - 'a'])
        {
            freq[s[i] - 'a']--;
            continue;
        }
        
        while(st.size() != 0 && st.top() > s[i] && freq[st.top() - 'a'] > 1)
        {
            seen[st.top() - 'a'] = false;
            freq[st.top() - 'a']--;
            st.pop();
        }
        
        if(!seen[s[i] - 'a'])
        {
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
    }
    string ans = "";
    while(st.size() != 0)
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}






