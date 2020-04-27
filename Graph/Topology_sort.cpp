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

//Kahn's Algo
void kahn_algo()
{
    vector<int> inDegree(N,0);
    for(int i=0;i<N;i++)
    {
        for(int e : graph[i])
        {
            inDegree[e]++;
        }
    }

    queue<int> que;
    for(int i=0;i<N;i++)
    {
        if(inDegree[i] == 0)
            que.push(i);
    }

    vector<int> ans;
    while(que.size() != 0)
    {
        int size = que.size();
        while(size-- > 0)
        {
            int rvtx = que.front();
            que.pop();
            ans.push_back(rvtx);
            for(int e : graph[rvtx])
            {
                if(--inDegree[e] == 0)
                {
                    que.push(e);
                }
                
            }
        }
    }

    if(ans.size() != N)
    {
        cout<<"Cycle\n";
    }
    else
    {
        for(int i=0;i<N;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    
}
void solve()
{
    makeGraph();
    // TopologySort_01();
    kahn_algo();

}
int main()
{
    solve();
}