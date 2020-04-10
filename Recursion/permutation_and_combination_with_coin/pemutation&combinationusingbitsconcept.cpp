#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
int combinationwith1coin(vector<int> &arr, int total, int index, string ans)
{
    if(total == 0 || arr.size() == index)
    {
        if(total == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;

    if(total-arr[index] >= 0)
    {
        c += combinationwith1coin(arr,total-arr[index],index+1,ans+to_string(arr[index]));
    }
    c += combinationwith1coin(arr,total,index+1,ans);
    return c;

}
int combinationwithinfinitecoin(vector<int> &arr, int total, int index, string ans)
{
    if(total == 0 || index == arr.size())
    {
        if(total == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;
    if(total - arr[index] >= 0)
    {
        c += combinationwithinfinitecoin(arr,total-arr[index],index,ans+to_string(arr[index]));
    }
    c += combinationwithinfinitecoin(arr,total,index+1,ans);
    
    return c;

}
int permutationwithinfinitecoin(vector<int> &arr, int total, int index, string ans)
{
    if(total == 0 || index == arr.size())
    {
        if(total == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;
    if(total-arr[index] >= 0)
    {
        c += permutationwithinfinitecoin(arr,total-arr[index],0,ans+to_string(arr[index]));
    }
    c += permutationwithinfinitecoin(arr,total,index+1,ans);
    return c;

}
int permutaionwith1coin(vector<int> &arr, int total, int index, string ans, vector<int> &visited)
{
    if(total == 0 || arr.size() == index)
    {
        if(total == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;
    if(total-arr[index] >= 0 && visited[index] == 0)
    {
        visited[index] = 1;
        c += permutaionwith1coin(arr,total-arr[index],0,ans+to_string(arr[index]),visited);
        visited[index] = 0;
    }
    c += permutaionwith1coin(arr,total,index+1,ans,visited);
    return c;
}
int main()
{

    vector<int> arr = {2,3,5,7};
    vector<int> visited(4,0);
    int total = 10;
    //cout<<combinationwith1coin(arr,total,0,"");
    //cout<<combinationwithinfinitecoin(arr,total,0,"");
    //cout<<permutationwithinfinitecoin(arr,total,0,"");
    cout<<permutaionwith1coin(arr,total,0,"",visited);
    return 0;
}