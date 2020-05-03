#include <bits/stdc++.h>
using namespace std;
int N = 15;
vector<vector<int>> graph(N,vector<int>());
void makeGraph()
{
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(11);
    graph[4].push_back(5);
    graph[4].push_back(7);
    graph[5].push_back(6);
    graph[5].push_back(9);
    graph[5].push_back(7);
    graph[6].push_back(9);
    graph[7].push_back(8);
    graph[7].push_back(9);
    graph[8].push_back(4);
    graph[8].push_back(10);
    graph[9].push_back(8);
    graph[9].push_back(10);
    graph[9].push_back(13);
    graph[10].push_back(11);
    graph[10].push_back(13);
    graph[11].push_back(12);
    graph[12].push_back(10);
    graph[12].push_back(14);
    graph[13].push_back(12);
    graph[14].push_back(13);
}
void TopologicalOrdering(int src, vector<bool>& vis, vector<int>& ans)
{
    vis[src] = true;
    for(int e : graph[src])
    {
        if(!vis[e])
        {
            TopologicalOrdering(e,vis,ans);
        }
    }

    ans.push_back(src);
}
void DFS(int src, vector<bool>& vis, vector<int>& arr, vector<vector<int>>& gp)
{
    vis[src] = true;
    for(int e : gp[src])
    {
        if(!vis[e])
            DFS(e,vis,arr,gp);
    }
    arr.push_back(src);
}
//kosaraju_algorithm
void SCC()
{
    vector<bool> vis(N,false);
    vector<int> ans;

    for(int i=0;i<N;i++)
    {
        if(vis[i] == false)
            TopologicalOrdering(i,vis,ans);
    }

    reverse(ans.begin(),ans.end());

    vector<vector<int>> gp(N,vector<int>());
    for(int i=0;i<N;i++)
    {
            for(int e : graph[i])
            {
                gp[e].push_back(i);
            }
    }

    vis.clear();
    vis.resize(N,false);

    int z = 0;
    for(int i=0;i<ans.size();i++)
    {
        int ele = ans[i];
        if(!vis[ele])
        {
            z++;
            vector<int> arr;
            DFS(ele,vis,arr,gp);
            for(int i=0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }

    //total- SCC
    cout<<z;

}
void solve()
{
    makeGraph();
    SCC();

}
int main()
{
    solve();
}