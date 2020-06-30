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

// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0

//Substring and Subsequence Series.=========================================================================

vector<vector<bool>> isPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap == 0)
                dp[i][j] = true;
            else if(gap == 1 && str[i] == str[j])
                dp[i][j] = true;
            else
                dp[i][j] = str[i] == str[j] && dp[i+1][j-1];
        }
    }

    return dp;
}

//Leetcode 005.==================================================================
string longestPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n,vector<int>(n,0));

    int maxLen = 0;
    int si=0,ei=0;
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap == 0)
                dp[i][j] = 1;
            else if(gap == 1 && str[i] == str[j])
                dp[i][j] = gap + 1;
            else if(str[i] == str[j] && dp[i+1][j-1] != 0)
                dp[i][j] = gap + 1; 

            if(dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                si = i;
                ei = j;
            }
        }
    }
    
    return str.substr(si, (ei - si + 1));
}

// Leetcode : 647. Palindromic Substrings

int countAllPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n,vector<int>(n,0));

    int count = 0;

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap == 0)
                dp[i][j] = 1;
            else if(gap == 1 && str[i] == str[j])
                dp[i][j] = gap + 1;
            else if(str[i] == str[j] && dp[i+1][j-1] != 0)
                dp[i][j] = gap + 1; 

            count += dp[i][j] > 0 ? 1 : 0; 
        }
    }
    
    return count;
}

// Leetcode : 516. Longest Palindromic Subsequence
int longestPlaindromeSubseq_Rec(string str, int si, int ei, vector<vector<int>>& dp, vector<vector<bool>>& isPalindrome)
{
    if(isPalindrome[si][ei])
        return dp[si][ei] = (ei - si + 1);
    
    if(dp[si][ei] != -1)
        return dp[si][ei];

    int len = 0;

    if(str[si] == str[ei])
        len = longestPlaindromeSubseq_Rec(str, si + 1, ei - 1, dp, isPalindrome) + 2;
    else
        len = max(longestPlaindromeSubseq_Rec(str, si , ei - 1, dp, isPalindrome), longestPlaindromeSubseq_Rec(str, si + 1, ei, dp, isPalindrome));
    
    return dp[si][ei] = len;
}

int longestPlaindromeSubseq_DP(string str, int si, int ei, vector<vector<int>>& dp, vector<vector<bool>>& isPalindrome)
{
    int n = str.length();

    for(int gap = 0; gap < n; gap++)
    {
        for(si = 0, ei = gap; ei < n; si++, ei++)
        {
            if(isPalindrome[si][ei])
            {
                dp[si][ei] = (ei - si + 1);
                continue;
            }


            int len = 0;
            if(str[si] == str[ei])
                len = dp[si+1][ei-1] + 2;
            else
                len = max(dp[si][ei-1], dp[si+1][ei]);
            
            dp[si][ei] = len;
        }
    }
    return dp[0][n-1];
}


//Leetcode 115 : distinct-subsequences.=========================================================

int distinct_subsequences(string& S, string& T, int n, int m, vector<vector<int>>& dp)
{
    if(m == 0)
        return 1;
    
    if(n < m)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(S[n-1] == T[m-1])
        return dp[n][m] = distinct_subsequences(S, T, n - 1, m, dp) + distinct_subsequences(S, T, n - 1, m - 1, dp);

    return dp[n][m] = distinct_subsequences(S, T, n - 1, m, dp);
}

int distinct_subsequences_DP(string& S, string& T, int n, int m, vector<vector<int>>& dp)
{
    int N = n, M = m;

    for(n = 0; n <= N; n++)
    {
        for(m = 0; m <= M; m++)
        {
            if(m == 0)
            {
                dp[n][m] = 1;
                continue;
            }
            
            if(n < m)
            {
                dp[n][m] = 0;
                continue;
            }

            if(S[n-1] == T[m-1])
                dp[n][m] = dp[n-1][m] + dp[n-1][m-1];

            else
                dp[n][m] = dp[n-1][m];
        }
    }
    return dp[N][M];
}

int distinct_subsequences_02(string& S, string& T, int i, int j, vector<vector<int>>& dp)
{
    if(j == T.length())
        return 1;
    
    if(T.length() - j > S.length() - i)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(S[i] == T[j])
        return dp[i][j] = distinct_subsequences_02(S, T, i + 1, j, dp) + distinct_subsequences_02(S, T, i + 1, j + 1, dp);

    return dp[i][j] = distinct_subsequences_02(S, T, i + 1, j, dp);
}

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << distinct_subsequences(s, t, n, m, dp) << endl;
    // cout << distinct_subsequences_DP(s, t, n, m, dp) << endl;

    display2D(dp);
}

//Geeks: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

int countPS(string s, int i, int j, vector<vector<int>>& dp)
{
    if(i > j)
        return dp[i][j] = 0;

    if(i == j)
        return dp[i][j] = 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int middleString = countPS(s, i + 1, j - 1, dp);
    int excludingLast = countPS(s, i, j - 1, dp);
    int excludingFirst = countPS(s, i + 1, j, dp);

    if(s[i] == s[j])
        return dp[i][j] = middleString + 1 + excludingLast + excludingFirst - middleString;
    
    return dp[i][j] = excludingLast + excludingFirst - middleString;

}

int countPS_(string s, int i, int j, vector<vector<int>>& dp)
{
    if(i > j)
        return dp[i][j] = 0;

    if(i == j)
        return dp[i][j] = 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int middleString = countPS_(s, i + 1, j - 1, dp);
    int excludingLast = countPS_(s, i, j - 1, dp);
    int excludingFirst = countPS_(s, i + 1, j, dp);

    int ans = excludingFirst + excludingLast;
    return dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;

}

int countPS_DP(string s, int i, int j, vector<vector<int>>& dp)
{
    int n = s.length();
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            int middleString = dp[i + 1][j - 1];
            int excludingLast = dp[i][j - 1];
            int excludingFirst = dp[i + 1][j];

            int ans = excludingFirst + excludingLast;
            dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;
        }
    }
    return dp[0][n - 1];
}


void stringSubstringSet()
{
    string str = "geeksforgeeks";
    int n = str.length();
    int si = 0, ei = n - 1;
    vector<vector<bool>> ispalindrome = isPlaindromeSubstring(str);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << countAllPlaindromeSubstring("aaa");
    
    // cout << longestPlaindromeSubseq_Rec(str, si, ei, dp, ispalindrome) << "\n";

    // cout << longestPlaindromeSubseq_DP(str, si, ei, dp, ispalindrome) << "\n";

    cout << numDistinct("geeksforgeeks","gks") << "\n";
    display2D(dp);
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
    stringSubstringSet();
}


int main()
{
    solve();
}