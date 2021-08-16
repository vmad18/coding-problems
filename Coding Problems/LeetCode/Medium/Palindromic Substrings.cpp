int countSubstrings(string s) {
    vector<vector<int>> dp(s.size()+2, vector<int>(s.size()+2,0));

    for(int i=1;i<s.size()+1;i++){
        for(int j=i;j<s.size()+1;j++){
            if(s[i-1]==s[j-1]){
                if(j-1==i-1){
                    dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1] + 1;
                }else{
                    dp[i][j] += dp[i-1][j+1]+1;
                }
            }
        }
    }
    return dp[s.size()][s.size()];
}