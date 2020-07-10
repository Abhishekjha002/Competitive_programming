#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

void display(vector<int>& arr)
{
    for(int ele : arr)
        cout<<ele<<" ";
    cout<<"\n";
}

void display2D(vector<vector<int>>& arr)
{
    for(vector<int> ar : arr)
        display(ar);
    cout<<"\n";
}


int MCM_rec(vector<int>& arr, int si, int ei, vector<vector<int>>& dp)
{
    if(si + 1 == ei)
        return dp[si][ei] = 0;

    if(dp[si][ei] != -1)
        return dp[si][ei];

    int minCost = 1e8;
    for(int cut = si + 1; cut < ei; cut++)
    {
        int leftCut = MCM_rec(arr, si, cut, dp);
        int rightCut = MCM_rec(arr, cut, ei, dp);

        int cost = leftCut + arr[si]*arr[cut]*arr[ei] + rightCut;

        minCost = min(minCost, cost);
    }

    return dp[si][ei] = minCost;
}

int MCM_DP(vector<int>& arr, int si, int ei, vector<vector<int>>& dp)
{
    vector<vector<string>> sdp(arr.size(), vector<string>(arr.size(), ""));

    for(int gap = 1; gap < arr.size(); gap++)
    {
        for(si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if(si + 1 == ei)
            {
                dp[si][ei] = 0;
                sdp[si][ei] = (char)(si + 'A');
                continue;
            }


            int minCost = 1e8;
            string ans = "";
            for(int cut = si + 1; cut < ei; cut++)
            {
                int leftCut = MCM_rec(arr, si, cut, dp);
                int rightCut = MCM_rec(arr, cut, ei, dp);

                int cost = leftCut + arr[si]*arr[cut]*arr[ei] + rightCut;

                if(minCost > cost)
                {
                    minCost = cost;
                    ans = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }

            dp[si][ei] = minCost;
            sdp[si][ei] = ans;
        }
    }

    cout << sdp[0][arr.size() - 1] << "\n";
    return dp[0][arr.size()-1];
}


void solve()
{
    
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    // cout << MCM_rec(arr, 0, n-1, dp) << "\n";

    cout << MCM_DP(arr, 0, n-1, dp) << "\n";
    
    display2D(dp);
}

int main()
{
    solve();
    return 0;
}