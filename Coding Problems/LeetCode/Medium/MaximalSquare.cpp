int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = rows > 0 ? matrix[0].size() : 0;

    vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));

    int maxsquare=0;

    //dp(i-1,j),dp(i,j-1),dp(i-1,j-1)

    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            if(matrix[i-1][j-1]=='1') {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j-1]) + 1;
                maxsquare = max(maxsquare,dp[i][j]);
            }
        }
    }
    return maxsquare*maxsquare;
}