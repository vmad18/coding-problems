bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for(int i=0;i<nums.size()-1;i++){
        for(int x=1;x<=nums[i];x++){
            if(i+x > nums.size() || dp[i+x-1] != 0) break;
            dp[i+x] += 1;
        }
    }
    
    return dp[nums.size()-1] > 0;
}