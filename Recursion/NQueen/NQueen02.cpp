#include<bits/stdc++.h>
using namespace std;
int NQueen(vector<vector<int>>& arr, int tqp, int index, string ans,vector<bool>& rowA,vector<bool>& colA,vector<bool>& diag,vector<bool>& aDiag)
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
        if(!rowA[x] && !colA[y] && !diag[x-y+arr[0].size()-1] && !aDiag[x+y])
        {
            rowA[x] = 1;
            colA[y] = 1;
            diag[x-y+arr[0].size()-1] = 1;
            aDiag[x+y] = 1;
            c += NQueen(arr,tqp-1,i+1,ans+"("+to_string(x)+","+to_string(y)+") ",rowA,colA,diag,aDiag);
            rowA[x] = 0;
            colA[y] = 0;
            diag[x-y+arr[0].size()-1] = 0;
            aDiag[x+y] = 0;
        }
    }
    return c;
}
void solve()
{
    
    int n = 4;
    int m = 4;
    vector<vector<int>> arr(n,vector<int>(m,0));
    vector<bool> rowA(n,false);
    vector<bool> colA(m,false);
    vector<bool> diag(n+m-1,false);
    vector<bool> aDiag(n+m-1,false);
    cout<<NQueen(arr,4,0,"",rowA,colA,diag,aDiag);

}
int main()
{
    solve();    
}