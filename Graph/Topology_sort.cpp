#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N = 7;
vector<vector<int>> graph(N,vector<int>());
void makeGraph()
{
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(6);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(5);
    graph[3].push_back(6);
    graph[6].push_back(4);
    graph[6].push_back(5);

}
void TopologySort_(int src, vector<bool>& vis,vector<int>& ans)
{
    vis[src] = true;
    for(int e : graph[src])
    {
        if(!vis[e])
            TopologySort_(e,vis,ans);
    }
    ans.push_back(src);
}
void TopologySort_01()
{
    vector<bool> vis(N,false);
    vector<int> ans;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            TopologySort_(i,vis,ans);
        }
    }
    
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
}
void solve()
{
    makeGraph();
    TopologySort_01();
}
int main()
{
    solve();
}