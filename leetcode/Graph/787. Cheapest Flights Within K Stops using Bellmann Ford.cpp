class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int INF = 1e8;
        K++;
        
        vector<vector<int>> dp(n, vector<int>(K + 1, INF));
        dp[src][0] = 0;
        
        for(int k=1;k<=K;k++)
        {
            for(int i=0;i<n;i++)    
                dp[i][k] = dp[i][k-1];
            
            for(vector<int>& e : flights)
            {
                dp[e[1]][k] = min(dp[e[1]][k], dp[e[0]][k-1] + e[2]);
            }
        }
        
        return dp[dst][K] == INF ? -1 : dp[dst][K]; 
    }
};