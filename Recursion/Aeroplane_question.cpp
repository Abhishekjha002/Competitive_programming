#include <iostream>
using namespace std;

int Board[13][5] = {0};
int originalBoard[13][5] = {0};
int maxCoins = 0;
int dirN[3] = {-1,0,1};

void Blast(int row)
{
    for(int i=row, count = 0; i>=0 && count < 5; i--, count++)
    {
        for(int j=0;j<5;i++)
        {
            if(Board[i][j] == 2)
            {
                Board[i][j] = 0;
            }
        }
    }
}

void unBlast(int row)
{
    for(int i=row, count = 0; i>=0 && count < 5; i--, count++)
    {
        for(int j=0;j<5;i++)
        {
            if(originalBoard[i][j] == 2)
            {
                Board[i][j] = 2;
            }
        }
    }
}

void helper(int n, int c, int coins)
{
    if(n == 0 || coins == -1)
    {
        maxCoins = max(maxCoins, coins);
        return;
    }

    for(int d=0;d<3;d++)
    {
        int y = c + dirN[d];
        if(y > 0 && y < 5)
        {
            if(Board[n-1][y] == 1)
                coins += 1;
            if(Board[n-1][y] == 2)
                coins -= 1;
            
            helper(n-1, y, coins);
            
            if(Board[n-1][y] == 1)
                coins -= 1;
            if(Board[n-1][y] == 2)
                coins += 1;
        }
    }
}

void oldDays_()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++){
            cin>>Board[i][j];
            originalBoard[i][j] = Board[i][j];
        }
    }

    for(int i=n-1;i<=4;i++)
    {
        Blast(i);
        helper(i,2,0);
        unBlast(i);
    }

}

void oldDays()
{
    int t;
    cin>>t;
    while(t--)
        oldDays_();
}

int main()
{
    oldDays();
    return 0;
}