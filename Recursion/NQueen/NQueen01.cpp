#include<bits/stdc++.h>
using namespace std;
bool check(int x, int y, vector<vector<int>>& arr)
{
    vector<vector<int>> dirN = {{0,-1},{-1,-1},{-1,0},{-1,1}};
    for(int d = 0;d<dirN.size();d++)
    {
        for(int mag=1;mag<arr.size();mag++)
        {
            int r = x + mag*dirN[d][0];
            int c = y + mag*dirN[d][1];
            if(r>=0 && c>=0 && r<arr.size() && c<arr[0].size() && arr[r][c] == 1)
                return false;
            else if(r<0 || c<0 || r>=arr.size() || c>=arr[0].size())
            {
                break;
            }

        }
    }
    return true;
}
int NQueen(vector<vector<int>>& arr, int tqp, int index, string ans)
{
    if(tqp == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i= index;i<arr.size()*arr[0].size();i++)
    {
        int x = i/arr[0].size();
        int y = i%arr[0].size();
        if(check(x,y,arr))
        {
            arr[x][y] = 1;
            c += NQueen(arr,tqp-1,i+1,ans+"("+to_string(x)+","+to_string(y)+") ");
            arr[x][y] = 0;
        }
    }
    return c;
}
void solve()
{
    int n = 4;
    vector<vector<int>> arr(n,vector<int>(n,0));
    cout<<NQueen(arr,4,0,"");

}
int main()
{
    solve();    
}