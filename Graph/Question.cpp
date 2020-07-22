// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. An island is considered to be the same as another if and only if one island has the same shape as another island (and not rotated or reflected).
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    vector<vector<int>> dirN = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> str = {"D","R","U","L"};
    string s = "";
    
    void helper(int i, int j, vector<vector<int>> &grid)
    {
        grid[i][j] = 2;
        
        for(int d=0;d<4;d++)
        {
            int x = i + dirN[d][0];
            int y = j + dirN[d][1];
            
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
            {
                s += str[d];
                helper(x, y, grid);
            }
        }
        
        s += 'B';
        return;
    }
     
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
                
        int n = grid.size();
        int m = grid[0].size();
        
        set<string> ss;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    helper(i,j,grid);
                    ss.insert(s);
                    s = "";
                }
                
            }
        }
        return ss.size();
    }
};