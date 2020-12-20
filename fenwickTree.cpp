// https://codeforces.com/blog/entry/61364
#include<bits/stdc++.h>
using namespace std;

int fen[100000];

void update(int i, int add, int N){
    while(i<N)
    {
        fen[i] += add;
        i = i + (i & (-i));
    }
}

int sum(int i){
    int s = 0;
    while(i > 0)
    {
        s += fen[i];
        i = i - (i & (-i));
    }
    return s;
}

int rangeSum(int L, int R)
{
    return sum(R) - sum(L-1);
}

void solve()
{
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};

    for(int i=1;i<arr.size();i++)
    {
        update(i,arr[i],arr.size());
    }

    cout<<rangeSum(4,11);

}

int main()
{
    solve();
    return 0;
}
