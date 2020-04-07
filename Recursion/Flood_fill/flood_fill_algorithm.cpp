####write a flood fill agorithm
#include<bits/stdc++.h>
#include<string>
using namespace std;
vector<vector<int> > dir = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
vector<string> dirN = {"R","E","U","N","L","W","D","S"};
bool isValid(int sr,int sc,vector<vector<int>> &board)
{
    if(sr < 0 || sc < 0 || sr >= board.size() || sc >= board[0].size() || board[sr][sc] == 1)
        return 0;
    else 
        return 1;
}
int floodfield(int sr, int sc, int er, int ec, vector<vector<int>> &board, int rad, string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int count = 0;
    board[sr][sc] = 1;

    for(int d = 0;d < dir.size();d++)
    {
        for(int mag = 1;mag <= rad; mag++)
        {
            int r = sr + mag*dir[d][0];
            int c = sc + mag*dir[d][1];
            if(isValid(r,c,board))
            {
                count += floodfield( r, c, er, ec, board, rad,ans + dirN[d] + to_string(mag) );
            }
        }
    }
    board[sr][sc] = 0;
    return count;

}

int main()
{
    int sc = 0,sr =0,er = 2,ec = 2;
    int rad = max(er,ec);
    vector<vector<int>> board(er+1, vector<int>(ec+1,0));
    cout<<floodfield(sr, sc, er, ec, board, rad, "");
}
