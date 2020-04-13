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
int KthOFFToON(int num, int k) // on -> on and off -> on
{
    unsigned int mask = (1<<k);
    return (num | mask);
}
int KthOnToOFF(int num, int k) // on -> oFF and off -> off
{
    int mask = (~(1 << k));
    return (num & mask);
}
int countSetBits(unsigned int n)
{
    int bitCount = 0;
    int totalBits = 32;
    while(totalBits != 0 && n != 0)
    {
        if((n&1) != 0)
        {
            bitCount++;
        }
        n >>= 1;
        totalBits--;
    }
    return bitCount;
}
int countSetBits01(unsigned int num)
{
    int bitCount = 0;

    while(num != 0)
    {
        num &= (num-1);
        bitCount++;
    }
    return bitCount;
}
void solve()
{
    //basics();
    //cout<<KthOFFToON(13,1);
    //cout<<KthOnToOFF(13,2);
    //cout<<countSetBits(726);
    cout<<countSetBits01(1016);
}
int main()
{
    solve();
}