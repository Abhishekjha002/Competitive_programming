#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
int comnbinationwith1coin(vector<int> arr, int qpsf, int tqp, int index, string ans)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=index;i<arr.size();i++)
    {
        c += comnbinationwith1coin(arr,qpsf+1,tqp,i+1,ans+"B"+to_string(i)+" Q"+to_string(qpsf));
    }
    return c;
}
int permutationwith1coin(vector<int> arr, int qpsf, int tqp, int index, string ans, vector<int> visited)
{
    if(qpsf == tqp)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=index;i<arr.size();i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            c += permutationwith1coin(arr,qpsf+1,tqp,0,ans+"B"+to_string(i)+" Q"+to_string(qpsf),visited);
            visited[i] = 0;
        }
    }
    return c;
}
int main()
{

    vector<int> arr = {1,1,1,1,1};
    vector<int> check(5,0);
    //cout<<comnbinationwith1coin(arr,0,3,0,"");
    cout<<permutationwith1coin(arr,0,3,0,"",check);
    return 0;
}