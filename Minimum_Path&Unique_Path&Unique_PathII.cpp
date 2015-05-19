Minimum path:

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        //f[k] = f[k-1] + f[k]
        const int m = grid.size();
        const int n = grid[0].size();
        int f[n];
        fill_n(&f[0], n, 0);
        
        //Even this is dynamic array, better utilize the loop in between
        for(int i=0; i<m; i++)
         for(int j=0; j<n; j++){
            f[j] = ( i==0 && j==0)? grid[0][0]:
            min( j==0? INT_MAX:f[j-1], i==0? INT_MAX:f[j] ) + grid[i][j];
        }
        return f[n-1];
    }
};


Unique Path:

class Solution {
public:
    int uniquePaths(int m, int n) {
        //recursion is more difficult to implement
        //Dp: f[k] = f[k-1] + f[k]
        int f[n];
        fill_n(&f[0],n,0);
        f[0] = 1;
        
        for(int i=0; i<m;i++){
            for(int j=1; j<n; j++){
                f[j] =  f[j-1] + (i==0? 0: f[j]);
            }
        }
        return f[n-1];
    }
};

Unique Path II:

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        // f[k] = grid[i][j] == 1? 0: f[k]+f[k-1]; 
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        
        int f[n];
        fill_n(&f[0], n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                f[j] = ( i==0 && j==0 )? 1:
                ( obstacleGrid[i][j] == 1? 0:
                    ( ( j==0?  0: f[j-1] )+f[j] ) );
            }
        }
        return f[n-1];
    }
};



Conclusion:
Concerns about grid[0][0] position
In rolling array: consider if f[0] needs to roll( j start from 0, or 1)