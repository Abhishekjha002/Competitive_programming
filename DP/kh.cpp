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

int fibo(int n, vector<int>& dp)
{
    if(n <= 1)
        return dp[n] = n;
    
    if(dp[n] != -1)
        return dp[n];

    int ans = fibo(n-1, dp) + fibo(n-2, dp);

    return dp[n] = ans;
}

int fiboDP(int n, vector<int>& dp)
{
    int N = n;
    for(n=0;n<=N;n++)
    {
        if(n <= 1)
        {   dp[n] = n;
            continue;
        }

        int ans = dp[n-1] + dp[n-2];//fibo(n-1, dp) + fibo(n-2, dp);

        dp[n] = ans;
    }

    return dp[N];
}


//MazePathSeries.==============================================

int mazePathHDV(int sr, int sc, int er, int ec, vector<vector<int>>& dp)
{
    if(sr == er && sc == ec)
        return dp[er][ec] = 1;
    
    if(dp[sr][sc] != -1)
        return dp[sr][sc];

    int count = 0;

    if(sr+1 <= er)
        count += mazePathHDV(sr+1, sc, er, ec, dp);

    if(sc+1 <= ec)
        count += mazePathHDV(sr, sc+1, er, ec, dp);
    
    if(sc+1 <= ec && sr+1 <= er)
        count += mazePathHDV(sr+1, sc+1, er, ec, dp);
    
    return dp[sr][sc] = count;

}

