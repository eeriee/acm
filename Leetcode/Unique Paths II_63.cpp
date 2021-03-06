class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n); 
        dp[0] = 1; 
        for(auto row: obstacleGrid){
            for(int i = 0; i <n; ++i){
                if(row[i]){
                    dp[i] = 0;
                }else if(i>0){
                    dp[i] += dp[i-1]; 
                }
            }
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0)); 
        dp[0][1] = 1;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(!obstacleGrid[i-1][j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};