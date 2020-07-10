#include <iostream>
#include <vector>
#include <string>
using namespace std;
void LIS_L2R(vector<int>& arr, vector<int>& dp)
{
    int N = arr.size();

    for(int i=0;i<N;i++)
    {
        dp[i] = arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
}
void LIS_R2L(vector<int>& arr, vector<int>& dp)
{
    int N = arr.size();

    for(int i=N-1;i>=0;i--)
    {
        dp[i] = arr[i];
        for(int j=i+1;j<=N;j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
}

int maximumSumBiotonicSubsequence(vector<int>& arr)
{
    int N = arr.size();
    
    vector<int> dp1(N);
    vector<int> dp2(N);

    LIS_L2R(arr, dp1);
    LIS_R2L(arr, dp2);

    int maxSum = 0;
    for(int i=0;i<N;i++)
    {
        maxSum = max(maxSum, dp1[i] + dp2[i] - arr[i]);
    }

    return maxSum;
}

void solve()
{
    
    vector<int> arr = {47 ,92 ,21 ,117 ,34 ,63 ,51 ,77 ,2 ,106 ,46 ,45 ,88 ,57};

    cout << maximumSumBiotonicSubsequence(arr);
}

int main()
{
    solve();
    return 0;
}