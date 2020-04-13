#include<bits/stdc++.h>
using namespace std;
void basics()
{
    //left shift
    unsigned int x = 7;
    x = (x<<1);
    cout<<x<<"\n";
    //check number is even or odd
    unsigned int x1 = 7;
    if( (x1&1) == 0)
    {
        cout<<"Even\n";
    }
    else
    {
        cout<<"odd\n";
    }
    //right shift
    unsigned int y = 16;
    y = (y>>1);
    cout<<y<<"\n";
    
}
void solve()
{
    basics();
}
int main()
{
    solve();
}