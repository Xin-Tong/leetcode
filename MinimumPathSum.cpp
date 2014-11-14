//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.




class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row=grid.size();
        int col=grid[0].size();
        if (row==0){
            return 0;
        }
        if (col==0){
            return 0;
        }
        vector<int> MinPa(col, INT_MAX);
        MinPa[0]=0;
        for(int i=0; i<=row-1; i++){
            MinPa[0]=MinPa[0]+grid[i][0];
            for(int j=1; j<=col-1; j++){
                MinPa[j]=min(MinPa[j], MinPa[j-1])+grid[i][j];
            }
        }
        return MinPa[col-1];
    }
};