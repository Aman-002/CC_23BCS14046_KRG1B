class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m =obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        vector<vector<long long>>dp(n,vector<long long>(m,0));
        dp[n-1][m-1] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long right=0;
                if(j<m-1){
                    right=dp[i][j+1];
                }
                long long down=0;
                if(i<n-1){
                    down=dp[i+1][j];
                }
                
                if(i==n-1 && j==m-1){
                    continue;
                }
                dp[i][j]=right+down;
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
            }
        }
        return (int)dp[0][0];
    }
};
