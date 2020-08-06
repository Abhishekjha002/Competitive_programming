#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<Edge>> gp(N, vector<Edge>());

//Basic function

void addEdge(vector<vector<Edge>>& gp, int u, int v, int w)
{
    gp[u].push_back(Edge(v, w));
    // gp[v].push_back(Edge(u, w));
}

vector<int> topo()
{

    vector<int> inDegree(N,0);

    for(vector<Edge> ar : gp)
    {
        for(Edge ele : ar)
            inDegree[ele.v]++;
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

            for(Edge e : gp[rvtx])
                if(--inDegree[e.v] == 0)
                    que.push(e.v);
        }
    }

    return ans;
}

void dfs(int src, vector<int>& dp, vector<bool>& vis)
{
    vis[src] = true;

    for(Edge e : gp[src])
    {
        if(!vis[e.v])
        {
            dfs(e.v, dp, vis);
            dp[src] = max(dp[src], dp[e.v] + e.w);
        }
        else
        {
            dp[src] = max(dp[src], dp[e.v] + e.w);
        }

    }
}

void display(vector<vector<Edge>> &gp)
{

    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << " -> ";

        // for(int j=0;j<gp[i].size();j++){
        //     Edge* e=gp[i][j];
        // }

        for (Edge e : gp[i])
        {
            cout << "(" << e.v << ", " << e.w << "), ";
        }
        cout << endl;
    }

    cout << endl;
}

void constructGraph()
{
    addEdge(gp, 0, 1, 20);
    addEdge(gp, 0, 3, 20);
    addEdge(gp, 1, 2, 10);
    addEdge(gp, 2, 3, 40);
    addEdge(gp, 3, 4, 2);
    addEdge(gp, 4, 5, 3);
    addEdge(gp, 4, 6, 8);
    addEdge(gp, 5, 6, 2);

}

void solve()
{
    constructGraph();
    vector<int> ans = topo();
    //display(gp);
    // for(int i=0;i<N;i++)
    //     cout<<ans[i]<<" ";

    vector<bool> vis(N,false);
    vector<int> dp(N,0);
    for(int i=0;i<N;i++)
    {
        if(!vis[ans[i]])
            dfs(ans[i],dp,vis);
    }

    for(int i=0;i<N;i++)
        cout<<i<<" -> "<<dp[i]<<"\n";

}

int main()
{
    solve();
    return 0;
}


