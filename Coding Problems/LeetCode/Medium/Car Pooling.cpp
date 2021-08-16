bool carPooling(vector<vector<int>>& trips, int capacity) {
    
    //better dp approach
    int b=0;
    for(vector<int> i:trips) if(i[2]>b) b=i[2];
    
    vector<int> dp(b+1,0);
    
    int sum=0;
    for(vector<int> i:trips){
        dp[i[1]]+=i[0];
        dp[i[2]]-=i[0];
    }
    
    for(int i:dp){
        sum+=i;
        if(sum>capacity) return false;
    }
    return sum<=capacity;
}