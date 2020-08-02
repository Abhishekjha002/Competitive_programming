#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N = 5;

vector<int> kahn_Algo(vector<vector<int>>& graph)
{
    vector<int> inDegree(N,0);

    for(vector<int> ar : graph)
    {
        for(int ele : ar)
            inDegree[ele]++;
    }

    queue<int> que;

    for(int i=0;i<N;i++)
        if(inDegree[i] == 0)
            que.push(i);

    vector<int> ans;

    while(que.size() != 0)
    {
        int size = que.size();
        while(size--)
        {
            int rvtx = que.front();
            que.pop();

            ans.push_back(rvtx);

            for(int e : graph[rvtx])
                if(--inDegree[e] == 0)
                    que.push(e);
        }
    }

    return ans;
}

void dfs(int src, vector<bool>& vis, vector<int>& dp, vector<vector<int>>& graph)
{
    vis[src] = true;

    for(int e : graph[src])
    {
        if(!vis[e]) // when vtx is not visited then calculate the answer for it. ====================
        {
            dfs(e, vis, dp, graph);
            dp[src] = max(dp[src], dp[e] + 1);
        }
        else  // when vtx is visited then why you calculate the anwer for it just use the save one;
        {
            dp[src] = max(dp[src], dp[e] + 1);
        }
        
    }
}

void constructGraph(vector<vector<int>>& graph)
{
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(2);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(0);
}

int main()
{
    vector<vector<int>> graph(N);
    constructGraph(graph);

    vector<int> topo = kahn_Algo(graph);

    // for(int i=0;i<topo.size();i++)
    //     cout<<topo[i]<<" ";

    vector<int> dp(N,0);

    vector<bool> vis(N,false);
    for(int i=0;i<N;i++)
    {
        if(!vis[topo[i]])
            dfs(topo[i], vis, dp, graph);
    }

    for(int i=0;i<N;i++)
        cout<<i<<"->"<<dp[i]<<"\n";

}