#include<bits/stdc++.h>
using namespace std;
int rowA = 0;
int colA = 0;
int diag = 0;
int aDiag = 0;
int NQueen(int n, int m, int tqp, int r,int index, string ans) // n means houses and m means rooms
{
    if(tqp == 0 || r == n || index == m)
    {
        if(tqp == 0)
        {
            cout<<ans<<"\n";
            return 1;
        }
        return 0;
    }

    int c = 0;
    
    int x = r;
    int y = index;

    if (!(rowA & (1 << x)) && !(colA & (1 << y)) && !(diag & (1 << (x - y + m - 1))) && !(aDiag & (1 << (x + y))))
    {
        rowA ^= (1 << x);
        colA ^= (1 << y);
        diag ^= (1 << (x - y + m - 1));
        aDiag ^= (1 << (x + y));

        c += NQueen(n, m, tqp-1, r+1, 0, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
        
        rowA ^= (1 << x);
        colA ^= (1 << y);
        diag ^= (1 << (x - y + m - 1));
        aDiag ^= (1 << (x + y));
    }

    c += NQueen(n, m, tqp, r, index+1, ans);

    return c;
}
void solve()
{
    
    int n = 6;
    int m = 6;

    cout<<NQueen(n,m,4,0,0,"");

}
int main()
{
    solve();    
}