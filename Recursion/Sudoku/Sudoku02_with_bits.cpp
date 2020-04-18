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

vector<int> row(9,0);
vector<int> col(9,0);
vector<vector<int>> mat(3,vector<int>(3,0));

int sudoku_02(vector<vector<int>>& board,vector<int>& call,int idx)
{
    if(idx == call.size())
    {
        display(board);
        return 1;
    }

    int r = call[idx]/9;
    int c = call[idx]%9;

    int res = 0;

    for(int num=1;num<=9;num++)
    {   
        int mask = (1 << num);
        if( !(row[r] & mask) && !(col[c] & mask) && !(mat[r/3][c/3] & mask) )
        {
            board[r][c] = num;
            row[r] ^= (1 << num);
            col[c] ^= (1 << num);
            mat[r/3][c/3] ^= (1 << num);
            res += sudoku_02(board,call,idx+1);
            row[r] ^= (1 << num);
            col[c] ^= (1 << num);
            mat[r/3][c/3] ^= (1 << num);
            board[r][c] = 0;
        }
    }
    
    return res;
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


    vector<int> call;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j] == 0)
            {
                call.push_back(i*9+j);
            }
            else
            {
                int mask = (1 << board[i][j]);
                row[i] ^= mask;
                col[j] ^= mask;
                mat[i/3][j/3] ^= mask;
            }
            
        }
    }
    cout<<sudoku_02(board,call,0);
}
int main()
{
    sudoku();
}