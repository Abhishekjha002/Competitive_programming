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
//using bits - infinite coin
int permu_infinite1(vector<int>& arr, int total, string ans, int index)
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
    if(total - arr[index] >= 0)
        c += permu_infinite1(arr,total-arr[index],ans+to_string(arr[index]),0);
    c += permu_infinite1(arr,total,ans,index+1);

    return c;
}
int main()
{

    vector<int> arr = {2,3,5,7};
    int total = 10;
    //cout<<permu_infinite(arr,total,"");
    cout<<permu_infinite1(arr,total,"",0);

}