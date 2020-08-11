#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D(vector<vector<int>> &arr)
{
    for (vector<int> ar : arr)
        display(ar);
    cout << endl;
}

//CutType.=============================================================
int MCM_rec(vector<int>& arr, int si, int ei, vector<vector<int>>& dp)
{
    if(si+1 == ei)
        return dp[si][ei] = 0;
    
    if(dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e8;
    
    for(int cut=si+1;cut<ei;cut++)
    {
        int leftCost = MCM_rec(arr, si, cut, dp);
        int rightCost = MCM_rec(arr, cut, ei, dp);

        int myCost = leftCost + arr[si]*arr[cut]*arr[ei] + rightCost;

        ans = min(ans, myCost);
    }

    return dp[si][ei] = ans;
}

int MCM_DP(vector<int>& arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    vector<vector<string>> sdp(n, vector<string>(n,""));

    for(int gap=1;gap<n;gap++)
    {
        for(int si=0,ei=gap;ei<n;si++,ei++)
        {
            if(si+1 == ei)
            {
                dp[si][ei] = 0;
                sdp[si][ei] = (char)('A' + si);
                continue;
            }

            int ans = 1e8;
            string sans = "";
            for(int cut=si+1;cut<ei;cut++)
            {
                int leftCost = dp[si][cut]; //MCM_rec(arr, si, cut, dp);
                int rightCost = dp[cut][ei]; //MCM_rec(arr, cut, ei, dp);

                int myCost = leftCost + arr[si]*arr[cut]*arr[ei] + rightCost;

                if(myCost < ans)
                {
                    ans = myCost;
                    sans = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }

            dp[si][ei] = ans;
            sdp[si][ei] = sans;
        }
    }

    cout<< sdp[0][n-1]<<"\n";
    cout << dp[0][n-1];
}

int costOfSearching(vector<int> &freq, int si, int ei)
{
    int sum = 0;
    for (int i = si; i <= ei; i++)
        sum += freq[i];
    return sum;
}


int OBST_rec(vector<int>& arr, int si, int ei, vector<vector<int>>& dp, vector<int>& prefix)
{
    if(dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e8;

    for(int cut=si;cut<=ei;cut++)
    {
        int leftCost = (cut == si) ? 0 : OBST_rec(arr, si, cut-1, dp, prefix);
        int rightCost = (cut == ei) ? 0 : OBST_rec(arr, cut+1, ei, dp, prefix);

        int myCost = leftCost + (prefix[ei+1] - prefix[si]) + rightCost;
        ans = min(ans, myCost);
    }

    return dp[si][ei] = ans;
}

int OBST_DP(vector<int>& arr, int si, int ei, vector<vector<int>>& dp, vector<int>& prefix)
{
    int n = arr.size();
    for(int gap=0;gap<n;gap++)
    {
        for(si=0,ei=gap;ei<n;si++,ei++)
        {
            int ans = 1e8;

            for(int cut=si;cut<=ei;cut++)
            {
                int leftCost = (cut == si) ? 0 : dp[si][cut-1];
                int rightCost = (cut == ei) ? 0 : dp[cut+1][ei];

                int myCost = leftCost + (prefix[ei+1] - prefix[si]) + rightCost;
                ans = min(ans, myCost);
            }

            dp[si][ei] = ans;
        }
    }

    return dp[0][n-1];
}



void OBST()
{
    vector<int> keys{10, 12, 20};
    vector<int> freq{34, 8, 50};

    vector<int> prefix(freq.size() + 1, 0);
    for(int i=1;i<prefix.size();i++)
        prefix[i] = prefix[i-1] + freq[i-1];

    vector<vector<int>> dp(freq.size(), vector<int>(freq.size(), -1));

    cout<<OBST_DP(keys, 0, keys.size()-1, dp, prefix);
}

// Leetcode : 312. Burst Balloons

int burstBallons(vector<int>& arr, int si, int ei, vector<vector<int>>& dp)
{
    if(dp[si][ei] != -1)
        return dp[si][ei];
    
    int lVal = (si == 0) ? 1 : arr[si-1];
    int rVal = (ei == arr.size() - 1) ? 1 : arr[ei+1];
    
    int ans = 0;
    
    for(int cut=si;cut<=ei;cut++)
    {
        int leftCost = (cut == si) ? 0 : burstBallons(arr, si, cut-1, dp);
        int rightCost = (cut == ei) ? 0 : burstBallons(arr, cut+1, ei, dp);
        
        int myCost = leftCost + lVal*arr[cut]*rVal + rightCost;
        ans = max(ans, myCost);
    }
    
    return dp[si][ei] = ans;
}
int maxCoins(vector<int>& nums) {
    
    int n = nums.size();
    if(n == 0)
        return 0;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    return burstBallons(nums, 0, n-1, dp);
    
}



void MCM()
{
    vector<int> arr{40, 20, 30, 10, 30};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    cout<<MCM_rec(arr, 0, n-1, dp)<<"\n";
    MCM_DP(arr);
    display2D(dp);
}

void cutType()
{
    // MCM();
    OBST();
}

void solve()
{
    cutType();
}



int main()
{
    solve();
    return 0;
}