int mazePathHDV_DP(int sr, int sc, int er, int ec, vector<vector<int>>& dp)
{
    for(sr=er;sr>=0;sr--)
    {
        for(sc=ec;sc>=0;sc--)
        {
            if(sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            if(sr+1 <= er)
                count += dp[sr+1][sc];//mazePathHDV(sr+1, sc, er, ec, dp);

            if(sc+1 <= ec)
                count += dp[sr][sc+1];//mazePathHDV(sr, sc+1, er, ec, dp);
            
            if(sc+1 <= ec && sr+1 <= er)
                count += dp[sr+1][sc+1];//mazePathHDV(sr+1, sc+1, er, ec, dp);
            
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

int mazePathMulti(int sr, int sc, int er, int ec, vector<vector<int>>& dp)
{

    if(sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if(dp[sr][sc] != -1)
        return dp[sr][sc];

    int count = 0;

    for(int jump=1;jump+sr<=er;jump++)
    {
        count += mazePathMulti(sr+jump,sc,er,ec,dp);
    }

    for(int jump=1;jump+sc<=ec;jump++)
    {
        count += mazePathMulti(sr,sc+jump,er,ec,dp);
    }

    for (int jump=1;sr+jump<=er && sc+jump<=ec; jump++)
    {
        count += mazePathMulti(sr+jump,sc+jump,er,ec,dp);
    }

    
    return dp[sr][sc] = count;
    
}

int mazePathMulti_DP(int sr, int sc, int er, int ec, vector<vector<int>>& dp)
{

    for(sr=er;sr>=0;sr--)
    {
        for(sc=ec;sc>=0;sc--)
        {
            if(sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            for(int jump=1;jump+sr<=er;jump++)
            {
                count += dp[sr+jump][sc];//mazePathMulti(sr+jump,sc,er,ec,dp);
            }

            for(int jump=1;jump+sc<=ec;jump++)
            {
                count +=  dp[sr][sc+jump];//mazePathMulti(sr,sc+jump,er,ec,dp);
            }

            for (int jump=1;sr+jump<=er && sc+jump<=ec; jump++)
            {
                count +=  dp[sr+jump][sc+jump];//mazePathMulti(sr+jump,sc+jump,er,ec,dp);
            }

            
            dp[sr][sc] = count;
        }
    }
    
    return dp[0][0];
}

int boardPath(int sp, int ep, vector<int>& dp)
{
    if(sp == ep)
        return dp[sp] = 1;
    
    if(dp[sp] != -1)
        return dp[sp];

    int count = 0;

    for(int d = 1; d <= 6 && ep >= sp + d; d++)
    {
        count += boardPath(sp+d, ep, dp);
    }

    return dp[sp] = count;
}

int boardPathDP(int sp, int ep, vector<int>& dp)
{
    for(int sp = ep; sp >= 0; sp--)
    {
        if(sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;

        for(int d = 1;d <= 6 && ep >= sp + d;d++)
        {
            count += dp[sp+d];//boardPath(sp+d, ep, dp);
        }

        dp[sp] = count;
    }

    return dp[0];
}

int boardPath_best(int sp, int ep)
{
    list<int> ll;
    for(sp=ep;sp>=0;sp--)
    {
        if(sp > ep - 2)
        {
            ll.push_front(1);
            continue;
        }

        if(ll.size() <= 6)
        {
            ll.push_front(2 * ll.front());
        }
        else
        {
            ll.push_front(2 * ll.front() - ll.back());
            ll.pop_back();
        }
    }

    return ll.front();
}

int boardPathWithDiceArray(int sp, int ep, vector<int> &diceArray, vector<int>& dp)
{
    if(sp == ep)
        return dp[sp] = 1;
    
    if(dp[sp] != -1)
        return dp[sp];

    int count = 0;

    for(int d = 0; d < diceArray.size() && sp + diceArray[d] <= ep; d++)
    {
        count += boardPathWithDiceArray(sp + diceArray[d], ep, diceArray, dp);
    }

    return dp[sp] = count;
}


int boardPathWithDiceArray_DP(int sp, int ep, vector<int> &diceArray, vector<int>& dp)
{
    for(sp = ep; sp >= 0; sp--)
    {
        if(sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;

        for(int d = 0; d < diceArray.size() && sp + diceArray[d] <= ep; d++)
        {
            count += dp[sp + diceArray[d]];//boardPathWithDiceArray(sp + diceArray[d], ep, diceArray, dp);
        }

        dp[sp] = count;
    }
    return dp[0];
}

// Leetcode : 70. Climbing Stairs

int climbStairs_01(int n, vector<int>& dp)
{
    if(n <= 1)
        return dp[n] = 1;
    
    if(dp[n] != -1)
        return dp[n];
    
    int ans = climbStairs_01(n-1, dp) + climbStairs_01(n-2, dp);
    
    return dp[n] = ans;
}
int climbStairs_DP(int n, vector<int>& dp)
{
    int N = n;
    for(n=0;n<=N;n++)
    {
        if(n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int ans = dp[n-1] + dp[n-2];//climbStairs_01(n-1, dp) + climbStairs_01(n-2, dp);

        dp[n] = ans;
    }
    return dp[N];
}
int climbStairs(int n) {
    
    vector<int> dp(n+1, -1);
    
    return climbStairs_DP(n, dp);
    
}

// Leetcode : 746. Min Cost Climbing Stairs

int minCostClimbingStairs_01(vector<int>& cost, int n, vector<int>& dp)
{
    if(n <= 1)
        return dp[n] = cost[n];
    
    if(dp[n] != -1)
        return dp[n];
    
    int ans = min(minCostClimbingStairs_01(cost,n-1,dp), minCostClimbingStairs_01(cost,n-2,dp));
    
    return dp[n] = ans + cost[n];
}
int minCostClimbingStairs_DP(vector<int>& cost, int n, vector<int>& dp)
{
    int N = n;
    for(n=0;n<=N;n++)
    {
        if(n <= 1)
        {
            dp[n] = cost[n];
            continue;
        }
    
        int ans = min(dp[n-1], dp[n-2]);

        dp[n] = ans + cost[n];
    }
    
    return dp[N];
}
int minCostClimbingStairs(vector<int>& cost) {
    
    int size = cost.size();
    cost.push_back(0);
    
    vector<int> dp(size+1,-1);
    
    return minCostClimbingStairs_DP(cost,size,dp);
    
}

// Friend pairing problem : https://www.geeksforgeeks.org/friends-pairing-problem/

int friends_pairing_problem(int n, vector<int>& dp)
{
    if(n <= 1)
    {
        return dp[n] = 1;
    }

    if(dp[n] != -1)
        return dp[n];

    int single = friends_pairing_problem(n-1, dp);
    int pair = friends_pairing_problem(n-2, dp)*(n-1);

    return dp[n] = single + pair;
}

int friends_pairing_problem_DP(int n, vector<int>& dp)
{
    int N = n;
    for(n=0;n<=N;n++)
    {
        if(n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int single = dp[n-1];//friends_pairing_problem(n-1, dp);
        int pair = dp[n-2]*(n-1);//friends_pairing_problem(n-2, dp)*(n-1);

        dp[n] = single + pair;
    }
    return dp[N];
}

//Leetcode : 64. Minimum Path Sum

int minPathSum_(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(sr == grid.size() - 1 && sc == grid[0].size() - 1)
        dp[sr][sc] = grid[sr][sc];
    
    if(dp[sr][sc] != -1)
        return dp[sr][sc];
    
    int minCost = INT_MAX;
    
    if(sr+1 <= grid.size()-1)
        minCost = min(minCost, minPathSum_(sr+1,sc,grid,dp));
    
    if(sc+1 <= grid[0].size()-1)
        minCost = min(minCost, minPathSum_(sr,sc+1,grid,dp));
    
    return dp[sr][sc] = grid[sr][sc] + minCost;
    
}
int minPathSum_DP(vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    for(int sr=grid.size()-1;sr>=0;sr--)
    {
        for(int sc=grid[0].size()-1;sc>=0;sc--)
        {
            if(sr == grid.size() - 1 && sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int minCost = INT_MAX;

            if(sr+1 <= grid.size()-1)
                minCost = min(minCost, dp[sr+1][sc]);

            if(sc+1 <= grid[0].size()-1)
                minCost = min(minCost, dp[sr][sc+1]);

            dp[sr][sc] = grid[sr][sc] + minCost;   
        }
    }
    return dp[0][0];
}
int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    // return minPathSum_(0,0,grid,dp);
    return minPathSum_DP(grid,dp);
}

// Gold Mine Problem : https://www.geeksforgeeks.org/gold-mine-problem/

int gold_mine_problem(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if(dp[sr][sc] != -1)
        return dp[sr][sc];
        
    int dirN[3][2] = {{-1,1},{0,1},{1,1}};

    int maxCoins = 0;
    for(int i=0;i<3;i++)
    {
        int x = sr + dirN[i][0];
        int y = sc + dirN[i][1];
        
        if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
            maxCoins = max(maxCoins, gold_mine_problem(x, y, grid, dp));
    }

    return dp[sr][sc] = maxCoins + grid[sr][sc];
}

int gold_mine_problem_DP(vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    for(int sr=grid.size()-1;sr>=0;sr--)
    {
        for(int sc=grid[0].size()-1;sc>=0;sc--)
        {
            if(sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }
                
            int dirN[3][2] = {{-1,1},{0,1},{1,1}};

            int maxCoins = 0;
            for(int i=0;i<3;i++)
            {
                int x = sr + dirN[i][0];
                int y = sc + dirN[i][1];
                
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
                    maxCoins = max(maxCoins, dp[x][y]);//;max(maxCoins, gold_mine_problem(x, y, grid, dp));
            }

            dp[sr][sc] = maxCoins + grid[sr][sc];
        }
    }

    int ans = 0;
    for(int i=0;i<grid.size();i++)
    {
        ans = max(ans, dp[i][0]);
    }
    return ans;
}

int count_of_ways(int n, int k, vector<vector<int>>& dp)
{
    if(k == 1 || n == k)
        return dp[k][n] = 1;

    if(dp[k][n] != 0)
        return dp[k][n];

    int newGroup = count_of_ways(n-1, k-1, dp);
    int existingGroup = count_of_ways(n-1, k, dp)*k;

    return dp[k][n] = newGroup + existingGroup;
}

int count_of_ways_DP(int n, int k, vector<vector<int>>& dp)
{
    int N = n;
    int K = k;
    for(k=1;k<=K;k++)
    {
        for(n=0;n<=N;n++)
        {
            if(n < k)
            {
                dp[k][n] = 0;
                continue;
            }
            
            if(k == 1 || n == k)
            {
                dp[k][n] = 1;
                continue;
            }

            int newGroup = dp[k-1][n-1];//count_of_ways(n-1, k-1, dp);
            int existingGroup = dp[k][n-1]*k;//count_of_ways(n-1, k, dp)*k;

            dp[k][n] = newGroup + existingGroup;
        }
    }
    return dp[K][N];
}

int count_of_ways_02(int n, int k)
{
    if(k == 1)
        return 1;

    if(n < 2*k)
        return 0;

    if(n == 2*k)
        return (n-1)*k;

    int newGroup = count_of_ways_02(n-2, k-1) * (n - 1);
    int existingGroup = count_of_ways_02(n-1, k)*k;

    return newGroup + existingGroup;
}


vector<vector<bool>> isPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;i<n && j<n;i++,j++)
        {
            if(gap == 0)
                dp[i][j] = true;
            
            else if(gap == 1)
                dp[i][j] = s[i] == s[j];
            
            else
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
        }
    }

    return dp;
}

string longestIncreasingSubsequence_02(string str)
{
    int n = str.size();
    int maxLen = 1;
    int si = 0;
    int ei = 0;
    int low, high;

    for(int i=0;i<n;i++)
    {
        //even length
        low = i - 1;
        high = i;

        while(low >= 0 && high < n && str[low] == str[high])
        {
            if(high - low + 1 > maxLen)
            {
                maxLen = high - low + 1;
                si = low;
                ei = high;
            }
            low--;
            high++;
        }

        //odd Length
        low = i - 1;
        high = i + 1;

        while(low >= 0 && high < n && str[low] == str[high])
        {
            if(high - low + 1 > maxLen)
            {
                maxLen = high - low + 1;
                si = low;
                ei = high;
            }
            low--;
            high++;
        }
    }

    return str.substr(si, (ei - si + 1));
}



void set3()
{
    cout << longestIncreasingSubsequence_02("abccbefgpgf");
}

void set2()
{
    // int n = 6;
    // vector<int> dp(n+1,-1);
    // // cout<<friends_pairing_problem(n, dp)<<"\n";
    // cout<<friends_pairing_problem_DP(n,dp)<<"\n";
    // display(dp);
    int n = 5, k = 3;
    vector<vector<int>> dp(k+1, vector<int>(n+1,0));
    // cout << count_of_ways(n, k, dp)<<"\n";
    // display2D(dp);
    // cout << count_of_ways_02(6,3);
    cout << count_of_ways_DP(n, k, dp);
}

void pathSet()
{
    int er = 3;
    int ec = 3; 
    vector<int> dp(11,-1);
    // vector<vector<int>> dp(er, vector<int>(ec,-1)); 
    // cout<<mazePathHDV(0,0,er-1,ec-1, dp)<<"\n";

    // cout<<mazePathHDV_DP(0,0,er-1,ec-1,dp)<<"\n";
    // cout<<mazePathMulti(0,0,er-1,ec-1,dp)<<"\n";
    // cout<<mazePathMulti_DP(0,0,er-1,ec-1,dp)<<"\n";

    // cout<<boardPathDP(0,10, dp)<<"\n";
    // cout<<boardPath_best(0,10);
    vector<int> arr = {2,5,7,3};
    cout<<boardPathWithDiceArray_DP(0,10,arr,dp);
    // display(dp);
    // display2D(dp);
    

}

void set1()
{
    int n = 5;
    vector<int> dp(n+1,-1);
    // cout<<fibo(n,dp)<<"\n";
    cout<<fiboDP(n,dp)<<"\n";
    display(dp);
}
void solve()
{
    // set1();
    // pathSet();
    // set2();
    set3();
}


int main()
{
    solve();
}