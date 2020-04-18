#include <iostream>
#include <vector>
#include <string>
using namespace std;
void display(vector<vector<int>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafeToPlace(vector<vector<int>>& board, int r, int c, int num)
{
    //row-check
    for(int i=0;i<board.size();i++)
    {
        if(board[i][c] == num)
        {
            return false;
        }
    }
    //col-check
    for(int j=0;j<board[r].size();j++)
    {
        if(board[r][j] == num)
        {
            return false;
        }
    }

    //3*3 - boxCheck
    int x = r/3;
    int y = c/3;
    x = x*3;
    y = y*3;
    for(int i=x;i!=x+3;i++)
    {
        for(int j=y;j!=y+3;j++)
        {
            if(board[i][j] == num)
                return false;
        }
    }
    return true;
}
int sudoku_01(vector<vector<int>>& board,int idx)
{
    if(idx == 81)
    {
        display(board);
        return 1;
    }

    int r = idx/board[0].size();
    int c = idx%board[0].size();

    int count = 0;

    if(!board[r][c])
    {
        for(int num=1;num<=9;num++)
        {
            if(isSafeToPlace(board,r,c,num))
            {
                board[r][c] = num;
                count += sudoku_01(board,idx+1);
                board[r][c] = 0;
            }
        }
    }
    else
    {
        count += sudoku_01(board,idx+1);
    }
    
    return count;
}
void sudoku()
{
    vector<vector<int>> board = {{3, 0, 0, 0, 0, 0, 0, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  

    cout<<sudoku_01(board,0);
}
int main()
{
    sudoku();
}