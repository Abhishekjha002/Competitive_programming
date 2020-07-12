#include <iostream>
#include <vector>
#include <string>
using namespace std;

int height(vector<int>& arr, int idx)
{
    if(idx >= arr.size())
        return -1;
    
    int lh = height(arr, 2*idx + 1);
    int rh = height(arr, 2*idx + 2);

    return max(lh, rh) + 1;
}

int size(vector<int>& arr, int idx)
{
    if(idx >= arr.size())
        return 0;
    
    int lh = size(arr, 2*idx + 1);
    int rh = size(arr, 2*idx + 2);

    return lh + rh + 1;
}

// Heap .=============================================== 

class Heap{

    vector<int> arr;
    public: 
        void swap(int si, int ei)
        {
            int temp = arr[si];
            arr[si] = arr[ei];
            arr[ei] = temp;
        }

        void downHeapify(int pi, int n)
        {
            int li = 2 * pi + 1;
            int ri = 2 * pi + 2;
            int maxIdx = pi;

            if(li < n && arr[li] > arr[maxIdx])
                maxIdx = li;
            
            if(ri < n && arr[ri] > arr[maxIdx])
                maxIdx = ri;

            if(pi != maxIdx)
            {
                swap(pi, maxIdx);
                downHeapify(maxIdx, n);
            }

        }

        void upHeapify(int ci)
        {
            int pi = (ci - 1) / 2;
            int minIdx = ci;

            if(pi >= 0 && arr[pi] < arr[minIdx])
                minIdx = pi;

            if(minIdx != ci)
            {
                swap(minIdx, ci);
                upHeapify(minIdx);
            }
        }

        Heap(vector<int>& temp)
        {
            for(int ele : temp)
            {
                arr.push_back(ele);
            }
            
            int n = arr.size();

            // Creation of Heap which guarantee that at root(top) we get maximum element
            for(int i=n-1;i>=0;i--)  // O(nlogn) -> O(2n)
            {
                downHeapify(i, n);
            }

            // for(int i=0;i<n;i++)
            // {
            //     cout << arr[i] << " ";
            // }
        }


        // User Function. =============================

        bool isEmpty()   // O(1)
        {
            return arr.size() == 0;
        }

        int size()   // O(1)
        {
            return arr.size();
        }

        int top()    // O(1)
        {
            if(arr.size() == 0)
                return -1;

            return arr[0];
        }

        void pop()  // O(logn)
        {
            if(arr.size() == 0)
                return -1;
            swap(0, arr.size()-1);
            arr.pop_back();
            downHeapify(0, arr.size());
        }

        void add(int val)  // O(logn)
        {
            arr.push_back(val);
            upHeapify(arr.size()-1);
        }

};
void solve()
{
    vector<int> arr{10,20,30,-2,-3,-4,5,6,7,8,9,22,11,13};
    // cout << height(arr, 0);
    // cout << size(arr, 0);
    Heap pq(arr);
    pq.add(100);
    pq.add(25);

    while(pq.size() != 0)    // O(nlogn)
    {
        cout << pq.top() << " "; 
        pq.pop();
    }
}


int main()
{
    solve();
    return 0;
}