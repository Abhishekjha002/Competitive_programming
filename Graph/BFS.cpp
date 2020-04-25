#include <iostream>
#include <vector>
#include <queue>
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
    int idx = -1;
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
    //addEdge(graph, 2, 5, 2);
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

void hamintonianPath(int src, int osrc, vector<bool>& visited, int count, string ans)
{
    if(count == visited.size() - 1)
    {
        if(findEdge(src,osrc) != -1)
        {
            cout<<"Cycle : " << ans + to_string(src)<<"\n";
            return;
        }
        cout<<"Path :" << ans + to_string(src)<<"\n";
        return;
    }

    visited[src] = true;
    for(Edge e : graph[src])
    {
        if(!visited[e.v])
            hamintonianPath(e.v, osrc, visited, count+1, ans + to_string(src));
    }
    visited[src] = false;
    return;
}
int GCC_(int src, vector<bool>& visited)
{
    int count = 0;
    visited[src] = true;
    for(Edge e : graph[src])
    {
        if(!visited[e.v])
            count += GCC_(e.v,visited);
    }
    return count + 1;
}
void GCC()
{
    vector<bool> visited(N,false);
    int count = 0;
    int maxSize = 0;
    for(int i=0;i<visited.size();i++)
    {
        if(!visited[i])
        {
            count++;
            maxSize = max(maxSize,GCC_(i,visited));
        }
    }
    cout << count << "\n" <<maxSize;
}
void BFS_01(int src, vector<bool>& visited)
{
    queue<pair<int,string>> que;
    que.push({src, to_string(src) + " "});
    int des = 6;

    while(que.size() != 0)
    {
        pair<int,string> rvtx = que.front();
        que.pop();

        if(visited[rvtx.first])  //detect cycle
        {
            cout<<"Cycle : "<<rvtx.second + to_string(rvtx.first)<<"\n";
            continue;
        }

        if(rvtx.first == des)
        {
            cout<<"Path : "<<rvtx.second <<"\n";
        }

        visited[rvtx.first] = true;
        for(Edge e : graph[rvtx.first])
        {
            if(!visited[e.v])
                que.push({e.v, rvtx.second + to_string(e.v) + " "});
        }
    }
    
}
// use delimiter
void BFS_02(int src, vector<bool>& visited)
{
    queue<pair<int,string>> que;
    que.push({src,to_string(src) + " "});
    que.push({-1,""});
    int level = 0;
    int des = 6;

    while(que.size() != 1)
    {
        pair<int,string> rvtx = que.front();
        que.pop();

        if(visited[rvtx.first])
        {
            cout<<"Cycle : "<<rvtx.second<<"\n";
            continue;
        }

        if(rvtx.first == des)
        {
            cout<<"Path : "<<rvtx.second<<"\n";
            cout<<"Level : "<<level<<"\n";
        }

        visited[rvtx.first] = true;
        
        for(Edge e : graph[rvtx.first])
        {
            if(!visited[e.v])
                que.push({e.v, rvtx.second + to_string(e.v) + " "});
        }

        pair<int,string> spc = que.front();
        if(spc.first == -1)
        {
            que.pop();
            que.push({-1,""});
            level++;
        }

    }

}

class variables{
    
    public:
    int v = 0;
    string s = "";
    int level = 0;
    
    variables(int v, string s,int level)
    {
        this->v = v;
        this->s = s;
        this->level = level;
    }
};

void BFS_03(int src, vector<bool>& visited)
{
    queue<variables> que;
    que.push({src,to_string(src)+" ",0});

    int des = 6;
    while(que.size() != 0)
    {
        variables rvtx = que.front();
        que.pop();

        if(visited[rvtx.v])
        {
            cout<<"Cycle : "<<rvtx.s<<"\n";
            continue;
        }
        if(rvtx.v == des)
        {
            cout<<"Path : "<<rvtx.s<<"\n";
            cout<<"Level : "<<rvtx.level<<"\n";
        }

        visited[rvtx.v] = true;
        for(Edge e : graph[rvtx.v])
        {
            if(!visited[e.v])
                que.push({e.v, rvtx.s + to_string(e.v) + " ",rvtx.level+1});
        }
    }

}

void BFS_04(int src, vector<bool>& visited)
{
    queue<int> que;
    que.push(src);
    int level = 0;
    int des = 6;
    int cycle = 1;

    while(que.size() != 0)
    {
        int size = que.size();

        while(size--)
        {
            int rvtx = que.front();
            que.pop();

            if(visited[rvtx])
            {
                cout<<"Cycle no. -> "<<cycle<<". "<<rvtx<<"\n";
                cycle++;
                continue;
            }

            if(rvtx == des)
            {
                cout<<"Level -> "<<level<<". "<<rvtx<<"\n";
            }

            visited[rvtx] = true;
            for(Edge e : graph[rvtx])
            {
                if(!visited[e.v])
                    que.push(e.v);
            }
        }
        level++;
    }


}
/////////////////////////If cycle is not your concern///////////////////////
void BFS_05(int src,vector<bool>& visited)
{
    queue<int> que;
    que.push(src);
    int level = 0;
    int des = 6;
    int cycle = 1;

    visited[src] = true;

    while(que.size() != 0)
    {
        int size = que.size();

        while(size--)
        {
            int rvtx = que.front();
            que.pop();

            if(rvtx == des)
                cout<<"Level -> "<<level<<". "<<rvtx<<"\n";

            
            for(Edge e : graph[rvtx])
            {
                if(!visited[e.v])
                {
                    visited[e.v] = true;
                    que.push(e.v);
                }
            }
        }
        level++;
    }
}
void solve()
{
    constructGraph();
    vector<bool> visited(N,false);
    //cout<<printAllPath(0,6,visited,"");
    //cout<<hasPath(0,6,visited);
    //allSolutionPair pair;
    //allSolution(0,6,visited,0,pair,20);
    //cout << pair.lightW << " " << pair.heavyW << " " << pair.ceilV << " " << pair.floorV;
    //hamintonianPath(2,2,visited,0,"");
    //GCC();
    // BFS_01(0,visited);
    // BFS_02(0,visited);
    // BFS_03(0,visited);
    // BFS_04(0,visited);
    BFS_05(0,visited);
}
int main()
{
    solve();
}