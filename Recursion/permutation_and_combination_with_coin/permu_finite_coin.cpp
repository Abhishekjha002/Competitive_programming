#include<iostream>
#include<vector>
using namespace std;
int finiteCoinPermutation(vector<int>& arr, int total, string ans, vector<int>& visited)
{
    if(total == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }
    int c = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(visited[i] == 0)
        {
            if(arr[i] <= total)
            {
                visited[i] = 1;
                c += finiteCoinPermutation(arr, total-arr[i], ans+to_string(arr[i]), visited);
                visited[i] = 0;
            }
        }
    }
    return c;
}
int finiteCoinPermutation1(vector<int>& arr, int total, string ans, int index)
{
    if(index == arr.size() || total == 0)
    {
        if(total == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;

    if(total - arr[index] <= 0)
        c += finiteCoinPermutation1(arr,total - arr[index],ans + to_string(arr[index]), index + 1);
    c += finiteCoinPermutation1(arr,total,ans,index+1);

    return c;


}
int main()
{

    vector<int> arr = {2,3,5,7};
    int total = 10;
    vector<int> visited(4,0);
    // cout<<finiteCoinPermutation(arr,total,"",visited);
    cout<<finiteCoinPermutation1(arr,total,"",0);

}