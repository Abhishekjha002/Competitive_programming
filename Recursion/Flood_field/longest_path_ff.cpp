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
pair<string,int> floodfield(int sr, int sc, int er, int ec, vector<vector<int>> &board)
{
    if(sr == er && sc == ec)
    {
        pair<string,int> p;
        p.first = "";
        p.second = 0;
        return p;
    }

    pair<string,int> ans;
    ans.second = INT_MIN;
    ans.first = "";

    board[sr][sc] = 1;

    for(int d = 0;d < dir.size();d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];
        if(isValid(r,c,board))
        {
            pair<string,int> smallAns = floodfield( r, c, er, ec, board);
            if(smallAns.second + 1 > ans.second)
            {
                ans.second = smallAns.second + 1;
                ans.first = dirN[d] + smallAns.first ;
            }
        }
    }
    board[sr][sc] = 0;
    return ans;

}

int main()
{
    int sc = 0,sr =0,er = 3,ec = 3;
    vector<vector<int>> board(er+1, vector<int>(ec+1,0));
    pair<string,int> ans = floodfield(sr, sc, er, ec, board);
    cout<<ans.first<<" "<<ans.second;
}