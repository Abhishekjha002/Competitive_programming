#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
int comnbinationQueen2D(vector<vector<int>> arr, int qpsf, int tqp, int index, string ans)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=index;i<arr.size()*arr[0].size();i++)
    {
        int x = i/arr[0].size();
        int y = i%arr[0].size();
        c += comnbinationQueen2D(arr,qpsf+1,tqp,i+1,ans+"("+to_string(x)+","+to_string(y)+")");
    }
    return c;
}
int permutationQueen2D(vector<vector<int>> &arr, int qpsf, int tqp, int index, string ans, vector<vector<int>> &visited)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=index;i<arr.size()*arr[0].size();i++)
    {
        int x = i/arr[0].size();
        int y = i%arr[0].size();
        if(!visited[x][y])
        {
            visited[x][y] = 1;
            c += permutationQueen2D(arr,qpsf+1,tqp,0,ans+"("+to_string(x)+","+to_string(y)+")",visited);
            visited[x][y] = 0;
        }
    }
    return c;
}
int main()
{
    vector<vector<int>> arr(3,vector<int>(3,1));
    vector<vector<int>> check(3,vector<int>(3,0));
    //cout<<comnbinationQueen2D(arr,0,3,0,"");
    cout<<permutationQueen2D(arr,0,3,0,"",check);
    return 0;
}
