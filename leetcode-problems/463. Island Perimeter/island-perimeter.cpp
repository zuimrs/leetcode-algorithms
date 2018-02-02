/**
 * File: island-perimeter.cpp * https://leetcode.com/problems/island%20perimeter/
 * By zuimrs
 * Runtime:  102 ms
 * Language: cpp
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int sum = 0;
        if(r == 0 || c== 0)
            return sum;
        for(int i = 0 ; i < r ; ++ i )
        {
            if(grid[i][0]) 
                sum ++;
            for(int j =  0 ;  j < c-1; ++j)
            {
                sum += grid[i][j]^grid[i][j+1];
                
            }
            if(grid[i][c-1])
                sum++;
        }
        for(int i = 0 ; i < c ; ++ i )
        {
            if(grid[0][i]) 
                sum ++;
            for(int j =  0 ;  j < r-1; ++j)
            {
                sum += grid[j][i]^grid[j+1][i];
                
            }
            if(grid[r-1][i])
                sum++;
        }
        return sum;
    }
};