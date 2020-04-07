#include<iostream>
#include<vector>
using namespace std;
int finiteCoinCombination(vector<int>& arr, int total, string ans, int index, vector<int>& visited)
{
    if(total == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }
    int c = 0;
    for(int i=index;i<arr.size();i++)
    {
        if(visited[i] == 0)
        {
            if(arr[i] <= total)
            {
                visited[i] = 1;
                c += finiteCoinCombination(arr, total-arr[i], ans+to_string(arr[i]), i, visited);
                visited[i] = 0;
            }
        }
    }
    return c;
}
int main()
{

    vector<int> arr = {2,3,5,7};
    int total = 10;
    vector<int> visited(4,0);
    cout<<finiteCoinCombination(arr,total,"",0,visited);


}