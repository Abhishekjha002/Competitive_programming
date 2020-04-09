#include<iostream>
#include<vector>
using namespace std;
int combination_infinite(vector<int>& arr, int total, string ans, int index)
{
    if(total == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;

    for(int i=index;i<arr.size();i++)
    {
        if(arr[i] <= total)
        {
            c += combination_infinite(arr, total-arr[i], ans + to_string(arr[i]), i);
        }
    }

    return c;

}
//using bits - combination infinite
int combination_infinite1(vector<int>& arr, int total, string ans, int index)
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
        c += combination_infinite1(arr,total-arr[index],ans+to_string(arr[index]),index);
    c += combination_infinite1(arr,total,ans,index+1);

    return c;

}

int main()
{

    //denomination
    vector<int> arr = {2,3,5,7};
    int total = 10;
    cout<<combination_infinite1(arr,total,"",0);

}