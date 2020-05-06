#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 9;

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

//add Edge
void addEdge(vector<vector<Edge>>& gp, int u, int v,int w)
{
    gp[u].push_back(Edge(v,w));
    gp[v].push_back(Edge(u,w));
}

//display graph
void display(vector<vector<Edge>>& gp)
{
    for(int i=0;i<gp.size();i++)
    {
        cout<<i<<"->";
        for(Edge e : gp[i])
        {
            cout<<"("<<e.v<<","<<e.w<<"),";
        }
        cout<<"\n";
    }
}

vector<int> par;
vector<int> setSize;
int findPar(int vtx)
{
    if(par[vtx] == vtx)
        return vtx;
    return par[vtx] = findPar(par[vtx]);
}

void merge(int l1, int l2)
{
    if(setSize[l1] < setSize[l2])
    {
        par[l1] = par[l2];
        setSize[l2] += setSize[l1];
    }
    else
    {
        par[l2] = par[l1];
        setSize[l1] += setSize[l2];
    }
}

// kruskal algorithm
void kruskalAlgo(vector<vector<int>>& graph)
{
    vector<vector<Edge>> kruskalGraph(N,vector<Edge>());

    sort(graph.begin(),graph.end(),[](vector<int> a, vector<int> b){
        return a[2] < b[2];
    });

    int n = N;

    for(int i=0;i<n;i++)
        par.push_back(i);
    
    setSize.resize(n,1);

    for(vector<int> ar : graph)
    {
        int u = ar[0];
        int v = ar[1];
        int w = ar[2];

        int p1 = findPar(u);
        int p2 = findPar(v);

        if(p1 != p2)
        {
            merge(p1,p2);
            addEdge(kruskalGraph, u, v, w);
        }
    }
    
    display(kruskalGraph);

}
void constructGraph(vector<vector<int>>& graph)
{
    graph.push_back({1,2,8});
    graph.push_back({0,7,8});
    graph.push_back({3,4,9});
    graph.push_back({4,5,10});
    graph.push_back({7,6,1});
    graph.push_back({6,5,2});
    graph.push_back({2,8,2});
    graph.push_back({0,1,4});
    graph.push_back({2,5,4});
    graph.push_back({6,8,6});
    graph.push_back({7,8,7});
    graph.push_back({2,3,7});
    graph.push_back({1,7,11});
    graph.push_back({3,5,14});
}
void solve()
{
    vector<vector<int>> graph;
    constructGraph(graph);
    kruskalAlgo(graph);   
}
int main()
{
    solve();
    return 0;
}
    