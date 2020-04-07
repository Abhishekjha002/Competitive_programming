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
int floodfield(int sr, int sc, int er, int ec, vector<vector<int>> &board,string ans)
{
    if(sr == er && sc == ec)
    {
        return 0;
    }

    int maxHeight = INT_MIN;
    board[sr][sc] = 1;

    for(int d = 0;d < dir.size();d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(isValid(r,c,board))
        {
            maxHeight = max(floodfield( r, c, er, ec, board, ans+dirN[d]) + 1, maxHeight);
        }
    }
    board[sr][sc] = 0;
    return maxHeight;

}

int main()
{
    int sc = 0,sr =0,er = 2,ec = 2;
    vector<vector<int>> board(er+1, vector<int>(ec+1,0));
    cout<<floodfield(sr, sc, er, ec, board,"");
}