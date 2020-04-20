#include <iostream>
#include <vector>
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
vector<vector<Edge>> graph(N,vector<Edge>());

//add Edge
void addEdge(vector<vector<Edge>>& gp, int u, int v,int w)
{
    gp[u].push_back(Edge(v,w));
    gp[v].push_back(Edge(u,w));
}

//remove Edge
int findEdge(int v1,int v2)
{
    int idx = 0;
    for(int i=0;i<graph[v1].size();i++)
    {
        Edge e = graph[v1][i];
        if(e.v == v2)
        {
            idx = i;
            break;
        }
    }
    return idx;
}
void removeEdge(int u, int v)
{
    int idx1 = findEdge(u,v);
    int idx2 = findEdge(v,u);

    graph[u].erase(graph[u].begin() + idx1);
    graph[v].erase(graph[v].begin() + idx2);
}

//remove vertex
void removeVtx(int vtx)
{
    while(graph[vtx].size() != 0)
    {
        Edge e = graph[vtx].back();
        removeEdge(e.v,vtx);
    }
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
void constructGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);
}
bool hasPath(int src, int des, vector<bool>& visited)
{
    if(src == des)
    {
        return 1;
    }

    visited[src] = true;
    for(int i=0;i<graph[src].size();i++)
    {
        int x = graph[src][i].v;
        if(!visited[x])
        {
            if(hasPath(x,des,visited)) return true;
        }
    }
    visited[src] = false;
    return false;
}
int printAllPath(int src, int des, vector<bool>& visited, string ans)
{
    if(src == des)
    {
        cout<<ans+to_string(des)<<"\n";
        return 1;
    }
    
    visited[src] = true;
    int count = 0;
    for(int i=0;i<graph[src].size();i++)
    {
        int x = graph[src][i].v;
        if(!visited[x])
        {
            count += printAllPath(x,des,visited,ans+to_string(src)+" ");
        }
    }
    visited[src] = false;
    return count;


}
void solve()
{
    constructGraph();
    vector<bool> visited(N,false);
    //cout<<printAllPath(0,6,visited,"");
    cout<<hasPath(0,6,visited);
}
int main()
{
    solve();
}