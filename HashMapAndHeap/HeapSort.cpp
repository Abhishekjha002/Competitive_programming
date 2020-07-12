#include <iostream>
#include <vector>
#include <string>
using namespace std;


void downHeapify(vector<int>& arr, int pi, int n)
{
    int lc = 2 * pi + 1;
    int rc = 2 * pi + 2;
    int maxIdx = pi;

    if(lc <= n && arr[lc] > arr[maxIdx])
        maxIdx = lc;
    
    if(rc <= n && arr[rc] > arr[maxIdx])
        maxIdx = rc;

    if(maxIdx != pi)
    {
        swap(arr[maxIdx], arr[pi]);
        downHeapify(arr, maxIdx, n);
    }

}

void heapSort(vector<int>& arr)
{
    int n = arr.size() - 1;
    for(int i = n; i >= 0; i--)    
    {
        downHeapify(arr, i, n);
    }

    while(n != 0)
    {
        swap(arr[0], arr[n--]);
        downHeapify(arr, 0, n);
    }

}



void solve()
{
    vector<int> arr{10,20,30,-2,-3,-4,5,6,7,8,9,22,11,13};
    heapSort(arr);
    for(int ele : arr)
        cout << ele << " ";

}


int main()
{
    solve();
    return 0;
}