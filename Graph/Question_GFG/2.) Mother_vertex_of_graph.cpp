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


vector<int> startTime(N,0);
vector<int> finishingTime(N,0);

int counter = 1;
int lfv = -1;

void dfs_finishingTime(int src, vector<bool>& vis)
{
    vis[src] = true;
    startTime[src] = counter++;

    for(Edge e : gp[src])
    {   
        if(!vis[e.v])
            dfs_finishingTime(e.v, vis);
    }

    lfv = src;
    finishingTime[src] = counter++;
}

int dfs(int src, vector<bool>& vis)
{
    vis[src] = true;

    int count = 0;
    for(Edge e : gp[src])
        if(!vis[e.v])
            count += dfs(e.v, vis);
    
    return count+1;
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
    addEdge(gp, 0, 2, 20);
    addEdge(gp, 1, 3, 10);
    addEdge(gp, 6, 0, 2);
    addEdge(gp, 6, 4, 2);
    addEdge(gp, 4, 1, 3);
    addEdge(gp, 5, 6, 8);
    addEdge(gp, 5, 2, 2);

}

void solve()
{
    constructGraph();
    vector<bool> vis(N,false);

    for(int i=0;i<N;i++)
        if(!vis[i])
            dfs_finishingTime(i, vis);
    
    // for(int i=0;i<N;i++)
    // {
    //     cout<<"vertex "<<i<<" -> "<<startTime[i]<<","<<finishingTime[i]<<"\n";
    // }

    // cout<<lfv;

    vis.clear();
    vis.resize(N,false);
    if(dfs(lfv, vis) == N)
    {
        cout<<"Mother Vertex is "<<lfv;
    }
    else
    {
        cout<<"No Mother Vtx";
    }
    
    

}

int main()
{
    solve();
    return 0;
}