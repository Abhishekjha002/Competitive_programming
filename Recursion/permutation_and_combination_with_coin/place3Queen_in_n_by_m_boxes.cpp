#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
int place_queen_combination(vector<vector<int>> &arr,int qpsf, int tqp,int index1, int index2,string ans)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;

    for(int i=index1;i<arr.size();i++)
    {
        for(int j=index2;j<arr[0].size();j++)
        {
            c += place_queen_combination(arr,qpsf+1,tqp,i,j+1,ans+"("+to_string(i)+","+to_string(j)+")");
        }
        index2 = 0;
    }
    return c;
}
int place_queen_permutation(vector<vector<int>> &arr,int qpsf, int tqp,int index1, int index2,string ans,vector<vector<int>> &visited)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;

    for(int i=index1;i<arr.size();i++)
    {
        for(int j=index2;j<arr[0].size();j++)
        {
            if(visited[i][j] == 0)
            {
                visited[i][j] = 1;
                c += place_queen_permutation(arr, qpsf+1, tqp, 0, 0, ans+"("+to_string(i)+","+to_string(j)+")", visited);
                visited[i][j] = 0;
            }
        }
    }
    return c;
}
int main()
{
    vector<vector<int>> arr(3,vector<int>(3,1));
    vector<vector<int>> visited(3,vector<int>(3,0));
    //cout<<place_queen_combination(arr,0,3,0,0,"");
    cout<<place_queen_permutation(arr,0,3,0,0,"",visited);
    return 0;
}
