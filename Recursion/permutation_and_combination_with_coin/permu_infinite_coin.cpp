#include<iostream>
#include<vector>
using namespace std;
int permu_infinite(vector<int>& arr, int total, string ans)
{
    if(total == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] <= total)
        {
            c += permu_infinite(arr,total-arr[i],ans+to_string(arr[i]));
        }
    }
    return c;

}
int main()
{

    vector<int> arr = {2,3,5,7};
    int total = 10;
    cout<<permu_infinite(arr,total,"");


}#include<iostream>
#include<vector>
using namespace std;
int permu_infinite(vector<int>& arr, int total, string ans)
{
    if(total == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] <= total)
        {
            c += permu_infinite(arr,total-arr[i],ans+to_string(arr[i]));
        }
    }
    return c;

}
int main()
{

    vector<int> arr = {2,3,5,7};
    int total = 10;
    cout<<permu_infinite(arr,total,"");


}